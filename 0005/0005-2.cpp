#include <iostream>
#include <cmath>

#define PI 3.1415926535

using namespace std;

double toRadian(double degree)
{
    return degree * PI / 180;
}

double function(double x, double degree)
{
    return (1 - cos(toRadian(degree))) / 2 * (cos(toRadian(2 * PI * x)) + 1);
}

int main()
{
    double a, b;
    double degree;
    int n;

    cout << "Enter a>>";
    cin >> a;
    cout << "Enter b>>";
    cin >> b;
    cout << "Enter degree>>";
    cin >> degree;
    cout << "Enter n>>";
    cin >> n;

    double result = 0;

    for (int i = 0; i < n; i++)
    {
        double x = a + (b - a) * i * n;
        result += function(x, degree);
    }

    result *= (b - a) / n;

    cout << "Result: " << result << endl;

    return 0;
}