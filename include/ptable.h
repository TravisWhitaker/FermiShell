//	ChemTerm Copyright (C) 2012 Travis Michael Whitaker

typedef struct
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
	float universeAbundance;
	float crustAbundance;
	float humanAbundance;
	float halfLifeYears; // -1 indicates stability.
	char CASn[15];
	char CIDn[15];
} element;

extern element hydrogen;

extern void populate();
