#ifndef __DYNAMICSET_H_INCLUDED__
#define __DYNAMICSET_H_INCLUDED__


class DynamicSet{
	public:
		virtual int getMax() const = 0;
		virtual int getMin() const = 0;
		virtual void insert() const = 0;
		virtual void remove(int x) const = 0;
		virtual int getSuccessor(int x) const = 0;
		virtual int getPredecessor(int x) const = 0;
	private:

};























#endif




