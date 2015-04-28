#include "number_.h"
#include "tools.h"
#include <fstream>

using namespace std;




int main()
{


  // 1er challenge
  string input = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  string ref = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

  Number chal1("hex", input);
  if (chal1.GetB64() == ref)
    cout << "Challenge 1 : Ok"<<endl;



  // 2eme challenge
  string
    input2_1 = "1c0111001f010100061a024b53535009181c",
    input2_2 = "686974207468652062756c6c277320657965",
    ref2 = "746865206b696420646f6e277420706c6179";

  Number chal2("hex", input2_1);
  Number input2("hex", input2_2);
  Number answer2 = Xor(chal2, input2);

  if (answer2.GetHex() == ref2)
    cout << "Challenge 2 : Ok" <<endl;



  // 3eme challenge
  string
    input3 = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b37360";
  Number chal3("hex",input3);

  cout << "Challenge 3 : my answer = " << BreakSingleBitXor(chal3) << endl;


  
  // 4eme challenge
  string line;
  ifstream fichier("chal4.txt", ios::in);
  Number chal4_best;
  double bestscore = 1000;
  int i = 0 ;
  while (getline (fichier,line))
    {
      Number chal4("hex",line);
      pair<double,Number> output = most_probable_string(chal4);
      if (output.first < bestscore)
        {
          bestscore = output.first;
          chal4_best = Xor(chal4,output.second);
        }
    }
  cout << "Challenge 4 : my answer = " << chal4_best.GetChar() <<endl;

  

  // 5eme challenge
  Number ICE("char", "ICE");
  Number chal5("char", "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal");
  string ref5 = "0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f";
  Number answer5 = Xor(chal5,ICE);
  if ( answer5.GetHex() == ref5)
    cout << "Challenge 5 : Ok" <<endl;



  // 6eme challenge
  Number chal6_1("char","this is a test");
  Number chal6_2("char","wokka wokka!!!");
 
  if (HammerDist(chal6_1, chal6_2) == 37)
    cout << "Challenge 6 : test Ok" <<endl;

  ifstream fichier2("chal6.txt", ios::in);
  string inside = "";
  while (getline (fichier2,line))
    {
      inside += line;
    }

  Number chal6_main("B64",inside);
  Number mykey("char","Terminator X  Bring the noise");
  cout << BreakRepeatingXor(chal6_main)<<endl;
  return 0;
}


