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
		virtual void insert(T x) = 0;
		virtual void remove(T x) = 0;
		virtual long long getSize() = 0;
		virtual bool search(T x) = 0;
        virtual void clear() = 0;
		virtual long long getCount(T x) = 0;
		virtual std::string objType() = 0;
};



#endif
