#include <stdio.h>
#include <string.h>
#define N 5

int add(int num1);
int min(int nums[]);
void main()
{
    int i;
    int length[N], x, y;

    char name[N][20] = {"sarang", "mideum", "sipjaga", "taepyeongyang", "amugeona"};

    char phone[N][14] = {"010-5210-1234", "010-523-1628",
                         "010-1235-8765", "010-345-1676", "010-5210-5463"};

    int things[N] = {7, 5, 4, 8, 9};
    float x1[N] = {4, 8, 6, 9, 10};
    float y1[N] = {4, 8, 6, 9, 10};

    scanf("%d  %d", &x, &y);

    for (i = 0; i < N; i++)
    {
        length[i] = (x1[i] - x) * (x1[i] - x) + (y1[i] - y) * (y1[i] - y);
    }

    int m = min(length);

    printf("%d\n", m);
    printf("%s, %s, %d\n", name[m], phone[m], things[m]);
}

int min(int nums[])
{
    int min = 0;
    for (int i = 0; i < N; i++)
    {
        if (nums[min] > nums[i])
        {
            min = i;
        }
    }
    return min;
}
