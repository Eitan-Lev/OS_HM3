/*
 * PageTable.cpp
 *
 *  Created on: 13 ����� 2017
 *      Author: Amit
 */

#include "PageTable.h"
#include "VirtualMemory.h"

//TODO support in log file should be added, as requested in pdf

int* PageTable::GetPage (unsigned int adr) {
	//Separating the virtual address into meaningful numbers.
	int pageDirectoryEntryNum = (createMask(22,31) & adr);
	int pageTableEntryNum = (createMask(12,21) & adr);
	//TODO int offset = (createMask(0,11) & adr);

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

/***
 * createMask()
 * Description: A method used to create a bit-mask.
 * Parameters: start- the bit which we want to start extracting from.
 * 			   finish- the bit we want to finish at (including!).
 * The function operates by first creating a 32-bit variable with all zeros.
 * It then assigns 1 into each bit we want to keep.
 */
unsigned int PageTable::createMask(unsigned int start, unsigned int finish) {
   unsigned int mask = 0;
   for (unsigned int i = start; i<= finish; i++) {
	   mask |= 1 << i;
   }
   return mask;
}


