#include <BinarySearchTree/BinarySearchTree.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;


int main() {
	DynamicSet<int> *set = new BinarySearchTree<int>();

	set->insert(5);
	set->insert(3);
	set->insert(7);
	set->insert(1);
	set->insert(4);
	set->insert(6);
	set->insert(8);
	set->insert(5);
	set->insert(6);
	set->insert(7);

	set->objType();	
	set->remove(7);
	set->objType();
	set->remove(7);
	set->objType();
/*
	for(int i = 0; i < 10; i++) {
		set->remove(i);
		//set->objType();
		//cout << set->getMax() << ' ' << set->getMin() << '\n';
		set->objType();
	}
*/
	delete set;
	return 0;
}



