/*
 * PageTableEntry.h
 *
 *  Created on: 11 áéðå× 2017
 *      Author: Amit
 */

#ifndef PAGETABLEENTRY_H_
#define PAGETABLEENTRY_H_

/*
 * TODO
 * I believe this code should represent an entry in the outer page table.
 * Meaning each "frame" it represents is actually a pointer to an inner page table,
 * whose name is PageDirectoryEntry.
 */

class PageTableEntry {
public:
	PageTableEntry(); //Your Constructor (and Destructor if you need one) should go here
	~PageTableEntry();
	int* get_page_address(); //Pointer to beginning of frame  
	void set_page_address(int* adr); //Set the pointer to a frame
	bool is_valid(); //Returns whether the entry is valid
	void set_valid(bool valid); //Allows to set whether the entry is valid
private:
	//Fill the class with the necessary member variables
	bool _valid;
	int* _framePointedBegining;
};








#endif /* PAGETABLEENTRY_H_ */
