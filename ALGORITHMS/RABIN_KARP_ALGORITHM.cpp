/*

//BRUTE FORCE

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void searchPattern(string &text, string &pattern) // Pass By Reference
    {
        int n = text.length();
        int m = pattern.length();
        int j;
        for (int i = 0; i <= n - m; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (pattern[j] != text[i + j])
                {
                    break;
                }
            }
            if (j == m)
            {
                cout << "index = " << i << "\n";
            }
        }
    }
};

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    Solution obj;
    obj.searchPattern(text, pattern);
    return 0;
}


Output:

index = 0
index = 9
index = 12

Time complexity: O(m*(n-m+1)) [Worst case time complexity] where m = length of pattern, n = length of text.

Space complexity: O(1)

*/





