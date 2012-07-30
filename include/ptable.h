//	This file contains all of the elemental data locally accessible by ChemTerm.
//
//	Test implementation of element struct:

struct element
{
	int atomNumber;
	char atomName[15];
	float atomMass;
	int phase; // -1 indicates unknown/ambiguous phase, 0 indicates a gas, 1 indicates a liquid, 2 indicates a solid.
	float fusionP;
	float vaporP;
	float density;
	float soundSpeed;
	float thermCon;
	int metalloid; // -1 indicates unknown/ambiguous, 0 indicates a metal, 1 indicates a metalloid, 2 indicates a non-metal.
	int magType; //-1 indicates unknown/ambiguous, 0 indicates diamagnetism, 1 indicates paramagnetism, 2 indicates ferromagnetism.
	char color[20];
	float refractiveIndex;
	int valence;
	float electroneg;
	float electroAffinity;
	float ionE1; // A value of -1 indicates unknown/undefined.
	float ionE2;
	float ionE3;
	float mHc;
	float atomRadius;
	struct isotope[37];
	float universeAbundance;
	float crustAbundance;
	float humanAbundance;
	float halfLifeYears; // -1 indicates stability.
	char CASn[15];
	char CIDn[15];
};

//	Test implementation of isotope struct:

struct isotope
{
	int isoNumber;
	char isoName[20];
	int isoMass;
	float abundance;// -1 indicates unknown/non-significant.
	int isRadioactive; // -1 indicates unknown/undefined, 0 indicates non-radioactive, 1 indicates radioactivity.
	float halfLifeYears; // -1 indicates stability.
};

//	This is the null instance of the struct 'isotope.'

struct isotope notope;

notope.isoNumber = 0;
notope.isoName = "\0"
notope.isoMass = 0;
notope.abundance = 100;
notope.isRadioactive = -1;
notope.halfLifeYears = -1;

//	Function to fill the remainder of the element.isotope array with 'notope.'

void isoFill(struct isoArray, int isoFilled)
{
	int isoInc;
	for(isoInc = isoFilled; isoInc < 37; isoInc++)
	{
		isoArray[isoInc] = notope;
	}
	return;
}

//	Start Periodic Table:

//	Hydrogen

struct element hydrogen

hydrogen.atomNumber = 1;
hydrogen.atomName = "Hydrogen\0";
hydrogen.atomMass = 1.00794;
hydrogen.phase = 0;
hydrogen.fusionP = -259.14;
hydrogen.vaporP = -252.87'
hydrogen.density = 0.00000899;
hydrogen.soundSpeed = 1270;
hydrogen.thermCon = 0.1805;
hydrogen.metalloid = -1;
hydrogen.magType = 0;
hydrogen.color = "colorless\0";
hydrogen.refractiveIndex = 1.000132;
hydrogen.valence = 1;
hydrogen.electroneg = 2.2;
hydrogen.electroAffinity = 0.755;
hydrogen.ionE1 = 13.598;
hydrogen.ionE2 = -1;
hydrogen.ionE3 = -1;
hydrogen.mHc = 285.8;
hydrogen.atomRadius = 25;
hydrogen.isotope[0] = H_1; hydrogen.isotope[1] = H_2; hydrogen.isotope[2] = H_3;
isoFill(hydrogen.isotope,3);
hydrogen.universeAbundance = 75;
hydrogen.crustAbundance = 0.15;
hydrogen.humanAbundance = 10;
hydrogen.halfLifeYears = -1;
hydrogen.CASn = "1333-74-0\0";
hydrogen.CIDn = "783";

struct isotope H_1;

H_1.isoNumber = 1;
H_1.isoName = "Hydrogen\0";
H_1.isoMass = 1;
H_1.abundance = 99.985;
H_1.isRadioactive = 0;
H_1.halfLifeYears = -1;

struct isotope H_2;

H_2.isoNumber = 2;
H_2.isoName = "Deuterium\0";
H_2.isoMass = 2;
H_2.abundance = 0.00015;
H_2.isRadioactive = 0;
H_2.halfLifeYears = -1;

struct isotope H_3;

H_3.isoNumber = 3;
H_3.isoName = "Tritium\0";
H_3.isoMass = 3;
H_3.abundance = -1;
H_3.isRadioactive = 1;
H_3.halfLifeYears = 12.32;
