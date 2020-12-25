#include <stdio.h>
#include <math.h>

#define PI 3.141592653598793

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
    double start, end;
    double degree;
    int n;

    double result = 0;

    printf("Enter start>>");
    scanf("%lf", &start);
    printf("Enter end>>");
    scanf("%lf", &end);

    printf("Enter n>>");
    scanf("%d", &n);

    printf("Enter degree>>");
    scanf("%lf", &degree);

    for (int i = 0; i < n; i++)
    {
        double x = start + i * (end - start) / n;

        result += function(x, degree);
    }

    result *= (end - start) / n;

    printf("%.15lf\n", result);

    return 0;
}