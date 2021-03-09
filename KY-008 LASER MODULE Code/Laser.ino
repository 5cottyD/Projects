int laserPin = 52;

void setup ()
{
  pinMode(laserPin, OUTPUT);
}

void loop () {
  digitalWrite(laserPin, HIGH);
  delay(20);
  digitalWrite(laserPin, LOW);
  delay(20);
}
