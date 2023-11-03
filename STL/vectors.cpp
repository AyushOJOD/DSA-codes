#include<bits/stdc++.h>
using namespace std;

int main(){

    // Size of vector is dynamic

    // Vectors can be defined as:
    vector<int> v;
    
    v.push_back(1);
    v.emplace_back(2);

    // To provide an iterator to it :
    vector<int>::iterator it = v.begin(); // This will point to the start

    it++; // the value goes to the next memory location

    cout<< *(it)<<endl;

    vector<int>:: iterator it = v.end(); // THIS POINTS TO MEMORY LOCATION AFTER THE LAST VALUE 
    vector<int>:: iterator it = v.rend();
    vector<int>:: iterator it = v.rbegin();

    // TRAVERSAL OF VECTOR:
    for(auto i: v){
        cout<<i<<" ";
    }

    // DELETION: 
    v.erase(v.begin() + 1); // Deletes second element
    

    v.erase(v.begin(), v.begin()+2); // This will delete the values from index 0, 1 i.e, before 2;

    // INSERTION:

    // v.insert(postion to be inserted, number of occurences, number to be instered) The middle one is not mandat

    return 0;
}