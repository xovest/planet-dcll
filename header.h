#pragma once

struct Planet {
  std::string name;
  Planet *next;
  Planet *prev;
};

void insertEnd(Planet*& head, std::string name);
void insertBegin(Planet*& head, std::string name);
void insertAfter(Planet*& head, std::string name, std::string afterVal);
void deletePlanet(Planet*& head, int pos);
void display(Planet* head);

//now we need to delete some, insert by position and goof around to see if we actually got something out of here