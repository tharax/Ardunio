long interval = 1000, singleTime = 0, doubleTime = 0, quadTime = 0, eightTime = 0;

void setup()
{
	//Serial.begin(9600);
	setUpPin(13);
	setUpPin(12);
	setUpPin(11);
	setUpPin(9);
}

void loop()
{
	long timeNow = millis();
	checkTimer(timeNow, singleTime, interval, 13);
	//checkTimer(timeNow, doubleTime, 2 * interval, 12);
	//checkTimer(timeNow, quadTime, 4 * interval, 11);
	//checkTimer(timeNow, eightTime, 8 * interval, 9);
}

void checkTimer(long currentTime, long lastTime, long interval, int ledPin)
{
	if (currentTime - lastTime >= interval)
	{
		lastTime += interval;
		digitalWrite(ledPin, !digitalRead(ledPin));
		//Serial.println(currentTime);
	}
}

void setUpPin(int pin)
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}