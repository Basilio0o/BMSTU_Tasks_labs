#include <iostream>
using namespace std;
int main(void)
{
    for (int i = 1; i < 11; i++)
    {
        if (i == 1)
        {
            cout << "Цена за " << i << " plate is " << 10 << endl; 
        }
        else
        {
            cout << "Price of " << i << " plates is " << i * 10 << endl;
        }
    }
    return 0;
}