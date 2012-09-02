//	FermiShell Copyright (C) 2012 Travis Whitaker

#ifndef TABLEIO
#define TABLEIO

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <portutils.h>

void dumpTables(const char *filename)
{
	FILE *dump;
	dump = fopen(filename,"w+");
	fwrite(Elements,sizeof(element),118,dump);
	fclose(dump);
	return;
}

#endif
