#include <iostream>

using namespace std;

template <typename T>
class Queue
{

private:
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head;
    Node *end;
    int size;

public:
    Queue() : size(0)
    {
        head = nullptr;
        end = nullptr;
    }
    ~Queue()
    {
        Node *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
    }

    Queue(Queue &q)
    {
        new (this) Queue;
        this->enqueue(q);
    }

    bool enqueue(T data)
    {

        ++size;

        if (head == nullptr)
        {
            head = new Node;
            head->data = data;
            head->next = nullptr;
            end = head;
            return true;
        }

        end->next = new Node;
        end->next->data = data;
        end = end->next;
        end->next = nullptr;

        return true;
    }

    const T dequeue()
    {
        Node *temp = head;
        T retData = temp->data;
        head = head->next;

        delete temp;
        temp = nullptr;

        --size;

        return retData;
    }

    bool enqueue(Queue &q)
    {
        Queue temp;
        T tempdata;
        while (q.head != nullptr)
        {
            temp.enqueue(q.dequeue());
        }
        while (temp.head != nullptr)
        {
            tempdata = temp.dequeue();
            enqueue(tempdata);
            q.enqueue(tempdata);
        }
    }

    const Queue &operator=(Queue &other)
    {
        this->~Queue();
        new (this) Queue(other);
        return *this;
    }

    Queue &operator+(Queue &other)
    {
        Queue *temp = new Queue;
        temp->enqueue(*this);
        temp->enqueue(other);
        return *temp;
    }

    const Queue &operator+=(Queue &other)
    {
        *this = *this + other;
        return *this;
    }

    T peek()
    {
        return head->data;
    }

    void print()
    {
        Queue temp;

        while (head != nullptr)
        {
            cout << peek() << endl;
            temp.enqueue(dequeue());
        }

        while (temp.head != nullptr)
        {
            enqueue(temp.dequeue());
        }
    }

    const bool isEmpty() const
    {
        if (head == nullptr)
            return true;
        return false;
    }

    const int getSize() const
    {
        return size;
    }
};

template <typename T>
ostream &operator<<(ostream &output, Queue<T> q)
{
    q.print();
    return output;
}

int main()
{
    Queue<int> q1, q2, q3;

    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);

    cout << q1.getSize() << endl;

    q2.enqueue(2);
    q2.enqueue(4);
    q2.enqueue(8);

    q1 += q2;
    q3 = q1 + q2;
    cout << q1 << '\n'
         << q2 << '\n'
         << q3 << endl;
         
    cout << q1.isEmpty() << "  " << q1.getSize() << endl;
}