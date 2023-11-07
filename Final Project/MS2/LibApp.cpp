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
		M << "yes";
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
	}
	
	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		int result = confirm("Add this publication to library?");
		if (result) {
			m_changed = true;
			cout << "Publication added";
		}

	}


}
