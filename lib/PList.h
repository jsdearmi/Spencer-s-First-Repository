// PList header file
// contains objects declarations
// Linked List
// List should support strings integers and double values

class Item{
public:
  virtual void print(){printf("Base\n");};
};

  class sItem: public Item{
  public:
    const char* str;
    sItem(const char* astr = ""){ // item with string constructor
      str = astr;
    }
    void print() {printf("%s\n",str); }
  };
  class iItem: public Item{
  public:
    int x;
    iItem(int ax = 0){ // item with int constructor
      x = ax;
    }
    void print() {printf("%d\n",x); }
  };
  class dItem: public Item{
  public:
    double d;
    dItem(double ad = 0.0){ // item with double constructor
      d = ad;
    }
    void print() {printf("%lf\n",d);}
  };


class List {
private:

// ListNode represents each
// node of the list
  class ListNode {
  public:
    Item* item; // data in the list
    ListNode *next;
  public:
    ListNode(Item* a, ListNode *n=NULL)
    {
      item = a;
      next=n; // automatically serves as a list tail
    }

    ListNode* getNext()
    {
      return next;
    }
    void setNext(ListNode *n)
    {
      next = n;
    }
    Item getItem()
    {
      return *item;
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

public: //contains iterator class

  class iterator {
  private:
    ListNode *node;

  public:
    iterator(ListNode *n=NULL) { node = n; }
    Item getItem() { return node->getItem(); }
    void increment() { node = node->next; }
    bool end() { return node==NULL; }

    friend class List;
  };

public:
  List();
  void append(Item* a);
  bool remove(Item &a);
  bool empty();
  void get(int x);


  iterator begin()
  {
    return iterator(head);
  }

  void removeAfter(iterator it); // pseudocode in zyBook 2.4
  void insertAfter(iterator it, Item item);


};

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void List::append(Item* a)
{
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else
    {
      tail->setNext(node);
      tail = node;
    }
}

bool List::remove(Item &copy)
{
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool List::empty()
{
  return head==NULL;
}

void List::insertAfter(List::iterator it, Item item) // pseudocode in zyBook 2.3
{
    if (it.node==NULL)
      { // special case to insert at the head
	// point new node at current head of list
	ListNode *node = new ListNode(&item,head);
	if (head==NULL) { // if head was NULL, tail was also NULL
	  tail = node;   // new node is now the tail
	  head = node;   // new node is now the head
	} else {
	  head = node;   // update head to new node
	}
      }
    else // insert after it
      {
	ListNode *node = new ListNode(&item,it.node->getNext());
	it.node->setNext(node);
	if (tail==it.node) tail = node;
      }
}

void List::removeAfter(List::iterator it) // pseudocode in zyBook 2.4
{
   if (it.node==NULL) // special case to remove head, it’s not after any node
     {
       ListNode *remove = head;               // will remove the head
       head = head->getNext();      // advance head
       if (head==NULL) tail = NULL; // if head is NULL now, list is empty
       delete remove;               // delete removed node
     }
   else // normal case, if not the head, then simply disconnect the node
     {
       ListNode *tmp = it.node;
       ListNode *remove = tmp->getNext(); // next node to be removed
       tmp->setNext(remove->getNext());   // point around node to be removed
       if (tail==remove) tail = tmp;      // if removing tail, update tail
       delete remove; // delete node      // delete the removed node
     }
}

void List::get(int x){
  //needs implementation
  //printf("get() is being called");
  ListNode *tmp = head;
  ListNode *headtmp = head;
  int k;
  for(k=0; k<=x; k++){ //not at the end of List
    if (x == k){
      printf("The item at index %d is: \n", x);
      head->item->print();
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
