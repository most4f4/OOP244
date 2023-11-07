// Final Project Milestone 1 
// File	Menu.h
// Version 1.0
// Date	2023-07-15
// Author	Mostafa Hasanalipourshahrabadi
// 
// Revision History
//---------------------------------------------------------------                              
//   Name:                 Date:                      Reason: 
//  
// 
/////////////////////////////////////////////////////////////////
/*
*****************************************************************
						  Final project milestone 1
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-07-15

Authenticity Declaration:
I declare this submission is the result of my own work and has
not been shared with any other student or 3rd party content
provider. This submitted piece of work is entirely of my own
creation.
*****************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"


using namespace std;
namespace sdds {

	MenuItem::MenuItem(const char* text) : content(nullptr) {
		if (text && text[0]) {
			content = new char[strlen(text) + 1];
			strcpy(content, text);
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] content;
	}

	MenuItem::operator bool() const
	{
		return content != nullptr and content[0] != '\0';
	}

	MenuItem::operator const char* () const
	{
		return content;
	}

	std::ostream& MenuItem::display(std::ostream& os) const
	{
		if (*this) {
			os << content;
		}
		return os;
	}

	Menu::Menu() : title(), itemCount(0) {
		// Set all elements of the items array to nullptr
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			items[i] = nullptr;
		}
	}

	Menu::Menu(const char* menuTitle) : title(menuTitle), itemCount(0) {
		// Set all elements of the items array to nullptr
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			items[i] = nullptr;
		}
	}

	Menu::~Menu()
	{
		for (unsigned int i = 0; i < itemCount; i++) {
			delete items[i];
		}
	}

	std::ostream& Menu::displayTitle(std::ostream& os)
	{
		if (title) {
			title.display();
		}
		return os;
	}

	std::ostream& Menu::displayMenu(std::ostream& os)
	{
		if (title) {
			title.display();
			os << ":" << endl;
		}
		for (unsigned int i = 0; i < itemCount; i++) {
				os.width(2);
				os.setf(ios::right);
				os.fill(' ');
				os << i + 1 << "- ";
				os.unsetf(ios::right);
				items[i]->display(os);
				os << endl;

		}
		os << " 0- Exit" << endl;
		os << "> ";

		return os;

	}

	unsigned int Menu::run()
	{

		displayMenu();
		unsigned int selection = getUserInt(0, itemCount);
		return selection;
	}

	unsigned int Menu::operator~()
	{
		return run();
	}

	Menu& Menu::operator<<(const char* menuItemContent)
	{
		if (itemCount < MAX_MENU_ITEMS) {
			items[itemCount] = new MenuItem(menuItemContent);
			itemCount++;
		}
		return *this;
	}

	Menu::operator int()
	{
		return itemCount;
	}

	Menu::operator unsigned int()
	{
		return itemCount;
	}

	Menu::operator bool()
	{
		return itemCount > 0;
	}

	const char* Menu::operator[](unsigned int index) const
	{
		if (index <= itemCount)
		{
			return items[index]->content;
			
		}
		else
		{
			return items[index %= itemCount]->content;
		}
	}

	std::ostream& operator<<(std::ostream& os, Menu& menu) {
		return (menu.displayTitle(os));
	}


}


	
