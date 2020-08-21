#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <ShiftRegister74HC595.h>

#define SDI 50
#define SCLK 2
#define LOAD 3
#define DIGITS 2 

#define eeprom 0x50

// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (DIGITS, SDI, SCLK, LOAD);  

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

int value,digit1,digit2,digit3,digit4; 
uint8_t  digits[] = {B11000000, //0
                      B11111001, //1 
                      B10100100, //2
                      B10110000, //3 
                      B10011001, //4
                      B10010010, //5
                      B10000010, //6 
                      B11111000, //7
                      B10000000, //8
                      B10010000 //9
                     };


int sensor = 46; 
int up = 47; 
int down = 48; 
int reset = 49;
uint8_t count = 0; 
uint8_t n=24;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(); 
  lcd.begin(20,4);
  Serial.begin(9600); 
  pinMode(sensor,INPUT); 
  pinMode(up,INPUT); 
  pinMode(down,INPUT); 
  pinMode(reset,INPUT);
  for(int i=22;i<46;i++){ 
    pinMode(i,OUTPUT); 
    digitalWrite(i,HIGH); 
  } 
  lcd.setCursor(5,0); 
  lcd.print("POLITEKNIK"); 
  lcd.setCursor(5,1); 
  lcd.print("ELEKTRONIKA"); 
  lcd.setCursor(7,2); 
  lcd.print("NEGERI"); 
  lcd.setCursor(6,3); 
  lcd.print("SURABAYA");
  delay(3000); 
  lcd.clear(); 

  lcd.setCursor(4,0); 
  lcd.print("DIBUAT OLEH:"); 
  lcd.setCursor(2,1); 
  lcd.print("DANANJAYA ENDI P"); 
  lcd.setCursor(10,2); 
  lcd.print("&"); 
  lcd.setCursor(2,3); 
  lcd.print("FILDZAH AURE G Z");
  delay(3000); 
  lcd.clear(); 
  
  lcd.setCursor(6,0); 
  lcd.print("PT.PMI"); 
  lcd.setCursor(2,1); 
  lcd.print("BU REFRIGERATOR"); 
  lcd.setCursor(3,2); 
  lcd.print("Urethane Door");
}

