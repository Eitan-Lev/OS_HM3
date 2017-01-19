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

int bugIndicator = 0;

#define STOP_POINT 1024*64

int main(){
    VirtualMemory vrtlMem;

    OurPointer ptr = vrtlMem.OurMalloc(1024*64); //That means we take everything possible in Physical memory + 1

    int* wtf;

    srand(1);
    for(int j = 0; j < 62 ; j++) {
        for (int i = 0; i < 1024 ; i++) {
        	 if(j == 61 && i != 1) { //TODO debug
        		 bugIndicator++;
                 wtf = vrtlMem.pageTable.GetPage(63328); // 63328 is the the number of the int which is in frame 61, int 864 that causes problems.
                 if(wtf == vrtlMem.physmemAdds[61])
                	 cout << "number " << i << " gives a correct result" << endl;
                 else
                  	 cout << "Fuck! number " << i << " gives a wrong result" << endl;
        	 }
        	 if(j == 61 && i == 862) { //TODO debug
				 bugIndicator++;
				 wtf = vrtlMem.pageTable.GetPage(63328);
        	}
            *ptr = rand() % 100;
            ptr++;
            //cout << "Finished with number " << i << endl; TODO debug
        }
        //cout << "Frame number " <<j <<" should be done allocating" << endl;
    }

/*
    //This one should cause swap out
    *ptr = 777;
    ptr++;*/

    return 0;
}

