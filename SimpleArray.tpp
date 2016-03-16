#ifndef __SIMPLEARRAY_TPP_INCLUDED__
#define __SIMPLEARRAY_TPP_INCLUDED__

#include <stdio.h>

#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100
#endif

template <class T>
SimpleArray<T>::SimpleArray() {
	printf("SIMPLEARRAY CONSTRUCTOR\n");
	numElements = 0;
	maxSize = MAX_ARRAY_SIZE;
}

template <class T>
SimpleArray<T>::~SimpleArray() {
	//TODO: ADD a cout statement to see what executes. Do it in the Dynamic Set destroyer too.
 	printf("SIMPLEARRAY DESTRUCTOR\n");
}

template <class T>
bool SimpleArray<T>::search(T x) {
	for(int i = 0; i < numElements; i++)	
		if(elements[i] == x)
			return true;
	return false;
}

template <class T>
long long SimpleArray<T>::getSize() {
	return numElements;
}

template <class T>
T SimpleArray<T>::getMax() {
	T maxElement = elements[0];
	unsigned int i;
	for(i = 0; i < numElements; i++)
		if(maxElement < elements[i])
			maxElement = elements[i];
	return maxElement;
}

template <class T>
T SimpleArray<T>::getMin(){
	T minElement = elements[0];
	unsigned int i;
	for(i = 0; i < numElements; i++)
		if(minElement < elements[i])
			minElement = elements[i];
	return minElement;
}



template <class T>
void SimpleArray<T>::insert(T x){
	if(numElements < MAX_ARRAY_SIZE) {
		elements[numElements] = x;
		numElements++;
	}		
}

template <class T>
void SimpleArray<T>::remove(T x){
	unsigned int i = 0,j = 0;
	if(numElements > 0) {
		while(i < numElements && elements[i] != x)
			i++;
		if(i < numElements) {
		j = numElements - 1;
		elements[i] = elements[j];
		numElements--;
		}
	}
}

template <class T>
T SimpleArray<T>::getSuccessor(T x) {
	T successor = getMax();
	unsigned int i,j;
	for(i = 0; i < numElements; i++)
		if(elements[i] > x && elements[i] <= successor)
			successor = elements[i];
	return successor;
}

template <class T>
T SimpleArray<T>::getPredecessor(T x) {
	T predecessor = getMin();
	unsigned int i,j;
	for(i = 0; i < numElements; i++)
		if(elements[i] < x && elements[i] >= predecessor)
			predecessor = elements[i];
	return predecessor;
}

template <class T>
std::string SimpleArray<T>::objType() {
	std::string result = "SimpleArray";
	return result;
};

#endif



















