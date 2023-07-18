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



#ifndef SDDS_MENU_H_
#define SDDS_MENU_H_
#include <iostream>

namespace sdds {

	const unsigned int MAX_MENU_ITEMS = 20;

	class Menu; // Forward declaration of Menu class

	class MenuItem {

		// Dynamic C-string for the content of the menu item
		char* content{};

		// Constructor & Destructor
		MenuItem(const char* text = nullptr); 
		~MenuItem(); 

		// Deleted copy constructor and copy assignment operator to prevent copying
		MenuItem(const MenuItem&) = delete;
		void operator=(const MenuItem&) = delete;

		// Bool and const char* type conversion 
		operator bool() const;     
		operator const char* () const;     

		// Method to display the content of the MenuItem on ostream
		std::ostream& display(std::ostream& os = std::cout) const; 

		// Allow Menu class to access private members of MenuItem
		friend class Menu; 
	};

	class Menu {

		MenuItem title{}; // Title of the menu
		MenuItem* items[MAX_MENU_ITEMS]{}; // Array of MenuItem pointers
		unsigned int itemCount = 0; // Number of items in the menu
	public:
		// Constructor & Destructor
		Menu();
		Menu(const char* menuTitle);
		~Menu();

		// Deleted copy constructor and copy assignment operator to prevent copying
		Menu(const Menu&) = delete;
		void operator=(const Menu&) = delete;

		std::ostream& displayTitle(std::ostream& os = std::cout); // Display the title of the menu
		std::ostream& displayMenu(std::ostream& os = std::cout); // Display the full menu

		unsigned int run(); // Run the menu and get user input
		unsigned int operator~(); // Run the menu (alternative syntax)

		operator int(); // Conversion to int (number of items)
		operator unsigned int(); // Conversion to unsigned int (number of items)
		operator bool(); // Conversion to bool(menu is not empty)

		Menu& operator<<(const char* menuItemContent); // Add a menu item

		const char* operator[](const unsigned int index) const; // Access menu item by index


		friend std::ostream& operator<<(std::ostream& os, const Menu& menu); // Insertion operator

	};

	std::ostream& operator<<(std::ostream& os, Menu& menu);


}

#endif // !MENU_H_

