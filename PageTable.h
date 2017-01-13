/*
 * PageTable.h
 *
 *  Created on: 10 αιπε 2017
 *      Author: Eitan Levin
 */

#ifndef PAGETABLE_H_
#define PAGETABLE_H_

#include "PageDirectoryEntry.h"

//TODO support in log file should be added, as requested in pdf

class PageTable {
public:
	//Notice the default constructor is intentionally !allocating! entries.
	//This is done in order to mimic the behavior of a linux system.
	PageTable(VirtualMemory* virtMem) : _virtMem(virtMem) {
		//_outerPageTable = (PageDirectoryEntry*)malloc(sizeof(PageDirectoryEntry)*NUM_OF_ENTRIES);
		//FIXME the pdf says malloc. But malloc does not call constructors. is new okay?
		_outerPageTable = new PageDirectoryEntry[NUM_OF_ENTRIES];
		//After that action we have 1024 un-initialized Page Directory Entries
	}

	~PageTable() {
		if(_outerPageTable != NULL) {
			delete [] _outerPageTable;
		}
	}

	//Here we get a virtual address of a page and we are expected to return a
	//pointer to the frame where it is located.
	int* GetPage (unsigned int adr) {
		//Separating the virtual address into meaningful numbers.
		int pageDirectoryEntryNum = (createMask(22,31) & adr);
		int pageTableEntryNum = (createMask(12,21) & adr);
		int offset = (createMask(0,11) & adr);

		//Checking if the inner table is valid. If not- allocating it.
		if(!_outerPageTable[pageDirectoryEntryNum].is_valid()) {
			_outerPageTable[pageDirectoryEntryNum].create_inner_table();
			_outerPageTable[pageDirectoryEntryNum].set_valid(true);
		}

		//Checking if the inner table entry is valid. If not- linking it to a free address.
		if(!_outerPageTable[pageDirectoryEntryNum].is_inner_entry_valid(pageTableEntryNum)) {
			int* freeAdr = _virtMem->GetFreeFrame();
			_outerPageTable[pageDirectoryEntryNum].set_page_address(pageTableEntryNum, freeAdr);
		}

		//Returning the physical address
		return _outerPageTable[pageDirectoryEntryNum].get_page_address(pageTableEntryNum);
	}

private:
	VirtualMemory* _virtMem; //Necessary in order to use its methods
	PageDirectoryEntry* _outerPageTable;	//This is basically cr3

	/***
	 * createMask()
	 * Description: A method used to create a bit-mask.
	 * Parameters: start- the bit which we want to start extracting from.
	 * 			   finish- the bit we want to finish at (including!).
	 * The function operates by first creating a 32-bit variable with all zeros.
	 * It then assigns 1 into each bit we want to keep.
	 */
	unsigned int createMask(int start, int finish) {
	   unsigned int mask = 0;
	   for (unsigned int i = start; i<= finish; i++) {
		   mask |= 1 << i;
	   }
	   return mask;
	}

};



#endif /* PAGETABLE_H_ */
