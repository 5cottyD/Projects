// Arduino master sketch

#include <Wire.h>

byte i2c_rcv;               // data received from I2C bus
unsigned long time_start;   // start time in milliseconds
//int stat_LED;               // status of LED: 1 = ON, 0 = OFF
//int value_pot;             // potentiometer position

void setup(){
    Serial.begin(9600);
  Wire.begin(); // join I2C bus as the master
  
  // initialize global variables
  i2c_rcv = 255;
  //time_start = millis();


}

void loop()
{
  Wire.requestFrom(0000000, 1);    // request potentiometer position from slave 0x08
  if(Wire.available()) 
  {        // read response from slave 0x08
    i2c_rcv = Wire.read();
   
   // Serial.println(i2c_rcv); 
  }
  Serial.println(i2c_rcv); 
}
