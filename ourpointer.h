/*
 * ourpointer.h
 *
 *  Created on: 10 áéðå 2017
 *      Author: Eitan Levin
 */

#ifndef OS_HM3_OURPOINTER_H_
#define OS_HM3_OURPOINTER_H_

#include "PageTable.h"

class OurPointer {
public:
	OurPointer(int adr, VirtualMemory* vrtlMem); //Constructor
	~OurPointer(); //Destructor
	int& operator*(); //Overload operator*
	OurPointer& operator++(); //Overload ++operator
	OurPointer operator++(int); //Overload operator++
	OurPointer& operator--(); //Overload operator--
	OurPointer operator--(int); //Overload --operator
private:
	unsigned int _adr; //the virtual address
	VirtualMemory* _vrtlMem; //for requesting translations
};



#endif /* OS_HM3_OURPOINTER_H_ */
