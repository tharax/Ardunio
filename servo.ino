/*
	Control a Servo, without using Ardunio Servo library.
	At the time of writing, the library wouldn't compile.
	github.com/tharax
*/

int servo = 14; //pin A0
int angle, pwm;

void setup()
{
	pinMode(servo, OUTPUT);
}

void loop ()
{
	for (angle = 0; angle <= 180; angle += 5)
	{
		servoPulse(servo, angle);
	}
	for (angle = 180; angle >= 0; angle -= 5)
	{
		servoPulse(servo, angle);
	}
}

void servoPulse (int servo, int angle)
{
	pwm = (angle * 11) + 500;      // Convert angle to microseconds
	digitalWrite(servo, HIGH);
	delayMicroseconds(pwm);
	digitalWrite(servo, LOW);
	delay(50);                   // Refresh cycle of servo
}