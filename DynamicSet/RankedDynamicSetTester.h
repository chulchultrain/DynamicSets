#ifndef __RANKEDDYNAMICSETTESTER_H_INCLUDED__
#define __RANKEDDYNAMICSETTESTER_H_INCLUDED__

#include <stdio.h>
#include <assert.h>
#include <DynamicSet/RankedDynamicSet.h>


class RankedDynamicSetTester {
    public:
        RankedDynamicSetTester() { printf("RANKEDDYNAMICSETTESTER CONSTRUCTOR\n"); }
        ~RankedDynamicSetTester() { printf("RANKEDDYNAMICSETTESTER DESTRUCTOR\n"); }
        void test(RankedDynamicSet<int> *rds );
        void test_insert(RankedDynamicSet<int> *ds);
        void test_ordering(RankedDynamicSet<int> *ds);
};

#endif
