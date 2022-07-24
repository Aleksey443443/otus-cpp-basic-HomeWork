#include "schet.h"
#include "rand.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
int a=rando();
int b;	
int i=0;
int schet(){
for(;b!=a;i++){
 cin>>b;
 if(b<a)
 	cout<<"more"<<endl;
 else  if(b>a)
 	cout<<"to much"<<endl;
 else 
 	cout<<"you win! IT Was "<<a<<" You made "<<i+1<<"  try"<<endl;;
};
return i;
 }