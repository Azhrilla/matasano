#include <string>
#include <bitset>
#include <iostream>
#include <vector>


using namespace std;
class Number
{
private:
  int m_size;
  string m_content;

public:
  Number(string, string);
  string GetHex();
  string GetBin();
  string GetB64();
  string GetChar();
  void Xor(Number);
  int HammerDist(Number);
  vector<int> FindKeysize();
};
