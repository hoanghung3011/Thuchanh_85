#include <iostream>
#include <queue>
using namespace std;
typedef struct tagNode
{
	int data;
	tagNode* left;
	tagNode* right;
}node;
typedef tagNode* tree;
void CreateTree(tree& t)
{
	t = NULL;
}
int emptyTree(tree t)
{
	if (t == NULL) return 1;
	return 0;
}
node* CreateNode(int x)
{
	node* p = new node;
	if (p == NULL) exit(1);
	else
	{
		p->data = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}
void insertNode(tree& t, int x)
{
	if (t == NULL)
	{
		node* p = new node;
		p->data = x;
		p->left = p->right = NULL;
		t = p;
	}
	else
	{
		if (t->data > x)
		{
			insertNode(t->left, x);
		}
		else if (t->data < x)
		{
			insertNode(t->right, x);
		}
	}
}
void input(tree& t)
{
	int chon;
	CreateTree(t);
	do {
		cout << "\n1.Nhap du lieu cho cay!";
		cout << "\n2.Thoat (nhap 0)";
		cout << "\nNhap lua chon: "; 
		cin >> chon;
		if (chon == 1)
		{
			int x;
			cout << "\nNhap x: "; cin >> x;
			insertNode(t, x);
		}
	} while (chon != 0);
}
void LNR(tree t)
{
	if (t != NULL)
	{
		LNR(t->left);
		cout << t->data << " ";
		LNR(t->right);
	}
}
node* searchX(tree t, int x)
{
	if (t != NULL)
	{
		if (t->data == x)
		{
			if (x > t->data)
				return searchX(t->right, x);
			else return searchX(t->left, x);
		}
	}
	return NULL;
}
int demNode(tree t)
{
	if (t == NULL)
		return 0;
	else return 1 + demNode(t->left) + demNode(t->right);
}
int isLeaf(node* t)
{
	return (t->left == NULL) && (t->right == NULL);
}
int demLeaf(tree t)
{
	if (t == NULL)
		return 0;
	else
	{
		if (isLeaf(t)) return 1;
		else
		{
			return demLeaf(t->left) + demLeaf(t->right);
		}
	}
}
int demNodeLeft(tree t)
{
	if (t == NULL)
		return 0;
	else
	{
		if (t->right == NULL && t->left != NULL)
			return 1 + demNodeLeft(t->left);
		return demNodeLeft(t->left) + demNodeLeft(t->right);
	}
}
int demnutco1con(tree t)
{
	int a, b;
	if (t == NULL) return 0;
	else
	{
		a = demnutco1con(t->left);
		b = demnutco1con(t->right);
		if ((t->left != NULL && t->right == NULL) || (t->left == NULL && t->right != NULL))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int demnutco2con(tree t)
{
	int a, b;
	if (t == NULL) return 0;
	else
	{
		a = demnutco1con(t->left);
		b = demnutco1con(t->right);
		if ((t->left == NULL && t->right == NULL))
			return 1 + a + b;
		return a + b;
	}
	return 0;
}
int tinhchieucao(tree t)
{
	int a, b;
	if (t == NULL)
		return 0;
	else
	{
		a = tinhchieucao(t->left);
		b = tinhchieucao(t->right);
	}
	if (a > b)
	{
		return a + 1;
	}
	else return b + 1;
}
void xuattheotungmuc(tree t)
{
	if (t != nullptr)
	{
		queue<tree> a;
		a.push(t);
		while (!a.empty())
		{
			node* p = a.front();
			cout << p->data << " ";
			a.pop();
			if (p->left != nullptr)
			{
				a.push(p->left);
			}
			if (p->right != nullptr)
			{
				a.push(p->right);
			}
		}
	}
}
int main()
{
	tree t;
	CreateTree(t);
	input(t);
	LNR(t);
	int x;
	cout << "\nNhap x can tim: ";
	cin >> x;
	node* p = searchX(t, x);
	if (p == NULL)
		cout << "\nKhong tim thay";
	else cout << "\nTim thay";
	cout << "\nCo " << demNode(t) << " nut trong cay";
	cout << "\nCo " << demLeaf(t) << " la trong cay";
	cout << "\nCo " << demNodeLeft(t) << " nut chi co cay con trai";
	cout << "\nCo " << demnutco1con(t) << " chi co 1 con";
	cout << "\nCo " << demnutco2con(t) << " co ca 2 con";
	cout << "\nChieu cao cua cay la: " << tinhchieucao(t);
	cout << "\n-----------------------------------------\n";
	xuattheotungmuc(t);
}