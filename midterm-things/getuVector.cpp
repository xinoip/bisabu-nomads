#include <iostream>

// basic vector impl

using namespace std;

class GetuVector
{
public:
    GetuVector();
    ~GetuVector();

    void print() const;

    const GetuVector &pushBack(double x);
    const GetuVector &pushBack(double arr[], int n);

    double operator[](int index) const;
    double &operator[](int index);

    //==, !=, <<

private:
    int size;
    double *data;
};

GetuVector::GetuVector()
{
    size = 0;
    data = new double[size];
}

GetuVector::~GetuVector()
{
    delete[] data;
}

void GetuVector::print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << "\n";
}

const GetuVector &GetuVector::pushBack(double x)
{
    double *tmp = new double[size + 1];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = data[i];
    }
    tmp[size] = x;
    delete[] data;
    this->data = tmp;
    this->size += 1;
    return *this;
}

const GetuVector &GetuVector::pushBack(double arr[], int n)
{
    double *tmp = new double[size + n];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = data[i];
    }
    for (int i = 0; i < n; i++)
    {
        tmp[i + size] = arr[i];
    }
    delete[] data;
    this->data = tmp;
    this->size += n;
    return *this;
}

double GetuVector::operator[](int index) const
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }
    else
    {
        return -1;
    }
}

double &GetuVector::operator[](int index)
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }
}

int main()
{
    GetuVector myVector;

    myVector.pushBack(12.0);
    myVector.pushBack(11.0);
    myVector.pushBack(10.0);

    myVector.print();

    double arr[4] = {1,2,3,4};
    myVector.pushBack(arr, 4);

    myVector.print();

    myVector[2] = 31;
    myVector.print();

    return 0;
}
