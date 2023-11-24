#include<bits/stdc++.h>
using namespace std;

int rev(int num)
{
    int reversed = 0;

    while (num != 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int countNicePairs(vector<int> &nums)
{
    int count = 0;

    for(int i=0;i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] - nums[rev(i)] == nums[j] - nums[rev(j)]){
                return 
            }
        }
    }
}

int main(){

    return 0;
}