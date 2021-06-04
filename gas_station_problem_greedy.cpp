#include<bits/stdc++.h>
using namespace std;

int canCompleteCircuit(int gas[], int cost[],int n) {
        int start = 0;
        int total = 0;
        int tank = 0;
        for(int i = 0 ; i < n; i++) {
            tank = tank + gas[i] - cost[i] ;
            if(tank < 0) {
                start = i+1 ;
                total = total + tank ;
                tank = 0 ;
            }
        }
        if(total + tank < 0) {
            return -1;
        } 
    return start;
}

int main()
{
    int n;
    cin>>n;
    int gas[n], cost[n];
    for (int i = 0; i < n; i++)
    {
        cin>>gas[i]>>cost[i];
    }
    cout<<canCompleteCircuit(gas, cost, n);
    return 0;
}