/*
 * PageTableEntry.h
 *
 *  Created on: 11 áéðå× 2017
 *      Author: Amit
 */

#ifndef PAGETABLEENTRY_H_
#define PAGETABLEENTRY_H_

#include <cstdlib>

/*
 * This file will represent each entry in the inner page table. That means that
 * each PageTableEntry has a pointer to a specific frame representing where the
 * page is kept- either in memory or in swap area.
 */

class PageTableEntry {
public:
	PageTableEntry() : _valid(false),_framePointedBegining(NULL) {}
		//When invoking this constructor that means we are creating an entry
		//inside the inner page table
	~PageTableEntry() {}
	int* get_page_address() {
		//Pointer to beginning of frame  
		return _framePointedBegining;
	}
	void set_page_address(int* adr) {
		//Set the pointer to a frame
		_framePointedBegining = adr;
	}
	bool is_valid() {
		//Returns whether the entry is valid
		return _valid;
	}
	void set_valid(bool valid) {
		//Allows to set whether the entry is valid
		_valid = valid;
	}
private:
	bool _valid;
	int* _framePointedBegining;
};








#endif /* PAGETABLEENTRY_H_ */
