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
	mpf_init_set_str(elementPop->atomMass,"1.00794",10);
    elementPop->phase = 0;
    mpf_init_set_str(elementPop->fusionP,"-259.14",10);
    mpf_init_set_str(elementPop->vaporP,"-252.87",10);
    mpf_init_set_str(elementPop->density,"0.00000899",10);
	mpf_init_set_str(elementPop->mohsHardness,"-1.0",10);
	mpf_init_set_str(elementPop->youngsModulus,"-1.0",10);
    mpf_init_set_str(elementPop->soundSpeed,"1270.0",10);
	mpf_init_set_str(elementPop->thermalExp,"-1.0",10);
    mpf_init_set_str(elementPop->thermCon,"0.01805",10);
    elementPop->metalloid = -1;
    elementPop->magType = 0;
    portstrcpy(elementPop->color,"colorless");
    mpf_init_set_str(elementPop->refractiveIndex,"1.000132",10);
    elementPop->valence = 1;
    mpf_init_set_str(elementPop->electroneg,"2.2",10);
    mpf_init_set_str(elementPop->electroAffinity,"0.755",10);
    mpf_init_set_str(elementPop->ionE1,"13.598",10);
    mpf_init_set_str(elementPop->ionE2,"-1.0",10);
    mpf_init_set_str(elementPop->ionE3,"-1.0",10);
    mpf_init_set_str(elementPop->mHc,"285.8",10);
    mpf_init_set_str(elementPop->atomRadius,"25.0",10);
    mpf_init_set_str(elementPop->universeAbundance,"75.0",10);
    mpf_init_set_str(elementPop->crustAbundance,"0.15",10);
    mpf_init_set_str(elementPop->humanAbundance,"10.0",10);
	mpf_init_set_str(elementPop->halfLifeYears,"-1",10);
    portstrcpy(elementPop->CASn,"1333-74-0");
    portstrcpy(elementPop->CIDn,"783");

	elementPop = &helium;
	Elements[1] = &helium;

	elementPop->atomNumber = 2;
	portstrcpy(elementPop->atomSymbol,"He");
	portstrcpy(elementPop->atomName,"Helium");
	mpf_init_set_str(elementPop->atomMass,"4.00260",10);
	elementPop->phase = 0;
	mpf_init_set_str(elementPop->fusionP,"-1.0",10);
	mpf_init_set_str(elementPop->vaporP,"-268.93",10);
	mpf_init_set_str(elementPop->density,"0.0001785",10);
	mpf_init_set_str(elementPop->mohsHardness,"-1.0",10);
	mpf_init_set_str(elementPop->youngsModulus,"-1.0",10);
	mpf_init_set_str(elementPop->soundSpeed,"970.0",10);
	mpf_init_set_str(elementPop->thermalExp,"-1.0",10);
	mpf_init_set_str(elementPop->thermCon,"0.1513",10);
	elementPop->metalloid = 2;
	elementPop->magType = 0;
	portstrcpy(elementPop->color,"colorless");
	mpf_init_set_str(elementPop->refractiveIndex,"1.000035",10);
	elementPop->valence = 0;
	mpf_init_set_str(elementPop->electroneg,"0.0",10);
	mpf_init_set_str(elementPop->electroAffinity,"0.0",10);
	mpf_init_set_str(elementPop->ionE1,"24.587",10);
	mpf_init_set_str(elementPop->ionE2 ,"54.418",10);
	mpf_init_set_str(elementPop->ionE3,"-1.0",10);
	mpf_init_set_str(elementPop->mHc,"-1.0",10);
	mpf_init_set_str(elementPop->atomRadius,"31.0",10);
	mpf_init_set_str(elementPop->universeAbundance,"23.0",10);
	mpf_init_set_str(elementPop->crustAbundance,"0.00000055",10);
	mpf_init_set_str(elementPop->humanAbundance,"-1.0",10);
	mpf_init_set_str(elementPop->halfLifeYears,"-1.0",10);
	portstrcpy(elementPop->CASn,"7440-59-7");
	portstrcpy(elementPop->CIDn,"23987");

	elementPop = &lithium;
	Elements[2] = &lithium;

	elementPop->atomNumber = 3;
	portstrcpy(elementPop->atomSymbol,"Li");
    portstrcpy(elementPop->atomName,"Lithium");
    mpf_init_set_str(elementPop->atomMass,"6.941",10);
    elementPop->phase = 2;
    mpf_init_set_str(elementPop->fusionP,"180.54",10);
    mpf_init_set_str(elementPop->vaporP,"1342.0",10);
    mpf_init_set_str(elementPop->density,"0.535",10);
	mpf_init_set_str(elementPop->mohsHardness,"0.6",10);
	mpf_init_set_str(elementPop->youngsModulus,"4.9",10);
    mpf_init_set_str(elementPop->soundSpeed,"6000.0",10);
	mpf_init_set_str(elementPop->thermalExp,"0.000046",10);	
    mpf_init_set_str(elementPop->thermCon,"85.0",10);
    elementPop->metalloid = 0;
    elementPop->magType = 1;
    portstrcpy(elementPop->color,"silver");
    mpf_init_set_str(elementPop->refractiveIndex,"-1.0",10);
    elementPop->valence = 1;
    mpf_init_set_str(elementPop->electroneg,"0.98",10);
    mpf_init_set_str(elementPop->electroAffinity,"0.618",10);
    mpf_init_set_str(elementPop->ionE1,"5.391",10);
    mpf_init_set_str(elementPop->ionE2,"-1.0",10);
    mpf_init_set_str(elementPop->ionE3,"-1.0",10);
    mpf_init_set_str(elementPop->mHc,"298.0",10);
    mpf_init_set_str(elementPop->atomRadius,"145.0",10);
    mpf_init_set_str(elementPop->universeAbundance,"0.0000006",10);
    mpf_init_set_str(elementPop->crustAbundance,"0.0017",10);
    mpf_init_set_str(elementPop->humanAbundance,"0.000003",10);
	mpf_init_set_str(elementPop->halfLifeYears,"-1.0",10);
    portstrcpy(elementPop->CASn,"7439-93-2");
    portstrcpy(elementPop->CIDn,"3028194");

}

//void popIso()
//{
//	isoPop = &___;
//}
