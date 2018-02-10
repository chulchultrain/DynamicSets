#include <DynamicSet/DynamicSetTester.h>
#include <vector>
void DynamicSetTester::test(DynamicSet<int> *ds ) {
    test_insert(ds);
    test_remove(ds);
}

void DynamicSetTester::test_insert(DynamicSet<int> *ds) {
    std::vector<int> insert_cases;
    insert_cases.push_back(-100);
    insert_cases.push_back(123);
    insert_cases.push_back(0);
    int icsz = insert_cases.size();
    for(int i = 0; i < icsz; i++) {
        assert(ds->search(insert_cases[i]) == false);
    }

    for(int i = 0; i < icsz; i++) {
        ds->insert(insert_cases[i]);
    }
    for(int i = 0; i < icsz; i++) {
        assert(ds->search(insert_cases[i]) );
   }
   for(int i = 0; i < icsz; i++) {
       assert(ds->getCount(insert_cases[i]) == 1);
   }

   for(int i = 0; i < icsz; i++) {
       if(i != 0) {
           ds->insert(insert_cases[i]);
       }
   }
   for(int i = 0; i < icsz; i++) {
       if(i == 0) {
           assert(ds->getCount(insert_cases[i]) == 1);
       } else {
           assert(ds->getCount(insert_cases[i]) == 2);
       }
   }

   //clear function
   for(int j = 0; j < 2; j++) {
       for(int i = 0; i < icsz; i++) {
           ds->remove(insert_cases[i]);
       }
   }

}


void DynamicSetTester::test_remove(DynamicSet<int> *ds) {
    std::vector<int> insert_cases;
    insert_cases.push_back(-100);
    insert_cases.push_back(123);
    insert_cases.push_back(0);
    int icsz = insert_cases.size();
    for(int i = 0; i < icsz; i++) {
        assert(ds->search(insert_cases[i]) == false);
        assert(ds->getCount(insert_cases[i]) == 0);
    }

    for(int i = 0; i < icsz; i++) {
        ds->remove(insert_cases[i]);
    }

    for(int i = 0; i < icsz; i++) {
        assert(ds->search(insert_cases[i]) == false);
        assert(ds->getCount(insert_cases[i]) == 0);
    }

    for(int i = 0; i < icsz; i++) {
        ds->insert(insert_cases[i]);
        ds->insert(insert_cases[i]);
    }

    for(int i = 0; i < icsz; i++) {
        ds->remove(insert_cases[i]);
    }

    for(int i = 0; i < icsz; i++) {
        assert(ds->search(insert_cases[i]) == true);
        assert(ds->getCount(insert_cases[i]) == 1);
    }

    for(int i = 0; i < icsz; i++) {
        ds->remove(insert_cases[i]);
    }

    for(int i = 0; i < icsz; i++) {
        assert(ds->search(insert_cases[i]) == false);
        assert(ds->getCount(insert_cases[i]) == 0);
    }

    for(int i = 0; i < icsz; i++) {
        ds->remove(insert_cases[i]);
    }

    for(int i = 0; i < icsz; i++) {
        assert(ds->search(insert_cases[i]) == false);
        assert(ds->getCount(insert_cases[i]) == 0);
    }
}
