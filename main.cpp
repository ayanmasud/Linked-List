#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include <iomanip>

using namespace std;

Node* add(Node* head, Node* current, Node* added);
void print(Node* next);
Node* del(Node* head, Node* current, int id);
void average(Node* next, float sum);

int length = 0;
int main() {
  cout << "'ADD' to add a student" << endl; // information as to what you can do
  cout << "'PRINT' to print students" << endl;
  cout << "'DELETE' to delete a student" << endl;
  cout << "'AVERAGE' to find the average GPA" << endl;
  cout << "'QUIT' to leave" << endl;
  
  Node* head = NULL;
  
  while (true)
  {
    char cmd[8];
    cin.getline(cmd, 8); // get the command from the player
    
    if (strcmp(cmd, "ADD") == 0) { // adds a student
      Student* student = new Student(); // adds a new struct Student to modify
      Node* current = new Node(student);
      
      cout << "First Name: "; // gets the users input
      cin >> student->fname;
      cout << "Last Name: ";
      cin >> student->lname;
      cout << "Student ID: ";
      cin >> student->id;
      cout << "GPA: ";
      cin >> student->gpa;
      
      head = add(head, head, current);
      length++;
    }
    else if (strcmp(cmd, "PRINT") == 0) { // print the students in the list
      print(head);
    }
    else if (strcmp(cmd, "DELETE") == 0) { // delete a student
      int iderase = -1;
      cout << "Enter the ID of the person to delete: ";
      cin >> iderase;

      if (length == 1 && iderase == head->getStudent()->id) {
	head = NULL;
      }
      else {
	head = del(head, head, iderase);
      }
      length--;
    }
    else if (strcmp(cmd, "AVERAGE") == 0) { // calculate the average gpa
      average(head, 0);
    }
    else if (strcmp(cmd, "QUIT") == 0) { // quit
      cout << endl << "Cya!" << endl;
      break;
    }
    cout << endl;
  }
  
  Student* s1 = new Student();
  s1->id = 5;
  Student* s2 = new Student();
  s2->id = 8;
  Student* s3 = new Student();
  s3->id = 2;
  Student* s4 = new Student();
  s4->id = 7;
  Student* s5 = new Student();
  s5->id = 9;
  Student* s6 = new Student();
  s6->id = 1;
  
  Node* head1 = new Node(s1);
  Node* head2 = new Node(s2);
  Node* head3 = new Node(s3);
  Node* head4 = new Node(s4);
  Node* head5 = new Node(s5);
  Node* head6 = new Node(s6);

  length++;
  head1 = add(head1, head1, head2);
  length++;
  head1 = add(head1, head1, head3);
  length++;
  head1 = add(head1, head1, head4);
  length++;
  head1 = add(head1, head1, head5);
  length++;
  head1 = add(head1, head1, head6);
  length++;
  
  //print(head1);

  //head1 = del(head1, head1, 5);

  cout << endl;
  //print(head1);
  
  return 0;
}

Node* add(Node* head, Node* current, Node* added) { // add a node to the linked list
  if (length == 0) { // empty list
    return added;
  }
  
  if (added->getStudent()->id > current->getStudent()->id) { // if the new node is bigger than the current
    if (current->getNext() == NULL) {
      current->setNext(added);
      return head;
    }
    else if (added->getStudent()->id < current->getNext()->getStudent()->id) { // if the new node is less than than the currents next node. this is where the new node belongs
      added->setNext(current->getNext());
      current->setNext(added);
      return head;
    }
    else { // new node is greater than currents next so we need to go deeper into the linked list to find its spot
      add(head, current->getNext(), added); // recursion
    }
  } // new node is less than current so it becomes the new head
  else {
    added->setNext(head);
    return added;
  }
  return head;
}

void print(Node* next) { // print the linked list
  if(next != NULL) {
    cout << next->getStudent()->fname << " " << next->getStudent()->lname << ", " << next->getStudent()->id << ", ";
    cout << fixed << setprecision(2) << next->getStudent()->gpa << endl;
    print(next->getNext());
  }
}

Node* newNext = NULL;
Node* del(Node* head, Node* current, int id) {
  if (current->getStudent()->id == id) { // if the head is the one to delete
    current = current->getNext();
    head->~Node();
    return current;
  }
  else {
    if (current->getNext() != NULL) { // not last in the list
      if (current->getNext()->getStudent()->id == id) { // currents next is the one to delete
	newNext = current->getNext()->getNext(); // stores the new next node
	current->getNext()->~Node(); // delete the node to be deleted
	current->setNext(newNext); // fix the linked list order
	return head;
      }
      else { // keep going through the linked list until you find it
	del(head, current->getNext(), id); // recursion
      }
    }
  }
  cout << "Invalid ID" << endl;
  return head;
}

void average(Node* next, float sum) {
  if (next != NULL) {
    sum+=next->getStudent()->gpa;
    average(next->getNext(), sum);
  }
  else {
    float avg = sum/length;
    cout << "GPA average of all students: ";
    cout << fixed << setprecision(2) << avg << endl;
  }
}
