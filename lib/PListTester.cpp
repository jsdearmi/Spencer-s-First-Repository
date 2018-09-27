#include <stdio.h>
#include "PList.h"


int main(){
  List l;
  char* somestring = (char*)"haaaaa";
  char* anotherstring = (char*)"leeeee";
  char* laststring = (char*)"luuuuuu";
  char* onemorestring = (char*)"yahhhhhh";
  //std::string
  sItem le(anotherstring);
  sItem lu(laststring);
  sItem ya(onemorestring);
  sItem something(somestring);
  iItem one(1);
  iItem two(2);
  dItem doub(47.34);
  dItem linklist(4.1);


  l.append(&something);
  l.append(&one);
  l.append(&le);
  l.append(&two);
  l.append(&lu);
  l.append(&doub);
  l.append(&ya);
  l.get(0);
  l.get(1);
  l.get(3);
  l.append(&linklist);
  l.get(2);
  l.get(9);
  l.get(4);
  l.get(6);

  return 0;
}