void loop() {
  // put your main code here, to run repeatedly: 
  count = readEEPROM(eeprom,0); 
  n = readEEPROM(eeprom,1); 
  Serial.print(n);
  Serial.println(count);
  
    if(digitalRead(reset)==LOW){ 
    delay(20); 
    if(digitalRead(reset)==LOW){ 
      while(digitalRead(reset)==LOW); 
      for(int i=22;i<46;i++){ 
        digitalWrite(i,HIGH); 
      }
      count=0; 
      writeEEPROM(eeprom,0,count);
    }
  } 

  
  if(digitalRead(up)==LOW){ 
    delay(20); 
    if(digitalRead(up)==LOW){ 
      while(digitalRead(up)==LOW);
      n++;
    } 
    if(n>24){ 
      n=24;
    } 
    writeEEPROM(eeprom,1,n);
  } 

if(digitalRead(down)==LOW){ 
    delay(20); 
    if(digitalRead(down)==LOW){ 
      while(digitalRead(down)==LOW);
      n--;
    } 
    if(n<18){ 
      n=18;
    } 
    writeEEPROM(eeprom,1,n);
      } 
  
  showNumber(n); 
  
  if(digitalRead(sensor)==LOW){
    delay(20); 
    if(digitalRead(sensor)==LOW){ 
      while(digitalRead(sensor)==LOW); 
      count++;
      writeEEPROM(eeprom,0,count);
    }
  } 

  if(count==1){ 
        digitalWrite(23,LOW);
        digitalWrite(22,LOW); 
        delay(100); 
        digitalWrite(22,HIGH); 
        delay(100); 
        
       } 

  else if(count==2){ 
        digitalWrite(24,LOW);
        digitalWrite(23,LOW); 
        delay(100); 
        digitalWrite(23,HIGH); 
        delay(100); 
        
       } 

   
  else if(count==3){ 
        digitalWrite(25,LOW);
        digitalWrite(24,LOW); 
        delay(100); 
        digitalWrite(24,HIGH); 
        delay(100); 
        
       } 

  else if(count==4){
        digitalWrite(26,LOW);
        digitalWrite(25,LOW); 
        delay(100); 
        digitalWrite(25,HIGH); 
        delay(100); 
        
       }

  else if(count==5){
        digitalWrite(27,LOW);
        digitalWrite(26,LOW); 
        delay(100); 
        digitalWrite(26,HIGH); 
        delay(100); 
        
       } 

  else if(count==6){
        digitalWrite(28,LOW);
        digitalWrite(27,LOW); 
        delay(100); 
        digitalWrite(27,HIGH); 
        delay(100); 
        
       } 

  else if(count==7){
        digitalWrite(29,LOW);
        digitalWrite(28,LOW); 
        delay(100); 
        digitalWrite(28,HIGH); 
        delay(100); 
        
       } 

  else if(count==8){
        digitalWrite(30,LOW);
        digitalWrite(29,LOW); 
        delay(100); 
        digitalWrite(29,HIGH); 
        delay(100); 
        
       } 

  else if(count==9){
        digitalWrite(31,LOW);
        digitalWrite(30,LOW); 
        delay(100); 
        digitalWrite(30,HIGH); 
        delay(100); 
        
       } 

  else if(count==10){
        digitalWrite(32,LOW);
        digitalWrite(31,LOW); 
        delay(100); 
        digitalWrite(31,HIGH); 
        delay(100); 
        
       } 

  else if(count==11){
        digitalWrite(33,LOW);
        digitalWrite(32,LOW); 
        delay(100); 
        digitalWrite(32,HIGH); 
        delay(100); 
        
       } 

  else if(count==12){
        digitalWrite(34,LOW);
        digitalWrite(33,LOW); 
        delay(100); 
        digitalWrite(33,HIGH); 
        delay(100); 
        
       } 

  else if(count==13){
        digitalWrite(35,LOW);
        digitalWrite(34,LOW); 
        delay(100); 
        digitalWrite(34,HIGH); 
        delay(100); 
        
       } 

  else if(count==14){
        digitalWrite(36,LOW);
        digitalWrite(35,LOW); 
        delay(100); 
        digitalWrite(35,HIGH); 
        delay(100); 
        
       }  

  else if(count==15){
        digitalWrite(37,LOW);
        digitalWrite(36,LOW); 
        delay(100); 
        digitalWrite(36,HIGH); 
        delay(100); 
        
       } 

  else if(count==16){
        digitalWrite(38,LOW);
        digitalWrite(37,LOW); 
        delay(100); 
        digitalWrite(37,HIGH); 
        delay(100); 
        
       } 

  else if(count==17){
        digitalWrite(39,LOW);
        digitalWrite(38,LOW); 
        delay(100); 
        digitalWrite(38,HIGH); 
        delay(100); 
        
       } 

  else if(count==18){ 
    if(n==18){ 
      digitalWrite(22,LOW);
      digitalWrite(39,LOW); 
      delay(100); 
      digitalWrite(39,HIGH); 
      delay(100); 
    } 
    else{
        digitalWrite(40,LOW);
        digitalWrite(39,LOW); 
        delay(100); 
        digitalWrite(39,HIGH); 
        delay(100); 
    } 
        
       } 

  else if(count==19){ 
    if(n==18){ 
      count=1;
    }
    else if(n==19){ 
      digitalWrite(22,LOW);
      digitalWrite(40,LOW); 
      delay(100); 
      digitalWrite(40,HIGH); 
      delay(100); 
      
    } 
    else {
        digitalWrite(41,LOW);
        digitalWrite(40,LOW); 
        delay(100); 
        digitalWrite(40,HIGH); 
        delay(100);  
    }
        
       } 

  else if(count==20){ 
    if(n==19){ 
      count=1;
    }  
    else if(n==20){ 
      digitalWrite(22,LOW);
      digitalWrite(41,LOW); 
      delay(100); 
      digitalWrite(41,HIGH); 
      delay(100);
    }
    else {
        digitalWrite(42,LOW);
        digitalWrite(41,LOW); 
        delay(100); 
        digitalWrite(41,HIGH); 
        delay(100);  
    }
        
       } 

  else if(count==21){
    if(n==20){ 
      count=1;
    } 
    else if(n==21){ 
      digitalWrite(22,LOW);
      digitalWrite(42,LOW); 
      delay(100); 
      digitalWrite(42,HIGH); 
      delay(100);
    } 
    else{
        digitalWrite(43,LOW);
        digitalWrite(42,LOW); 
        delay(100); 
        digitalWrite(42,HIGH); 
        delay(100); 
    }
       } 

  else if(count==22){ 
    if(n==21){ 
      count=1;
    } 
    else if(n==22){ 
      digitalWrite(22,LOW);
      digitalWrite(43,LOW); 
      delay(100); 
      digitalWrite(43,HIGH); 
      delay(100);
    } 
    else{
        digitalWrite(44,LOW);
        digitalWrite(43,LOW); 
        delay(100); 
        digitalWrite(43,HIGH); 
        delay(100); 
    }
       } 

  else if(count==23){ 
    if(n==22){ 
      count=1;
    } 
    else if(n==23){ 
      digitalWrite(22,LOW);
      digitalWrite(44,LOW); 
      delay(100); 
      digitalWrite(44,HIGH); 
      delay(100);
    } 
    else{
        digitalWrite(45,LOW);
        digitalWrite(44,LOW); 
        delay(100); 
        digitalWrite(44,HIGH); 
        delay(100); 
    }
       } 

  else if(count==24){
    if(n==23){ 
      count=1;
    } 
    else{
        digitalWrite(22,LOW);
        digitalWrite(45,LOW); 
        delay(100); 
        digitalWrite(45,HIGH); 
        delay(100); 
    } 
       } 

  else if(count==25) { 
    count=1;
  }
} 

void showNumber(uint8_t num)
{
    digit2=num % 10 ;
    digit1=(num / 10) % 10 ;
    //Send them to 7 segment displays
    uint8_t numberToPrint[]= {digits[digit2],digits[digit1]};
    sr.setAll(numberToPrint);  
} 

void writeEEPROM(int deviceaddress, unsigned int eeaddress, byte data){ 
  Wire.beginTransmission(deviceaddress); 
  Wire.write((int)(eeaddress >> 8));
  Wire.write((int)(eeaddress & 0xFF));
  Wire.write(data); 
  Wire.endTransmission(); 
  delay(5);
  } 

byte readEEPROM(int deviceaddress, unsigned int eeaddress){ 
  byte rdata=0xFF; 
  Wire.beginTransmission(deviceaddress); 
  Wire.write((int)(eeaddress >> 8)); 
  Wire.write((int)(eeaddress & 0xFF)); 
  Wire.endTransmission(); 
  Wire.requestFrom(deviceaddress,1); 
  if (Wire.available()){ 
    rdata = Wire.read(); 
    return rdata;
  } 
}
  
