// Wyatt Applebay
// 004973341

#include <iostream>
#include <string>
#include <cctype>
#include "Vector2.h"
#include "Stack.h"

using namespace std;

bool is_operator(string x)
{
  if (x == "+" or x == "-" or x == "*" or x == "/")
    return true;
  return false;

}

bool is_operand(string x)
{
  return isalnum(x[0]);
}

bool is_lower_eq_precedence(string op1, string op2)
{
  return ( op2 == "*" or op2 == "/" or op1 == "+" or op1 == "-");
}

string infix2postfix()
{
  Stack<Vector<string> > thestack;
  string postfix = " ";

  string inp;
  cin >> inp;      //step 1; first time
  while (true)
    {
      if (inp == "=")
       break;

      if (is_operand(inp))
        {
          postfix = postfix + inp + " ";
        }
        //cout << inp << " "; //step 2

      else if (inp == "(")
        thestack.push("("); // step 3
// step 4********************************************
      else if (is_operator(inp))
        {
          if (thestack.empty())
            thestack.push(inp); // 4.a

          else
            {                   // 4.b
              while (thestack.top() != "(" and !thestack.empty() and !is_lower_eq_precedence(thestack.top(), inp))
              {                 // 4.b.1
                //cout << thestack.top() << " ";
                postfix = postfix + thestack.top() + " ";
                thestack.pop();
              }
              thestack.push(inp);  // 4.b.2
            }
        } //*****************************************
        else if (inp == ")")
          {
            while (thestack.top() != "(")
              {
                thestack.pop();
                //cout << thestack.top() << " ";
                postfix = postfix + thestack.top() + " ";
              }
              thestack.pop();
          }
        else
          cout << "Should never go here " << endl;
        cin >> inp;
    }

  while (!thestack.empty())
    {
      //cout << thestack.top() << " ";
      postfix = postfix + thestack.top() + " ";
      thestack.pop();
    }
   return postfix;
}

int main()
{
  string infix;
  cout << "Enter an infix expression: ";
  cout << endl << endl;

  string post = infix2postfix();

  cout << "Postfix expression: " << post << endl << endl;

  return 0;
}
