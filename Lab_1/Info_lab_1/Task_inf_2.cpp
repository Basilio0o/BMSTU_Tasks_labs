#include <iostream>
using namespace std;
int main(void)
{
    cout << "| quantity | price    |" << endl;
    for (int i = 1; i < 11; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "_";
        
        }
        cout << "\n|";
        cout.width(4); // метод для установки ширины вывода
        cout << i;
        cout << " pcs. | ";
        cout.width(3);
        cout << i*10; 
        cout << " rub. |"<< endl;
    }
    return 0;
}