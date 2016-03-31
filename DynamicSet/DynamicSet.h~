#ifndef __DYNAMICSET_H_INCLUDED__
#define __DYNAMICSET_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <string>

template <class T>
class DynamicSet{
	public:
		DynamicSet() { printf("DYNAMICSET CONSTRUCTOR\n"); };
		virtual ~DynamicSet() { printf("DYNAMIC SET DESTRUCTOR\n"); };
		virtual T getMax() = 0;
		virtual T getMin() = 0;
		virtual void insert(T x) = 0;
		virtual void remove(T x) = 0;
		virtual T getSuccessor(T x) = 0;
		virtual T getPredecessor(T x) = 0;
		virtual long long getSize() = 0;
		virtual bool search(T x) = 0;
		virtual std::string objType() = 0;
	private:

};



#endif




