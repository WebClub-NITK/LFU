#include "cppunit/TestFixture.h"
#include "cppunit/TestSuite.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestCaller.h"
#include "cppunit/TestAssert.h"
#include "cppunit/ui/text/TestRunner.h"

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#include "lfu.cc"

class LFUTest : public CppUnit::TestFixture
{ 
 public:

    LFUTest();
    ~LFUTest();

	void Test1();
	void Test2();
    CppUnit::TestSuite *Suite();
};
