//	ChemTerm Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <ptable.h>
#include <portutils.h>
#include <parser.h>

char usersays[256];
element *output;

int main(int argc, char *argv[])
{
	int version = 0;
	int precision = 0;
	int complete = 0;
	for(int i=0;i<argc;i++)
	{
		if(portstrcmp(argv[i],"-v",sizeof(argv[i]),3) == 1)
		{
			version = 1;
			break;
		}
		else if(portstrcmp(argv[i],"-c",sizeof(argv[i]),3) == 1)
		{
			complete = 1;
		}
		else if(portstrcmp(argv[i],"-p",sizeof(argv[i]),3) == 1)
		{
			i++;
			precision = atoi(argv[i]);
			printf("Got precision level %d\n",precision);
			return 0;
		}
	}
	if(version == 1)
	{
		printf("ChemTerm Version 0.0.1d\n");
		return 0;
	}
	else
	{
		printf("Populating tables...");
		popPtable();
		printf("\t\t\t\t\t[OK!]\n");
		usersays[0] = '\0';
		while(usersays[0] != 'q' && usersays[0] != 'Q')
		{
			printf("~#>");
			fgets(usersays,356,stdin);
			if(usersays[0] == 'q' || usersays[0] == 'Q')
			{
				break;
			}
			else
			{
				output = singularParse(muchBetter(usersays,sizeof(usersays)),sizeof(usersays));

				if(output != 0)
				{
					if(complete == 1)
					{
						completeElementData(output);
					}
					else
					{
						basicElementData(output);
					}
				}
				else
				{
					printf("No match, try entering an element name or symbol.\n");
				}
			}
		}
		printf("Exiting...");
		return 0;
	}
}
