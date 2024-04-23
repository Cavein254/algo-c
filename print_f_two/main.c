#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void print(char *initial, ...);

int main(void)
{
	print("ddff", 23,12,2.1,4.2);
	print("fdfd", 1.1,32,2.1,45);

	return 0;
}

void print(char *initial, ...)
{
	int num_args = strlen(initial);
	va_list args;

	va_start(args, initial);

	for(int i = 0; i < num_args; i++){
		if(initial[i] == 'd')
		{
			int x = va_arg(args, int);
			printf("%d\n",x);
		} else if(initial[i] == 'f')
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}
	}
	va_end(args);
}
