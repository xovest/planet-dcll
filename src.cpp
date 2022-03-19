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

  // Node *tail = head->prev;
  // cout << "Reverse: ";
  // while (temp->prev != tail) {
  //   cout << temp->data << " ";
  //   temp = temp->prev;
  // }
  // cout << temp->data << "\n";
}

void deleteNode(Node*& head, int val) {
  if (head == NULL) return;

  Node* curr = head;
  Node* prev = NULL;
  while (curr->data != val) {
    if (curr->next == head) {
      cout << "List has no " << val << " in it";
      return;
    }

    prev = curr;
    curr = curr->next;
  }

  if (curr->next == head && prev == NULL) {
    head = NULL;
    free(curr);
    return;
  }

  if (curr == head) {
    prev = head->prev;
    head = head->next;
    prev->next = head;
    head->prev = prev;
    free(curr);
  } else if (curr->next == head) {
    prev->next = head;
    head->prev = prev;
    free(curr);
  } else {
    Node* temp = curr->next;
    prev->next = temp;
    temp->prev = prev;
    free(curr);
  }
}