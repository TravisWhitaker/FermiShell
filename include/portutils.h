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

	if(str1len >= str2len)
	{
		limit = str1len;
	}
	else
	{
		limit = str2len;
	}

	for(int i=0; i<=limit; i++)
	{
		if(str1[i] == str2[i])
		{
			if(str1[i] == '\0' && str2[i] == '\0')
			{
				different = 0;
				break;
			}
			else
			{
				continue;
			}
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
