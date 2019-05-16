#include "stdafx.h"
#include "Menu.h"
#include <vector>
#include <string>
#include <conio.h>
#include "Text.h"

namespace CI
{
	Window background;
	HANDLE options = GetStdHandle(STD_OUTPUT_HANDLE);
	short Menu::getSelectedOption()
	{
		return selectedOption;
	}

	short Menu::getColor()
	{
		return Color.getColor();
	}

	void Menu::setTextColor(short color)
	{
		Color.setColor(color);
	}

	void Menu::setOptions(std::vector<std::string> items) {
		Menu::Options = items;
	}

	std::vector<std::string> Menu::getOptions() {
		return Menu::Options;
	}

	void Menu::setMenuInterface(COORD SIZE, COORD POSITION, short color,short backgroundColor,std::vector<std::string> Options, boolean Single, boolean Double) {
		background.setWindowInterface({SIZE.X,short(Options.size()*5+2)}, POSITION, backgroundColor, Single, Double);
		background.showWindow();
		SIZE.X = SIZE.X - 10;
		if (SIZE.X > 0) {
			setSize(SIZE);
		}
		else {
			std::cout << "ERROR: Too small size\n";
			exit(1);
		}
		setPosition(POSITION);
		if (color < 256 && color >= 0) {
			setTextColor(color);
		}
		else {
			std::cout << "ERROR: In method 'setMenuInterface' attribute 'color' set incorrectly\n";
			exit(1);
		}
		setOptions(Options);
	}
	void Menu::ManageOptions() {
		unsigned int Longest = Options[0].length();
		for (std::vector<std::string>::iterator it = Options.begin(); it != Options.end(); ++it) {
			if ((*it).length() > Longest) {
				Longest = (*it).length();
			}
		}
		char ch;
		bool entered = false;
		short color = getColor();
		COORD POSITION = getPosition();
		POSITION.X = POSITION.X + 5;
		POSITION.Y = POSITION.Y + 2;
		COORD SIZE = getSize();
		COORD CONSTPOSITION = POSITION;
		SetConsoleCursorPosition(options, POSITION);
		//CONSTPOSITION.Y = CONSTPOSITION.Y + 1;
		POSITION.Y = POSITION.Y + 1;
		POSITION.X = POSITION.X+(((SIZE.X - Longest) + 1) / 2)-3;
		SetConsoleCursorPosition(options, POSITION);
		SetConsoleTextAttribute(options, color);
		std::cout<<">> " + Options[(POSITION.Y - (CONSTPOSITION.Y - 1)) / 5] + " <<";
		do {
			ch = _getch();
			if (ch != '\0')
			{
				if (ch == 'H') {
					SetConsoleCursorPosition(options, POSITION);
					SetConsoleTextAttribute(options, color);
					std::cout << "   " << Options[(POSITION.Y - (CONSTPOSITION.Y - 1)) / 5] << "   ";
					entered = false;
					if (POSITION.Y - 5 > CONSTPOSITION.Y)
						POSITION.Y = POSITION.Y - 5;
					SetConsoleCursorPosition(options, POSITION);
					std::cout<<">> " + Options[(POSITION.Y - (CONSTPOSITION.Y - 1)) / 5] + " <<";
				}
				else if (ch == 'P') {
					SetConsoleCursorPosition(options, POSITION);
					SetConsoleTextAttribute(options, color);
					std::cout << "   " << Options[(POSITION.Y - (CONSTPOSITION.Y - 1)) / 5] << "   ";
					entered = false;
					if (POSITION.Y + 5 < CONSTPOSITION.Y + Options.size()*5)
						POSITION.Y = POSITION.Y + 5;
					SetConsoleCursorPosition(options, POSITION);
					std::cout << ">> " + Options[(POSITION.Y - (CONSTPOSITION.Y - 1)) / 5] + " <<";

				}
				else if(ch=='\r') {
					if (!entered) {
						std::cout << " " << Options[(POSITION.Y - (CONSTPOSITION.Y - 1)) / 5];
						selectedOption = (POSITION.Y - (CONSTPOSITION.Y - 1)) / 5;
						entered = true;
						SetConsoleTextAttribute(options, 0b00001111);
						system("CLS");
						break;
					}
				}
			}
		} while (ch != 'e');

	}

	void Menu::drawMenu(COORD SIZE, COORD POSITION, int Longest) {
		for (std::vector<std::string>::iterator it = Options.begin(); it != Options.end(); ++it)
		{
			SetConsoleCursorPosition(options, POSITION);
			for (int i = 0; i < SIZE.X; i++) {
				std::cout << " ";
			}
			POSITION.Y++;
			SetConsoleCursorPosition(options, POSITION);
			POSITION.Y++;
			for (int i = 0; i < ((SIZE.X - Longest) + 1) / 2; i++) {
				std::cout << " ";
			}
			std::cout << *it;
			for (int i = 0; i < SIZE.X - (*it).length() - ((SIZE.X - Longest) + 1) / 2; i++) {
				std::cout << " ";
			}
			SetConsoleCursorPosition(options, POSITION);
			POSITION.Y++;

			for (int i = 0; i < SIZE.X; i++) {
				std::cout << " ";
			}

			POSITION.Y++;
			POSITION.Y++;
			SetConsoleCursorPosition(options, POSITION);

		}
		SetConsoleTextAttribute(options, 0b00001111);
		ManageOptions();
	}

	void Menu::showOptions()
	{
		background.showWindow();
		COORD SIZE = getSize();
		COORD POSITION = getPosition();
		short color = getColor();
		POSITION.X = POSITION.X + 5;
		POSITION.Y = POSITION.Y + 2;
		SetConsoleTextAttribute(options, getColor());
		std::vector<std::string> Options = getOptions();
		int Longest = Options[0].length();
		for (std::vector<std::string>::iterator it = Options.begin(); it != Options.end(); ++it) {
			if ((*it).length() > Longest) {
				Longest = (*it).length();
				}
		}
		drawMenu(SIZE, POSITION, Longest);
	}
}
