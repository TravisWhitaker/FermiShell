//	ChemTerm Copyright (C) 2012 Travis Michael Whitaker

#include <stdio.h>
#include <ptable.h>
#include <portutils.h>

int main()
{
	printf("Populating tables...");
	popPtable();
	printf("               [OK!]\n");
	printf("%s     ",Elements[0]->atomSymbol);
	printf("%s\n",Elements[0]->atomName);
	printf("%s     ",Elements[1]->atomSymbol);
	printf("%s\n",Elements[1]->atomName);
	return 0;
}
