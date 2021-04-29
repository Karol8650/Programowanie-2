#include <iostream>
#include <fstream>
using namespace std;

class Dziennik {

private:

    enum Level {
        SEVERE = 6,
        WARNING = 5,
        INFO = 4,
        CONFIG = 3,
        FINE = 2,
        FINER = 1,
        FINEST = 0
    };

    Level level;
    ofstream myFile;

    void consoleMessage(Level level, string message);

    void fileMessage(Level level, string message);

public:

    void changeLevel(string str);

    void logSevere(string message);

    void logWarning(string message);

    void logInfo(string message);

    void logConfig(string message);

    void logFine(string message);

    void logFiner(string message);

    void logFinest(string message);


};

void Dziennik::consoleMessage(Dziennik::Level level, string message) {
    cout << level << " " << message + "\n";
}

void Dziennik::fileMessage(Dziennik::Level level, string message) {
    myFile.open("log.txt", ios::out);
    if(myFile.is_open()) {
        myFile << level << " " << message + "\n";
        myFile.close();
    }
    else {
        cout << "Blad otwarcia pliku" << endl;
    }
}

void Dziennik::changeLevel(string str) {
    if(str == "SEVERE")
        level = SEVERE;
    else if(str == "WARNING")
        level = WARNING;
    else if(str == "INFO")
        level = INFO;
    else if(str == "CONFIG")
        level = CONFIG;
    else if(str == "FINE")
        level = FINE;
    else if(str == "FINER")
        level = FINER;
    else if(str == "FINEST")
        level = FINEST;
}

void Dziennik::logSevere(string message) {
    cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
    char choice;
    cin >> choice;
    if(choice == 'k') {
        if(level >= SEVERE)
            consoleMessage(level, message);
    }
    else if(choice == 'p') {
        if(level >= SEVERE) {
            fileMessage(level, message);
        }
    }
}

void Dziennik::logWarning(string message) {
    cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
    char choice;
    cin >> choice;
    if(choice == 'k') {
        if(level >= WARNING)
            consoleMessage(level, message);
    }
    else if(choice == 'p') {
        if(level >= WARNING) {
            fileMessage(level, message);
        }
    }
}

void Dziennik::logInfo(string message) {
    cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
    char choice;
    cin >> choice;
    if(choice == 'k') {
        if(level >= INFO)
            consoleMessage(level, message);
    }
    else if(choice == 'p') {
        if(level >= INFO) {
            fileMessage(level, message);
        }
    }
}

void Dziennik::logConfig(string message) {
    cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
    char choice;
    cin >> choice;
    if(choice == 'k') {
        if(level >= CONFIG)
            consoleMessage(level, message);
    }
    else if(choice == 'p') {
        if(level >= CONFIG) {
            fileMessage(level, message);
        }
    }
}

void Dziennik::logFine(string message) {
    cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
    char choice;
    cin >> choice;
    if(choice == 'k') {
        if(level >= FINE)
            consoleMessage(level, message);
    }
    else if(choice == 'p') {
        if(level >= FINE) {
            fileMessage(level, message);
        }
    }
}

void Dziennik::logFiner(string message) {
    cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
    char choice;
    cin >> choice;
    if(choice == 'k') {
        if(level >= FINER)
            consoleMessage(level, message);
    }
    else if(choice == 'p') {
        if(level >= FINER) {
            fileMessage(level, message);
        }
    }
}

void Dziennik::logFinest(string message) {
    cout << "Zapisac komunikat w konsoli czy w pliku? Konsola - wcisnij k; pilk - wcisnij p\n";
    char choice;
    cin >> choice;
    if(choice == 'k') {
        if(level >= FINEST)
            consoleMessage(level, message);
    }
    else if(choice == 'p') {
        if(level >= FINEST) {
            fileMessage(level, message);
        }
    }
}


int main() {
    Dziennik dziennik;
    dziennik.changeLevel("WARNING");
    dziennik.logSevere("savere");
    dziennik.changeLevel("FINER");
    dziennik.logInfo("info");
    dziennik.logFiner("finer");
}
