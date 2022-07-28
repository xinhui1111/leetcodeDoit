#include <stdio.h>

#include<stdint.h>

int main_test1() {
	int8_t i = 0;
	int mulity_i = 0;
	printf("%u\n", INT8_MAX);
	printf("--------------------\n");
	for (;;i=i+1-mulity_i*INT8_MAX)
	{
		if (i == INT8_MAX)
			mulity_i++;
		printf("i=%u\n", i);
	}

	
}