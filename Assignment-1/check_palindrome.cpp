// author:Aryanthepain
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count_digits(ll num)
{
    int no_of_digits = 0;
    while (num != 0)
    {
        no_of_digits++;
        num /= 10;
    }
    return no_of_digits;
}

ll reverse_number(ll x)
{
    ll y = 0;

    while (x != 0)
    {
        y = y * 10 + x % 10;
        x = x / 10;
    }

    return y;
}

bool check_palindrome(ll num)
{
    ll palindrome = reverse_number(num);

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
        int palindrome_count = 0;

        cout << "palindromes:" << endl;

        vector<ll> palindromes;
        for (ll i = 3; i <= digits; i++)
        {
            ll temp = number;

            // check if temp is a palindrome 'i' digits at a time
            while (temp >= 100)
            {
                ll curr = temp % (power(10, i));
                if (check_palindrome(curr))
                {
                    bool palindrome_already_found = false;

                    // check if palindrome already exists
                    for (int i = 0; i < palindromes.size(); i++)
                    {
                        if (curr == palindromes[i])
                        {
                            palindrome_already_found = true;
                            break;
                        }
                    }

                    if (!palindrome_already_found)
                    {
                        palindromes.push_back(curr);
                        cout << curr << endl;
                        palindrome_count++;
                    }
                }
                temp /= 10;
            }
        }
        cout << "No of palindromes:" << palindrome_count << endl;
        cout << "==============" << endl;
    }

    return 0;
}
