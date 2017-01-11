/*
 * PageDirectoryEntry.h
 *
 *  Created on: 11 áéðå 2017
 *      Author: ilanmisa
 */

#ifndef OS_HW3_PAGEDIRECTORYENTRY_H_
#define OS_HW3_PAGEDIRECTORYENTRY_H_

class PageTableEntry {
public:
	//Your Constructor (and Destructor if you need one) should go here
	int* get_page_address(); //Pointer to beginning of frame  
	void set_page_address(int* adr); //Set the pointer to a frame
	bool is_valid(); //Returns whether the entry is valid
	void set_valid(bool valid); //Allows to set whether the entry is valid
private:
	//Fill the class with the necessary member variables
};



#endif /* OS_HW3_PAGEDIRECTORYENTRY_H_ */
