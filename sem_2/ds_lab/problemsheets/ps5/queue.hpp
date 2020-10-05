#include <iostream>
using namespace std;

template <class T>
class Queue
{
    int front, rear;
    int size;
    T *queue;

public:
    Queue();
    Queue(int);
    void enqueue(T);
    T dequeue();
    void display();
    int count();
    ~Queue();
};

template <class T>
Queue<T>::Queue()
{
    front = rear = -1;
    queue = new T[0]();
}

template <class T>
Queue<T>::~Queue()
{
    delete[] queue;
}

template <class T>
Queue<T>::Queue(int size)
{
    delete[] queue;
    this->size = size;
    queue = new T[size]();
}

template <class T>
void Queue<T>::enqueue(T element)
{
    if (rear == size - 1)
    {
        cout << "Queue is full\n";
        return;
    }
    else if (rear == -1)
        front = 0;
    rear++;
    queue[rear] = element;
}

template <class T>
T Queue<T>::dequeue()
{
    T element;
    if (rear == -1)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    element = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    rerturn element;
}

template <class T>
void Queue<T>::display()
{
    if (rear == -1)
    {
        cout << "Queue is empty\n";
        return;
    }
    Queue<T> Q(size);
    int local_rear = rear;
    cout << "Displaying Queue\n";
    while (front != -1)
    {
        element = dequeue();
        cout << element << "\t";
        Q.enqueue(element);
    }
    cout << endl;
    for (int i = 0; i <= local_rear; i++)
    {
        element = Q.dequeue();
        enqueue(element);
    }
}

template <class T>
int Queue<T>::count()
{
    if (rear == -1)
        return 0;
    return rear - front + 1;
}