//	Copyright (C) 2012 Travis Whitaker

#include <gmp.h>
#include <ptable.h>


char *portstrcpy(char dest[], const char source[]);

void popPtable()
{
	elementPop = &hydrogen;
	Elements[0] = &hydrogen;

	elementPop->atomNumber = 1;
	portstrcpy(elementPop->atomSymbol,"H");
    portstrcpy(elementPop->atomName,"Hydrogen");
    elementPop->atomMass = 1.00794;
    elementPop->phase = 0;
    elementPop->fusionP = -259.14;
    elementPop->vaporP = -252.87;
    elementPop->density = 0.00000899;
	elementPop->mohsHardness = -1;
	elementPop->youngsModulus = -1;
    elementPop->soundSpeed = 1270;
	elementPop->thermalExp = -1;
    elementPop->thermCon = 0.1805;
    elementPop->metalloid = -1;
    elementPop->magType = 0;
    portstrcpy(elementPop->color,"colorless");
    elementPop->refractiveIndex = 1.000132;
    elementPop->valence = 1;
    elementPop->electroneg = 2.2;
    elementPop->electroAffinity = 0.755;
    elementPop->ionE1 = 13.598;
    elementPop->ionE2 = -1;
    elementPop->ionE3 = -1;
    elementPop->mHc = 285.8;
    elementPop->atomRadius = 25;
    elementPop->universeAbundance = 75;
    elementPop->crustAbundance = 0.15;
    elementPop->humanAbundance = 10;
	elementPop->halfLifeYears = -1;
    portstrcpy(elementPop->CASn,"1333-74-0");
    portstrcpy(elementPop->CIDn,"783");

	elementPop = &helium;
	Elements[1] = &helium;

	elementPop->atomNumber = 2;
	portstrcpy(elementPop->atomSymbol,"He");
	portstrcpy(elementPop->atomName,"Helium");
	elementPop->atomMass = 4.00260;
	elementPop->phase = 0;
	elementPop->fusionP = -1;
	elementPop->vaporP = -268.93;
	elementPop->density = 0.0001785;
	elementPop->mohsHardness = -1;
	elementPop->youngsModulus = -1;
	elementPop->soundSpeed = 970;
	elementPop->thermalExp = -1;
	elementPop->thermCon = 0.1513;
	elementPop->metalloid = 2;
	elementPop->magType = 0;
	portstrcpy(elementPop->color,"colorless");
	elementPop->refractiveIndex = 1.000035;
	elementPop->valence = 0;
	elementPop->electroneg = 0;
	elementPop->electroAffinity = 0;
	elementPop->ionE1 = 24.587;
	elementPop->ionE2 = 54.418;
	elementPop->ionE3 = -1;
	elementPop->mHc = -1;
	elementPop->atomRadius = 31;
	elementPop->universeAbundance = 23;
	elementPop->crustAbundance = 0.00000055;
	elementPop->humanAbundance = -1;
	elementPop->halfLifeYears = -1;
	portstrcpy(elementPop->CASn,"7440-59-7");
	portstrcpy(elementPop->CIDn,"23987");

	elementPop = &lithium;
	Elements[2] = &lithium;

	elementPop->atomNumber = 3;
	portstrcpy(elementPop->atomSymbol,"Li");
    portstrcpy(elementPop->atomName,"Lithium");
    elementPop->atomMass = 6.941;
    elementPop->phase = 2;
    elementPop->fusionP = 180.54;
    elementPop->vaporP = 1342.0;
    elementPop->density = 0.535;
	elementPop->mohsHardness = 0.6;
	elementPop->youngsModulus = 4.9;
    elementPop->soundSpeed = 6000;
	elementPop->thermalExp = .000046;	
    elementPop->thermCon = 85.0;
    elementPop->metalloid = 0;
    elementPop->magType = 1;
    portstrcpy(elementPop->color,"silver");
    elementPop->refractiveIndex = -1;
    elementPop->valence = 1;
    elementPop->electroneg = 0.98;
    elementPop->electroAffinity = 0.618;
    elementPop->ionE1 = 5.391;
    elementPop->ionE2 = -1;
    elementPop->ionE3 = -1;
    elementPop->mHc = 298.0;
    elementPop->atomRadius = 145;
    elementPop->universeAbundance = .0000006;
    elementPop->crustAbundance = 0.0017;
    elementPop->humanAbundance = .000003;
	elementPop->halfLifeYears = -1;
    portstrcpy(elementPop->CASn,"7439-93-2");
    portstrcpy(elementPop->CIDn,"3028194");

}

//void popIso()
//{
//	isoPop = &___;
//}
