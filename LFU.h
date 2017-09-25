#define inf (-1e9)

using namespace std;

struct dataNode;
struct freqNode
{
	int freq;
	freqNode *next, *prev;
	dataNode *head; 	//Strating of freq_list
};

struct dataNode
{
	int data;
	dataNode *next, *prev;
	freqNode *parent;
};

class LFU
{
private:

	freqNode *head;
	unordered_map<int, dataNode*> m;

	freqNode *newFreqNode(int frequency, freqNode *next, freqNode *prev);
	void delFreqNode(freqNode *tmp);

	dataNode *newDataNode(int data, freqNode *parent);
	void delDataNode(dataNode *tmp);

public:

	LFU();
	~LFU();

	void access(int data);
	void insert(int data);
	int evict();
	void printLfu();

};

