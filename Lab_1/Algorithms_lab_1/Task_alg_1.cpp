#include <iostream> //Подключение библиотеки для определения функций ввода/вывода

using namespace std; //Определяем пространство имён

void Input(int arr[10])
{
    for (int i = 0; i < 10; i++){
        cin >> arr[i];
    }
}

void Output(int arr[10])
{
    for (int i = 0; i < 10; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int Sum(int arr[10])
{
    int s = 0;
    for (int i = 0; i < 10; i++){
        s += arr[i];
    }
    return s;
}

int Minimum(int arr[10])
{
    int mn = arr[0];
    for (int i = 1; i < 10; i++){
        if (arr[i] < mn) mn = arr[i];
    }
    return mn;
}

void BubbleSort(int arr[10])
{
    int temp = 0;
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10 - i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int array[10];
    cout << "Enter numbers:\n";
    Input(array);
    cout << "The unsorted array: ";
    Output(array);
    cout << "Sum of the elements of the array is " << Sum(array) << endl;
    cout << "The minimal element of the array is " << Minimum(array) << endl;
    BubbleSort(array);
    cout << "The sorted array: ";
    Output(array);
    return 0;
}