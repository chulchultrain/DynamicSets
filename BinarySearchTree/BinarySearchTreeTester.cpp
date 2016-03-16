#include <BinarySearchTree/BinarySearchTree.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;


int main() {
	DynamicSet<int> *set = new BinarySearchTree<int>();

	for(int i = 0; i < 10; i++) {
		set->insert(i);
		//cout << set->search(i) << '\n';
	}
	set->objType();



	for(int i = 0; i < 10; i++) {
		set->remove(i);
		//set->objType();
		cout << set->getMax() << ' ' << set->getMin() << '\n';
	}

	delete set;
	return 0;
}




