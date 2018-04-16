#ifndef __BINARYSEARCHTREE_H_INCLUDED__
#define __BINARYSEARCHTREE_H_INCLUDED__

#include <DynamicSet/RankedDynamicSet.h>

template <class T>
class BinarySearchTree : public RankedDynamicSet<T> {
    public:
        BinarySearchTree() { printf("BINARY SEARCH TREE CONSTRUCTOR\n");};
        virtual ~BinarySearchTree() { printf("BINARY SEARCH TREE DESTRUCTOR\n");};
        virtual T getMax() = 0;
		virtual T getMin() = 0;
		virtual void insert(T x) = 0;
		virtual void remove(T x) = 0;
		virtual T getSuccessor(T x) = 0;
		virtual T getPredecessor(T x) = 0;
		virtual long long getSize() = 0;
		virtual bool search(T x) = 0;
		virtual long long getCount(T x) = 0;
        virtual long long getRank(T x) = 0;
		virtual std::string objType() = 0;

};

#endif
