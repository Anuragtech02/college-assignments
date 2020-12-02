#include <iostream>
using namespace std;

const int QUEUE_SIZE = 5;

class CircularQueue
{
private:
    int front;
    int rear;
    int arr[QUEUE_SIZE];
    int itemCount;

public:
    CircularQueue()
    {
        itemCount = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < QUEUE_SIZE; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }
    bool isFull()
    {
        return (rear + 1) % QUEUE_SIZE == front;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = val;
        }
        else
        {
            rear = (rear + 1) % QUEUE_SIZE;
            arr[rear] = val;
        }
        itemCount++;
    }

    int dequeue()
    {
        int temp = 0;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return temp;
        }
        else if (rear == front)
        {
            temp = arr[rear];
            rear = -1;
            front = -1;
            itemCount--;
            return temp;
        }
        else
        {
            cout << "Front value: " << front << endl;
            temp = arr[front];
            arr[front] = 0;
            front = (front + 1) % QUEUE_SIZE;
            itemCount--;
            return temp;
        }
    }

    int count()
    {
        return itemCount;
    }

    void display()
    {
        cout << "All values in the Queue are : " << endl;
        for (int item : arr)
        {
            cout << item << "\t";
        }
    }
};

int main()
{
    CircularQueue q1;
    int value, option;

    do
    {
        cout << "\n\nSelect the option that you want to perform. Enter 0 to exit." << endl;
        cout << "1. Insert value into queue (Enqueue)." << endl;
        cout << "2. Delete value from queue (Dequeue)." << endl;
        cout << "3. Is queue empty ?" << endl;
        cout << "4. Is queue full ?" << endl;
        cout << "5. Total elements in queue." << endl;
        cout << "6. Display elements of queue." << endl
             << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue" << endl;
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Operation \nDequeued Value : " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            if (q1.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;
        case 5:
            cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            q1.display();
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}