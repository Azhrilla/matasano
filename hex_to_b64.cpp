#include <bitset>
#include <iostream>
#include <map>
#include <cmath>
#include "number_.h"
#include <fstream>
#define N_ 8
using namespace std;


double score(string A)
{

  int realSize = A.size();
  map<char,double> charmap;
  charmap.insert(pair<char,double>('e',0));
  charmap.insert(pair<char,double>('t',0));
  charmap.insert(pair<char,double>('a',0));
  charmap.insert(pair<char,double>('o',0));
  charmap.insert(pair<char,double>('i',0));
  charmap.insert(pair<char,double>('n',0));
  charmap.insert(pair<char,double>('s',0));
  charmap.insert(pair<char,double>('h',0));
  charmap.insert(pair<char,double>('r',0));
  charmap.insert(pair<char,double>('d',0));
  charmap.insert(pair<char,double>('l',0));
  charmap.insert(pair<char,double>('u',0));

  map<char,double> freqmap;
  freqmap.insert(pair<char,double>('e',12.702));
  freqmap.insert(pair<char,double>('t',9.056));
  freqmap.insert(pair<char,double>('a',8.167));
  freqmap.insert(pair<char,double>('o',7.507));
  freqmap.insert(pair<char,double>('i',6.966));
  freqmap.insert(pair<char,double>('n',6.749));
  freqmap.insert(pair<char,double>('s',6.327));
  freqmap.insert(pair<char,double>('h',6.094));
  freqmap.insert(pair<char,double>('r',5.987));
  freqmap.insert(pair<char,double>('d',4.253));
  freqmap.insert(pair<char,double>('l',4.025));
  freqmap.insert(pair<char,double>('u',2.758));

  for (unsigned int i = 0; i < A.size(); i++)
    {
      if (A[i]== 'a' || A[i] == 'A')
        charmap['a']+=1;
      if (A[i]== 't' || A[i] == 'T')
        charmap['t']+=1;
      if (A[i]== 'e' || A[i] == 'E')
        charmap['e']+=1;
      if (A[i]== 'o' || A[i] == 'O')
        charmap['o']+=1;
      if (A[i]== 'i' || A[i] == 'I')
        charmap['i']+=1;
      if (A[i]== 'n' || A[i] == 'N')
        charmap['n']+=1;
      if (A[i]== 'h' || A[i] == 'H')
        charmap['h']+=1;
      if (A[i]== 'r' || A[i] == 'R')
        charmap['r']+=1;
      if (A[i]== 's' || A[i] == 'S')
        charmap['s']+=1;
      if (A[i]== 'l' || A[i] == 'L')
        charmap['l']+=1;
      if (A[i]== 'u' || A[i] == 'U')
        charmap['u']+=1;
      if (A[i]== 'd' || A[i] == 'D')
        charmap['d']+=1;
      if (A[i] == ' ') realSize--;

    }
  for (map<char,double>::iterator it = charmap.begin(); it != charmap.end(); it++)
    {
      realSize = (realSize == 0)?1:realSize;
      it->second/=realSize;;
      it->second*=100;
    }

  double score = 0;
  map<char,double>::iterator it2 = charmap.begin();
  for (map<char,double>::iterator it = freqmap.begin(); it != freqmap.end(); it++)
    {
      score += (it->second - it2->second)* (it->second - it2->second);
      it2++;
    }

  return score;
}



pair<double,Number> most_probable_string(Number A)
{
  int size = pow(2,N_);
  Number best("bin","0");
  double bestScore = 1000;
  for (unsigned int i = 0 ; i < size; i++)
    {

      bitset<N_> mybit(i);
      Number mynumb("bin", mybit.to_string());
      Number tested = A;
      tested.Xor(mynumb);
      double scoreTest = score(tested.GetChar());
      if (scoreTest < 400)
        //cout <<i << " " <<scoreTest << " " <<  tested.GetChar() <<endl;
      if (scoreTest < bestScore)
        {
          bestScore = scoreTest;
          best = tested;
        }
    }
  //cout << best.GetChar() <<endl;
  return pair<double,Number>(bestScore,best);
}

int main()
{
  // 1er challenge
  string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  string ref = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

  // 2eme challenge
  string
    input2_1 = "1c0111001f010100061a024b53535009181c",
    input2_2 = "686974207468652062756c6c277320657965",
    ref2 = "746865206b696420646f6e277420706c6179";


  // 3eme challenge
  string
    input3 = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b37360";


  Number chal1("hex", input);
  if (chal1.GetB64() == ref) cout << "chal1 ok"<<endl;

  Number chal2("hex", input2_1);
  Number input2("hex", input2_2);

  chal2.Xor(input2);

  if (chal2.GetHex() == ref2)
    cout << "chal2 ok" <<endl;

  Number chal3("hex",input3);

  most_probable_string(chal3);
  string line;
  ifstream fichier("chal4.txt", ios::in);
  Number chal4_best("bin","1");
  double bestscore = 1000;
  int i = 0 ;
  while (getline (fichier,line))
    {
      Number chal4("hex",line);
      pair<double,Number> output = most_probable_string(chal4);
      if (output.first < bestscore)
        {
          bestscore = output.first;
          chal4_best = output.second;
        }
    }
  //  cout << chal4_best.GetChar() <<endl;

  Number ICE("char", "ICE");
  Number chal5("char", "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal");
  string ref5 = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
  chal5.Xor(ICE);
  if ( chal5.GetHex() == ref5)
  cout << "chal5 ok" <<endl;


  Number chal6_1("char","this is a test");
  Number chal6_2("char","wokka wokka!!!");
  if (chal6_1.HammerDist(chal6_2) ==37)
    cout << "test chal 6 ok" <<endl;

  ifstream fichier2("chal6.txt", ios::in);
  string inside = "";
  while (getline (fichier2,line))
    {
      inside += line;
    }
  Number chal6_main("B64",inside);
  chal6_main.FindKeysize();
  return 0;
}


