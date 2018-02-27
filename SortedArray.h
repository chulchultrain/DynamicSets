#ifndef __SORTEDARRAY_H_INCLUDED__
#define __SORTEDARRAY_H_INCLUDED__

#include <DynamicSet/RankedDynamicSet.h>

#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100000
#endif

template <class T>
struct Node {
	T val;
	long long count;
};

template <class T>
class SortedArray : public RankedDynamicSet<T> {
    public:
        SortedArray();
		virtual ~SortedArray();
		virtual T getMax();
		virtual T getMin();
		virtual void insert(T x);
		virtual void remove(T x);
		virtual T getSuccessor(T x);
		virtual T getPredecessor(T x);
		virtual long long getSize();
		virtual bool search(T x);
		virtual long long getCount(T x);
        virtual long long getRank(T x);
		virtual std::string objType();
    private:
        long long lookUpIndex(T x);
        long long lookUpPlaceToPut(T x);
        void PrintState();
        long long numElements;
        long long array_size;
        Node<T> elements[MAX_ARRAY_SIZE];
};

#include <SortedArray.tpp>

#endif
