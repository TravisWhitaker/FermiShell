//	ChemTerm Copyright (C) 2012 Travis Whitaker

#include <stdio.h>
#include <ptable.h>
#include <portutils.h>

char usersays[100];
element *singularParse(char input[]);
element *output;

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
			output = singularParse(usersays);

			if(output != 0)
			{
				printf("Name:\t\t%s\n",output->atomName);
				printf("Symbol:\t\t%s\n",output->atomSymbol);
				printf("Atomic Number:\t%d\n",output->atomNumber);
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

element *singularParse(char input[])
{
	for(int i=0;i<sizeof(input);i++)
	{
		if(input[i] == '\n')
		{
			input[i] = '\0';
			break;
		}
		else
		{
			continue;
		}
	}

	element *scanner;

	for(int i=0;i<119;i++)
	{
		scanner = Elements[i];
		if(scanner == 0)
		{
			break;
		}
		else if(portstrcmp(input,Elements[i]->atomName,sizeof(input),sizeof(Elements[i]->atomName)) == 1)
		{
			return Elements[i];
		}
		else if(portstrcmp(input,Elements[i]->atomSymbol,sizeof(input),sizeof(Elements[i]->atomSymbol)) == 1)
		{
			return Elements[i];
		}
		else
		{
			continue;
		}
	}
	return 0;
}
