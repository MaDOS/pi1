#include "Stack.h"

//constructor
Stack::Stack() //:z(NULL);
{
	tail=NULL; //tail=z
	head=NULL; //head=y
}

void Stack::push(Student& data) //push
{
	ListElem *newElement = new ListElem(data, NULL);

	if(head == NULL) //is empty?
	{
			tail = newElement;
	}
	else
	{
		newElement->setNext(head);
	}
	head = newElement;
}
void Stack::print() //print stack
{
	if (head == NULL) //is empty?
	{
		std::cout << "Der Stack ist leer." << std::endl;
	}
	else
	{
		ListElem*cursor = head; //cursor=head

		while (cursor != NULL)
		{
			std::cout << (cursor->getContent()).name << ", MatNr. " << (cursor->getContent()).matNr << " geb. am " << (cursor->getContent()).date_of_birth << " wohnhaft in " << (cursor->getContent()).adresse << std::endl;
			cursor = cursor->getNext(); //cursor einen weiter schieben
		}
	}
}

bool Stack::pop(Student&data) //pop
{
	if(head==NULL) //is empty?
		return false;
	else
	{
		data =head->getContent();
		head= head->getNext();
		return true;
	}
}

int Stack::b(int a)
{
	while(1)
	{
		if(a)
			return 1;

		tail= head;
		head =NULL;
		return 3;
	}
}





