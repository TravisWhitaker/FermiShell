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

char *niceMPF(mpf_t input, char output[])
{
	int j = 0;
	char mantissa[102];
	mp_exp_t magnitude;
	mp_exp_t apparentMagnitude;
	mp_exp_t *exponent;
	exponent = &magnitude;

	mpf_get_str(mantissa,exponent,10,100,input);

	apparentMagnitude = magnitude;

	if(mantissa[0] == '-')
	{
		apparentMagnitude++;
	}

	if(magnitude == 0)
	{
		portstrcpy(output,"NEG NOT IMPLEMENTED");
		return output;
	}
	else if(magnitude > 0)
	{
		for(int i=j;i<118;i++)
		{
			if(i == apparentMagnitude)
			{
				output[i] = '.';
				if(mantissa[(j+1)] == '\0')
				{
					output[(i+1)] = '0';
					output[(i+2)] = '\0';
					return output;
				}
				else
				{
					continue;
				}
			}
			else if(mantissa[j] == '\0')
			{
				output[i] = '\0';
				return output;
			}
			else
			{
				output[i] = mantissa[j];
				j++;
			}
		}
	}
	else
	{
		portstrcpy(output,"MP_EXP_T ERROR");
		return output;
	}
	portstrcpy(output,"UNKNOWN ERROR");
	return output;
}

void basicElementData(element *input)
{
	char *mpfOut;
	mpfOut = malloc(sizeof(mpfOut)*118);

	printf("Name:\t\t%s\n",input->atomName);
	printf("Symbol:\t\t%s\n",input->atomSymbol);
	printf("Atomic Number:\t%d\n",input->atomNumber);
	printf("Atomic Mass:\t%s\n",niceMPF(input->atomMass,mpfOut));
	printf("Melting Point:\t%s°C\n",niceMPF(input->fusionP,mpfOut));
	printf("Boiling Point:\t%s°C\n",niceMPF(input->vaporP,mpfOut));
	printf("Density:\t%s g/cm^3\n",niceMPF(input->density,mpfOut));

	free(mpfOut);
}


#endif
