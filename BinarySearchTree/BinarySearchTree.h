#ifndef __BINARYSEARCHTREE_H_INCLUDED__
#define __BINARYSEARCHTREE_H_INCLUDED__

#include <DynamicSet/DynamicSet.h>

	template <class T>
	struct Node {
		Node *parent, *left, *right;
		T val;
		long long size,count,height;
		Node(T v) {val = v; parent = left = right = 0; height = 0; size = count = 1; };
	};

template <class T>
class BinarySearchTree : public DynamicSet<T> {
	public:
		BinarySearchTree();
		virtual ~BinarySearchTree();
		virtual T getMax();
		virtual T getMin();
		virtual void insert(T x);
		virtual void remove(T x);
		virtual T getSuccessor(T x);
		virtual T getPredecessor(T x);
		virtual long long getSize();
		virtual bool search(T x);
		virtual std::string objType();
		virtual long long getCount(T x);		

	protected:

		Node<T> *root;
		void DeleteSubTree(Node<T> *root);
		Node<T> *getSubTreeMax(Node<T> *root);
		Node<T> *getSubTreeMin(Node<T> *root);
		Node<T> *getSuccessor(Node<T> *nodePtr);
		Node<T> *getPredecessor(Node<T> *nodePtr);
		void swapVal(Node<T> *n1, Node<T> *n2);
		int numChildren(Node<T> *n);
		virtual void preOrderTraversal(Node<T> *n);

		void UpdateNode(Node<T> *n);
		Node<T> *searchForNode(T x);
		
		void BalanceTree(Node<T> *n);
		long long nodeBalance(Node<T> *n);
		void LeftRotate(Node<T> *n);
		void RightRotate(Node<T> *n);
		void FixUpTree(Node<T> *n);
	private:
		

};




#include <BinarySearchTree/BinarySearchTree.tpp>





#endif










