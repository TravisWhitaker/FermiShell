//	FermiShell Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <ptable.h>
#include <portutils.h>
#include <parser.h>
#include <tableIO.h>

char Version[] = "FermiShell Version 0.0.1d";
char usersays[256];
element *output;
int argHandled = 0;
int tablesFilled = 0;
char mutableArg[256];
int complete = 0;
int dump = 0;
int load = 0;

int main(int argc, char *argv[])
{
	int version = 0;
	precision = 0;
	for(int i=1;i<argc;i++)
	{
		if(portstrcmp(argv[i],"-v",sizeof(argv[i]),3) == 1)
		{
			version = 1;
			break;
		}
		else if(portstrcmp(argv[i],"-d",sizeof(argv[i]),3) == 1)
		{
			dump = 1;
			break;
		}
		else if(portstrcmp(argv[i],"-l",sizeof(argv[i]),3) == 1)
		{
			load = 1;
		}
		else if(portstrcmp(argv[i],"-c",sizeof(argv[i]),3) == 1)
		{
			complete = 1;
		}
		else if(portstrcmp(argv[i],"-p",sizeof(argv[i]),3) == 1)
		{
			i++;
			precision = atoi(argv[i]);
			if(precision == 0)
			{
				if(portstrcmp(argv[i],"0",sizeof(argv[i]),2) == 1)
				{
					continue;
				}
				else
				{
					printf("Erroneous precision.\n");
				}
			}
			else
			{
				mpf_set_default_prec(8*precision);
				continue;
			}
		}
		else
		{
			if(tablesFilled == 0)
			{
				printf("Populating tables...");
				popPtable();
				tablesFilled = 1;
				printf("\t\t\t\t\t[OK!]\n");
			}

			portstrcpy(mutableArg,argv[i]);

			output = singularParse(muchBetter(mutableArg,sizeof(mutableArg)),sizeof(mutableArg));

			if(output != 0)
			{
				argHandled = 1;
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
	if(argHandled == 1)
	{
		return 0;
	}
	else if(version == 1)
	{
		printf("%s\n",Version);
		return 0;
	}
	else if(dump == 1)
	{
		printf("This is where I would take a dump.\n");
		printf("Populating tables...");
		popPtable();
		printf("\t\t\t\t\t[OK!]\n");
		printf("Dumping tables...");
		dumpTables("poop.frm");
		printf("\t\t\t\t\t[OK!]\n");
		printf("Exiting...\n");
		return 0;
	}
	else
	{
		if(tablesFilled == 0)
		{
			printf("Populating tables...");
			popPtable();
			tablesFilled = 1;
			printf("\t\t\t\t\t[OK!]\n");
		}
		usersays[0] = '\0';
		while(usersays[0] != 'q' && usersays[0] != 'Q')
		{
			printf("~#>");
			fgets(usersays,256,stdin);
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
		printf("Exiting...\n");
		return 0;
	}
}
