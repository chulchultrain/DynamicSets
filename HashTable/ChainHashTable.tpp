#ifndef __CHAINHASHTABLE_TPP_INCLUDED__
#define __CHAINHASHTABLE_TPP_INCLUDED__

#include <stdio.h>
//TODO: Try to bypass pputting MAX_HASH_VAL in 2 places at once .tpp and .h files
#ifndef MAX_HASH_VAL
#define MAX_HASH_VAL 523
#endif

template <class T>
ChainHashTable<T>::ChainHashTable() {
	printf("CHAINHASHTABLE CONSTRUCTOR\n");
	maxSize = MAX_HASH_VAL;
	size = 0;
	int i = 0;
	for(i = 0; i < MAX_HASH_VAL; i++)
		table[i] = 0;
	printf("CONSTRUCTOR COMPLETE\n");
}

template <class T>
ChainHashTable<T>::~ChainHashTable() {
	printf("CHAINHASHTABLE DESTRUCTOR\n");
	for(int i = 0; i < MAX_HASH_VAL; i++)
		DeleteList(table[i]);
}

template <class T>
long long ChainHashTable<T>::getSize() {
	return size;
}

template <class T>
long long ChainHashTable<T>::getCount(T x) {
    long long key = hashFunction(x);
	TNode *nodePtr = table[key];
    long long count = 0;
	while(nodePtr != NULL) {
        if(nodePtr->val == x)
            count++;
		nodePtr = nodePtr->next;

    }
    return count;
}

template <class T>
T ChainHashTable<T>::getMax() {
	T max;
	printf("FUNCTION ERROR. CHAINHASHTABLE::GETMAX UNDEF\n");
	return max;
}

template <class T>
T ChainHashTable<T>::getMin() {
	T min;
	printf("FUNCTION ERROR. CHAINHASHTABLE::GETMIN UNDEF\n");
	return min;
}



template <class T>
bool ChainHashTable<T>::search(T x) {
	long long key = hashFunction(x);
	TNode *nodePtr = table[key];
	while(nodePtr != NULL && nodePtr->val != x)
		nodePtr = nodePtr->next;
	if(nodePtr)
		return true;
	else
		return false;
}

template <class T>
void ChainHashTable<T>::insert(T x) {
	//TODO: IMPLEMENT function;
	int i = 0;
	long long key = hashFunction(x);
	TNode *tNode = new TNode;
	tNode->val = x;
	tNode->next = table[key];
	table[key] = tNode;

	printf("INSERT COMPLETE\n");
}

template <class T>
void ChainHashTable<T>::DeleteList(TNode *head) {
	if(head) {
		DeleteList(head->next);
		delete head;
	}
}

template <class T>
void ChainHashTable<T>::remove(T x) {

	//TODO: IMPLEMENT function;
	int i = 0;
	long long key = hashFunction(x);
	TNode *nodePtr = table[key], *prevPtr = NULL;
	while( nodePtr && nodePtr->val != x) {
		prevPtr = nodePtr;
		nodePtr = nodePtr->next;
	}
	if(nodePtr != NULL)
		if(prevPtr) {
			prevPtr->next = nodePtr->next;
			delete nodePtr;
			printf("WAS IN HERE\n");
		}
		else if(nodePtr == table[key]) {
			table[key] = nodePtr->next;
			delete nodePtr;
			printf("WAS IN HERE\n");
		}
	printf("REMOVE COMPLETE\n");
}

template <class T>
T ChainHashTable<T>::getSuccessor(T x) {
	//TODO: IMPLEMENT function;
	T successor;
	printf("FUNCTION ERROR. CHAINHASHTABLE::GETSUCCESSOR UNDEF\n");
	return successor;
}

template <class T>
T ChainHashTable<T>::getPredecessor(T x) {
	//TODO: IMPLEMENT function
	T predecessor;
	printf("FUNCTION ERROR. CHAINHASHTABLE::GETPREDECESSOR UNDEF\n");
	return predecessor;
}

template <class T>
long long ChainHashTable<T>::hashFunction(T x) {
	long long hash = (long long)x % MAX_HASH_VAL;
	return hash;
}

template <class T>
std::string ChainHashTable<T>::objType() {
	std::string result = "ChainHashTable";
	return result;
}


















#endif
