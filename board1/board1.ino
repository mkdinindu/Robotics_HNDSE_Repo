#include <Servo.h>

Servo foodServo;

const int foodServoPin = 6;
const int foodPIR = 5;
const int foodIR = 7;
int fPirRead = 0; // variable to store the PIR sensor status (value) - for food
int irRead = 0; // veriable to store the IR sensor status

const int solonoidValve = 13;    
const int waterPIR = 2;  
const int trigger = 3;
const int echo = 4;
int wPirRead = 0; // variable to store the PIR sensor status (value) - for water


void setup() 
{
  foodServo.write(47); //start with lid closed
  foodServo.attach(foodServoPin); //connect to pin
  pinMode(foodPIR, INPUT);
  
  pinMode(solonoidValve, OUTPUT);   
  pinMode(waterPIR, INPUT);            
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT); 
  
  Serial.begin(9600);
}

void loop()
{
  detectCat();
  dispenseFood();
}

void dispenseFood()
{
  irRead = digitalRead(foodIR);
  fPirRead = digitalRead(foodPIR);
  
  if (fPirRead == HIGH)
  {
    Serial.println("Motion detected!");
    if(irRead == HIGH)
    {
      delay(100); // to read output
      foodServo.write(0); //open lid
      delay(1000);
      foodServo.write(47);
    }
    else
    {
      foodServo.write(47); // keep lid closed
    }
  }
  else
  {
    delay(100); //read output
    Serial.println("Motion stopped");
    foodServo.write(47); // keep lid closed
  }
}

void detectCat()
{
  wPirRead = digitalRead(waterPIR);   // read sensor value
  if (wPirRead == HIGH)
  {           
    waterDetectAndDispense();  // check if the ultrasonic sensor can detect water and if so, dispense
    Serial.println("Motion detected!");
    delay(100);   // to read output 
  } 
  else
  {      
     Serial.println("Motion stopped!");
     delay(100); // to read output   
  }
}

void waterDetectAndDispense()
{ 
  Serial.println("Water Detected!");

  digitalWrite(trigger, HIGH);
  digitalWrite(trigger, LOW);
  
  int time = pulseIn(echo, HIGH);
  int waterThere = 0.0343*time/2; //waterThere = distance
  Serial.println("Distance :" + waterThere);
  if(waterThere > 4)
  {
    digitalWrite(solonoidValve, LOW); // open valve to dispense water
    Serial.println("Filling Water");
    delay(7000); // to fill the bowl
    digitalWrite(solonoidValve, HIGH); // close valve
  }
  else
  {
    digitalWrite(solonoidValve, HIGH); // keep valve closed
    Serial.println("Not filling water");
  }
}