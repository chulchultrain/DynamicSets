#include <DynamicSet/DynamicSetTester.h>
#include <SimpleArray.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>



int main() {
	DynamicSet<int> *set = new SimpleArray<int>();
	DynamicSetTester dst;
    dst.test(set);
	delete set;


	return 0;
}
