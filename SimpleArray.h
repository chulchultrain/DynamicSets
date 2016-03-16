#ifndef __SIMPLEARRAY_H_INCLUDED__
#define __SIMPLEARRAY_H_INCLUDED__

#include <DynamicSet/DynamicSet.h>


#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100
#endif

template <class T>
class SimpleArray : public DynamicSet<T> {
	public:
		virtual T getMax();
		virtual T getMin();
		virtual void insert(T x);
		virtual void remove(T x);
		virtual bool search(T x);
		virtual T getSuccessor(T x);
		virtual T getPredecessor(T x);
		virtual long long getSize();
		SimpleArray();
		virtual ~SimpleArray();
		virtual std::string objType();	
	private:
		T elements[MAX_ARRAY_SIZE];
		long long numElements;
		long long maxSize;
};



#include <SimpleArray.tpp>














#endif
