#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

#define ZELENA 2
#define BUTTON_PIN_1 8
#define RUMENA 4  
#define BUTTON_PIN_2 12 
#define RDECA 7 
#define BUTTON_PIN_3 13 

LiquidCrystal_I2C lcd(0x27,20,4);

bool IGRALEC_1 = 0;
bool IGRALEC_2 = 0;
bool IGRALEC_3 = 0;
bool x = 0;
bool z = 0;
bool y = 0;
bool q= 0;
int zaporedje;

bool prt_1 = false;
bool prt_2 = false;
bool prt_3 = false;

void setup() {
  pinMode(ZELENA, OUTPUT);
  pinMode(RUMENA, OUTPUT);
  pinMode(RDECA, OUTPUT);
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(BUTTON_PIN_3, INPUT); 
  Serial.begin(9600);
  Serial.println("dela");

  lcd.init();  
  lcd.backlight();
}

void loop(){
  IGRALEC_1 = digitalRead(BUTTON_PIN_1);
  IGRALEC_2 = digitalRead(BUTTON_PIN_2); 
  IGRALEC_3 = digitalRead(BUTTON_PIN_3);
  lcd.setCursor(0,0);
  lcd.print("1:");
  lcd.setCursor(8,0);
  lcd.print("2:");
  lcd.setCursor(3,1);
  lcd.print("3:");
  if ((IGRALEC_1 ==  HIGH) || (IGRALEC_2 ==  HIGH) || (IGRALEC_3 ==  HIGH)){
     digitalWrite(ZELENA, LOW);
     digitalWrite(RUMENA, HIGH);
     x = 1;

        while (x == 1){
          if ((y==1) && (q==1) && (z==1)){
            digitalWrite(RUMENA, LOW);

            while(true){
              digitalWrite(RDECA, HIGH);
              delay(100);
              digitalWrite(RDECA, LOW);
              delay(100);
            }            
          }
          
          IGRALEC_1 = digitalRead(BUTTON_PIN_1);
          IGRALEC_2 = digitalRead(BUTTON_PIN_2); 
          IGRALEC_3 = digitalRead(BUTTON_PIN_3);  
          if (IGRALEC_1 == HIGH&&prt_1 == false){
              zaporedje++;
              Serial.println(zaporedje);
              if (zaporedje==1&&prt_1 == false){
              Serial.println("IGR1");
              lcd.setCursor(2,0);
              lcd.print("IGR1");
              }
              else if (zaporedje==2&&prt_1 == false){
              Serial.println("IGR1");
              lcd.setCursor(10,0);
              lcd.print("IGR1");
              }
              else if (zaporedje==3&&prt_1 == false){
              Serial.println("IGR1");
              lcd.setCursor(5,1);
              lcd.print("IGR1");
              }
              prt_1 = true;
                        
            y = 1;
          }
          if (IGRALEC_2 == HIGH&&prt_2 == false){
              zaporedje++;
              Serial.println(zaporedje);
              if (zaporedje==1&&prt_2 == false){
              Serial.println("IGR2");
              lcd.setCursor(2,0);
              lcd.print("IGR2");

              }
              else if (zaporedje==2&&prt_2 == false){
              Serial.println("IGR2");
              lcd.setCursor(10,0);
              lcd.print("IGR2");
              }
              else if (zaporedje==3&&prt_2 == false){
              Serial.println("IGR2");
              lcd.setCursor(5,1);
              lcd.print("IGR2");
              }
              prt_2 = true;
            q = 1;
          }
          if (IGRALEC_3 == HIGH&&prt_3 == false){
              zaporedje++;
              Serial.println(zaporedje);
              if (zaporedje==1&&prt_3 == false){
              Serial.println("IGR3");
              lcd.setCursor(2,0);
              lcd.print("IGR3");
              }
              else if (zaporedje==2&&prt_3 == false){
              Serial.println("IGR3");
              lcd.setCursor(10,0);
              lcd.print("IGR3");
              }
              else if (zaporedje==3&&prt_3 == false){
              Serial.println("IGR3");
              lcd.setCursor(5,1);
              lcd.print("IGR3");
              }
              prt_3 = true;
            z = 1;
          } 
                          
        
        }
}

  else {digitalWrite(ZELENA, HIGH);}
   
}

