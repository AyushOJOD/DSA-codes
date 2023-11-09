#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    for(int i=0;i<9;i++){
        for(int j=0;i<9;j++){
            unordered_map<char, int> temp;
            if(board[i][j]){
                temp[board[i][j]]++;
            }
        }
    }
}

int main(){

    return 0;
}