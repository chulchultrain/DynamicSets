#ifndef __AVLTREE_H_INCLUDED__
#define __AVLTREE_H_INCLUDED__

#include <string>
#include <stdlib.h>
#include <iostream>
#include <BinarySearchTree/BinarySearchTree.h>

template <class T>
struct Node {
    T val;
    long long count;
    long long size;
    long long height;
    long long distinct_size;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    Node() { count = size = 0; left = right = parent = NULL; height = distinct_size = 0; }
    Node(T x) { count = size = 1; left = right = parent = NULL; val = x; height = 1; distinct_size = 1;}
    void printState() {
        std::cout << "V: " << val << " ";
        std::cout << "A: " << this << " ";
        std::cout << "L: " << left << " ";
        std::cout << "R: " << right << " ";
        std::cout << "P: " <<  parent << " ";
        std::cout << "H: " <<  height << " ";
        std::cout << "C: " << count << " ";
        std::cout << "S: " << size << " ";
        std::cout <<  "DS: " << distinct_size << "\n";
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

        void LRRTest();
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
        void swapVal(Node<T> *n1, Node<T> *n2);
        void setNodeSize(Node<T> *subRoot);
        void setNodeDistinctSize(Node<T> *subRoot);
        void setNodeHeight(Node<T> *subRoot);
        void FixTreeSizes(Node<T> *subRoot);
        void destroySubTree(Node<T> *subRoot);

        void Remove(Node<T> *subRoot);
        Node<T> *getSuccessorNode(Node<T> *subRoot);
        Node<T> *getPredecessorNode(Node<T> *subRoot);

        void PreOrderTraversal(Node<T> *subRoot);
        void InOrderTraversal(Node<T> *subRoot);
        void PostOrderTraversal(Node<T> *subRoot);

        void LeftRotate(Node<T> *subRoot);
        void RightRotate(Node<T> *subRoot);
        void SetChildParent(Node<T> *child, Node<T> *adult, std::string side);
        void FixBranch(Node<T> *subRoot);
        long long Balance(Node<T> *subRoot);
};

#include <BinarySearchTree/AVLTree.tpp>

#endif
