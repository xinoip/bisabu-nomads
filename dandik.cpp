#include <iostream>

const int N = 9;

using namespace std;

void initIdArray(int arr[N])
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }
}

void unionPair(int arr[N], int p, int q)
{
    int pid = arr[p];
    int qid = arr[q];
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == pid)
            arr[i] = qid;
    }
}

bool isConnected(int arr[N], int p, int q)
{
    return (arr[p] == arr[q]);
}

int main(int argc, char const *argv[])
{
    int id[N];
    initIdArray(id);

    int p, q;
    char mode;
    while (true)
    {
        cin >> p >> q >> mode;

        if (mode == 'C' || mode == 'c')
        {
            cout << "isConnected(" << p << "," << q << ") = " << isConnected(id, p, q) << endl;
        }
        else if (mode == 'U' || mode == 'u')
        {
            cout << "Connecting " << p << " with " << q << endl;
            unionPair(id, p, q);
        }
        else if (mode == 'Q' || mode == 'q')
        {
            cout << "exit\n";
            break;
        }
    }

    return 0;
}
