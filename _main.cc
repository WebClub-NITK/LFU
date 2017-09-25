#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#include "LFU.cc"

LFU lfu_cache;

void AddValue(int num)
{
	lfu_cache.insert(num);
}

void LookUpValue(int num)
{
	lfu_cache.access(num);
}

void EvictFromCache()
{
	lfu_cache.evict();
}

void PrintLFU()
{
	lfu_cache.printLfu();
}