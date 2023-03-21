#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include<glm/glm.hpp>
#include<vector>
#include<tuple>
#include<iostream>

using namespace std;

#define n 1000
#define m 3
#define A 0.0
#define B 40.0

#define a 10.0
#define b 28.0
#define c 2.666  


vector<tuple<double,double,double>> r(n);

double f1(double x, double y);
double f2(double x,double y, double z);
double f3(double x,double y,double z);

void solve(vector<tuple<double,double,double>>& r);
void plot();

int main()
{
  
  solve(r);
  //plot();


  return 0;
}


void solve(vector<tuple<double,double,double>>& r){

  vector<double> x(n), y(n), z(n);
  
  const double h = (B-A)/n;

  double k11,k12,k13,k21,k22,k23,k31,k32,k33,k41,k42,k43;

  x[0] = 1, y[0] = 1, z[0] = 1;

  for(int i = 0;i<n;i++){
    
    k11 = h * f1(x[i],y[i]);
    k12 = h * f2(x[i],y[i],z[i]);
    k13 = h * f3(x[i],y[i],z[i]);

    k21 = h * f1(x[i] + k11/2, y[i] + k12/2);
    k22 = h * f2(x[i] + k11/2,y[i] + k12/2, z[i] + k13/2);
    k23 = h * f3(x[i] + k11/2,y[i] + k12/2, z[i] + k13/2);
    
    k31 = h * f1(x[i] + k21/2, y[i] + k22/2);
    k32 = h * f2(x[i] + k21/2, y[i] + k22/2,z[i] + k23/2);
    k33 = h * f3(x[i] + k21/2, y[i] + k22/2,z[i] + k23/2);

    k41 = h * f1(x[i] + k31,y[i] + k32);
    k42 = h * f2(x[i] + k31, y[i] + k32, z[i] + k33);    
    k43 = h * f3(x[i] + k31, y[i] + k32, z[i] + k33);

    x[i+1] = x[i] + (k11 + 2 * k21 + 2 * k31 + k41) / 6;
    y[i+1] = y[i] + (k12 + 2 * k22 + 2 * k32 + k42) / 6;
    z[i+1] = z[i] + (k13 + 2 * k23 + 2 * k33 + k43) / 6;
    cout << x[i] << "," << y[i] << "," << z[i] << endl;

  }

  for(int i = 0; i < n; i++){
    r[i] = make_tuple(x[i],y[i],z[i]);
  } 
}

double f1(double x, double y){
  
  return a*(y - x);
}

double f2(double x,double y,double z){

  return x * (b - z) - y;
}

double f3(double x, double y, double z){
  
  return x*y - c*z;
}

void plot()
{

  char title[] = "Lorenz Attractor Simulation";

  if(!glfwInit())
    throw "Could not initialize GLFW\n";
  
  GLFWwindow* window;
  window = glfwCreateWindow(1280,720,title,NULL,NULL);

  if(window == NULL){
    throw "Could not create window\n";
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);
  

  //wait for user to press a key
  
  glfwSetInputMode(window,GLFW_STICKY_KEYS,1);

  do{
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  while( glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );

}
