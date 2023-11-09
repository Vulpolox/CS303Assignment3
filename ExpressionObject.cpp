//Jack Keys || CompSci303 || Assignment #3

#include "ExpressionObject.h"

ExpressionObject::ExpressionObject()
{
  
}

bool ExpressionObject::isBalanced()
{
  std::stack<char> parenthesisStack;
  char currentLeftParenthesis;

  //iterate through all elements in the infix expression
  for (auto element : this->currentExpression)
    {
      //if the element is a left parenthesis
      if (isIn(element[0], this->leftParentheses))
      {
        parenthesisStack.push(element[0]); //push it to the stack
      }

      //if the element is a right parenthesis
      if (isIn(element[0], this->rightParentheses))
      {
        //if there is an unpaired right parenthesis (i.e. a right parenthesis is found while stack is empty)
        if (parenthesisStack.empty())
        {
          return false; //expression is unbalanced
        }

        currentLeftParenthesis = parenthesisStack.top(); //store top parenthesis from stack in temporary reference
        parenthesisStack.pop(); //remove top element

        //if the left parenthesis is not the same type as the right parenthesis
        if (!isMatchingParentheses(currentLeftParenthesis, element[0]))
        {
          return false; //expression is unbalanced
        }
      }
    }
  
  //after loop terminates, if there are no unpaired left parentheses
  if (parenthesisStack.empty())
  {
    return true; //expression is balanced
  }

  return false; //expression contains unpaired left parentheses and is therefore unbalanced
}


bool ExpressionObject::isMatchingParentheses(char pl, char pr)
{
  return this->leftParentheses.find(pl) == this->rightParentheses.find(pr);
}


bool ExpressionObject::isIn(char toFind, std::string list)
{
  return list.find(toFind) != std::string::npos;
}


bool ExpressionObject::isValidElement(std::string s)
{

  //the only instance where a valid input's size is > 1 is if it is a number
  //with more than 1 digit; test to see if all characters are numbers in this case
  if (s.size() > 1)
  {
    for (auto character : s)
    {
      if (!std::isdigit(character))
        return false; //if a character in the input isn't a digit, then it cannot be a valid entry

    }
    return true; //input is a number with > 1 digit
  }

  //this conditional executes if the input string contains only 1 character
  else if (!s.empty() && isIn(s[0], this->validOperators) ||
          isIn(s[0], this->rightParentheses) || isIn(s[0], this->leftParentheses)
          || isalnum(s[0]))
  {
    return true; //input is a parenthesis, operator, or variable
  }

  return false; //input is invalid
}


void ExpressionObject::createPostfixExpression()
{
  try
    {
      this->postfixExpression.clear(); //clear the old postfix expression
      
      //if the expression is not balanced, tell the user
      if (!this->isBalanced())
      {
        this->postfixExpression.push_back("Unable to create postfix expression; infix expression is unbalanced");
        return;
      }

      //algorithm for converting infix to postfix
      else
      {

        std::stack<char> operatorStack;
        char matchingLeftParenthesis;

        //read through each token in the infix expression
        for (auto token : this->currentExpression)
          {
            //if the current token is not a parenthesis or operator (i.e. is an operand)
            if (!isIn(token[0], this->leftParentheses) && !isIn(token[0], this->rightParentheses) 
                && !isIn(token[0], this->validOperators))
            {
              this->postfixExpression.push_back(token); //push it onto the postfix expression vector (output)
            }

            //if current token is a left parenthesis
            else if (isIn(token[0], this->leftParentheses))
            {
              operatorStack.push(token[0]); //push it onto the operator stack
            }

            //if current token is a right parenthesis
            else if (isIn(token[0], this->rightParentheses))
            {
              matchingLeftParenthesis = this->leftParentheses.at(this->rightParentheses.find(token[0])); //store the matching left parenthesis in the var

              //while the top element in the stack isn't the matching left parenthesis
              while (operatorStack.top() != matchingLeftParenthesis)
                {
                  this->postfixExpression.push_back(std::string(1, operatorStack.top())); //add the top operator from the stack to postfix expression
                  operatorStack.pop(); //remove the top operator
                }
              
              operatorStack.pop(); //remove the mathcing left parenthesis from the operator stack
            }

            //if the current token is an operator
            else if (isIn(token[0], this->validOperators))
            {
              
              //while the precedence of the current token operator is <= to the precedence of the top operator on the stack
              //and the stack is not empty
              while (!operatorStack.empty() && getPrecedence(token[0]) <= getPrecedence(operatorStack.top()))
                {
                  this->postfixExpression.push_back(std::string(1, operatorStack.top())); //add the top operator from the stack to postfix expression
                  operatorStack.pop(); //remove the top operator
                }

              operatorStack.push(token[0]); //add the current token to the operator stack
            }
            
          }

        //add the remaining operators from the stack to the postfix expression after the loop terminates
        while (!operatorStack.empty())
          {
            this->postfixExpression.push_back(std::string(1, operatorStack.top())); //add the top operator from the stack to postfix expression
            operatorStack.pop(); //remove the top operator
          }
      }

    }
    
  catch(...)
    {
      this->postfixExpression.push_back("Unable to create postfix expression from given infix expression; unknown error, check formatting");
      return;
    }
}


void ExpressionObject::setExpression()
{
  
  std::string input = "";

  while (input != "q")
    {
      std::cout << "\n\n\n";
      
      std::cout << "Enter a variable, parenthesis, or number [enter \'q\' to stop, \'c\' to clear expression]\n   >>>";
      std::cin >> input;

      //check if input is valid
      if (!isValidElement(input))
      {
        std::cout << "Input is not valid.  Try again\n---" << std::endl << std::endl;
        continue;
      }

      //if user wants to clear expression
      if (input == "c")
      {
        this->clearExpression();
        continue;
      }

      //if user wants to stop adding elements
      if (input == "q")
      {
        std::cout << "Final Expression:\n---\n" << this->getCurrentExpression() << std::endl << std::endl;
        this->createPostfixExpression();
        break;
      }

      this->currentExpression.push_back(input);
      std::cout << "Current Expression:\n---\n" << this->getCurrentExpression() << std::endl << std::endl;
    } 
}


void ExpressionObject::clearExpression()
{
  this->currentExpression.clear();
}


std::string ExpressionObject::getCurrentExpression()
{
  std::ostringstream sout;

  for (auto element : this->currentExpression)
    {
      sout << element << " ";
    }

  return sout.str();
}


std::string ExpressionObject::getPostfixExpression()
{
  std::ostringstream sout;

  for (auto element : this->postfixExpression)
    {
      sout << element << " ";
    }

  return sout.str();
}

int ExpressionObject::getPrecedence(char op)
{
  if (op == '+' || op == '-')
  {
    return 1;
  }

  else if (op == '*' || op == '/' || op == '%')
  {
    return 2;
  }

  return 0;
}