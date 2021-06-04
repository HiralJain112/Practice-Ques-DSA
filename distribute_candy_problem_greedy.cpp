#include<bits/stdc++.h>
using namespace std;

int candy(int[] ratings, int size) {
    int sum = 0
    int[size] left2right = {1}
    int[size] right2left = {1}
    for (int i = 1 to i < size) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1
        }
    }
    for (int i = size - 2 to i >= 0) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1
        }
    }
    for (int i = 0 to i < size) {
        sum += max(left2right[i], right2left[i])
    }
    return sum
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    return 0;
}