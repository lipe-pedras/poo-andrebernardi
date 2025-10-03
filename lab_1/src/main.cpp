#include <iostream>
#include <vector>
#include <string>
#include "rectangle.h"

int power(int, int);
int factorial_aux(int);
void factorial(void);
void primes(void);
void display_menu(void);
void rectangle_on_screen(void);
int sum_aux(int);
void sum(void);
int gcd_aux(int, int);
void gcd(void);
void binary(void);
void palindrome(void);

using namespace std;

int power(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}

inline int factorial_aux(int n)
{
    return (n < 2 ? 1 : n * factorial_aux(n - 1));
}

void factorial()
{
    int number;
    cout << "Enter the number to calculate factorial.\n";
    cin >> number;
    cout << factorial_aux(number);
}

void primes()
{
    vector<int> primes;
    vector<int> divisors;
    int num = 2;

    do
    {
        for (int element : primes)
        {
            if (num % element == 0)
            {
                divisors.push_back(num);
            }
        }

        if (divisors.size() == 0)
        {
            primes.push_back(num);
        }
        num++;
        divisors.clear();
    } while (primes.size() < 20);

    for (int element : primes)
    {
        cout << element << " ";
    }
    cout << endl;
}

void display_menu()
{
    int choice, exit = 1;
    while (exit)
    {
        cout << "\n\nOptions Menu\n1.Factorial\n2.Primes\n3.Options Menu\n4.Rectangle on Screen\n5.Sum\n6.GCD\n7.Binary\n8.Palindrome\n9.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            factorial();
            break;

        case 2:
            primes();
            break;

        case 3:
            for ( char z = 0; z < 2; z++ ) {}
            break;

        case 4:
            rectangle_on_screen();
            break;

        case 5:
            sum();
            break;

        case 6:
            gcd();
            break;

        case 7:
            binary();
            break;

        case 8:
            palindrome();
            break;

        case 9:
            exit = 0;
            break;

        default:
            cout << "Please enter only one of the numbers from the menu!";
            break;
        }
    }
}

void rectangle_on_screen()
{
    int width, height;
    char border, fill;
    bool should_fill;

    cout << "What will be the width and height of the rectangle?\n";
    cin >> width >> height;

    cout << "Which character should be used as border? And which should be used for filling?\n";
    cin >> border >> fill;

    cout << "Should the rectangle be filled? [0/1]\n";
    cin >> should_fill;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1))
            {
                cout << border;
            }
            else
            {
                if (should_fill)
                {
                    cout << fill;
                }
                else
                {
                    if (i == 1 || i == (height - 2) || j == 1 || j == (width - 2))
                    {
                        cout << fill;
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

int sum_aux(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sum_aux(n - 1);
}

void sum()
{
    int n;

    cout << "Enter the number of integers to be added.\n";
    cin >> n;
    cout << "The sum is " << sum_aux(n);
}

int gcd_aux(int a, int b)
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
            return gcd_aux(b, a % b);
    }
    else
        return gcd_aux(b, a);
}

void gcd()
{
    int a, b;
    cout << "Enter the numbers whose GCD you want to find.\n";
    cin >> a >> b;

    cout << "The GCD between " << a << " and " << b << " is " << gcd_aux(a, b);
}

void binary()
{
    int binary, new_num = 0, i = 0;

    cout << "Enter binary number.\n";
    cin >> binary;

    while (binary >= 10)
    {
        new_num += (binary % 10) * power(2, i);
        binary /= 10;
        i++;
    }

    new_num += binary * power(2, i);

    cout << new_num;
}

bool is_palindrome(int number)
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

void palindrome()
{
    int num;
    string Snum;

    while (true)
    {
        cout << "Enter a 7-digit palindrome.\n";
        cin >> num;

        if (is_palindrome(num))
        {
            cout << "The entered number is a palindrome.\n";
            break;
        }
        else
        {
            cout << "The entered number is not a palindrome.\n";
        }
    }
}

int main()
{
    display_menu();

    Rectangle rectangle(20, 5);
    cout << "\n\nLength: " << rectangle.getLength();
    cout << "\nWidth: " << rectangle.getWidth();
    cout << "\nArea: " << rectangle.getArea();
    cout << "\nPerimeter: " << rectangle.getPerimeter();
    cout << "\nSquare? " << (rectangle.isSquare() ? "Yes\n" : "No\n");
    rectangle.printRectangle();

    return 0;
}