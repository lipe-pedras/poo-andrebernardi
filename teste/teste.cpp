#include <iostream>
#include <cmath>

int main()
{
    double rho_esp = 7.86;
    double c, Dmed, dint, erroDmed, errodint, n, rho_esp, rho_gli, vel, errovel, erro_rho_esp, erro_rho_gli, erroC;
    double g = 9.78520, errog = 0.00004;
    erroC = (Dmed / dint) * ((1 + 9 * Dmed) / (2 * dint)) * sqrt( pow((erroDmed / Dmed), 2) + pow((errodint / dint), 2) );
    c = (9 * Dmed / 4 * dint) * sqrt( pow((erroDmed / Dmed), 2) + pow((errodint/dint), 2) )
    n = (pow(Dmed, 2) / 18) * ((rho_esp - rho_gli) / (vel * (1 + c))) * g;

    double erroN = n * sqrt( (pow((2*erroDmed/ Dmed), 2)) + pow((errog/g), 2) + pow((errovel/vel), 2) + pow( ( (sqrt( (erro_rho_esp * erro_rho_esp + erro_rho_gli * erro_rho_gli) ) / rho_esp - rho_gli) ), 2) + pow( (erroC / 1+c), 2));
}