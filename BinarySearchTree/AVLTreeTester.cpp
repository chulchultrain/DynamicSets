#include <BinarySearchTree/AVLTree.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


void PrintStates(AVLTree<int> *set) {
    printf("START PRINT STATES\n\n");
    printf("pre order traversal:\n");
    set->PreOrderTraversal();
    printf("in order traversal:\n");
    set->InOrderTraversal();
    printf("post order traversal:\n");
    set->PostOrderTraversal();
    printf("\n\n");
}

int main() {
    AVLTree<int> *set = new AVLTree<int>();
    PrintStates(set);
    set->insert(1);
    PrintStates(set);
    set->insert(2);
    PrintStates(set);
    set->insert(0);
    PrintStates(set);
    delete set;
	return 0;
}
