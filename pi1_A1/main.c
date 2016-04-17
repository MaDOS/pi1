int fak(int n);
int fibo(int n);
int fiboIT(int n);

int main()
{

	return 0;
}

int fak(int n)
{
	return (n == 1) ? 1 : n*fak(n-1);
}

int fibo(int n)
{
	return (n<=2) ? (n+1)>>1 : fibo(n-2) + fibo(n-1);
}

int fiboIT(int n)
{
	int solution = (n<=2) ? (n+1)>>1 : 0;
	int nm1 = 1;
	int nm2 = 1;

	int i;

	for(i = 3; i <= n; i++)
	{
		solution = nm1 + nm2;
		nm2 = nm1;
		nm1 = solution;
	}

	return solution;
}
