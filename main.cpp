#include "BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <string.h>
#include <sstream>
#include <fstream>

main()
{
  BinaryTree Tree;
  std::string input,command;
  int value,result;
  std::chrono::duration<double> time;
  std::fstream file;
  Node *newNode=new Node;

  file.open("dat.txt");
   if (!file)
   {
    std::cout << "Unable to open file";
    exit(1);
   }
  while(file>>newNode->value)
  {
    file>>newNode->name;
    file>>newNode->stat[0];
    file>>newNode->stat[1];
    file>>newNode->stat[2];
    Tree.insert(newNode);
  }
  file.close();


while(1)
{
  system("cls");
  std::cout<<"Preorder: ";
  Tree.printPreorder();
  std::cout<<"\nInorder: ";
  Tree.printInorder();
  std::cout<<"\nPostorder: ";
  Tree.printPostorder();
  std::cout<<"\nLast command execution time: "<<time.count();
  std::cout<<"         Result: "<<result;
  std::cout<<"\nType cmd:";
  std::getline(std::cin,input);

  std::istringstream inStream(input);
  inStream >> command;
  inStream >> value;
  if(command.compare("insert")==0)
    {
      newNode->value=value;
      std::cout<<"\nName:";
      std::cin>>newNode->name;
      getchar();
      std::cout<<"\nStats str dex int:";
      std::getline(std::cin,input);
      std::istringstream inStream(input);
      inStream>>newNode->stat[0];
      inStream>>newNode->stat[1];
      inStream>>newNode->stat[2];
      auto  start=std::chrono::high_resolution_clock::now();
      Tree.insert(newNode);
      auto  finish=std::chrono::high_resolution_clock::now();
      time=finish-start;
    }
  if(command.compare("delete")==0)
    {
      auto  start=std::chrono::high_resolution_clock::now();
      Tree.remove(value);
      auto  finish=std::chrono::high_resolution_clock::now();
      time=finish-start;
    }
  if(command.compare("cut")==0)
    {
      auto  start=std::chrono::high_resolution_clock::now();
      Tree.cut(value);
      auto  finish=std::chrono::high_resolution_clock::now();
      time=finish-start;
    }
  if(command.compare("read")==0)
    {
      Tree.read(value);
      getchar();
    }
  if(command.compare("balance")==0)
    {
      auto  start=std::chrono::high_resolution_clock::now();
      Tree.balance();
      auto  finish=std::chrono::high_resolution_clock::now();
      time=finish-start;
    }
  if(command.compare("searchMin")==0)
    {
      auto  start=std::chrono::high_resolution_clock::now();
      result=Tree.searchMin();
      auto  finish=std::chrono::high_resolution_clock::now();
      time=finish-start;
    }
  if(command.compare("searchMax")==0)
    {
      auto  start=std::chrono::high_resolution_clock::now();
      result=Tree.searchMax();
      auto  finish=std::chrono::high_resolution_clock::now();
      time=finish-start;
    }
  if(command.compare("search")==0)
    {
      auto  start=std::chrono::high_resolution_clock::now();
      result=Tree.search(value);
      auto  finish=std::chrono::high_resolution_clock::now();
      time=finish-start;
    }
  if(command.compare("exit")==0) break;

}

}
