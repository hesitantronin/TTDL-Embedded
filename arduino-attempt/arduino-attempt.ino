#define LED_BUILTIN 2
#define ADC_PIN 34


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);                    
  digitalWrite(LED_BUILTIN, LOW); 
  delay(1000);                    
  sensorValue = analogRead(ADC_PIN);
  print("The sensor read: " + sensorvalue)
}
