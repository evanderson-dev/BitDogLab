#ifndef NOTES_H
#define NOTES_H

#include <stdint.h>

// Frequências das notas musicais em Hz com nomes em português e oitavas
#define SI_Oitava_0     31   // Si (oitava 0)
#define DO_Oitava_1     33   // Dó (oitava 1)
#define DO_S_Oitava_1   35   // Dó sustenido (oitava 1)
#define RE_Oitava_1     37   // Ré (oitava 1)
#define RE_S_Oitava_1   39   // Ré sustenido (oitava 1)
#define MI_Oitava_1     41   // Mi (oitava 1)
#define FA_Oitava_1     44   // Fá (oitava 1)
#define FA_S_Oitava_1   46   // Fá sustenido (oitava 1)
#define SOL_Oitava_1    49   // Sol (oitava 1)
#define SOL_S_Oitava_1  52   // Sol sustenido (oitava 1)
#define LA_Oitava_1     55   // Lá (oitava 1)
#define LA_S_Oitava_1   58   // Lá sustenido (oitava 1)
#define SI_Oitava_1     62   // Si (oitava 1)
#define DO_Oitava_2     65   // Dó (oitava 2)
#define DO_S_Oitava_2   69   // Dó sustenido (oitava 2)
#define RE_Oitava_2     73   // Ré (oitava 2)
#define RE_S_Oitava_2   78   // Ré sustenido (oitava 2)
#define MI_Oitava_2     82   // Mi (oitava 2)
#define FA_Oitava_2     87   // Fá (oitava 2)
#define FA_S_Oitava_2   93   // Fá sustenido (oitava 2)
#define SOL_Oitava_2    98   // Sol (oitava 2)
#define SOL_S_Oitava_2  104  // Sol sustenido (oitava 2)
#define LA_Oitava_2     110  // Lá (oitava 2)
#define LA_S_Oitava_2   117  // Lá sustenido (oitava 2)
#define SI_Oitava_2     123  // Si (oitava 2)
#define DO_Oitava_3     131  // Dó (oitava 3)
#define DO_S_Oitava_3   139  // Dó sustenido (oitava 3)
#define RE_Oitava_3     147  // Ré (oitava 3)
#define RE_S_Oitava_3   156  // Ré sustenido (oitava 3)
#define MI_Oitava_3     165  // Mi (oitava 3)
#define FA_Oitava_3     175  // Fá (oitava 3)
#define FA_S_Oitava_3   185  // Fá sustenido (oitava 3)
#define SOL_Oitava_3    196  // Sol (oitava 3)
#define SOL_S_Oitava_3  208  // Sol sustenido (oitava 3)
#define LA_Oitava_3     220  // Lá (oitava 3)
#define LA_S_Oitava_3   233  // Lá sustenido (oitava 3)
#define SI_Oitava_3     247  // Si (oitava 3)
#define DO_Oitava_4     262  // Dó (oitava 4, Dó central)
#define DO_S_Oitava_4   277  // Dó sustenido (oitava 4)
#define RE_Oitava_4     294  // Ré (oitava 4)
#define RE_S_Oitava_4   311  // Ré sustenido (oitava 4)
#define MI_Oitava_4     330  // Mi (oitava 4)
#define FA_Oitava_4     349  // Fá (oitava 4)
#define FA_S_Oitava_4   370  // Fá sustenido (oitava 4)
#define SOL_Oitava_4    392  // Sol (oitava 4)
#define SOL_S_Oitava_4  415  // Sol sustenido (oitava 4)
#define LA_Oitava_4     440  // Lá (oitava 4)
#define LA_S_Oitava_4   466  // Lá sustenido (oitava 4)
#define SI_Oitava_4     494  // Si (oitava 4)
#define DO_Oitava_5     523  // Dó (oitava 5)
#define DO_S_Oitava_5   554  // Dó sustenido (oitava 5)
#define RE_Oitava_5     587  // Ré (oitava 5)
#define RE_S_Oitava_5   622  // Ré sustenido (oitava 5)
#define MI_Oitava_5     659  // Mi (oitava 5)
#define FA_Oitava_5     698  // Fá (oitava 5)
#define FA_S_Oitava_5   740  // Fá sustenido (oitava 5)
#define SOL_Oitava_5    784  // Sol (oitava 5)
#define SOL_S_Oitava_5  831  // Sol sustenido (oitava 5)
#define LA_Oitava_5     880  // Lá (oitava 5)
#define LA_S_Oitava_5   932  // Lá sustenido (oitava 5)
#define SI_Oitava_5     988  // Si (oitava 5)
#define DO_Oitava_6     1047 // Dó (oitava 6)
#define DO_S_Oitava_6   1109 // Dó sustenido (oitava 6)
#define RE_Oitava_6     1175 // Ré (oitava 6)
#define RE_S_Oitava_6   1245 // Ré sustenido (oitava 6)
#define MI_Oitava_6     1319 // Mi (oitava 6)
#define FA_Oitava_6     1397 // Fá (oitava 6)
#define FA_S_Oitava_6   1480 // Fá sustenido (oitava 6)
#define SOL_Oitava_6    1568 // Sol (oitava 6)
#define SOL_S_Oitava_6  1661 // Sol sustenido (oitava 6)
#define LA_Oitava_6     1760 // Lá (oitava 6)
#define LA_S_Oitava_6   1865 // Lá sustenido (oitava 6)
#define SI_Oitava_6     1976 // Si (oitava 6)
#define DO_Oitava_7     2093 // Dó (oitava 7)
#define DO_S_Oitava_7   2217 // Dó sustenido (oitava 7)
#define RE_Oitava_7     2349 // Ré (oitava 7)
#define RE_S_Oitava_7   2489 // Ré sustenido (oitava 7)
#define MI_Oitava_7     2637 // Mi (oitava 7)
#define FA_Oitava_7     2794 // Fá (oitava 7)
#define FA_S_Oitava_7   2960 // Fá sustenido (oitava 7)
#define SOL_Oitava_7    3136 // Sol (oitava 7)
#define SOL_S_Oitava_7  3322 // Sol sustenido (oitava 7)
#define LA_Oitava_7     3520 // Lá (oitava 7)
#define LA_S_Oitava_7   3729 // Lá sustenido (oitava 7)
#define SI_Oitava_7     3951 // Si (oitava 7)
#define DO_Oitava_8     4186 // Dó (oitava 8)
#define DO_S_Oitava_8   4435 // Dó sustenido (oitava 8)
#define RE_Oitava_8     4699 // Ré (oitava 8)
#define RE_S_Oitava_8   4978 // Ré sustenido (oitava 8)

void play_tone(uint32_t pin, uint32_t frequency, uint32_t duration_ms);

#endif

// C = Dó
// D = Ré
// E = Mi
// F = Fá
// G = Sol
// A = Lá
// B = Si

// Nota	Frequência (Hz)
// C4	261.63
// D4	293.66
// E4	329.63
// F4	349.23
// G4	392.00
// A4	440.00
// B4	493.88
// C5	523.25