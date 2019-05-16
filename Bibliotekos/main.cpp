#include "stdafx.h"
#include <iostream>
#include "windowInterface.h"
#include "Indicator.h"
#include "Menu.h"
#include "Text.h"
#include <vector>
#include <string>


using namespace std;

CI::Window langPagrindinis;
CI::Menu langMeniu;
CI::Indicator Indikatorius;
CI::Text text;
int main()
{

	HANDLE konsole = GetStdHandle(STD_OUTPUT_HANDLE);

	vector<string> Options;
	Options.push_back("Option1");
	Options.push_back("Option2");
	Options.push_back("Option355");
	Options.push_back("Option5");
	COORD SIZE, SIZE2;
	COORD POSITION,POSITION2;
	POSITION = { 4,2 };
	SIZE = {40,25};
	//setWindowInterface(Dydis, Pozicija, Spalva, Viengubi Rėmeliai, Dvigubi Rėmeliai)
	langPagrindinis.setWindowInterface({ 30,10 }, {50,12}, 0b00001111, false, true);
	//setMenuInterface(Dydis, Pozicija, Spalva Pasirinkimo, Fono Spalva, Pasirinkimų tekstai, Viengubi Rėmeliai, Dvigubi Rėmeliai)
	langMeniu.setMenuInterface(SIZE,POSITION, 0b11110000, 0b00001111 ,Options,false,true);
	//setIndicatorInterface(Ilgis, Pozicija, spalva)
	Indikatorius.setIndicatorInterface(40, {4,0}, 0b11110000);
	//setTextInterface(Dydis, Pozicija, Spalva, Viengubi Rėmeliai, Dvigubi Rėmeliai)
	text.setTextInterface({ 30,10 }, {50,2}, 0b11110000, true, false);
	text.printText("Lorem ipsum dolor sit amet, sea te rebum copiosae iracundia, lorem postea cu cum. Erant inciderint dissentiet cum ea, his.");
	Indikatorius.showIndicator("Hello World");

	while (1) {
		langPagrindinis.showWindow();
		langMeniu.showOptions();
		switch (langMeniu.getSelectedOption()) {
		case 0:
			Indikatorius.showIndicator(Options[langMeniu.getSelectedOption()]);
			text.printText("Lorem ipsum dolor sit amet, sea te rebum copiosae iracundia, lorem postea cu cum. Erant inciderint dissentiet cum ea, his.");
			break;
		case 1:
			Indikatorius.showIndicator(Options[langMeniu.getSelectedOption()]);
			text.printText("Lorem ipsum dolor sit amet, te sonet doming lucilius pro, quodsi iracundia eu sed, qui ex partem expetendis sadipscing duo.");
			break;
		case 2:
			text.printText("Lorem ipsum dolor sit amet, error reprimique efficiendi nam eu, no mea possim aperiri. Eu nam diceret fierent. Tation labitur.");
			Indikatorius.showIndicator(Options[langMeniu.getSelectedOption()]);
			break;
		default : 
			Indikatorius.showIndicator("There is no actions set for this Option");
		}

	}


	
	return 0;
}






