#ifndef __AVLTREE_H_INCLUDED__
#define __AVLTREE_H_INCLUDED__

#include <string>
#include <stdlib.h>
#include <BinarySearchTree/BinarySearchTree.h>

template <class T>
struct Node {
    T val;
    long long count;
    long long size;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    Node() { count = size = 0; left = right = parent = NULL; };
    Node(T x) { count = size = 1; left = right = parent = NULL; val = x; }
    void printState() {
        printf("ADDR: %p ", this);
        printf("LEFT: %p ", left);
        printf("RIGHT: %p ", right);
        printf("PARENT: %p \n", parent);
    }
};

template <class T>
class AVLTree : public BinarySearchTree<T> {
    public:
        AVLTree() { printf("AVL TREE CONSTRUCTOR\n");};
        virtual ~AVLTree();
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

        void PreOrderTraversal();
        void InOrderTraversal();
        void PostOrderTraversal();
        void clear();
    private:

        Node<T> *root;
        Node<T> *insert(Node<T> *subRoot,T x);
        Node<T> *searchNode(T x);
        void PrintPreOrderTraversal();
        void PrintPostOrderTraversal();

        int NumChildren(Node<T> *subRoot);
        Node<T> **ChildNodePointer(Node<T> *subRoot,Node<T> *childNode);
        void Physical_Remove(Node<T> *removeNode);
        Node<T> *LeftMostChild(Node<T> *subRoot);
        void setNodeSize(Node<T> *subRoot);
        void FixTreeSizes(Node<T> *subRoot);
        void destroySubTree(Node<T> *subRoot);

        void Remove(Node<T> *subRoot);
        Node<T> *getSuccessorNode(Node<T> *subRoot);
        Node<T> *getPredecessorNode(Node<T> *subRoot);

        void PreOrderTraversal(Node<T> *subRoot);
        void InOrderTraversal(Node<T> *subRoot);
        void PostOrderTraversal(Node<T> *subRoot);
};

#include <BinarySearchTree/AVLTree.tpp>

#endif
