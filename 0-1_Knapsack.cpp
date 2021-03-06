/* C++ program � Naive recursive implementation of 0-1 Knapsack problem */
#include<iostream>
using namespace std;

/* Function to find maximum of two integers */
int max(int a, int b) { return (a > b)? a : b; }

/* Function to find the maximum value that can be put in a knapsack of capacity W */
int knapSack(int W, int weight[], int value[], int n)
{
    if (n == 0 || W == 0) /* Base Case */
        return 0;

    /* If weight of the nth item is more than Knapsack capacity W */
    if (weight[n-1] > W)
        return knapSack(W, weight, value, n-1); /* this item cannot be included in the optimal solution */

    else return max( value[n-1] + knapSack(W-weight[n-1], weight, value, n-1), knapSack(W, weight, value, n-1));
}

int main()
{
    int n;
    cout << "\nEnter the number of items :";
    cin >> n;
    int value[n];
    int weight[n];
    int i;
    cout << "\nEnter the item�s weight and its value \n";
    for(i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    int W;
    cout << "\nEnter the capacity of the knapsack : ";
    cin >> W;
    cout << "\nMaximum value in a 0-1 knapsack : " << knapSack(W, weight, value, n) << endl;
    return 0;
}
