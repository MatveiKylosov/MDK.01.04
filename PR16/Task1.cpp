#include <iostream>
#include "windows.h"
using namespace std;
bool isLucky(int ticket) {
    int firstHalf = ticket / 1000;
    int secondHalf = ticket % 1000;
    int sumFirstHalf = (firstHalf / 100) + (firstHalf / 10 % 10) + (firstHalf % 10);
    int sumSecondHalf = (secondHalf / 100) + (secondHalf / 10 % 10) + (secondHalf % 10);
    return sumFirstHalf == sumSecondHalf;
}
int main() {
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int M, N;
    cout << "Введите номер меньшего билета (M): ";
    cin >> M;
    cout << "Введите номер большего билета (N): ";
    cin >> N;
    int luckyCount = 0;
    for (int ticket = M; ticket <= N; ++ticket) {
        if (isLucky(ticket)) {
            luckyCount++;
        }
    }
    cout << "Количество счастливых билетов: " << luckyCount << endl;
}