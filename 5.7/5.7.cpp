#include <iostream>
#include <time.h>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

void InA(int[], int);
void Ulitka(int[], int);

int main()
{
    int n;
    setlocale(LC_ALL, "rus");

    cout << " ¬введите пор€док матрицы " << endl;
    cin >> n;

    int* a = new int[n * n];
    InA(a, n);
    Ulitka(a, n);

    delete[] a;

    return 0;
}

void InA(int a[], int n) //ввод 1д
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int v;

    do
    {
        cout << " 0 - по умолчанию, 1 - рандом, 2 - ввод" << endl;
        cin >> v;
        cout << endl;
    } while (v != 0 && v != 1 && v != 2);

    if (v == 0) //умолчание
    {
        for (int i = 0; i < n * n; i++)
        {
            a[i] = i;
            cout << " " << a[i];
        }
        cout << endl;
    }

    if (v == 1) //рандом
    {
        for (int i = 0; i < n * n; i++)
        {
            a[i] = rand() % 10;
            cout << " " << a[i];
        }
        cout << endl;
    }

    if (v == 2) //ввод
    {
        for (int i = 0; i < n * n; i++)
            cin >> a[i];
        cout << endl;
    }

    return;
}

void Ulitka(int a[], int n) //вывод 2д из 1д
{
    float** b = new float* [n]; //строки
    for (int i = 0; i < n; i++)
        b[i] = new float[n]; //столбцы

    for (int i = 0; i < n; i++) //в ноль
        for (int j = 0; j < n; j++)
            b[i][j] = 0;

    int z = 1, t, i = 1;
    int y = (n - 1) / 2, x = (n - 1) / 2;
    b[y][x] = a[0];
    x += 1;

    //for (int i = 1; i < n*n; i++) //улитка //!!!n*n
    while (x < n && y < n)
    {
        i++;
        if (z == 1)
        {
            if (i % 2 == 0) i--;
            cout << "(" << y << "/" << x << ")";
            for (t = 0; t < i; t++)
            {
                b[y + t][x] = a[t + 1]; cout << "+";
            }
            y += t;
        }

        if (z == 2)
        {
            cout << "(" << y << "/" << x << ")";
            for (t = 0; t < i; t++)
            {
                b[y][x - t] = a[t + 1]; cout << "+";
            }
            x -= t;
        }

        if (z == 3)
        {
            if (i % 2 == 1) i--;
            cout << "(" << y << "/" << x << ")";
            for (t = 0; t < i; t++)
            {
                b[y - t][x] = a[t + 1]; cout << "+";
            }
            y -= t;
        }

        if (z == 4)
        {
            if (i % 2 == 1) i--;
            cout << "(" << y << "/" << x << ")";
            for (t = 0; t < i; t++)
            {
                b[y][x + t] = a[t + 1]; cout << "+";
            }
            x += t + 1;
        }

        cout << z << " ";

        z += 1;
        if (z == 5)
            z -= 4;
    }

    cout << endl;
    for (int i = 0; i < n; i++) //вывод
    {
        for (int j = 0; j < n; j++)
            cout << setw(3) << b[i][j];
        cout << endl;
    }

    for (int i = 0; i < n; i++) //удаление
        delete[] b[i];

    return;
}