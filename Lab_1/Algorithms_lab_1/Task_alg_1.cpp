#include <iostream>

using namespace std;

void Input(int arr[], int n)
{
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

void Output(int arr[], int n)
{
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int Sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++){
        s += arr[i];
    }
    return s;
}

int Minimum(int arr[], int n)
{
    int mn = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] < mn) mn = arr[i];
    }
    return mn;
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int len = 0;
    cout << "Enter the number of elements:\n";
    cin >> len;
    int array[len];
    cout << "Enter numbers:\n";
    Input(array, len);
    cout << "The unsorted array: ";
    Output(array, len);
    cout << "Sum of the elements of the array is " << Sum(array, len) << endl;
    cout << "The minimal element of the array is " << Minimum(array, len) << endl;
    BubbleSort(array, len);
    cout << "The sorted array: ";
    Output(array, len);
    cout << "Have a nice day)";
    return 0;
}