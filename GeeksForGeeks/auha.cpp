#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int minConcatPreStrings(const vector<string>& A, const string& B) {
    // Step 1: Calculate the frequency of each character in B
    unordered_map<char, int> freq_B;
    for (char c : B) {
        freq_B[c]++;
    }

    // Initialize min_preString to a large value
    double min_preString = numeric_limits<double>::infinity();

    // Step 2: Iterate through each string in A
    for (const string& string_A : A) {
        // Step 3a: Calculate the frequency of each character in the current string
        unordered_map<char, int> freq_A;
        for (char c : string_A) {
            freq_A[c]++;
        }

        // Step 3b and 3c: Calculate the ratio for each character and update min_preString
        double ratio = numeric_limits<double>::infinity();
        for (const auto& entry : freq_B) {
            char char_B = entry.first;
            int count_B = entry.second;
            
            if (freq_A.find(char_B) == freq_A.end()) {
                ratio = 0;
                break;
            }
            ratio = min(ratio, static_cast<double>(freq_A[char_B]) / count_B);
        }

        min_preString = min(min_preString, ratio);
    }

    // Step 5: Check if it's possible to build B
    if (min_preString == numeric_limits<double>::infinity()) {
        return -1;
    }

    // Step 6: Return the ceiling of min_preString
    return static_cast<int>(ceil(min_preString));
}

int main() {
    // Example usage:
    vector<string> A = {"abc", "bcb", "ka", "efgh"};
    string B = "efkabc";
    int result = minConcatPreStrings(A, B);
    cout << result << endl;  // Output: 2

    return 0;
}