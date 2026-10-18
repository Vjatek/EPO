
/*	Prog_00
	Blikani LED tam i zpet
*/
//Deklarace promennych
int Pins_Out[] = {2,3,4,5,6,7,8,9}; //je to jako 0 1 2 3 4 5 6 7
unsigned char pozice=0; //deklarace promenne pozice a dani hodnoty (jde to delat v setupu) toto jsou globalni promenny
boolean smer;
//metoda setup

void setup()
{
	smer=true;
	for (int i=0; i<8; i++)
	{
		pinMode(Pins_Out[i], OUTPUT);
		digitalWrite(Pins_Out[i], LOW);
	}
	digitalWrite(Pins_Out[pozice], HIGH);
	delay(1000);
}
//metoda Loop
void loop()
{
	digitalWrite(Pins_Out[pozice], LOW);
	if (smer)
	{	
		if (++pozice > 7)
		{
			pozice=6; //vysledkem zavorky je true nebo false
			smer=false;	
		}
	}
	else
	{
		if (--pozice == 255)
		{
			pozice=1; //je to unsigned char kdyz od nuly odectu jednicku je to 255
			smer=true;
		}
	}
	digitalWrite(Pins_Out[pozice], HIGH);
	delay(1000);
}
//4 prepinace 4 rychlosti bez podminek pomoci pole
//nikdy nesmime pouzit pin 13 jako vstupni protoze tam je ledka!!!!
//pin 0, 1 se nesmi pouzit jako vstup protoze je tam seriova linka