//	ChemTerm Copyright (C) 2012 Travis Michael Whitaker

#include <stdio.h>
#include <ptable.h>
#include <portutils.h>

char usersays[100];

int main()
{
	printf("Populating tables...");
	popPtable();
	printf("               [OK!]\n");
	usersays[0] = '\0';
	while(usersays[0] != 'q')
	{
		printf("~#>");
		fgets(usersays,100,stdin);
		if(usersays[0] == 'q')
		{
			printf("Exiting...\n");
			break;
		}
		else
		{
			printf("YAY!\n");
		}
	}
	return 0;
}


