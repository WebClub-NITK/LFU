#include "LFU_cache.h"

int main()
{
	LFU cache;

	cache.insert(1);
	cache.insert(2);
	cache.insert(3);
	cache.insert(4);
	cache.insert(5);

	cache.print_lfu();

	cache.access(3);
	cache.access(3);
	cache.access(4);
	cache.access(2);
	cache.access(5);

	cache.print_lfu();

	cout<<"\nEvicted : "<<cache.evict()<<"\n";
	cout<<"Evicted : "<<cache.evict()<<"\n";

	cache.print_lfu();
}