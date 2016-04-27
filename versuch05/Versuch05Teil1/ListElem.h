#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

class ListElem
{
    private:
	    Student content; //z=content
        ListElem *nextElem; //y=next

    public:
	    ListElem::ListElem(Student const &pData, ListElem *const pNext);

	    void setContent(Student &pData); //setContent
	    void setNext(ListElem *pNext); //setNext
	    Student getContent(); //getContent
	    ListElem *getNext(); //getNext
};

#endif
