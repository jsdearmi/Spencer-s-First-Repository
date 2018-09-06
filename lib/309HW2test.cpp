#include <stdio.h>

int number = 0; //global variable holds number of items in the list
class Item {
public:
  const char * str;
  Item(const char *as = "")
  {
    str = as;
  }
};

class List {
private:

// ListNode represents each
// node of the list
  class ListNode {
  private:
    Item item; // data in the list
    ListNode *next;
  public:
    ListNode(Item a)
    {
      item = a;
      next=NULL; // automatically serves as a list tail
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
      return item;
    }
    /*void getIndex() {
      return index;
    }*/
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;


public:
  List();
  void push_back(Item a);
  bool remove_front(Item &a);
  bool empty();
  int length();
};

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void List::push_back(Item a)
{
  number += 1;
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

bool List::remove_front(Item &copy)
{
  if (!empty()) // if list is not empty
    {
      number -= 1;
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

  int List::length()
  {
    printf("The length of the list is %d\n",number);
    return 1;
  }


int main()
{
  List l;

  l.push_back(Item("milk"));
  l.push_back(Item("eggs"));
  l.push_back(Item("bread"));
  l.push_back(Item("potato chips"));
  l.push_back(Item("toothpaste"));

  l.length();

  while(!l.empty())
    {
      Item copy;
      l.remove_front(copy);

      printf("Next thing removed: %s\n",copy.str);
      l.length();
    }



  return 0;
} // still need to implement get(n)
