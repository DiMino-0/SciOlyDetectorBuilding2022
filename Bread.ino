//Bounds are in PPM NaCI
int BOUND_1 = 1000;
int BOUND_2 = 2000;
int BOUND_3 = 3000;

int YELLOW_LED = 1;
int RED_LED = 2;
int BLUE_LED = 3;

int SENSOR = A0;
double input = 0;
double voltage = 0;
int salinity = 0;

void setup() 
{
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    pinMode(SENSOR, INPUT);

    Serial.begin(9600);
}
void loop() 
{
    //4.9 m/v per unit
    input = analogRead(SENSOR);

    //ADC equation
    voltage = input * (5.0/1023.0);

    //Voltage to PPM equation
    salinity = (voltage * 0.01);

    //BOUNDS to highlight the LEDs
    if (salinity <= BOUND_1)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
    }
    else if (salinity > BOUND_1 && salinity <= BOUND_2)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(BLUE_LED, LOW);
    }
    else if (salinity > BOUND_2 && salinity <= BOUND_3)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(BLUE_LED, HIGH);
    }

    //output to the serial monitor
    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.print(" V");
    Serial.print(" and ");
    Serial.print("Salinity: ");
    Serial.print(salinity);
    Serial.println(" ppm");

    //In milliseconds
    delay(8000);
}