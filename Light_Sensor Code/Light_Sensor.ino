void setup() {
  Serial.begin(9600);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

  Serial.print("Analog reading = ");
  Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 100) {
    Serial.println(" - Very bright");
  } else if (analogValue < 200) {
    Serial.println(" - Bright");
  } else if (analogValue < 500) {
    Serial.println(" - Light");
  } else if (analogValue < 800) {
    Serial.println(" - Dim");
  } else {
    Serial.println(" - Dark");
  }

  delay(500);
}
