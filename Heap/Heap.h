#ifndef __HEAP_H_INCLUDED__
#define __HEAP_H_INCLUDED__


template <class T>
class Heap : public DynamicSet<T> {
	public:
		Heap() { printf("HEAP CONSTRUCTOR\n"); };
		virtual ~Heap() { printf("DYNAMIC SET DESTRUCTOR\n"); };
		virtual T getMax() = 0;
		virtual T getMin() = 0;
		virtual void insert(T x) = 0;
		virtual void remove(T x) = 0;
		virtual T getSuccessor(T x) = 0;
		virtual T getPredecessor(T x) = 0;
		virtual long long getSize() = 0;
		virtual bool search(T x) = 0;
		
	private:	








};










#endif
