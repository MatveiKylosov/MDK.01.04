#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;
struct Employee {
    string firstName;
    string lastName;
    string patronymic;
    string birthDate;
    string education;
    string address;
    string profession;
};
void writeToFile() {
    ofstream file("employees.txt");

    Employee employees[4] = {
        {"Иван", "Иванов", "Иванович", "01.01.1980", "Высшее", "Москва, ул. Пушкина, д. 1", "Программист"},
        {"Мария", "Петрова", "Сергеевна", "02.02.1985", "Среднее", "Санкт-Петербург, ул. Ленина, д. 2", "Менеджер"},
        {"Алексей", "Смирнов", "Петрович", "03.03.1975", "Высшее", "Казань, ул. Горького, д. 3", "Инженер"},
        {"Елена", "Кузнецова", "Алексеевна", "04.04.1990", "Среднее", "Екатеринбург, ул. Чехова, д. 4", "Маркетолог"}
    };

    for (int i = 0; i < 4; ++i) {
        file << employees[i].firstName << endl
            << employees[i].lastName << endl
            << employees[i].patronymic << endl
            << employees[i].birthDate << endl
            << employees[i].education << endl
            << employees[i].address << endl
            << employees[i].profession << endl;
    }

    file.close();
}
void readFromFile() {
    ifstream file("employees.txt");
    if (!file) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }
    Employee emp;
    cout << "Сотрудники с высшим образованием:\n";
    while (getline(file, emp.firstName) &&
        getline(file, emp.lastName) &&
        getline(file, emp.patronymic) &&
        getline(file, emp.birthDate) &&
        getline(file, emp.education) &&
        getline(file, emp.address) &&
        getline(file, emp.profession)) {
        if (emp.education == "Высшее") {
            cout << emp.firstName << " " << emp.lastName << endl;
        }
    }
    file.clear();
    file.seekg(0);
    string profession;
    cout << "\nВведите профессию для поиска: ";
    cin >> profession;
    cin.ignore();
    cout << "Данные о сотруднике с профессией " << profession << ":\n";
    while (getline(file, emp.firstName) &&
        getline(file, emp.lastName) &&
        getline(file, emp.patronymic) &&
        getline(file, emp.birthDate) &&
        getline(file, emp.education) &&
        getline(file, emp.address) &&
        getline(file, emp.profession)) {
        if (emp.profession == profession) {
            cout << "Имя: " << emp.firstName << endl;
            cout << "Фамилия: " << emp.lastName << endl;
            cout << "Отчество: " << emp.patronymic << endl;
            cout << "Дата рождения: " << emp.birthDate << endl;
            cout << "Образование: " << emp.education << endl;
            cout << "Адрес: " << emp.address << endl;
        }
    }

    file.close();
}
int main() {
    system("cls");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    writeToFile();
    readFromFile();
    return 0;
}
