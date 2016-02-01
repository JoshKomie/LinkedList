#include <iostream>
using namespace std;

//Josh Komie
//linked list practice

struct node
{
	int data;
	struct node *next;
};

int InitNode(node **n, int data)
{
	(*n) = new node;
	if (*n == nullptr)
		return 0;
	(*n)->data = data;
	(*n)->next = nullptr;
	return 1;
}

int InsertEnd(node **root, int data)
{
	node *newNode, *current;
	if (!InitNode(&newNode, data))
		return 0;
	if ((*root) == nullptr)
	{
		(*root) = newNode;
	}
	else
	{
		current = (*root);
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	return 1;
}

int InsertBeginning(node **root, int data)
{
	node *newNode;
	if (!InitNode(&newNode, data))
		return 0;
	if (*root != nullptr)
	{
		newNode->next = (*root);
	}
	(*root) = newNode;
	return 1;
}

int InsertMid(node **root, int data, int position)
{
	node *newNode, *temp;
	if (!InitNode(&newNode, data))
		return 0;
	if ((*root) == nullptr && position == 0)
		*root = newNode;
	else if (*root == nullptr && position != 0)
	{
		cout << "root is null but pos not 0" << endl;
		return 0;
	}
	else if (position == 0)
	{
		newNode->next = (*root);
		(*root) = newNode;
	}
	else
	{
		temp = (*root);
		for (int i = 0; i < position - 1; i++)
		{
			if (temp->next == nullptr)
			{
				cout << "position larger than length of linked list" << endl;
				return 0;
			}
			temp = temp->next;
			
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return 1;
}

int InsertOrdered(node **root, int data)
{
	node *newNode, *current, *prev;
	if (!InitNode(&newNode, data))
		return 0;
	if (*root == nullptr)
		*root = newNode;
	else
	{
		current = *root;
		while (current->next != nullptr && current->data <= data)
		{
			prev = current;
			current = current->next;
		}
		newNode->next = current;
		prev->next = newNode;
	}
	return 1;
}
int DeleteIndex(node **root, int index)
{
	if (*root == nullptr)
		return 0;
	node *current = *root;
	if (index == 0)
	{
		(*root) = (*root)->next;
		delete current;
		return 1;
	}
	else
	{
		int i = 0;
		while (current->next != nullptr)
		{
			i++;
			if (i == index)
			{
				node *temp = current->next;
				//if end of list
				if (current->next->next == nullptr)
				{
					current->next = nullptr;
					delete temp;
					return 1;
				}
				current->next = current->next->next;
				delete temp;
				return 1;
			}
			current = current->next;
		}
	}
	return 0;
}

int DeleteValue(node **root, int value)
{
	node *current = *root;
	if (current->data == value)
	{
		(*root) = (*root)->next;
		delete current;
		return 1;
	}
	else
	{
		while (current->next != nullptr)
		{
			if (current->next->data == value)
			{
				node *temp = current->next;
				if (current->next->next == nullptr)
				{
					current->next = nullptr;
					delete temp;
					return 1;
				}
				current->next = current->next->next;
				delete temp;
				return 1;
			}
			current = current->next;
		}
	}
	return 0;
}
	
void Print(node **root)
{
	cout << "Linked List = {";
	node *c = (*root);
	if (c != nullptr)
	{
		while (c->next != nullptr)
		{
			cout << c->data << ", ";
			c = c->next;
		}
		cout << c->data;
	}
	cout << "}" << endl;
}
		
		
int main()
{
	node *root = nullptr;
	InsertBeginning(&root, 1);
	Print(&root);
	InsertEnd(&root, 5);
	Print(&root);
	InsertMid(&root, 2, 1);
	Print(&root);
	InsertOrdered(&root, 3);
	Print(&root);
	DeleteValue(&root, 1);
	Print(&root);
}