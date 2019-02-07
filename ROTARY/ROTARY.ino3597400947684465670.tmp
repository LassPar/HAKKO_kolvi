
#define encoderPinA 2
#define encoderPinB 3
#define encoderpinBUT 4

int encoderPos = 0;
int encoderPinALast = LOW;
int encoderAstate = LOW;
unsigned long last_rotary_time;
int siirtyma = 0;

boolean buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
boolean lastState = HIGH;
int button_timer_counter = 0;



void setup() {
  pinMode (encoderPinA, INPUT_PULLUP);
  pinMode (encoderPinB, INPUT_PULLUP);
  pinMode(encoderpinBUT, INPUT_PULLUP);
  Serial.begin (9600);
}

void loop() {
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
      encoderPos = encoderPos - siirtyma;
    } 
    else {
      encoderPos = encoderPos + siirtyma;
    }

    encoderPos = constrain(encoderPos, 0, 500);
    
    Serial.println (encoderPos);
    //Serial.print ("\n");
  }
  encoderPinALast = encoderAstate;
  Serial.println(button()*100);
}


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

