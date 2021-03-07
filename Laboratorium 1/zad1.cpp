#include <iostream>
using namespace std;

void getStringUsername(string tab[]) {

    int num;
    cout << "Podaj ilosc nazwisk: ";
    cin >> num;

    for(int i = 0; i < num; i++) {
        cout << i + 1 << " nazwisko: ";
        cin >> tab[i];
    }

}

int getCharUsername(char* tab[]) {

    int num;
    cout << "Podaj ilosc nazwisk: ";
    cin >> num;

    int lengthOfUsername;

    for(int i = 0; i < num; i++) {
        cout << "Podaj dlugosc nazwiska: ";
        cin >> lengthOfUsername;

        tab[i] = new char[lengthOfUsername + 1];

        cout << i + 1 << " nazwisko: ";
        cin >> tab[i];
        *(tab[i] + lengthOfUsername) = '\0';
    }

    return num;

}


int main() {

    const int size = 100;

    string tabString[size];
    char* tabChar[size];

    getStringUsername(tabString);
    int num = getCharUsername(tabChar);

    for(int i = 0; i < num; i++) {
        delete [] tabChar[i];
        tabChar[i] = nullptr;
    }


    return 0;

}