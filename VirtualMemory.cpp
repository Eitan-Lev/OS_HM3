/*
 * VirtualMemory.cpp
 *
 *  Created on: 13 בינו׳ 2017
 *      Author: Amit
 */

#include "VirtualMemory.h"

/*
 * GetFreeFrame:
 * Remove one item from the freeFrameList and return it – suggestion,
 * use memset(framePtr, 0, PAGESIZE) before return, might help debugging!
 */
int* VirtualMemory::GetFreeFrame() {
	int* freeFramePtr = this->freeFramesList.front();
	this->freeFramesList.pop();
	memset(freeFramePtr, 0 ,PAGESIZE); //Now the entire page would be 0s
	return freeFramePtr;
}

/*
 * ReleaseFrame:
 * Releases the frame pointed by the framePointer, make sure you only
 * use this function with a pointer to the beginning of the Frame!
 * it should be the same pointer as held in the PTE.
 */
void VirtualMemory::ReleaseFrame(int* framePointer) {
	free(framePointer);
	//TODO maybe we should test the ptr given to us to make sure no mistakes are made.
}


