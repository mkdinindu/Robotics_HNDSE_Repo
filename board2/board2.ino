//logic of UNO board 2. controlls litterbox (gear motor and servo moter), Real time clock, and laser pointer in front

#include <Servo.h>
#include <RTClib.h>

RTC_DS3231 rtc;
Servo litterServo;
Servo laserServo;

const int PIRPin = 3;   
const int litterServoPin = 2;
const int input1 = 4;
const int input2 = 5;
const int input3 = 6;
const int input4 = 7;

const int laserServoPin = 9;
const int lightPin = 13;

int PIRValue = 0;

void setup() 
{
   Serial.begin(9600);

   pinMode(PIRPin, INPUT);
   pinMode(input1, OUTPUT); //input 1 of H bridge for gearmotor
   pinMode(input2, OUTPUT); //input 2 of H bridge for gearmotor
   pinMode(input3, OUTPUT); //input 3 of H bridge for gearmotor
   pinMode(input4, OUTPUT); //input 4 of H bridge for gearmotor
   
   litterServo.attach(litterServoPin);
   litterServo.write(115);
  
  	//real time clock ?????
  
  laserServo.attach(9);
  pinMode(laserServoPin, OUTPUT);
  pinMode(lightPin, OUTPUT);
  
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC!");
    Serial.flush();
    while (1) delay(10);
  }
} 


void loop()
{
  	PIRValue = digitalRead(PIRPin);
    
  if (PIRValue == HIGH) 
    {
        Serial.println("Motion detected");
        litterBoxInOut();
        
       
    } 
  else 
  	{
        Serial.println("No motion detected");
        delay(500);
    }
    
  delay(800);
  
  RTCStart();
  //throwBall();
  //moveLaser();
}

void litterBoxInOut()
{
  Serial.println("Motion detected!");
  Serial.println("PIRValue");
  	
  digitalWrite(input2, HIGH);
  digitalWrite(input1, LOW);
  delay(11000);
  
  digitalWrite(input2, LOW);
  digitalWrite(input1, LOW);
  delay(20000);

  Serial.println("Scooping");
  litterServo.write(60);
  delay(1000);
  litterServo.write(115);

  digitalWrite(input2, LOW);
  digitalWrite(input1, HIGH);
  delay(11000);
  digitalWrite(input2, LOW);
  digitalWrite(input1, LOW);


}



void moveLaser()
{
  digitalWrite(laserServoPin, HIGH);
  digitalWrite(lightPin, HIGH);  

  int randomAngle = random(0, 180);
  laserServo.write(randomAngle); 

  delay(3000);  // Wait for 3 seconds before moving again
}

void throwBall()
{
  

  int rs = random(0, 4);

  if(rs == 0){
    analogWrite(11, 220);
    Serial.println("230");
  }else if(rs == 1){
    analogWrite(11, 230);
    Serial.println("240");
  }else if(rs == 3){
    analogWrite(11, 255);
    Serial.println("255");
  }
  
  
  
  digitalWrite(6, HIGH);
  delay(220);
  digitalWrite(6, LOW);
  delay(2000);
 
    // Wait for 3 seconds before moving again
}

void RTCStart()
{
   DateTime now = rtc.now(); // Get the current time

  // Store individual time components in variables
  int year = now.year();
  int month = now.month();
  int day = now.day();
  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();

  // Print the time to the Serial Monitor
  Serial.print(year, DEC);
  Serial.print('/');
  Serial.print(month, DEC);
  Serial.print('/');
  Serial.print(day, DEC);
  Serial.print(' ');
  Serial.print(hour, DEC);
  Serial.print(':');
  Serial.print(minute, DEC);
  Serial.print(':');
  Serial.print(second, DEC);
  Serial.println();

  delay(1000);
  if(hour == 5 && minute == 38){
    int randomChoice = random(0, 1);
    if(randomChoice == 0)
    {
      for(int i = 0; i < 8; i++){
        moveLaser();
      }
      
    }
    else
    {
      throwBall();
    }
  } 
}