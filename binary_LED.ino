long interval = 10;
long pause = 1200 * interval;
long singleTime = 0, doubleTime = 0, quadTime = 0, eightTime = 0;
int one = 0, two = 0, three = 0, four= 0;

void setup()
{
	Serial.begin(9600);
	Serial.println("Start");
	setUpPin(13);
	setUpPin(12);
	setUpPin(11);
	setUpPin(9);
}

void loop()
{
	long timeNow = millis();
	if (timeNow - singleTime >= interval)
	{
		singleTime += interval;
		switchLightBulb(13);
		one++;
	}
	if (timeNow - doubleTime >= 2 * interval)
	{
		doubleTime += (2 * interval);
		switchLightBulb(12);
		two++;
	}
	if (timeNow - quadTime >= 4 * interval)
	{
		quadTime += (4 * interval);
		switchLightBulb(11);
		three++;
	}
	if (timeNow - eightTime >= 8 * interval)
	{
		eightTime += (8 * interval);
		switchLightBulb(9);
		four++;
	}
	if (timeNow >= pause)
	{
		Serial.println("counters");
		Serial.println(one);
		Serial.println(two);
		Serial.println(three);
		Serial.println(four);
		delay(600000);
		timeNow = 0;
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