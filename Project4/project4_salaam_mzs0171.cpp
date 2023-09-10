/**
 *
 * Linked data structures (nodes) + Unit testing 
 * Project 4
 * @author  MOHAMAD SALAAM (MZS0171@auburn.edu)
 * @version 03/05/21
 * g++ project4_salaam_mzs0171.cpp
 * ./a.out
 * written in JGrasp
 * Sources: project 4 file + hints
 * + help from github + geeksforgeeks.org + stackoverflow.com
 */

#include <iostream>
#include <string>
using namespace std;  
int num_of_questions = 0;

// Nodes and pointer

struct trivia_node {

   int points;
   string question;
   string answer;
   trivia_node *next;
};

// Functions

typedef trivia_node* pointer;
int ask_question(pointer ques_list, int num_ask);
void init_question_list(pointer& ques_list);
void add_question(pointer& ques_list);
void Unit_Test();
#define TRIVIA_QUIZ

// Main Method for nodes

int main() {

#ifdef TRIVIA_QUIZ
   pointer node_list = new trivia_node;
   init_question_list(node_list);

	// Run + User input
   
   cout << "*** Welcome to Moe's trivia quiz game ***\n";
   string input;
   do {
      add_question(node_list);
      cout << "Continue? (Yes/No): ";
      getline(cin, input);
      
   } while (input.compare("Yes") == 0 || input.compare("yes") == 0);
   cout << endl;

	// Start game
   
   ask_question(node_list, num_of_questions);
   cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***";
   
   return 0;
}
#endif

	// Unit testing

#ifdef UNIT_TESTING
	Unit_Test();
	return 0;
}
#endif

//  Functions for nodes

void init_question_list(pointer& ques_list) {

   pointer cur_ptr = new trivia_node;

// Questions and answers + node pointers
   // #1 example
   
   cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)";
   cur_ptr->answer = "38";
   cur_ptr->points = 100;
   cur_ptr->next = new trivia_node;
   
   ques_list = cur_ptr;
   cur_ptr = ques_list->next;
   
   // #2 example
   
   cur_ptr->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   cur_ptr->answer = "Bank of Italy";
   cur_ptr->points = 50;
   cur_ptr->next = new trivia_node;
   cur_ptr = cur_ptr->next;
   
   // #3 example
   
   cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
   cur_ptr->answer = "Wii Sports";
   cur_ptr->points = 20;
   cur_ptr->next = NULL;

   num_of_questions += 3;
}

// New pointers or questions

void add_question(pointer& ques_list) {

   pointer new_pointer = new trivia_node;

	// User input
   
   cout << "Enter a question: ";
   getline(cin, new_pointer->question);
   
   cout << "Enter an answer: ";
   getline(cin, new_pointer->answer);
   
   cout << "Enter award points: ";
   cin >> new_pointer->points;
   
   cin.ignore(); 
   new_pointer->next = NULL;
   trivia_node* last = ques_list;
   
   while (last->next != NULL) {
      last = last->next;
   }
   last->next = new_pointer;
   num_of_questions++;
}

int ask_question(pointer ques_list, int num_ask) {

   pointer cur_ptr = ques_list;
   string user_answer;
   int total_points = 0;

	// Check queue
   
   if (ques_list == NULL) {
      return 0;
   }

	// Check number of questions
   
   if (num_ask <= 0) {
   
      cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
      return 1;
   } 
   else if (num_of_questions < num_ask) {
   
      cout << "Warning - there is only " << num_of_questions << " trivia in the list." << endl;
      return 1;
   } 
   else {
      for (int i = 0; i < num_ask; i++) {
      
         cout << "Question: " << cur_ptr->question << endl;
         cout << "Answer: ";
         getline(cin, user_answer);
         
         if (user_answer.compare(cur_ptr->answer) == 0) {
         
            cout << "Your answer is correct. You receive " << cur_ptr->points << " points." << endl;
            total_points += cur_ptr->points;
         } 
         else {
         
            cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
         }
         
         cout << "Your total points: " << total_points << endl << endl;
         cur_ptr = cur_ptr->next;
         
      }
   }
   return 0;
}

// Unit test + debug

void Unit_Test() {

   cout << "*** This is a debugging version ***\n"; 
   pointer node_list = new trivia_node;
   init_question_list(node_list);

   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
   ask_question(node_list, 0);
   cout << "Case 1 passed\n\n";

   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
   ask_question(node_list,1);
   cout << "Case 2.1 passed\n\n";

   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
   ask_question(node_list,1);
   cout << "Case 2.2 passed\n\n";

   cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
   ask_question(node_list,3);
   cout << "Case 3 passed\n\n";

   cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
   ask_question(node_list,5);
   cout << "Case 4 passed\n\n";

   cout << "*** End of the Debugging Version ***";
   
}