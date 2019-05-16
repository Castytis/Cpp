#include "stdafx.h"
#include "Text.h"

namespace CI
{
	void Text::printText(std::string words) {
		unsigned int index = 0;
		showWindow();
		SetConsoleTextAttribute(getAccessToConsole(), getFillColor());
		SetConsoleCursorPosition(getAccessToConsole(), { getPosition().X+1, getPosition().Y+1 });
		for (short i = 0; i < getSize().Y-2; i++) {
			for (int j = 0; j < getSize().X-2; j++) {

				if ((index + 1) < words.length()) {
					std::cout << words[index];
					index++;
				}
				else {
					std::cout << " ";
				}
			}
			SetConsoleCursorPosition(getAccessToConsole(), { getPosition().X+1 ,getPosition().Y+i+2 });
		}
	}
	void Text::setTextInterface(COORD Size, COORD Position, short Color, boolean SingleBorder, boolean DoubleBorder) {
		setWindowInterface(Size, Position, Color, SingleBorder, DoubleBorder);
	}
}