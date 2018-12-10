#include "BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sstream>
#include <fstream>

main()
{
  BinaryTree Tree;
  std::string input,command;
  int value,result;
  double time;
  clock_t start,finish;
  std::fstream file;

  file.open("dat.txt");
   if (!file)
   {
    std::cout << "Unable to open file";
    exit(1);
   }
  while(file>>value)
  {
    Tree.insert(value);
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
  std::cout<<"\nLast command execution time: "<<std::fixed<<time;
  std::cout<<"         Result: "<<result;
  std::cout<<"\nType cmd:";
  std::getline(std::cin,input);

  std::istringstream inStream(input);
  inStream >> command;
  inStream >> value;
  if(command.compare("insert")==0)
    {
      start=clock();
      Tree.insert(value);
      finish=clock();
      time=(double)((start-finish)/CLOCKS_PER_SEC);
    }
  if(command.compare("delete")==0)
    {
      start=clock();
      Tree.remove(value);
      finish=clock();
      time=(double)((start-finish)/CLOCKS_PER_SEC);
    }
  if(command.compare("cut")==0)
    {
      start=clock();
      Tree.cut(value);
      finish=clock();
      time=(double)((start-finish)/CLOCKS_PER_SEC);
    }
  if(command.compare("balance")==0)
    {
      start=clock();
      Tree.balance();
      finish=clock();
      time=(double)((start-finish)/CLOCKS_PER_SEC);
    }
  if(command.compare("searchMin")==0)
    {
      start=clock();
      result=Tree.searchMin();
      finish=clock();
      time=(double)((start-finish)/CLOCKS_PER_SEC);
    }
  if(command.compare("searchMax")==0)
    {
      start=clock();
      result=Tree.searchMax();
      finish=clock();
      time=(double)((start-finish)/CLOCKS_PER_SEC);
    }
  if(command.compare("search")==0)
    {
      start=clock();
      result=Tree.search(value);
      finish=clock();
      time=(double)((start-finish)/CLOCKS_PER_SEC);
    }
  if(command.compare("exit")==0) break;

}

}
