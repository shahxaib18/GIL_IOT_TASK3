//GIL_IOT_TASK_3

#include <LiquidCrystal_I2C.h>     //I2C LCD
#include <wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //lcd Address
int EnterBtn = 7;  
int UpBtn =6;
int DownBtn=5;
int bulb = 12;
int time=0 ;
void setup() {
  pinMode(bulb, OUTPUT);
  pinMode(EnterBtn, INPUT);
  pinMode(UpBtn, INPUT);
  pinMode(DownBtn, INPUT);
  lcd.init();          
lcd.backlight();   // lcd back light
lcd.setCursor(0,0);  
lcd.print("HELLO GIL"); //lcd wellcome note
lcd.setCursor(0,1);
lcd.print("IOT TASK 3"); //lcd wellcome note
lcd.setCursor(0,1);
delay(2000);
lcd.clear();
}
void loop() {
     lcd.setCursor(0,0);
lcd.print("press Enter to"); //instructions on lcd
     lcd.setCursor(0,1);
lcd.print("set timer"); 
    int ent = digitalRead(EnterBtn); //looking for cammand
  delay(200);  
while(ent==1){
time=1;                 //time defualt setting on 1
 ent = digitalRead(EnterBtn);   //looking for 2nd cammand to set new time
while(ent!=1){
       int   down= digitalRead(DownBtn);
  int up= digitalRead(UpBtn);  
  if(up==1){            // increasing time variable
    if(time==5){          // check if time is already on its max
      time=1;
    }
    else
    time++;
    }
     if(down==1){           // decreasing time variable
    if(time==1){            // check if time is already on its min
      time=5;
    }
    else time--;
  } 
    lcd.clear();        // desplaying time during setting
    lcd.setCursor(0,0);  
    lcd.print("SET TIME (1-5)");
    lcd.setCursor(2,1);
    lcd.blink();   
    lcd.print(time);
    ent = digitalRead(EnterBtn);    // if time is set the looking of enter to save it
    delay(200);
} 
delay(200);
ent = digitalRead(EnterBtn);
} 
if(time!=0){
 lcd.setCursor(0,0);  
    lcd.print("Time set for ");        // increasing time variable
lcd.print(time);
lcd.setCursor(0,1);  
    lcd.print("mins plz wait.. ");   // increasing time variable
delay(time*60*1000);               // converting sec into min
lcd.clear();
lcd.print("BULB ON!");
digitalWrite(bulb,HIGH);          // getting bulb ON after given time
delay(time*60*100);               
digitalWrite(bulb,LOW);          // getting bulb OFF after given time
lcd.clear();
time=0;
}
}
