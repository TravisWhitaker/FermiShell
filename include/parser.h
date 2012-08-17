//  ChemTerm Copyright (C) 2012 Travis Whitaker
#ifndef PARSER
#define PARSER

#include <gmp.h>

int beanCounter(const char input[], const int inputSize)
{
	int beans = 0;
	for(int i=0; i<inputSize; i++)
	{
		if(input[i] == '\0')
		{
			return beans;
		}
		else
		{
			beans++;
		}
	}
	return -1;
}

char *muchBetter(char input[], const int inputSize)
{
	char lowerCase[27] = "abcdefghijklmnopqrstuvwxyz";
	char upperCase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char init = input[0];
	if(beanCounter(input,inputSize) <= 3)
	{
		return input;
	}
	else
	{
		for(int i=0; i<26; i++)
		{
			if(init == lowerCase[i])
			{
				input[0] = upperCase[i];
				return input;
			}
			else
			{
				continue;
			}
		}
	}
	return input;
}

element *singularParse(char input[], const int inputSize)
{
	for(int i=0;i<inputSize;i++)
	{
		if(input[i] == '\n')
		{
			input[i] = '\0';
			break;
		}
		else
		{
			continue;
		}
	}
	element *scanner;

	for(int i=0;i<119;i++)
	{
		scanner = Elements[i];
		if(scanner == 0)
		{
			break;
		}
		else if(portstrcmp(input,Elements[i]->atomName,sizeof(input),sizeof(Elements[i]->atomName)) == 1)
		{
			return Elements[i];
		}
		else if(portstrcmp(input,Elements[i]->atomSymbol,sizeof(input),sizeof(Elements[i]->atomSymbol)) == 1)
		{
			return Elements[i];
		}
		else
		{
			continue;
		}
	}
	return 0;
}
#endif
