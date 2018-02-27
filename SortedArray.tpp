#include <iostream>
template<class T>
SortedArray<T>::SortedArray() {
    array_size = numElements = 0;

}

template<class T>
SortedArray<T>::~SortedArray() {
}

template <class T>
T SortedArray<T>::getMax() {
    if(array_size > 0)
        return elements[array_size-1].val;
    else
        return elements[0].val;
}


template <class T>
T SortedArray<T>::getMin() {
    return elements[0].val;
}


template <class T>
void SortedArray<T>::insert(T x) {
    long long idx = lookUpIndex(x);
    if(idx >= 0) {
        elements[idx].count++;
    } else {
        long long place_put_idx = lookUpPlaceToPut(x);
        for(long long i = array_size; i > place_put_idx; i--) {
            elements[i] = elements[i-1];
        }
        elements[place_put_idx].val = x;
        elements[place_put_idx].count = 1;
        array_size++;
    }
    numElements++;
    //TODO
    PrintState();
}

template <class T>
long long SortedArray<T>::lookUpPlaceToPut(T x) {
    long long res = 0LL;
    for(long long i = 0; i < array_size; i++) {
        if(x < elements[i].val)
            return i;
    }
    return array_size;
}

template <class T>
long long SortedArray<T>::lookUpIndex(T x) {
    //TODO:non-iterative but binary search.
    long long res = -1LL;
    for(long long i = 0; i < array_size; i++) {
        if(x == elements[i].val) {
            res = i;
            break;
        }
    }
    return res;
}


template <class T>
void SortedArray<T>::remove(T x) {
    long long idx = lookUpIndex(x);
    if(idx != -1) {
        elements[idx].count--;
        if(elements[idx].count == 0) {
            for(long long i = idx; i < array_size-1; i++) {
                elements[i] = elements[i+1];
            }
            array_size--;
        }
        numElements--;
    }
    PrintState();
}

template <class T>
T SortedArray<T>::getSuccessor(T x) {
    T res;
    for(long long i = 0; i < array_size; i++) {
        if(elements[i].val > x) {
            res = elements[i].val;
            break;
        }
    }
    return res; //TODO
}


template <class T>
T SortedArray<T>::getPredecessor(T x) {
    T res;
    for(long long i = array_size - 1; i >= 0; i--) {
        if(elements[i].val < x) {
            res = elements[i].val;
            break;
        }
    }
    return res;
}


template <class T>
long long SortedArray<T>::getSize() {
    return numElements;
}

template <class T>
bool SortedArray<T>::search(T x) {
    for(int i = 0; i < array_size; i++) {
        if(elements[i].val == x) {
            return true;
        }
    }
    return false; //TODO
}


template <class T>
long long SortedArray<T>::getCount(T x) {
    for(long long i = 0; i < array_size; i++) {
        if(elements[i].val == x) {
            return elements[i].count;
        }
    }
    return 0LL; //TODO
}

template <class T>
long long SortedArray<T>::getRank(T x) {
    long long res = -1LL;
    for(long long i = 0; i < array_size; i++) {
        if(elements[i].val == x) {
            res = i + 1;
            break;
        }
    }
    return res;
}

template <class T>
std::string SortedArray<T>::objType() {
    std::string result = "SortedArray";
    return result;
}

template <class T>
void SortedArray<T>::PrintState() {
    std::cout << "PRINTSTATE FUNC\n";
    for(long long i = 0; i < array_size; i++) {
        std::cout << elements[i].val << ' ' << elements[i].count << '\n';
    }
    std::cout << '\n';
}
