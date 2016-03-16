#ifndef __MAXBINARYHEAP_H_INCLUDED__
#define __MAXBINARYHEAP_H_INCLUDED__


#include <string>
#include <DynamicSet/DynamicSet.h>

#ifndef MAX_HEAP_SIZE
#define MAX_HEAP_SIZE 200
#endif

template <class T>
class MaxBinaryHeap : public DynamicSet<T> {
	public:
		MaxBinaryHeap();
		virtual ~MaxBinaryHeap();
		virtual T getMax();
		virtual T getMin();
		virtual void insert(T x);
		virtual void remove(T x);
		virtual T getSuccessor(T x);
		virtual T getPredecessor(T x);
		virtual long long getSize();
		virtual bool search(T x);
		virtual std::string objType();
		T extractMax();
	private:	
		virtual long long leftChild(long long node);
		virtual long long rightChild(long long node);
		virtual long long parent(long long node);
		void swap(long long index1, long long index2);
		void Heapify(long long pos);
		T elements[MAX_HEAP_SIZE];	
		long long size;





};


#include <Heap/MaxBinaryHeap.tpp>




#endif
