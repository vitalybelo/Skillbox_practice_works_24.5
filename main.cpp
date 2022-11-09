#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include <map>
#include "windows.h"
using namespace std;

struct Person {
    string name;
    struct tm birthday;
};

tm getDateInput () {

    time_t t = time(nullptr);
    struct tm* oneDate = localtime(&t);

    cout << "\tВведите дату в формате YYYY/mm/dd: ";
    while (true) {
        cin >> get_time(oneDate, "%Y/%m/%d");
        if (cin && oneDate->tm_year >= 0) break;
        cerr << "\tНеверный формат, попробуйте еще раз: ";
        cin.clear();
        fflush(stdin);
    }

    if (oneDate->tm_year >= 1970) {
        // создаем корректные даты если это не раньше < 1970 года
        t = mktime(oneDate);
        oneDate = localtime(&t);
    }
    cout << "\t" << asctime(oneDate) << endl;
    return *oneDate;
}

string getDateString (struct tm &oneDate) {
    string mon = to_string(oneDate.tm_mon + 1);
    if (mon.length() == 1) mon = "0" + mon;
    string day = to_string(oneDate.tm_mday);
    if (day.length() == 1) day = "0" + day;
    return mon + day;
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person person{};
    vector<Person> friends;

    do {
        cin.clear();
        fflush(stdin);

        cout << "Введите имя: ";
        getline(cin, person.name);
        if (!person.name.empty() && person.name != "end")
        {
            person.birthday = getDateInput();
            friends.push_back(person);
        }

    } while (person.name != "end");

    cout << endl;
    for (Person & p : friends) {
        cout << "Name: " << p.name << " :: " << asctime(&p.birthday) << endl;
    }

    return 0;
}

