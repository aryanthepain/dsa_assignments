// author:Aryanthepain
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count_digits(ll num)
{
    int count = 0;
    while (num != 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

bool check_palindrome(ll num)
{
    ll palindrome = 0;
    ll temp = num;
    while (temp != 0)
    {
        palindrome = palindrome * 10 + temp % 10;
        temp = temp / 10;
    }
    if (num == palindrome)
    {
        return true;
    }
    return false;
}

ll power(ll a, ll b)
{
    ll temp = 1;
    for (ll i = 0; i < b; i++)
    {
        temp *= a;
    }
    return temp;
}

int main()
{
    cout << "To check palindrome numbers from substrings of a given number" << endl;
    cout << "================" << endl;
    cout << "enter -1 to end program" << endl;
    while (1)
    {
        cout << "enter number to check palindromes(-1 to end program)" << endl;
        ll number;
        cin >> number;
        if (number == -1)
            return 0;

        int digits = count_digits(number); // number of digits of the input number
        int count = 0;                     // number of palindromes

        cout << "palindromes:" << endl;

        vector<ll> numbers;
        for (ll i = 3; i <= digits; i++)
        {
            ll temp = number;
            while (temp >= 100)
            {
                ll check = temp % (power(10, i));
                if (check_palindrome(check))
                {
                    int found = 0;
                    for (int i = 0; i < numbers.size(); i++)
                    {
                        if (check == numbers[i])
                        {
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0)
                    {
                        numbers.push_back(check);
                        cout << check << endl;
                        count++;
                    }
                }
                temp /= 10;
            }
        }
        cout << "No of palindromes:" << count << endl;
        cout << "==============" << endl;
    }

    return 0;
}
