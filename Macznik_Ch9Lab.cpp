#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
// Structure to store snow condition data
struct SnowData {
    int date;
    double snowDepth;
};
// Function prototypes
void getData(SnowData snowConditions[], int days, const string& month, int startDay);
void sortData(SnowData snowConditions[], int days);
void displayData(const SnowData snowConditions[], int days, const string& month, int startDay);
int main() {
    const int days = 7;
    SnowData snowConditions[days];
    string month;
    int startDay;
    // Introduction
    cout << "This program keeps track of base snow conditions\nat the Alpine Heaven Resort.\n";
    cout << "Enter the month and starting date of the report\n(e.g. January 9): ";
    cin >> month >> startDay;
    getData(snowConditions, days, month, startDay);
    sortData(snowConditions, days);
    displayData(snowConditions, days, month, startDay);
    return 0;
}
// Function to collect data from the user
void getData(SnowData snowConditions[], int days, const string& month, int startDay) {
    for (int i = 0; i < days; i++) {
        snowConditions[i].date = startDay + i;
        do {
            cout << "Enter the base snow (in inches) for " << month << " " << snowConditions[i].date << ": ";
            cin >> snowConditions[i].snowDepth;
            if (snowConditions[i].snowDepth < 0) {
                cout << "Snow depth must be a positive number. Please re-enter.\n";
            }
        } while (snowConditions[i].snowDepth < 0);
    }
}
// Function to sort the data using bubble sort
void sortData(SnowData snowConditions[], int days) {
    bool swapped;
    for (int i = 0; i < days - 1; i++) {
        swapped = false;
        for (int j = 0; j < days - i - 1; j++) {
            if (snowConditions[j].snowDepth > snowConditions[j + 1].snowDepth) {
                swap(snowConditions[j], snowConditions[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
// Function to display the data in a tabular format
void displayData(const SnowData snowConditions[], int days, const string& month, int startDay) {
    cout << "\nSnow Report " << month << " " << startDay << " - " << startDay + days - 1 << endl;
    cout << "  Date   Base\n";
    for (int i = 0; i < days; i++) {
        cout << setw(7) << snowConditions[i].date << setw(8) << snowConditions[i].snowDepth << endl;
    }
}
