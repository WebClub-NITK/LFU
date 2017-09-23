#include "Class prototype.h"

LFU::LFU()
{
	head = new freqNode;
	head->next = NULL;
	head->prev = NULL;
}

LFU::~LFU()
{
	head->next = NULL;
	delete head;
}

freqNode *LFU::newFreqNode(int frequency, freqNode *next, freqNode *prev)
{
	freqNode *obj = new freqNode;
	obj->freq = frequency;
	obj->next = next;
	obj->head = NULL;
	obj->prev = prev;
	if(next != NULL)
		next->prev = obj;
	prev->next = obj;
	return obj;
}

void LFU::delFreqNode(freqNode *tmp)
{
	tmp->prev->next = tmp->next;
	if(tmp->next !=NULL)
		tmp->next->prev = tmp->prev;
	delete tmp;
}

dataNode *LFU::newDataNode(int data, freqNode *parent)
{
	dataNode *obj = new dataNode;
	obj->data = data;
	obj->next = parent->head;
	if(parent->head !=NULL)
		parent->head->prev = obj;
	obj->parent = parent;
	parent->head = obj;
	obj->prev = NULL;
	return obj;
}

void LFU::delDataNode(dataNode *tmp)
{
	if(tmp->prev !=NULL)
		tmp->prev->next = tmp->next;
	else
		tmp->parent->head = tmp->next;

	if(tmp->next !=NULL)
		tmp->next->prev = tmp->prev;

	if(tmp->parent-> head == NULL)
		delFreqNode(tmp->parent);
	delete tmp;
}

void LFU::access(int data)
{
	if(m.find(data)==m.end())
	{
		insert(data);
		return;
	}

	dataNode *tmp = m[data], *new_tmp;
	int cur_freq = tmp->parent->freq;
	freqNode *next_freq_node = tmp->parent->next;

	if(next_freq_node == NULL || next_freq_node->freq != cur_freq +1)
		next_freq_node = newFreqNode(cur_freq +1, next_freq_node, tmp->parent);

	new_tmp = newDataNode(tmp->data, next_freq_node);
	m[data] = new_tmp;
	delDataNode(tmp);
}

void LFU::insert(int data)
{
	if(m.find(data)!=m.end())
	{
		access(data);
		return;
	}

	freqNode *start_freq_node = head->next;

	if(start_freq_node == NULL || start_freq_node->freq !=1)
		start_freq_node = newFreqNode(1, start_freq_node, head);

	dataNode *tmp = newDataNode(data, start_freq_node);
	m[data] = tmp;
}

int LFU::evict()
{
	if(head->next == NULL)
	{
		cout<<"The set is empty\n";
		return inf;
	}
	
	dataNode *tmp = head->next->head;
	int ret = tmp->data;
	delDataNode(tmp);
	return ret;
}

void LFU::printLfu()
{
	freqNode *f = head->next;
	dataNode *tmp;

	cout<<"\n";
	while(f!=NULL)
	{
		cout<<"Frequency "<<f->freq<<" : ";
		tmp = f->head;
		while(tmp!=NULL)
		{
			cout<<tmp->data<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
		f = f->next;
	}
	cout<<endl;
}