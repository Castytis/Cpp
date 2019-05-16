// consoleInterface.h //
#ifndef windowInterface_H
#define windowInterface_H
#include <iostream>
#include <windows.h>
#include "XYCoords.h"
#include "Colors.h"

namespace CI
{

	class Window
	{
		XYCoords dydis, vieta;
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		Color WindowColor;
		bool remeliai, dvigubiRemeliai;
		void setborder(bool);
		void setborderDouble(bool);
		
	public:
		HANDLE getAccessToConsole();
		bool setPosition(COORD);
		bool setSize(COORD);
		COORD getSize();
		short setFillColor(short);
		short getFillColor();
		COORD getPosition();
		void setWindowInterface(COORD, COORD, short, boolean, boolean);
		void showWindow();
		//void setMenu();
	};
}


#endif


