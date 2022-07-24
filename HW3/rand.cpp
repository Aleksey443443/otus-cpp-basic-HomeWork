#include "rand.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
 	using namespace std;
 int rando(){
	srand(time(nullptr));
const int z=rand()%10;
return z;
 }