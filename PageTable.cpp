/*
 * PageTable.cpp
 *
 *  Created on: 13 ����� 2017
 *      Author: Amit
 */

#include "PageTable.h"
#include "VirtualMemory.h"
#include "MacroDefine.h"

//TODO support in log file should be added, as requested in pdf

int* PageTable::GetPage (unsigned int adr) {
	//Separating the virtual address into meaningful numbers.
	unsigned int virtualAddress = adr;
	CHANGE_ADR_INT_TO_ADR(virtualAddress);
	int pageDirectoryEntryNum;
	int pageTableEntryNum;
	GET_MSB_BITS(virtualAddress, pageDirectoryEntryNum);
	GET_MIDDLE_BITS(virtualAddress, pageTableEntryNum);

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

