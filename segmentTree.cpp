#include <bits/stdc++.h>
using namespace std;
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) { return s + (e - s) / 2; }
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
           getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}
// Return sum of elements in range from index qs (query start)
// to qe (query end). It mainly uses getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n - 1 || qs > qe)
    {
        cout << "Invalid Input";
        return -1;
    }
    return getSumUtil(st, 0, n - 1, qs, qe, 0);
}
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
             constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
    return st[si];
}

/* Function to construct segment tree from given array. This function
allocates memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for the segment tree
    // Height of segment tree
    int x = (int)(ceil(log2(n)));
    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;
    // Allocate memory
    int *st = new int[max_size];
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n - 1, st, 0);
    // Return the constructed segment tree
    return st;
}
// Driver program to test above functions
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Build segment tree from given array
    int *st = constructST(arr, n);
    // Print sum of values in array from index 1 to 3
    cout << "Sum of values in given range = " << getSum(st, n, 1, 3) << endl;
    return 0;
}
