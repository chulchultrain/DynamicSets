#ifndef __DYNAMICSETTESTER_H_INCLUDED__
#define __DYNAMICSETTESTER_H_INCLUDED__

#include <stdio.h>
#include <assert.h>
#include <DynamicSet/DynamicSet.h>
#include <vector>

class DynamicSetTester {
    public:
        DynamicSetTester() { printf("DYNAMICSETTESTER CONSTRUCTOR\n");
            insert_cases.push_back(-100);
            insert_cases.push_back(123);
            insert_cases.push_back(0); }
        ~DynamicSetTester() { printf("DYNAMICSETTESTER DESTRUCTOR\n"); }
        void test(DynamicSet<int> *ds );
        void test_clear(DynamicSet<int> *ds);
        void test_insert(DynamicSet<int> *ds);

        void test_remove(DynamicSet<int> *ds);
    private:
        std::vector<int> insert_cases;
};


#endif
