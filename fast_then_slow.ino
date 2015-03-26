/* Flashing LED Version 2
 * ------------------------
 *
 * Turns on and off a light emitting diode(LED) connected to a digital  
 * pin, in intervals of 2 seconds using millis() function
 *
 */
int ledPin = 13;                 // LED connected to digital pin 13
unsigned long currentTime;
unsigned long loopTime;

void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  currentTime = millis();
  loopTime = currentTime;  
  Serial.begin(9600);
}

void loop()
{
  int val = !digitalRead(ledPin);
  Serial.println(val);
  digitalWrite(ledPin, val);   // toggles the LED on/off
  delay(1000);                  // waits for a second
}

// const int ledPin = 13;
// const int interval = 999;
// int ledState = HIGH;
// long lastTime = 0;
// long doubleTime = 0;
// long quadTime = 0;

// void setup()
// {
// 	Serial.begin(9600);
// 	pinMode(13, OUTPUT);
// 	digitalWrite(13, LOW);
// 	//pinMode(11, OUTPUT);
// 	//pinMode(9, OUTPUT);
// }

// void loop()
// {
// 	long timeNow = millis();
// 	if (timeNow - lastTime > interval)
// 	{
// 		lastTime = timeNow;
// 		switchLightBulb(13);
// 		Serial.println(lastTime);
// 	}
// 		// if(ledState == HIGH)
// 		// {
// 		// 	ledState = LOW;
// 		// 	Serial.print("off: ");
// 		// 	Serial.println(lastTime);
// 		// }
// 		// else
// 		// {
// 		// 	ledState = HIGH;
// 		// 	Serial.print("on:  ");
// 		// 	Serial.println(lastTime);
// 		// }
// 		// digitalWrite(13, ledState);
// 	// }
// 	// if (timeNow - doubleTime > (2 * interval))
// 	// {
// 	// 	doubleTime = timeNow;
// 	// 	if(ledState == HIGH)
// 	// 	{
// 	// 		ledState = LOW;
// 	// 		Serial.print("double off: ");
// 	// 		Serial.println(doubleTime);
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		ledState = HIGH;
// 	// 		Serial.print("double on:  ");
// 	// 		Serial.println(doubleTime);
// 	// 	}
// 	// 	digitalWrite(11, ledState);
// 	// }
// 	// if (timeNow - quadTime > (4 * interval))
// 	// {
// 	// 	quadTime = timeNow;
// 	// 	if(ledState == HIGH)
// 	// 	{
// 	// 		ledState = LOW;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		ledState = HIGH;
// 	// 	}
// 	// 	digitalWrite(9, ledState);
// 	// }
// }

// void switchLightBulb(int ledPin)
// {
// 	digitalWrite(ledPin, !digitalRead(ledPin));
// }