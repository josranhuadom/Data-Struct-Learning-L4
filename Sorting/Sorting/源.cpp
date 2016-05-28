#include<iostream>
using namespace std;
#define MAXSIZE 30
typedef int KeyType;
typedef char InfoType;

typedef struct
{
	KeyType key;
	InfoType otherinfo = NULL;
}ReadType;

typedef struct
{
	ReadType r[MAXSIZE + 1];
	int length;
}erray;

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

	//��������

	system("pause");
}