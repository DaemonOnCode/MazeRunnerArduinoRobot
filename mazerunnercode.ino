const int trig = A0;
const int echo = A1;
const int ftrig = A2;
const int fecho = A3;
long duration,fduration,distance,fdistance;

int fsensorHit=0;
int rsensorHit=0;
int alligned=0;
void setup() {

pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(ftrig,OUTPUT);
pinMode(fecho,INPUT);
}

void loop() {
digitalWrite(trig,LOW);
delayMicroseconds(2);  
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
duration = pulseIn(echo,HIGH);
distance = duration/58; 
digitalWrite (ftrig,LOW);
delayMicroseconds(2);
digitalWrite(ftrig,HIGH);
delayMicroseconds(10);
digitalWrite(ftrig,LOW);
fduration = pulseIn(fecho,HIGH);
fdistance = fduration/58;

if (fdistance<10)
  {
    fsensorHit=1;
  }
else
  {
    fsensorHit=0;
  }
  if ((distance>3) && (distance<=2) && (fsensorHit==0))
   {
    alligned=1;
   }
  else if (distance<=8)
   {
    rsensorHit=1;
   }
  else
  {
  alligned=0;
  rsensorHit=0;
  }
  if(fsensorHit==0)
  {
    
   if(rsensorHit==1)
    {
       analogWrite(6,60);
digitalWrite(10,LOW);

analogWrite(11,60);
digitalWrite(5,LOW);
  }
 
    else if(rsensorHit==0)
    {
      
      analogWrite(6,10);
digitalWrite(10,LOW);

analogWrite(11,60);
digitalWrite(5,LOW);

    }
    
     }
else if(fsensorHit==1)
{
  if(rsensorHit==1)
  {analogWrite(6,60);
digitalWrite(10,LOW);

analogWrite(11,10);
digitalWrite(5,LOW);

delay(1200);


}
else if(rsensorHit==0)
{
  analogWrite(6,10);
digitalWrite(10,LOW);

analogWrite(11,60);
digitalWrite(5,LOW);

}
} 

}