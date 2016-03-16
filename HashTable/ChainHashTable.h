#ifndef __CHAINHASHTABLE_H_INCLUDED__
#define __CHAINHASHTABLE_H_INCLUDED__

#include <HashTable/HashTable.h>

#ifndef MAX_HASH_VAL
#define MAX_HASH_VAL 523
#endif



template <class T>
class ChainHashTable : public HashTable<T> {
	public:
		ChainHashTable();
		virtual ~ChainHashTable();
		virtual T getMax();
		virtual T getMin();
		virtual void insert(T x);
		virtual void remove(T x);
		virtual T getSuccessor(T x);
		virtual T getPredecessor(T x);
		virtual long long hashFunction(T x);
		virtual long long getSize();
		virtual bool search(T x);
		virtual std::string objType();	
	private:
		struct TNode {
			T val;
			TNode *next;
		};

		void DeleteList(TNode *head);

		TNode *table[MAX_HASH_VAL];
		long long maxSize;
		long long size;

};




#include <HashTable/ChainHashTable.tpp>





#endif
