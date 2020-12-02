// 입력받은 연립방정식의 해를 가우스-조던 소거법을 써서 구함
// 이 프로그램은 10원 연립방정식의 해 까지를 구할 수 있음.
// augmented matrix 는 첨가행렬 또는 확장행렬로 번역한다.

#include <stdio.h>
// #include <stdlib.h>
#include <math.h>
#define eps 0.000000001

void printMatrix(double mat[10][11], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    double amat[10][11], v;
    int i, j, k, x, dim;

    // system("cls");
    printf("Matrix size: ");
    scanf("%d", &dim);

    //  2차원 배열에 행렬을 읽어 들임
    printf("input elements: \n");
    for (i = 0; i < dim; i += 1)
    {
        for (j = 0; j < dim + 1; j += 1)
        {
            scanf("%lf", &amat[i][j]);
        }
    }

    // 가우스 조던 소거법
    for (i = 0; i < dim; i += 1)
    {
        x = i;

        // i번째 칼럼중에서 가장 큰 원소를 남아 있는 n-i개 행 중에서 구함
        for (j = i + 1; j < dim; j += 1)
        {
            if (amat[j][i] > amat[x][i])
            {
                x = j;
            }

            if (fabs(amat[x][i]) < eps)
            { // 프로그램의 비정상적 종료
                printf("\n 원소가 너무 작아서 계속할 수가 없슴 !!!");
                getchar();
                getchar();
                return 0;
            }
        }

        printMatrix(amat, dim, dim + 1);

        // 가장 큰 원소를 가진 행과 i번째 행을 서로 바꿈
        if (x != i)
        {
            for (k = 0; k < dim + 1; k += 1)
            {
                v = amat[i][k];
                amat[i][k] = amat[x][k];
                amat[x][k] = v;
            }
        }
        printMatrix(amat, dim, dim + 1);

        // 소거연산을 해줌
        for (j = 0; j < dim; j += 1)
        {
            if (j != i)
            {
                v = amat[j][i];
                for (k = 0; k < dim + 1; k += 1)
                {
                    amat[j][k] -= (amat[i][k] / amat[i][i]) * v;
                }
            }
            else
            {
                v = amat[j][i];
                for (k = 0; k < dim + dim; k += 1)
                {
                    amat[j][k] /= v;
                }
            }
            printMatrix(amat, dim, dim + 1);
        }
        puts("=======================================");
    }
    // 행렬의 출력
    printf("\noutput result: \n");
    for (i = 0; i < dim; i += 1)
    {
        for (j = 0; j < dim + 1; j += 1)
        {
            if (j == dim)
                printf("  ");
            printf(" %g", amat[i][j]);
        }
        printf("\n");
    }

    return 0;
}