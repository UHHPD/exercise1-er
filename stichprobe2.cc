#include <iostream>
#include <fstream>
#include <cmath>

int main(){

std::ifstream fin("datensumme.txt");
std::ifstream fin2("datensumme.txt");
std::ofstream fout("mittelwerte.txt");
std::ofstream fout2("varianzen.txt");
int a;
double n=9;
int sum=0;
double sum2=0;
double mean=0;

for(int i=0; i<26; ++i){

int sum =0;
double sum2=0;

    for(int j=0; j<9; ++j){
        fin >> a;
        sum += a;
    }
    mean = 1/n * sum;

    //*std::cout<<mean<<std::endl;

    
    fout << mean <<std::endl;

    for(int k=0; k<9;++k){
        fin2 >> a;
        sum2 += pow((a-mean),2);
    }

    double var = 1/n * sum2;
  //*  std::cout<<var<<std::endl;
    
    fout2 << var << std::endl;    

}  

fin.close();
fin2.close();
fout.close();
fout2.close();

std::ifstream fin3("mittelwerte.txt");
std::ifstream fin4("varianzen.txt");

double sum3=0;
double mean3=0;
double sum4=0;
double var4=0;
double N =26;
double b;

for(int i=0; i<N; ++i){
    fin3>>b;
    sum3+=b;
   //* std::cout<<sum3<<std::endl;

}
mean3=1/N * sum3;
std::cout<<"Mittelwert:"<<mean3<<std::endl;
//std::cout<<"Korrigierter Mittelwert:"<<N/(N-1)*mean3<<std::endl;

for(int j=0; j<N;j++){
    fin4>>b;
    sum4 += pow((mean3-b),2);
  //*  std::cout<<sum4<<std::endl;
}
var4 = 1/N * sum4;
std::cout<<"Varianz:"<<var4<<std::endl;
// std::cout<<"Korrigierte Varianz:"<<N/(N-1)*var4<<std::endl;

fin3.close();
fin4.close();
}
