//	ChemTerm Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <gmp.h>
#include <ptable.h>
#include <portutils.h>
#include <parser.h>

char usersays[256];
element *output;

int main()
{
	printf("ChemTerm v0.0.1d\n");
	printf("Populating tables...");
	popPtable();
	printf("\t\t\t\t\t[OK!]\n");
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
			output = singularParse(muchBetter(usersays,sizeof(usersays)),sizeof(usersays));

			if(output != 0)
			{
				basicElementData(output);
			}
			else
			{
				printf("No match, try entering an element name or symbol.\n");
			}
		}
	}
	printf("Exiting...\n");
	return 0;
}
