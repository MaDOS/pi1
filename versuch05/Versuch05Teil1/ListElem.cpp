#include "ListElem.h"

//constructor
ListElem::ListElem(Student const &pData, ListElem *const pNext)
{
	content=pData;//z=content
	nextElem=pNext;//y=next
}

void ListElem::setContent(Student &pData) //setContent a
{
	content = pData; //z=content
}

void ListElem::setNext(ListElem *const pNext)//setNext b
{
	nextElem = pNext; //y=next
}



Student ListElem::getContent() //getContent c
{
	return content;//z=content
}

ListElem *ListElem::getNext() //getNext d
{
	return nextElem;//y=next
}
