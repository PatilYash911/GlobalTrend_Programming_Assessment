#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main()
{
    int number = 12345;
    cout << "Sum of digits of " << number << " is " << sumOfDigits(number) << endl;
    return 0;
}
