//	ChemTerm Copyright (C) 2012 Travis Michael Whitaker

#include <stdio.h>
#include <ptable.h>
#include <portutils.h>

int main()
{
	printf("Populating tables...");
	popPtable();
	printf("               [OK!]\n");
	printf("%s     ",hydrogen.atomSymbol);
	printf("%s\n",hydrogen.atomName);
	printf("%s     ",helium.atomSymbol);
	printf("%s\n",helium.atomName);
	return 0;
}
