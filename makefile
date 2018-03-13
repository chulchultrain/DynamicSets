HOME_DIR = $(shell pwd)
DS_DIR=$(HOME_DIR)/DynamicSet
HT_DIR = $(HOME_DIR)/HashTable
BST_DIR = $(HOME_DIR)/BinarySearchTree

CC = g++
FLAGS = -I$(HOME_DIR) -c -Wall
CCMD = $(CC) $(FLAGS)

SoATester: $(HOME_DIR)/SortedArrayTester.o $(HOME_DIR)/DynamicSet/RankedDynamicSetTester.o
	$(CC) -o $(HOME_DIR)/SoATester $(HOME_DIR)/SortedArrayTester.o $(HOME_DIR)/DynamicSet/RankedDynamicSetTester.o

SATester: $(HOME_DIR)/SimpleArrayTester.o $(HOME_DIR)/DynamicSet/DynamicSetTester.o
	$(CC) -o $(HOME_DIR)/SATester $(HOME_DIR)/SimpleArrayTester.o $(HOME_DIR)/DynamicSet/DynamicSetTester.o

CHTTester: $(HT_DIR)/ChainHashTableTester.o
	$(CC) -o $(HOME_DIR)/CHTTester $(HT_DIR)/ChainHashTableTester.o



$(HOME_DIR)/DynamicSet/DynamicSetTester.o: $(DS_DIR)/DynamicSetTester.h $(DS_DIR)/DynamicSetTester.cpp $(DS_DIR)/DynamicSet.h
	$(CCMD)  $(DS_DIR)/DynamicSetTester.cpp -o $(DS_DIR)/DynamicSetTester.o

$(HOME_DIR)/DynamicSet/RankedDynamicSetTester.o: $(DS_DIR)/RankedDynamicSetTester.h $(DS_DIR)/RankedDynamicSetTester.cpp $(DS_DIR)/RankedDynamicSet.h $(DS_DIR)/DynamicSetTester.h
	$(CCMD)  $(DS_DIR)/RankedDynamicSetTester.cpp -o $(DS_DIR)/RankedDynamicSetTester.o

$(HOME_DIR)/SimpleArrayTester.o: $(HOME_DIR)/SimpleArray.h $(HOME_DIR)/SimpleArrayTester.cpp $(HOME_DIR)/SimpleArray.tpp $(DS_DIR)/DynamicSetTester.h
	$(CCMD)  $(HOME_DIR)/SimpleArrayTester.cpp -o $(HOME_DIR)/SimpleArrayTester.o

$(HOME_DIR)/SortedArrayTester.o: $(HOME_DIR)/SortedArray.h $(HOME_DIR)/SortedArrayTester.cpp $(HOME_DIR)/SortedArray.tpp $(DS_DIR)/RankedDynamicSetTester.h
	$(CCMD)  $(HOME_DIR)/SortedArrayTester.cpp -o $(HOME_DIR)/SortedArrayTester.o


$(HT_DIR)/ChainHashTableTester.o: $(HT_DIR)/HashTable.h $(HT_DIR)/ChainHashTableTester.cpp $(HT_DIR)/ChainHashTable.tpp
	$(CCMD)  $(HT_DIR)/ChainHashTableTester.cpp -o $(HT_DIR)/ChainHashTableTester.o

$(BST_DIR)/AVLTreeTester.o: $(BST_DIR)/AVLTree.h $(BST_DIR)/AVLTree.tpp $(BST_DIR)/AVLTreeTester.cpp 
	$(CCMD) $(BST_DIR)/AVLTreeTester.cpp -o $(BST_DIR)/AVLTreeTester.o


