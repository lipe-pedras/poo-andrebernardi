// prova_bimestral.h
#ifndef PROVA_BIMESTRAL_H
#define PROVA_BIMESTRAL_H

#include <iostream>
#include <vector>

using namespace std;

class prova_bimestral
{
private:
    int num_q;               // numero de questoes
    vector<string> questoes; // enunciados da prova
    float nota;              // nota da prova
    string materia;          // nome do aluno
public:
    prova_bimestral();
    prova_bimestral(int num_q, vector<string> questoes, float nota, string materia);
    ~prova_bimestral();

    int getNumQuestoes() const;
    string getQuestao(int) const;
    float getNota() const;
    string getMateria() const;

    friend istream &operator>>(istream &in, prova_bimestral &p);
    friend ostream &operator<<(ostream *out, const prova_bimestral &p);
};

#endif
