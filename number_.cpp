#include "number_.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
Number::Number(string type, string content)
{
  if (type == "hex")
    {
      m_size = content.size() * 4;
      m_content = "";
      for (unsigned int i = 0; i < content.size(); i++)
        {
          if (content[i] == '0') m_content += ("0000");
          else if (content[i] == '1') m_content += ("0001");
          else if (content[i] == '2') m_content += ("0010");
          else if (content[i] == '3') m_content += ("0011");
          else if (content[i] == '4') m_content += ("0100");
          else if (content[i] == '5') m_content += ("0101");
          else if (content[i] == '6') m_content += ("0110");
          else if (content[i] == '7') m_content += ("0111");
          else if (content[i] == '8') m_content += ("1000");
          else if (content[i] == '9') m_content += ("1001");
          else if (content[i] == 'a') m_content += ("1010");
          else if (content[i] == 'b') m_content += ("1011");
          else if (content[i] == 'c') m_content += ("1100");
          else if (content[i] == 'd') m_content += ("1101");
          else if (content[i] == 'e') m_content += ("1110");
          else if (content[i] == 'f') m_content += ("1111");
        }
    }
  else if (type == "bin")
    {
      m_size = content.size();
      m_content = content;
    }
  else if (type == "B64")
    {
      m_size = content.size() * 6;
      for (unsigned int i = 0; i < content.size(); i++)
        {
          if (content[i] == 'A') m_content += ("000000");
          else if (content[i] == 'R') m_content += ("010001");
          else if (content[i] == 'i') m_content += ("100010");
          else if (content[i] == 'z') m_content += ("110011");
          else if (content[i] == 'B') m_content += ("000001");
          else if (content[i] == 'S') m_content += ("010010");
          else if (content[i] == 'j') m_content += ("100011");
          else if (content[i] == '0') m_content += ("110100");
          else if (content[i] == 'C') m_content += ("000010");
          else if (content[i] == 'T') m_content += ("010011");
          else if (content[i] == 'k') m_content += ("100100");
          else if (content[i] == '1') m_content += ("110101");
          else if (content[i] == 'D') m_content += ("000011");
          else if (content[i] == 'U') m_content += ("010100");
          else if (content[i] == 'l') m_content += ("100101");
          else if (content[i] == '2') m_content += ("110110");
          else if (content[i] == 'E') m_content += ("000100");
          else if (content[i] == 'V') m_content += ("010101");
          else if (content[i] == 'm') m_content += ("100110");
          else if (content[i] == '3') m_content += ("110111");
          else if (content[i] == 'F') m_content += ("000101");
          else if (content[i] == 'W') m_content += ("010110");
          else if (content[i] == 'n') m_content += ("100111");
          else if (content[i] == '4') m_content += ("111000");
          else if (content[i] == 'G') m_content += ("000110");
          else if (content[i] == 'X') m_content += ("010111");
          else if (content[i] == 'o') m_content += ("101000");
          else if (content[i] == '5') m_content += ("111001");
          else if (content[i] == 'H') m_content += ("000111");
          else if (content[i] == 'Y') m_content += ("011000");
          else if (content[i] == 'p') m_content += ("101001");
          else if (content[i] == '6') m_content += ("111010");
          else if (content[i] == 'I') m_content += ("001000");
          else if (content[i] == 'Z') m_content += ("011001");
          else if (content[i] == 'q') m_content += ("101010"); 
          else if (content[i] == '7') m_content += ("111011");
          else if (content[i] == 'J') m_content += ("001001");   
          else if (content[i] == 'a') m_content += ("011010");     
          else if (content[i] == 'r') m_content += ("101011");       
          else if (content[i] == '8') m_content += ("111100");
          else if (content[i] == 'K') m_content += ("001010");   
          else if (content[i] == 'b') m_content += ("011011");     
          else if (content[i] == 's') m_content += ("101100");     
          else if (content[i] == '9') m_content += ("111101");
          else if (content[i] == 'L') m_content += ("001011");  
          else if (content[i] == 'c') m_content += ("011100");    
          else if (content[i] == 't') m_content += ("101101");     
          else if (content[i] == '+') m_content += ("111110");
          else if (content[i] == 'M') m_content += ("001100");   
          else if (content[i] == 'd') m_content += ("011101");    
          else if (content[i] == 'u') m_content += ("101110");     
          else if (content[i] == '/') m_content += ("111111");
          else if (content[i] == 'N') m_content += ("001101"); 
          else if (content[i] == 'e') m_content += ("011110");    
          else if (content[i] == 'v') m_content += ("101111");
          else if (content[i] == 'O') m_content += ("001110");  
          else if (content[i] == 'f') m_content += ("011111");    
          else if (content[i] == 'w') m_content += ("110000");    
          else if (content[i] == 'P') m_content += ("001111");    
          else if (content[i] == 'g') m_content += ("100000");  
          else if (content[i] == 'x') m_content += ("110001");
          else if (content[i] == 'Q') m_content += ("010000");     
          else if (content[i] == 'h') m_content += ("100001");   
          else if (content[i] == 'y') m_content += ("110010");
        }
    }
  else if (type == "char")
    {
      m_size = content.size() * 8;
      for (unsigned int i = 0; i < content.size(); i++)
        {
          int buff = content[i];
          bitset<8> buffer(buff);
          m_content += buffer.to_string();
        }
    }

}


