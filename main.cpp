#include <bits/stdc++.h>
#include "header.h"
using namespace std;

int main() {
  Planet *p = 0;
  insertEnd(p, "one");
  insertEnd(p, "two");
  insertEnd(p, "three");
  insertEnd(p, "four");
  insertEnd(p, "five");
  insertEnd(p, "six");
  insertAtLocation(p, "intruder", 0);
  display(p);
  return 0;
}