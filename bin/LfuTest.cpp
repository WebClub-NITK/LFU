//
// Created by mohit on 20/2/17.
//

#include "../header/LfuTest.h"

LfuTest::LfuTest() {

}

LfuTest::~LfuTest() {

}

void LfuTest::setup() {
    this->lfu = new Lfu();
}

void LfuTest::testAdd() {
    AddValue(5);
    AddValue(4);
    AddValue(3);
    AddValue(4);
    PrintLfu();
}

void LfuTest::AddValue(int value) {
    this->lfu->Set(value);
}

void LfuTest::LookUpValue(int value) {
    this->lfu->Retrieve(value);
}

void LfuTest::Evict(int value) {
    this->lfu->Evict(value);
}

void LfuTest::PrintLfu() {
    this->lfu->PrintLfu();
}

CppUnit::TestSuite* LfuTest::suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite;
    suiteOfTests->addTest(new CppUnit::TestCaller<LfuTest>("testAdd", &LfuTest::testAdd));
    return suiteOfTests;
}

/*int main() {
    LfuTest *lfuTest = new LfuTest();
    lfuTest->setup();
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(lfuTest->suite());
    runner.run();
    return 0;
}*/
