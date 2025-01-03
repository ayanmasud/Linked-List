#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

class Node {
 public:
  Node* next; // next node
  Student* student; // student in this node
  
  Node(Student* newstudent);
  Node* getNext();
  void setNext(Node* newnext);
  Student* getStudent();
  ~Node();
};
