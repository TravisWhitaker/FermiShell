//  FermiShell Copyright (C) 2012 Travis Whitaker
#ifndef BOHR
#define BOHR

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <portutils.h>

int precision;

void fancyBshells(element *input)
{
	mpf_t mantissa; mpf_init_set_str(mantissa,"0.5",10);
	mpf_t mutMass; mpf_init(mutMass);
	mpf_t neutrons; mpf_init(neutrons);
	for(int i=0;i<7;i++)
	{
		if(input->bohrShells[i] == 0)
		{
			break;
		}
		else
		{
			printf("(");
		}
	}
	
	printf("%d",input->atomNumber);
	printf("/");
	mpf_floor(mutMass,input->atomMass);
	mpf_add(mutMass,mutMass,mantissa);
	if(mpf_cmp(input->atomMass,mutMass) >= 0)
	{
		mpf_ceil(mutMass,input->atomMass);
	}
	else
	{
		mpf_floor(mutMass,input->atomMass);
	}
	if(mpf_cmp_si(mutMass,-1) == 0)
	{
		printf("?");
	}
	else
	{
		gmp_printf("%.*Ff",precision,mutMass);
	}
	printf(")");

	for(int i=0;i<8;i++)
	{
		if(input->bohrShells[i] == 0)
		{
			return;
		}
		else
		{
			printf("%d",input->bohrShells[i]);
			printf(")");
		}
	}
}

void fancyLewisStructure(element *input)
{
	int complete;
	int electrons = input->vEshell;
	int quadrant[4] = {0,0,0,0};
	
	while(electrons != 0)
	{
		for(int i=0;i<4;i++)
		{
			if(electrons != 0)
			{
				quadrant[i] = quadrant[i] + 1;
				electrons--;
			}
			else
			{
				break;
			}
		}
		for(int i=0;i<4;i++)
		{
			if(electrons != 0)
			{
				quadrant[i] = quadrant[i] + 1;
				electrons--;
			}
			else
			{
				break;
			}
		}
	}

	printf(" ");
	if(quadrant[0] == 0)
	{
		asm("nop");
	}
	else if(quadrant[0] == 1)
	{
		printf(".");
	}
	else if(quadrant[0] == 2)
	{
		printf("..");
	}
	printf("\n\t\t\t\t");
	if(quadrant[1] == 0)
	{
		printf(" ");
	}
	else if(quadrant[1] == 1)
	{
		printf(".");
	}
	else if(quadrant[1] == 2)
	{
		printf(":");
	}
	printf("%s",input->atomSymbol);
	if(quadrant[2] == 0)
	{
		printf(" ");
	}
	else if(quadrant[2] == 1)
	{
		printf(".");
	}
	else if(quadrant[2] == 2)
	{
		printf(":");
	}
	printf("\n\t\t\t\t");
	printf(" ");
	if(quadrant[3] == 0)
	{
		asm("nop");
	}
	else if(quadrant[3] == 1)
	{
		printf("'");
	}
	else if(quadrant[3] == 2)
	{
		printf("''");
	}
	return;
}
#endif
