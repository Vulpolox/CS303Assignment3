//Jack Keys || CompSci303 || Assignment #3

#ifndef EXPRESSION_OBJECT_H
#define EXPRESSION_OBJECT_H

#include <string>
#include <iostream>
#include <stack>
#include <cctype>
#include <vector>
#include <sstream>
#include <cstdlib>

class ExpressionObject 
{

  private:
  
    std::string validOperators = "+-/*%"; //list of valid operators
    std::string leftParentheses = "([{"; //list of valid left parentheses
    std::string rightParentheses = ")]}"; //list of valid right parentheses
    
    std::vector<std::string> currentExpression; //vector to hold infix expression
    std::vector<std::string> postfixExpression; //vector to hold postfix expression
  
  public:
  
    /*Constructor*/
    
      ExpressionObject(); //default constructor
    
    /*Member Functions*/
    
      // pre  -- takes no arguments
      // post -- returns true if currentExpression is balanced; else false
      bool isBalanced();
      
      // pre  -- takes two chars containing parentheses, pl and pr
      // post -- returns true if the parentheses match; else false
      bool isMatchingParentheses(char pl, char pr);
      
      // pre  -- takes a char and a string, toFind and list respectively
      // post -- returns true if toFind is in list; else false
      bool isIn(char toFind, std::string list);
      
      // pre  -- takes a string as a parameter, s
      // post -- returns true if the string is valid in an infix expression
      bool isValidElement(std::string s);
      
      // pre  -- takes no arguments
      // post -- creates a postfix expression based off of the infix expression stored in currentExpression
      void createPostfixExpression();
      
      // pre  -- takes no arguments
      // post -- creates a valid infix expression from user input and stores it in currentExpression
      void setExpression();
      
      // pre  -- takes no arguments
      // post -- overwrites what is currently in currentExpression with an empty string
      void clearExpression();
      
      // pre  -- takes no arguments
      // post -- converts currentExpression into a string and returns it
      std::string getCurrentExpression();
      
      // pre  -- takes no arguments
      // post -- converts postfixExpression into a string and returns it
      std::string getPostfixExpression();
      
      // pre  -- takes a char representing an operator, op
      // post -- returns an integer corresponding to said operator's precedence; 0 for non-operators, 1 for +,- and 2 for /, *, %
      int getPrecedence(char op);

};

#endif