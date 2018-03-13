#include <DynamicSet/RankedDynamicSetTester.h>
#include <SortedArray.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>




int main() {


    RankedDynamicSet<int> *sets[10];
    for(int i = 0; i < 10; i++) {
        sets[i] = new SortedArray<int>();
    }
    RankedDynamicSetTester rdst;
    rdst.test_insert(sets[0]);
    rdst.test_clear(sets[1]);
    rdst.test_remove(sets[2]);
    for(int i = 0; i < 10; i++) {
        delete sets[i];
    }

	return 0;
}
