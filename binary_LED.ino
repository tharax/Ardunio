long interval = 50; // milliseconds
long Time1 = 0, Time2 = 0, Time3 = 0, Time4 = 0;

void setup()
{
	setUpPin(13);
	setUpPin(12);
	setUpPin(11);
	setUpPin(9);
}

void loop()
{
	long currentTime = millis();
	Time1 = switchLightBulb(currentTime, Time1, 1 * interval, 13);
	Time2 = switchLightBulb(currentTime, Time2, 2 * interval, 12);
	Time3 = switchLightBulb(currentTime, Time3, 4 * interval, 11);
	Time4 = switchLightBulb(currentTime, Time4, 8 * interval, 9);
}

void setUpPin(int LED)
{
	pinMode(LED, OUTPUT);
	digitalWrite(LED, LOW);
}

long switchLightBulb(long currentTime, long previousTime, long interval, int LED)
{
	if (currentTime - previousTime >= interval)
	{
		digitalWrite(LED, !digitalRead(LED));
		return previousTime + interval;
	}
	return previousTime;
}