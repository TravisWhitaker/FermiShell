//	ChemTerm Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <ptable.h>
#include <portutils.h>

char usersays[100];

int main()
{
	printf("ChemTerm v0.0.1d\n");
	printf("Populating tables...");
	popPtable();
	printf("                    [OK!]\n");
	printf("Size of element: %d bytes\n",sizeof(element));
	printf("Size of database: %d bytes\n",2*sizeof(element));
	usersays[0] = '\0';
	while(usersays[0] != 'q' && usersays[0] != 'Q')
	{
		printf("~#>");
		fgets(usersays,100,stdin);
		if(usersays[0] == 'q' || usersays[0] == 'Q')
		{
			break;
		}
		else
		{
		}
	}
	printf("Exiting...\n");
	return 0;
}
