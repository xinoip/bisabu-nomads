#include <iostream>

using namespace std;

class Stack
{
public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        while (top != nullptr)
        {
            pop();
        }
    }

    void operator=(Stack &s)
    {
        

        while (top != nullptr)
        {
            pop();
        }

        *this += s;

    }

    void operator+=(Stack &s)
    {
        Stack temp;

        while (s.top != nullptr)
        {
            temp.push(s.pop());
        }

        while (temp.top != nullptr)
        {                         //I was going to just do top = s.top but then we have
            int val = temp.pop(); //the same pointers so while destroying assigned stacks we free more
            push(val);            //than once.
            s.push(val);
        }

    }

    void push(const int val)
    {
        Node *temp = new Node;

        temp->data = val;
        temp->next = top;
        top = temp;
    }

    const int pop()
    {
        if (top != nullptr)
        {
            int val = top->data;
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
        int temp;
        if (top != nullptr)
        {
            temp = pop();
            print();
            cout << temp << endl;
            push(temp);
        }
    }

private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *top;
};

int main()
{
    Stack s1, s2;

    for (int i = 0; i < 10; ++i)
        s1.push(i);

    cout << s1.size() << endl;

    s1.print();

    for (int i = 15; i < 20; ++i)
        s2.push(i);

    s2.print();

    s1 = s2;

    s1.print();

    cout << s1.size() << "   " << s2.size() << endl;
}