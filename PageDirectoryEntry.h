/*
 * PageDirectoryEntry.h
 *
 *  Created on: 11 αιπε 2017
 *      Author: ilanmisa
 */

#ifndef OS_HW3_PAGEDIRECTORYENTRY_H_
#define OS_HW3_PAGEDIRECTORYENTRY_H_

#include "PageTableEntry.h"

#define NUM_OF_ENTRIES 1024

/*
 * This file will be representing an entry in the outer page table. That means
 * each entry here is actually an inner page table containing 1024 PageTableEntry.
 * Note: This is an entry of the outer page table, but it is kind of an inner page
 * table itself. This why we'll inherit the inner entries and add functionality.
 */

class PageDirectoryEntry : public PageTableEntry{
public:
	//Notice the default constructor intentionally does !not allocate! entries.
	//This is done in order to mimic the behavior of a linux system.
	PageDirectoryEntry() : _valid(false),_innerTable(NULL) {}

	~PageDirectoryEntry() {
		free(_innerTable);
	}

	int* get_page_address(int innerTableEntry, VirtualMemory* virtmem) override {

	}

	void set_page_address(int innerTableEntry, int* adr) override {
	}

	//set_valid and is_valid functions are also here. They are inherited as-is.


private:
	PageTableEntry* _innerTable;
};



#endif /* OS_HW3_PAGEDIRECTORYENTRY_H_ */
