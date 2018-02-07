#ifndef __DYNAMICSETTESTER_H_INCLUDED__
#define __DYNAMICSETTESTER_H_INCLUDED__

#include <stdio.h>
#include <assert.h>
#include <DynamicSet/DynamicSet.h>

class DynamicSetTester {
    public:
        DynamicSetTester() { printf("DYNAMICSETTESTER CONSTRUCTOR\n"); }
        ~DynamicSetTester() { printf("DYNAMICSETTESTER DESTRUCTOR\n"); }
        void test(DynamicSet<int> *ds );
};


#endif
