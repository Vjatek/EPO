/* Prog_00
Blikani led tam i zpet bez deformace
*/

int Pins_Out[] = {2,3,4,5,6,7,8,9};
unsigned char pozice = 0;
boolean dir = true;

void setup()
{
	for (int i = 0; i < 8; i++)
	{
		pinMode(Pins_Out[i], OUTPUT);
		digitalWrite(Pins_Out[i], LOW);
	}

	digitalWrite(Pins_Out[pozice], HIGH);
	digitalWrite(Pins_Out[pozice+1], HIGH);
	delay(1000);
}

void loop()
{
	digitalWrite(Pins_Out[pozice], LOW);
	digitalWrite(Pins_Out[pozice+1], LOW);

	if(dir)
	{
		if (++pozice > 6)
		{
			pozice = 5;
			dir = false;
		}
	}
	else
	{
		if (--pozice == 0)
		{
			dir = true;
		}
	}

	digitalWrite(Pins_Out[pozice], HIGH);
	digitalWrite(Pins_Out[pozice+1], HIGH);
	delay(1000);
}