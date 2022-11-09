#include <iostream>
#include <ctime>
#include <iomanip>
#include "windows.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    time_t now = time(nullptr);
    tm timerSet = *localtime(&now);
    cout << "\nУстановка таймера, введите интервал (MM:SS) : ";
    do {
        cin >> get_time(&timerSet, "%M:%S");
        if (cin.good()) break;

        cerr << "\tНеверный формат ввода, повторите: ";
        cin.clear();
        fflush(stdin);

    } while (true);

    now = time(nullptr);
    tm instantNow = *localtime(&now);
    timerSet.tm_min += instantNow.tm_min;
    timerSet.tm_sec += instantNow.tm_sec;
    time_t end = mktime(&timerSet);

    cout << endl;
    while (now < end) {

        time_t left_time = end - now;
        timerSet = *localtime(&left_time);
        cout << put_time(&timerSet,"%M:%S") << endl;
        Sleep(990);
        now = time(nullptr);
    }
    cout << "00:00\a\nDING DING DING\a\n\n";

    return 0;
}
