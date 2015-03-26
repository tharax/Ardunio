const int ledPin = 13;
const int interval = 1000;
int ledState = HIGH;
long lastTime = 0;
long doubleTime = 0;
long quadTime = 0;

void setup()
{
	// for(int i=0; i<14; i++)
	// {
	// 	if(i % 2 == 1)
	// 	{
	// 		pinMode(i, OUTPUT);
	// 	}
	// }
	pinMode(13, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(9, OUTPUT);
}

void loop()
{
	long timeNow = millis();
	
	if (timeNow - lastTime > interval)
	{
		lastTime = timeNow;
		if(ledState == HIGH)
		{
			ledState = LOW;
		}
		else
		{
			ledState = HIGH;
		}
		// for(int i=0; i<14; i++)
		// {
		// 	if(i % 2 == 0)
		// 	{
				// digitalWrite(i, ledState);
			// }
			// if(i % 2 == 1)
			// {
				digitalWrite(13, ledState);
				//digitalWrite(11, ledState);
				//digitalWrite(9, ledState);
		// 	}
		// }
	}
	if (timeNow - doubleTime > (2 * interval))
	{
		doubleTime = timeNow;
		if(ledState == HIGH)
		{
			ledState = LOW;
		}
		else
		{
			ledState = HIGH;
		}
		digitalWrite(11, ledState);
	}
	if (timeNow - quadTime > (4 * interval))
	{
		quadTime = timeNow;
		if(ledState == HIGH)
		{
			ledState = LOW;
		}
		else
		{
			ledState = HIGH;
		}
		digitalWrite(9, ledState);
	}
}