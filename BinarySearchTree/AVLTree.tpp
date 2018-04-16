#include <iostream>
#include <stdlib.h>

template <class T>
AVLTree<T>::~AVLTree() {
    destroySubTree(root);
}


template <class T>
T AVLTree<T>::getMax() {
    Node<T> *nodePtr = root;
    T val;
    while(nodePtr->right) {
        nodePtr = nodePtr->right;
    }
    if(nodePtr) {
        val = nodePtr->val;
    }
    return val;
}


template <class T>
T AVLTree<T>::getMin() {
    Node<T> *nodePtr = root;
    T val;
    while(nodePtr->left) {
        nodePtr = nodePtr->left;
    }
    if(nodePtr) {
        val = nodePtr->val;
    }
    return val;
}


template <class T>
void AVLTree<T>::insert(T x) {
    //root = insert(root,x);
    //the first part can be put into a physical insert function
    if(!root) {
        root = new Node<T>(x);
        return;
    }
    Node<T> *nodePtr = root, *parentPtr = NULL;
    while(nodePtr && nodePtr->val != x) {
        parentPtr = nodePtr;
        if(nodePtr->val < x) {
            nodePtr = nodePtr->right;
        } else {
            nodePtr = nodePtr->left;
        }
    }
    if(nodePtr) {
        nodePtr->count++;
        nodePtr->size++;
    } else {
        Node<T> *newNode = new Node<T>(x);
        if(parentPtr->val < x) {
            parentPtr->right = newNode;
        } else {
            parentPtr->left = newNode;
        }
        newNode->parent = parentPtr;
        FixTreeSizes(newNode);
    }

}


template <class T>
void AVLTree<T>::FixTreeSizes(Node<T> *subRoot) {
    Node<T> *nodePtr = subRoot;
    while(nodePtr) {
        setNodeSize(nodePtr);
        nodePtr = nodePtr->parent;
    }
}

template <class T>
void AVLTree<T>::setNodeSize(Node<T> *subRoot) {
    long long leftSize = 0,rightSize = 0;
    if(subRoot->left) {
        leftSize = subRoot->left->size;
    }
    if(subRoot->right) {
        rightSize = subRoot->right->size;
    }
    subRoot->size = subRoot->count + leftSize + rightSize;
}
/*
    an insert on a subtree will return a balanced subtree by returning
    the node that is the root of that subtree.
*/
template <class T>
Node<T> *AVLTree<T>::insert(Node<T> *subRoot,T x) {
    //gotta insert here case.
    if(!subRoot) {
        Node<T> *newNode = new Node<T>();
        return newNode;
    } else {
        //insert logic
        if(subRoot->val == x) {
            subRoot->count++;
            subRoot->size++;
        } else {
            if(subRoot->val < x) {
                subRoot->left = insert(subRoot->left,x);
                subRoot->left->parent = subRoot;
            } else {
                subRoot->right = insert(subRoot->right,x);
                subRoot->right->parent = subRoot;
            }
            setNodeSize(subRoot);
        }
        //rotation logic later
        //fixup logic
        return subRoot;
    }
}

template <class T>
void AVLTree<T>::remove(T x) {
    Node<T> *nodePtr = root, *parentPtr = NULL;
    if(!root) {
        return;
    }
    while(nodePtr && nodePtr->val != x) {
        parentPtr = nodePtr;
        if(nodePtr->val < x) {
            nodePtr = nodePtr->right;
        } else {
            nodePtr = nodePtr->left;
        }
    }
    if(nodePtr) {
        nodePtr->count--;
        nodePtr->size--;
        if(nodePtr->count ==  0) {
            Remove(nodePtr);
            //what about the underlying counts. counts have to be
            //recalculated on  both sides. perhaps built into physical remove.
        }
    }

}

template <class T>
Node<T> **AVLTree<T>::ChildNodePointer(Node<T> *subRoot) {
    Node<T> **res = NULL;
    if(subRoot->left) {
        res = &subRoot->left;
    } else if(subRoot->right) {
        res = &subRoot->right;
    }
    return res;
}

/*
assumption subroot exists
*/
template<class T>
Node<T> *AVLTree<T>::LeftMostChild(Node<T> *subRoot) {
    if(subRoot->left) {
        return subRoot->left;
    } else if(subRoot->right) {
        return subRoot->right;
    } else
        return NULL;
}

/*
    Notes: Use the double pointer to be able to
    set parent->left or parent
*/

template <class T>
int AVLTree<T>::NumChildren(Node<T> *subRoot) {
    int res = 0;
    if(subRoot->left) {
        res++;
    }
    if(subRoot->right) {
        res++;
    }
    return res;
}

