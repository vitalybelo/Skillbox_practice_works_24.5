#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include "windows.h"
#include <map>
using namespace std;

struct Person {
    string name;
    struct tm birthday{};
};

tm getDateInput ();
string getKeyString (struct Person &p);
string getPersonString (struct Person &p);
int solveDatePuzzle (tm &oneDate);

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person person{};
    vector<Person> friends;
    map<string, int> friendsList;

    do {
        cin.clear();
        fflush(stdin);

        cout << "Введите имя: ";
        getline(cin, person.name);
        if (!person.name.empty() && person.name != "end")
        {
            person.birthday = getDateInput();
            friends.push_back(person);
            string key = getKeyString(person);
            int value = (int)(friends.size() - 1);
            friendsList.insert(pair<string, int>(key, value));
        }

    } while (person.name != "end");

    bool upDated = true;
    bool isToday = true;
    bool isAhead = true;
    cout << "\nВывод результатов:\n";
    auto iter = friendsList.begin();

    for (; iter != friendsList.end(); iter++) {
        int i = iter->second;
        switch (solveDatePuzzle(friends.at(i).birthday)) {
            case -1:
                if (upDated) {
                    cout << "\nСписок дней рождения, которые уже прошли:\n";
                    upDated = false;
                }
                cout << "\t" << getPersonString(friends.at(i)) << endl;
                break;
            case 0:
                if (isToday) {
                    cout << "\nСегодня мы поздравляем с днем рождения:\n";
                    isToday = false;
                }
                cout << "\t" << getPersonString(friends.at(i)) << endl;
                break;
            case 1:
                if (isAhead) {
                    cout << "\nСписок тех, кого нужно не забыть поздравить:\n";
                    isAhead = false;
                }
                cout << "\t" << getPersonString(friends.at(i)) << endl;
                break;
        }
    }
    cout << "\n\nВывод списка результатов завершен\n";

    return 0;
}

tm getDateInput () {

    time_t t = time(nullptr);
    struct tm* oneDate = localtime(&t);

    cout << "\tВведите дату в формате YYYY/mm/dd: ";
    while (true) {
        cin >> get_time(oneDate, "%Y/%m/%d");
        if (cin && oneDate->tm_year > 0)
            break;
        cerr << "\tНеверный формат, попробуйте еще раз: ";
        cin.clear();
        fflush(stdin);
    }
    if (oneDate->tm_year >= 70) {
        t = mktime(oneDate);
        oneDate = localtime(&t);
    }
    return *oneDate;
}

string getKeyString (struct Person &p) {
    string mon = to_string(p.birthday.tm_mon + 1);
    if (mon.length() == 1) mon = "0" + mon;
    string day = to_string(p.birthday.tm_mday);
    if (day.length() == 1) day = "0" + day;
    return mon + "." + day + " " + p.name;
}

string getPersonString (struct Person &p) {
    string months[] {"январь","февраль","март","апрель","май","июнь","июль","август",
                     "сентябрь","октябрь","ноябрь","декабрь"};

    string s = "Имя: " + p.name + " день рождения: ";
    string day = to_string(p.birthday.tm_mday);
    if (day.length() == 1) day = "0" + day;

    s += day + " " + months[p.birthday.tm_mon];
    return s;
}

int solveDatePuzzle (tm &oneDate) {

    time_t now = time(nullptr);
    tm* today = localtime(&now);

    if (oneDate.tm_mon < today->tm_mon) return -1;

    if (oneDate.tm_mon == today->tm_mon) {
        if (oneDate.tm_mday < today->tm_mday) {
            return -1;
        } else if (oneDate.tm_mday == today->tm_mday) {
            return 0;
        }
    }
    return 1;
}
