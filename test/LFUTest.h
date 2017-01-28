//
// Created by mohit on 28/1/17.
//

#ifndef LFU_TEST_H
#define LFU_TEST_H

#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestAssert.h"
#include "cppunit/ui/text/TestRunner.h"

class LFUTest : public CppUnit::TestFixture{
protected:
    int val1; int val2;

public:
    LFUTest();
    void setUp(){
        val1 = 1;
        val2 = 2;
    }
    void tearDown(){

    }
    void testAdd();
    CppUnit::TestSuite *suite();
};


#endif //LFU_TEST_H
