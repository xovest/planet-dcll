#include <iostream>
#include "header.h"
using namespace std;

int main() {
  Node* head = NULL;
  insertEnd(head, 2);
  insertBegin(head, 1);
  insertEnd(head, 4);
  insertEnd(head, 9);
  insertAfter(head, 7, 4);
  display(head);
  return 0;
}