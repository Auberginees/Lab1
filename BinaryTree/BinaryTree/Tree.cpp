#include <iostream>
#include "Tree.h"

/* �������, �� ������� ������ ������*/
void CreateTree(Node*& pNode, int n) {
	if (pNode == NULL) // ���� ������ ������, �� ��������� �������
		return;
	else
	{
		pNode = new Node; // ����� ����� ������
		datatype data;
		std::cin >> data; // ���������� ������
		pNode->key = data;
		pNode->left = pNode->right = NULL;
		int left = n / 2 - 1; // ��������� ����� ��������
		int right = n - left - 1; // ��������� ������� ��������
		CreateTree(pNode->left, left);
		CreateTree(pNode->right, right);
	}
};

/* �������, �� ������� �� ����������� ������ */
void ShowTree(Node*& pNode, int L) {
	if (pNode == NULL)
		return;
	ShowTree(pNode->left, L + 1); // ��������� ����� ��������
	for (int i = 0; i < L; i++)
	{
		std::cout << "    ";
	}
	std::cout << pNode->key << std::endl;
	ShowTree(pNode->right, L + 1); // ��������� ������� ��������
};

/* �������, �� ������� ����� ������ � ������� �������*/
void PrefixOrder(Node*& pNode)
{
	if (pNode == NULL)
		return; // ���������� �� �� ������ ������
	std::cout << pNode->key <<" "; // ���������� ���� � ����
	PrefixOrder(pNode->left); // ����� ����� ��������
	PrefixOrder(pNode->right); // ����� ������� ��������
};

/* �������, �� ������� ����� ������ � ����������� �������*/
void PostfixOrder(Node*& pNode)
{
	if (pNode == NULL)
		return; // ���������� �� �� ������ ������
	PostfixOrder(pNode->left); // ����� ����� ��������
	PostfixOrder(pNode->right); // ����� ������� ��������
	std::cout << pNode->key << " "; // ���������� ���� � ����
};

/* �������, �� ������� ����� ������ � ����������� �������*/
void InfixOrder(Node*& pNode)
{
	if (pNode == NULL)
		return;
	InfixOrder(pNode->left); // ����� ����� ��������
	std::cout << pNode->key << " "; // ���������� ���� � ����
	InfixOrder(pNode->right); // ����� ������� ��������
};

/* �������, �� ������� ����� ����� �� ������*/
bool SearchNodeBST(Node* pNode, datatype key)
{
	if (pNode == NULL)
		return false;
	else if (pNode->key == key) // ���� ��������� ����� ������� � ������ ������
		return true;
	else if (key < pNode->key) // ���� ��������� ����� ������ �� ���� ������
		return SearchNodeBST(pNode->left, key);
	else // ���� ��������� ����� ������ �� ���� ������
		return SearchNodeBST(pNode->right, key);
};

/* �������, �� ������� ����� � �������� �����*/
Node* CreateRootBST(datatype key)
{
	Node* pNode = new Node; // ������ �������� ���'���
	pNode->key = key; // �������� ����
	pNode->parent = pNode->left = pNode->right = NULL;
	return pNode;
};

/* �������, �� �������� ����� ����� � �������� �����*/
Node* InsertNodeBST(Node*& root, datatype key)
{
	if (root == NULL)
	{
		root = CreateRootBST(key);
		return root;
	}
	else
		if (key <= root->key)
			root->left = InsertNodeBST(root->left, key);
		else
			root->right = InsertNodeBST(root->right, key);
	return root;
};

/* �������, �� ��������� ��������� �����*/
void PredSucNodeBST(Node* pNode, Node*& predecessor, Node*& successor, datatype key)
{
	if (pNode == NULL)
	{
		return;
	}
	if (pNode->key == key) // ���� ����� ���� � �������
	{
		if (pNode->left != NULL) {
			Node* temp = pNode->left;
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			predecessor = temp;
		}
		if (pNode->right != NULL)
		{
			Node* temp = pNode->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			successor = temp;
		}
		return;
	}
	if (pNode->key > key) // ���� ����� ���� � ������ �� �����
	{
		successor = pNode;
		PredSucNodeBST(pNode->left, predecessor, successor, key);
	}
	else // ���� ���� � ������ �� �����
	{
		predecessor = pNode;
		PredSucNodeBST(pNode->right, predecessor, successor, key);
	}
};

/* �������, �� ��������� ��������� �����*/
Node* MinimumNodeBST(Node* pNode)
{
	if (pNode == NULL) return NULL;
	while (pNode->left)
	{
		pNode = pNode->left;
	}
	return pNode;
};

/* �����, �� ��������� ������������ �����*/
Node* MaximumNodeBST(Node* pNode)
{
	while (pNode->right)
		pNode = pNode->right;
	return pNode;
};

/* �����, �� ������� ����� � �������� ������*/
Node* DeleteNodeBST(Node*& delNode, datatype key)
{
	if (delNode == NULL) //����������, �� � ������ �������
		return delNode;
	/*���������, ����� ������� �� ����� - ����� �� �������*/
	if (delNode->key > key)
		delNode->left = DeleteNodeBST(delNode->left, key);
	else
		if (delNode->key < key)
			delNode->right = DeleteNodeBST(delNode->right, key);
		else
		{
			if (delNode->left == NULL && delNode->right == NULL)
			{
				delete delNode;
				delNode = NULL;
				return delNode;
			}
			else
				if (delNode->left == NULL)
				{
					Node* temp = delNode;
					delNode = delNode->right;
					delete temp;
					return delNode;
				}
				else
					if (delNode->right == NULL)
					{
						Node* temp = delNode;
						delNode = delNode->left;
						delete temp;
						return delNode;
					}
			Node* temp = MinimumNodeBST(delNode->right);
			delNode->key = temp->key; // ��������� ���� �����
			delNode->right = DeleteNodeBST(delNode->right, temp->key); // ���������� ��������� �����
		}
	return delNode;
};

