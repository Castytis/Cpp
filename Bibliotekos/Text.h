#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include "WindowInterface.h"
#include <string>
#include "XYCoords.h"

namespace CI
{
	class Text :public Window
	{
	public:
		void printText(std::string);
		void setTextInterface(COORD, COORD, short, boolean, boolean);
	};
}

#endif // TEXT_H_INCLUDED

