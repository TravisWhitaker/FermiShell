<!--- FermiShell Copyright (C) 2012 Travis Whitaker -->

FermiShell
========

Retrieve, compare, calculate, analyze, graph, simulate, and experiment with chemical data.

---

FermiShell is an interactive shell designed to allow for straightforward, computational, simulatory, and scriptable modelling and analysis of chemical states and systems. It can draw from an extensive built-in database of chemical data and statistics. FermiShell is written in C and makes extensive use of the GNU Multiprecision library(GMP). FermiShell is released under the terms of a modified version of the MIT license, the full terms of which may be found in the file "LICENSE."

What can FermiShell do?
=====================
- Retrieve data and statistics. What is the most common isotope of Plutonium? What are the potential oxidation states of Technetium? What is the specific heat capacity of Aluminium? FermiShell    allows you to script access to it's extensive built-in periodic, polyatomic ion, and CCC tables.
- Compare and contrast electronegativities, ionization energies, solubilities, free energy states, and oxidation/reduction states. What salt must be used to extract pure Copper from CuSO4? What is the best solvent for extracting caffeine from Jolt™?
- Calculate rates, limiting-reagents, molarities, molalities, free energies, and cell potentials. Want to build your own MacBook Pro battery? What metals and salts should you use for the correct voltage? How much sugar can you dissolve in your 90°C coffee?
- Analyze theoretical chemical systems with support for many common reactions, including electrochemical cells. Test hypotheses and verify the range and accuracy of experimental data.
- Graph your data alongside theoretical means and extremes. Make powerful comparisons and gain more insight into experimental results and errors.
- Simulate experiments with your own specified parameters. Gain insight into your potential data before and during your time in the lab.
- Experiment with chemicals outside of your kit. Don't have access to nuclear-grade equipment? Conduct titrations with salts of Uranium anyway. Don't have an ISO 8 cleanroom? Thermodynamially optimize the growth of silicon substrates.

Dependencies:
=============
- libc
- gmblib(version 4 or greater for best performance)

How to Build:
=============
The makefile specifies Clang/LLVM as the compiler. You are of course free to change these, just make sure that you link against GMP, usually with the -lgmp compiler flag, and that you are in C99 mode. There is no config scipt(right now). The executable that is built doesn't require any other files; you can put it anywhere and it will be run just fine.
