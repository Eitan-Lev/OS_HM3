/*
 * PageDirectoryEntry.h
 *
 *  Created on: 11 áéðå 2017
 *      Author: ilanmisa
 */

#ifndef OS_HW3_PAGEDIRECTORYENTRY_H_
#define OS_HW3_PAGEDIRECTORYENTRY_H_

/*
 * TODO I Believe this one is basically a duplication of code from PageTableEntry.
 * The only real difference will be the fact that the entries here will actually point
 * to a physical memory entry and not another page table;
 * Actually, it is better if this class will just inherit pageTableEntry
 */

class PageDirectoryEntry { //FIXME ALL the code here is actually pageTableEntry code from the pdf, not directory
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
