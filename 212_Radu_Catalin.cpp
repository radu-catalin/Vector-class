#include <iostream>

using namespace std;

char* errorMsg[30] = {
    "ERROR 0: Vectorii alesi au dimensiuni diferite"
};

class Vector {
    private:
        double *v; // vector
        int context; // numarul de componente
    public:
        Vector(double, int);
        Vector(Vector&);
        void change(double, int);
        void read(istream&);
        void print(ostream &out);
        friend istream& operator>>(istream&, Vector&);
        friend ostream& operator<<(ostream&, Vector&);
        Vector& operator=(Vector &vect);
        friend Vector& operator+(Vector&, Vector&);
        friend Vector& operator-(Vector&, Vector&);
        friend Vector& operator+=(Vector&, Vector&);
        friend Vector& operator-=(Vector&, Vector&);
        friend bool operator==(Vector&, Vector&);
        friend bool operator!=(Vector&, Vector&);
        friend int length(Vector&);
        friend void readObjects(int&);
};

Vector::Vector(double x = 0, int n = 0) {
    this->change(x, n);
}

Vector::Vector(Vector &vect) {
    double *v = new double[vect.context];
    for(int i = 0; i < vect.context; i++) {
        v[i] = vect.v[i];
    }
    this->v = v;
    this->context = vect.context;
}

void Vector::change(double x, int n) {
    this->v = new double[n];
    this->context = n;
    for(int i = 0; i < n; i++) {
        this->v[i] = x;
    }
}

void Vector::read(istream &in) {
    cout << "Numarul de componente: ";
    in >> this->context;
    cout << "Vector: ";
    double *v = new double[this->context];
    for(int i = 0; i < this->context; i++) {
        in >> v[i];
    }
    this->v = v;
}

void Vector::print(ostream &out) {
    for(int i = 0; i < this->context; i++) {
        out << this->v[i] << " ";
    }
    out << "\n";
}

istream& operator>>(istream& in, Vector& vect) {
    vect.read(in);
    return in;
}

ostream& operator<<(ostream& out, Vector& vect) {
    vect.print(out);
    return out;
}

Vector& Vector::operator=(Vector &vect) {
    double *v = new double[vect.context];
    for(int i = 0; i < vect.context; i++) {
        this->v[i] = vect.v[i];
    }
    this->context = vect.context;
}

Vector& operator+(Vector& v1, Vector& v2) {
    try {
        if(v1.context != v2.context) {
            throw 0;
        }
        Vector *vect = new Vector(0, v1.context);

        vect->context = v1.context;
        for(int i = 0; i < v1.context; i++) {
            vect->v[i] = v1.v[i] + v2.v[i];
        }

        return *vect;

    } catch(int code) {
        system("cls");
        cout << errorMsg[code];
    }
}

Vector& operator-(Vector& v1, Vector& v2) {
    try {
        if(v1.context != v2.context) {
            throw 0;
        }
        Vector *vect = new Vector(0, v1.context);

        vect->context = v1.context;
        for(int i = 0; i < v1.context; i++) {
            vect->v[i] = v1.v[i] - v2.v[i];
        }

        return *vect;

    } catch(int code) {
        system("cls");
        cout << errorMsg[code];
    }
}

Vector& operator+=(Vector& v1, Vector& v2) {
    return v1 + v2;
}

Vector& operator-=(Vector& v1, Vector& v2) {
    return v1 - v2;
}


bool operator==(Vector &v1, Vector& v2) {
    if(v1.context != v2.context) {
        return false;
    }

    for(int i = 0; i < v1.context; i++) {
        if(v1.v[i] != v2.v[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(Vector &v1, Vector& v2) {
    if(v1.context != v2.context) {
        return true;
    }

    for(int i = 0; i < v1.context; i++) {
        if(v1.v[i] != v2.v[i]) {
            return true;
        }
    }

    return false;
}

int length(Vector& vect) {
    return vect.context;
}

void readObjects(int n) {
    Vector* object = new Vector[n];

    for(int i = 0; i < n; i++) {
        cout << "v" << i + 1 << ":\n";
        cin >> object[i];
        cout << "\n";
    }
    system("cls");
    cout << "Vectorii cititi sunt:\n";
    for(int i = 0; i < n; i++) {
        cout << "v" << i + 1 <<": ";
        cout << object[i];
    }
}

// Menu Class
class Menu {
    private:
        Vector v1;
        Vector v2;
    public:
        Menu() {
            this->menu();
        }
    private:
        void menu();
        void option0();
        void option1();
        void option2();
        void option3();
        void option4();
        void option5();
        void readVectors();
        void backToMenu();
};

void Menu::menu() {
    cout << "Alege o optiune:\n\n";
    cout << "0. Aduna doi vectori\n";
    cout << "1. Scade doi vectori\n";
    cout << "2. Verifica daca doi vectori sunt egali\n";
    cout << "3. Verifica daca doi vectori sunt diferiti\n";
    cout << "4. Verifica lungimea unui vector\n";
    cout << "5. Citeste si afiseaza n obiecte\n";
    cout << "6. Iesi din meniu\n";

    int opt;
    cin >> opt;

    switch(opt) {
        case 0:
            this->option0();
        break;
        case 1:
            this->option1();
        break;
        case 2:
            this->option2();
        break;
        case 3:
            this->option3();
        break;
        case 4:
            this->option4();
        break;
        case 5:
            this->option5();
        break;
    }
}

void Menu::option0() {
    this->readVectors();
    cout << "v1 + v2 = ";
    cout << v1 + v2;
    this->backToMenu();
}

void Menu::option1() {
    this->readVectors();
    cout << "v1 - v2 = ";
    cout << v1 - v2;
    this->backToMenu();
}

void Menu::option2() {
    this->readVectors();
    if(v1 == v2) {
        cout << "Vectorii sunt egali\n";
    } else {
        cout << "Vectorii NU sunt egali\n";
    }
    this->backToMenu();
}

void Menu::option3() {
    this->readVectors();
    if(v1 != v2) {
        cout << "Vectorii sunt diferiti\n";
    } else {
        cout << "Vectorii NU sunt diferiti\n";
    }
    this->backToMenu();
}

void Menu::option4() {
    system("cls");
    cout << "v:\n";
    cin >> v1;
    cout << "\n";
    cout << "Lungimea vectorului este: " << length(v1);
    this->backToMenu();

}

void Menu::option5() {
    system("cls");
    int n;
    cout << "Numarul de obiecte: ";
    cin >> n;
    cout << "\n";
    readObjects(n);
    this->backToMenu();
}
void Menu::readVectors() {
    system("cls");
    cout << "v1:\n";
    cin >> v1;
    cout << "\nv2:\n";
    cin >> v2;
    cout << "\n";
}

void Menu::backToMenu() {
    char opt;
    cout << "Apasa orice tasta urmata de enter pentru a te intoarce in meniu\n";
    cin >> opt;
    system("cls");
    this->menu();
}



int main()
{
    new Menu(); // Deschid meniul
    return 0;
}
