#include "tools.h"



Number Xor(Number A, Number B)
{
  string
    bin_A = A.GetBin(),
    bin_B = B.GetBin(),
    newcontent = "";
  int
    size_A = bin_A.size(),
    size_B = bin_B.size();


  if (size_A < size_B)
    {
      Number output;
      return output;
    }
  if (size_A == size_B)
    {
      for (unsigned int i = 0 ; i < size_A; i++)
        {
          if (bin_A[i] == bin_B[i])
            newcontent += "0";
          else
            newcontent += "1";
        }
    }
  else
    {
      int iterator = 0;
      for (unsigned int i=0; i < size_A; i++)
        {
          if (bin_A[i] == bin_B[iterator])
            newcontent += "0";
          else
            newcontent += "1";
          iterator++;
          if (iterator >= size_B)
            iterator=0;
        }
    }
  Number output("bin", newcontent);
  return output;
}


int HammerDist(Number A, Number B)
{

  return HammerDist(A.GetBin(), B.GetBin());
}


int HammerDist(string  bin_A, string bin_B)
{
  int
    size_A = bin_A.size(),
    size_B = bin_B.size();
  int dist=0;
  if (size_A != size_B)
    return 0;
  for (unsigned int i = 0 ; i < size_A; i++)
    {
      if (bin_A[i] != bin_B[i])
        dist++;
    }
  return dist;
}

double Score(string A)
{
  int realSize = A.size();
  double spaces = 0 ;
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
  freqmap.insert(pair<char,double>('e',12.02));
  freqmap.insert(pair<char,double>('t',9.10));
  freqmap.insert(pair<char,double>('a',8.12));
  freqmap.insert(pair<char,double>('o',7.68));
  freqmap.insert(pair<char,double>('i',7.31));
  freqmap.insert(pair<char,double>('n',6.95));
  freqmap.insert(pair<char,double>('s',6.28));
  freqmap.insert(pair<char,double>('h',5.92));
  freqmap.insert(pair<char,double>('r',6.02));
  freqmap.insert(pair<char,double>('d',4.32));
  freqmap.insert(pair<char,double>('l',3.98));
  freqmap.insert(pair<char,double>('u',2.758));

  for (unsigned int i = 0; i < A.size(); i++)
    {
      if (A[i]== 'a')
        charmap['a']+=1;
      if (A[i]== 't')
        charmap['t']+=1;
      if (A[i]== 'e')
        charmap['e']+=1;
      if (A[i]== 'o')
        charmap['o']+=1;
      if (A[i]== 'i')
        charmap['i']+=1;
      if (A[i]== 'n')
        charmap['n']+=1;
      if (A[i]== 'h')
        charmap['h']+=1;
      if (A[i]== 'r')
        charmap['r']+=1;
      if (A[i]== 's')
        charmap['s']+=1;
      if (A[i]== 'l')
        charmap['l']+=1;
      if (A[i]== 'u')
        charmap['u']+=1;
      if (A[i]== 'd')
        charmap['d']+=1;
      if (A[i] == ' ') spaces++;

    }
  for (map<char,double>::iterator it = charmap.begin(); it != charmap.end(); it++)
    {
      it->second/=realSize;
      it->second*=100;
    }

  double score = 0;
  map<char,double>::iterator it2 = charmap.begin();
  for (map<char,double>::iterator it = freqmap.begin(); it != freqmap.end(); it++)
    {
      score +=(abs(it->second - it2->second)/ (it -> second));
      it2++;
    }
  //score += abs(spaces*100/realSize -15);
  return score;
}



pair<double,Number> most_probable_string(Number A)
{
  int size = pow(2,N_);
  Number best;
  Number KEY;
  double bestScore = 10000;
  for (unsigned int i = 0 ; i < size; i++)
    {

      bitset<N_> mybit(i);
      Number mynumb("bin", mybit.to_string());
      Number tested = Xor(A,mynumb);
      double scoreTest = Score(tested.GetChar());

      if (scoreTest < bestScore)
        {
          bestScore = scoreTest;
          best = tested;
          KEY = mynumb;
        }
    }
  return pair<double,Number>(bestScore,KEY);
}


int FindKeySize(Number A)
{
  string inside_A = A.GetBin();
  vector<int> output;
  int bitSize = A.GetSize() / 8;
  int sizeMax = 30;
  int KeySize = A.GetSize();
  int distKey = 10000;
  int maxBlock = 50;
  for (unsigned int i = 1; i < sizeMax; i++)
    {
      int  blockCount = (maxBlock < bitSize/i)? maxBlock : bitSize / i;
      vector<string> sub_string;
      vector<int> dist;

      for (unsigned int j = 0; j < blockCount; j++)
        sub_string.push_back(inside_A.substr(j * i * 8, i*8));

      for (unsigned int j = 0; j < blockCount; j++)
        {
           for (unsigned int k = j + 1; k < blockCount; k++)
             {
                 dist.push_back(HammerDist(sub_string[j],sub_string[k]));
             }
        }
      double  average_dist = 0;
      for (unsigned int j = 0; j < dist.size(); j++)
        average_dist += dist[j];

      average_dist /=(i * dist.size());

      if ( distKey > average_dist)
        {
          distKey = average_dist;
          KeySize = i;
        }
    }
  return KeySize;
}


string BreakSingleBitXor(Number A)
{
  Number key = most_probable_string(A).second;
  return Xor(A,key).GetChar();
}


string BreakRepeatingXor(Number A)
{
  int keysize =  FindKeySize(A);

  cout << "Keysize = " << keysize <<endl;
  vector<Number> sub_strings = A.GetSubNumber(keysize);
  string key = "";
  for (unsigned int i = 0 ; i < keysize; i++)
    {
      Number temp = most_probable_string(sub_strings[i]).second;
      key += temp.GetBin();
      Number output = Xor(sub_strings[i],temp);
    };

  Number KEY("bin", key);
  cout << KEY.GetChar() <<endl;
  return Xor(A,KEY).GetChar();

}
