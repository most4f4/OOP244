/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/06  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
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
		MenuItem& operator=(const MenuItem&) = delete;

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
		unsigned int itemCount{}; // Number of items in the menu
	public:
		// Constructor & Destructor
		Menu();
		Menu(const char* menuTitle);
		~Menu();

		// Deleted copy constructor and copy assignment operator to prevent copying
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;

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

