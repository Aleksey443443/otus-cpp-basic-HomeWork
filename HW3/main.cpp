#pragma once
#include "rand.h"
#include "schet.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
int main() {
		const std::string high_scores_filename = "111.txt";	
	cout << "Hi! Enter your name, please:" <<endl;
	string user_name;
	cin >> user_name;
	cout<<"Enter you guess"<<endl;
	int attempts_count;
	rand();
	schet();
	attempts_count=schet()+1;
		ofstream out_file{high_scores_filename, ios_base::app};//запись
		out_file << user_name << ' ';
		out_file << attempts_count;
		out_file << endl;// запись
	ifstream in_file{high_scores_filename};
	cout << "High scores table:" << endl;
		string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			//cout<<schet()+1<<"  try"<<endl;
			cout << username << '\t' << high_score << endl;
			}
}
