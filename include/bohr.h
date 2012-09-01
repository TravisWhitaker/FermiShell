//  FermiShell Copyright (C) 2012 Travis Whitaker
#ifndef BOHR
#define BOHR

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <portutils.h>

void fancyBshells(element *input)
{
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
	
	printf("%s",input->atomSymbol);
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


#endif
