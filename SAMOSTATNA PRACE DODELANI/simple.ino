
/*	This is a default program--
	Use File->Load Prog to load a different program
*/

int pole[100];
int matice[10][10];
int zmena = 0;
int posledniZmena = 0;	

void setup()
{
	pinMode(A0, INPUT);
	Serial.begin(9600);
	while(!Serial)
	{
		;
	}
	Serial.println("Serial OK");
}

void loop()
{
	zmena = digitalRead(A0);
	if (zmena != posledniZmena && zmena == 0)
	{
		for(int s = 0; s < 100; s++)
		{
			pole[s] = random(-99,100);
			Serial.print(pole[s]);
		}
		for(int s = 0; s < 10; s++)
		{
			for(int r = 0; r < 10; r++)
			{
				matice[s][r] = random(-99, 100);

				Serial.print(" ");
				if(matice[s][r] < 10 && matice[s][r] > -10)
				{
					Serial.print(" ");
				}
				if(matice[s][r]>=0)
				{
					Serial.print(" ");
				}

				Serial.print(matice[s][r]);

			}
			Serial.println();
		}
	}
	posledniZmena = zmena;
}

