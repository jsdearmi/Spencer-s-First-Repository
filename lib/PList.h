// PList header file
// contains objects declarations
// Linked List
// List should support strings integers and double values

class Item{
public:
  virtual void print();
};

  class sItem: public Item{
  public:
    const char* str;
    sItem(const char* astr = "");
    void print();
  };
  class iItem: public Item{
  public:
    int x;
    iItem(int ax = 0);
    void print();
  };
  class dItem: public Item{
  public:
    double d;
    dItem(double ad = 0.0);
    void print();
  };


class List {
private:

// ListNode represents each
// node of the list
class ListNode {
private:
  Item* item; // data in the list
  ListNode *next;
public:
  //ListNode(Item *a, ListNode *n)
  ListNode(Item *a, ListNode *n=NULL)
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
  friend class List;
};

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

public: //contains iterator class

  class iterator {
  private:
    ListNode *node;

  public:
    iterator(ListNode *n) { node = n; }
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


  iterator begin();

  void removeAfter(iterator it);
  void insertAfter(iterator it, Item item);


};
