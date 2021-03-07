#include <iostream>
using namespace std;

struct Wyksztalcenie
{
    std::string poziom = "srednie";
    std::string jednostka = "liceum";
};

struct Czlowiek
{
    std::string imie = "Jan";
    std::string nazwisko = "Nowak";
    unsigned short wiek = 20;
    Wyksztalcenie* szkola;
};

int main() {

    Wyksztalcenie wyksztalcenie;
    Wyksztalcenie* wsk = &wyksztalcenie;
    Czlowiek czlowiek;
    czlowiek.szkola = wsk;

}
