#include <string>

using namespace std;

#ifndef POLIGONO_H
#define POLIGONO_H

class Poligono
{
private:
    int n;
    float c;

public:
    Poligono(int n, float c);
    ~Poligono();

    void set(int, float);
    string nome () const;
    float area();
    float perimetro();

};

#endif