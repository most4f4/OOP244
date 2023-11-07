/*
*****************************************************************
						  Final project milestone 2
Full Name  : Mostafa Hasanalipourshahrabadi
Student ID#: 154581227
Email      : mhasanalipourshahrab@myseneca.ca
Section    : NAA
Date       : 2023-11-06

Authenticity Declaration:
I declare this submission is the result of my own work and has
not been shared with any other student or 3rd party content
provider. This submitted piece of work is entirely of my own
creation.
*****************************************************************
*/

#include <iostream>
#include "LibApp.h"

using namespace std;
namespace sdds {

	LibApp::LibApp() :
		m_changed(false),
		m_mainMenu("Seneca Libray Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?")
	{
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		load();
	}

	bool LibApp::confirm(const char* message) {
		Menu M(message);
		M << "Yes";
		return M.run() == 1;
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
	}

	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
		cout << endl;
	}
	
	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		int result = confirm("Add this publication to library?");
		if (result) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
		cout << endl;

	}

	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		int result = confirm("Remove this publication from the library?");
		if (result) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
		cout << endl;
	}

	void LibApp::checkOutPub() {
		search();
		int result = confirm("Check out publication?");
		if (result) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	}

	void LibApp::run()
	{
		bool stayFlag = true;

		do {
			int userSelection = m_mainMenu.run();
			switch (userSelection)
			{
			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			case 0:
				if (m_changed) {
					int exitSelection = m_exitMenu.run();
					switch (exitSelection)
					{
					case 1:
						save();
						stayFlag = false;
						break;
					case 2:
						cout << endl;
						break;
					case 0:
						if (confirm("This will discard all the changes are you sure ?")) {
							stayFlag = false;
						}
						break;
					}
				}
				else {
					stayFlag = false;
				}

			}

		} while (stayFlag);
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;

	}

}
