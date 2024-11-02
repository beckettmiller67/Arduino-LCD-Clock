#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//insert time 
int sec = 0;
int min = 0;
int hour = 0;
unsigned long prevmillis = 0;
void setup() {
//tells arduino lcd is 16 by 2 units
  lcd.begin(16,2);
}
void loop() {
//software based clock, make math calculated to tell time
  unsigned long currentmillis = millis();
  if (currentmillis-prevmillis>=1000){
    prevmillis = currentmillis;
    sec++;
//counts seconds and adds minute at 60
    if (sec == 60){
      sec = 0;
      min++;
//counts minutes and adds hour at 60
    } if (min == 60){
        min = 0;
        hour++;
//counts minute and resets at 24
      }  if (hour == 24){
          hour = 0;
      }
//clock formatting hour:minute:second
    lcd.setCursor(0,1);
    if (hour<10){
      lcd.print("0");
    }
    lcd.print(hour);
    lcd.print(":");
    if (min<10){
      lcd.print("0");
    }
    lcd.print(min);
    lcd.print(":");
    if (sec<10){
      lcd.print("0");
    }
    lcd.print(sec);
  }
}
