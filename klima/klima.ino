
#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
const byte satir=4;
const byte sutun=4;
char tustakimi[satir][sutun]=
{
  {'7','8','9','/'},
  {'4','5','6','x'},
  {'1','2','3','-'},
  {'c','0','=','+'},
};
byte satirpin[satir]={22,23,24,25};
byte sutunpin[sutun]={26,27,28,29};
Keypad tustakimim = Keypad(makeKeymap(tustakimi),satirpin,sutunpin,satir,sutun);
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo yonmotor1;  
Servo yonmotor2;  
Servo kapak;  
int derece = 0;   
String klimaDurum;
String sistemDurum;

int inPin1=7;
int inPin2=6;
int enA=5;
int buz=31;
int inPin3=4;
int inPin4=3;
int enB=2;
int hiz;
int i=1;
const int analogPin=A0;
float gerilimDegeri=0;
float sensorDegeri = 0;
float odasicakligi = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
   yonmotor1.attach(14);
   yonmotor2.attach(15);
   kapak.attach(16);
  
    pinMode(buz,OUTPUT);
    pinMode(inPin1,OUTPUT);
    pinMode(inPin2,OUTPUT);
    pinMode(inPin3,OUTPUT);
    pinMode(inPin4,OUTPUT);  
}
void kapaklar(){
        for (derece = 0; derece <= 180; derece += 1) {
            sensorDegeri = analogRead(analogPin);
            gerilimDegeri = (sensorDegeri/1023)*5000;
            odasicakligi = gerilimDegeri / 10.0;   
          yonmotor1.write(derece); 
          yonmotor2.write(derece);              
          delay(15);              
           char tus = tustakimim.getKey(); 
           if(tus == '0'){
           klimaDurum="yanlis";
            kapaklarkapat();                      
           }
     if(tus == '8' && i<8){
    if( klimaDurum=="dogru"){      
     i++;  
    }
  if(i==1){ 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:24C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }
  if(i==2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:23C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }
  if(i==3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:22C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece;21C");  
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi;");
  }if(i==5){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:20C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==6){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:19C");  
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==7){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:18C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }      
  }
  else if(tus == '2' && i>1){
    if( klimaDurum=="dogru"){
      i--;   
    }  
  if(i==1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:24C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }
  if(i==2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:23C");
    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }
  if(i==3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:22C");
    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:21C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==5){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:20C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==6){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:19C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==7){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:18C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }
  }  
if(i == 1){
  hiz =50;
}
else if(i ==2){
  hiz = 80;
}
else if(i ==3){
  hiz = 115;
}
else if(i ==4){
  hiz = 150;
}
else if(i ==5){
  hiz = 185;
}
else if(i ==6){
  hiz = 220;
}
else if(i ==7){
  hiz = 255;
}
    analogWrite(7,hiz);
  analogWrite(6,0);
  analogWrite(4,hiz);
  analogWrite(3,0);
            lcd.setCursor(14,1);
            lcd.print(odasicakligi);
  } 
       for (derece = 180; derece >= 0; derece -= 1) {
            sensorDegeri = analogRead(analogPin);
            gerilimDegeri = (sensorDegeri/1023)*5000;
            odasicakligi= gerilimDegeri/ 10.0;    
          yonmotor1.write(derece);
          yonmotor2.write(derece);                 
          delay(15);
           char tus = tustakimim.getKey();
           if(tus == '0'){
            klimaDurum="yanlis";            
            kapaklarkapat();                                      
           } 
    if(tus == '8' && i<8){
    if( klimaDurum=="dogru"){   
     i++;    
    }
    if(i==1){
     
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:24C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");    
  }
  if(i==2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:23C");  
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }
  if(i==3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:22C");    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:21C");    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==5){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:20C");    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==6){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:19C");   
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==7){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:18C");   
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }   
  }

  else if(tus == '2' && i>1){
    if( klimaDurum=="dogru"){   
      i--;   
    }  
  if(i==1){ 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:24C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");    
  }
  if(i==2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:23C");   
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }
  if(i==3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:22C");    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:21C");    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==5){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:20C");
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==6){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:19C");    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }if(i==7){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Klima Derece:18C");    
    lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:");
  }    
  }
if(i == 1){
  hiz =50;
}
else if(i ==2){
  hiz = 80;
}
else if(i ==3){
  hiz = 115;
}
else if(i ==4){
  hiz = 150;
}
else if(i ==5){
  hiz = 185;
}
else if(i ==6){
  hiz = 220;
}
else if(i ==7){
  hiz = 255;
}
     analogWrite(7,hiz);
     analogWrite(6,0);
     analogWrite(4,hiz);
     analogWrite(3,0);
            lcd.setCursor(14,1);
            lcd.print(odasicakligi);                          
  }  
kapaklar();  
} 
void kapaklarkapat(){
  yonmotor1.write(0); 
  yonmotor2.write(0); 
  kapak.write(0);   
     analogWrite(7,0);
     analogWrite(6,0);
     analogWrite(4,0);
     analogWrite(3,0);   
loop();
}
void loop() {
 char tus = tustakimim.getKey();
 if(tus!=NO_KEY){
 if(tus == 'c' ){
   
   tone(buz,4000);
    delay(20);
    noTone(buz);
      kapak.write(180); 
      klimaDurum="dogru";
      lcd.print("Klima Acildi");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,1);
    lcd.print("Oda Sicakligi:"); 
      kapaklar();
 }
if(tus == '0' ){
 klimaDurum="yanlis";   
}
}
 if(klimaDurum == "yanlis"){ 
   
   lcd.clear();  
  kapaklarkapat();
}
}
  
