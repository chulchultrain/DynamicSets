#include <DynamicSet/DynamicSetTester.h>
#include <SimpleArray.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>



int main() {
    DynamicSet<int> *sets[10];
    for(int i = 0; i < 10; i++) {
        sets[i] = new SimpleArray<int>();
    }
    DynamicSetTester dst;
    dst.test_insert(sets[0]);
    dst.test_clear(sets[1]);
    dst.test_remove(sets[2]);
    for(int i = 0; i < 10; i++) {
        delete sets[i];
    }


	return 0;
}
