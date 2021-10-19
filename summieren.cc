#include <fstream>
#include <iostream>


int main() 
{
  std::ifstream fin("daten.txt");
  std::ofstream fout("datensumme.txt");
  int a, b, c;
  while(! fin.eof()) 
  {
    fin >> a >> b;
    c = a + b;
    // std::cout << "Die Summe aus " << a << " und " << b << " ist " << c << std::endl;
    fout << c << std::endl;
  }
  fin.close();
  fout.close();
}

