
int sensorPin = A0;    
int sensorValue = 0; 
int rotswitchNumber = 0;

void setup() 
{
    Serial.begin(9600);
}


void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.print("Value:");
  Serial.println(sensorValue);
  Serial.print("SwitchNumber:");
  Serial.println(rotswitchNumber);

  if (sensorValue < 20)
    {
    rotswitchNumber = 1;
    }
  else if ((sensorValue >=80) && (sensorValue<= 120))
    {
    rotswitchNumber = 2;
    }
  else if ((sensorValue >=180) && (sensorValue<= 220))
    {
    rotswitchNumber = 3;
    }
  else if ((sensorValue >=280) && (sensorValue<= 320))
    {
    rotswitchNumber = 4;
    }    
  else if ((sensorValue >=380) && (sensorValue<= 420))
    {
    rotswitchNumber = 5;
    }
  else if ((sensorValue >=480) && (sensorValue<= 520))
    {
    rotswitchNumber = 6;
    }    
  else if ((sensorValue >=580) && (sensorValue<= 620))
    {
    rotswitchNumber = 7;
    }   
  else if ((sensorValue >=680) && (sensorValue<= 720))
    {
    rotswitchNumber = 8;
    }
  else if ((sensorValue >=780) && (sensorValue<= 820))
    {
    rotswitchNumber = 9;
    }
  else if ((sensorValue >=880) && (sensorValue<= 920))
    {
    rotswitchNumber = 10;
    }
  else if (sensorValue > 1000)
    {
    rotswitchNumber = 11;
    }
}
