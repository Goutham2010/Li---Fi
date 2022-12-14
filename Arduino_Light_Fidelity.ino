#include<LiquidCrystal.h>

int ir = 10;
int buzzer = 8;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, ct = 9;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

#define ldr 7

int val;
int val2;
String duration;

void setup() {
  // put your setup code here, to run once:
  analogWrite(ct,50);
  Serial.begin(9600);
  pinMode(ldr, INPUT_PULLUP);
  pinMode(ir, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  lcd.begin(16,2);
  lcd.print("Namaste Sir");
  lcd.setCursor(0,1);
  lcd.print("or Madam");
  delay(4000);
  lcd.clear();
  lcd.print("Welcome to Scie-");
  lcd.setCursor(0,1);
  lcd.print("nce Exhibition");
  delay(3000);
  lcd.clear();
  lcd.print("By Chiranthan");
  lcd.setCursor(0,1);
  lcd.print("and Goutham");
  delay(3000);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int irStatus = digitalRead(ir);
  if (irStatus == 1){
  digitalWrite(buzzer, HIGH);
  }

  else{
    digitalWrite(buzzer, LOW);
  }
  int val = digitalRead(ldr);
  while(val == 0)
  {
    int val2 = digitalRead(ldr);
    duration += val2;
    if(duration == "001")
    {
      Serial.println("Received message: hi");
      lcd.clear();
      lcd.clear();
      lcd.print("hi");
    }
    if(duration == "0001")
    {
      Serial.println("Received message: hello");
      lcd.clear();
      lcd.clear();
      lcd.print("hello");
    }
    if(duration == "00001")
    {
      Serial.println("Received message: how are you?");
      lcd.clear();
      lcd.clear();
      lcd.print("how are you?");
    }
    if(duration == "000001")
    {
      Serial.println("Received message: I am fine");
      lcd.clear();
      lcd.clear();
      lcd.print("I am fine");
    }
    if(duration == "0000001")
    {
      Serial.println("Received message: ok");
      lcd.clear();
      lcd.clear();
      lcd.print("ok");
    }
    if(duration == "00000001")
    {
      Serial.println("Received message: good morning");
      lcd.clear();
      lcd.clear();
      lcd.print("good morning");
    }
    if(duration == "000000001")
    {
      Serial.println("Received message: good afternoon");
      lcd.clear();
      lcd.clear();
      lcd.print("good afternoon");
    }
    if(duration == "0000000001")
    {
      Serial.println("Received message: good evening");
      lcd.clear();
      lcd.print("good evening");
    }
    if(duration == "00000000001")
    {
      Serial.println("Received message: thank you");
      lcd.clear();
      lcd.clear();
      lcd.print("thank you");
    }
    if(duration == "000000000001")
    {
      Serial.println("Received message: sorry");
      lcd.clear();
      lcd.clear();
      lcd.print("sorry");
    }
    if(val2 == 1)
    {
      duration = "";
      break;
    }
    delay(200);
  }
}
