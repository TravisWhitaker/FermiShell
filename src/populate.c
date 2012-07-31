//	Copyright (C) 2012 Travis Michael Whitaker

#include <portutils.h>
#include <ptable.h>

element hydrogen;

void populate()
 {
    hydrogen.atomNumber = 1;
    portstrcpy(hydrogen.atomName,"Hydrogen\0");
    hydrogen.atomMass = 1.00794;
    hydrogen.phase = 0;
    hydrogen.fusionP = -259.14;
    hydrogen.vaporP = -252.87;
    hydrogen.density = 0.00000899;
    hydrogen.soundSpeed = 1270;
    hydrogen.thermCon = 0.1805;
    hydrogen.metalloid = -1;
    hydrogen.magType = 0;
    portstrcpy(hydrogen.color,"colorless\0");
    hydrogen.refractiveIndex = 1.000132;
    hydrogen.valence = 1;
    hydrogen.electroneg = 2.2;
    hydrogen.electroAffinity = 0.755;
    hydrogen.ionE1 = 13.598;
    hydrogen.ionE2 = -1;
    hydrogen.ionE3 = -1;
    hydrogen.mHc = 285.8;
    hydrogen.atomRadius = 25;
    hydrogen.universeAbundance = 75;
    hydrogen.crustAbundance = 0.15;
    hydrogen.humanAbundance = 10;
	hydrogen.halfLifeYears = -1;
    portstrcpy(hydrogen.CASn,"1333-74-0\0");
    portstrcpy(hydrogen.CIDn,"783\0");
}

