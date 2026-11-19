/* Prog_00
Blikani led tam i zpet bez deformace
*/

int Pins_Out[] = {2,3,4,5,6,7,8,9};
unsigned char pozice = 0;
boolean dir = true;

int pocetLED;

int cas[]={200,400,800,1600};
char indexCasu;

void setup()
{
	// nastavení pinù na výstupní
	pinMode(10, INPUT);
	pinMode(11, INPUT);
	pinMode(18, INPUT);

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
	pocetLED = digitalRead(18) * 1 + 1;
	indexCasu = digitalRead(10) * 1 + digitalRead(11) * 2;

	// zhasni všechny LED
	for(int i = 0; i < 8; i++)
	{
		digitalWrite(Pins_Out[i], LOW);
	}

	// Posun
	if(dir)
	{
		if(pocetLED == 2)
		{
			if(++pozice > 6)
			{
				pozice = 5;
				dir = false;
			}
		}
		else if(pocetLED == 1)
		{
			if(++pozice > 7)
			{
				pozice = 6;
				dir = false;
			}
		}
	}
	else
	{
		if(--pozice == 0)
		{
			dir = true;
		}
	}

	// Rozsvícení LED
	if(pocetLED == 1)
	{
		digitalWrite(Pins_Out[pozice], HIGH);
	}
	else if(pocetLED == 2)
	{
		digitalWrite(Pins_Out[pozice], HIGH);
		digitalWrite(Pins_Out[pozice+1], HIGH);
	}

	delay(cas[indexCasu]);
}