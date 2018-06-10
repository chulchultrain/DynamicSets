#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cstring>

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
        FixTreeSizes(nodePtr);
    } else {
        Node<T> *newNode = new Node<T>(x);
        if(parentPtr->val < x) {
            parentPtr->right = newNode;
        } else {
            parentPtr->left = newNode;
        }
        newNode->parent = parentPtr;
        FixTreeSizes(newNode);
        FixBranch(newNode);
    }

}




template <class T>
void AVLTree<T>::FixTreeSizes(Node<T> *subRoot) {
    Node<T> *nodePtr = subRoot;
    while(nodePtr) {
        setNodeSize(nodePtr);
        setNodeDistinctSize(nodePtr);
        setNodeHeight(nodePtr);
        nodePtr = nodePtr->parent;
    }
}

template <class T>
void AVLTree<T>::setNodeHeight(Node<T> *subRoot) {
    long long leftHeight = 0, rightHeight = 0;
    if(subRoot->left) {
        leftHeight = subRoot->left->height;
    }
    if(subRoot->right) {
        rightHeight = subRoot->right->height;
    }
    subRoot->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

template <class T>
void AVLTree<T>::setNodeDistinctSize(Node<T> *subRoot) {
    long long leftSize = 0,rightSize = 0;
    if(subRoot->left) {
        leftSize = subRoot->left->distinct_size;
    }
    if(subRoot->right) {
        rightSize = subRoot->right->distinct_size;
    }
    subRoot->distinct_size = 1 + leftSize + rightSize;
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
    Node<T> *nodePtr = root;
    //Node<T> *parentPtr = NULL;
    if(!root) {
        return;
    }
    while(nodePtr && nodePtr->val != x) {
        //parentPtr = nodePtr;
        if(nodePtr->val < x) {
            nodePtr = nodePtr->right;
        } else {
            nodePtr = nodePtr->left;
        }
    }
    if(nodePtr) {
        nodePtr->count--;
        nodePtr->size--;
        FixTreeSizes(nodePtr);
        if(nodePtr->count ==  0) {
            Remove(nodePtr);
            //what about the underlying counts. counts have to be
            //recalculated on  both sides. perhaps built into physical remove.
        }

    }

}

template <class T>
Node<T> **AVLTree<T>::ChildNodePointer(Node<T> *subRoot, Node<T> *childNode) {
    Node<T> **res = NULL;
    if(subRoot->left == childNode) {
        res = &subRoot->left;
    } else if(subRoot->right == childNode) {
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


template <class T>
void AVLTree<T>::swapVal(Node<T> *n1, Node<T> *n2) {
	T temp = n1->val;
	n1->val = n2->val;
	n2->val = temp;
	long long tempCount = n1->count;
	n1->count = n2->count;
	n2->count = tempCount;
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
        if(root)
            root->parent = NULL;
        delete removeNode;
    } else {
        //non root case. important detail = has a parent.
        Node<T> *parentNode = removeNode->parent;
        Node<T> **removeNodeDirectionPointer = ChildNodePointer(parentNode,removeNode);
        Node<T> *childNode = LeftMostChild(removeNode);
        //std::cout << "AFTER CHILDNODEPOINTER AND LEFTMOSTCHILD IN PR" << std::endl << std::endl;
        (*removeNodeDirectionPointer) = childNode;
        //std::cout << "AFTER REFERENCE RNDP" << std::endl << std::endl;
        if(childNode)
            childNode->parent = parentNode;
        //std::cout << "AFTER CNP = P" << std::endl << std::endl;
        delete removeNode;
        //std::cout << "AFTER REMOVE " << std::endl << std::endl;
        FixTreeSizes(parentNode);
        //std::cout << "AFTER FTS" << std::endl << std::endl;
        FixBranch(parentNode);
        //std::cout << "AFTER FB" << std::endl << std::endl;
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
        ////std::cout << "2child route" << std::endl << std::endl;
        Node<T> *successorNode = getSuccessorNode(removeNode);
        swapVal(removeNode,successorNode);
        Physical_Remove(successorNode);

        FixTreeSizes(removeNode);
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
    memset(&val,0,sizeof(T));
    Node<T> *nodePtr = searchNode(x);
    if(nodePtr) {
        Node<T> *successorNode = getSuccessorNode(nodePtr);
        if(successorNode)
            val = successorNode->val;
    }
    return val;
}


template <class T>
T AVLTree<T>::getPredecessor(T x) {
    T val;
    memset(&val,0,sizeof(T));
    Node<T> *nodePtr = searchNode(x);
    if(nodePtr) {
        Node<T> *predecessorNode = getPredecessorNode(nodePtr);
        if(predecessorNode)
            val = predecessorNode->val;
    }
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
Node<T> *AVLTree<T>::searchNode(T x) {
    Node<T> *nodePtr = root;
    while(nodePtr != NULL && nodePtr->val != x) {
        if(nodePtr->val < x)
            nodePtr = nodePtr->right;
        else
            nodePtr = nodePtr->left;
    }
    return nodePtr;
}


template <class T>
bool AVLTree<T>::search(T x) {
    Node<T> *nodePtr = searchNode(x);
    if(nodePtr)
        return true;
    else
        return false;
}


template <class T>
long long AVLTree<T>::getCount(T x) {
    Node<T> *nodePtr = searchNode(x);
    long long count = 0;
    if(nodePtr)
        count = nodePtr->count;
    return count;
}

template <class T>
long long AVLTree<T>::getRank(T x) {
    if(searchNode(x) == NULL)
        return 0;
    long long lower_b = 1;
    Node<T> *nodePtr = root;
    while(nodePtr->val != x) {
        if(nodePtr->val < x) {
            if(nodePtr->left)
                lower_b += nodePtr->left->distinct_size;
            lower_b++;
            nodePtr = nodePtr->right;
        } else {
            nodePtr = nodePtr->left;
        }
    }
    if(nodePtr->val == x)
        if(nodePtr->left)
            lower_b += nodePtr->left->distinct_size;
        return lower_b;
    return 0;
}

template <class T>
void AVLTree<T>::PreOrderTraversal() {
    PreOrderTraversal(root);
}

template <class T>
void AVLTree<T>::PreOrderTraversal(Node<T> *subRoot) {
    if(subRoot) {
        subRoot->printState();
        //std::cout << subRoot->val << '\n';
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
        //std::cout << "HERE\n";
        destroySubTree(subRoot->left);
        destroySubTree(subRoot->right);
        delete subRoot;
    }
}

template <class T>
void AVLTree<T>::clear() {
    //std::cout << "HIHI" << std::endl << std::endl << std::endl;
    destroySubTree(root);
}

template <class T>
std::string AVLTree<T>::objType() {
    std::string result = "AVLTree";
    return result;
}

template <class T>
void AVLTree<T>::SetChildParent(Node<T> *child, Node<T> *parent, std::string side) {
    if(child) {
        child->parent = parent;
    }
    if(parent) {
        if(side == "left")
            parent->left = child;
        if(side == "right")
            parent->right = child;
    }
}

/*
    if the node doesnt exist or the rightchild of the node doesnt exist,
    no left rotate can actually be done.

    we stitch the subroots parent as the parent of the right child.


    the left child of the right child gets stuck as the original subroot's
    right child.

*/

template <class T>
void AVLTree<T>::LeftRotate(Node<T> *subRoot) {
    if(!subRoot)
        return;
    //Node<T> *leftChild = subRoot->left;
    Node<T> *rightChild = subRoot->right;
    if(!rightChild)
        return;
    Node<T> *parent = subRoot->parent;

    Node<T> *rightChildLeftChild = rightChild->left;
    std::string s = "left";
    if(parent) {
        if(parent->right == subRoot)
            s = "right";
    }

    SetChildParent(rightChild,parent,s);
    SetChildParent(subRoot,rightChild,"left");
    SetChildParent(rightChildLeftChild,subRoot,"right");
    FixTreeSizes(subRoot);
    FixTreeSizes(rightChild);
    if(root == subRoot) {
        root = rightChild;
    }

}

template <class T>
void AVLTree<T>::RightRotate(Node<T> *subRoot) {
    if(!subRoot)
        return;
    Node<T> *leftChild = subRoot->left;
    //Node<T> *rightChild = subRoot->right;
    if(!leftChild)
        return;

    Node<T> *parent = subRoot->parent;

    Node<T> *leftChildRightChild = leftChild->right;
    std::string s = "left";
    if(parent) {
        if(parent->right == subRoot) {
            s = "right";
        }
    }
    SetChildParent(leftChild,parent,s);
    SetChildParent(subRoot,leftChild,"right");
    SetChildParent(leftChildRightChild,subRoot,"left");
    FixTreeSizes(subRoot);
    FixTreeSizes(leftChild);
    if(root == subRoot) {
        root = leftChild;
    }
}

template <class T>
long long AVLTree<T>::Balance(Node<T> *subRoot) {
    if(!subRoot)
        return 0LL;
    long long leftHeight = 0,rightHeight = 0;
    if(subRoot->left)
        leftHeight = subRoot->left->height;
    if(subRoot->right)
        rightHeight = subRoot->right->height;
    long long res = leftHeight - rightHeight;
    return res;
}

template <class T>
void AVLTree<T>::FixBranch(Node<T> *subRoot) {
    if(!subRoot)
        return;
    //std::cout << "START FIXBRANCH " << subRoot->val << std::endl;
    long long dif = Balance(subRoot);
    if(dif > 1) {
        //std::cout << "LEFT" << std::endl;
        long long leftBalance = Balance(subRoot->left);
        if(leftBalance <= -1)
            LeftRotate(subRoot->left);
        RightRotate(subRoot);
    } else if(dif < -1) {
        //std::cout << "RIGHT" << std::endl;
        long long rightBalance = Balance(subRoot->left);
        if(rightBalance >= 1)
            RightRotate(subRoot->right);
        LeftRotate(subRoot);
    }
    //std::cout << "AFTER ROTATE " << subRoot->val << std::endl;
    FixBranch(subRoot->parent);
}

template <class T>
void AVLTree<T>::LRRTest() {
    LeftRotate(root);
    PreOrderTraversal();
    InOrderTraversal();
    RightRotate(root);
    PreOrderTraversal();
    InOrderTraversal();
}
/*
TODO:Test inserts of same number can be done under RDS Tester
TODO:add a field for rank. cuz count counts all instances,
but we need something for unique instance.
TODO:update all pertinent functions after addition of rank.
TODO:need to create more tests for rank in RDS given multiple inserts
of same value.
*/
