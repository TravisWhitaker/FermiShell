//  ChemTerm Copyright (C) 2012 Travis Whitaker
#ifndef PARSER
#define PARSER

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

char *atomNameCapFix(char input[], const int inputSize)
{
	char init = input[0];
	if(beanCounter(input,inputSize) <= 3)
	{
		return input;
	}
	else if(init == 'a')
	{
		input[0] = 'A';
	}
	else if(init == 'b')
	{
		input[0] = 'B';
	}
	else if(init == 'c')
	{
		input[0] = 'C';
	}
	else if(init == 'd')
	{
		input[0] = 'D';
	}
	else if(init == 'e')
	{
		input[0] = 'E';
	}
	else if(init == 'f')
	{
		input[0] = 'F';
	}
	else if(init == 'g')
	{
		input[0] = 'G';
	}
	else if(init == 'h')
	{
		input[0] = 'H';
	}
	else if(init == 'i')
	{
		input[0] = 'I';
	}
	else if(init == 'j')
	{
		input[0] = 'J';
	}
	else if(init == 'k')
	{
		input[0] = 'K';
	}
	else if(init == 'l')
	{
		input[0] = 'L';
	}
	else if(init == 'm')
	{
		input[0] = 'M';
	}
	else if(init =='n')
	{
		input[0] ='N';
	}
	else if(init == 'o')
	{
		input[0] = 'O';
	}
	else if(init == 'p')
	{
		input[0] = 'P';
	}
	else if(init == 'q')
	{
		input[0] = 'Q';
	}
	else if(init == 'r')
	{
		input[0] = 'R';
	}
	else if(init == 's')
	{
		input[0] = 'S';
	}
	else if(init == 't')
	{
		input[0] = 'T';
	}
	else if(init == 'u')
	{
		input[0] = 'U';
	}
	else if(init == 'v')
	{
		input[0] = 'V';
	}
	else if(init == 'w')
	{
		input[0] = 'W';
	}
	else if(init == 'x')
	{
		input[0] = 'X';
	}
	else if(init == 'y')
	{
		input[0] = 'Y';
	}
	else if(init =='z')
	{
		input[0] = 'Z';
	}
	else
	{
		return input;
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
