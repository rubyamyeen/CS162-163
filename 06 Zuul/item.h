//blueprint for item
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Item {
  char description[20];
public:
  //constructor
  Item(char* newDescription);
  char* getDescription();

};

#endif
