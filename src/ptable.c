//	Copyright (C) 2012 Travis Michael Whitaker

#include <portutils.h>
#include <ptable.h>

void popPtable()
{
	populator = &hydrogen;

    populator->atomNumber = 1;
    portstrcpy(populator->atomName,"Hydrogen\0");
    populator->atomMass = 1.00794;
    populator->phase = 0;
    populator->fusionP = -259.14;
    populator->vaporP = -252.87;
    populator->density = 0.00000899;
    populator->soundSpeed = 1270;
    populator->thermCon = 0.1805;
    populator->metalloid = -1;
    populator->magType = 0;
    portstrcpy(populator->color,"colorless\0");
    populator->refractiveIndex = 1.000132;
    populator->valence = 1;
    populator->electroneg = 2.2;
    populator->electroAffinity = 0.755;
    populator->ionE1 = 13.598;
    populator->ionE2 = -1;
    populator->ionE3 = -1;
    populator->mHc = 285.8;
    populator->atomRadius = 25;
    populator->universeAbundance = 75;
    populator->crustAbundance = 0.15;
    populator->humanAbundance = 10;
	populator->halfLifeYears = -1;
    portstrcpy(populator->CASn,"1333-74-0\0");
    portstrcpy(populator->CIDn,"783\0");
}

