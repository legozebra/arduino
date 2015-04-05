int LED=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);      // Set pin as an OUTPUT
  digitalWrite(LED, HIGH);   // Turn ON the LED
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  digitalWrite(LED, HIGH);
}
