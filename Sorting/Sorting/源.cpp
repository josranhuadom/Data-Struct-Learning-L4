#include<iostream>
using namespace std;
#define MAXSIZE 30
typedef int KeyType;
typedef char InfoType;

//构建存储单个数据的结构
typedef struct
{
	KeyType key;
	InfoType otherinfo = NULL;
}ReadType;
//构建整个数组
typedef struct
{
	ReadType r[MAXSIZE + 1];
	int length;
}erray;

//插入排序
void InsertSort(erray G)
{
	int j;
	for (int i = 2; i <= G.length; i++)
	{
		if (G.r[i].key < G.r[i - 1].key)
		{
			G.r[0] = G.r[i];
			G.r[i] = G.r[i - 1];
			for (j = i - 2; G.r[0].key < G.r[j].key; --j)
				G.r[j + 1] = G.r[j];
			G.r[j + 1] = G.r[0];
		}
		cout << "第" << i - 1 << "次排序后的结果为：";
		for (int i = 1; i <= G.length; i++)
		{
			cout << G.r[i].key;
			if (i < G.length)
				cout << "<";
		}
		cout << endl;
	}
}

//冒泡排序
void BubbleSort(erray G)
{
	int m = G.length - 1;
	int flag = 1;
	while ((m > 0) && (flag == 1))
	{
		flag = 0;
		for (int j = 1; j <= m; j++)
		{
			if (G.r[j].key > G.r[j + 1].key)
			{
				flag = 1;
				G.r[0] = G.r[j];
				G.r[j] = G.r[j + 1];
				G.r[j + 1] = G.r[0];
			}
		}
		--m;
		if (flag == 1)
		{
			for (int i = 1; i <= G.length; i++)
			{
				cout << G.r[i].key;
				if (i != G.length)
					cout << "<";
			}
			cout << endl;
		}
	}
}

//快速排序
//每一趟排序的具体操作
int Partition(erray &G, int low, int high)
{
	G.r[0] = G.r[low];
	int pivotkey = G.r[low].key;
	while (low < high)
	{
		while ((low < high) && (G.r[high].key >= pivotkey))
			--high;
		G.r[low] = G.r[high];
		while ((low < high) && (G.r[low].key <= pivotkey))
			++low;
		G.r[high] = G.r[low];
	}
	G.r[low] = G.r[0];
	return low;
}
//对排序的递归调用
void QSort(erray &G, int low, int high)
{
	int pivotloc;
	if (low < high) 
	{
		pivotloc = Partition(G, low, high);
		for (int i = 1; i <= G.length; i++)
		{
			cout << G.r[i].key;
			if (i != G.length)
				cout << "<";
		}
		cout << endl;
		QSort(G, low, pivotloc - 1);
		QSort(G, pivotloc + 1, high);
	}
}

void QuickSort(erray G)
{
	QSort(G, 1, G.length);
	for (int i = 1; i <= G.length; i++)
	{
		cout << G.r[i].key;
		if (i != G.length)
			cout << "<";
	}
	cout << endl;
}

int main()
{
	erray G;
	cout << "请输入即将输入的元素个数（大于8个）" << endl;
	cin >> G.length;
	while (G.length <= 8)
	{
		cout << "小于8，请重新输入" << endl;
		cin >> G.length;
	}
	cout << "请输入各元素" << endl;
	for (int i = 1; i <= G.length; i++)
		cin >> G.r[i].key;
	cout << endl;
	//插入排序
	cout << "插入排序:" << "\n";
	InsertSort(G);
	cout << endl;
	//冒泡排序
	cout << "冒泡排序" << "\n";
	BubbleSort(G);
	cout << endl;
	//快速排序
	cout << "快速排序" << "\n";
	QuickSort(G);


	cout << endl;
	system("pause");


}