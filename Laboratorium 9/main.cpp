#include <iostream>
#include <algorithm>
#include <iomanip>

class Macierz2D {

    static const int m_rozmiar = 3;
    float** m_dane;

public:
    Macierz2D();
    Macierz2D(float);
    Macierz2D(float**);
    Macierz2D(const Macierz2D&);
    Macierz2D(std::initializer_list<float>);
    static int get_rozmiar() ;
    float getField(int, int) const;
    void setField(int, int, float);
    Macierz2D& operator++();
    Macierz2D& operator++(int);
    Macierz2D& operator--();
    Macierz2D& operator--(int);
    Macierz2D& operator+=(const Macierz2D&);
    Macierz2D& operator-=(const Macierz2D&);
    Macierz2D& operator*(int);
    Macierz2D& operator*=(int);
    Macierz2D& operator*=(const Macierz2D&);
    Macierz2D& operator=(const Macierz2D&);
    ~Macierz2D();

};

Macierz2D::Macierz2D() {

    this->m_dane = new float*[m_rozmiar];
    for(int i = 0; i < m_rozmiar; ++i)
        m_dane[i] = new float[m_rozmiar];

}

Macierz2D::Macierz2D(const Macierz2D & inna_macierz) : Macierz2D(){
    *this = inna_macierz;
}

Macierz2D::Macierz2D(float x) : Macierz2D() {
    for(int i = 0; i < m_rozmiar; i++) {
        for(int j = 0; j < m_rozmiar; j++) {
            this->m_dane[i][j] = x;
        }
    }
}

Macierz2D::Macierz2D(float **m_dane)  {
    this->m_dane = m_dane;
}

Macierz2D::Macierz2D(std::initializer_list<float> list) : Macierz2D() {
    int i = 0, j = 0;
    for (float n : list) {
        m_dane[i][j] = n;
        if(j == 2)
            i++;
        j = (j + 1) % 3;
    }

}

int Macierz2D::get_rozmiar() {
    return m_rozmiar;
}

float Macierz2D::getField(int x, int y) const {
    return m_dane[x][y];
}

void Macierz2D::setField(int x, int y, float wartosc) {
    m_dane[x][y] = wartosc;
}

Macierz2D operator+(const Macierz2D& macierz1, const Macierz2D& macierz2) {
    Macierz2D macierz_suma;
    float wartosc;
    int rozmiar = macierz1.get_rozmiar();

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            wartosc = macierz1.getField(i, j) + macierz2.getField(i, j);
            macierz_suma.setField(i, j, wartosc);
        }
    }

    return macierz_suma;
}

Macierz2D operator-(const Macierz2D& macierz1, const Macierz2D& macierz2) {
    Macierz2D macierz_roznica;
    float wartosc;
    int rozmiar = macierz1.get_rozmiar();

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            wartosc = macierz1.getField(i, j) - macierz2.getField(i, j);
            macierz_roznica.setField(i, j, wartosc);
        }
    }

    return macierz_roznica;
}

Macierz2D operator*(const Macierz2D& macierz1, const Macierz2D& macierz2) {
    Macierz2D macierz_iloczyn;
    float wartosc;
    int rozmiar = macierz1.get_rozmiar();

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            macierz_iloczyn.setField(i, j, 0);
            wartosc = 0;
            for (int k = 0; k < rozmiar; k++) {
                wartosc += macierz1.getField(i, k) * macierz2.getField(k, j);
            }
            macierz_iloczyn.setField(i, j, wartosc);
        }
    }

    return macierz_iloczyn;
}

std::ostream& operator<<(std::ostream& wyjscie, const Macierz2D& macierz) {
    wyjscie << macierz.getField(0, 0) << " " << macierz.getField(0, 1) << " " << macierz.getField(0, 2) << std::endl
            << macierz.getField(1, 0) << " " << macierz.getField(1, 1) << " " << macierz.getField(1, 2) << std::endl
            << macierz.getField(2, 0) << " " << macierz.getField(2, 1) << " " << macierz.getField(2, 2) << std::endl;
    return wyjscie;
}

