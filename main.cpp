#include <bits/stdc++.h>
#include "header.h"
using namespace std;

int main() {
  //splitting the command
  char command[100];
  cin.get(command, 100);
  char* token = strtok(command, " ");
  string s[10];
  int k = 0;
  while (token != NULL) {
    s[k++] = token;
    token = strtok(NULL, " ");
  }
  return 0;
}