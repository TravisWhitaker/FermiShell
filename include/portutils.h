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

int portstrcmp(const char str1[], const char str2[]) //Compares two strings
{
	int different = 0;
	int limit;
	int str1len = sizeof(str1);
	int str2len = sizeof(str2);

	if(str1len > str2len)
	{
		limit = str1len+1;
	}
	else
	{
		limit = str2len+1;
	}

	for(int i=0; i<=limit; i++)
	{
		if(str1[i] == str2[i])
		{
			continue;
		}
		else
		{
			different = 1;
			break;
		}
	}

	if(different == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
#endif
