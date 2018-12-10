#include "BinaryTree.h"
#include <stdlib.h>
#include <stdio.h>

BinaryTree::BinaryTree()
{
 root=NULL;
}


void BinaryTree::insert(Node* node,int value)
{
  if(value<node->value)
  {
    if(node->left==NULL)
     {
       node->left=new Node;
       node->left->value=value;
       node->left->left=node->left->right=NULL;
     }
    else
      insert(node->left,value);
  }

  if(value>node->value)
  {
    if(node->right==NULL)
    {
      node->right=new Node;
      node->right->value=value;
      node->right->left=node->right->right=NULL;
    }
    else
      insert(node->right,value);
  }

}

void BinaryTree::insert(int value)
{
  if(root==NULL)
  {
    root=new Node;
    root->value=value;
    root->left=NULL;
    root->right=NULL;
  }
  else
   insert(root,value);
}

Node* BinaryTree::remove(Node* node,int value)
{
   if(node==NULL) return NULL;
   if(value<node->value)
     node->left=remove(node->left,value);
   else if(value>node->value)
     node->right=remove(node->right,value);
   else
   {
     if(node->left==NULL)
     {
       Node *temp=node->right;
       delete node;
       return temp;
     }
     if(node->right==NULL)
     {
       Node *temp=node->left;
       delete node;
       return temp;
     }
    Node* temp=searchMin(node->right);
    node->value=temp->value;
    node->right=remove(node->right,temp->value);

   }

}

void BinaryTree::remove(int value)
{
  root=remove(root,value);
}

Node* BinaryTree::cut(Node* node,int value)
{
  if(node==NULL) return NULL;
  if(value<node->value)
    node->left=cut(node->left,value);
  else if(value>node->value)
    node->right=cut(node->right,value);
  else
  {
    delete node;
    return NULL;
  }
}

void BinaryTree::cut(int value)
{

  root=cut(root,value);

}


void BinaryTree::printPostorder(Node* node)
{
  if(node==NULL) return;
  printPostorder(node->left);
  printPostorder(node->right);
  printf("%d ",node->value);
}


void BinaryTree::printPostorder()
{
  printPostorder(root);
}

void BinaryTree::printInorder(Node* node)
{
  if(node==NULL) return;
  printInorder(node->left);
  printf("%d ",node->value);
  printInorder(node->right);
}

void BinaryTree::printInorder()
{
  printInorder(root);
}

void BinaryTree::printPreorder(Node* node)
{
  if(node==NULL) return;
  printf("%d ",node->value);
  printPreorder(node->left);
  printPreorder(node->right);
}

void BinaryTree::printPreorder()
{
  printPreorder(root);
}

Node* BinaryTree::searchMin(Node* node)
{
  if(node->left==NULL) return node;
  else
  searchMin(node->left);
}

int BinaryTree::searchMin()
{
  return searchMin(root)->value;
}

Node* BinaryTree::searchMax(Node* node)
{
  if(node->right==NULL) return node;
  else
  searchMax(node->right);
}

int BinaryTree::searchMax()
{
  return searchMax(root)->value;
}

Node* BinaryTree::search(Node* node,int value)
{
 if(node->value<value)
  search(node->right,value);
 else if(node->value>value)
  search(node->left,value);
 else
  return node;
}

int BinaryTree::search(int value)
{
  return search(root,value)->value;
}

void BinaryTree::toArray(Node* node,std::vector<Node*> *array)
{
  if(node==NULL) return;
  toArray(node->left,array);
  (*array).push_back(node);
  toArray(node->right,array);
}

Node* BinaryTree::arrayToBST(std::vector<Node*> *array,int low,int high)
{
  if(low>high) return NULL;
  int mid=(low+high)/2;
  Node *temp=(*array).at(mid);
  temp->left=arrayToBST(array,low,mid-1);
  temp->right=arrayToBST(array,mid+1,high);
  return temp;

}

void BinaryTree::balance()
{
  std::vector<Node*> array;
  toArray(root,&array);
  root=arrayToBST(&array,0,array.size()-1);
}
