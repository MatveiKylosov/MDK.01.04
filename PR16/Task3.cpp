#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    srand(time(0));
    
    const int SIZE = 10;
    int arr[SIZE];

    // Генерация случайных чисел
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100; // Числа от 0 до 99
    }

    // Вывод массива до сортировки
    cout << "Массив до сортировки: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, SIZE);

    // Вывод массива после сортировки
    cout << "Массив после сортировки: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
