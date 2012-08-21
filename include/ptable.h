//	ChemTerm Copyright (C) 2012 Travis Whitaker

#ifndef PTABLE
#define PTABLE

#include <gmp.h>

typedef struct
{
	int atomNumber;
	char atomSymbol[5];
	char atomName[15];
	mpf_t atomMass;
	int phase; // -1 indicates unknown/ambiguous phase, 0 indicates a gas, 1 indicates a liquid, 2 indicates a solid.
	mpf_t fusionP; //-1 indicates unknown temperature.
	mpf_t vaporP;
	mpf_t density;
	mpf_t mohsHardness;
	mpf_t youngsModulus;
	mpf_t soundSpeed;
	mpf_t thermalExp;
	mpf_t thermCon;
	int metalloid; // -1 indicates unknown/ambiguous, 0 indicates a metal, 1 indicates a metalloid, 2 indicates a non-metal.
	int magType; //-1 indicates unknown/ambiguous, 0 indicates diamagnetism, 1 indicates paramagnetism, 2 indicates ferromagnetism.
	mpf_t superconductingPoint;
	char color[20];
	mpf_t refractiveIndex;
	int valence;
	mpf_t electroneg;
	mpf_t electroAffinity;
	mpf_t ionE1; // A value of -1 indicates unknown/undefined.
	mpf_t ionE2;
	mpf_t ionE3;
	mpf_t mHc;
	mpf_t atomRadius;
	mpf_t universeAbundance;
	mpf_t crustAbundance;
	mpf_t humanAbundance;
	mpf_t halfLifeYears; // -1 indicates stability.
	char CASn[15];
	char CIDn[15];
} element;

element *elementPop;
void popPtable();

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
element sodium;
element magnesium;
element aluminium;
element silicon;
element phosphorus;
element sulfur;
element chlorine;
element argon;
element potassium;
element calcium;

#endif
