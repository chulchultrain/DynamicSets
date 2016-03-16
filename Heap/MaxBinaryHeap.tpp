		


#ifndef MAX_HEAP_SIZE
#define MAX_HEAP_SIZE 200
#endif

template <class T>
MaxBinaryHeap<T>::MaxBinaryHeap() { 
	size = 0;
	printf("MAXBINARYHEAP CONSTRUCTOR\n");
}

template <class T>
MaxBinaryHeap<T>::~MaxBinaryHeap() {
	printf("MAXBINARYHEAP DESTRUCTOR\n");
}


template <class T>
void MaxBinaryHeap<T>::Heapify(long long pos) {
	long long left = leftChild(pos), right = rightChild(pos);
	long long largest = pos;
	if(left < size && elements[left] > elements[pos]) {
		largest = left;
	}
	if(right < size && elements[right] > elements[largest]) {
		largest = right;
	}
	if(largest != pos) {
		swap(pos,largest);
		Heapify(largest);
	}
		
}

template <class T>
T MaxBinaryHeap<T>::extractMax() {
	T max;
	if(size > 0) {
		max = elements[0];
		size--;
		swap(0,size);
		Heapify(0);
	}
	return max;
}

template <class T>
T MaxBinaryHeap<T>::getMax() {
//	if(size > 0) TODO: How to handle this error
		return elements[0];
}

template <class T>
T MaxBinaryHeap<T>::getMin() {
	T min;

	printf("FUNCTION ERROR. MAXBINARYHEAP::GETMIN UNDEF\n");
	return min;
}

template <class T>
void MaxBinaryHeap<T>::swap(long long index1, long long index2) {
	T temp = elements[index1];
	elements[index1] = elements[index2];
	elements[index2] = temp;	
}

template <class T>
void MaxBinaryHeap<T>::insert(T x) {
	if(size < MAX_HEAP_SIZE) {
		elements[size] = x;
		size++;
		long long pos = size - 1;
		long long p = parent(pos);
		while(elements[p] < elements[pos]) {
			swap(p,pos);
			pos = p;
			p = parent(pos);
		}
	}
}

/*
	Linear search for x.
	swap x with last element in heap. 
	if x > parent, traverse and swap until not larger than parent
	if x < either child, heapify
*/
template <class T>
void MaxBinaryHeap<T>::remove(T x) {
	int i;
	for(i = 0; i < size; i++)
		if(elements[i] == x)
			break;
	if(i < size) {
		swap(i,size - 1);
		size--;
	}
	if( elements[i] > elements[parent(i)]) {
		while(elements[i] > elements[parent(i)] ) {
			swap(i,parent(i));
			i = parent(i); }
	}
	else
		Heapify(i);
		
}

template <class T>
T MaxBinaryHeap<T>::getSuccessor(T x) {
	T successor;
	printf("FUNCTION ERROR. MAXBINARYHEAP::GETSUCCESSOR UNDEF\n");
	return successor;
}

template <class T>
T MaxBinaryHeap<T>::getPredecessor(T x) {
	T predecessor;
	printf("FUNCTION ERROR. MAXBINARYHEAP::GETPREDECESSOR UNDEF\n");
	return predecessor;
}

template <class T>
long long MaxBinaryHeap<T>::getSize() {
	return size;
}

template <class T>
bool MaxBinaryHeap<T>::search(T x) {
	printf("FUNCTION ERROR. MAXBINARYHEAP::SEARCH UNDEF\n");
	return false;
}

template <class T>
std::string MaxBinaryHeap<T>::objType() {
	std::string result = "MaxBinaryHeap";
	return result;
}		

template <class T>
long long MaxBinaryHeap<T>::leftChild(long long nodeIndex) {
	return nodeIndex * 2 + 1;
}

template <class T>
long long MaxBinaryHeap<T>::rightChild(long long nodeIndex) {
	return nodeIndex * 2 + 2;
}

template <class T>
long long MaxBinaryHeap<T>::parent(long long nodeIndex) {
	return (nodeIndex - 1) / 2;
}






