#include <DynamicSet/RankedDynamicSetTester.h>
#include <vector>
#include <iostream>
#include <algorithm>

void RankedDynamicSetTester::test(RankedDynamicSet<int> *rds ) {
    test_insert(rds);
    test_ordering(rds);
}

void RankedDynamicSetTester::test_insert(RankedDynamicSet<int> *rds ) {


}

void RankedDynamicSetTester::test_ordering(RankedDynamicSet<int> *rds ) {
    std::vector<int> insert_cases;
    insert_cases.push_back(-100);
    insert_cases.push_back(123);
    insert_cases.push_back(0);
    insert_cases.push_back(-20);
    insert_cases.push_back(-400);
    insert_cases.push_back(33);
    std::vector<int> sorted_cases = insert_cases;
    sort(sorted_cases.begin(),sorted_cases.end());

    long long counter = 0;
    int icsz = insert_cases.size();

    for(int i = 0; i < icsz; i++) {
        assert(rds->search(insert_cases[i]) == false);
    }

    for(int i = 0; i < icsz; i++) {
        rds->insert(insert_cases[i]);
        counter++;
        assert(rds->getSize() == counter);
    }

    for(int i = 0; i < icsz; i++) {
        assert(rds->getRank(sorted_cases[i]) == i + 1);
    }

    for(int i = 0; i < icsz - 1; i++) {
        assert(rds->getSuccessor(sorted_cases[i]) == sorted_cases[i+1]);
    }

    for(int i = 1; i < icsz; i++) {
        assert(rds->getPredecessor(sorted_cases[i]) == sorted_cases[i-1]);
    }
    for(int i = 0; i < icsz; i++) {
        if(i != 0 && i != icsz - 1) {
            rds->insert(insert_cases[i]);
            counter++;
            assert(rds->getSize() == counter);
        }
    }
    for(int i = 0; i < icsz; i++) {
        assert(rds->getRank(sorted_cases[i]) == i + 1);
    }

    for(int i = 0; i < icsz - 1; i++) {
        assert(rds->getSuccessor(sorted_cases[i]) == sorted_cases[i+1]);
    }

    for(int i = 1; i < icsz; i++) {
        assert(rds->getPredecessor(sorted_cases[i]) == sorted_cases[i-1]);
    }
}
