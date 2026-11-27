//odpoved na otazky
//1 - 1024
//2 - precist pin posuvniku a dat ho do promenne
//3 - ano
//4 - 6

//definice promennych
int Pins_Out[] = {2,3,4,5,6,7,8,9};
char pozice = 0;
boolean dir = true;

void setup()
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(Pins_Out[i], OUTPUT);
		digitalWrite(Pins_Out[i], LOW);
	}

	digitalWrite(Pins_Out[pozice], HIGH);
	digitalWrite(Pins_Out[pozice + 1], HIGH);

}

void loop()
{
	int rychl = map(analogRead(A0), 0, 1023, 100, 1000);	
	//vypnuti vsech ledek
	for(int i = 0; i < 8; i++)
	{
		digitalWrite(Pins_Out[i], LOW);
	}
	if(dir == true)
	{
		if(pozice > 6)
		{
			pozice = 7;
			digitalWrite(Pins_Out[pozice], HIGH);
			dir = false;
		}
		else
		{

			digitalWrite(Pins_Out[pozice], HIGH);
			digitalWrite(Pins_Out[pozice + 1], HIGH);
			pozice++;
		}
	}
	else if(dir == false)
	{
		if (pozice < 1)
		{
			pozice = 0;
			digitalWrite(Pins_Out[pozice], HIGH);
			dir = true;
		}
		else
		{
			pozice--;
			digitalWrite(Pins_Out[pozice], HIGH);
			digitalWrite(Pins_Out[pozice + 1], HIGH);

		}
	}
	delay(rychl);

}
