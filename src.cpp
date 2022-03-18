#include <iostream>
#include "header.h"
using namespace std;

void insertEnd(Node*& head, int val) {
  if (head == NULL) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = newNode->prev = newNode;

    head = newNode;
  } else {
    Node* tail = head->prev;

    Node* newNode = new Node;
    newNode->data = val;

    newNode->next = head;
    head->prev = newNode;
    newNode->prev = tail;
    tail->next = newNode;
  }
}

void insertBegin(Node*& head, int val) {
  Node* tail = head->prev;

  Node* newNode = new Node;
  newNode->data = val;

  newNode->next = head;
  newNode->prev = tail;

  tail->next = head->prev = newNode;

  head = newNode;
}

void insertAfter(Node*& head, int val, int afterVal) {
  Node* newNode = new Node;
  newNode->data = val;

  Node* temp = head;
  while (temp->data != afterVal) temp = temp->next;
  Node* next = temp->next;

  temp->next = newNode;
  newNode->prev = temp;
  newNode->next = next;
  next->prev = newNode;
}

void display(Node* head) {
  Node* temp = head;

  cout << "Forward: ";
  while (temp->next != head) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << temp->data << "\n";

  Node *tail = head->prev;
  cout << "Reverse: ";
  while (temp->prev != tail) {
    cout << temp->data << " ";
    temp = temp->prev;
  }
  cout << temp->data << "\n";
}