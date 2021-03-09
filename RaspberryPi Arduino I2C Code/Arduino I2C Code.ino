int laserPin = 10;

void setup ()
{
  pinMode(laserPin, OUTPUT);
}

void loop () {
  digitalWrite(laserPin, HIGH);
  delay(100);
  digitalWrite(laserPin, LOW);
  delay(100);
}
