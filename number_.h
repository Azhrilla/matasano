#include <string>
#include <bitset>
#include <iostream>
#include <vector>

#ifndef NUMBER_H
#define NUMBER_H

using namespace std;




class Number
{
private:
  int m_size;
  string m_content;

public:
  Number();
  Number(string, string);
  string GetHex();
  string GetBin();
  string GetB64();
  string GetChar();
  int GetSize();
  vector<Number> GetSubNumber(int, int bitsize = 8);
};

bool TestSubNumber(Number A);
#endif
