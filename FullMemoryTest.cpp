/*
 * MySwapTest.cpp
 *
 *  Created on: 19 בינו׳ 2017
 *      Author: Amit
 */

#include<iostream>
#include<fstream>
#include "OurPointer.h"
#include "VirtualMemory.h"

using namespace std;

int breakPoint = 0;

int main(){
    VirtualMemory vrtlMem;

    OurPointer ptr = vrtlMem.OurMalloc(1024*64); //That means we take everything possible in Physical memory

    srand(1);
    for (int i = 0; i < 63; i++) {
    	for(int j = 0; j < 1024 ; j++) {
        	*ptr = (rand() % 100);
        	ptr++;
        	if(i == 61 && j == 863) {  //TODO debug
        		breakPoint++;
        	}
    	}
    	cout << "Done with frame " << i << endl;  //TODO debug
    }

  /*
    //This one should cause swap out
    *ptr = 777;
    ptr++;*/

    return 0;
}

