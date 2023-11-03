#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i] == 0){
                if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    count++;
                }
            }
        }
        if(count>=n){
            return true;
        }
        else{
            return false;
        }
    }

int main(){
    vector <int> fb={1,0,0,0,1}; 

    cout<<canPlaceFlowers(fb,2);

    return 0;
}