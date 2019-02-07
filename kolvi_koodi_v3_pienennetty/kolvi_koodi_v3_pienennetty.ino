//#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//#define CS_PIN 14
//File settings_file;

#define TEMP_PIN A6
#define PWM_PIN 5
#define encoderPinA 2
#define encoderPinB 3
#define encoderpinBUT 4


int encoderPinALast = LOW;
int encoderAstate = LOW;
unsigned long last_rotary_time;
int siirtyma = 0;

float erotus= 0;
float integraali = 0;
float derivaatta = 0;
float temp_target = -5;
float temp_target_last = 0;
int heater_power_on = true;
float temp_now = 0;
float temp_prew = 0;
float Kp = 50;
float Ki = 0;
float Kd = 0;
float temps[] = {0,0,0,0,0};
int output = 0;
unsigned long prew_millis = 0;
int saatovali = 100;

//thermistortable[][ADC-arvo, lämpötila(*C)]

int thermistortable[][2] = {
  {50 , 0},
  {296 , 20},
  
  {354 , 60}, 
  
  {415 , 100}, //---
  
  {491 , 150}, //---
  
  {570 , 200}, //---
  
  {647 , 250}, //---
  
  {722 , 300}, //---
  
  {784 , 350}, //
  
  {869 , 400},
  {948 , 450},
  {1024 , 500}
  

};


int buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
int lastState = HIGH;

void setup() 
{
  pinMode(TEMP_PIN, INPUT);
  pinMode(PWM_PIN, OUTPUT);
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(encoderpinBUT, INPUT_PULLUP);

  Serial.begin (115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay();
  
  //initializeSD();
  //read_settings();

}

void loop() 
{
  if (prew_millis + saatovali <= millis())
  {
    //Serial.println(temp_target);
    lampotilanaytto(temp_now, temp_target);
    
    PID_cal();
    analogWrite(PWM_PIN, constrain((int)(output + 0.5), 0, 255));
    prew_millis = millis();
  }
  
  if (heater_power_on == true)
  {
    temp_target = temp_target + rotaryencoder();
    temp_target_last = temp_target;
  }
  else
  {
    temp_target = 0;
  }
  
  temp_target = temp_target + rotaryencoder();
  
  if (button() == true)
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

//****************************************** SD ****************************************************
/*
void initializeSD()
{
  pinMode(CS_PIN, OUTPUT);

  if (SD.begin())
  {
  }
}

void save_settings()
{
  settings_file = SD.open("SETTINGS.txt");

  if (settings_file)
  {
    settings_file.println(String(temp_target));
    
    settings_file.close();
  }
}

void read_settings()
{
  settings_file = SD.open("SETTINGS.txt");

  if (settings_file)
  {
    char ch;
    for (int i = 0; i < 1; i++)
    {
      String setting = "";
      while (true)
      {
        ch = settings_file.read();
        if (ch == '\n')
        {
          break;
        }
        else
        {
          setting += ch;
        }
      }
      switch(i)
      {
        case 0:
          temp_target = setting.toInt();
          break;
      }
    }
    settings_file.close();
  }
}
*/
//****************************************** SD ****************************************************

//******************************************* BUT ***********************************

int button()
{
  buttonState = digitalRead(encoderpinBUT);
  if (millis() - lastDebounceTime > debounceDelay) 
  {
    if (buttonState == LOW && lastState == HIGH) 
    {
      lastDebounceTime = millis();
      lastState = LOW;
      
      return true;

    }
    else if (buttonState == HIGH && lastState == LOW) 
    {
      lastState = HIGH;
    }
  }
  return false;
}
//******************************************* BUT ***********************************

//******************************************* ROTARY ***********************************

int rotaryencoder() 
{
  siirtyma = 0;
  encoderAstate = digitalRead(encoderPinA);
  if ((encoderPinALast == LOW) && (encoderAstate == HIGH)) {
    // lt = millis() - last_time;

    if (millis() - last_rotary_time > 200)
    {
      siirtyma = 1;
    }
    else if (millis() - last_rotary_time <= 100 && millis() - last_rotary_time > 75)
    {
      siirtyma = 2;
    }
    else if (millis() - last_rotary_time <= 75 && millis() - last_rotary_time > 50)
    {
      siirtyma = 3;
    }
    else if (millis() - last_rotary_time <= 50 && millis() - last_rotary_time > 25)
    {
      siirtyma = 4;
    }
    else if (millis() - last_rotary_time <= 25 && millis() - last_rotary_time > 0)
    {
      siirtyma = 5;
    }

    last_rotary_time = millis();

    if (digitalRead(encoderPinB) == LOW) {
      siirtyma = 0 - siirtyma;
    } 
  }
  encoderPinALast = encoderAstate;
  return siirtyma;
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
  Serial.println(raw_temp);

  
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
      //return 1;///
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
  //Serial.print(temp_now);
  
  erotus = temp_target - temp_now;

  integraali = integraali + erotus;

  derivaatta = (temp_now - temp_prew) / saatovali;

  //output = Kp * max(erotus, 0) + Ki * max(integraali, 0) + Kd * max(derivaatta, 0);
  output = Kp * erotus + Ki * integraali + Kd * derivaatta;
}

//******************************************* PID ***********************************

