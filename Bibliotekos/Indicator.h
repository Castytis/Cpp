#ifndef INDICATOR_H_INCLUDED
#define INDICATOR_INCLUDED

#include "WindowInterface.h"
#include <string>
#include "Text.h"

namespace CI
{
	class Indicator
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		short Length;
		COORD Position;
		short Color;
	public:
		void showIndicator(std::string);
		void setIndicatorInterface(short, COORD, short);
		void setColor(short);
		void setLength(short);
		void setPosition(COORD);
		HANDLE getAccessToConsole();
		COORD getPosition();
		short getColor();
		short getLength();
	};
}

#endif // INDICATOR_H_INCLUDED

