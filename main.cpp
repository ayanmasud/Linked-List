#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include <iomanip>

using namespace std;

Node* add(Node* head, Node* current, Node* added);
void print(Node* next);
Node* del(Node* head, Node* current, int id);

int main() {

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
  
  head1 = add(head1, head1, head2);
  head1 = add(head1, head1, head3);
  head1 = add(head1, head1, head4);
  head1 = add(head1, head1, head5);
  head1 = add(head1, head1, head6);
  
  print(head1);

  head1 = del(head1, head1, 5);

  cout << endl;
  print(head1);
  
  return 0;
}

Node* add(Node* head, Node* current, Node* added) { // add a node to the linked list
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
    cout << next->getStudent()->id << " ";
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
  return head;
}
