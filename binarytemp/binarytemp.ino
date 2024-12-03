#include <Bonezegei_DHT11.h>

const int lightDecimal = 13;
const int lightB0 = 12;
const int lightB1 = 11;
const int lightB2 = 10;
const int lightB3 = 9;
const int lightB4 = 8;
const int lightB5 = 7;
const int lightNeg = 6;
Bonezegei_DHT11 dht(2);

int lightBin[] = {lightB0, lightB1, lightB2, lightB3, lightB4, lightB5};

void setup() {
  // put your setup code here, to run once:
  pinMode(lightDecimal, OUTPUT);
  pinMode(lightB0, OUTPUT);
  pinMode(lightB1, OUTPUT);
  pinMode(lightB2, OUTPUT);
  pinMode(lightB3, OUTPUT);
  pinMode(lightB4, OUTPUT);
  pinMode(lightB5, OUTPUT);
  pinMode(lightNeg, OUTPUT);
  Serial.begin(115200);
  dht.begin();
}

void setLights(int temp, int decimalTemp) {
  if(temp < 0) {
    digitalWrite(lightNeg, HIGH);
    temp = -temp;
  }
  else digitalWrite(lightNeg, LOW);
  for(int i = 0; i < 6; ++i) {
    digitalWrite(lightBin[i], bitRead(temp, i) == 0 ? LOW : HIGH);
    Serial.print("Setting pin ");
    Serial.print(i);
    Serial.print("with number ");
    Serial.print(temp);
    Serial.print(".");
    Serial.print(decimalTemp);
    Serial.println();
  }
  if(decimalTemp > 4) digitalWrite(lightDecimal, HIGH);
  else digitalWrite(lightDecimal, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(dht.getData()) {
    float temp = dht.getTemperature();
    int whole = temp;
    int dec = (temp-whole) * 10;
    setLights(whole, dec);
    Serial.println(temp);
    Serial.println(dht.getHumidity());
    delay(30000);
  }
}
