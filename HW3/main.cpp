#pragma once
#include "rand.h"
#include "schet.h"
#include "inout.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

string user_name;
int attempts_count;

int main() {
	cout << "Hi! Enter your name, please:" <<endl;
	cin >> user_name;
	cout<<"Enter you guess"<<endl;
		rand();
		schet();
	attempts_count=schet()+1;
		inout();
}
