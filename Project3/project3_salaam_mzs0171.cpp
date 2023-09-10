/**
 *
 * input/output + sorting
 * Project 3
 * @author  MOHAMAD SALAAM (MZS0171@auburn.edu)
 * @version 03/05/21
 * g++ project3_salaam_mzs0171.cpp
 * ./a.out
 * written in JGrasp
 * Sources: project 3 file + hints
 * + help from github for C++ syntax 
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Functions to check file, write file, read file, sort

bool check_file(string);
void write_file(string, vector<int>);
void to_string(vector<int>);
vector<int> merge(vector<int>, vector<int>);
vector<int> read_file(string);


// Main 
int main() {

	// Variables

   string file1;
   string file2;
   string file3;
   vector<int> numbers1;
   vector<int> numbers2;
   vector<int> numbers3;

   cout << "*** Welcome to Moe's sorting program ***" << endl;

	// First input
   do {
      cout << "Enter the first input file name: ";
      cin >> file1;
   } while (cin.fail() || !check_file(file1));

   numbers1 = read_file(file1);
   cout << "The list of " << numbers1.size()
       << " numbers in the file " + file1 + " is:\n";
   to_string(numbers1);

	// Second input

   do {
      cout << "Enter the second input file name: ";
      cin >> file2;
   } while (cin.fail() || !check_file(file2));

   numbers2 = read_file(file2);
   cout << "The list of " << numbers2.size()
       << " numbers in file " + file2 + " is:\n";
   to_string(numbers2);

   numbers3 = merge(numbers1, numbers2);
   cout << "The sorted list of " << numbers3.size() << " numbers is: ";
   
   for (unsigned int i=0; i < numbers3.size(); i++) {
      cout << numbers3.at(i) << " ";
   }
   cout << endl;

	// Output file

   do {
      cout << "Enter the output file name: ";
      cin >> file3;
   } while (cin.fail());

   write_file(file3, numbers3);

   cout << "*** Please check the new file - " + file3 + " ***" << endl
       << "*** Goodbye. ***";

   return 0;
}

// Functions

// Check for file
bool check_file(string file) {
   ifstream stream;

// check if file exists
   stream.open(file.c_str());
   if (stream.fail()) {
      stream.close();
      return false;
   }
   stream.close();

   return true;
}

// Add to output file
vector<int> read_file(string file) {
   ifstream stream;
   vector<int> v;
   int i;

   stream.open(file.c_str());
   while (stream >> i) {
      v.insert(v.end(), i);
   }
   stream.close();

   return v;
}


// Sorting function
vector<int> merge(vector<int> v1, vector<int> v2) {
   vector<int> v3;

   v3 = v1;
   v3.insert(v3.end(), v2.begin(), v2.end());
   sort(v3.begin(), v3.end());

   return v3;
}

// Printing the numbers
void to_string(vector<int> v) {
   for (unsigned int i=0; i < v.size(); i++) {
      cout << v.at(i) << endl;
   }
   cout << endl;
}

   // Output file
void write_file(string file, vector<int> v) {
   ofstream stream;

   stream.open(file.c_str());
   for (unsigned int i=0; i < v.size(); i++) {
      stream << v.at(i) << endl;
   }
   stream.close();
}