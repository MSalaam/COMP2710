/**
 *
 * small program to calculate monthly interest rate
 * Porject 1
 * @author  MOHAMAD SALAAM (MZS0171@auburn.edu)
 * @version 29/01/21
 * g++ project1_salaam_mzs0171.cpp
 * ./a.out
 * written in JGrasp
 * Sources: Hints file, test cases 
 * + help from github for C++ syntax since only know java
 */

#include <iostream>
#include <iomanip>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main() {

   // for format
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   double loan;
   double interest;
   double payments;
   int month = 0;
   double total = 0;

   // enter loan amount and non-negative

   do {
      cout << "Loan Amount: ";
      cin >> loan;
      if (loan <= 0) {
         cout << "Please enter a positive amount." << endl;
      }
   }
   while (loan <= 0);

   // enter interest amount and non-negative
   do {
      cout << "Interest Rate (% per year): "; 
      cin >> interest;
      if (interest <= 0) {
         cout << "Please enter a positive amount." << endl;
      }
   }
   while (interest <= 0);


   // enter payment and non-negativ
   double interestRate = interest/12/100;

   do {
      
      cout << "Monthly Payments: "; 
      cin >> payments;
      if (payments <= (loan*interestRate)){
         cout << "please enter a larger amount" << endl;
      }
   }
   while (payments < (loan*interestRate));


   // table
   cout << endl;
   cout << "*****************************************************************\n"
      << "\tAmortization Table\n" 
      << "*****************************************************************\n"  
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 

   // for calucations and format

   while (loan > 0)
   {
   
      if (month == 0) {
         cout << month++ << "\t$" << loan;
      
         if (loan < 1000) cout << "\t";
         cout << "  N/A\t\tN/A\tN/A\t\tN/A\n";
      }
      else {
      
         double interestPayment = loan*interestRate;
         double principal = payments - interestPayment;
      
         loan -= principal;
         total += interestPayment;
      
         if (loan < 0) {
            principal += loan;
            payments += loan;
            loan = 0;
         }
      
         cout << month++ << "\t\t$" << loan;
      
         if (loan < 1000) cout << "\t";
      
         cout << "  $" << payments << "\t" << interestRate*100 << "\t$"
            << interestPayment << "\t\t$" << principal << "\n";
      }
   }

   // ending text
   cout << "****************************************************************\n";
   cout << "\nIt takes " << --month << " months to pay off the loan.";
   cout << "\nTotal interest paid is: $" << total;
   cout << endl;

}
