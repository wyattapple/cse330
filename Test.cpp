#include <iostream>
#include <string>
#include <cctype>
#include "Stack.h"
#include "Vector2.h"
using namespace std;

bool is_operator(string x)
{
    if(x=="+"||x=="-"||x=="*"||x=="/")
        return true;

    return false;
}

bool lower_eq_precensence(string op1, string op2)
{
    return (op2 == "*"||op2 == "/"||op1 == "+"|| op1 == "-");

}

string infix2postfix()
{
    Stack<Vector<string>> thestack;
    string postfix = " ";
    string nextinp;

    cin >> nextinp;//step 1

    while (nextinp != "=")
    {
        if(isalnum(nextinp[0]))
        {//step 2
            //cout << nextinp;
            postfix = postfix + nextinp + " " ;
        }
        else if (nextinp == "(")
        {//step 3
            thestack.push("(");
        }
        else if (is_operator(nextinp))
        {//step 4
             if(thestack.empty())
            {
                thestack.push(nextinp);//step 4a
            }
            else
            { //step 4b I 1-3
                while(true)
                {
                    if(thestack.empty())
                        break;
                    if(thestack.top()=="(")
                        break;
                    if(lower_eq_precensence(thestack.top(),nextinp))
                        break;
                    //cout << thestack.top();
                    postfix = postfix + thestack.top() + " ";
                    thestack.pop();
                }
                thestack.push(nextinp);//step 4 b II
            }
        }
        else if (nextinp == ")")
        {//step 5
           while (thestack.top() != "(")
           {
               //cout << thestack.top();
                postfix = postfix + thestack.top() + " ";
                thestack.pop();
           }
            thestack.pop();

        }
        else
        {
            cout << "Something is wrong" << endl;
        }
        cin >> nextinp;

    }
    while(!thestack.empty())
    {
         //cout << thestack.top();
         postfix = postfix + thestack.top() + " ";
         thestack.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    string postfix = infix2postfix();

    cout<< "postfix expression: " << postfix;
    cout << endl<< endl;


    /*
    Stack<Vector<int>>mystack;
    for(int i= 0; i<=10;i++)
    {
        mystack.push(1);
    }
    while (mystack.empty())
    {
        cout<< mystack.top() << " ";
    }
    cout << endl << endl;
    */

   return 0;

}
