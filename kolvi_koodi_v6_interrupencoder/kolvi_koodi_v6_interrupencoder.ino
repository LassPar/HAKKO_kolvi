#include <EEPROM.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define TEMP_PIN A6
#define PWM_PIN 9
#define encoderPinA 2
#define encoderPinB 3
#define encoderpinBUT 4
#define BUZZER_PIN 1


boolean encoderBstate = LOW;
int encoder_suunta = 0;
unsigned long last_rotary_time;
int siirtyma = 0;

float erotus= 0;
float integraali = 0;
float derivaatta = 0;
float temp_target = 0;
float temp_target_last = 0;
boolean heater_power_on = false;
float temp_now = 0;
float temp_prew = 0;
float Kp = 50; // PID Arvot myös heater power-true - kohdassa.
float Ki = 1;
float Kd = 20;
float temps[] = {0,0,0,0,0};
int output = 0;
unsigned long prew_millis = 0;
int saatovali = 100;

//thermistortable[][ADC-arvo, lämpötila(*C)]

int thermistortable[][2] = {
  {236 , 0},
  {299 , 50},
  {362 , 100},
  {424 , 150},
  {492 , 200},
  {555 , 250},
  {622 , 300},
  {688 , 350},
  {746 , 400},
  {807 , 450},
  {865 , 500},
  {1024, 600}
};


boolean buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
boolean lastState = HIGH;
int button_timer_counter = 0;

