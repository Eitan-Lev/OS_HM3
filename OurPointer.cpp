/*
 * OurPointer.cpp
 *
 *  Created on: 14 áéðå× 2017
 *      Author: Amit
 */

#include "OurPointer.h"
#include "VirtualMemory.h"

//Operator that returns the int pointed by OurPointer
int& OurPointer::operator*() {
	return *(_vrtlMem->GetPage(_adr));
}

//Overload ++operator
OurPointer& OurPointer::operator++() {
	_adr += sizeof(_adr);
	//FIXME if a OurPointer p1 is connected to a Physical address no. 0 for example.. when we increment it
	//just lose its connection to it?
	return *this;
}

//Overload operator++ means we increment the virtual address.
OurPointer OurPointer::operator++(int) {
	OurPointer beforeAddition(_adr,_vrtlMem);
	this->operator++(); //Using the pre-fix operator we already overloaded
	return beforeAddition;
}

//Overload --operator TODO mistake in pdf??
OurPointer& OurPointer::operator--() {
	_adr -= sizeof(_adr);
	return *this;
}

//Overload operator--
OurPointer OurPointer::operator--(int) {
	OurPointer beforeDecrement(_adr,_vrtlMem);
	this->operator--(); //Using the pre-fix operator we already overloaded
	return beforeDecrement;
}


