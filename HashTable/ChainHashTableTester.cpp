#include <HashTable/ChainHashTable.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


void PrintSearch(DynamicSet<int> *set, int i) {
	std::cout << i << " is in here ";
	if( set->search(i))
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

}
 

int main() {
	DynamicSet<int> *set = new ChainHashTable<int>;
	int i = 0;
	for(i = 0; i < 10; i++)
		set->insert(i);

	for(i = 5; i < 15; i++)
		PrintSearch(set,i);

	for(i = 20; i >= 0; i--)
		set->remove(i);

	for(i = 5; i < 15; i++)
		PrintSearch(set,i);
	
	std::cout << set->objType() << '\n';

	delete set;

	return 0;
}
