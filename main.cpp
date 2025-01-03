#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include <iomanip>

using namespace std;

//vector<Node*> sort(vector<Node*> &current, int size, bool newSort);
Node* sort(Node* head);
void print(Node* n);

int main() {
  /*Student* ayan = new Student(); // create student 1
  strcpy(ayan->name, "Ayan"); // set student 1 name

  Student* ehan = new Student(); // create student 2
  strcpy(ehan->name, "Ehan"); // set student 2 name
  
  Node* head = new Node(ayan); // first node carries student 1
  Node* head2 = new Node(ehan); // second node carries student 2
  
  head->setNext(head2); // next node in first node is second node
  
  cout << head->getNext()->getStudent()->name << endl; // obtain the name of student 2 using the first node

  head->~Node();
  head2->~Node();

  cout << "Didn't abort";*/

  cout << "a";
  
  Student* s1 = new Student();
  s1->id = 5;
  Student* s2 = new Student();
  s2->id = 8;
  Student* s3 = new Student();
  s3->id = 2;
  Student* s4 = new Student();
  s4->id = 7;

  Node* head1 = new Node(s1);
  Node* head2 = new Node(s2);
  Node* head3 = new Node(s3);
  Node* head4 = new Node(s4);

  head1->setNext(head2);
  head2->setNext(head3);
  head3->setNext(head4);

  vector<Node*> list;
  list.push_back(head1);
  list.push_back(head2);
  list.push_back(head3);
  list.push_back(head4);


  cout << endl;

  print(head1);
  
  cout << endl << "1";

  
  Node* newHead = sort(head1);
  cout << "2" << endl;

  print(newHead);
  
  cout << endl;
  
  return 0;
}

Node* sort(Node* head) {
  Node* newHead = nullptr;  // New sorted linked list head
  Node* current = nullptr; // Pointer to traverse the original list

  while (head != nullptr) {
    Node* prevMax = nullptr;
    Node* maxNode = head;
    Node* prev = nullptr;
    current = head;

    // Find the node with the largest id in the list
    while (current->getNext() != nullptr) {
      if (current->getNext()->getStudent()->id > maxNode->getStudent()->id) {
        prevMax = current;
        maxNode = current->getNext();
      }
      current = current->getNext();
    }

    // Remove maxNode from the original list
    if (prevMax != nullptr) {
      prevMax->setNext(maxNode->getNext());
    } else {
      head = head->getNext();
    }

    // Insert maxNode at the start of the new sorted list
    maxNode->setNext(newHead);
    newHead = maxNode;
  }

  return newHead;
}

/*vector<Node*> newlist;
vector<Node*> sort(vector<Node*> &current, int size, bool newSort) {
  vector<Node*> changelist = current;
  cout << "in";
  if (newSort == true) {
    newSort = false;
    newlist.clear();
    sort(changelist, size, false);
  }
  else if (size != 0) {
    vector<Node*>::iterator it;
    int smallest = 100;
    Student* carrying = new Student();
    Node* carryingNode = new Node(carrying);
    
    for (it = changelist.begin(); it < changelist.end(); it++) {
      if ((*it)->getStudent()->id < smallest) {
	smallest = (*it)->getStudent()->id;
	carrying = (*it)->getStudent();
	carryingNode = (*it);
      }
      
    }
    cout << "small:" << smallest;
    newlist.push_back(carryingNode);

    for (it = changelist.begin(); it < changelist.end(); it++) { // remove that one we pushed into newlist from current
      if ((*it)->getStudent()->id == smallest) {
	cout << "erased" << (*it)->getStudent()->id;
	(*it)->~Node();
	changelist.erase(it);
      }
    }

    size-=1;
    size-=1;
    sort(current, size, false); // this is giving problems, might have something to do with the vector size in the if statment. maybe use an index number to keep track instead
  }
  
  return newlist;
}
*/
void print(Node* n) {
  if (n->getNext() != NULL) {
    print(n->getNext());
  }
  cout << n->getStudent()->id;
}
