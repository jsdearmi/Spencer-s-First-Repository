#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


class StringArrayList {
private:
  int arraysize;
  int arraytail;
  int listhead;
  int listtail;
  const char** List; //array pointing to const char* to string
  int IsEmpty(); // returns 1 if the list is empty
  void ShiftListLeft(); //used for when we remove the head
  void BiggerArray(); //if the list outgrows the array add 10 to array



public:
  void push_back(const char*);
  void get(int);
  void length();
  void remove_front();
  StringArrayList();
  ~StringArrayList();
};

StringArrayList::StringArrayList(){ //constructor
    arraysize = 10;
    List = (const char**)malloc(sizeof(const char*)*arraysize);
    arraytail = arraysize - 1;
    listhead = listtail = -1;

}

StringArrayList::~StringArrayList(){ // destructor
  free(List);
}

void StringArrayList::push_back(const char* thing){
  if (IsEmpty() == 1){ //list is empty
    listhead = 0;
    listtail = 0;
  }
  else if(listtail == arraytail){
    BiggerArray();
    listtail += 1;
  }
  else {listtail += 1;}
  List[listtail] = thing;

}

int StringArrayList::IsEmpty(){
  if(listhead == -1){
    return 1;
  }
  else return 0;
}

void StringArrayList::get(int n){
  if((IsEmpty() == 0) && (n <= listtail)){
    printf("The item at index %d is %s\n", n, List[n]);
  }
  else if(IsEmpty() == 1){
    printf("The list is empty\n");
  }
  else{
    printf("The list is not empty, but he given index, %d, does not exists\n", n);
  }
}

void StringArrayList::length(){
  printf("The length of the list is %d\n", (listtail+1));
}

void StringArrayList::BiggerArray(){
  const char** tmplist;
  tmplist = List;
  arraysize += 10;
  List = (const char**)malloc(sizeof(const char*)*arraysize);
  List = tmplist;
  arraytail = arraysize - 1;

}

void StringArrayList::ShiftListLeft(){
  int i=0;
  const char* tempthing;
  for(i=0;i<(listtail);i++){
    tempthing=List[i+1];
    List[i] = tempthing;
  }
  listtail -= 1; //decrement listtail to show the shift
}

void StringArrayList::remove_front(){
  if(IsEmpty()==1){ //check if list is empty
    printf("List is already empty\n");
  }
  else if(listtail == 0){ //one item in the list
    List[listhead] = NULL;
    listhead = -1;
    listtail = -1;
    printf("List is only had 1 item and is now empty\n");
  }
  else{
  const char* tmp = List[listhead];
  List[listhead] = NULL;
  ShiftListLeft();
  printf("%s has been removed\n", tmp);
  }

}

int main(){

StringArrayList l;
char a[10] = "milk";
l.get(0);
l.push_back("10");
l.push_back("20");
l.push_back("30");
l.push_back("40");
l.push_back("50");
l.push_back("60");
l.push_back("70");
l.push_back("80");
l.push_back("90");
l.push_back("100");
l.push_back("110");
l.push_back("120");
l.push_back("130");
l.push_back("140");
l.push_back("150");
l.push_back("160");
l.push_back("170");
l.push_back("180");
l.push_back("190");
l.push_back("200");
l.push_back("210");
l.push_back(a);
l.remove_front();
l.length();
l.get(0);
l.get(20);
l.get(19);
l.remove_front();
l.length();
printf("working");
/*
StringArrayList l;
char a[10] = "10";
char b[10] = "20";
char c[10] = "30";
char d[10] = "40";
char e[10] = "50";
char f[10] = "60";
char g[10] = "70";
char h[10] = "80";
char i[10] = "90";
char j[10] = "100";
char k[10] = "110";
char m[10] = "130";
char n[10] = "140";
char o[10] = "150";
char p[10] = "160";
char q[10] = "170";
char r[10] = "180";
char s[10] = "190";
char t[10] = "200";
char u[10] = "210";
char v[10] = "220";
*
l.push_back(a);
l.push_back(b);
l.push_back(c);
l.push_back(d);
l.push_back(e);
l.push_back(f);
l.push_back(g);
l.push_back(h);
l.push_back(i);
l.push_back(g);
l.push_back(j);
l.push_back(k);
l.push_back(m);
l.push_back(n);
l.push_back(o);
l.push_back(p);
l.push_back(q);
l.push_back(r);
l.push_back(s);
l.push_back(t);
l.push_back(u);
l.push_back(v);
l.length();
l.remove_front();
l.get(0);
l.get(30);
l.get(22);
l.get(21);
l.get(20);
*/
  return 0;
}