string Number::GetHex()
{
  string output = "";
  int size = (m_size%4 == 0)? m_size: m_size - m_size%4;
  for (unsigned int i = 0; i < size; i+=4)
    {
      if (m_content.substr(i, 4) == "0000") output += "0";
      if (m_content.substr(i, 4) == "0001") output += "1";
      if (m_content.substr(i, 4) == "0010") output += "2";
      if (m_content.substr(i, 4) == "0011") output += "3";
      if (m_content.substr(i, 4) == "0100") output += "4";
      if (m_content.substr(i, 4) == "0101") output += "5";
      if (m_content.substr(i, 4) == "0110") output += "6";
      if (m_content.substr(i, 4) == "0111") output += "7";
      if (m_content.substr(i, 4) == "1000") output += "8";
      if (m_content.substr(i, 4) == "1001") output += "9";
      if (m_content.substr(i, 4) == "1010") output += "a";
      if (m_content.substr(i, 4) == "1011") output += "b";
      if (m_content.substr(i, 4) == "1100") output += "c";
      if (m_content.substr(i, 4) == "1101") output += "d";
      if (m_content.substr(i, 4) == "1110") output += "e";
      if (m_content.substr(i, 4) == "1111") output += "f";
    }
  return output;
}

string bin_to_char(string input)
{

  string output;
  if (input == "01000001")      output = "A";
  else if (input == "01000010") output = "B";
  else if (input == "01000011") output = "C";
  else if (input == "01000100") output = "D";
  else if (input == "01000101") output = "E";
  else if (input == "01000110") output = "F";
  else if (input == "01000111") output = "G";
  else if (input == "01001000") output = "H";
  else if (input == "01001001") output = "I";
  else if (input == "01001010") output = "J";
  else if (input == "01001011") output = "K";
  else if (input == "01001100") output = "L";
  else if (input == "01001101") output = "M";
  else if (input == "01001110") output = "N";
  else if (input == "01001111") output = "O";
  else if (input == "01010000") output = "P";
  else if (input == "01010001") output = "Q";
  else if (input == "01010010") output = "R";
  else if (input == "01010011") output = "S";
  else if (input == "01010100") output = "T";
  else if (input == "01010101") output = "U";
  else if (input == "01010110") output = "V";
  else if (input == "01010111") output = "W";
  else if (input == "01011000") output = "X";
  else if (input == "01011001") output = "Y";
  else if (input == "01011010") output = "Z";
  else if (input == "01100001") output = "a";
  else if (input == "01100010") output = "b";
  else if (input == "01100011") output = "c";
  else if (input == "01100100") output = "d";
  else if (input == "01100101") output = "e";
  else if (input == "01100110") output = "f";
  else if (input == "01100111") output = "g";
  else if (input == "01101000") output = "h";
  else if (input == "01101001") output = "i";
  else if (input == "01101010") output = "j";
  else if (input == "01101011") output = "k";
  else if (input == "01101100") output = "l";
  else if (input == "01101101") output = "m";
  else if (input == "01101110") output = "n";
  else if (input == "01101111") output = "o";
  else if (input == "01110000") output = "p";
  else if (input == "01110001") output = "q";
  else if (input == "01110010") output = "r";
  else if (input == "01110011") output = "s";
  else if (input == "01110100") output = "t";
  else if (input == "01110101") output = "u";
  else if (input == "01110110") output = "v";
  else if (input == "01110111") output = "w";
  else if (input == "01111000") output = "x";
  else if (input == "01111001") output = "y";
  else if (input == "01111010") output = "z";
  else if (input == "00110000") output = "0";
  else if (input == "00110001") output = "1";
  else if (input == "00110010") output = "2";
  else if (input == "00110011") output = "3";
  else if (input == "00110100") output = "4";
  else if (input == "00110101") output = "5";
  else if (input == "00110110") output = "6";
  else if (input == "00110111") output = "7";
  else if (input == "00111000") output = "8";
  else if (input == "00111001") output = "9";
  else if (input == "00100111") output = "'";
  else output = " ";

 return output;



}

