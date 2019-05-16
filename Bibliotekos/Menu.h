#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "WindowInterface.h"
#include <string>
#include <vector>
#include "Colors.h"
#include "Text.h"

namespace CI
{
	class Menu :public Window
	{
	private:
		short selectedOption;
		std::vector<std::string> Options;
		Color Color;
		Text text;
		void drawMenu(COORD,COORD, int);
		void ManageOptions();
		short getColor();
		void setTextColor(short);
		void setOptions(std::vector<std::string>);
	public:
		short getSelectedOption();
		void showOptions();
		void setMenuInterface(COORD, COORD, short,short, std::vector<std::string>, boolean, boolean);
		std::vector<std::string> getOptions();

	};
}

#endif // MENU_H_INCLUDED
