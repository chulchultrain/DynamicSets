#ifndef __HASHTABLE_H_INCLUDED__
#define __HASHTABLE_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <DynamicSet/DynamicSet.h>

template <class T>
class HashTable : public DynamicSet<T> {
	public:
		HashTable() { printf("HASHTABLE CONSTRUCTER\n"); };
		virtual ~HashTable() { printf("HASHTABLE DESTRUCTOR\n"); };
		virtual T getMax() = 0;
		virtual T getMin() = 0;
		virtual void insert(T x) = 0;
		virtual void remove(T x) = 0;
		virtual T getSuccessor(T x) = 0;
		virtual T getPredecessor(T x) = 0;
		virtual long long hashFunction(T x) = 0;
};














#endif
