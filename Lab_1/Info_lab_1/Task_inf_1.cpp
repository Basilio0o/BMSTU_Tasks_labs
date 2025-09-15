#include <iostream>
using namespace std;
int main()
{
    double income;
    cout << "Enter your income ";
    cin >> income;
    if (income <= 50000)
    {
        cout << "Your tax is " << income * 0.13 << endl;
    }
    else if (5000 < income <= 100000)
    {
        cout << "Your tax is " << income * 0.2 << endl;
    }
    else
    {
        cout << "Your tax is " << income * 0.25 << endl;
    }
    return 0;
}