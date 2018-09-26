#include <stdio.h>
#include "PList.h"
#include <string.h>
int main(){
  List l;
  char* somestring = (char*)"milk";
  //std::string
  sItem something(somestring);
  iItem one(1);
  iItem two(2);
  dItem doub(47.34);
  l.append(&something);
  l.append(&one);
  l.append(&two);
  l.append(&doub);
  l.get(0);
  l.get(1);
  l.get(3);
  l.get(2);

  return 0;
}
