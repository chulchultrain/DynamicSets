#include <SimpleArray.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

 
bool TestInsert(DynamicSet<int> *set) {
	

}


int main() {
	DynamicSet<int> *set = new SimpleArray<int>();
	int i = 0;
	for(i = 0; i < 20; i++)
		set->insert(i);
	for(i = 0; i < 30; i++)
		set->insert(i);
		//TESTER METHODS. TestInsert. TestDelete. TestMax. TestMin. 
	printf("HERE I AM\n");
	if( set->search(21) )
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

	if( set->search(19) )
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";
	
	for(i = 0; i < 30; i++)
		set->remove(i);

	if( set->search(21) )
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";

	if( set->search(19) )
		std::cout << "TRUE\n";
	else
		std::cout << "FALSE\n";
	std::cout << set->objType() << '\n';

	delete set;


	return 0;
}






