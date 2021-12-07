//3 pins, one blue, one red, one yellow
int yellowLED = 1;
int redLED = 2;
int blueLED = 3;

//1 sensor, our thermsistor (analog)
int sensor = A0;
int resistance;
int bound1 = 0;
int bound2 = 0;
int bound3 = 0;
float temperature;

//constants for stienhart
int A = 0;
int B = 0;
int C = 0;


//runs when the board is powered up
void setup() 
{
    //set the LEDs to output
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(blueLED, OUTPUT);

    //set the sensor to input
    pinMode(sensor, INPUT);

    Serial.begin(9600);
}
//Runs constantly after after setup
void loop() 
{
    resistance = analogRead(sensor);

    //calculate the temperature
    temperature = voltageToTemp(resistance);

    if(temperature < bound1)
    {
        digitalWrite(redLED, HIGH);
    }
        if(temperature < bound2)
    {
        digitalWrite(yellowLED, HIGH);
    }
        if(temperature < bound3)
    {
        digitalWrite(blueLED, HIGH);
    }

    Serial.print("Resistance: ");
    Serial.print(resistance);
    Serial.println(" Ohms");
    delay(1000);
}

int voltageToTemp(int resistance)
{
    //convert voltage to temperature for nichrome using Steinhart-Hart equation
    //https://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation
}