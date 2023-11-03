#include<iostream>
using namespace std;

bool isPalindrome(int x) {
        int res=0;
        while(x>0){
            res=res+x%10;
            x=x/10;
        }

        if(x==res){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }

int main(){
    

    return 0;
}