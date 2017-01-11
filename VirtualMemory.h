/*
 * VirtualMemory.h
 *
 *  Created on: 10 αιπε 2017
 *      Author: Eitan Levin
 */

#ifndef OS_HM3_VIRTUALMEMORY_H_
#define OS_HM3_VIRTUALMEMORY_H_

#include <queue>
#include "ourpointer.h"
#include "PhysMem.h"
#include <unordered_set>
#include "PageTable.h"

#define PAGESIZE 4096
#define VIRTMEMSIZE 4294967296
#define NUMOFFRAMES 64
using namespace std;

class VirtualMemory {
	friend class PageTable;
public:
	/*
	 * VirtualMemory: Initialize freeFramesList to contain all 64 frame	pointers as given by PhysMem Class,
	 * initialize the PageTable, give the pageTable a pointer to this object so it can
	 * utilize GetFreeFrame and	ReleaseFrame
	 */
	VirtualMemory() {
		PhysMem currPhysMem;
		currPhysMem.Access(); //I think now we have created the physical memory. Not entirely sure TODO
		for(int i = 0; i < NUMOFFRAMES ; i++) {
			this->freeFramesList.push(currPhysMem.GetFrame(i));	//Now our list will contain pointers to all frames
		}
		this->allocated = 0;
		//TODO page-table init
		//TODO giving page-table a pointer to virtual memory

	}

	~VirtualMemory();

	/*
	 * GetFreeFrame:
	 * Remove one item from the freeFrameList and return it – suggestion,
	 * use memset(framePtr, 0, PAGESIZE) before return, might help debugging!
	 */
	int* GetFreeFrame() {
		int* freeFramePtr = this->freeFramesList.pop();
		memset(freeFramePtr, 0 ,PAGESIZE); //Now the entire page would be 0s
		return freeFramePtr;
	}

	/*
	 * ReleaseFrame:
	 * Releases the frame pointed by the framePointer, make sure you only
	 * use this function with a pointer to the beginning of the Frame!
	 * it should be the same pointer as held in the PTE.
	 */
	void ReleaseFrame(int* framePointer) {
		free(framePointer);
		//TODO maybe we should test the ptr given to us to make sure no mistakes are made.
	}

	/*
	 * OurPointer:
	 * Allocates a pointer, we added the code for your convenience
	 */
	OurPointer OurMalloc(size_t size) {
		if (allocated + size >= (VIRTMEMSIZE >> 2)) {
			throw "We are limited to 4294967296 bytes with our 32 bit address size";
		}
		OurPointer ptr(allocated, this);
		allocated += size;
		return ptr;
	}

	int* GetPage(unsigned int adr) {
		return pageTable.GetPage(adr);
	}

private:
	/*
	 * allocated:
	 * The number of ints already allocated, ((allocated * 4) = (number of bytes already allocated)),
	 * this can also be used as the next address to be allocated.
	 */
	size_t allocated;
	queue<int*> freeFramesList;
	PageTable pageTable;
};



#endif /* OS_HM3_VIRTUALMEMORY_H_ */
