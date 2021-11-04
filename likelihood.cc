#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>

int Ntot=234;

using namespace std;
vector<int> daten(Ntot);

/*
Definiere Poisson-Funktion.
Argumente sind Mittelwert mu und Häufigkeit k.
Ausgabe ist Wahrscheinlichkeit, die Häufigkeit k zu beobachten
*/
double poisson(double mu, int k) {
  double prob = pow(mu,k)*exp(-mu)/(tgamma(k+1));
  return prob;
}

/*
Definiere Likelihood-Funktion.
Argumente sind der Mittelwert mu und der Vektor, der das beobachtete Sample enthält.
Ausgabe ist Wahrscheinlichkeit, genau das gegebene Sample bei gegebenem Mittelwert zu beobachten.
Hierzu multipliziert die Funktion die Poisson-Wahrscheinlichkeit für alle Events miteinander.
*/

double prob(std::vector<int> daten, double mu) {
  double sprob = 1;
  for(int k : daten) {
    double kprob = poisson(mu,k);
    sprob *= kprob;
    //std::cout << m << " " << daten[m] <<  " " << k << " " << kprob << " " << sprob << std::endl;
  }
  return sprob;
}

int main() {

ifstream fin("datensumme.txt");
ofstream fout("likelihood.txt");

//Fülle Vektor "daten" mit den Werten aus datensumme.txt
//Die push_back-Funktion hängt den ihr gegebenen Wert an den Vektor an.
int zahl = 0;
for(int i = 0; i < Ntot; i++) {
  fin >> zahl;
  daten[i] = zahl;
  //daten.push_back(zahl);
  //std::cout << zahl << std::endl;
}

fin.close();

/*
for(int m = 0; m < daten.size(); m++) {
    double k = daten[m];
    std::cout << m << " " << daten[m] <<  " " << k << std::endl;
  }
*/

std::cout << prob(daten, 3.11538) << std::endl;

/*
Schreibe die Werte von mu und L(mu) für Werte von mu zwischen 0 und 6 in Intervallen von 0,1 in die Datei likelihood.txt.
L(mu) basiert auf dem beobachteten Sample.
*/

for (int j = 0; j < 61; j++) {
  double mu1 = 0.1 * j;
  double muprob = prob(daten, mu1);
  //Reicht das so als Input für die Funktion prob? Muss die ganze Vektordefinition angegeben werden?
  fout << mu1 << " " << muprob << std::endl;
}

fout.close();

ofstream fout2("nll.txt");

/*
Schreibe die Werte von mu und - 2 ln (L(mu)) für Werte von mu zwischen 0 und 6 in Intervallen von 0,1 in die Datei nll.txt.
L(mu) basiert auf dem beobachteten Sample.
*/

for (int j = 0; j < 61; j++) {
  double mu1 = 0.1 * j;
  double muprob = prob(daten, mu1);
  double nll = - 2 * log(muprob);
  //Reicht das so als Input für die Funktion prob? Muss die ganze Vektordefinition angegeben werden?
  fout2 << mu1 << " " << nll << std::endl;
}



}