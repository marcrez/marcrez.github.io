/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */


#define echoPin 12 // Echo Pin
#define trigPin 11 // Trigger Pin
#define LEDPin 13 // Onboard LED

int motor1_enablePin = 4; //pwm
int motor1_in1Pin = 2;
int motor1_in2Pin = 3;
 
int motor2_enablePin = 5; //pwm
int motor2_in1Pin = 6;
int motor2_in2Pin = 7;
 

int minimumRange = 10; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 
   //on initialise les pins du moteur 1
  pinMode(motor1_in1Pin, OUTPUT);
  pinMode(motor1_in2Pin, OUTPUT);
  pinMode(motor1_enablePin, OUTPUT);
 
  //on initialise les pins du moteur 2
  pinMode(motor2_in1Pin, OUTPUT);
  pinMode(motor2_in2Pin, OUTPUT);
  pinMode(motor2_enablePin, OUTPUT);
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
  SetMotor1(200, true);
  SetMotor2(200, true);
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(LEDPin, LOW);
   SetMotor2(0, true);
   SetMotor1(175, false);
 
 }
 
 //Delay 50ms before next reading.
 delay(50);
}


//Fonction qui set le moteur1
void SetMotor1(int speed, boolean reverse)
{
  analogWrite(motor1_enablePin, speed);
  digitalWrite(motor1_in1Pin, ! reverse);
  digitalWrite(motor1_in2Pin, reverse);
}
 
//Fonction qui set le moteur2
void SetMotor2(int speed, boolean reverse)
{
  analogWrite(motor2_enablePin, speed);
  digitalWrite(motor2_in1Pin, ! reverse);
  digitalWrite(motor2_in2Pin, reverse);
}
