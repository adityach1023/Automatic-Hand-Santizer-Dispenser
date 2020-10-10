const int servo = 9; //define Servo Signal Pin
const int trigPin = 10; //define Trigger Pin
const int echoPin = 11; //define Echo Pin

// defines variables

long duration;
int distance;

#include <Servo.h>

Servo myservo; // create servo object to control a servo

int pos = 0; // variable to store the servo position

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
myservo.attach(servo); // attaches the servo on pin 9 to the servo object
myservo.write(0); // Sets Servo to initially 0 degrees
Serial.begin(9600); // Starts the serial communication
}

void loop() {
//
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds

duration = pulseIn(echoPin, HIGH);

// Calculating the distance

distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.println("Distance: ");
Serial.println(distance);

//Servo

if(distance<10)
{ //Check distance is less than 10cm
myservo.write(45); // Sets Servo in stages from 0 to 180 degrees so soap does not pitch out.
delay(100);
myservo.write(90);
delay(100);
myservo.write(135);
delay(100);
myservo.write(120); //Ajust how far you want the servo to go.
delay(1000);
myservo.write(00); // Reset the servo to 0 Degrees
delay(2500); //Delay the next time someone can get soap
}
}
