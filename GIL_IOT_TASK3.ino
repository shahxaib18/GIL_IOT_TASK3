
#include <LiquidCrystal_I2C.h>
#include <wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int EnterBtn = 7;
int UpBtn =6;
int DownBtn=5;
int bulb = 12;
int time=0 ;
void setup() {
  Serial.begin(9600);
  pinMode(bulb, OUTPUT);
  pinMode(EnterBtn, INPUT);
  pinMode(UpBtn, INPUT);
  pinMode(DownBtn, INPUT);
  lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("HELLO GIL"); 
lcd.setCursor(0,1);
lcd.print("IOT TASK 3"); 
delay(2000);
lcd.clear();
}
void loop() {
     lcd.setCursor(0,0);
lcd.print("press Enter to"); 
     lcd.setCursor(0,1);
lcd.print("set timer"); 
    int ent = digitalRead(EnterBtn);
  delay(200);  
while(ent==1){
time=1;
 ent = digitalRead(EnterBtn);
while(ent!=1){
       int   down= digitalRead(DownBtn);
  int up= digitalRead(UpBtn);  
  if(up==1){
    if(time==5){
      time=1;
    }
    else
    time++;
    }
     if(down==1){
    if(time==1){
      time=5;
    }
    else time--;
  } lcd.clear();
    lcd.setCursor(0,0);  
    lcd.print("SET TIME (1-5)");
    lcd.setCursor(2,1);
    lcd.blink();   
    lcd.print(time);
   ent = digitalRead(EnterBtn);
   delay(200);
} 
delay(200);
ent = digitalRead(EnterBtn);
} 
if(time!=0){
 lcd.setCursor(0,0);  
    lcd.print("Time set for ");
lcd.print(time);
lcd.setCursor(0,1);  
    lcd.print("mins plz wait.. ");
delay(time*60*100);
lcd.clear();
lcd.print("BULB ON!");
digitalWrite(bulb,HIGH);
delay(time*60*100);
digitalWrite(bulb,LOW);
lcd.clear();
time=0;
}
}
