/*
 * OurPointer.cpp
 *
 *  Created on: 14 ����� 2017
 *      Author: Amit
 */

#include "OurPointer.h"
#include "VirtualMemory.h"
#include "MacroDefine.h"

//Operator that returns the int pointed by OurPointer
int& OurPointer::operator*() {
	unsigned int virtualAddress = _adr;
	int offset;
	CHANGE_ADR_INT_TO_ADR(virtualAddress);
	GET_OFFSET_BITS(virtualAddress, offset);
	return *(_vrtlMem->GetPage(_adr) + offset);
	//FIXME!! This will be an error when there is more than one page/frame saved in physical memory
}

//Overload ++operator
OurPointer& OurPointer::operator++() {
	//_adr += sizeof(_adr); TODO this is how we thought it should be. but maybe address should only store up to 1024?
	_adr++;
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
	//_adr -= sizeof(_adr);
	_adr--;
	return *this;
}

//Overload�operator--
OurPointer OurPointer::operator--(int) {
	OurPointer beforeDecrement(_adr,_vrtlMem);
	this->operator--(); //Using the pre-fix operator we already overloaded
	return beforeDecrement;
}
