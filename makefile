DS_DIR = $(shell pwd)
HT_DIR = $(DS_DIR)/HashTable
CC = g++
FLAGS = -I$(DS_DIR) -c -Wall
CCMD = $(CC) $(FLAGS)

SATester: $(DS_DIR)/SimpleArrayTester.o $(DS_DIR)/DynamicSet/DynamicSetTester.o
	$(CC) -o $(DS_DIR)/SATester $(DS_DIR)/SimpleArrayTester.o $(DS_DIR)/DynamicSet/DynamicSetTester.o

CHTTester: $(HT_DIR)/ChainHashTableTester.o
	$(CC) -o $(DS_DIR)/CHTTester $(HT_DIR)/ChainHashTableTester.o

$(DS_DIR)/DynamicSet/DynamicSetTester.o: $(DS_DIR)/DynamicSet/DynamicSetTester.h $(DS_DIR)/DynamicSet/DynamicSetTester.cpp
	$(CCMD)  $(DS_DIR)/DynamicSet/DynamicSetTester.cpp -o $(DS_DIR)/DynamicSet/DynamicSetTester.o

$(DS_DIR)/SimpleArrayTester.o: $(DS_DIR)/SimpleArray.h $(DS_DIR)/SimpleArrayTester.cpp $(DS_DIR)/SimpleArray.tpp
	$(CCMD)  $(DS_DIR)/SimpleArrayTester.cpp -o $(DS_DIR)/SimpleArrayTester.o


$(HT_DIR)/ChainHashTableTester.o: $(HT_DIR)/HashTable.h $(HT_DIR)/ChainHashTableTester.cpp $(HT_DIR)/ChainHashTable.tpp
	$(CCMD)  $(HT_DIR)/ChainHashTableTester.cpp -o $(HT_DIR)/ChainHashTableTester.o


