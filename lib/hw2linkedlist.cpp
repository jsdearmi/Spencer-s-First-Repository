//Title
 //Spencer Dearmin
 /*
 Description
 */

 #include <stdio.h>
 #include <math.h>
 #include <string.h>

//Item represesnts a string for the name of an item
class Item {
public:
  const char* str;
  Item(const char *astr = ""){
    str = astr;
  }
};

 class List {
 private:
   //ListNode represents each item in the List
   class ListNode {
   public:
     Item item; //data in the List
     ListNode *next;

   public:
     ListNode(Item a){
       item = a;
       next = NULL;
     }
     ListNode* getNext(){
       return next;
     }
     void setNext(ListNode *n){
       next = n;
     }
     Item getItem(){
       return item;
     }
   };
   //add head and tail pointer
   ListNode *head;
   ListNode *tail;
 public:
   List();
   ~List();
   void push_back(Item a); //append to the end of List
   bool remove_front(Item &a); //remove from the FRONT of the List
   bool empty(); //check if list is empty
   void length(); //get the number of items in the list
   void get(int n);
 };

//first need to initialze the list to be empty
List::List(){
  //constructor function
  //there's nothing in the List
  head = NULL;
  tail = NULL;
}

List::~List(){
  //list class destructor
  //free all of the nodes from the List
  Item t;
  while(!empty()){ //while the List is not empty
    remove_front(t);
  }
}

void List::push_back(Item a){
  ListNode *node = new ListNode(a);
  if (head == NULL){ //if the list is empty set head and tail to be node
    head = node;
    tail = node;
    // this results in 1 single item in the list
  } else { //otherwise put the new node at the end of the list
    tail->setNext(node);
    tail = node;
  }
}

bool List::remove_front(Item &copy){
  if(!empty()){ // if the list is NOT empty
    copy = head->getItem(); //return copy of head of the List
    ListNode *temp = head->getNext();
    delete head; //delete the current list head
    head = temp; //update new head to the temp
    // check to see if removed the last head
    if (temp==NULL){ //then we removed the last element
      tail = NULL; //then set tail to NULL
    }
    return true;
  }
  return false; //returns false if the list was empty
}

bool List::empty(){
  //if the head = NULL then we know the list is empty
  return head==NULL; //returns a true or false value
}

void List::length(){
  ListNode *tmp = head;
  ListNode *headtmp = head;
  int k=0;
  while(tmp!=NULL){
    tmp = head->getNext();
    head = tmp;
    k++;
  }
  printf("The length of the list is %d\n",k);
  head = headtmp;
  return;
}

void List::get(int x){
  //needs implementation
  ListNode *tmp = head;
  ListNode *headtmp = head;
  int k;
  for(k=0; k<=x; k++){ //not at the end of List
    if (x == k){
      printf("The item at index %d is %s\n",x, head->item.str);
      head = headtmp;
      return;
    }
    else{
      tmp = head->getNext();
      head = tmp;
      if(tmp == NULL) break;
    }
  }
  printf("Index not found\n");
  head = headtmp;
  return;
}

 int main() {


   /*List l;

   l.length();

   l.push_back(Item("milk"));
   l.push_back(Item("eggs"));
   l.push_back(Item("bread"));
   l.get(0);
   l.push_back(Item("potato chips"));

   l.push_back(Item("toothpaste"));
   l.get(1);
   l.get(4);
   l.get(5);

   l.length();

   while(!l.empty())
     {
       Item copy;
       l.remove_front(copy);

       printf("Next thing removed: %s\n",copy.str);
       l.length();
     }*/

 return 0;
 }
