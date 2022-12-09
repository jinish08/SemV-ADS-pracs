#include <bits/stdc++.h>
using namespace std;
class DynamicArray
{
private:
    int currSize;
    int capacity;
    int *a;

    void resizeArray()
    {
        if (currSize == capacity)
        {
            cout << "DOUBLING SIZEEEEE" << endl;
            int *temp = new int(2 * capacity);
            for (int i = 0; i < capacity; i++)
            {
                temp[i] = a[i];
            }
            free(a);
            a = temp;
            capacity = 2 * capacity;
        }
    }

public:
    DynamicArray()
    {
        a = new int(1);
        currSize = 0;
        capacity = 1;
    }

    void insertAtEnd(int x)
    {
        if (currSize == capacity)
        {
            resizeArray();
        }
        a[currSize] = x;
        currSize++;
    }

    int getArraySize()
    {
        return currSize;
    }

    int getCapacity()
    {
        return capacity;
    }
};

int main()
{
    DynamicArray a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a.insertAtEnd(i);
        cout << "Curr Size: " << a.getArraySize() << endl;
        cout << "Capacity: " << a.getCapacity() << endl;
    }
}