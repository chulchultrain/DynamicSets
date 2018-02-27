#include <DynamicSet/RankedDynamicSetTester.h>
#include <SortedArray.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>




int main() {
	RankedDynamicSet<int> *set = new SortedArray<int>();
	RankedDynamicSetTester rdst;
    rdst.test(set);
	delete set;


	return 0;
}
