//
// Created by mohit on 28/1/17.
//

#include "LFUTest.h"


LFUTest::LFUTest() {

}


void LFUTest::testAdd() {
    int result = this->val1 + this->val2;
    CPPUNIT_ASSERT(result == 3);
}

CppUnit::TestSuite *LFUTest::suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite;
    suiteOfTests->addTest(new CppUnit::TestCaller<LFUTest>("testAdd", &LFUTest::testAdd));
    return suiteOfTests;
}

int main(){
    LFUTest *lfuTest = new LFUTest();
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(lfuTest->suite());
    runner.run();

    return 0;
}
