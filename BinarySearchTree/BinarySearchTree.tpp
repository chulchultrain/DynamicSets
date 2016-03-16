template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
	size = 0;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	DeleteSubTree(root);
}

template <class T>
void BinarySearchTree<T>::DeleteSubTree(Node<T> *subRoot) {
	if(subRoot) {
		DeleteSubTree(subRoot->left);
		DeleteSubTree(subRoot->right);
		delete subRoot;
	}
}

template <class T>
Node<T> *BinarySearchTree<T>::getSubTreeMax(Node<T> *root) {
	Node<T> *nodePtr = root;
	if(nodePtr)
		while(nodePtr->right) {
			nodePtr = nodePtr->right;
		}
	return nodePtr;
}

template <class T>
Node<T> *BinarySearchTree<T>::getSubTreeMin(Node<T> *root) {
	Node<T> *nodePtr = root;
	if(nodePtr)
		while(nodePtr->left) {
			nodePtr = nodePtr->left;
		}
	return nodePtr;	
}

template <class T>
Node<T> *BinarySearchTree<T>::getSuccessor(Node<T> *n) {
	Node<T> *nodePtr = n, *parentPtr = n->parent;
	if(nodePtr->right)
		return getSubTreeMin(nodePtr->right);
	else {
		while(parentPtr != NULL && nodePtr != parentPtr->left) {
			nodePtr = parentPtr;
			parentPtr = parentPtr->parent;
		}	
		return parentPtr;
	}
		
}

template <class T>
Node<T> *BinarySearchTree<T>::getPredecessor(Node<T> *n) {
	Node<T> *nodePtr = n, *parentPtr = n->parent;
	if(nodePtr->left)
		return getSubTreeMax(nodePtr->left);
	else {
		while(parentPtr != NULL && nodePtr != parentPtr->right) {
			nodePtr = parentPtr;
			parentPtr = parentPtr->parent;
		}	
		return parentPtr;
	}
	
}

template <class T>
T BinarySearchTree<T>::getMax() {
	T maxVal;
	Node<T> *maxPtr = getSubTreeMax(root);
	if(maxPtr)
		maxVal = maxPtr->val;
	return maxVal;
}

template <class T>
T BinarySearchTree<T>::getMin() {
	T minVal;
	Node<T> *minPtr = getSubTreeMin(root);
	if(minPtr)
		minVal = minPtr->val;
	return minVal;
}


template <class T>
void BinarySearchTree<T>::insert(T x) {
	if(!root) {
		root = new Node<T>;
		root->val = x;
		return;
	}

	Node<T> *nodePtr = root, *prevPtr = NULL;
	while(nodePtr != NULL) {
		prevPtr = nodePtr;
		if(x < nodePtr->val)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	nodePtr = new Node<T>;
	nodePtr->parent = prevPtr;
	nodePtr->val = x;
	if(x < prevPtr->val)
		prevPtr->left = nodePtr;
	else
		prevPtr->right = nodePtr;

	size++;
}

template <class T>
int BinarySearchTree<T>::numChildren(Node<T> *n) {
	if(n) {
		int count = 0;
		if(n->left)
			count++;
		if(n->right)
			count++;
		return count;
	}
	return 0;
}

template <class T>
void BinarySearchTree<T>::swapVal(Node<T> *n1, Node<T> *n2) {
	T temp = n1->val;
	n1->val = n2->val;
	n2->val = temp;
}

template <class T>
void BinarySearchTree<T>::remove(T x) {
	if(root) {
		Node<T> *nodePtr = root, *splice = 0, *spliceP = 0, *spliceC = 0;
		while(nodePtr && nodePtr->val != x) {
			if(x < nodePtr->val)
				nodePtr = nodePtr->left;
			else
				nodePtr = nodePtr->right;
		}
		if(nodePtr != NULL) {
			size--;
			if( numChildren(nodePtr) < 2)
				splice = nodePtr;
			else {
				splice = getSuccessor(nodePtr);
				swapVal(splice,nodePtr);
			}

			spliceP = splice->parent;
			if(splice->left)
				spliceC = splice->left;
			else
				spliceC = splice->right;	
	
			if(splice == root) {
				root = spliceC;
				if(root)
					root->parent = NULL;
			}
			else {
				if(splice == spliceP->left) 
					spliceP->left = spliceC;
				else
					spliceP->right = spliceC;
				if(spliceC)
					spliceC->parent = spliceP;
			}			
			delete splice;
		}
	}
	
}


template <class T>
T BinarySearchTree<T>::getSuccessor(T x) {
	T successor;
	printf("FUNCTION ERROR. BINARYSEARCHTREE::GETSUCCESSOR UNDEF\n");
	return successor;
}

template <class T>
T BinarySearchTree<T>::getPredecessor(T x) {
	T predecessor;
	printf("FUNCTION ERROR. BINARYSEARCHTREE::GETPREDECESSOR UNDEF\n");
	return predecessor;
}


template <class T>
long long BinarySearchTree<T>::getSize() {
	return size;
}

template <class T>
bool BinarySearchTree<T>::search(T x) {
	Node<T> *nodePtr = root;
	while(nodePtr && nodePtr->val != x) {
		if(x < nodePtr->val)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	if(nodePtr)
		return true;
	else
		return false;
}

template <class T>
std::string BinarySearchTree<T>::objType() {
	std::string result = "BinarySearchTree";
	preOrderTraversal(root);
	return result;
}


template <class T>
void BinarySearchTree<T>::preOrderTraversal(Node<T> *n) {
	if(n) {
		printf("%d\n", (int)(n->val));
		preOrderTraversal(n->left);
		preOrderTraversal(n->right);

	}

}























