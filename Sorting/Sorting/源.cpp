#include<iostream>
using namespace std;
#define MAXSIZE 30
typedef int KeyType;
typedef char InfoType;

//�����洢�������ݵĽṹ
typedef struct
{
	KeyType key;
	InfoType otherinfo = NULL;
}ReadType;
//������������
typedef struct
{
	ReadType r[MAXSIZE + 1];
	int length;
}erray;

//��������
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
		cout << "��" << i - 1 << "�������Ľ��Ϊ��";
		for (int i = 1; i <= G.length; i++)
		{
			cout << G.r[i].key;
			if (i < G.length)
				cout << "<";
		}
		cout << endl;
	}
}

//ð������
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

//��������
//ÿһ������ľ������
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
//������ĵݹ����
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
	cout << "�����뼴�������Ԫ�ظ���������8����" << endl;
	cin >> G.length;
	while (G.length <= 8)
	{
		cout << "С��8������������" << endl;
		cin >> G.length;
	}
	cout << "�������Ԫ��" << endl;
	for (int i = 1; i <= G.length; i++)
		cin >> G.r[i].key;
	cout << endl;
	//��������
	cout << "��������:" << "\n";
	InsertSort(G);
	cout << endl;
	//ð������
	cout << "ð������" << "\n";
	BubbleSort(G);
	cout << endl;
	//��������
	cout << "��������" << "\n";
	QuickSort(G);


	cout << endl;
	system("pause");


}