#include <stdio.h>
#include <stdarg.h>

int max(int num_args, ...);

int main(void)
{
	int max_num = max(5,99,100,-2000,200,2);
	printf("min_num : %d\n", max_num);

	return 0;
}

int max(int num_args, ...)
{
	va_list args;
	va_start(args, num_args);

	int min;

	for (int i = 0; i < num_args; i++)
	{
		int x = va_arg(args,int);
		if (i == 0) min = x;
		else if ( x < min) min = x;
	}

	va_end(args);

	return min;
}
