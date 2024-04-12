#include <iostream>
#include <vector>
#include <string>
#include "retangulo.h"

int pow(int, int);
int fatorial_aux(int);
void fatorial(void);
void primos(void);
void Imprime_Menu(void);
void retangulo_na_tela(void);
void soma_aux(void);
void soma(void);
void mdc_aux(void);
void mdc(void);
void binario(void);
void palindromo(void);

using namespace std;

int pow(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}

inline int fatorial_aux(int n)
{
    return (n < 2 ? 1 : n * fatorial_aux(n - 1));
}

void fatorial()
{
    int numero;
    cout << "Digite o numero cujo fatorial sera calculado.\n";
    cin >> numero;
    cout << fatorial_aux(numero);
}

void primos()
{
    vector<int> primos;
    vector<int> divisores;
    int num = 2;

    do
    {
        for (int element : primos)
        {
            if (num % element == 0)
            {
                divisores.push_back(num);
            }
        }

        if (size(divisores) == 0)
        {
            primos.push_back(num);
        }
        num++;
        divisores.clear();
    } while (size(primos) < 20);

    for (int element : primos)
    {
        cout << element << " ";
    }
    cout << endl;
}

void Imprime_Menu()
{
    int escolha, sair = 1;
    while (sair)
    {
        cout << "\n\nMenu de Opcoes\n1.Fatorial\n2.Primos\n3.Menu de Opcoes\n4.Retangulo Na Tela\n5.Soma\n6.MDC\n7.Binario\n8.Palindromo\n9.Sair\n";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            fatorial();
            break;

        case 2:
            primos();
            break;

        case 3:
            for ( char z = 0; z < 2; z++ ) {}
            break;

        case 4:
            retangulo_na_tela();
            break;

        case 5:
            soma();
            break;

        case 6:
            mdc();
            break;

        case 7:
            binario();
            break;

        case 8:
            palindromo();
            break;

        case 9:
            sair = 0;
            break;

        default:
            cout << "Digite apenas um dos numeros indexados no menu!";
            break;
        }
    }
}

void retangulo_na_tela()
{
    int largura, altura;
    char borda, preenchimento;
    bool preencher;

    cout << "Qual sera a largura e a altura do retangulo?\n";
    cin >> largura >> altura;

    cout << "Qual caracter deve ser usado como borda? E qual deve ser usado para o preenchimento?\n";
    cin >> borda >> preenchimento;

    cout << "O retangulo deve ser preenchido? [0/1]\n";
    cin >> preencher;

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (i == 0 || i == (altura - 1) || j == 0 || j == (largura - 1))
            {
                cout << borda;
            }
            else
            {
                if (preencher)
                {
                    cout << preenchimento;
                }
                else
                {
                    if (i == 1 || i == (altura - 2) || j == 1 || j == (largura - 2))
                    {
                        cout << preenchimento;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << "\n";
    }
}

int soma_aux(int n)
{
    if (n == 0)
        return 0;
    else
        return n + soma_aux(n - 1);
}

void soma()
{
    int n;

    cout << "Entre com o numero de inteiros a serem somados.\n";
    cin >> n;
    cout << "A soma eh " << soma_aux(n);
}

int mdc_aux(int a, int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a == b)
        return a;
    else if (a > b)
    {
        if ((a % b) == 0)
            return b;
        else
            return mdc_aux(b, a % b);
    }
    else
        return mdc_aux(b, a);
}

void mdc()
{
    int a, b;
    cout << "Digite os numeros cujo MDC deseja ser encontrado.\n";
    cin >> a >> b;

    cout << "O MDC entre " << a << " e " << b << " eh " << mdc_aux(a, b);
}

void binario()
{
    int binario, novo = 0, i = 0;

    cout << "numero em binario.\n";
    cin >> binario;

    while (binario >= 10)
    {
        novo += (binario % 10) * pow(2, i);
        binario /= 10;
        i++;
    }

    novo += binario * pow(2, i);

    cout << novo;
}

bool is_palindromo(int number)
{
    string snum = to_string(number);
    int len = snum.length();

    if (len != 7)
        return false;
    else
    {
        for (int i = 0; i < len / 2; i++)
        {
            if (snum[i] != snum[len - i - 1])
                return false;
        }
        return true;
    }
}

void palindromo()
{
    int num;
    string Snum;

    while (true)
    {
        cout << "Digite um palindromo de 7 digitos.\n";
        cin >> num;

        if (is_palindromo(num))
        {
            cout << "O numero digitado eh um palindromo.\n";
            break;
        }
        else
        {
            cout << "O numero digitado nao eh um palindromo.\n";
        }
    }
}

int main()
{
    Imprime_Menu();

    Retangulo retangulo(20, 5);
    cout << "\n\nComprimento: " << retangulo.getComprimento();
    cout << "\nLargura: " << retangulo.getLargura();
    cout << "\nArea: " << retangulo.getArea();
    cout << "\nPerimetro: " << retangulo.getPerimetro();
    cout << "\nQuadrado? " << (retangulo.Is_Square() ? "Sim\n" : "Nao\n");
    retangulo.printRetangulo();

    return 0;
}
