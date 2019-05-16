#include "stdafx.h"
#include "Text.h"
#include "Indicator.h"

namespace CI
{
	void Indicator::showIndicator(std::string words) {
		unsigned int index = 0;
		SetConsoleTextAttribute(getAccessToConsole(), getColor());
		SetConsoleCursorPosition(getAccessToConsole(), getPosition());
		for (short i = 0; i < getLength(); i++) {
			if ((index + 1) <= words.length()) {
				std::cout << words[index];
				index++;
			}
			else {
				std::cout << " ";
			}
		}
		if (getLength() < words.length()) {
			std::cout << "...";
		}
	}

	HANDLE Indicator::getAccessToConsole() {
		return console;
	}

	void Indicator::setColor(short color) {
		Color = color;
	}

	void Indicator::setLength(short l) {
		Length = l;
	}

	short Indicator::getLength() {
		return Length;
	}

	short Indicator::getColor() {
		return Color;
	}

	void Indicator::setPosition(COORD pos) {
		Position = pos;
	}

	COORD Indicator::getPosition() {
		return Position;
	}
	void Indicator::setIndicatorInterface(short length, COORD position, short color) {
		setPosition(position);
		setColor(color);
		setLength(length);

	}

}