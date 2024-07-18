#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> charSet;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.size(); ++end)
    {
        char currentChar = s[end];

        while (charSet.find(currentChar) != charSet.end())
        {
            charSet.erase(s[start]);
            ++start;
        }

        charSet.insert(currentChar);
        int currentLength = end - start + 1;
        maxLength = max(maxLength, currentLength);
    }

    return maxLength;
}

int main()
{
    string input = "ssssss";
    int length = lengthOfLongestSubstring(input);
    cout << length << endl;
    return 0;
}
