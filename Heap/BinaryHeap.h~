#ifndef __BINARYHEAP_H_INCLUDED__
#define __BINARYHEAP_H_INCLUDED__


template <class T>
class BinaryHeap : public DynamicSet<T> {
	public:
		BinaryHeap() { printf("BINARYHEAP CONSTRUCTOR\n"); };
		virtual ~BinaryHeap() { printf("BINARYHEAP DESTRUCTOR\n"); };
		virtual T getMax() = 0;
		virtual T getMin() = 0;
		virtual void insert(T x) = 0;
		virtual void remove(T x) = 0;
		virtual T getSuccessor(T x) = 0;
		virtual T getPredecessor(T x) = 0;
		virtual long long getSize() = 0;
		virtual bool search(T x) = 0;
	protected:
		virtual long long LeftChild(long long node) = 0;
		virtual long long RightChild(long long node) = 0;
		virtual long long parent(long long node) = 0;


};










#endif
