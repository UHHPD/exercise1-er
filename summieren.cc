#include <fstream>
#include <iostream>


int main() 
{
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme.txt");
  int a, b, c;
  for(int i = 0; i<234; ++i) 
  {
  fin >> a >> b;
  c=a+b;
  fout << c << std::endl;
  }
/*  
  while(! fin.eof()) 
  {
    fin >> a >> b;
    c = a + b;
    // std::cout << "Die Summe aus " << a << " und " << b << " ist " << c << std::endl;
    fout << c << std::endl;
  }
  */
  fin.close();
  fout.close();
}

