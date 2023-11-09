//Jack Keys || CompSci303 || Assignment #3

#include "ExpressionObject.h"
#include "Queue.h"

int main() 
{
  ExpressionObject expression;
  std::string input = "";
  bool isDone = false;

  /*Driver Code for Expression Handler*/
  
  while (!isDone)
    {
      std::cout << "CHOOSE ONE OF THE FOLLOWING:\n---" << std::endl
                << "a -- edit infix expresssion" << std::endl
                << "b -- check if expression is balanced" << std::endl
                << "c -- see postfix expression" << std::endl
                << "q -- quit" << std::endl
                << "---\nCurrent Expression:\n---\n" << expression.getCurrentExpression() << std::endl << std::endl << "   >>>";
      
      std::cin >> input;

      switch(input[0])
        {
          
          case 'a':

            expression.setExpression();
            break;

          case 'b':

            if (expression.isBalanced())
            {
              std::cout << "Expression is balanced" << std::endl << std::endl;
            }
  
            else
            {
              std::cout << "Expression is not balanced" << std::endl << std::endl;
            }

            break;

          case 'c':

            std::cout << "Postfix Expression\n---" << std::endl << expression.getPostfixExpression() << std::endl << std::endl;
            break;

          case 'q':

            isDone = true;
            break;

          default:

            std::cout << "Not a valid choice.  Try again\n---" << std::endl << std::endl;
        }
    }

  /*Driver Code for Queue*/

  isDone = false;
  Queue<std::string> q;

  while (!isDone)
    {
      std::cout << "CHOOSE ONE OF THE FOLLOWING:\n---" << std::endl
        << "a -- add element to queue" << std::endl
        << "b -- remove element from queue" << std::endl
        << "c -- see top element of queue" << std::endl
        << "d -- check if queue is empty" << std::endl
        << "e -- get the size of the queue" << std::endl
        << "q -- quit\n\n   >>>";

      std::cin >> input;

      switch(input[0])
        {
          
          case 'a':
          
            std::cout << "Enter string to add to queue\n\n   >>>";
            std::cin >> input;
            q.enqueue(input);
            break;

          case 'b':

            if (q.isEmpty())
            {
              std::cout << "Cannot remove from empty queue" << std::endl << std::endl;
            }
  
            else
            {
              q.dequeue();
            }
  
            break;

          case 'c':

            if (!q.isEmpty())
            {
              std::cout << "Top of the queue: " << q.peek() << std::endl << std::endl;
            }
  
            break;

          case 'd':

            if (q.isEmpty())
            {
              std::cout << "Queue is empty" << std::endl << std::endl;
            }
  
            else
            {
              std::cout << "Queue is not empty" << std::endl << std::endl;
            }

            break;

          case 'e':

            std::cout << q.getSize() << std::endl << std::endl;
            break;

          default:

            std::cout << "Not a valid choice.  Try again\n---" << std::endl << std::endl;
        }
    }
}

