#include<GLFW/glfw3.h>
#include<vector>
#include<tuple>

using namespace std;

#define n 1000
#define A 0
#define B 40


vector<tuple<double,double,double>> r(n);

double f1(const double a,double y, double x);
double f2(const double b,double x,double z, double y);
double f3(const double c,double x,double y,double z);

vector<tuple<double,double,double>> solve();

int main()
{
  return 0;
}


vector<tuple<double,double,double>> solve(){


  




  return r;
}

double f1(const double a, double y, double x){

  return a * (y - x);
}

double f2(const double b, double x,double z,double y){

  return x * (b-z) -y;
}

double f3(const double c, double x, double y, double z){
  
  return x * y - c * z;
}
