template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = NULL;
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
void BinarySearchTree<T>::FixUpTree(Node<T> *n) {
	if(n) {
		Node<T> *nodePtr = n;
		while(nodePtr != NULL) {
			UpdateNode(nodePtr);
			BalanceTree(nodePtr);
			nodePtr = nodePtr->parent;
		}	
	}
}

template <class T>
void BinarySearchTree<T>::LeftRotate(Node<T> *n) {
	if(n && n->right) {
		bool resetRoot = false;
		if(n == root) {
			resetRoot = true;
		}
		Node<T> *a = n, *b = n->right, *parent = a->parent;
		Node<T> *alpha = a->left, *beta = b->left, *gamma = b->right;
		a->right = beta;
		b->left = a;
		a->parent = b;
		b->parent = parent;
		if(beta)
			beta->parent = a;
		if(parent) {
			if(b->val < parent->val)
				parent->left = b;
			else
				parent->right = b;
		}

		UpdateNode(a);
		UpdateNode(b);		
		if(resetRoot)
			root = b;
	}
}

template <class T>
void BinarySearchTree<T>::RightRotate(Node<T> *n) {
	if(n && n->left) {
		bool resetRoot = false;
		if(n == root) {
			resetRoot = true;
		}
		Node<T> *a = n, *b = n->left, *parent = a->parent;
		Node<T> *alpha = b->left, *beta = b->right, *gamma = a->right;
		a->left = beta;
		b->right = a;
		a->parent = b;
		b->parent = parent;
		if(beta)
			beta->parent = a;
		UpdateNode(a);
		UpdateNode(b);
		if(resetRoot)
			root = b;
	}
}


template <class T>
void BinarySearchTree<T>::BalanceTree(Node<T> *n) {
	long long balance = 0,leftBalance = -1, rightBalance = -1;
	Node<T> *nodePtr = n;
	balance = nodeBalance(nodePtr);
	if(balance > 1 || balance < -1) {
		if(balance > 1) {
			leftBalance = nodeBalance(nodePtr->left);
			if(leftBalance <= -1)
				LeftRotate(nodePtr->left);
			RightRotate(nodePtr);
		}
		else if(balance < -1) {
			rightBalance = nodeBalance(nodePtr->right);
			if(rightBalance >= 1)
				RightRotate(nodePtr->right);
			LeftRotate(nodePtr);
		}
	}
}


template <class T>
long long BinarySearchTree<T>::nodeBalance(Node<T> *n) {
	long long balance = 0, leftHeight = -1, rightHeight = -1;
	if(n) {
		if(n->left)
			leftHeight = n->left->height;
		if(n->right)
			rightHeight = n->right->height;
		balance = leftHeight - rightHeight;
	}
	return balance;
}


template <class T>
void BinarySearchTree<T>::insert(T x) {
	if(!root) {
		root = new Node<T>(x);
		return;
	}


	Node<T> *nodePtr = root, *prevPtr = NULL;
	while(nodePtr != NULL && nodePtr->val != x) {
		prevPtr = nodePtr;
		if(x < nodePtr->val)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	if(nodePtr) {
		nodePtr->count++;
		FixUpTree(nodePtr);
		return;
	}

	nodePtr = new Node<T>(x);
	nodePtr->parent = prevPtr;
	if(x < prevPtr->val)
		prevPtr->left = nodePtr;
	else
		prevPtr->right = nodePtr;

	FixUpTree(nodePtr);	
	preOrderTraversal(root);
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
	long long tempCount = n1->count;
	n1->count = n2->count;
	n2->count = tempCount;
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
			if(nodePtr->count > 1) {
				nodePtr->count--;
				FixUpTree(nodePtr);
				return;
			}

			if( numChildren(nodePtr) < 2)
				splice = nodePtr;
			else {
				splice = getSuccessor(nodePtr);
				swapVal(splice,nodePtr);
				//FixUpTree(splice);
				//FixUpTree(nodePtr);
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
			splice->count--;	//sets to zero to properly fixup tree
			FixUpTree(splice);
			delete splice;
			preOrderTraversal(root);
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
	return root->size;
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
	printf("\n");
	return result;
}


template <class T>
void BinarySearchTree<T>::preOrderTraversal(Node<T> *n) {
	if(n) {
		printf("%d %lld %lld %lld\n", (int)(n->val), n->count, n->height, n->size);
		preOrderTraversal(n->left);
		preOrderTraversal(n->right);

	}

}



template<class T>
void BinarySearchTree<T>::UpdateNode(Node<T> *n) {
	if(n) {
		long long leftSize = 0, rightSize = 0;
		long long leftHeight = -1, rightHeight = -1;
		if(n->left) {
			leftSize = n->left->size;
			leftHeight = n->left->height;
		}
		if(n->right) {
			rightSize = n->right->size;
			rightHeight = n->right->height;
		}
		n->size = leftSize + rightSize + n->count;
		n->height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}
}

template<class T>
Node<T> *BinarySearchTree<T>::searchForNode(T x) {
	Node<T> *nodePtr = root;
	while(nodePtr && nodePtr->val != x) {
		if(x < nodePtr->val)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return nodePtr;
}


template<class T>
long long BinarySearchTree<T>::getCount(T x) {
	Node<T> *nodePtr = root;
	while(nodePtr && nodePtr->val != x) {
		if(x < nodePtr->val)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	if(nodePtr)
		return nodePtr->count;
	else
		return 0;
}













