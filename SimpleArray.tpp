#ifndef __SIMPLEARRAY_TPP_INCLUDED__
#define __SIMPLEARRAY_TPP_INCLUDED__

#include <stdio.h>


template <class T>
SimpleArray<T>::SimpleArray() {
	printf("SIMPLEARRAY CONSTRUCTOR\n");
	numElements = maxIndex = 0;
	maxSize = MAX_ARRAY_SIZE;
}

template <class T>
SimpleArray<T>::~SimpleArray() {
	//TODO: ADD a cout statement to see what executes. Do it in the Dynamic Set destroyer too.
 	printf("SIMPLEARRAY DESTRUCTOR\n");
}

template <class T>
void SimpleArray<T>::swapElements(int i,int j) {
	Node<T> temp = elements[i];
	elements[i] = elements[j];
	elements[j] = temp;
}

template <class T>
bool SimpleArray<T>::search(T x) {
	for(int i = 0; i < maxIndex; i++)
		if(elements[i].val == x)
			return true;
	return false;
}

template <class T>
long long SimpleArray<T>::getCount(T x) {
	for(int i = 0; i < maxIndex; i++)
		if(elements[i].val == x)
			return elements[i].count;
	return 0;
}

template <class T>
long long SimpleArray<T>::getSize() {
	return numElements;
}

template <class T>
T SimpleArray<T>::getMax() {
	T maxElement = elements[0].val;
	unsigned int i;
	for(i = 0; i < numElements; i++)
		if(maxElement < elements[i].val)
			maxElement = elements[i].val;
	return maxElement;
}

template <class T>
T SimpleArray<T>::getMin(){
	T minElement = elements[0].val;
	unsigned int i;
	for(i = 0; i < maxIndex; i++)
		if(minElement < elements[i].val)
			minElement = elements[i].val;
	return minElement;
}



template <class T>
void SimpleArray<T>::insert(T x){
	unsigned int i = 0;
	while(i < maxIndex && elements[i].val != x)
		i++;
	if(i < maxIndex) {
		elements[i].count++;
		numElements++;
	}
	else if(i == maxIndex && i < MAX_ARRAY_SIZE) {
		elements[maxIndex].val = x;
		elements[maxIndex].count = 1;
		maxIndex++;
		numElements++;
	}

}

template <class T>
void SimpleArray<T>::remove(T x){
	unsigned int i = 0,j = 0;
	if(maxIndex > 0) {
		while(i < maxIndex && elements[i].val != x)
			i++;
		if(i < maxIndex) {
			if(elements[i].count > 1) {
				elements[i].count--;
			}
			else {
				j = maxIndex - 1;
				swapElements(i,j);
				maxIndex--;
			}
			numElements--;
		}
	}
}

template <class T>
std::string SimpleArray<T>::objType() {
	std::string result = "SimpleArray";
	return result;
};

template <class T>
void SimpleArray<T>::clear() {
    maxIndex = 0;
    numElements = 0;
    for(long long i = 0; i < maxSize; i++) {
        elements[i].count = 0;
    }
}

#endif
