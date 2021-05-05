#include <iostream>

class Kapitan;
class Statek;
class StatekPasazerski;
class Mysliwiec;
class TransportowiecBojowy;



class Kapitan {
private:
    std::string imie;
    std::string nazwisko;
    int lataSluzby = 0;
    bool emerytura = false;
public:
    std::string get_imie() const;
    std::string get_nazwisko() const;

    Kapitan(std::string imie, std::string nazwisko, int lataSluzby, bool emerytura);
    Kapitan();
};

class Statek {
private:
    int m_zaloga = 0;
    std::string nazwa;
    int m_racje = 0;
    int size = 0;
    int* statek_tab;

protected:
    Kapitan m_kapitan;
public:
    virtual void oblicz_zywnosc();
    virtual void oblicz_zywnosc(bool desery);
    int get_zaloga() const;
    void werbunek(int);
    Kapitan get_kapitan() const;
    std::string get_nazwa() const;
    int get_racje();
    void set_racje(int);
    virtual void initialize_tab(int);
    virtual void printTab(int* tab);
    virtual int* get_tab();

    Statek(Kapitan kapitan, std::string nazwa, int zaloga);
    Statek();
    virtual ~Statek();

};

class StatekPasazerski: public virtual Statek {
private:
    int m_pasazerowie = 0;
    int size;
    int* pas_tab;

public:
    int get_pasazerowie() const;
    void set_pasazerowie(int pasazerowie);
    int liczba_osob() const;
    void oblicz_zywnosc() override;
    void oblicz_zywnosc(bool) override;
    void initialize_tab(int);
    int* get_tab() override;
    void printTab(int* tab) override;
    StatekPasazerski();
    StatekPasazerski(int);
    ~StatekPasazerski();
};

class Mysliwiec : public virtual Statek {
private:
    int liczba_wiezyczek = 1;
public:
    int get_wiezyczki() const { return liczba_wiezyczek; };
};


class TransportowiecBojowy : public StatekPasazerski, public Mysliwiec {
};

Kapitan::Kapitan(std::string imie, std::string nazwisko, int lataSluzby, bool emerytura) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->lataSluzby = lataSluzby;
    this->emerytura = emerytura;
}

Kapitan::Kapitan() {}

std::string Kapitan::get_imie() const{
    return imie;
}

std::string Kapitan::get_nazwisko() const{
    return nazwisko;
}


int Statek::get_zaloga() const {
    return m_zaloga;
}

void Statek::werbunek(int x) {
    if(x < 1) {
        std::cout << "bledne dane!\n";
        return;
    }
    m_zaloga += x;
}

Kapitan Statek::get_kapitan() const { return m_kapitan; }


Statek::Statek() : Statek(Kapitan("John", "Sheridan", 10
        , false), "White Star", 5){
}

Statek::Statek(Kapitan m_kapitan, std::string nazwa, int m_zaloga) {
    this->m_kapitan = m_kapitan;
    this->nazwa = nazwa;
    this->m_zaloga = m_zaloga;
}


Statek::~Statek() {
    if(size > 0)
        delete[] statek_tab;
    std::cout << "Zostal wywolany destruktor klasy Statek." << std::endl;
}

std::string Statek::get_nazwa() const{
    return nazwa;
}

void Statek::oblicz_zywnosc() {
    m_racje = 3 * m_zaloga;
}

void Statek::set_racje(int x) {
    m_racje = x;
}

int Statek::get_racje() {
    return m_racje;
}

void Statek::oblicz_zywnosc(bool desery) {
    if (desery)
    {
        m_racje = 4 * m_zaloga;
        return;
    }
    m_racje = 3 * m_zaloga;
}

void Statek::initialize_tab(int x) {

    if(x > 0) {
        if(size > 0)
            delete[] statek_tab;
        size = x;
        statek_tab = new int[x];
        for (int i = 0; i < x; i++)
            *(statek_tab + i) = i;
    }
    else
        std::cout << "za maly rozmiar";

}

void Statek::printTab(int* tab) {
    if(size > 0) {
        for(int i = 0; i < size; i++)
            std::cout << *(tab + i) << " ";
        std::cout << "\n";
    }
    else {
        std::cout << "tablica nie posiada elementow\n";
    }
}

int *Statek::get_tab() {
    return statek_tab;
}

void StatekPasazerski::set_pasazerowie(int pasazerowie) {
    m_pasazerowie = pasazerowie;
}

int StatekPasazerski::get_pasazerowie() const {
    return m_pasazerowie;
}

int StatekPasazerski::liczba_osob() const {
    return m_pasazerowie + get_zaloga();
}

StatekPasazerski::StatekPasazerski() {}

StatekPasazerski::StatekPasazerski(int x) {
    m_pasazerowie = x;
}

void StatekPasazerski::oblicz_zywnosc(bool x) {
    Statek::oblicz_zywnosc(x);
}

void StatekPasazerski::oblicz_zywnosc() {
    Statek::oblicz_zywnosc();
}

void StatekPasazerski::initialize_tab(int x) {
    if(x > 0) {
        if(size > 0)
            delete[] pas_tab;
        size = x;
        pas_tab = new int[x];
        for (int i = x - 1; i >= 0; i--)
            *(pas_tab + i) = i;
    }
    else
        std::cout << "za maly rozmiar";
}

StatekPasazerski::~StatekPasazerski() {
    if(size > 0)
        delete[] pas_tab;
    std::cout << "Zostal wywolany destruktor klasy StatekPasazerski." << std::endl;
}

int* StatekPasazerski::get_tab() {
    return pas_tab;
}

void StatekPasazerski::printTab(int *tab) {
    if(size > 0) {
        for(int i = 0; i < size; i++)
            std::cout << *(tab + i) << " ";
        std::cout << "\n";
    }
    else {
        std::cout << "tablica nie posiada elementow\n";
    }
}


std::ostream& operator <<(std::ostream &strumien, const Kapitan &kapitan) {
    strumien << "imie: " << kapitan.get_imie() << ", nazwisko: " << kapitan.get_nazwisko();
    return strumien;
}

std::ostream& operator <<(std::ostream &strumien, const Statek &statek) {
    strumien << "Kapitan: " << statek.get_kapitan() << ", nazwa: "
             << statek.get_nazwa() << ", liczba zalogi: " << statek.get_zaloga();
    return strumien;
}


int main() {

    Statek* statek = new StatekPasazerski;
    statek->initialize_tab(5);
    statek->printTab(statek->get_tab());
    statek->initialize_tab(7);
    statek->printTab(statek->get_tab());
    delete statek;

    std::cout << "\n\n";

    TransportowiecBojowy* trb = new TransportowiecBojowy();
// Statek wiozący 100 pasażerów:
    StatekPasazerski* z_pasazerami = new StatekPasazerski(100);
    Statek* tab_statki[] = { new Statek{}
            , new StatekPasazerski{}
            , new Statek(Kapitan("Susan", "Ivanova", 10, false), "Starfury", 1)
            , trb
            , z_pasazerami
    };
    for (Statek* statek : tab_statki)
    {
        std::cout << *statek << std::endl;
        statek->oblicz_zywnosc(false);
        std::cout << "Racje: " << statek->get_racje() << std::endl;
    }

    for(int i = 0; i < 5; i++) {
        delete tab_statki[i];
    }


}
