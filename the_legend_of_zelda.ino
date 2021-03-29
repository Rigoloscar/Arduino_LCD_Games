  #include<Wire.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 6, 5, 4, 3); 


byte atack [8]        
{ 0b01110,
  0b10110,
  0b00110,
  0b10100,
  0b11111,
  0b00100,
  0b01010,
  0b01001,
};

byte defend [8]      
{
  0b01110,
  0b01101,
  0b01100,
  0b00101,
  0b11111,
  0b00100,
  0b01010,
  0b10010,
};

byte live [8]
{
  0b00000,
  0b11011,
  0b11011,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
};

byte enemigo [8]
{
  0b01010,
  0b10001,
  0b11111,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b01010,
};

byte zelda1 [8] {
  
  0b00001,
  0b00111,
  0b00001,
  0b01111,
  0b10000,
  0b10111,
  0b10111,
  0b10000,
};

byte zelda2 [8] {
  0b10000,
  0b11100,
  0b10000,
  0b11110,
  0b00001,
  0b11101,
  0b11101,
  0b01101,
};

byte zelda4 [8] {
  
 0b11101,
 0b11001,
  0b00001,
  0b11101,
  0b11101,
  0b00010,
  0b11100,
  0b10000,
};

byte zelda5 [8] {
  
  0b10001,
  0b10011,
  0b10110,
  0b10111,
  0b10111,
  0b01000,
  0b00111,
  0b00001,
};

int boton1 = 2;
int boton2 = 7 ;
int state1 = 0;
int state2 = 0;
int juego = false;
int buzzerPin = 9;
int xplayer = 5;
int tiempo=150;
int xenemy = 0;
int enemy = false;
int ataque=false;
int vida=4;
int partida=true;
int contador=0;
const int nivel=14;


void setup() {
  
 lcd.begin(16,2);
 pinMode(boton1, INPUT);
 pinMode(boton2, INPUT);
 pinMode(buzzerPin, OUTPUT);
 lcd.createChar(1, atack);
 lcd.createChar(2,defend);
 lcd.createChar(3, live);
 lcd.createChar(4, enemigo);
 lcd.createChar(5, zelda1);
 lcd.createChar(6, zelda2);
 lcd.createChar(7, zelda4);
 lcd.createChar(8, zelda5);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.write(5);
 lcd.setCursor(1, 0);
 lcd.write(6);
 lcd.setCursor(1, 1);
 lcd.write(7);
 lcd.setCursor(0, 1);
 lcd.write(8);
 lcd.setCursor(2, 0);
 lcd.write("the legend of");
 lcd.setCursor(2, 1);
 lcd.write("ELDA");
 delay(5000);
 lcd.clear(); 
 lcd.setCursor(0, 1);
 lcd.write(3);
 lcd.setCursor(1, 1);
 lcd.write(3);
 lcd.setCursor(2, 1);
 lcd.write(3);
 lcd.setCursor(3, 1);
 lcd.write(3);
 ataque=false;
 juego=false;
 lcd.setCursor(5, 0);
 lcd.write(2);
}



void loop() {
 int impact=random(1, 7);
 state1=digitalRead(boton1);
 state2=digitalRead(boton2);

 

 
 
 if(vida==4&&contador<nivel){
 lcd.setCursor(0, 1);
 lcd.write(3);
 lcd.setCursor(1, 1);
 lcd.write(3);
 lcd.setCursor(2, 1);
 lcd.write(3);
 lcd.setCursor(3, 1);
 lcd.write(3);
 }
 else if(vida==3&&contador<nivel){
 lcd.setCursor(0, 1);
 lcd.write(3);
 lcd.setCursor(1, 1);
 lcd.write(3);
 lcd.setCursor(2, 1);
 lcd.write(3);
 lcd.setCursor(3, 1);
 lcd.write(" ");
 }
 else if(vida==2&&contador<nivel){
 lcd.setCursor(0, 1);
 lcd.write(3);
 lcd.setCursor(1, 1);
 lcd.write(3);
 lcd.setCursor(2, 1);
 lcd.write(" ");
 lcd.setCursor(3, 1);
 lcd.write(" ");  
 }
 else if(vida==1&&contador<nivel){
 lcd.setCursor(0, 1);
 lcd.write(3);
 lcd.setCursor(1, 1);
 lcd.write(" ");
 lcd.setCursor(2, 1);
 lcd.write(" ");
 lcd.setCursor(3, 1);
 lcd.write(" ");
 }
 else if(vida<=0&&partida==true&&contador<nivel){
 lcd.clear();
 lcd.setCursor(3, 0);
 lcd.write("LINK LOSED");
 lcd.setCursor(0, 1);
 lcd.write("try another time");
 enemy=false;
 ataque=false;
 partida=false;
 }
 if(contador>=nivel&&vida>0&&partida==true){
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.write("LINK WON");
  lcd.setCursor(0, 1);
  lcd.write("princess's saved");
  enemy=false;
  ataque=false;
  partida=false;
 }
 
 if(enemy==true&&vida>0&&contador<nivel){
  if(impact==5&&juego==true){
   tone(buzzerPin, 600, 200); 
   vida--;
   xenemy=xplayer; 
   lcd.setCursor(xenemy, 0);
   lcd.write("_");
   delay(600);
   lcd.setCursor(xenemy, 0);
   lcd.write(4);
   delay(tiempo); 
   xplayer++;
   lcd.setCursor(xplayer, 0);
   lcd.write(2);
   delay(tiempo);
   enemy=false;
   
   
   
  }
  else if(ataque==false&&impact!=5&&contador<nivel){
   xenemy=random(1, 14);
   if (xenemy!=xplayer){
   lcd.setCursor(xenemy, 0);
   lcd.write("_");
   delay(600);
   lcd.setCursor(xenemy, 0);
   lcd.write(4);
   enemy=false;
   ataque=false;
   }
  }
 }

 if(state2==HIGH&&xplayer>0&&state1==LOW&&vida>0&&contador<nivel){
  if(juego=false){
    enemy=true;
  }
  xplayer--;
  lcd.setCursor(xplayer, 0);
  lcd.write(2);
  lcd.setCursor(xplayer+1, 0);
  lcd.write(" ");
  delay(tiempo);
  
 }
  else if(state1==HIGH&&xplayer<15&&state2==LOW&&vida>0&&contador<nivel){
    if(juego=false){
    enemy=true;
    }
    xplayer++;
    lcd.setCursor(xplayer, 0);
    lcd.write(1);
    lcd.setCursor(xplayer-1, 0);
    lcd.write(" ");
    delay(tiempo);
    
  }
   else if(xplayer==xenemy&&ataque==false&&vida>0&&contador<nivel){
    enemy=true;
    juego=true;
    contador++;
    if(juego==true&&contador>0){
    tone(buzzerPin, 800, 90);
    }
    
   }
 }
 
