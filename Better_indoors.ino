
#include <DHT.h>
#define DHTPIN 3     // Hvilken pin DHT22 sidder i.
#define DHTTYPE DHT22   // DHT 22
DHT dht(DHTPIN, DHTTYPE); //// int DHT sensoren


int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value


int sensorValue1; //navnet på Co2 mål
int ledDry = 13; //led til tørhed
int ledFugt = 12; //led til fugt
int ledCo2 = 11; //led til Co2
int ledKold = 10; //led til koldhed
int ledVarm = 9; //led til varme
void setup()
{
  Serial.begin(9600);
  dht.begin(); //start DHT
  pinMode(ledVarm, OUTPUT); //Led outputs
  pinMode(ledKold, OUTPUT);
  pinMode(ledCo2, OUTPUT);
  pinMode(ledFugt, OUTPUT);
  pinMode(ledDry, OUTPUT);        
}

void loop()
{
    //Læs data og gem det i hum og temp.
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    sensorValue1 = analogRead(0);
    //Print vores værdier
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.print(" Celsius");
    Serial.print(" AirQuality=");
    Serial.print(sensorValue1, DEC);
    Serial.println(" PPM");
    if (temp < 20)
      digitalWrite(ledKold, HIGH);
    if (temp > 30)
      digitalWrite(ledVarm, HIGH);
    if (hum > 60)
      digitalWrite(ledFugt, HIGH);
    if (hum < 40)
      digitalWrite(ledDry, HIGH);
    if (sensorValue1 > 1000)
      digitalWrite(ledCo2, HIGH);
    delay(1000); //Delay 1 sec.
    
}                       
