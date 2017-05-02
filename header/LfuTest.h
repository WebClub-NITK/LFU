//
// Created by mohit on 20/2/17.
//

#ifndef LFU_LFUTEST_H
#define LFU_LFUTEST_H

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestAssert.h"
#include "cppunit/ui/text/TestRunner.h"

#include "Lfu.h"

class LfuTest : public CppUnit::TestFixture {
private:
    Lfu *lfu;
public:
    LfuTest();
    ~LfuTest();
    void AddValue(int value);
    void LookUpValue(int value);
    void Evict(int value);
    void EvictFromCache();
    void PrintLfu();
    void setUp();
    void tearDown();
    void testAdd();
    CppUnit::TestSuite *suite();
};


#endif //LFU_LFUTEST_H
