//	ChemTerm Copyright (C) 2012 Travis Whitaker

#ifndef PTABLE
#define PTABLE
typedef struct
{
	int atomNumber;
	char atomSymbol[5];
	char atomName[15];
	float atomMass;
	int phase; // -1 indicates unknown/ambiguous phase, 0 indicates a gas, 1 indicates a liquid, 2 indicates a solid.
	float fusionP; //-1 indicates unknown temperature.
	float vaporP;
	float density;
	float mohsHardness;
	float youngsModulus;
	float soundSpeed;
	float thermalExp;
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
	float universeAbundance;
	float crustAbundance;
	float humanAbundance;
	float halfLifeYears; // -1 indicates stability.
	char CASn[15];
	char CIDn[15];
} element;

typedef struct
{
	int isoNumber;
	char isoSymbol[5];
	char isoName[25];
	float isoMass;
	float isoRadius;
	float isoAbundance;
	float halfLifeYears;
	int primaryDecayMode;
	int secondaryDecayMode;
	int tertiaryDecayMode;
	element *finalState;
} isotope;

element *elementPop;
void popPtable();

isotope *isoPop;
void popIso();

element *Elements[119];

element hydrogen;
element helium;
element lithium;
element beryllium;
element boron;
element carbon;
element nitrogen;
element oxygen;
element fluorine;
element neon;
#endif
