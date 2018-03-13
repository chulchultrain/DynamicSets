#ifndef __RANKEDDYNAMICSETTESTER_H_INCLUDED__
#define __RANKEDDYNAMICSETTESTER_H_INCLUDED__

#include <stdio.h>
#include <assert.h>
#include <DynamicSet/RankedDynamicSet.h>
#include <DynamicSet/DynamicSetTester.h>

class RankedDynamicSetTester : public DynamicSetTester{
    public:
        RankedDynamicSetTester() { printf("RANKEDDYNAMICSETTESTER CONSTRUCTOR\n"); }
        ~RankedDynamicSetTester() { printf("RANKEDDYNAMICSETTESTER DESTRUCTOR\n"); }
        void test(RankedDynamicSet<int> *rds );
        void test_insert(RankedDynamicSet<int> *rds);
        void test_clear(RankedDynamicSet<int> *rds);
        void test_remove(RankedDynamicSet<int> *rds);
        void test_ordering(RankedDynamicSet<int> *rds);
};

#endif
