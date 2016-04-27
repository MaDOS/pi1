#include <iostream>
using namespace std;

int main()
{
	int array[][10] = {{0,1,2,3,4,5,6,7,8,9},{10,11,12,13,14,15,16,17,18,19}};

	int x;
	int y;

	for(x = 0; x < 2; x++)
	{
		for(y = 0; y < 10; y++)
		{
			cout << "array[x=" << x << "][y=" << y << "] Adresse: " << &array[x][y] << " ### " << array[x][y] << endl;
		}
	}

	for(x = 0; x < 20; x++)
	{
		cout << "array[x=" << x << "] Adresse: " << &array[x]  << " ### " << array[x] << endl;
		cout << "*array[x=" << x << "] Adresse: " << &array[x]  << " ### " << *array[x] << endl;
		cout << "array[0][x=" << x << "] Adresse: " << &array[0][x]  << " ### " << array[0][x] << endl;
	}

	return 0;
}
