/*
	Dagu Motor Experiments
	github.com/tharax
*/

#include "AFMotor.h" //Motor Library

AF_DCMotor leftMotor(1);
AF_DCMotor rightMotor(2);

int currentSpeed = 127;
int currentDirection = FORWARD;
long duration, distance;

void setup()
{
	Serial.begin(9600); //Debugging console

	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);

	pinMode(A4, OUTPUT); //trigPin
	pinMode(A5, INPUT); //echoPin

	leftMotor.setSpeed(currentSpeed);
	rightMotor.setSpeed(currentSpeed);
	leftMotor.run(currentDirection);
	rightMotor.run(currentDirection);
}

void loop()
{
	ping();//Sonar ping


	if (distance < 15 && distance > 0)
	{
		//turn around
		TurnAround(currentDirection);
	}
	else
	{
		//continue
	}

	//Debugging code
	if (distance >= 200 || distance <= 0)
	{
		Serial.println("Outside Range");
	}
	else
	{
		Serial.print(distance);
		Serial.println("0 mm");
	}
}


void TurnAround (int currentDirection)
{
	leftMotor.run(FORWARD);
	rightMotor.run(BACKWARD);
	delay(300);
	rightMotor.run(FORWARD);
}

void ping ()
{
	digitalWrite(A4, HIGH);
	delayMicroseconds(10);
	digitalWrite(A4, LOW);
	duration = pulseIn(A5, HIGH);
	distance = (duration / 2) / 29.1;
}