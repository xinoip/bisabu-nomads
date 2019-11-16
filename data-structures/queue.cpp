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

    Queue(const Queue &q)
    {
        new (this) Queue;
        this->enqueue(q);
    }

    const bool enqueue(const T data)
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

    const bool enqueue(const Queue &q)
    {
        Node* temp = q.head;
        while(temp != nullptr){
            enqueue(temp->data);
            temp = temp->next;
        }

    }

    Queue &operator=(const Queue &other)
    {
        this->~Queue();
        new (this) Queue(other);
        return *this;
    }

    Queue operator+(const Queue &other) // q1 + q2 + q3 linkable
    {
        Queue temp(*this);
        temp.enqueue(other);
        return temp;
    }

    Queue &operator+=(const Queue &other) // a = b += c linkable.
    {
        *this = *this + other;
        return *this;
    }

    const T peek() const
    {
        return head->data;
    }

    void print() const
    {
        Node* cursor = head;

        while (cursor != nullptr)
        {
            cout << cursor->data << endl;
            cursor = cursor->next;
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
    q3 = q1 + q2 + q3;
    cout << q1 << '\n'
         << q2 << '\n'
         << q3 << endl;
         
    cout << q1.isEmpty() << "  " << q1.getSize() << endl;
}