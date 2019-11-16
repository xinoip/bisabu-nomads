#include <iostream>

using namespace std;


template <typename T>
class Stack
{
public:
    Stack()
    {
        top = nullptr;
    }

    Stack(Stack &s)
    {
        push(s);
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }

    Stack &operator=(Stack &s)
    {
        this->~Stack();
        new (this) Stack(s);
        return *this;
    }

    void operator+=(Stack &s)
    {
        push(s);
    }

    void push(const T val)
    {
        Node *temp = new Node;

        temp->data = val;
        temp->next = top;
        top = temp;
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

            return val;
        }
    }

    const int size() const //Kinda anticlimatic but whatever.
    {
        Node *temp = top;
        int count = 0;
        while (temp != nullptr)
        {
            temp = temp->next;
            ++count;
        }
        return count;
    }

    void print()
    {
        T temp;
        if (top != nullptr)
        {
            temp = pop();
            print();
            cout << temp << endl;
            push(temp);
        }
    }

private:
    
    void push(Stack &s)
    {
        Stack temp;

        while (s.top != nullptr)
        {
            temp.push(s.pop());
        }

        while (temp.top != nullptr)
        {                         //I was going to just do top = s.top but then we have
            T val = temp.pop(); //the same pointers so while destroying assigned stacks we free more
            push(val);            //than once.
            s.push(val);
        }
    }

    struct Node
    {
        T data;
        Node *next;
    };

    Node *top;
};

int main()
{
    Stack<int> s1;
    Stack<double> s2;
    Stack<int> s3;

    for (int i = 0; i < 10; ++i)
        s1.push(i);

    cout << s1.size() << endl;

    s1.print();

    for (double i = 15; i < 20; i += 0.5)
        s2.push(i);

    for(int i =50;i<70;++i)
        s3.push(i);

    s2.print();

    s1 += s3;

    s1.print();

    cout << s1.size() << "   " << s2.size() << endl;
}