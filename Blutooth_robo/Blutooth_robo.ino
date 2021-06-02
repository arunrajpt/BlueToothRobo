#define left1 2
#define left2 3

#define right1 4
#define right2 5
char a;
int trigPin =6 ;    // Trigger
int echoPin = 7;    // Echo
long duration, cm;
void setup() {
Serial.begin (9600);
pinMode(left1,OUTPUT);
pinMode(left2,OUTPUT);
pinMode(right1,OUTPUT);
pinMode(right2,OUTPUT);

 pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
 digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1;    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  //Serial.println(cm);
  //Serial.println("cm");
  delay(500);
  ////////////////////////////////
 if(Serial.available() > 0)
   {
    a=Serial.read(); 
    Serial.print(a);  
    }
   if(a=='1')
   {
//  Serial.print("hi");
    digitalWrite(left1,HIGH);
  digitalWrite(left2,LOW);
  digitalWrite(right1,HIGH);
  digitalWrite(right2,LOW);
   }
   else if(a=='2')
   {
    digitalWrite(left1,LOW);
  digitalWrite(left2,HIGH);
  digitalWrite(right1,LOW);
  digitalWrite(right2,HIGH);
   }
   else if(a=='3')
   {
    digitalWrite(left1,HIGH);
  digitalWrite(left2,LOW);
  digitalWrite(right1,LOW);
  digitalWrite(right2,HIGH);
  delay(200);
  digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  a=0;
   }
   else if(a=='4')
   {
    digitalWrite(left1,LOW);
  digitalWrite(left2,HIGH);
  digitalWrite(right1,HIGH);
  digitalWrite(right2,LOW);
  delay(200);
  digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  a=0;
   }
   else if(a=='0')
   {
    digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  Serial.print("stop");
   }
if(cm<=40)
{
  digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  delay(500);
   digitalWrite(left1,HIGH);
  digitalWrite(left2,LOW);
  digitalWrite(right1,HIGH);
  digitalWrite(right2,LOW);
  delay(1000);
   digitalWrite(left1,LOW);
  digitalWrite(left2,LOW);
  digitalWrite(right1,LOW);
  digitalWrite(right2,LOW);
  Serial.print("stop"); 
}

}
