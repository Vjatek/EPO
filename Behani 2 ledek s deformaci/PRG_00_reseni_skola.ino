
/*	Prog_00
	Blikani LED tam i zpet
*/
//Deklarace promennych
int Pins_Out[] = {2,3,4,5,6,7,8,9}; //je to jako 0 1 2 3 4 5 6 7
unsigned char pozice=1; //deklarace promenne pozice a dani hodnoty (jde to delat v setupu) toto jsou globalni promenny
boolean smer = true;
//metoda setup

void setup()
{
	for (int i=0; i<8; i++)
	{
		pinMode(Pins_Out[i], OUTPUT);
		digitalWrite(Pins_Out[i], LOW);
	}
	digitalWrite(Pins_Out[pozice], HIGH);
	digitalWrite(Pins_Out[pozice-1], HIGH);
	delay(500);
}
//metoda Loop
void loop()
{
	digitalWrite(Pins_Out[pozice], LOW);
	digitalWrite(Pins_Out[pozice-1], LOW);
	if (smer)//if resi pouze true nebo false
	{	
		if (++pozice > 7)//pricte jednicku pak resi podminku
		{
			pozice=7;
			smer=false;
			digitalWrite(Pins_Out[pozice], HIGH);
			delay(500);
		}
	}
	else
	{
		if (--pozice == 0)
		{
			smer=true;
			digitalWrite(Pins_Out[pozice], HIGH);
			delay(500);
			pozice=1;
		}
	}
	digitalWrite(Pins_Out[pozice], HIGH);
	digitalWrite(Pins_Out[pozice-1], HIGH);
	delay(500);
}
//4 prepinace 4 rychlosti bez podminek pomoci pole
//nikdy nesmime pouzit pin 13 jako vstupni protoze tam je ledka!!!!
//pin 0, 1 se nesmi pouzit jako vstup protoze je tam seriova linka