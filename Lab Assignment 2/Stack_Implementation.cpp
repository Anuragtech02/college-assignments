#include <iostream>
#include <string>
using namespace std;

const int STACK_SIZE = 10;

class Stack
{
private:
    int top;
    int arr[STACK_SIZE];

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 9)
            return true;
        else
            return false;
    }
    void push(int value)
    {
        if (isFull())
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = value;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            top--;
            return popValue;
        }
    }
    void displayStack()
    {
        cout << "All values in stack are: " << endl;
        int i = top;
        while (i >= 0)
        {
            cout << arr[i] << endl;
            i--;
        }
    }
};

int main()
{
    int a;
    cout << "***************STACK****************" << endl;
    cout << "1) Create stack" << endl;
    cout << "2) Add value into stack" << endl;
    cout << "3) Delete value from stack" << endl;
    cout << "4) Display stack" << endl;
    cout << "Choose any of the operation, which u want to perform: ";
    cin >> a;
    if (a == 1)
    {
        Stack s1;
        int value, option;
        do
        {
            if (a != 1)
            {
                cout << "Choose any of the operation, which u want to perform: ";
                cin >> a;
            }
            switch (a)
            {
            case 1:
            {
                cout << "Stack is already created" << endl;
                break;
            }
            case 2:
            {
                cout << "Enter the value: ";
                cin >> value;
                s1.push(value);
                break;
            }
            case 3:
            {
                cout << "deleted value is: " << s1.pop() << endl;
                break;
            }
            case 4:
            {
                s1.displayStack();
                break;
            }
            default:
            {
                cout << "Enter proper option number" << endl;
                break;
            }
            }
            a = 0;
            cout << "Do u want to continue(1/0): ";
            cin >> option;
        } while (option != 0);
    }
    else
        cout << "First create a stack" << endl;
}