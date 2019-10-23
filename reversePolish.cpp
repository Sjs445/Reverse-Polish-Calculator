#include <iostream>
#include <stack>

using namespace std;

void Evaluate(stack<int> s, char * input);
bool checkDigit(char []);


int main()
{
    stack <int> s;
    char expression[]="20 123 45 + 77 - * $";
    Evaluate(s, expression);
    return 0;
}

void Evaluate(stack<int> s, char * input)
{
    int i=0;
    char * args;
    int num1, num2;

    args=strtok(input, " ");

    while(args!=NULL)
    {
        if(checkDigit(args))
        {
            s.push(atoi(args));
        }
        else
        {
            if(strcmp(args, "$")==0)
            break;
            num1=s.top();
            s.pop();
            num2=s.top();
            s.pop();

            if(strcmp(args, "+")==0)
            {
                s.push(num1+num2);
            }
            else if(strcmp(args, "-")==0)
            {
                s.push(num2-num1);
            }
            else if(strcmp(args, "*")==0)
            {
                s.push(num1*num2);
            }
            else
            {
                break;
            }
        }
        
        args=strtok(NULL, " ");
        i++;
    }

    cout<<"Postfix exprssion evaluated: $"<<s.top()<<endl;
}

bool checkDigit(char input[])
{
    int i=0;
    while(input[i])
    {
        if(isdigit(input[i]))
        {
            return true;
        }
        i++;
    }
    return false;
}