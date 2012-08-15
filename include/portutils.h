//	ChemTerm Copyright (C) 2012 Travis Whitaker
//
//	Here we implement several common functions from files like <string.h> to preserve potential future portability to Z80 and AVR.

#ifndef PORTSTRCPY
#define PORTSTRCPY
char *portstrcpy(char dest[], const char source[]) //Copies one null-terminated string onto another.
{
	int i = 0;
	while(source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

int portstrcmp(const char str1[], const char str2[], int str1len, int str2len) //Compares two strings
{
	int different = 0;
	int limit;

	printf("\n");
	printf("According to portstrcpy:\n");
	printf("size of str1: %d\n",str1len);
	printf("size of str2: %d\n",str2len);

	if(str1len >= str2len)
	{
		limit = str1len;
	}
	else
	{
		limit = str2len;
	}

	printf("Size of limit: %d\n",limit);
	printf("\n");

	for(int i=0; i<=limit; i++)
	{
		printf("i is currently %d",i);
		printf(", str1[i] is %c",str1[i]);
		printf(", str2[i] is %c\n",str2[i]);
		if(str1[i] == str2[i])
		{
			printf("I see that str1[i] == str2[i]...\n");
			if(str1[i] == '\0' && str2[i] == '\0')
			{
				printf("Found null terminator in str1 and str2, setting different = 0 and breaking...\n");
				different = 0;
				break;
			}
			else
			{
				printf("No null terminator, continuing...\n");
				continue;
			}
		}
		else
		{
			printf("str1[i] and str2[i] are different, setting different = 1 and breaking...\n");
			different = 1;
			break;
		}
	}

	if(different == 0)
	{
		printf("They were the same, returning 1.\n");
		return 1;
	}
	else
	{
		printf("They were different, returning 0.\n");
		return 0;
	}
}
#endif
