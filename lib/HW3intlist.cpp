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
  int* List; //array pointing to char* to string
  int IsEmpty(); // returns 1 if the list is empty
  void ShiftListLeft(); //used for when we remove the head
  void BiggerArray(); //if the list outgrows the array add 10 to array



public:
  void push_back(int);
  void get(int);
  void length();
  void remove_front();
  StringArrayList();
  ~StringArrayList();
};

StringArrayList::StringArrayList(){ //constructor
    arraysize = 10;
    List = (int*)malloc(sizeof(int)*arraysize);
    arraytail = arraysize - 1;
    listhead = listtail = -1; // denotes an empty list
    printf("the list has been constructed\n");
}

StringArrayList::~StringArrayList(){ // destructor
  free(List);
  printf("the list has been destroyed\n");
}

void StringArrayList::push_back(int thing){
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
  printf("%d thing has been added to the list\n", thing);

}

int StringArrayList::IsEmpty(){
  if(listhead == -1){
    return 1;
  }
  else return 0;
}

void StringArrayList::get(int n){
  if((IsEmpty() == 0) && (n <= listtail)){
    printf("The item at index %d is %d\n", n, List[n]);
  }
  else if(IsEmpty() == 1){
    printf("The list is empty\n");
  }
  else{
    printf("The list is not empty, but the given index, %d, does not exist\n", n);
  }
}

void StringArrayList::length(){
  printf("The length of the list is %d\n", (listtail+1));
}

void StringArrayList::BiggerArray(){
  int* tmplist;
  tmplist = List;
  arraysize += 10;
  List = (int*)malloc(sizeof(int)*arraysize);
  List = tmplist;
  arraytail = arraysize - 1;
  printf("array has added 10\n");

}

void StringArrayList::ShiftListLeft(){
  int i=0;
  int tempthing;
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
    List[listhead] = 0;
    listhead = -1;
    listtail = -1;
    printf("List is only had 1 item and is now empty\n");
  }
  else{
  int tmp = List[listhead];
  List[listhead] = 0;
  ShiftListLeft();
  printf("%d has been removed\n", tmp);
  }

}

int main(){
/*
StringArrayList l;
l.get(0);
l.push_back(10);
l.push_back(20);
l.push_back(30);
l.push_back(40);
l.push_back(50);
l.push_back(60);
l.push_back(70);
l.push_back(80);
l.push_back(90);
l.push_back(100);
l.push_back(110);
l.push_back(120);
l.push_back(130);
l.push_back(140);
l.push_back(150);
l.push_back(160);
l.push_back(170);
l.push_back(180);
l.push_back(190);
l.push_back(200);
l.push_back(210);
l.remove_front();
l.length();
l.get(0);
l.get(20);
l.get(19);
l.remove_front();
l.length();
*/

  return 0;
}
