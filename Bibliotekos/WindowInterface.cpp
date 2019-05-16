#include "stdafx.h"
#include "WindowInterface.h"
#include "Colors.h"
#include "Text.h"
#include "XYCoords.h"
#include <typeinfo>
// consoleInterface.cpp //
namespace CI
{

	

	HANDLE Window::getAccessToConsole() {
		return console;
	}


	bool Window::setPosition(COORD dds)
	{
		return vieta.setXY(dds);
	}

	bool Window::setSize(COORD dds)
	{
		return dydis.setXY(dds);
	}



	COORD Window::getSize()
	{
		return dydis.getXY();
	}

	short Window::getFillColor()
	{
		return WindowColor.getColor();
	}

	short Window::setFillColor(short color) {
		return WindowColor.setColor(color);
	}

	COORD Window::getPosition()
	{
		return vieta.getXY();
	}

	void Window::setborder(bool singleBorders) {
		remeliai = singleBorders;
	}

	void Window::setborderDouble(bool doubleBorders) {
		dvigubiRemeliai = doubleBorders;
	}

	void Window::setWindowInterface(COORD Size, COORD Position, short Color, boolean SingleBorder, boolean DoubleBorder) {
		setSize(Size);
		setPosition(Position);
		if (Color < 256 && Color >= 0) {
			WindowColor.setColor(Color);
		}
		else {
			std::cout << "ERROR: In method 'setWindowInterface' attribute 'color' set incorrectly\n";
			exit(1);
		}
		if (SingleBorder && DoubleBorder) {
			std::cout << "ERROR: In method 'setWindowInterface' You should choose only one of the border types\n";
			exit(1);
		}
		else {
			setborder(SingleBorder);
			setborderDouble(DoubleBorder);
		}
	}

	void Window::showWindow()
	{
		SetConsoleTextAttribute(getAccessToConsole(), getFillColor());
		char borderH, borderV, ltCorner, rtCorner, lbCorner, rbCorner;
		COORD SIZE = getSize();
		COORD POSITION = getPosition();
		if (remeliai && dvigubiRemeliai || dvigubiRemeliai) {
			borderH = char(205);
			borderV = char(186);
			ltCorner = char(200);
			rtCorner = char(188);
			lbCorner = char(201);
			rbCorner = char(187);

		}
		else if (remeliai) {
			borderH = char(196);
			borderV = char(179);
			lbCorner = char(218);
			rbCorner = char(191);
			ltCorner = char(192);
			rtCorner = char(217);
		}
		else {
			borderH = ' ';
			ltCorner = ' ';
			rtCorner = ' ';
			lbCorner = ' ';
			rbCorner = ' ';
		}
			for (int i = 0; i < SIZE.Y; i++)
			{

				SetConsoleCursorPosition(getAccessToConsole(), POSITION);
				POSITION.Y++;
				if (i == SIZE.Y-1) {
					for (int j = 0; j < SIZE.X; j++)
					{
						if (j == 0) {
							std::cout << ltCorner;
						} else if (j==SIZE.X-1) {
							std::cout << rtCorner;
						} else {
							std::cout << borderH;
						}
					}
				} else if (i == 0) {
					for (int j = 0; j < SIZE.X; j++)
					{
						if (j == 0) {
							std::cout << lbCorner;
						}
						else if (j == SIZE.X - 1) {
							std::cout << rbCorner;
						}
						else {
							std::cout << borderH;
						}
					}
				}
				else {
					for (int j = 0; j < SIZE.X; j++)
					{
						if (j == 0 || j== SIZE.X-1) {
							std::cout << borderV;
						}
						else {
							std::cout << " ";
						}
					}
				}
				std::cout << "\n";

			}
		SetConsoleTextAttribute(getAccessToConsole(), 0b00001111);


	}
}
