/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author	Mostafa Hasanalipourshahrabadi
Revision History
-----------------------------------------------------------
Date      Reason
2023/11/10  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include "LibApp.h"
#include "PublicationSelector.h"
#include "Publication.h"
#include "Utils.h"

using namespace std;
namespace sdds {

	LibApp::LibApp(const char* fileName) :
		m_changed(false),
		m_mainMenu("Seneca Libray Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_pubType("Choose the type of publication:")
	{
		ut.strncpy(m_fileName, fileName, 256);

		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		m_pubType << "Book";
		m_pubType << "Publication";

		load();
	}

	bool LibApp::confirm(const char* message) {
		Menu M(message);
		M << "Yes";
		return M.run() == 1;
	}

	/*
	First print "Loading Data" and then open the data file for reading and read 
	all the publications in dynamic instances pointed by the PPA Array. 
	
	Do this by first reading a single character for the type of publication and 
	then dynamically instantiating the corresponding object into the next available PPA element. 
	Then extract the object from the file stream and add one to the NOLP. Since the extraction 
	operator calls the proper read function virtually, the object will be properly read from the file. 
	
	Continue this until the ifstream reading fails.
	
	At the end set the LLRN to the reference number of the last publication read.
	*/
	void LibApp::load() {

		cout << "Loading Data" << endl;

		ifstream infile(m_fileName);

		char type{};

		for (int i = 0; infile && i < SDDS_LIBRARY_CAPACITY; i++) {

			infile >> type;

			infile.ignore();

			if (infile) {

				if (type == 'P') {

					m_ppa[i] = new Publication;

				}else if (type == 'B') {

					m_ppa[i] = new Book;

				}

				if (m_ppa[i]) {

					infile >> *m_ppa[i];

					m_nolp++;

					m_llrn = m_ppa[i]->getRef();

				}

			}

		}

	}

	//First print "Saving Data" and then open the data file stream for overwriting.  (ofstream)
	//Go through the elements of PPA up to the N0LP.
	//Insert all elements into the ofstream object except those with 0 (zero) as Library Reference Number.
	//(return value of getRef() method)

	//	> Publications that have the reference number of 0 (zero) are deleted by the user (removed from the library)
	//and therefore should not be saved back into the data file.We refer to these publications as deleted ones.

	void LibApp::save() {

		cout << "Saving Data" << endl;

		ofstream outfile(m_fileName);

		for (int i = 0; i < m_nolp; i++) {

			if (m_ppa[i]->getRef() != 0) {

				outfile << *m_ppa[i] << endl;

			}

		}

	}

	int LibApp::search(int searchType) {

		char tempTitle[257]{};
		char tempType{};
		int userSelection = 0;
		PublicationSelector ps("Select one of the following found matches:", 15);

		int selectedType = m_pubType.run();


		if (selectedType == 0) {
			cout << "Aborted!" << endl;
		}
		else {

			if (selectedType == 1) {
				tempType = 'B';
			}
			else if (selectedType == 2) {
				tempType = 'P';
			}

			cin.ignore();
			cout << "Publication Title: ";
			cin.getline(tempTitle, 257);

			switch (searchType)
			{
			case 1: // search All

				for (int i = 0; i < m_nolp; i++) {

					if (m_ppa[i]->type() == tempType && m_ppa[i]->operator==(tempTitle) && m_ppa[i]->getRef() != 0) {
						ps << m_ppa[i];
					}
				}

				break;

			case 2: //Search Checkout Items

				for (int i = 0; i < m_nolp; i++) {

					if (m_ppa[i]->type() == tempType && m_ppa[i]->operator==(tempTitle) && m_ppa[i]->getRef() != 0
						&& m_ppa[i]->onLoan()) {
						ps << m_ppa[i];
					}
				}

				break;

			case 3: //Search Available Items

				for (int i = 0; i < m_nolp; i++) {

					if (m_ppa[i]->type() == tempType && m_ppa[i]->operator==(tempTitle) && m_ppa[i]->getRef() != 0
						&& !m_ppa[i]->onLoan()) {
						ps << m_ppa[i];
					}
				}

				break;
			}

			if (ps) {

				ps.sort();

				userSelection = ps.run();

				if (userSelection > 0) {

					cout << *getPub(userSelection) << endl;

				}
				else {

					cout << "Aborted!" << endl;

				}

			}
			else {

				cout << "No matches found!" << endl;

			}


		}

		return userSelection;

	}

	//	- Print: `"Return publication to the library"`
	//	- Search for "on loan" publications only
	//	- If the user selects a publication and confirms the return using the prompt : `"Return Publication ? "`
	//	- If the publication is more than 15 days on loan, a 50 cents per day penalty will be calculated for the number of days exceeding the 15 days.
	//	- Following message is printed : `Please pay $9.99 penalty for being X days late!`, 9.99 is replaced with the penalty value and X is replaced with the number of late days.
	//	- set the membership number of the publication to 0 (zero)
	//	-set the "changed" flag to true
	//	- print: `"Publication returned"

	void LibApp::returnPub() {

		cout << "Returning publication" << endl;
		int userSelection = search(2);

		if (userSelection && confirm("Return Publication ? ")) {

			Date today;
			int loanDays = today - getPub(userSelection)->checkoutDate();

			if (loanDays > 15) {

				double penalty = 0.50 * (loanDays - 15);
				cout << "Please pay $";
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << penalty;
				cout.unsetf(ios::fixed);
				cout<< " penalty for being " << (loanDays - 15) << " days late!";

				getPub(userSelection)->set(0);
				m_changed = true;
				cout << "Publication returned" << endl;
			}

		}

		cout << endl;
	}
	
	void LibApp::newPublication() {

		if (m_nolp == SDDS_LIBRARY_CAPACITY) {

			cout << "Library is at its maximum capacity!";

		} else {

			cout << "Adding new publication to library" << endl;

			int tempType = m_pubType.run();

			if (tempType == 0) {

				cout << "Aborted!" << endl;

			}
			else {

				Publication* p;

				tempType == 1 ? p = new Book : p = new Publication;

				//  clear any existing characters in the input buffer
				//  ensuring that read starts with an empty buffer and waits for user input.
				cin.ignore();

				p->read(cin);

				if (cin.fail()) {

					cin.ignore(1000, '\n');
					cin.clear();
					cout << "Aborted!" << endl;
				}
				else {

					int userConfirm = confirm("Add this publication to the library?");

					if (userConfirm == 1) {

						if (p) {

							m_llrn++;
							p->setRef(m_llrn);
							m_ppa[m_nolp] = p;
							m_nolp++;
							m_changed = true;
							cout << "Publication added" << endl;

						} else {

							cout << "Failed to add publication!" << endl;
							delete p;

						}
					} else {

						cout << "Aborted!" << endl;
						delete p;

					}

				}

			}

		}

		cout << endl;

	}

	/* 
	    - print: `"Removing publication from the library"`
		- Search all the publications
		- If the user selects a publication and confirms to remove the publication using the prompt :
		  "Remove this publication from the library ? "
		- Set the library reference of the selected publication to 0 (zero)
		- set the "changed" flag to true
		- print : `"Publication removed"`
	*/

	void LibApp::removePublication() {

		cout << "Removing publication from library" << endl;

		int userSelection = search(1);

		if (userSelection > 0 && confirm("Remove this publication from the library?")) {


			getPub(userSelection)->setRef(0);
			m_changed = true;
			cout << "Publication removed" << endl;

		}

		cout << endl;
	}


	//	- print: `"Checkout publication from the library"`
	//	- Search in available publications only
	//	- If the user selects a publication and confirms to checkout using the prompt : `"Check out publication ? "`
	//	- read a 5 digit number from the console, if invalid print : `"Invalid membership number, try again: "` and read again
	//	- set the membership number of the selected publication the integer value.
	//	- set the changed flag to true
	//	- print : `"Publication checked out"`

	void LibApp::checkOutPub() {

		cout << "Checkout publication from the library" << endl;

		int selectedPub = search(3);

		if (selectedPub && confirm("Check out publication?")) {
			int membershipNo = ut.getUserInt(10000, 99999, "Invalid membership number, try again: ");
			getPub(selectedPub)->set(membershipNo);
			m_changed = true;
			cout << "Publication checked out" << endl;
		}
		cout << endl;
	}


	Publication* LibApp::getPub(int libRef)
	{
		for (int i = 0; i < m_nolp; i++) {

			if (m_ppa[i]->getRef() == libRef) {

				return m_ppa[i];

			}

		}

		return nullptr;

	}

	void LibApp::run()
	{
		bool exitFlag = false;

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
						exitFlag = true;
						break;
					case 2:
						cout << endl;
						break;
					case 0:
						if (confirm("This will discard all the changes are you sure ?")) {
							exitFlag = true;
						}
						break;
					}
				}
				else {
					exitFlag = true;
				}

			}

		} while (!exitFlag);
		cout << endl;
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;

	}

}
