#include <iostream>

using namespace std;


template <typename T>
class Stack
{
public:
    Stack() : size_(0)
    {
        top = nullptr;
    }

    Stack(const Stack &s)
    {
        new (this) Stack;
        push(s);
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }

    Stack &operator=(const Stack &s) // s1 = s2 = s3 linkable
    {
        this->~Stack();
        new (this) Stack(s);
        return *this;
    }

    Stack& operator+=(const Stack &s) // s1 = s2 += s3 linkable
    {
        push(s);
        return *this;
    }

    Stack operator+(const Stack &s){ // s1 + s2 + s3 linkable
        Stack temp(*this);
        temp.push(s);
        return temp;
    }

    void push(const T val)
    {
        Node *temp = new Node;

        temp->data = val;
        temp->next = top;
        top = temp;

        ++size_;
    }

        
    void push(const Stack &s)
    {
        Node* cursor = s.top;

        while(cursor != nullptr){
            push(cursor->data);
            cursor = cursor->next;
        }
    }


    const T pop()
    {
        if (top != nullptr)
        {
            T val = top->data;
            Node *temp = top;

            top = top->next;
            delete temp;
            temp = nullptr;

            --size_;

            return val;
        }
    }

    const int size() const //Kinda anticlimatic but whatever.
    {
        return size_;
    }

    void print() const
    {
        Node* cursor = top;

        while(cursor != nullptr){
            cout << cursor->data << endl;
            cursor = cursor->next;
        }
    }

private:


    struct Node
    {
        T data;
        Node *next;
    };

    Node *top;
    int size_;
};

int main()
{
    Stack<int> s1;
    Stack<int> s2;
    Stack<int> s3;

    for (int i = 0; i < 10; ++i)
        s1.push(i);

    cout << s1.size() << endl;

    s1.print();

    for (int i = 15; i < 20; ++i)
        s2.push(i);

    for(int i =50;i<70;++i)
        s3.push(i);

    s2.print();

    s1 = s1 + s2 + s3;

    s1.print();

    cout << s1.size() << "   " << s2.size() << endl;
}