#include <iostream>
#include <string>
#include "windows.h"
using namespace std;
struct Trip {
    int train_number;       
    string destination;     
    string days;            
    string arrival_time;    
    double cost;            
};
bool containsDay(const string& days, const string& day) {
    int i = 0, j = 0;
    while (i < days.length()) {
        while (i < days.length() && days[i] == ' ') {
            i++;
        }
        j = 0;
        while (i + j < days.length() && j < day.length() && days[i + j] == day[j]) {
            j++;
        }
        if (j == day.length() && (i + j == days.length() || days[i + j] == ' ')) {
            return true;
        }
        while (i < days.length() && days[i] != ' ') {
            i++;
        }
    }
    return false;
}
int main() {
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите количество поездок: ";
    cin >> n;
    cin.ignore(); 
    Trip* trips = new Trip[n];
    for (int i = 0; i < n; ++i) {
        cout << "\nПоездка " << i + 1 << ":\n";
        cout << "Введите номер поезда: ";
        cin >> trips[i].train_number;
        cin.ignore();
        cout << "Введите пункт назначения: ";
        getline(cin, trips[i].destination);
        cout << "Введите дни следования (например: Понедельник Среда): ";
        getline(cin, trips[i].days);
        cout << "Введите время прибытия (например, 15:30): ";
        cin >> trips[i].arrival_time;
        cout << "Введите стоимость: ";
        cin >> trips[i].cost;
        cin.ignore();
    }
    cout << "\nВведите пункт назначения для поиска: ";
    string target_destination;
    getline(cin, target_destination);
    cout << "\nПоезда, следующие в " << target_destination << " в понедельник или среду:\n";
    for (int i = 0; i < n; ++i) {
        if (trips[i].destination == target_destination &&
            (containsDay(trips[i].days, "Понедельник") || containsDay(trips[i].days, "Среда"))) {
            cout << "Номер поезда: " << trips[i].train_number
                << ", Время прибытия: " << trips[i].arrival_time
                << ", Стоимость: " << trips[i].cost << endl;
        }
    }
    delete[] trips;
    return 0;
}
