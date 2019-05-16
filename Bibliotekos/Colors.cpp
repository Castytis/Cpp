#include "stdafx.h"
#include "Colors.h"

namespace CI
{

	bool Color::setColor(short color)
	{// reikia suprogramuoti apsaugą nuo neteisingų reikšmių
		spalva = color;
		return false;
	}

	short Color::getColor()
	{
		return spalva;
	}

}
