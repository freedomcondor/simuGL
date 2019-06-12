/*
 *    Zhu Weixu
 *        zhuweixu_harry@126.com
 *    
 *    Version 1.0 : everything basic
 */

#ifndef LIST
#define LIST

/*
 *   data structure:
 *
 *                             focal 
 *                               |
 *                               V
 *     Head ,      first,   second,  ...   ,  last ,   Tail
 *      |                                                |
 *      V                                                V
 *   empty node <--> xx  <--> xx  <--> xx            empty node
 *
 *   To traverse:
 *   	for (x.firstFocal(); !x.focalAtTail(); x.nextFocal())
 */

template <class T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node *next, *prev;
	}*head, *tail, *focal;

	Node* createNode()
	{
		Node *p;
		p = new Node();
		return p;
	}
	int deleteNode(Node *p)
	{
		delete p;
		return 0;
	}

public:
	List();
	~List();
	int length;
	T& getFocal();
	T& operator[](int x);
	int nextFocal();
	int prevFocal();
	int firstFocal();
	int lastFocal();
	int focalAtHead();
	int focalAtTail();

	int insert(const T& x);
	int delFocal();
	int pushHead(const T& x);
	int pushTail(const T& x);
	T popHead();
	T popTail();
};

#include "List.cpp"
#endif
