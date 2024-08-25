bool drivecomplete = false;
bool reversecomplete = false;

void setup()
{
	pinMode(10, INPUT_PULLDOWN);  // reverse
	pinMode(11, INPUT_PULLDOWN);  // drive
	pinMode(22, OUTPUT);          // output horn
}

void loop()
{
	if ((digitalRead(10) == HIGH && !reversecomplete) && delay(1000))	// check if still high after a delay in case reverse is pass-through
	{
		for (int i=0; i<3; i++)
		{
			digitalWrite(22, HIGH);
			delay(200);
			digitalWrite(22, LOW);
			delay(200);
		}
	
		reversecomplete = true;
	}

	else if (digitalRead(10) == LOW)
		reversecomplete = false;

	if (digitalRead(11) == HIGH && !drivecomplete)
	{
		for (int i = 0; i < 2; i++)
		{
			digitalWrite(22, HIGH);
			delay(200);
			digitalWrite(22, LOW);
			delay(200);
		}

		drivecomplete = true;
	}
	
	else if (digitalRead(11) == LOW)
		drivecomplete = false;
}
