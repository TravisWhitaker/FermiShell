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
	int magType; //-1 indicates unknown/ambiguous, 0 indicates diamagnetism, 1 indicates paramagnetism, 2 indicates ferromagnetism, 3 indicates anitferromagnetism.
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
element scandium;
element titanium;
element vanadium;
element chromium;
element manganese;
element iron;
element cobalt;
element nickel;
element copper;
element zinc;
element gallium;
element germanium;
element arsenic;
element selenium;
element bromine;
element krypton;
element rubidium;
element strontium;
element yttrium;
element zirconium;
element niobium;
element molybdenum;
element technetium;
element ruthenium;
element rhodium;
element palladium;
element silver;
element cadmium;
element indium;
element tin;
element antimony;
element tellurium;
element iodine;
element xenon;
element caesium;
element barium;
element lanthanum;
element cerium;
element praseodymium;
element neodymium;
element promethium;
element samarium;
element europium;
element gadolimium;
element terbium;
element dysprosium;
element holmium;
element erbium;
element thulium;
element ytterbium;
element lutetium;
element hafnium;
element tantalum;
element tungsten;
element rhenium;
element osmium;
element iridium;
element platinim;
element gold;
element mercury;
element thallium;
element lead;
element bismuth;
element polonium;
element astatine;
element radon;
element francium;
element radium;
element actinium;
element thorium;
element protactinium;
element uranium;
element neptunium;
element plutonium;
element americium;
element curium;
element berkelium;
element californium;
element einsteinium;
element fermium;
element mendelevium;
element nobelium;
element lawrencium;
element rutherfordium;
element dubnium;
element seaborgium;
element bohrium;
element hassium;
element meitnerium;
element darmstadtium;
element roentgenium;
element copernicum;
element ununtrium;
element flerovium;
element ununpentium;
element livermorium;
element ununseptium;
element ununoctium;

#endif
