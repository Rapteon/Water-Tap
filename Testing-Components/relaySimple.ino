#define RELAY1 6
#define RELAY2 7
#define RELAY3 8
#define RELAY4 9

void setup(){
  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);
  pinMode(RELAY3,OUTPUT);
  pinMode(RELAY4,OUTPUT);
}

void loop(){
  digitalWrite(RELAY1,LOW);
  delay(2000);
  digitalWrite(RELAY1,HIGH);
  delay(2000);
  digitalWrite(RELAY2,LOW);
  delay(2000);
  digitalWrite(RELAY2,HIGH);
  delay(2000);
  digitalWrite(RELAY3,LOW);
  delay(2000);
  digitalWrite(RELAY3,HIGH);
  delay(2000);
  digitalWrite(RELAY4,LOW);
  delay(2000);
  digitalWrite(RELAY4,HIGH);
  delay(2000);
}
