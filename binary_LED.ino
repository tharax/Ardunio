long interval = 50;
long singleTime = 0;
long doubleTime = 0;
long quadTime = 0;
long eightTime = 0;

void setup()
{
	setUpPin(13);
	setUpPin(12);
	setUpPin(11);
	setUpPin(9);
}

void loop()
{
	long timeNow = millis();
	if (timeNow - singleTime > interval)
	{
		singleTime = timeNow;
		switchLightBulb(13);
	}
	if (timeNow - doubleTime > 2 * interval)
	{
		doubleTime = timeNow;
		switchLightBulb(12);
	}
	if (timeNow - quadTime > 4 * interval)
	{
		quadTime = timeNow;
		switchLightBulb(11);
	}
	if (timeNow - eightTime > 8 * interval)
	{
		eightTime = timeNow;
		switchLightBulb(9);
	}
}

void switchLightBulb(int ledPin)
{
	digitalWrite(ledPin, !digitalRead(ledPin));
}

void setUpPin(int pin)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}