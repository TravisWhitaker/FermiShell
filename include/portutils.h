//	ChemTerm Copyright (C) 2012 Travis Michael Whitaker
//
//	Here we implement several common functions from files like <string.h> to preserve potential future portability to Z80 and AVR.

char *portstrcpy(char dest[], const char source[])
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
