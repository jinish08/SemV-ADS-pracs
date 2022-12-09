#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void increment(vector<int> &v)
{
    int i = 0;
    while (i < v.size() && v[i] == 1)
    {
        v[i] = 0;
        i++;
    }
    if (i == v.size())
    {
        v.push_back(1);
    }
    if (i < v.size())
    {
        v[i] = 1;
    }
}
void display(vector<int> &v)
{
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int num;
    cout << "Enter a number to be incremented: ";
    cin >> num;
    int k = ceil((float)log(num) / log(2));
    for (int i = 0; i < k; i++)
    {
        v.push_back(num % 2);
        num = num / 2;
    }
    int n;
    cout << "Enter number of increments: ";
    cin >> n;
    display(v);
    while (n--)
    {
        increment(v);
        display(v);
    }
    return 0;
}