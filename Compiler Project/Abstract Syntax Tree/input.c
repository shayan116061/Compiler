#include <stdio.h>

int main()
{
	float j = 20;
	int n; 
    n = j;
	int i;
	int factors = 0;
	for(i = 1; i <= n; i++)
		factors = (n % i == 0) ? factors + 1 : factors;
	int isprime = (factors == 2) ? 1 : 0;
	
}