/*
    take care parent child connections. won't have to deal with the case
    of 2 children.
*/
template <class T>
void AVLTree<T>::Physical_Remove(Node<T> *removeNode) {
    if(root == removeNode) {
        //special root case.
        root = LeftMostChild(removeNode);
        root->parent = NULL;
        delete removeNode;
    } else {
        //non root case. important detail = has a parent.
        Node<T> *parentNode = removeNode->parent;
        Node<T> **removeNodeDirectionPointer = ChildNodePointer(parentNode);
        Node<T> *childNode = LeftMostChild(removeNode);

        (*removeNodeDirectionPointer) = childNode;
        childNode->parent = parentNode;
    }
}

template <class T>
void AVLTree<T>::Remove(Node<T> *removeNode) {
    // if have zero children. A-okay.
    // if have only one child, okay, just connect parent to child.
    // if have 2 children, put node's successor in its place.
    // because node successor if 2 children is left most
    int nc = NumChildren(removeNode);
    if(nc == 0) {
        Physical_Remove(removeNode);
    } else if(nc == 1) {
        Physical_Remove(removeNode);
    } else {
        Node<T> *successorNode = getSuccessorNode(removeNode);
        long long successorCount = successorNode->count;
        T successorVal = successorNode->val;
        Physical_Remove(getSuccessorNode(removeNode));
        removeNode->count = successorCount;
        removeNode->val = successorVal;
    }
}

template <class T>
Node<T> *AVLTree<T>::getSuccessorNode(Node<T> *subRoot) {
    Node<T> *res = NULL;
    Node<T> *nodePtr = subRoot;
    if(subRoot->right) {
        nodePtr = subRoot->right;
        while(nodePtr->left) {
            nodePtr = nodePtr->left;
        }
    } else {
        while(nodePtr) {
            if(nodePtr->parent && nodePtr->parent->left == nodePtr) {
                nodePtr = nodePtr->parent;
                break;
            } else {
                nodePtr = nodePtr->parent;
            }
        }
    }
    res = nodePtr;
    return res;
}

template <class T>
Node<T> *AVLTree<T>::getPredecessorNode(Node<T> *subRoot) {
    Node<T> *res = NULL;
    Node<T> *nodePtr = subRoot;
    if(subRoot->left) {
        nodePtr = subRoot->left;
        while(nodePtr->right) {
            nodePtr = nodePtr->right;
        }
    } else {
        while(nodePtr) {
            if(nodePtr->parent && nodePtr->parent->right == nodePtr) {
                nodePtr = nodePtr->parent;
                break;
            } else {
                nodePtr = nodePtr->parent;
            }
        }
    }
    res = nodePtr;
    return res;
}


template <class T>
T AVLTree<T>::getSuccessor(T x) {
    T val;
    return val;
}


template <class T>
T AVLTree<T>::getPredecessor(T x) {
    T val;
    return val;
}


template <class T>
long long AVLTree<T>::getSize() {
    if(root)
        return root->size;
    else
        return 0LL;
}


template <class T>
bool AVLTree<T>::search(T x) {
    return true;
}


template <class T>
long long AVLTree<T>::getCount(T x) {
    return 0;
}


template <class T>
long long AVLTree<T>::getRank(T x) {
    return 0;
}

template <class T>
void AVLTree<T>::PreOrderTraversal() {
    PreOrderTraversal(root);
}

template <class T>
void AVLTree<T>::PreOrderTraversal(Node<T> *subRoot) {
    if(subRoot) {
        std::cout << subRoot->val << '\n';
        PreOrderTraversal(subRoot->left);
        PreOrderTraversal(subRoot->right);
    }
}

template <class T>
void AVLTree<T>::InOrderTraversal() {
    InOrderTraversal(root);
}

template <class T>
void AVLTree<T>::InOrderTraversal(Node<T> *subRoot) {
    if(subRoot) {
        InOrderTraversal(subRoot->left);
        std::cout << subRoot->val << '\n';
        InOrderTraversal(subRoot->right);
    }
}

template <class T>
void AVLTree<T>::PostOrderTraversal() {
    PostOrderTraversal(root);
}

template <class T>
void AVLTree<T>::PostOrderTraversal(Node<T> *subRoot) {
    if(subRoot) {
        PostOrderTraversal(subRoot->left);
        PostOrderTraversal(subRoot->right);
        std::cout << subRoot->val << '\n';
    }
}

template <class T>
void AVLTree<T>::destroySubTree(Node<T> *subRoot) {
    if(subRoot) {
        destroySubTree(subRoot->left);
        destroySubTree(subRoot->right);
        delete subRoot;
    }
}

template <class T>
void AVLTree<T>::clear() {
    destroySubTree(root);
}

template <class T>
std::string AVLTree<T>::objType() {
    std::string result = "AVLTree";
    return result;
}
