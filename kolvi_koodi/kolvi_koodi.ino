#define TEMP_PIN = A1;
#define PWM_PN = 13;

int temp = 0;
int temps[] = {0,0,0,0,0};
int Dtemps[] = {0,0,0,0,0};
int target_temp = 0;
float Kp = 1;
float Ki = 1;
float Kd = 1;
int output = 0;
unsigned long prew_millis = 0;
int temp_prew

void setup() 
{

}

void loop() 
{

  analogWrite(PWM_PIN, output);
  if (prew_millis + 100 >= millis())
  {
    PID_cal();
    prew_millis = millis();
  }

}


int lue_lampotila()
{
    int raw_temp = analogRead(TEMP_PIN);
  
  // Lämpötilan kalibrointilaskuja...

  return temperature;
}

void PID_cal()
{
  // Lukee nykyisen, talletta nykyise ja 4 edellistä
  temps[] = {lue_lampotila(), temps[0], temps[1], temps[2], temps[3]};

  temp_prew = temp_now;

  // Laskee keskiarvon viidestä edellisestä
  temp_now = (temps[0] + temps[1] + temps[2] + temps[3] + temps[4])/5;
  
  erotus = target_temp - temp_now;

  integraali = integral + erotus;

  derivaatta = (temp_now - temp_prew) / 100
}

