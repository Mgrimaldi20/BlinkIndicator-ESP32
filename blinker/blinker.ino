bool drivecomplete = false;
bool reversecomplete = false;

void setup()
{
	// put your setup code here, to run once:
	pinMode(10, INPUT_PULLDOWN);  // reverse
	pinMode(11, INPUT_PULLDOWN);  // drive
	pinMode(22, OUTPUT);          // output horn
}

void loop()
{
	// put your main code here, to run repeatedly:
	if (digitalRead(10) == HIGH && !reversecomplete)
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