void setup() 
{
//---------------------------------------------- Set PWM frequency for D9 & D10 ------------------------------
 
TCCR1B = TCCR1B & B11111000 | B00000001;    // set timer 1 divisor to     1 for PWM frequency of 31372.55 Hz
//TCCR1B = TCCR1B & B11111000 | B00000010;    // set timer 1 divisor to     8 for PWM frequency of  3921.16 Hz
//TCCR1B = TCCR1B & B11111000 | B00000011;    // set timer 1 divisor to    64 for PWM frequency of   490.20 Hz (The DEFAULT)
//TCCR1B = TCCR1B & B11111000 | B00000100;    // set timer 1 divisor to   256 for PWM frequency of   122.55 Hz
//TCCR1B = TCCR1B & B11111000 | B00000101;    // set timer 1 divisor to  1024 for PWM frequency of    30.64 Hz
  
  pinMode(TEMP_PIN, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(encoderpinBUT, INPUT_PULLUP);

  Serial.begin (115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  display.clearDisplay();
  
  temp_target = read_target_temp();
  temp_target_last = temp_target;
}

void loop() 
{
  
  if (prew_millis + saatovali <= millis())
  {
    
    lampotilanaytto(temp_now, temp_target);
    
    PID_cal();

    if (temp_target > 0)
    {
      analogWrite(PWM_PIN, constrain((int)(output + 0.5), 0, 255));
    }
    else
    {
      analogWrite(PWM_PIN, 0);
    }
    prew_millis = millis();
  }

  if (temp_now >= 600)
  {
    heater_power_on = false;
  }
  
  if (heater_power_on == true)
  {
    attachInterrupt(digitalPinToInterrupt(encoderPinA), rotaryencoder, RISING);
//  temp_target = constrain(temp_target, 0, 480);
    temp_target_last = temp_target;
    Kp = 50;
    Ki = 1;
    Kd = 20;
  }
  else
  {
    detachInterrupt(encoderPinA);
    Kp = 0;
    Ki = 0;
    Kd = 0;
    temp_target = 0;
  }

  byte button_funktio_state = button();
  
  if (button_funktio_state == 1)
  {
    if (heater_power_on == false)
    {
      heater_power_on = true;
      temp_target = temp_target_last;
    }
    else
    {
      heater_power_on = false;
    }
  }
  
  if (button_funktio_state == 2)
  {
    store_target_temp(temp_target);

    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(1,22);
    display.print((int)temp_target); 
    display.setTextSize(1);
    display.print("O");
    display.setTextSize(2);
    display.print("C "); 
    display.print("SAVED"); 
    display.display();
    delay(1000);
    
    //tone(BUZZER_PIN, 300, 100);
  }
}

//****************************************** SCREEN ****************************************************

void lampotilanaytto(int now, int target)
{
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("TEMPERATURE NOW");
  display.setCursor(0,50);
  display.println("TARGET");

  display.setTextSize(4);
  display.setCursor(10,13);
  display.print(now); 
  display.setTextSize(2);
  display.setCursor(85,13);
  display.print("O");
  display.setTextSize(4);
  display.print("C");  

  display.setCursor(20,50);
  
  display.setTextSize(2);
  display.setCursor(40,50);
  display.print(target); 
  display.setTextSize(1);
  display.setCursor(80,50);
  display.print("O");
  display.setTextSize(2);
  display.print("C");  
  
  display.display();
}


//****************************************** SCREN ****************************************************

//****************************************** EEPROM ****************************************************

void store_target_temp(int target_temp)
{
  byte val_1 = 0;
  byte val_2 = 0;
  
  if (target_temp <= 255)
  {
    val_1 = target_temp;
    val_2 = 0;
  }
  else// if (target_temp > 255)
  {
    val_1 = 255;
    val_2 = target_temp - 255;
  }
  Serial.print("save");
  EEPROM.update(0, val_1);
  EEPROM.update(1, val_2);
}

int read_target_temp()
{
  Serial.print(EEPROM.read(0));
  return (int)(EEPROM.read(0) + EEPROM.read(1));
}


//****************************************** EEPROM ****************************************************

//******************************************* BUT ***********************************

byte button()
{
  buttonState = digitalRead(encoderpinBUT);
  if (millis() - lastDebounceTime > debounceDelay) 
  {
    lastDebounceTime = millis();
    if (buttonState == LOW && lastState == HIGH) 
    {

      button_timer_counter = 0;
      lastState = LOW;
      lastDebounceTime = millis();
      //return 0
    }
    else if (buttonState == LOW && lastState == LOW) 
    {
      button_timer_counter +=1 ;
      lastState = LOW;
    }
    else if (buttonState == HIGH && lastState == LOW && button_timer_counter < 20) 
    {
      lastState = HIGH;
      return 1;
    }
    if (button_timer_counter == 20)
    {
      button_timer_counter = 0;
      return 2;
    }
    if (buttonState == HIGH) 
    {
      button_timer_counter = 0;
      lastState = HIGH;
    }
  }
  return 0;
}
//******************************************* BUT ***********************************

//******************************************* ROTARY ***********************************

void rotaryencoder() 
{
  encoderBstate = digitalRead(encoderPinB);
  
  if (encoderBstate == HIGH) 
  {
    encoder_suunta = 1;
  }
  else if (encoderBstate == LOW) 
  {
    encoder_suunta = -1;
  }   
  
  if (millis() - last_rotary_time > 200)
  {
    siirtyma = 1;
  }
  else if (millis() - last_rotary_time <= 100 && millis() - last_rotary_time > 75)
  {
    siirtyma = 1;
  }
  else if (millis() - last_rotary_time <= 75 && millis() - last_rotary_time > 50)
  {
    siirtyma = 1;
  }
  else if (millis() - last_rotary_time <= 50 && millis() - last_rotary_time > 25)
  {
    siirtyma = 3;
  }
  else if (millis() - last_rotary_time <= 25 && millis() - last_rotary_time > 0)
  {
    siirtyma = 5;
  }

  last_rotary_time = millis();

  temp_target = temp_target + siirtyma * encoder_suunta;
  temp_target = constrain(temp_target, 0, 480);
}

//******************************************* ROTARY ***********************************

//******************************************* MAPFLOAT ***********************************

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return(((out_max - out_min) * x + in_max * out_min - in_min * out_max) / (in_max - in_min));
}

//******************************************* MAPFLOAT ***********************************

//******************************************* LUE_LÄMPÖTILA ***********************************

float lue_lampotila()
{
  int raw_temp = analogRead(TEMP_PIN);
  //Serial.println(raw_temp);

  
  for (unsigned int i = 0; i < sizeof(thermistortable)-1; i++)
  {
    if (raw_temp < thermistortable[i][0])
    {
      continue;
    }
    else if (raw_temp >= thermistortable[i][0] && raw_temp <= thermistortable[i+1][0])
    {

      return float(mapfloat(raw_temp, thermistortable[i][0], thermistortable[i+1][0], thermistortable[i][1], thermistortable[i+1][1]));
    }
    else
    {
      //return 0;
    }
  }
  return 1;
}


//******************************************* LUE_LÄMPÖTILA ***********************************

//******************************************* PID ***********************************

void PID_cal()
{
  // Lukee nykyisen, talletta nykyise ja 4 edellistä
  temps[4] = temps[3];
  temps[3] = temps[2];
  temps[2] = temps[1];
  temps[1] = temps[0];
  temps[0] = lue_lampotila();

  temp_prew = temp_now;
  //Serial.print(temp_now);

  // Laskee keskiarvon viidestä edellisestä
  temp_now = (temps[0] + temps[1] + temps[2] + temps[3] + temps[4])/5.0;
  
  erotus = temp_target - temp_now;

  if (temp_target - temp_now > 10 || temp_now - temp_target > 10)
  {
    integraali = 0;
  }
  else
  {
    integraali = integraali + erotus;
  }  

  derivaatta = (temp_now - temp_prew) / saatovali;

  //output = Kp * max(erotus, 0) + Ki * max(integraali, 0) + Kd * max(derivaatta, 0);
  output = Kp * erotus + Ki * integraali + Kd * derivaatta;
  Serial.print(constrain((int)(output + 0.5), 0, 255));
  Serial.print(",");
  Serial.print(temp_now);
  Serial.print(",");
  Serial.println(temp_target);
}

//******************************************* PID ***********************************


