//  ChemTerm Copyright (C) 2012 Travis Whitaker
#ifndef PARSER
#define PARSER

#include <gmp.h>
#include <portutils.h>
#include <stdlib.h>

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

void basicElementData(element *input)
{
	printf("Name:\t\t\t%s\n",input->atomName);
	printf("Symbol:\t\t\t%s\n",input->atomSymbol);
	printf("Atomic Number:\t\t%d\n",input->atomNumber);
	gmp_printf("Atomic Mass:\t\t%.Ff\n",input->atomMass);
	printf("Phase:\t\t\t");
	if(input->phase == -1)
	{
		printf("Unknown/Ambiguous");
	}
	else if(input->phase == 0)
	{
		printf("Gaseous");
	}
	else if(input->phase == 1)
	{
		printf("Liquid");
	}
	else if(input->phase == 2)
	{
		printf("Solid");
	}
	printf("\n");
	gmp_printf("Density:\t\t%.Ff g/cm^3\n",input->density);
	gmp_printf("Menting Point:\t\t%.Ff°C\n",input->fusionP);
	gmp_printf("Boiling Point:\t\t%.Ff°C\n",input->vaporP);
	printf("Metallic Character:\t");
	if(input->metalloid == -1)
	{
		printf("Ambiguous/Unknown");
	}
	else if(input->metalloid == 0)
	{
		printf("Metallic");
	}
	else if(input->metalloid == 1)
	{
		printf("Metalloid");
	}
	else if(input->metalloid == 2)
	{
		printf("Non-metallic");
	}
	printf("\n");
	printf("Color:\t\t\t%s\n",input->color);
	printf("Valence:\t\t%d\n",input->valence);
	gmp_printf("Electronegativity:\t%.Ff\n",input->electroneg);
	gmp_printf("Ionization Energies:\t%.Ff eV\n",input->ionE1);
	gmp_printf("Atomic Radius:\t\t%.Ff pm\n",input->atomRadius);
}


#endif
