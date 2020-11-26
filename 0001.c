#include <stdio.h>

#define MAX_DISC 50

typedef struct _pillar
{
    int discs[MAX_DISC];
    int disc_num;
} pillar;

int moveDisc(pillar *pillar1, pillar *pillar2);
void printPillar(pillar p);
void initPillar(pillar *p);
int getTopDisc(pillar p);
int addtopDisc(pillar *p, int disc);
int popTopDisc(pillar *p);
int checkClear(pillar pillars[], int disc_num);

int main()
{
    pillar pillars[3];
    for (int i = 0; i < 3; i++)
    {
        initPillar(pillars + i);
    }

    int disc_num;
    scanf("%d", &disc_num);
    for (int i = 0; i < disc_num; i++)
    {
        addtopDisc(pillars, disc_num - i);
    }

    int movement = 0;

    while (!checkClear(pillars, disc_num))
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%d: ", i);
            printPillar(pillars[i]);
            printf("\n");
        }

        int p1, p2;
        scanf("%d %d", &p1, &p2);

        if (moveDisc(pillars + p1, pillars + p2))
        {
            movement++;
        }
    }

    printf("%d\n", movement);

    return 0;
}

int checkClear(pillar pillars[], int disc_num)
{
    if (pillars[2].disc_num == disc_num)
    {
        return 1;
    }
    return 0;
}
int getTopDisc(pillar p)
{
    return p.discs[p.disc_num - 1];
}
int addtopDisc(pillar *p, int disc)
{
    if (getTopDisc(*p) < disc)
    {
        return 0;
    }
    p->discs[p->disc_num] = disc;
    p->disc_num++;
    return 1;
}
int popTopDisc(pillar *p)
{
    return p->discs[--p->disc_num];
}

void initPillar(pillar *p)
{
    p->disc_num = 0;
}

void printPillar(pillar p)
{
    if (p.disc_num == 0)
    {
        printf("x");
    }

    for (int i = 0; i < p.disc_num; i++)
    {
        printf("%d ", p.discs[i]);
    }
}

int moveDisc(pillar *pillar1, pillar *pillar2)
{
    if (addtopDisc(pillar2, getTopDisc(*pillar1)))
    {
        popTopDisc(pillar1);
        return 1;
    }
    return 0;
}