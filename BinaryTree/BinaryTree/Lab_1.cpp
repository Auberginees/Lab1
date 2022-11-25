#include <iostream>
#include "Tree.h"

using namespace std;

Node* pNode = NULL;

int main()
{
	setlocale(LC_CTYPE, "ukr");
	cout << "Ваш розмiр дерева:" << endl;
	int n;
	cin >> n;
	cout << "Напишiть значення:" << endl;
	int key;
	int i = 0;
	while (i < n)
	{
		cin >> key;
		if (SearchNodeBST(pNode, key))
		{
			cout << "Вузол iз такими даними вже iснує. Будь ласка, введiть iнше значення. " << endl;
		}
		else
		{
			InsertNodeBST(pNode, key);
			i++;
		}
	}
	cout << "Дерево: " << endl;
	ShowTree(pNode, 0);
	int y = 0;
	while (1)
	{
		cout << " - 1 Додати значення" << endl;
		cout << " - 2 Видалити значення" << endl;
		cout << " - 3 Алгоритм обходу у внутрiшньому порядку" << endl;
		cout << " - 4 Алгоритм обходу у зворотному порядку" << endl;
		cout << " - 5 Алгоритм обходу у прямому порядку" << endl;
		cout << " - 6 Пошук" << endl;
		cout << " - 7 Пошук предка або нащадка" << endl;
		cout << " - 8 Вихiд" << endl;
		cout << "Впишiть число: " << endl;
		cin >> y;
	
		if (y == 1)
		{
			cout << "Елемент для вставки: ";
			cin >> key;
			cout << endl;
			InsertNodeBST(pNode, key);
			cout << "Дерево: " << endl;
			ShowTree(pNode, 0);
			
		}
		if (y == 2)
		{
			cout << "Елемент для видалення: ";
			cin >> key;
			cout << endl;
			if (!SearchNodeBST(pNode, key))
				cout << "Вузол не найдено" << endl;
			else
			{
				DeleteNodeBST(pNode, key);
				cout << "Дерево: " << endl;
				ShowTree(pNode, 0);
			}
			
		}
		if (y == 3)
		{
			cout << endl << "Внутрiшнiй порядок:\n" << endl;
			InfixOrder(pNode);
			cout << endl;
			
		}
		if (y == 4)
		{
			cout << endl << "Зворотнiй порядок:\n" << endl;
			PostfixOrder(pNode);
			cout << endl;
			
		}
		if (y == 5)
		{
			cout << endl << "Прямий порядок:\n" << endl;
			PrefixOrder(pNode);
			cout << endl;
			
		}
		if (y == 6)
		{
			cout << "Пошук:" << endl;
			cin >> key;
			if (!SearchNodeBST(pNode, key))
				cout << "Вузол не найдено" << endl;
			else
				cout << "Елемент найдено" << endl;
			
		}
		if (y == 7)
		{
			Node* predecessor = NULL, * successor = NULL;
			cout << "Уведiть число: ";
			cin >> key;
			cout << endl;
			PredSucNodeBST(pNode, predecessor, successor, key);
			if (predecessor != NULL)
			{
				cout << "Предок " << key << " є " << predecessor->key << endl;
			}
			else
			{
				cout << "Предка немає";
			}
			if (successor != NULL)
			{
				cout << "Нащадок " << key << " є " << successor->key << endl;
			}
			else
			{
				cout << "Нащадка немає";
			}
			cout << endl;
		
		}
		if (y == 8)
			break;
		}

	return 0;
};
