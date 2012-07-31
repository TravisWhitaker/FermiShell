//	ChemTerm Copyright (C) 2012 Travis Michael Whitaker

#include <stdio.h>
#include <ptable.h>
#include <portutils.h>

int main()
{
	printf("Populating tables...\n");
	popPtable();
	printf("%s\n",hydrogen.atomName);
	return 0;
}
