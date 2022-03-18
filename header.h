#pragma once

struct Node {
  int data;
  Node *next;
  Node *prev;
};

void insertEnd(Node*& head, int val);
void insertBegin(Node*& head, int val);
void insertAfter(Node*& head, int val, int afterVal);
void display(Node* head);