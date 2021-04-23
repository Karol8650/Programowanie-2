#include <iostream>
#include <fstream>
using namespace std;

enum Level {
    SEVERE = 6,
    WARNING = 5,
    INFO = 4,
    CONFIG = 3,
    FINE = 2,
    FINER = 1,
    FINEST = 0
};

class Dziennik {
private:
    Level level;

public:
    void changeLevel(Level level) {
        this->level = level;
    }

    void logSevere(string message) {
        cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
        char choice;
        cin >> choice;
        if(choice == 'k') {
            if(level >= SEVERE)
            cout << level << " " << message + "\n";
        }
        else if(choice == 'p') {
            if(level >= SEVERE) {
                ofstream myfile;
                myfile.open("log.txt", fstream::out | fstream::app);
                myfile << level << " " << message + "\n";
                myfile.close();
            }
        }
    }

    void logWarning(string message) {
        cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
        char choice;
        cin >> choice;
        if(choice == 'k') {
            if(level >= WARNING)
            cout << level << " " << message + "\n";
        }
        else if(choice == 'p') {
            if(level >= WARNING) {
                ofstream myfile;
                myfile.open("log.txt", fstream::out | fstream::app);
                myfile << level << " " << message + "\n";
                myfile.close();
            }
        }
    }

    void logInfo(string message) {
        cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
        char choice;
        cin >> choice;
        if(choice == 'k') {
            if(level >= INFO)
            cout << level << " " << message + "\n";
        }
        else if(choice == 'p') {
            if(level >= INFO) {
                ofstream myfile;
                myfile.open("log.txt", fstream::out | fstream::app);
                myfile << level << " " << message + "\n";
                myfile.close();
            }
        }
    }

    void logConfig(string message) {
        cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
        char choice;
        cin >> choice;
        if(choice == 'k') {
            if(level >= CONFIG)
            cout << level << " " << message + "\n";
        }
        else if(choice == 'p') {
            if(level >= CONFIG) {
                ofstream myfile;
                myfile.open("log.txt", fstream::out | fstream::app);
                myfile << level << " " << message + "\n";
                myfile.close();
            }
        }
    }

    void logFine(string message) {
        cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
        char choice;
        cin >> choice;
        if(choice == 'k') {
            if(level >= FINE)
            cout << level << " " << message + "\n";
        }
        else if(choice == 'p') {
            if(level >= FINE) {
                ofstream myfile;
                myfile.open("log.txt", fstream::out | fstream::app);
                myfile << level << " " << message + "\n";
                myfile.close();
            }
        }
    }

    void logFiner(string message) {
        cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
        char choice;
        cin >> choice;
        if(choice == 'k') {
            if(level >= FINER)
            cout << level << " " << message + "\n";
        }
        else if(choice == 'p') {
            if(level >= FINER) {
                ofstream myfile;
                myfile.open("log.txt", fstream::out | fstream::app);
                myfile << level << " " << message + "\n";
                myfile.close();
            }
        }
    }

    void logFinest(string message) {
        cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
        char choice;
        cin >> choice;
        if(choice == 'k') {
            if(level >= FINEST)
            cout << level << " " << message + "\n";
        }
        else if(choice == 'p') {
            if(level >= FINEST) {
                ofstream myfile;
                myfile.open("log.txt", fstream::out | fstream::app);
                myfile << level << " " << message + "\n";
                myfile.close();
            }
        }
    }


};


int main() {
    Dziennik dziennik;
    dziennik.changeLevel(WARNING);
    dziennik.logSevere("savere");
    dziennik.changeLevel(FINER);
    dziennik.logInfo("info");
    dziennik.logFiner("finer");
}