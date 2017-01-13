/*
 * unitTests.cpp
 *
 *  Created on: 13 בינו׳ 2017
 *      Author: Amit
 */

#include "unitTests.h"
#include "PhysMem.h"
#include "PageTableEntry.h"
#include "PageDirectoryEntry.h"
#include "SwapDeviceTest.h"//FIXME for eitan tests

/**
 * Very basic tests, just to make sure everything is okay.
 */
bool pageTableEntryTest() {
	PageTableEntry ent1, ent2, ent3;

	if(ent1.is_valid() || ent2.is_valid() || ent3.is_valid()) {
		ERROR_AND_PRINT("valid status at creation is bad");
	}
	if(ent1.get_page_address() || ent2.get_page_address() || ent3.get_page_address()) {
		ERROR_AND_PRINT("frame pointed status at creation is bad");
	}

	ent1.set_valid(true);
	ent2.set_valid(true);
	ASSERT_TRUE(ent1.is_valid());
	ASSERT_TRUE(ent2.is_valid());
	ASSERT_FALSE(ent3.is_valid());

	int ptrA = 1, ptrB = 2, ptrC = 3;
	ent1.set_page_address(&ptrA);
	ent2.set_page_address(&ptrB);
	ent3.set_page_address(&ptrC);
	if( *(ent1.get_page_address()) != 1 || *(ent2.get_page_address()) != 2 || *(ent3.get_page_address()) != 3 ) {
		ERROR_AND_PRINT("set_page_address in bad");
	}
	ent1.set_page_address(&ptrB);
	if( *(ent1.get_page_address()) != 2) {
		ERROR_AND_PRINT("set_page_address in bad");
	}
	return true;
}

/**
 * Test meant to check the outter table entries.
 */
bool pageDirectoryEntryTest() {
	PageDirectoryEntry ent1, ent2;

	if(ent1.is_valid() || ent2.is_valid()) {
			ERROR_AND_PRINT("valid status at creation is bad");
	}

	ent1.create_inner_table();
	ent1.set_valid(true);
	for(int i = 0; i < NUM_OF_ENTRIES ; i++) {
		if(ent1.is_inner_entry_valid(i)) {
			ERROR_AND_PRINT("inner entries are created and they are not supposed to.");
		}
	}
	return true;
}



int main() {
	RUN_TEST("pageTableEntryTest",pageTableEntryTest());
	RUN_TEST("pageDirectoryEntryTest",pageDirectoryEntryTest());
	EitanTests();//Will run test and all in the other file
	return 0;
}

