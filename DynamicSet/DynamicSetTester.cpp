#include <DynamicSet/DynamicSetTester.h>

void DynamicSetTester::test(DynamicSet<int> *ds ) {
    assert(ds->getSize() == 0);
    for(int i = 0; i < 10000; i++) {
        ds->insert(i);
    }
    printf("Size is %lld",ds->getSize());
    assert(ds->getSize() == 10000);
    for(int i = 0; i < 10000; i++) {
        assert(ds->getCount(i) == 1);
    }
    for(int i = -10; i < 10010; i++) {
        ds->remove(i);
    }
    for(int i = -100; i < 10100; i++) {
        assert(ds->getCount(i) == 0);
    }
}
