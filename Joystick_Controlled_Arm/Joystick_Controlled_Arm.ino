#include<Servo.h>
int x,y,cy=60,cc=0,angle;
Servo b, e, c;
void setup() {

  
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
  pinMode(2,INPUT);
  hp();
}

void loop() 
{
x=analogRead(A3);
y=analogRead(A2);
if(y<250 && cy>=20)
{
  b.write(cy);
  e.write(cy+30);
  cy--;
  delay(30);
}
else if(y>750 && cy<=60)
{
  b.write(cy);
  e.write(cy+30);
  cy++;
  delay(30);
}
if(x<250)
{
  step4();
  step3();
  step2();
  step1();
  delay(100);
}
else if(x>750)
{
  step1();
  step2();
  step3();
  step4();
  delay(100);
}
if(digitalRead(2)==1)
{
  cc++;
  delay(300);
}
switch(cc)
  {
    case 1: for(angle=40;angle<=80;angle++)
    {
      c.write(angle);
      delay(40);
    }
    cc++;
    break;
    case 3:
    for(angle=80;angle>=40;angle--)
    {
      c.write(angle);
      delay(40);
    }
    cc++;
    break;
    case 5: cc=1;
    break;
  }
}
void hp()
{
  b.write(60);
  e.write(90);
  c.write(40);
}
void step1()
{
  digitalWrite(12,0);
  digitalWrite(13,1);
  digitalWrite(14,1);
  digitalWrite(15,1);
  delay(50);
}
void step2()
{
  digitalWrite(12,1);
  digitalWrite(13,0);
  digitalWrite(14,1);
  digitalWrite(15,1);
  delay(50);
}
void step3()
{
  digitalWrite(12,1);
  digitalWrite(13,1);
  digitalWrite(14,0);
  digitalWrite(15,1);
  delay(50);
}
void step4()
{
  digitalWrite(12,1);
  digitalWrite(13,1);
  digitalWrite(14,1);
  digitalWrite(15,0);
  delay(50);
}
