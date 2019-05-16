#ifndef XYCOORDS_H_INCLUDED
#define XYCOORDS_H_INCLUDED
#include <windows.h>

namespace CI
{
	class XYCoords
	{
	private:
		COORD XY;
	public:
		bool setXY(COORD);
		COORD getXY();
	};
}

#endif
