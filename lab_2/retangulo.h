#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo
{
public:
    Retangulo(int c = 1, int l = 1);
    ~Retangulo();

    void setComprimento(int c);
    void setLargura(int l);
    int getComprimento() const;
    int getLargura() const;
    double getArea() const;
    double getPerimetro() const;
    void printRetangulo() const;
    bool Is_Square() const;

private:
    int comprimento;
    int largura;
};

#endif