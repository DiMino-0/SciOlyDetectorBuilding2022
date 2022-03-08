//Bounds are in PPM NaCI
int BOUND_1 = 1000;
int BOUND_2 = 2000;
int BOUND_3 = 3000;

int BLUE_LED = 1;
int RED_LED = 2;
int GREEN_LED = 3;
int SENSOR = A0;

double voltage = 0;
int salinity = 0;

void setup()
{
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  pinMode(SENSOR, INPUT);

  Serial.begin(9600);
}
void loop()
{
  //4.9 mV per unit
  voltage = analogRead(SENSOR);

  //Voltage to PPM equation
  salinity = (voltage * 57.6) - 38233;

  //BOUNDS to light the LEDs
  if (salinity <= BOUND_1)
  {
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
  else if (salinity > BOUND_1 && salinity <= BOUND_2)
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  else if (salinity > BOUND_2 && salinity <= BOUND_3)
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  //output to the serial monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" mV");
  Serial.print(" and ");
  Serial.print("Salinity: ");
  Serial.print(salinity);
  Serial.println(" ppm");

  //In milliseconds
  delay(3000);
}