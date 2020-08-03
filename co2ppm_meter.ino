/* Modified code by ScottyD www.youtube.com/channel/UCLx3Gi9s_5uvVwURRIsWXKg
 * 
 * Carbon Dioxide Parts Per Million Meter
 * CO2PPM
 
 * Original code by www.youtube.com/c/learnelectronics


/*
 * Atmospheric CO2 Level..............400ppm
 * Average indoor co2.............350-450ppm
 * Maxiumum acceptable co2...........1000ppm
 * Dangerous co2 levels.............>2000ppm
 */

#define anInput     A0                        //analog feed from MQ135
#define co2Zero     55                        //calibrated CO2 0 level

void setup() 
{
  pinMode(anInput,INPUT);                     //MQ135 analog feed set for input
  Serial.begin(9600);                         //serial comms for debuging
}
  
void loop() 
{
  
  int co2now[10];                               //int array for co2 readings
  int co2raw = 0;                               //int for raw value of co2
  int co2ppm = 0;                               //int for calculated ppm
  int zzz = 0;                                  //int for averaging


  for (int x = 0;x<10;x++)  //samplpe co2 10x over 2 seconds
  {                   
    co2now[x]=analogRead(A0);
    delay(200);
  }

  for (int x = 0;x<10;x++)  //add samples together
  {                     
    zzz=zzz + co2now[x];  
  }
  
  co2raw = zzz/10;                            //divide samples by 10
  co2ppm = co2raw - co2Zero;                 //get calculated ppm

  Serial.print("AirQuality=");
  Serial.print(co2ppm);  // prints the value read
  Serial.println(" PPM");
  delay(50);             

}
