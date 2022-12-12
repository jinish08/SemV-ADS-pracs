#include <bits/stdc++.h>
using namespace std;

int hash1(string s, int arrsize)
{
    int hash = 6;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 34 + s[i]) % arrsize;
    }
    return hash;
}

int hash2(string s, int arrsize)
{
    int hash = 19;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 21 + s[i]) % arrsize;
    }
    return hash;
}

void check(int *arr1, int *arr2, int size, string s)
{
    int h1 = hash1(s, size);
    int h2 = hash2(s, size);

    int a = arr1[h1];
    int b = arr2[h2];

    if (a && b)
        cout << "Count of " << s << " is: " << (min(a, b)) << endl;
    else
        cout << s << " doesnt exist" << endl;
}

void insert(int *arr1, int *arr2, int size, string s)
{
    int h1 = hash1(s, size);
    int h2 = hash2(s, size);

    arr1[h1] += 1;
    arr2[h2] += 1;

    cout << s << " is inserted" << endl;
}

int main()
{
    int size = 10;
    int arr1[10] = {0};
    int arr2[10] = {0};
    string s[] = {"jack", "jack", "jack", "lane", "lane", "lane", "lane", "lane", "bob", "bob", "bob", "bob", "bob", "bob", "alice", "zuck", "eve", "max"};

    for (int i = 0; i < sizeof(s) / sizeof(s[0]); i++)
    {
        insert(arr1, arr2, size, s[i]);
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Enter name to lookup: ";
    string name;
    cin >> name;
    check(arr1, arr2, size, name);

    return 0;
}
