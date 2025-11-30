// 6)Write a program to construct and verify a magic square of order 'n' (for both even
// & odd) such that all rows, columns, and diagonals sum to the same value.
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void printSquare(vector<vector<int>> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << "\n";
    }
}

bool verify(vector<vector<int>> &a)
{
    int n = a.size();
    int sum = 0;

    for (int j = 0; j < n; j++)
        sum += a[0][j];

    for (int i = 0; i < n; i++)
    {
        int r = 0, c = 0;
        for (int j = 0; j < n; j++)
        {
            r += a[i][j];
            c += a[j][i];
        }
        if (r != sum || c != sum)
            return false;
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++)
    {
        d1 += a[i][i];
        d2 += a[i][n - 1 - i];
    }
    return (d1 == sum && d2 == sum);
}

vector<vector<int>> oddMagic(int n)
{
    vector<vector<int>> a(n, vector<int>(n, 0));
    int i = 0, j = n / 2, num = 1;

    while (num <= n * n)
    {
        a[i][j] = num++;
        int ni = (i - 1 + n) % n;
        int nj = (j + 1) % n;
        if (a[ni][nj] != 0)
            i = (i + 1) % n;
        else
        {
            i = ni;
            j = nj;
        }
    }
    return a;
}

vector<vector<int>> doublyEvenMagic(int n)
{
    vector<vector<int>> a(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = i * n + j + 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i % 4 == j % 4) || ((i % 4) + (j % 4) == 3))
                a[i][j] = n * n + 1 - a[i][j];

    return a;
}

int main()
{
    int n;
    cout << "Enter order n (>=3): ";
    cin >> n;

    if (n < 3)
    {
        cout << "n must be >= 3\n";
        return 0;
    }

    vector<vector<int>> m;

    if (n % 2 == 1)
    {
        m = oddMagic(n);
        printSquare(m);
    }
    else if (n % 4 == 0)
    {
        m = doublyEvenMagic(n);
        printSquare(m);
    }
    else
    {
        cout << "Singly-even (6,10,14...) NOT supported in simple version.\n";
        return 0;
    }

    cout << (verify(m) ? "Magic Square Verified\n" : "Not a Magic Square\n");

    return 0;
}
