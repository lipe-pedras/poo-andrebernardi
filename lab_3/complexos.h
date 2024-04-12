#include<vector>

using namespace std;

#ifndef COMPLEXOS_H
#define COMPLEXOS_H

class Complexo
{
    private:
        double r, c;
        static int count;

    protected:
    vector<double> polar(Complexo);
    Complexo retangular(vector<double>);

    public:
        Complexo soma(Complexo);
        Complexo subtracao(Complexo);
        Complexo multiplicacao(Complexo);
        Complexo divisao(Complexo);
        
        Complexo();
        Complexo(double, double);

        double modulo();
        void printRetangular();
        void printNumberOfComplexes();
};

#endif