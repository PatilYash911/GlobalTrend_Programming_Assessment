#include <bits/stdc++.h>
using namespace std;

bool isAlphabetic(string &str)
{
    for (char ch : str)
    {
        if (!(ch >= 'a' && ch <= 'z') && !(ch >= 'A' && ch <= 'Z'))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string input1 = "HelloWorld";
    string input2 = "Hello123";

    cout << (isAlphabetic(input1) ? "Yes" : "No") << endl;
    cout << (isAlphabetic(input2) ? "Yes" : "No") << endl;

    return 0;
}
