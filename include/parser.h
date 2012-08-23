//  FermiShell Copyright (C) 2012 Travis Whitaker
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
	printf("Table Block:\t\t%s\n",input->block);
	printf("Atomic Mass:\t\t");
	if(mpf_cmp_si(input->atomMass,-1) == 0)
	{
		printf("Unknown/Relativistic");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->atomMass);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->atomMass);
		}
		printf(" amu");
	}
	printf("\n");
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
	printf("Density:\t\t");
	if(mpf_cmp_si(input->density,-1) == 0)
	{
		printf("Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->density);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->density);
		}
		printf(" g/cm³");
	}
	printf("\n");
	printf("Melting Point:\t\t");
	if(mpf_cmp_si(input->fusionP,-1) == 0)
	{
		printf("Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->fusionP);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->fusionP);
		}
		printf("°C");
	}
	printf("\n");
	printf("Boiling Point:\t\t");
	if(mpf_cmp_si(input->vaporP,-1) == 0)
	{
		printf("Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->vaporP);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->vaporP);
		}
		printf("°C");
	}
	printf("\n");
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
	printf("Valence:\t\t");
	if(input->valence == -1)
	{
		printf("Unknown/Relativistic");
	}
	else
	{
		printf("%d",input->valence);
	}
	printf("\n");
	printf("Electronegativity:\t");
	if(mpf_cmp_si(input->electroneg,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{	
			gmp_printf("%.Ff",input->electroneg);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->electroneg);
		}
	}
	printf("\n");
	printf("Ionization Energies:\t");
	if(mpf_cmp_si(input->ionE1,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}	
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->ionE1);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->ionE1);
		}
		printf(" eV");
	}
	printf("\n");
	printf("Atomic Radius:\t\t");
	if(mpf_cmp_si(input->atomRadius,-1) == 0)
	{
		printf("Unknown/Relativistic");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->atomRadius);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->atomRadius);
		}
		printf(" pm");
	}
	printf("\n");
}

void completeElementData(element *input)
{
	printf("Name:\t\t\t\t%s\n",input->atomName);
	printf("Symbol:\t\t\t\t%s\n",input->atomSymbol);
	printf("Atomic Number:\t\t\t%d\n",input->atomNumber);
	printf("Table Block:\t\t\t%s\n",input->block);
	printf("Atomic Mass:\t\t\t");
	if(mpf_cmp_si(input->atomMass,-1) == 0)
	{
		printf("Unknown/Relativistic");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->atomMass);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->atomMass);
		}
		printf(" amu");
	}
	printf("\n");
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
	printf("Density:\t\t\t");
	if(mpf_cmp_si(input->density,-1) == 0)
	{
		printf("Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->density);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->density);
		}
		printf(" g/cm³");
	}
	printf("\n");
	printf("Melting Point:\t\t\t");
	if(mpf_cmp_si(input->fusionP,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->fusionP);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->fusionP);
		}
		printf("°C");
	}
	printf("\n");
	printf("Boilint Point:\t\t\t");
	if(mpf_cmp_si(input->vaporP,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->vaporP);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->vaporP);
		}
		printf("°C");
	}
	printf("\n");
	printf("Mohs Hardness:\t\t\t");
	if(mpf_cmp_si(input->mohsHardness,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->mohsHardness);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->mohsHardness);
		}
	}
	printf("\n");
	printf("Yount's Modulus:\t\t");
	if(mpf_cmp_si(input->youngsModulus,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->youngsModulus);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->youngsModulus);
		}
		printf(" GPa");
	}
	printf("\n");
	printf("Sound Propagation Speed:\t");
	if(mpf_cmp_si(input->soundSpeed,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->soundSpeed);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->soundSpeed);
		}
		printf(" m/s");
	}
	printf("\n");
	printf("Thermal Expansion:\t\t");
	if(mpf_cmp_si(input->thermalExp,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->thermalExp);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->thermalExp);
		}
		printf(" 1/K");
	}
	printf("\n");
	printf("Thermal Conductivity:\t\t");
	if(mpf_cmp_si(input->thermCon,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->thermCon);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->thermCon);
		}
		printf(" W/(mK)");
	}
	printf("\n");
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
		printf("Unknown/Non-superconducting");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->superconductingPoint);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->superconductingPoint);
		}
		printf(" K");
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
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->refractiveIndex);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->refractiveIndex);
		}
	}
	printf("\n");
	printf("Valence:\t\t\t");
	if(input->valence == -1)
	{
		printf("Unknown/Relativistic");
	}
	else
	{
		printf("%d",input->valence);
	}	
	printf("\n");
	printf("Electronegativity:\t\t");
	if(mpf_cmp_si(input->electroneg,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->electroneg);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->electroneg);
		}
	}
	printf("\n");
	printf("Electron Affinity:\t\t");
	if(mpf_cmp_si(input->electroAffinity,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->electroAffinity);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->electroAffinity);
		}
		printf(" eV");
	}
	printf("\n");
	printf("Ionization Energies:\t\t");
	if(mpf_cmp_si(input->ionE1,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision  == 0)
		{
			gmp_printf("%.Ff",input->ionE1);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->ionE1);
		}
		printf(" eV");
	}
	printf("\t");
	if(mpf_cmp_si(input->ionE2,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->ionE2);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->ionE2);
		}
		printf(" eV");
	}
	printf("\t");
	if(mpf_cmp_si(input->ionE3,-1) == 0)
	{
		printf("Ambiguous/Unknown");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->ionE3);
		}
		else
		{
			gmp_printf("%.*Ff",input->ionE3);
		}
		printf(" eV");
	}
	printf("\n");
	printf("Molar Heat of Combustion:\t");
	if(mpf_cmp_si(input->mHc,-1) == 0)
	{
		printf("Unknown/Non-spontaneous");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->mHc);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->mHc);
		}
		printf(" kJ/mol");
	}
	printf("\n");
	printf("Atomic Radius:\t\t\t");
	if(mpf_cmp_si(input->atomRadius,-1) == 0)
	{
		printf("Unknown/Relativistic");
	}
	else
	{
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->atomRadius);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->atomRadius);
		}
		printf(" pm");
	}
	printf("\n");
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
		if(precision == 0)
		{
			gmp_printf("%.Ff",input->halfLifeYears);
		}
		else
		{
			gmp_printf("%.*Ff",precision,input->halfLifeYears);
		}
		printf(" years");
	}
	printf("\n");
	printf("CAS:\t\t\t\t%s\n",input->CASn);
	printf("CID:\t\t\t\t%s\n",input->CIDn);
}
	
#endif
