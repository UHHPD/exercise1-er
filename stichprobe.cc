#include <fstream>
#include <iostream>
#include <cmath>

int main() 
{
  std::ifstream fin("datensumme.txt");
  double count, sum=0, avg, var, stdev;
  for(int i = 0; i<234; ++i) 
  {
    fin >> count;
    sum += count;
  }
  avg = sum / 234;
  std::cout << "Die Summe aus allen Zahlen ist: " << sum << std::endl;
  std::cout << "Damit erhält man einen Mittelwert von " << avg << std::endl;
  fin.close();

  sum=0;
  std::ifstream fin2("datensumme.txt");
  for(int i = 0; i<234; ++i) 
  {
    fin2 >> count;
    sum += (count-avg)*(count-avg);
    std::cout << count << " " << sum << std::endl;
  }
  var = sum / 234;
  std::cout << "Man erhält eine Varianz von: " << var << "..." <<std::endl;
  stdev = sqrt(var);
  std::cout << "...womit sich eine Standardabweichung von " << stdev << " ergibt!" << std::endl;
}