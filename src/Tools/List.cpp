/*
 *    Zhu Weixu
 *        zhuweixu_harry@126.com
 *    
 *    Version 1.0 : everything basic
 */

#include "stdlib.h"
#include "stdio.h"

template <class T>
List<T>::List()
{
	head = createNode();
	tail = createNode();
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	focal = tail;

	length = 0;
}

template <class T>
List<T>::~List()
{
	Node *p, *q;  
	p = head;
	while (p != NULL)
	{
		q = p->next;
		deleteNode(p);
		p = q;
	}
}

template <class T>
T& List<T>::getFocal()
{
	return focal->data;
}

template <class T>
T& List<T>::operator[](int x)
{
	firstFocal();
	for (int i = 0; i < x; i++)
		nextFocal();
	if (focalAtTail())
		lastFocal();
	return getFocal();
}

template <class T>
int List<T>::nextFocal()
{
	if (focal != tail)
	{
		focal = focal->next;
		return 0;
	}
	else
		return -1;
}

template <class T>
int List<T>::prevFocal()
{
	if (focal != head)
	{
		focal = focal->prev;
		return 0;
	}
	else
		return -1;
}

template <class T>
int List<T>::firstFocal()
{
	focal = head->next;
	return 0;
}

template <class T>
int List<T>::lastFocal()
{
	focal = tail->prev;
	return 0;
}

template <class T>
int List<T>::focalAtHead()
{
	return (focal == head);
}

template <class T>
int List<T>::focalAtTail()
{
	return (focal == tail);
}

template <class T>
int List<T>::insert(const T& x)
{
	Node *p;  

	if (focal == tail)
		focal = tail->prev;

	p = createNode();
	p->data = x;

	p->next = focal->next;
	p->prev = focal;

	focal->next->prev = p;
	focal->next = p;

	focal = p;

	length++;
	return 0;
}

template <class T>
int List<T>::delFocal()
{
	if (length == 0)
		return -1;

	Node* p = focal;
	focal->prev->next = focal->next;
	focal->next->prev = focal->prev;
	focal = focal->next;

	deleteNode(p);

	length--;
	if ((focal == tail) && (length != 0)) focal = tail->prev;

	return 0;
}

template <class T>
int List<T>::pushTail(const T& x)
{
	Node *temp;

	temp = focal;
	focal = tail;
	insert(x);
	if (length != 1)
		focal = temp;
	return 0;
}

template <class T>
int List<T>::pushHead(const T& x)
{
	Node *temp;

	temp = focal;
	focal = head;
	insert(x);
	if (length != 1)
		focal = temp;
	return 0;
}

template <class T>
T List<T>::popHead()
{
	Node *temp;
	T data;

	if (length == 0) return getFocal();

	temp = focal;
	focal = head->next;
	if (temp == focal) temp = focal->next;

	data = getFocal();
	delFocal();

	focal = temp;

	return data;
}

template <class T>
T List<T>::popTail()
{
	Node *temp;
	T data;

	if (length == 0) return getFocal();

	temp = focal;
	focal = tail->prev;
	if (temp == focal) temp = focal->prev;

	data = getFocal();
	delFocal();

	focal = temp;

	return data;
}
