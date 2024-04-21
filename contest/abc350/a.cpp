#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, abc, num;
    cin >> s;

    for (int i = 0; i < 6; i++)
    {
        if (i > 2)
        {
            num.push_back(s[i]);
        }
        else
        {
            abc.push_back(s[i]);
        }
    }

    int n = stoi(num);
    bool flg = true;
    if (abc != "ABC")
    {
        flg = false;
    }
    else if (n == 316)
    {
        flg = false;
    }
    else if (n <= 0 || n >= 350)
    {
        flg = false;
    }

    if (flg)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}