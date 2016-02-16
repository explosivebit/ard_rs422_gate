include <SoftwareSerial.h>

#define SSerialRX        10
#define SSerialTX        11 
 
SoftwareSerial RS485Serial(SSerialRX, SSerialTX); // RX, TX

const int ledPin =  12;     // TX
const int ledPin2 =  9;     // RX
int lectura = 100;

void setup() { 
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  RS485Serial.begin(9600);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin, LOW);
} 
 
void loop(){
  digitalWrite(ledPin, HIGH);
  RS485Serial.write(lectura);
  Serial.println(lectura);
  delay(500);
  digitalWrite(ledPin, LOW);
  if(RS485Serial.available()){ 
    digitalWrite(ledPin2, HIGH); 
    int funcion = RS485Serial.read();
    Serial.println(funcion);
  }else{
      digitalWrite(ledPin2, LOW);
    }
}