std::istream& operator>>(std::istream& wejscie, const Macierz2D& macierz) {
    wejscie >> macierz.getField(0, 0) >> macierz.getField(0, 1) >> macierz.getField(0, 2)
            >> macierz.getField(1, 0) >> macierz.getField(1, 1) >> macierz.getField(1, 2)
            >> macierz.getField(2, 0) >> macierz.getField(2, 1) >> macierz.getField(2, 2);

    return wejscie;
}

Macierz2D& Macierz2D::operator++() {
    const int rozmiar = Macierz2D::get_rozmiar();
    for (int i = 0; i < rozmiar; i++) {
        for(int j = 0; j < rozmiar; j++) {
            this->m_dane[i][j] += 1;
        }
    }
    return *this;
}

Macierz2D& Macierz2D::operator++(int) {
    Macierz2D przed_inkr = *this;
    const int rozmiar = Macierz2D::get_rozmiar();
    for (int i = 0; i < rozmiar; i++) {
        for(int j = 0; j < rozmiar; j++) {
            this->m_dane[i][j] += 1;
        }
    }
    return przed_inkr;
}

Macierz2D& Macierz2D::operator--() {
    const int rozmiar = Macierz2D::get_rozmiar();
    for (int i = 0; i < rozmiar; ++i) {
        for(int j = 0; j < rozmiar; j++) {
            this->m_dane[i][j] -= 1;
        }
    }
    return *this;
}

Macierz2D& Macierz2D::operator--(int) {
    Macierz2D przed_dekr = *this;
    const int rozmiar = Macierz2D::get_rozmiar();
    for (int i = 0; i < rozmiar; ++i) {
        for(int j = 0; j < rozmiar; j++) {
            this->m_dane[i][j] -= 1;
        }
    }
    return przed_dekr;
}

Macierz2D& Macierz2D::operator+=(const Macierz2D& inna_macierz) {
    *this = *this + inna_macierz;
    return *this;
}

Macierz2D& Macierz2D::operator-=(const Macierz2D& inna_macierz) {
    *this = *this - inna_macierz;
    return *this;
}

Macierz2D& Macierz2D::operator*(int calkowita) {
    Macierz2D wynik;
    for (int i = 0; i < m_rozmiar; i++) {
        for (int j = 0; j < m_rozmiar; j++) {
            float wartosc = m_dane[i][j] * calkowita;
            wynik.setField(i, j, wartosc);
        }
    }
    return wynik;
}

Macierz2D& Macierz2D::operator*=(int calkowita) {
    for (int i = 0; i < m_rozmiar; i++) {
        for (int j = 0; j < m_rozmiar; j++) {
            m_dane[i][j] *= calkowita;
        }
    }
    return *this;
}

Macierz2D& Macierz2D::operator=(const Macierz2D& inny) {
    int rozmiar = get_rozmiar();
    for (int i = 0; i < rozmiar; i++) {
        for(int j = 0; j < rozmiar; j++) {
            float wartosc = inny.getField(i, j);
            this->m_dane[i][j] = wartosc;
        }
    }
    return *this;
}

Macierz2D &Macierz2D::operator*=(const Macierz2D& inna_macierz) {
    *this = *this * inna_macierz;
    return *this;
}

bool operator<(const Macierz2D& macierz1, const Macierz2D& macierz2) {
    float wartosc;
    int rozmiar = macierz1.get_rozmiar();
    for(int i = 0; i < rozmiar; i++) {
        for(int j = 0; j < rozmiar; j++) {
            if(macierz1.getField(i,j) < macierz2.getField(i,j))
                return true;
            if(macierz1.getField(i,j) > macierz2.getField(i,j))
                return false;
        }
    }
    return false;
}


Macierz2D::~Macierz2D() {
    for(int i = 0; i < m_rozmiar; ++i) {
        delete[] m_dane[i];
        m_dane[i] = NULL;
    }
    delete[] m_dane;
    m_dane = NULL;
}

