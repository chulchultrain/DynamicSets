#ifndef __SIMPLEARRAY_H_INCLUDED__
#define __SIMPLEARRAY_H_INCLUDED__

#include <DynamicSet/DynamicSet.h>


#ifndef MAX_ARRAY_SIZE
#define MAX_ARRAY_SIZE 100000
#endif

template <class T>
struct Node {
	T val;
	long long count;
    Node() {count = 0;}
    Node(T x) {val = x; count = 1;}
};

template <class T>
class SimpleArray : public DynamicSet<T> {
	public:
		virtual T getMax();
		virtual T getMin();
		virtual void insert(T x);
		virtual void remove(T x);
		virtual bool search(T x);
		virtual long long getSize();
        virtual void clear();
		SimpleArray();
		virtual ~SimpleArray();
		virtual std::string objType();
		virtual long long getCount(T x);
	private:
		void swapElements(int i,int j);
		Node<T> elements[MAX_ARRAY_SIZE];
		long long maxIndex;
		long long maxSize;
		long long numElements;

};



#include <SimpleArray.tpp>














#endif
