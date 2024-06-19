// #include <thingsml.h>
// #include <thingsml_http.h>
// #include <thingsml_http_firmware.h>

#define LED_BUILTIN 5
#define ADC_PIN 35

bool isOn = false;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  while (!Serial) {

  }
  Serial.println("Hi?");
  delay(10000);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ADC_PIN, INPUT);
}

/*
void loop() {
  isOn = !isOn;
  Serial.println("Hi :D");
  digitalWrite(LED_BUILTIN, isOn ? HIGH: LOW);
  delay(10);
}
*/


bool measureBool() {
  return analogRead(ADC_PIN) > 2400;
}


int measureInt() {
  return analogRead(ADC_PIN);
}

// the loop function runs over and over again forever
void loop() {
  isOn = !isOn;
  digitalWrite(LED_BUILTIN, isOn ? HIGH : LOW);
  Serial.printf("%d\n", analogRead(ADC_PIN));
  // Serial.println(measureBool() ? "On " : "Off");
  delay(100);
}