string Number::GetChar()
{
  string output = "";
  int size = (m_size%8 == 0)? m_size: m_size - m_size%8;
  for (unsigned int i = 0; i < size; i+=8)
    {
     string extrait =  m_content.substr(i, 8);
     output += bin_to_char(extrait);
    }

  return output;
}

string Number::GetBin()
{
  return m_content;
}

string Number::GetB64()
{
  string output = "";
  int size = (m_size%6 == 0)? m_size: (m_size - m_size%6);

  for (unsigned int i = 0; i < size; i+=6)
    {
      if (m_content.substr(i, 6) == "000000") output += "A";
      else if (m_content.substr(i, 6) == "010001") output += "R";
      else if (m_content.substr(i, 6) == "100010") output += "i";
      else if (m_content.substr(i, 6) == "110011") output += "z";
      else if (m_content.substr(i, 6) == "000001") output += "B";
      else if (m_content.substr(i, 6) == "010010") output += "S";
      else if (m_content.substr(i, 6) == "100011") output += "j";
      else if (m_content.substr(i, 6) == "110100") output += "0";
      else if (m_content.substr(i, 6) == "000010") output += "C";
      else if (m_content.substr(i, 6) == "010011") output += "T";
      else if (m_content.substr(i, 6) == "100100") output += "k";
      else if (m_content.substr(i, 6) == "110101") output += "1";
      else if (m_content.substr(i, 6) == "000011") output += "D";
      else if (m_content.substr(i, 6) == "010100") output += "U";
      else if (m_content.substr(i, 6) == "100101") output += "l";
      else if (m_content.substr(i, 6) == "110110") output += "2";
      else if (m_content.substr(i, 6) == "000100") output += "E";
      else if (m_content.substr(i, 6) == "010101") output += "V";
      else if (m_content.substr(i, 6) == "100110") output += "m";
      else if (m_content.substr(i, 6) == "110111") output += "3";
      else if (m_content.substr(i, 6) == "000101") output += "F";
      else if (m_content.substr(i, 6) == "010110") output += "W";
      else if (m_content.substr(i, 6) == "100111") output += "n";
      else if (m_content.substr(i, 6) == "111000") output += "4";
      else if (m_content.substr(i, 6) == "000110") output += "G";
      else if (m_content.substr(i, 6) == "010111") output += "X";
      else if (m_content.substr(i, 6) == "101000") output += "o";
      else if (m_content.substr(i, 6) == "111001") output += "5";
      else if (m_content.substr(i, 6) == "000111") output += "H";
      else if (m_content.substr(i, 6) == "011000") output += "Y";
      else if (m_content.substr(i, 6) == "101001") output += "p";
      else if (m_content.substr(i, 6) == "111010") output += "6";
      else if (m_content.substr(i, 6) == "001000") output += "I";
      else if (m_content.substr(i, 6) == "011001") output += "Z";
      else if (m_content.substr(i, 6) == "101010") output += "q"; 
      else if (m_content.substr(i, 6) == "111011") output += "7";
      else if (m_content.substr(i, 6) == "001001") output += "J";   
      else if (m_content.substr(i, 6) == "011010") output += "a";     
      else if (m_content.substr(i, 6) == "101011") output += "r";       
      else if (m_content.substr(i, 6) == "111100") output += "8";
      else if (m_content.substr(i, 6) == "001010") output += "K";   
      else if (m_content.substr(i, 6) == "011011") output += "b";     
      else if (m_content.substr(i, 6) == "101100") output += "s";     
      else if (m_content.substr(i, 6) == "111101") output += "9";
      else if (m_content.substr(i, 6) == "001011") output += "L";  
      else if (m_content.substr(i, 6) == "011100") output += "c";    
      else if (m_content.substr(i, 6) == "101101") output += "t";     
      else if (m_content.substr(i, 6) == "111110") output += "+";
      else if (m_content.substr(i, 6) == "001100") output += "M";   
      else if (m_content.substr(i, 6) == "011101") output += "d";    
      else if (m_content.substr(i, 6) == "101110") output += "u";     
      else if (m_content.substr(i, 6) == "111111") output += "/";
      else if (m_content.substr(i, 6) == "001101") output += "N"; 
      else if (m_content.substr(i, 6) == "011110") output += "e";    
      else if (m_content.substr(i, 6) == "101111") output += "v";
      else if (m_content.substr(i, 6) == "001110") output += "O";  
      else if (m_content.substr(i, 6) == "011111") output += "f";    
      else if (m_content.substr(i, 6) == "110000") output += "w";    
      else if (m_content.substr(i, 6) == "001111") output += "P";    
      else if (m_content.substr(i, 6) == "100000") output += "g";  
      else if (m_content.substr(i, 6) == "110001") output += "x";
      else if (m_content.substr(i, 6) == "010000") output += "Q";     
      else if (m_content.substr(i, 6) == "100001") output += "h";   
      else if (m_content.substr(i, 6) == "110010") output += "y";
    }
  return output;
}


