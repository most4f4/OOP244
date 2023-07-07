#ifndef NAMESPACE_SHOPPINGLIST_H 
#define NAMESPACE_SHOPPINGLIST_H

namespace sdds {

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();

}



#endif