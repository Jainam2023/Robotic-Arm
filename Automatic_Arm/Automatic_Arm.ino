#include<Servo.h>
Servo l, r, c;
int cr=90,cl=40;
void setup() {
  l.attach(4);
  r.attach(5);
  c.attach(6);
}

void loop() {
int x=analogRead(A3);
int y=analogRead(A2);
r.write(0);
if(y>750)
{
  cr++;
  l.write(cr);
  delay(50);
}
if(y<250)
{
  cr--;
  l.write(cr);
  delay(50);
}
if(x>750)
{
  cl++;
  c.write(cl);
  delay(10);
}
if(x<250)
{
  cl--;
  c.write(cl);
  delay(10);
}
}
