

#define LED 2

void setup() {
  // Set pin mode
  pinMode(LED,INPUT);
   Serial.begin(9600);
  Serial.println(F("Rain  test!"));
}

void loop() {
  int rain= digitalRead(LED);
  int anarain = analogRead(12);
  if(anarain < 4095){
  Serial.println(F("its raining"));
  }
  else{
    Serial.println(F("not raining"));
  }
   Serial.println(anarain);
  delay(1000);
}
