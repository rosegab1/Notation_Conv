#ifndef NOTATIONCONVERTER_H
#define NOTATIONCONVERTER_H
#include "NotationConverterInterface.hpp"
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

typedef string Elem;

typedef struct node{
        string ch;
        node* next;
        node* prev;
        }* nodePtr;

class NotationConverter : public NotationConverterInterface
{
  nodePtr head;
  nodePtr rear;

public:
  NotationConverter();

  bool empty() const; 
  const Elem& front() const; 
  const Elem& back() const; 
  void insertFront(string e); 
  void insertBack(string e); 
  void removeFront();
  void removeBack(); 
  void clearDeque();

  int precedence(string op);
  void invalid_char(string inStr);

  string postfixToInfix(string inStr);
  string postfixToPrefix(string inStr);
  string infixToPostfix(string inStr);

  string infixToPrefix(string inStr);
  string prefixToInfix(string inStr);
  string prefixToPostfix(string inStr);    
};

#endif /* NOTATIONCONVERTER_H */