Macierz2D macierzJednostkowa() {
    Macierz2D macierz;
    int rozmiar = macierz.get_rozmiar();
    for(int i = 0; i < rozmiar; i++) {
        for(int j = 0; j < rozmiar; j++) {
            if(i == j)
                macierz.setField(i, j, 1);
            else
                macierz.setField(i, j, 0);
        }
    }
    return macierz;
}

Macierz2D transpozycja(Macierz2D macierz) {
    int rozmiar = macierz.get_rozmiar();
    for(int i = 0; i < rozmiar; i++) {
        for(int j = i + 1; j < rozmiar; j++) {
                float temp = macierz.getField(i, j);
                macierz.setField(i, j, macierz.getField(j, i));
                macierz.setField(j, i, temp);
        }
    }
    return macierz;
}


int main() {

    const int rozmiar = 3;
    const int ilosc_macierzy = 3;

    float** tab1 = new float*[rozmiar];
    float** tab2 = new float*[rozmiar];
    float** tab3 = new float*[rozmiar];

    tab1[0] = new float[rozmiar]{4, 8, 3};
    tab1[1] = new float[rozmiar]{5, 3, 2};
    tab1[2] = new float[rozmiar]{5, 5, 6};

    tab2[0] = new float[rozmiar]{4, 7, 3};
    tab2[1] = new float[rozmiar]{6, 3, 7};
    tab2[2] = new float[rozmiar]{5, 3, 2};

    tab3[0] = new float[rozmiar]{4, 7, 3};
    tab3[1] = new float[rozmiar]{1, 3, 4};
    tab3[2] = new float[rozmiar]{8, 9, 6};

    Macierz2D macierze[ilosc_macierzy] = {Macierz2D(tab1), Macierz2D(tab2), Macierz2D(tab3)};

    std::sort(macierze, macierze + 3);

    std::cout << "Po sortowaniu: " << std::endl;
    std::cout << macierze[0] << std::endl;
    std::cout << macierze[1] << std::endl;
    std::cout << macierze[2] << std::endl;

    Macierz2D macierz_iloczyn = macierze[0] * macierze[1];

    std::cout << macierze[0].getField(0, 0) << std::setw(5) << macierze[0].getField(0, 1) << std::setw(5) << macierze[0].getField(0, 2)
    << std::setw(10) << macierze[1].getField(0, 0) << std::setw(5) << macierze[1].getField(0, 1) << std::setw(5) << macierze[1].getField(0, 2)
    << std::setw(10) << macierz_iloczyn.getField(0, 0) << std::setw(5) << macierz_iloczyn.getField(0, 1) << std::setw(5) << macierz_iloczyn.getField(0, 2);
    std::cout << std::endl;

    std::cout << macierze[0].getField(1, 0) << std::setw(5) << macierze[0].getField(1, 1) << std::setw(5) << macierze[0].getField(1, 2)
    << std::setw(5) << "*" << std::setw(5) << macierze[1].getField(1, 0) << std::setw(5) << macierze[1].getField(1, 1) << std::setw(5) << macierze[1].getField(1, 2)
    << std::setw(5) << "=" << std::setw(5) << macierz_iloczyn.getField(1, 0) << std::setw(5) << macierz_iloczyn.getField(1, 1) << std::setw(5) << macierz_iloczyn.getField(1, 2);
    std::cout << std::endl;

    std::cout << macierze[0].getField(2, 0) << std::setw(5) << macierze[0].getField(2, 1) << std::setw(5) << macierze[0].getField(2, 2)
    << std::setw(10) << macierze[1].getField(2, 0) << std::setw(5) << macierze[1].getField(2, 1) << std::setw(5) << macierze[1].getField(2, 2)
    << std::setw(10) << macierz_iloczyn.getField(2, 0) << std::setw(5) << macierz_iloczyn.getField(2, 1) << std::setw(5) << macierz_iloczyn.getField(2, 2);

}
