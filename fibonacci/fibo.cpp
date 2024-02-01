// Author: Brandon Wong
// CECS 325-02 Prog 0
// Due 02/01/2024

#include <iostream>

int fibo(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return fibo(n-1) + fibo(n-2);
}

int main()
{
	for (int i {0}; i <= 20; ++i)
		std::cout << i << ':' << fibo(i) << '\n';
	return 0;
}
