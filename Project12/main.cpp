#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
public:
    class Node 
    {
    public:
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };
private:
    Node* start;
    Node* end;

public:
    Queue() : start(nullptr), end(nullptr) {}

    ~Queue() 
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            start = end = newNode;
        }
        else {
            end->next = newNode;
            end = newNode;
        }
    }

    T dequeue() {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }

        T item = start->data;
        Node* temp = start;
        start = start->next;
        delete temp;

        if (start == nullptr)
        {
            end = nullptr;
        }

        return item;
    }

    T peek() const 
    {
        if (isEmpty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return start->data;
    }

    bool isEmpty() const 
    {
        return start == nullptr;
    }
};

template<typename T>
class PriorityQueue 
{
public:
    class Node 
    {
    public:
        T data;
        int priority;
        Node* next;

        Node(const T& item, int p) : data(item), priority(p), next(nullptr) {}
    };

private:
    Node* start;

public:
    PriorityQueue() : start(nullptr) {}

    ~PriorityQueue() 
    {
        while (!isEmpty()) 
        {
            dequeue();
        }
    }

    void enqueue(const T& item, int priority) 
    {
        Node* newNode = new Node(item, priority);

        if (isEmpty() || priority < start->priority) 
        {
            newNode->next = start;
            start = newNode;
        }
        else 
        {
            Node* current = start;
            while (current->next != nullptr && current->next->priority <= priority) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T dequeue() 
    {
        if (isEmpty()) 
        {
            throw runtime_error("PriorityQueue is empty");
        }
        T item = start->data;
        Node* temp = start;
        start = start->next;
        delete temp;
        return item;
    }

    T peek() const 
    {
        if (isEmpty()) 
        {
            throw std::runtime_error("Queue is empty");
        }
        return start->data;
    }

    bool isEmpty() const 
    {
        return start == nullptr;
    }
};

int main() {
    Queue<int> q;
    PriorityQueue<int> pq;

    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(7);

    pq.enqueue(5, 3);
    pq.enqueue(3, 2);
    pq.enqueue(7, 1);
    cout << "Queue:\nInput: 5 3 7\n";
    cout << "Output: ";
    while (!q.isEmpty()) 
    {
        cout << q.dequeue() << " ";
    }
    cout << endl << endl;
    cout << "PriorityQueue:\nInput: 5(3), 3(2), 7(1)\n";
    cout << "Output: ";
    while (!pq.isEmpty()) 
    {
        cout << pq.dequeue() << " ";
    }
    cout << endl;

    return 0;
}