#ifndef TOOLS_H
#define TOOLS_H


#include "number_.h"
#include <string>
#include <map>
#include <cmath>

#define N_ 8

Number Xor(Number,Number);
int HammerDist(Number, Number);
int HammerDist(string, string);
double Score(string);
pair<double,Number> most_probable_string(Number A);
int FindKeySize(Number);
string BreakSingleBitXor(Number A);
string BreakRepeatingXor(Number A);

















#endif
