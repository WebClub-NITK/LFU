#include <bits/stdc++.h>
#include <unordered_map>
#define inf (-1e9)

using namespace std;

struct data_node;
struct freq_node
{
	int freq;
	freq_node *next, *prev;
	data_node *head; 	//Strating of freq_list
};

struct data_node
{
	int data;
	data_node *next, *prev;
	freq_node *parent;
};

class LFU
{
	freq_node *head;
	unordered_map<int, data_node*> m;
public:
	LFU()
	{
		head = new freq_node;
		head->next = NULL;
		head->prev = NULL;
	}
	~LFU()
	{
		head->next = NULL;
		delete head;
	}

	freq_node *new_freq_node(int frequency, freq_node *next, freq_node *prev);
	void del_freq_node(freq_node *tmp);

	data_node *new_data_node(int data, freq_node *parent);
	void del_data_node(data_node *tmp);

	void access(int data);
	void insert(int data);
	int get_lfu_item();
	int evict();

};

freq_node *LFU::new_freq_node(int frequency, freq_node *next, freq_node *prev)
{
	freq_node *obj = new freq_node;
	obj->freq = frequency;
	obj->next = next;
	obj->head = NULL;
	obj->prev = prev;
	if(next != NULL)
		next->prev = obj;
	prev->next = obj;
	return obj;
}

void LFU::del_freq_node(freq_node *tmp)
{
	tmp->prev->next = tmp->next;
	if(tmp->next !=NULL)
		tmp->next->prev = tmp->prev;
	delete tmp;
}

data_node *LFU::new_data_node(int data, freq_node *parent)
{
	data_node *obj = new data_node;
	obj->data = data;
	obj->next = parent->head;
	parent->head->prev = obj;
	obj->parent = parent;
	parent->head = obj;
	obj->prev = NULL;
	return obj;
}

void LFU::del_data_node(data_node *tmp)
{
	if(tmp->next !=NULL)
		tmp->prev->next = tmp->next;
	else
		tmp->parent->head = tmp->next;

	if(tmp->next !=NULL)
		tmp->next->prev = tmp->prev;

	if(tmp->parent-> head == NULL)
		del_freq_node(tmp->parent);
	delete tmp;
}

void LFU::access(int data)
{
	if(m.find(data)==m.end())
	{
		cout<<"No such key\n";
		return;
	}

	data_node *tmp = m[data], *new_tmp;
	int cur_freq = tmp->parent->freq;
	freq_node *next_freq_node = tmp->parent->next;

	if(next_freq_node == NULL || next_freq_node->freq != cur_freq +1)
		next_freq_node = new_freq_node(cur_freq +1, next_freq_node, tmp->parent->prev);

	new_tmp = new_data_node(tmp->data, next_freq_node);
	m[tmp->data] = new_tmp;
	del_data_node(tmp);
}

void LFU::insert(int data)
{
	if(m.find(data)!=m.end())
	{
		cout<<"Key already exists\n";
		return;
	}

	freq_node *start_freq_node = head->next;

	if(start_freq_node == NULL || start_freq_node->freq !=1)
		start_freq_node = new_freq_node(1, start_freq_node, head);

	data_node *tmp = new_data_node(data, start_freq_node);
	m[data] = tmp;
}

int LFU::get_lfu_item()
{
	if(head->next == NULL)
	{
		cout<<"The set is empty\n";
		return inf;
	}
	return head->next->head->data;
}

int LFU::evict()
{
	int data = get_lfu_item();
}

int main()
{

}