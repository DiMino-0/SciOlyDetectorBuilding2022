//3 pins, one blue, one red, one yellow
int YELLOW_LED = 1;
int RED_LED = 2;
int BLUE_LED = 3;
int sensor = A0;

//LEDS
int resistance = 0;
int bound1 = 0;
int bound2 = 0;
int bound3 = 0;

//constants for equation?
int salinity = 0;

void setup() 
{
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    pinMode(sensor, INPUT);

    Serial.begin(9600);
}
void loop() 
{
    resistance = analogRead(sensor);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);

    //get salinity using resitance
    salinity = (resistance * 0.01);

    if (salinity <= 0.1)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(BLUE_LED, HIGH);
    }
    else if (salinity > 0.1 && salinity < 0.2)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(BLUE_LED, LOW);
    }
    else if (salinity >= 0.2 && salinity <= 0.3)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
    }
    else if (salinity > 0.3)
    {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(BLUE_LED, HIGH);
    }

    Serial.print("Resistance: ");
    Serial.print(resistance);
    Serial.println(" Ohms");
    Serial.print("Resistance: ");
    Serial.print(salinity);
    Serial.println(" oom");
    delay(1000);
}