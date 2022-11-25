#pragma once

#include <iostream>

typedef int datatype;

/* ���������� ����� �������� ������ */
struct Node {
	datatype key = NULL; // ���� �����
	Node* parent = NULL; // �������� �� ����������� �����
	Node* left = NULL; // �������� �� ����� �������
	Node* right = NULL; // �������� �� ������� �������
};

extern Node* pNode; // �������� �� ����� ������

void CreateTree(Node*& pNode, int n);
void ShowTree(Node*& pNode, int L);
void PrefixOrder(Node*& pNode);
void PostfixOrder(Node*& pNode);
void InfixOrder(Node*& pNode);
bool SearchNodeBST(Node* pNode, datatype key);
Node* CreateRootBST(datatype key);
Node* InsertNodeBST(Node*& root, datatype key);
void PredSucNodeBST(Node* pNode, Node*& predecessor, Node*& successor, datatype key);
Node* MinimumNodeBST(Node* pNode);
Node* MaximumNodeBST(Node* pNode);
Node* DeleteNodeBST(Node*& delNode, datatype key);
