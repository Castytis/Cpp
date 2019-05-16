#include "stdafx.h"
#include "XYCoords.h"

namespace CI
{

	COORD XYCoords::getXY()
	{
		return XY;
	}

	bool XYCoords::setXY(COORD koordinate)
	{
		// Įprogramuoti apsaugą nuo neteisingų reikšmių
		XY.X = koordinate.X;
		XY.Y = koordinate.Y;
		return true;
	};

}
