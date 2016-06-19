#include <SoftwareSerial.h>
int tempPin=0;
int termoResistorValue;
int twoLED =3;
int oneLED =2;
int a=7;
int b=6;
int c=5;
int d=11;
int e=10;
int f=8;
int g=9;
int dp=4;
String temperatureString = "";
void digital_1(void)
{
  unsigned char j;
  digitalWrite(c,LOW);//Set C Segment to low which lights this segment
  digitalWrite(b,LOW);//Set B Segment to low which lights this segment
  for(j=7;j<=11;j++)//Set the rest Segments to high which turn off this segment.
    digitalWrite(j,HIGH);
  digitalWrite(dp,HIGH);//Turn off DP segment (the little dot on the right down part)
}
//Display Number 2
void digital_2(void)
{
  unsigned char j;
  digitalWrite(b,LOW);
  digitalWrite(a,LOW);
  for(j=9;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(f,HIGH);
}
//Display Number 3
void digital_3(void)
{
  unsigned char j;
  digitalWrite(g,LOW);
  digitalWrite(d,LOW);
  for(j=5;j<=7;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(e,HIGH);
}
//Display Number 4
void digital_4(void)
{
  digitalWrite(c,LOW);
  digitalWrite(b,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);   
}
//Display Number 5
void digital_5(void)
{
  unsigned char j;
  for(j=7;j<=9;j++)
    digitalWrite(j,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(e,HIGH); 
}
//Display Number 6
void digital_6(void)
{
  unsigned char j;
  for(j=7;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(c,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(b,HIGH);   
}
//Display Number 7
void digital_7(void)
{
  unsigned char j;
  for(j=5;j<=7;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  for(j=8;j<=11;j++)
    digitalWrite(j,HIGH);
}
//Display Number 8
void digital_8(void)
{
  unsigned char j;
  for(j=5;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
}
void digital_9(void)
{
  unsigned char j;
  for(j=5;j<=9;j++)
    digitalWrite(j,LOW);
  digitalWrite(f,LOW);  
  digitalWrite(dp,HIGH);
  digitalWrite(e,HIGH);
}
void digital_0(void)
{
  unsigned char j;
  for(j=5;j<=8;j++)
    digitalWrite(j,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);   
  digitalWrite(dp,HIGH);
  digitalWrite(g,HIGH);
}
void drawDigit(char drawdigit){
  int value = drawdigit-'0'; 
  switch (value){
    case 1:
      digital_1();
      break;
    case 2: 
      digital_2();
      break; 
    case 3: 
      digital_3();
      break;
    case 4: 
      digital_4();
      break;
    case 5: 
      digital_5();
      break;
    case 6: 
      digital_6();
      break;
    case 7: 
      digital_7();
      break;
    case 8: 
      digital_8();
      break;
    case 9: 
      digital_9();
      break;
    default:
        digital_0();
    //break;          
    }
  }
void setup() {
  analogReference(INTERNAL); //  changing aRef to 1.1V for better resolution
  Serial.begin(9600);
  int i;//Set Pin Mode as output
  for(i=2;i<=11;i++)
    pinMode(i,OUTPUT);

}
void loop() {
  digitalWrite(oneLED,LOW);
  digitalWrite(twoLED,LOW);
  termoResistorValue = analogRead(tempPin);
  float temperatureInC=termoResistorValue / 9.3092; 
  /* 1.1V / 1024 = 1.0742 mV. 10 mV is equal to 1 degree Celsius.
  10/ 1.0742 ~9.3092 
  */
  temperatureString = (String)temperatureInC;
  char charToDraw = temperatureString.charAt(1);
  if (temperatureInC >= 10 and temperatureInC < 20) {
    digitalWrite(oneLED,HIGH);
    Serial.println(temperatureInC);

    }
  else if (temperatureInC >= 20 and temperatureInC < 30){
    digitalWrite(twoLED,HIGH);
    Serial.println(temperatureInC);
    }
  else {
    digitalWrite(twoLED,HIGH);
    digitalWrite(oneLED,HIGH);
    Serial.println(temperatureInC);
    }
    drawDigit(charToDraw);
    delay(5000);
}
