/**
 * @file List.cpp
 * content: linked list data structure
 */

#include "List.h"

List::List(): head(NULL), tail(NULL)
{
}

/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_head(const Student& pData)
{
	ListElem* new_element = new ListElem(pData, NULL, NULL);

	if (tail == NULL)                                       // list empty?
	{
		tail = new_element;
	}
	else
	{
		head->setPrev(new_element);
		new_element->setNext(head);
	}

	head = new_element;
}

/**
 * @brief Dequeue an element from the end of the list.
 *
 * This is the single linked version.
 *
 * @param pData The data will be stored here.
 * @return bool
 */
bool List::dequeue(Student& pData)
{
	ListElem* cursor = head;

	if (head == NULL)                                       // list empty?
	{
		return false;
	}
	else if (head == tail)                                  // only one element
	{
		pData = head->getData();
		delete head;
		head = NULL;
		tail = NULL;
	}
	else
	{
		while (cursor->getNext() != tail)
		{
			cursor = cursor->getNext();
		}

		pData = tail->getData();
		tail = cursor;
		delete cursor->getNext();
		tail->setNext(NULL);
	}

	return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards()
{
	ListElem* cursor = head;

	while (cursor != NULL)
	{
		std::cout << (cursor->getData()).name << ", MatNr. " << (cursor->getData()).matNr
				  << " geb. am " << (cursor->getData()).date_of_birth
				  << " wohnhaft in " << (cursor->getData()).adresse << std::endl;
		cursor = cursor->getNext();
	}
}

/**
 * @brief Print content from last to first element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_backwards()
{
	ListElem* cursor = tail;

	while (cursor != NULL)
	{
		std::cout << (cursor->getData()).name << ", MatNr. " << (cursor->getData()).matNr
				  << " geb. am " << (cursor->getData()).date_of_birth
				  << " wohnhaft in " << (cursor->getData()).adresse << std::endl;
		cursor = cursor->getPrev();
	}
}

/**
 * @brief delete an spezific element defined by its mNr
 *
 * @return void
 */
void List::delete_element(int pNr)
{
	ListElem* cursor = head;
	while ((cursor->getData()).matNr != pNr)
	{
		cursor = cursor->getNext();
	}

	//cursor ist nun das zu löschende elemnet

	if (cursor == head)	//head aktualisieren
	{
		head=head->getNext();
		head->setPrev(NULL); //cursor->getNext()->setPrev(cursor->getPrev());
	}
	else if (cursor == tail) //tail aktualisieren
	{
		tail=tail->getPrev();
		tail->setNext(NULL); //cursor->getPrev()->setNext(cursor->getNext());
	}
	else
	{
		cursor->getNext()->setPrev(cursor->getPrev());
		cursor->getPrev()->setNext(cursor->getNext());
	}

	std::cout << (cursor->getData()).name << ", MatNr. " << (cursor->getData()).matNr
				<< "wurde aus der Liste gelöscht"<< std::endl;
	delete cursor;
}

/**
 * @brief Enqueue an element at the end of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_tail(const Student& pData)
{
	ListElem* new_element = new ListElem(pData, NULL, NULL);

	if (tail == NULL)                                       // list empty?
	{
		head = new_element;
	}
	else
	{
		tail->setNext(new_element);
		new_element->setPrev(tail);
	}

	tail = new_element;
}
