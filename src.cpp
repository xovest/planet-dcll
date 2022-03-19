#include <iostream>
#include "header.h"
using namespace std;

void insertEnd(Planet*& head, string val) {
  if (head == NULL) {
    Planet* newPlanet = new Planet;
    newPlanet->name = val;
    newPlanet->next = newPlanet->prev = newPlanet;

    head = newPlanet;
  } else {
    Planet* tail = head->prev;

    Planet* newPlanet = new Planet;
    newPlanet->name = val;

    newPlanet->next = head;
    head->prev = newPlanet;
    newPlanet->prev = tail;
    tail->next = newPlanet;
  }
}

void insertBegin(Planet*& head, string val) {
  Planet* tail = head->prev;

  Planet* newPlanet = new Planet;
  newPlanet->name = val;

  newPlanet->next = head;
  newPlanet->prev = tail;

  tail->next = head->prev = newPlanet;

  head = newPlanet;
}

void insertAfter(Planet*& head, string val, string afterVal) {
  Planet* newPlanet = new Planet;
  newPlanet->name = val;

  Planet* temp = head;
  while (temp->name != afterVal) temp = temp->next;
  Planet* next = temp->next;

  temp->next = newPlanet;
  newPlanet->prev = temp;
  newPlanet->next = next;
  next->prev = newPlanet;
}

void display(Planet* head) {
  Planet* temp = head;

  while (temp->next != head) {
    cout << temp->name << " ";
    temp = temp->next;
  }
  cout << temp->name << "\n";

  // Planet *tail = head->prev;
  // while (temp->prev != tail) {
  //   cout << temp->name << " ";
  //   temp = temp->prev;
  // }
  // cout << temp->name << "\n";
}

void deletePlanet(Planet*& head, string val) {
  if (head == NULL) return;

  Planet* curr = head;
  Planet* prev = NULL;
  while (curr->name != val) {
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
    Planet* temp = curr->next;
    prev->next = temp;
    temp->prev = prev;
    free(curr);
  }
}