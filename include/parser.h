//  ChemTerm Copyright (C) 2012 Travis Whitaker
#ifndef PARSER
#define PARSER

#include <gmp.h>
#include <portutils.h>
#include <stdlib.h>

int precision;

int beanCounter(const char input[], const int inputSize)
{
	int beans = 0;
	for(int i=0; i<inputSize; i++)
	{
		if(input[i] == '\0')
		{
			return beans;
		}
		else
		{
			beans++;
		}
	}
	return -1;
}

char *muchBetter(char input[], const int inputSize)
{
	char lowerCase[27] = "abcdefghijklmnopqrstuvwxyz";
	char upperCase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char init = input[0];
	if(beanCounter(input,inputSize) <= 3)
	{
		return input;
	}
	else
	{
		for(int i=0; i<26; i++)
		{
			if(init == lowerCase[i])
			{
				input[0] = upperCase[i];
				return input;
			}
			else
			{
				continue;
			}
		}
	}
	return input;
}

element *singularParse(char input[], const int inputSize)
{
	for(int i=0;i<inputSize;i++)
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
		else if(portstrcmp(input,Elements[i]->atomName,inputSize,sizeof(Elements[i]->atomName)) == 1)
		{
			return Elements[i];
		}
		else if(portstrcmp(input,Elements[i]->atomSymbol,inputSize,sizeof(Elements[i]->atomSymbol)) == 1)
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

void basicElementData(element *input)
{
	printf("Name:\t\t\t%s\n",input->atomName);
	printf("Symbol:\t\t\t%s\n",input->atomSymbol);
	printf("Atomic Number:\t\t%d\n",input->atomNumber);
	gmp_printf("Atomic Mass:\t\t%.Ff\n",input->atomMass);
	printf("Phase:\t\t\t");
	if(input->phase == -1)
	{
		printf("Ambiguous/Unknown");
	}
	else if(input->phase == 0)
	{
		printf("Gaseous");
	}
	else if(input->phase == 1)
	{
		printf("Liquid");
	}
	else if(input->phase == 2)
	{
		printf("Solid");
	}
	printf("\n");
	gmp_printf("Density:\t\t%.Ff g/cm^3\n",input->density);
	gmp_printf("Menting Point:\t\t%.Ff°C\n",input->fusionP);
	gmp_printf("Boiling Point:\t\t%.Ff°C\n",input->vaporP);
	printf("Metallic Character:\t");
	if(input->metalloid == -1)
	{
		printf("Ambiguous/Unknown");
	}
	else if(input->metalloid == 0)
	{
		printf("Metallic");
	}
	else if(input->metalloid == 1)
	{
		printf("Metalloid");
	}
	else if(input->metalloid == 2)
	{
		printf("Non-metallic");
	}
	printf("\n");
	printf("Color:\t\t\t%s\n",input->color);
	printf("Valence:\t\t%d\n",input->valence);
	gmp_printf("Electronegativity:\t%.Ff\n",input->electroneg);
	gmp_printf("Ionization Energies:\t%.Ff eV\n",input->ionE1);
	gmp_printf("Atomic Radius:\t\t%.Ff pm\n",input->atomRadius);
}

void completeElementData(element *input)
{
	printf("Name:\t\t\t\t%s\n",input->atomName);
	printf("Symbol:\t\t\t\t%s\n",input->atomSymbol);
	printf("Atomic Number:\t\t\t%d\n",input->atomNumber);
	gmp_printf("Atomic Mass:\t\t\t%.Ff\n",input->atomMass);
	printf("Phase:\t\t\t\t");
	if(input->phase == -1)
	{
		printf("Ambiguous/Unknown");
	}
	else if(input->phase == 0)
	{
		printf("Gaseous");
	}
	else if(input->phase == 1)
	{
		printf("Liquid");
	}
	else if(input->phase == 2)
	{
		printf("Solid");
	}
	printf("\n");
	gmp_printf("Density:\t\t\t%.Ff g/cm^3\n",input->density);
	gmp_printf("Menting Point:\t\t\t%.Ff°C\n",input->fusionP);
	gmp_printf("Boiling Point:\t\t\t%.Ff°C\n",input->vaporP);
	gmp_printf("Mohs Hardness:\t\t\t%.Ff\n",input->mohsHardness);
	gmp_printf("Young's Modulus:\t\t%.Ff GPa\n",input->youngsModulus);
	gmp_printf("Sound Propagation Speed:\t%.Ff m/s\n",input->soundSpeed);
	gmp_printf("Thermal Expansion:\t\t%.Ff 1/K\n",input->thermalExp);
	gmp_printf("Thermal Conductivity:\t\t%.Ff W/(mK)\n",input->thermCon);
	printf("Metallic Character:\t\t");
	if(input->metalloid == -1)
	{
		printf("Ambiguous/Unknown");
	}
	else if(input->metalloid == 0)
	{
		printf("Metallic");
	}
	else if(input->metalloid == 1)
	{
		printf("Metalloid");
	}
	else if(input->metalloid == 2)
	{
		printf("Non-metallic");
	}
	printf("\n");
	printf("Magnetic Behavior:\t\t");
	if(input->magType == -1)
	{
		printf("Ambiguous/Unknown");
	}
	else if(input->magType == 0)
	{
		printf("Diamagnetic");
	}
	else if(input->magType == 1)
	{
		printf("Paramagnetic");
	}
	else if(input->magType == 2)
	{
		printf("Ferromagnetic");
	}
	else if(input->magType == 3)
	{
		printf("Antiferromagnetic");
	}
	printf("\n");
	printf("Superconducting Point:\t\t");
	if(mpf_cmp_si(input->superconductingPoint,-1) == 0)
	{
		printf("Unknown");
	}
	else
	{
		gmp_printf("%.Ff K",input->superconductingPoint);
	}
	printf("\n");
	printf("Color:\t\t\t\t%s\n",input->color);
	printf("Refractive Index:\t\t");
	if(mpf_cmp_si(input->refractiveIndex,-1) == 0)
	{
		printf("Non-refracting/Unknown");
	}
	else
	{
		gmp_printf("%.Ff",input->refractiveIndex);
	}
	printf("\n");
	printf("Valence:\t\t\t%d\n",input->valence);
	gmp_printf("Electronegativity:\t\t%.Ff\n",input->electroneg);
	gmp_printf("Electron Affinity:\t\t%.Ff eV\n",input->electroAffinity);
	gmp_printf("Ionization Energies:\t\t%.Ff eV\n",input->ionE1);
	printf("Molar Heat of Combustion:\t");
	if(mpf_cmp_si(input->mHc,-1) == 0)
	{
		printf("Unknown");
	}
	else
	{
		gmp_printf("%.Ff kJ/mol",input->mHc);
	}
	printf("\n");
	gmp_printf("Atomic Radius:\t\t\t%.Ff pm\n",input->atomRadius);
	gmp_printf("Universe Abundance:\t\t%.Ff%\n",input->universeAbundance);
	gmp_printf("Earth's Crust Abundance:\t%.Ff%\n",input->crustAbundance);
	gmp_printf("Human Abundance:\t\t%.Ff%\n",input->humanAbundance);
	printf("Half Life:\t\t\t");
	if(mpf_cmp_si(input->halfLifeYears,-1) == 0)
	{
		printf("Stable");
	}
	else
	{
		gmp_printf("%.Ff years",input->halfLifeYears);
	}
	printf("\n");
	printf("CAS:\t\t\t\t%s\n",input->CASn);
	printf("CID:\t\t\t\t%s\n",input->CIDn);
}

	
#endif
