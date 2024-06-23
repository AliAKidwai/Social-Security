#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

// Person - stores the name and social security number
class Person {
public:
    char Firstname[128];
    char Lastname[128];
    int Socialsecurity;
};

// getperson - read a person object from the keyboard and return a copy to the caller
Person getperson() {
    Person person;

    cout << "Enter first name: ";
    cin >> person.Firstname;

    cout << "Enter last name: ";
    cin >> person.Lastname;

    cout << "Enter Social security number: ";
    cin >> person.Socialsecurity;

    return person;
}

// getpeople - read an array of person objects; return the number read
int getpeople(Person people[], int maxsize) {
    int index;
    for (index = 0; index < maxsize; index++) {
        char Answer;
        cout << "Enter another name? (Y or N): ";
        cin >> Answer;
        if (Answer != 'Y' && Answer != 'y') {
            break;
        }
        people[index] = getperson();
    }
    return index;
}

// displayperson - display a person on the default display
void displayperson(Person person) {
    cout << "First name: " << person.Firstname << endl;
    cout << "Last name: " << person.Lastname << endl;
    cout << "Social security number: " << person.Socialsecurity << endl;
}

// displaypeople - display an array of person objects
void displaypeople(Person people[], int ncount) {
    for (int index = 0; index < ncount; index++) {
        displayperson(people[index]);
    }
}

// sortpeople - sort an array of count person objects by social security number (using bubble sort)
void sortpeople(Person people[], int ncount) {
    int nswaps = 1;
    while (nswaps != 0) {
        nswaps = 0;
        for (int n = 0; n < (ncount - 1); n++) {
            if (people[n].Socialsecurity > people[n + 1].Socialsecurity) {
                swap(people[n], people[n + 1]);
                nswaps++;
            }
        }
    }
}

int main() {
    // allocate room for some names
    Person people[128];

    // prompt the user for input
    cout << "Read name/social security information" << endl;
    int ncount = getpeople(people, 128);

    // sort the list
    sortpeople(people, ncount);

    // now display the results
    cout << "Here is the list sorted by social security number" << endl;
    displaypeople(people, ncount);

    return 0;
}