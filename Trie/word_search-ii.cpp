#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // struct of Trie

    struct TrieNode
    {
        bool wordEnd;
        string word;
        TrieNode *children[26];
    };

    // get a new Node
    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();

        // set the constaints
        newNode->wordEnd = false;
        newNode->word = "";

        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    // Insertion
    void insert(TrieNode *root, string &word)
    {
        TrieNode *curr = root;

        for (char &ch : word)
        {
            if (curr->children[ch - 'a'] == NULL)
            {
                curr->children[ch - 'a'] = getNode();
            }

            curr = curr->children[ch - 'a'];
        }

        curr->wordEnd = true;
        curr->word = word;
    }

    void dfs(vector<vector<char>> &board, int row, int col, TrieNode *root, vector<string> &res, int n, int m)
    {
        if (row < 0 || row >= n || col < 0 || col >= m)
        {
            return;
        }

        if (board[row][col] == '#' || root->children[board[row][col] - 'a'] == NULL)
        {
            return;
        }

        root = root->children[board[row][col] - 'a'];

        if (root->wordEnd)
        {
            res.push_back(root->word);
            root->wordEnd = false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            dfs(board, nRow, nCol, root, res, n, m);
        }

        board[row][col] = temp;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int n = board.size();
        int m = board[0].size();

        TrieNode *root = getNode();

        for (string &word : words)
        {
            insert(root, word);
        }

        vector<string> result;

        // Traverse the board

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char ch = board[i][j];

                if (root->children[ch - 'a'] != NULL)
                {
                    dfs(board, i, j, root, result, n, m);
                }
            }
        }
    }
};

int main()
{

    return 0;
}