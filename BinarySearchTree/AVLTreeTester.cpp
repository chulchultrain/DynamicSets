#include <BinarySearchTree/AVLTree.h>
#include <DynamicSet/RankedDynamicSetTester.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void PrintStates(AVLTree<int> *set) {
    printf("START PRINT STATES\n\n");
    printf("pre order traversal:\n");
    set->PreOrderTraversal();
    printf("in order traversal:\n");
    set->InOrderTraversal();
    printf("post order traversal:\n");
    set->PostOrderTraversal();
    printf("\n\n\n");
}

void Test_Multi_Insert(AVLTree<int> *set) {
    set->clear();
    set->insert(1);
    PrintStates(set);
    set->insert(2);
    PrintStates(set);
    set->insert(2);
    PrintStates(set);
    set->insert(1);
    PrintStates(set);
    set->insert(3);
    PrintStates(set);
    set->remove(2);
    PrintStates(set);
    set->remove(2);
    PrintStates(set);
    set->clear();
}

void First_Part(AVLTree<int> *set) {
    set->clear();
    set->insert(1);
    PrintStates(set);
    set->insert(0);
    PrintStates(set);
    set->insert(5);
    PrintStates(set);
    set->insert(4);
    PrintStates(set);
    set->insert(7);
    PrintStates(set);
    set->insert(9);
    PrintStates(set);
    set->insert(6);
    PrintStates(set);
    set->insert(8);
    PrintStates(set);
    //PrintStates(set);
    //set->LRRTest();
    cout << set->getRank(9) << endl;
    cout << set->getRank(0) << endl;
    cout << set->getRank(1) << endl;
    set->remove(5);
    PrintStates(set);
    //set->remove(7);
    //PrintStates(set);
    set->clear();

}

int main() {
    AVLTree<int> *set = new AVLTree<int>();
    //Test_Multi_Insert(set);
    First_Part(set);
/*
    PrintStates(set);
    set->insert(1);
    PrintStates(set);
    set->insert(2);
    PrintStates(set);
    set->insert(0);
    PrintStates(set);


    cout << set->getPredecessor(2) << endl;
    cout << set->getPredecessor(1) << endl;
    cout << set->getSuccessor(0) << endl;
    cout << set->getSuccessor(1) << endl;

    set->remove(0);
    PrintStates(set);
    set->remove(1);
    PrintStates(set);
    set->remove(2);
    PrintStates(set);
    */

    RankedDynamicSet<int> *sets[10];
    for(int i = 0; i < 10; i++) {
        sets[i] = new AVLTree<int>();
    }
    RankedDynamicSetTester rdst;
    rdst.test_insert(sets[0]);
    rdst.test_clear(sets[1]);
    rdst.test_remove(sets[2]);
    for(int i = 0; i < 10; i++) {
        delete sets[i];
    }
    delete set;
	return 0;
}
