#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct node
{
  int value;
  struct node *left,*right;
}Node;


class BinaryTree
{
  Node *root;
public:
  BinaryTree();
  BinaryTree(int);
  void insert(int value);
  void insert(Node*,int value);
  void remove(int value);
  Node* remove(Node*,int value);
  void printPostorder();
  void printPostorder(Node*);
  void printInorder();
  void printInorder(Node*);
  void printPreorder();
  void printPreorder(Node*);
  int searchMin();
  Node* searchMin(Node*);
  int searchMax();
  Node* searchMax(Node*);
  int search(int);
  Node* search(Node*,int value);

};

#endif
