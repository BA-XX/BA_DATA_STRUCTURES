#include <iostream>
#include <conio.h>
#include "stack.hpp"

bool checkBalancedParentheses(const std::string &expression)
{
    Stack<char> stack; // create a char stack

    for (char ch : expression)
    {
        if (ch == '{' || ch == '[' || ch == '(')
            // if it is an opening parenthesis, push it to the stack
            stack.push(ch);

        else if (ch == '}' || ch == ']' || ch == ')')
        {
            // if it is a closing parenthesis
            if (stack.isEmpty())
                return false;

            char top = stack.top();

            if ((ch == '}' && top == '{') ||
                (ch == ']' && top == '[') ||
                (ch == ')' && top == '('))
                stack.pop(); // only pop if the top element matches the closing parenthesis

            else
                return false;
        }
    }

    // if the stack is not empty, there are unmatched opening parentheses
    return stack.isEmpty();
}

int main()
{
    std::string expression;

    do
    {
        std::cout << "enter an expression : ";
        std::cin >> expression;
        std::cout << "Expression is : " << expression << std::endl;

        if (checkBalancedParentheses(expression))
            std::cout << "Ok! expression is Balanced" << std::endl;
        else
            std::cout << "Non Balanced!" << std::endl;

        std::cout << "----- Press any key to continue or press 0 to exit -----" << std::endl;

    } while (getch() != '0');

    return 0;
}