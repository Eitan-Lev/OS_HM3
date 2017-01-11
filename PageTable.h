/*
 * PageTable.h
 *
 *  Created on: 10 αιπε 2017
 *      Author: Eitan Levin
 */

#ifndef PAGETABLE_H_
#define PAGETABLE_H_

#include "PageDirectoryEntry.h"

class PageTable {
public:
	//Your Constructor (and Destructor if you need one) should go here
	int* GetPage (unsigned int adr);
private:
	//Fill the class with the necessary member variables
};



#endif /* PAGETABLE_H_ */
