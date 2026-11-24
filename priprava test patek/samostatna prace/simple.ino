//naplnit pole nasledne naplnit matici
//definice promenych
int pole[100];
int matice[10][10];

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
	if(digitalRead(A0) == 0)
	{
		for(int s = 0; s < 100; s++)
		{
			pole[s] = random(-99,100);
			Serial.print(pole[s]);
		}
		for (int s = 0; s < 10; s++)
		{
			for (int j = 0; j < 10; j++)
			{
				matice[s][j] = random(-99,100);
				//zarovnani vseho
				Serial.print(" ");
				if (matice[s][j] > -10 && matice[s][j] <10)
				{
					Serial.print(" ");
				}
				if (matice[s][j] >= 0)
				{
					Serial.print(" ");
				}
				//vypsani matice
				Serial.print(matice[s][j]);

			}
			Serial.println();
		}
	}
}