void Number::Xor(Number A)
{
  string newcontent = "";
  if (m_size < A.m_size)
    return;
  if (m_size == A.m_size)
    {
      for (unsigned int i = 0 ; i < m_size; i++)
        {
          if (m_content[i] == A.m_content[i])
            newcontent += "0";
          else
            newcontent += "1";
        }
    }
  else
    {
      int iterator = 0;
      for (unsigned int i=0; i < m_size; i++)
        {
          if (m_content[i] == A.m_content[iterator])
            newcontent += "0";
          else
            newcontent += "1";
          iterator++;
          if (iterator >= A.m_size)
            iterator=0;
        }
    }
  m_content = newcontent;
}


int Number::HammerDist(Number A)
{
  int dist=0;
  if (m_size != A.m_size)
    return 0;
  for (unsigned int i = 0 ; i < m_size; i++)
    {
      if (m_content[i] != A.m_content[i])
        dist++;
    }
  return dist;
}


vector<int> Number::FindKeysize()
{
  vector<int> distances;
  int max_size = 40;
  for (unsigned int i = 0; i < max_size ; i++)
    {
      string extract1 = m_content.substr(0, i);
      string extract2 = m_content.substr(i, i);
      Number
        test1 ("bin", extract1),
        test2 ("bin", extract2);
      int dist = test1.HammerDist(test2);
      distances.push_back(dist);
    }
  for(unsigned int i = 0 ; i < distances.size() ; i++)
    cout << "lol " << distances[i] <<endl;
}
