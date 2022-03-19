#pragma once

struct Node {
  int data;
  Node *next;
  Node *prev;
};

void insertEnd(Node*& head, int val);
void insertBegin(Node*& head, int val);
void insertAfter(Node*& head, int val, int afterVal);
void deleteNode(Node*& head, int pos);
void display(Node* head);

//now we need to delete some, insert by position and goof around to see if we actually got something out of here