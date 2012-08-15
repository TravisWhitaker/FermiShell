//	ChemTerm Copyright (C) 2012 Travis Whitaker

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
			if(portstrcmp(usersays,"That is some Gerard shit right there...") == 1)
			{
				printf("LAWL\n");
			}
			else
			{
				printf("Shh, I'm trying to think!\n");
			}
		}
	}
	printf("Exiting...\n");
	return 0;
}
