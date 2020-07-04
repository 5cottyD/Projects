// Code created/butched by ScottyD find the video @ https://www.youtube.com/channel/UCLx3Gi9s_5uvVwURRIsWXKg

#include <font_5x4.h>
#include <font_8x4.h>
#include <font_8x5.h>
#include <HT1632.h>
#include <images.h>

#include <RTClib.h>
#include <Wire.h>
#include <stdio.h>


int daysInMonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 2020 WAS A LEAP YEAR CHANGE FEB TO 28 if not leap year
int daycount[]={0,31,59,90,120,151,181,212,243,273,304,334}; 
 
int targetDay = 5; //My Cake day is 5,   
int targetMonth = 7; //My Cake month is 7,   
int targetYear = 2020; //Set year to this year
int nowdaynumber;
int TargetNumber;
int daysToTarget; 

int d;
int n;

int i = 0;
int wd;

char c[60];

int status ; //= snprintf(c, 60, "Days to cake Day : %d", daysToTarget);

int setRTC = 0;

RTC_DS1307 RTC;
 
void setup () 
 {
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  HT1632.begin(7, 8, 9); // CS,WR,DATA

  
 if (! RTC.isrunning() || setRTC == 1) 
   {
      Serial.println("RTC is NOT running!");
     //  following line sets the RTC to the date &amp; time this sketch was compiled
      RTC.adjust(DateTime(__DATE__, __TIME__));
   }
 }
 
void loop () {
    DateTime now = RTC.now();
    HT1632.clear();

  int d = targetMonth;
  int TargetNumber = daycount[d-1] + targetDay;
  Serial.println(TargetNumber);

  int n = now.month();
  int nowdaynumber = daycount[n-1] + now.day(); 
  Serial.println(nowdaynumber);


 
    if(TargetNumber < nowdaynumber)
      {

      daysToTarget = 365-(nowdaynumber - TargetNumber);

      Serial.print("YEAR IS GREATER");
      Serial.print("Days To CakeDay: ");
      Serial.println(daysToTarget);
     //Serial.println(TargetNumber);
      int status = snprintf(c, 60, "Days to cake Day : %d", daysToTarget);
       
      }

    
  else 
    {  
      daysToTarget = TargetNumber - nowdaynumber;
      Serial.print("This Year");

      Serial.print("Days To CakeDay: ");
     Serial.println(daysToTarget);
      int status = snprintf(c, 60, "Days to cake Day : %d", daysToTarget);

      
    }



  if (daysToTarget < 0 )
  {
    targetYear++ ;
    Serial.print("resetting year");
    Serial.println(targetYear);
  }
    
 if (daysToTarget <= 0)
 {
    Serial.print("TODAY IS YOUR CAKE DAY");
    
    int status = snprintf(c, 60, "TODAY IS YOUR CAKE DAY");
 }


   //delay(50);
   Serial.print(now.year(), DEC);
   Serial.print('/');
   Serial.print(now.month(), DEC);
   Serial.print('/');
   Serial.print(now.day(), DEC);
   Serial.print(' ');
   Serial.print(now.hour(), DEC);
   Serial.print(':');
   Serial.print(now.minute(), DEC);
   Serial.print(':');
   Serial.print(now.second(), DEC);
   Serial.println();
   Serial.println();
  
    HT1632.clear();  
    wd = HT1632.getTextWidth(c, FONT_8X4_END, FONT_8X4_HEIGHT);

    HT1632.drawText(c, OUT_SIZE - i, 0, FONT_8X4, FONT_8X4_END, FONT_8X4_HEIGHT);
    HT1632.drawImage(IMG_CAKE, IMG_CAKE_WIDTH,  IMG_CAKE_HEIGHT, OUT_SIZE - i - 10, 0);
    HT1632.drawImage(IMG_CAKE, IMG_CAKE_WIDTH,  IMG_CAKE_HEIGHT, OUT_SIZE - i + 100, 0);
    HT1632.render();

    i = (i+1)%(wd + OUT_SIZE);
  
}
