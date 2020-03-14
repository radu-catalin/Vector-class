#include <iostream>

using namespace std;

char *errorMsg[20] = {
    "Vectori alesi au dimensiuni diferite"};

class Vector
{
public:
    double *v;   // vector
    int context; // numarul de componente
public:
    Vector(double, int);
    Vector(Vector &);
    // ~Vector(Vector&);
    void change(double, int);
    void read(istream &);
    void print(ostream &out);
    friend istream &operator>>(istream &, Vector &);
    friend ostream &operator<<(ostream &, Vector &);
    Vector &operator=(Vector &vect);
    friend Vector &operator+(Vector &, Vector &);
    friend Vector &operator-(Vector &, Vector &);
    friend Vector &operator+=(Vector &, Vector &);
    friend Vector &operator-=(Vector &, Vector &);
    friend bool operator==(Vector &, Vector &);
    friend int length(Vector &);
};

Vector::Vector(double x = 0, int n = 0)
{
    this->change(x, n);
}

Vector::Vector(Vector &vect)
{
    double *v = new double[vect.context];
    for (int i = 0; i < vect.context; i++)
    {
        v[i] = vect.v[i];
    }
    this->v = v;
    this->context = vect.context;
}

void Vector::change(double x, int n)
{
    this->v = new double[n];
    this->context = n;
    for (int i = 0; i < n; i++)
    {
        this->v[i] = x;
    }
}

void Vector::read(istream &in)
{
    cout << "Number of components: ";
    in >> this->context;
    cout << "Vector: ";
    double *v = new double[this->context];
    for (int i = 0; i < this->context; i++)
    {
        in >> v[i];
    }
    this->v = v;
    cout << "reading is finished\n";
}

void Vector::print(ostream &out)
{
    out << "Number of components: " << this->context << "\n";
    out << "Vector ";
    for (int i = 0; i < this->context; i++)
    {
        out << this->v[i] << " ";
    }
    out << "\n";
}

istream &operator>>(istream &in, Vector &vect)
{
    vect.read(in);
    return in;
}

ostream &operator<<(ostream &out, Vector &vect)
{
    vect.print(out);
    return out;
}

Vector &Vector::operator=(Vector &vect)
{
    double *v = new double[vect.context];
    for (int i = 0; i < vect.context; i++)
    {
        this->v[i] = vect.v[i];
    }
    this->context = vect.context;
}

Vector &operator+(Vector &v1, Vector &v2)
{
    try
    {
        if (v1.context != v2.context)
        {
            throw 0;
        }
        Vector *vect = new Vector(0, v1.context);

        vect->context = v1.context;
        for (int i = 0; i < v1.context; i++)
        {
            vect->v[i] = v1.v[i] + v2.v[i];
            cout << vect->v[i];
        }

        return *vect;
    }
    catch (int code)
    {
        cout << errorMsg[code];
    }
}

Vector &operator-(Vector &v1, Vector &v2)
{
    try
    {
        if (v1.context != v2.context)
        {
            throw 0;
        }
        Vector *vect = new Vector(0, v1.context);

        vect->context = v1.context;
        for (int i = 0; i < v1.context; i++)
        {
            vect->v[i] = v1.v[i] - v2.v[i];
        }

        return *vect;
    }
    catch (int code)
    {
        cout << errorMsg[code];
    }
}

Vector &operator+=(Vector &v1, Vector &v2)
{
    return v1 + v2;
}

Vector &operator-=(Vector &v1, Vector &v2)
{
    return v1 - v2;
}

bool operator==(Vector &v1, Vector &v2)
{
    if (v1.context != v2.context)
    {
        return false;
    }

    for (int i = 0; i < v1.context; i++)
    {
        if (v1.v[i] != v2.v[i])
        {
            return false;
        }
    }

    return true;
}

bool operator!=(Vector &v1, Vector &v2)
{
    if (v1.context != v2.context)
    {
        return true;
    }

    for (int i = 0; i < v1.context; i++)
    {
        if (v1.v[i] != v2.v[i])
        {
            return true;
        }
    }

    return false;
}

int length(Vector &vect)
{
    return vect.context;
}

int main()
{
    Vector v1(1, 3), v2(1, 3);
    v1.change(3.5, 4);
    return 0;
}
