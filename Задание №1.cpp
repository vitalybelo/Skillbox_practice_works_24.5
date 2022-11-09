#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

struct Case {
    string caseName;
    time_t startTime{0};
    time_t finishTime{0};
    long caseDuration{0};
    bool caseFinished = false;
};

string getCommand();
string getTimeString (long n_time);
void finishCase (Case &c);

int main() {
    setlocale(LC_ALL, "Russian");

    string comm;
    vector<Case> events;
    do {
        int i = (int) events.size() - 1;
        comm = getCommand();
        // BEGIN
        if (comm == "begin" || comm == "new") {
            // заканчиваем предыдущее дело
            if (i > -1 && !events[i].caseFinished) {
                finishCase(events[i]);
            }
            // начинаем новое дело
            Case newCase;
            cout << "\tВведите название нового дела: ";
            getline(cin,newCase.caseName);
            if (!newCase.caseName.empty())
            {
                newCase.startTime = time(nullptr);
                newCase.finishTime = newCase.startTime;
                newCase.caseDuration = 0;
                events.push_back(newCase);
            }
            // STATUS
        } else if (comm == "status" || comm == "list") {
            cout << "\n\tСписок дел (" << events.size() << ") ::" << endl;
            for (Case & c : events) {
                cout << "\tНазвание: " << c.caseName << "  :: продолжительность: ";
                cout << (c.caseFinished ? getTimeString(c.caseDuration) + " завершено" : "выполняется") << endl;
            }
            // END
        } else if (comm == "end" || comm == "finish") {
            if (i > -1)
                finishCase(events[i]);
        }

    } while (comm != "exit");
    return 0;
}


string getCommand() {
    cout << "\nВведите команду: ";
    string command;
    getline(cin,command);
    for (char & i : command) {
        i = (char) tolower(i);
    }
    return command;
}

string getTimeString (long n_time) {
    string s = to_string(n_time / 3600) + ":";
    n_time %= 3600;
    s += to_string(n_time / 60) + ":";
    n_time %= 60;
    s += to_string(n_time);
    return s;
}

void finishCase (Case &c) {
    if (!c.caseFinished) {
        c.caseFinished = true;
        c.finishTime = time(nullptr);
        c.caseDuration = (long) difftime(c.finishTime, c.startTime);
    }
}

