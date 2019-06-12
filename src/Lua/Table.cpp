#include "Table.h"

#include "stdlib.h"

ConstBase::ConstBase()
{
	numberList = (struct numberNode*)malloc(sizeof(struct numberNode));
	numberList->next = NULL;
	stringList = (struct stringNode*)malloc(sizeof(struct stringNode));
	stringList->next = NULL;
}

ConstBase::~ConstBase()
{
	struct numberNode *pn, *qn;
	pn = numberList; while (pn != NULL) {qn = pn; pn = pn->next; free(qn);}
	struct stringNode *ps, *qs;
	ps = stringList; while (ps != NULL) {qs = ps; ps = ps->next; free(qs);}
}

int* index(double x)
{
	struct numberNode *p, *q;
	for (p = numberList->next; p != NULL; p = p->next)
		if (p->value == x)
			return p;
	if (p == NULL)

}

int* index(const char x[])
{
}

