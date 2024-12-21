#ifndef _STACK_H
#define _STACK_H

#define NMAX 100

#define TYPE char

#define FTYPE "%3c,"

typedef struct  Stack {

	int   top;

	TYPE  data[NMAX];

} stack;

int isempty(stack* s);// ���������, ���� ���� ���� {top==0} ������� 1, ����� 0

int isfull(stack* s);// ���������, ���� ���� ����� {top==NMAX-1} ������� 1, ����� 0

int push(stack* s, TYPE a);//��������� ������� � � ����  {top=top+1, data[top]=a}, ���� ���� �� �����

TYPE pop(stack* s);// ������� ������� {data[top]}, ������ ��� �� ����� {top=top-1}, ���� ���� �� ����

TYPE top(stack* s);//������� �������� �������� � ������� ����� {return data[top]}

#endif /* _STACK_H */