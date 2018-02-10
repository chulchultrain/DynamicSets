HOME_DIR = $(shell pwd)
DS_DIR=$(HOME_DIR)/DynamicSet
HT_DIR = $(HOME_DIR)/HashTable

CC = g++
FLAGS = -I$(HOME_DIR) -c -Wall
CCMD = $(CC) $(FLAGS)

SATester: $(HOME_DIR)/SimpleArrayTester.o $(HOME_DIR)/DynamicSet/DynamicSetTester.o
	$(CC) -o $(HOME_DIR)/SATester $(HOME_DIR)/SimpleArrayTester.o $(HOME_DIR)/DynamicSet/DynamicSetTester.o

CHTTester: $(HT_DIR)/ChainHashTableTester.o
	$(CC) -o $(HOME_DIR)/CHTTester $(HT_DIR)/ChainHashTableTester.o

$(HOME_DIR)/DynamicSet/DynamicSetTester.o: $(DS_DIR)/DynamicSetTester.h $(DS_DIR)/DynamicSetTester.cpp $(DS_DIR)/DynamicSet.h
	$(CCMD)  $(DS_DIR)/DynamicSetTester.cpp -o $(DS_DIR)/DynamicSetTester.o

$(HOME_DIR)/SimpleArrayTester.o: $(HOME_DIR)/SimpleArray.h $(HOME_DIR)/SimpleArrayTester.cpp $(HOME_DIR)/SimpleArray.tpp
	$(CCMD)  $(HOME_DIR)/SimpleArrayTester.cpp -o $(HOME_DIR)/SimpleArrayTester.o


$(HT_DIR)/ChainHashTableTester.o: $(HT_DIR)/HashTable.h $(HT_DIR)/ChainHashTableTester.cpp $(HT_DIR)/ChainHashTable.tpp
	$(CCMD)  $(HT_DIR)/ChainHashTableTester.cpp -o $(HT_DIR)/ChainHashTableTester.o


