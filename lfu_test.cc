#include "lfu_test.h"

LFUTest::LFUTest()
{}

LFUTest::~LFUTest()
{}

void LFUTest::Test1()
{
	LFU lfu_cache;

	lfu_cache.insert(5);
	lfu_cache.insert(4);
	lfu_cache.insert(3);
	lfu_cache.insert(4);
	lfu_cache.access(5);

	CPPUNIT_ASSERT(lfu_cache.evict() == 3);
	CPPUNIT_ASSERT(lfu_cache.evict() == 5);
}

void LFUTest::Test2()
{
	LFU lfu_cache;

	lfu_cache.insert(1);
	lfu_cache.insert(1);
	lfu_cache.insert(1);
	lfu_cache.insert(2);
	lfu_cache.insert(2);
	lfu_cache.insert(3);

	CPPUNIT_ASSERT(lfu_cache.evict() == 3);

	lfu_cache.insert(2);

	CPPUNIT_ASSERT(lfu_cache.evict() == 2);
}

CppUnit::TestSuite* LFUTest::Suite()
{
	CppUnit::TestSuite *suite_of_tests = new CppUnit::TestSuite;
	suite_of_tests->addTest(new CppUnit::TestCaller<LFUTest>("test_1", &LFUTest::Test1));
	suite_of_tests->addTest(new CppUnit::TestCaller<LFUTest>("test_2", &LFUTest::Test2));
	return suite_of_tests;
}

int main()
{
    LFUTest *lfu_cache_test = new LFUTest();
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(lfu_cache_test->Suite());
    runner.run();
    return 0;
}