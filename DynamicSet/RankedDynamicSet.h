#ifndef __RANKEDDYNAMICSET_H_INCLUDED__
#define __RANKEDDYNAMICSET_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <DynamicSet/DynamicSet.h>

template <class T>
class RankedDynamicSet : public DynamicSet<T> {
	public:
		RankedDynamicSet() { printf("RANKED DYNAMIC SET CONSTRUCTOR\n"); };
		virtual ~RankedDynamicSet() { printf("RANKED DYNAMIC SET DESTRUCTOR\n"); };
		virtual T getMax() = 0;
		virtual T getMin() = 0;
		virtual void insert(T x) = 0;
		virtual void remove(T x) = 0;
		virtual T getSuccessor(T x) = 0;
		virtual T getPredecessor(T x) = 0;
		virtual long long getSize() = 0;
		virtual bool search(T x) = 0;
        virtual void clear() = 0;
		virtual long long getCount(T x) = 0;
        virtual long long getRank(T x) = 0;
		virtual std::string objType() = 0;
	private:

};



#endif
