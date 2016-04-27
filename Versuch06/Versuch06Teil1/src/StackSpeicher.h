/*
 * Praktikum Informatik 1
 * Versuch 6.1: Templates und Überladen von Operatoren
 *
 * Datei:  StackSpeicher.h
 * Inhalt: generischer Stackspeicher
 */

#ifndef STACKSPEICHER_H_
#define STACKSPEICHER_H_

// StackClass
template<int size, class T>
class StackSpeicher
{
  public:
	StackSpeicher();
	void push (const T& e);
	void pop (T& e);
	void quick_sort(int l, int r);
	int partition(int l, int r);
	void exchange(int i, int j);
	// Inser your Implementation here

  private:
	T space[size];
	int index;
};

/**
 * @brief Constructor
 */
template <int size, class T>
StackSpeicher <size, T> :: StackSpeicher():index(-1)
{
}

/**
 * @brief Function to push an Element
 * @param e Element to save
 */
template <int size, class T>
void StackSpeicher <size, T>::push(const T& e)
{
	if (index < (size-1))
	{
		index += 1;
		space[index] = e;
	}
}

/**
 * @brief Function to retriev an Element from the Stack
 * @param e Position to save the Element
 */
template<int size, class T>
void StackSpeicher<size, T>::pop(T& e)
{
	if (index >= 0)
	{
		e = space[index];
		index -= 1;
	}
}

// Insert your Implementation here

template<int size, class T>
void StackSpeicher<size, T>::quick_sort(int l, int r)
{
	int k;
	if (r <= l)
		return;
	k = partition(l, r);
	quick_sort (l, k - 1);
	quick_sort (k + 1 , r);
}

template<int size, class T>
int StackSpeicher<size, T>::partition(int l, int r)
{
	int i, j, k;
	T v;
	k = r;			//gewählter index des pivotelement
	v = space[k];	//das pivotelements
	i = l;			//laufindes mit start links
	j = r - 1;		//laufindex mit start links neben pivot
	while (1)
	{
		while (space[i] <= v && i < r)
			i++;

		while (space[j] >= v && j >= l)
			j--;

		if (i >= j)
			break;

		else
			exchange(i, j); //einsortieren abh. vom pivot
	}
	exchange(i, k); //pivot an pivot stelle tauschen
	return i; 		//pivot zurück geben
}

template<int size, class T>
void StackSpeicher<size, T>::exchange(int i, int j)
{
	T pHolder;

	pHolder=space[i];
	space[i]=space[j];
	space[j]=pHolder;
}


#endif /*STACKSPEICHER_H_*/
