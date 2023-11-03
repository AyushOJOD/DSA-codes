// Using Recursion
#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price, int start, int end){
    if(end<=start){
        //base case when there is only one element left in array or no more profit can be made
        return 0;
    }
    int profit=0;
    for(int i=start;i<end;i++){
        for(int j=i+1;j<=end;j++){
            if(price[i]<price[j]){
                int curr_profit = price[j]-price[i]+ maxProfit(price,start,i-1)+maxProfit(price,j+1,end);
                profit= std::max(profit,maxProfit);
            }
        
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<maxProfit(a,0,n-1);

    return 0;
}