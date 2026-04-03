#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    list<Goat> trip;
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    for (int i = 0; i < 11; i++){
        add_goat(trip, names, colors);
    }

    display_trip(trip);

    return 0;
}

int main_menu(){
    int choice;
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice --> ";
    cin >> choice;

    //error handling
    //Checking if input is int and is in range.
    while (!cin || choice < 1 || choice > 4){
        if (!cin) {
            //clear error and clear buffer
            cin.clear();
            cin.ignore(10000, '\n');
        }
        cout << "Please enter a valid choice.\n";
        cout << "Choice --> ";
        cin >> choice;
    }

    return choice;
}

void add_goat(list<Goat> &trip, string names [], string colors []){
    //creating the new goat
    Goat new_goat = Goat(names[rand() % SZ_NAMES], (rand() % MAX_AGE) + 1, colors[rand() % SZ_COLORS]);
    //pushing the goat to the end of the trip
    trip.push_back(new_goat);
}

void display_trip(list<Goat> trip){
    int i = 1;
    for (Goat g : trip) {
        cout << '[' << i << "] ";
        cout << g.get_name() << " ";
        cout << "(" << g.get_age() << ", " << g.get_color() << ")\n";
        i++;
    }
}

