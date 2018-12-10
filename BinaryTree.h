#ifndef BINARY_TREE
#define BINARY_TREE
#include <vector>

typedef struct node
{
  int value;

  struct node *left,*right;
}Node;


class BinaryTree
{
  Node *root;

  void insert(Node*,int);
  Node* remove(Node*,int value);
  Node* cut(Node*,int);
  void printPostorder(Node*);
  void printInorder(Node*);
  void printPreorder(Node*);
  Node* searchMin(Node*);
  Node* searchMax(Node*);
  Node* search(Node*,int value);
  void toArray(Node*,std::vector<Node*>*);
  Node* arrayToBST(std::vector<Node*>*,int,int);
public:
  BinaryTree();
  void insert(int);
  void remove(int value);
  void cut(int value);
  void printPostorder();
  void printInorder();
  void printPreorder();
  void balance();
  int searchMin();
  int searchMax();
  int search(int);

};

#endif
