#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int** a; // указатель на массив
    int** a1;
    int i, j, n, v1;
    system("chcp 1251");
    system("cls");
    printf("¬ведите количество строк: ");
    scanf("%d", &n);

    // ¬ыделение пам€ти
    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(n * sizeof(int));
    }

    // ¬вод элементов массива

    srand(time(NULL));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i != j) {
                a[i][j] = rand() % 2;
                a[j][i] = a[i][j];
            }
            else a[i][j] = 0; // €чейки, значение которых нам предстоит найти
        }
    printf("M1:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)

            printf("%3d", a[i][j]);
        printf("\n");
    };
    printf("¬ведите вершину: ");
    scanf("%d", &v1);
    a1 = (int**)malloc((n + 1) * sizeof(int*));
    for (i = 0; i < n + 1; i++)
    {
        a1[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == v1 or i == v1)
            {
                a1[i][j] = a[i][j];
                a1[n][j] = a[i][j];
                a1[i][n] = a[i][j];
                a1[n][n] = 0;
            }
            else
            {
                a1[i][j] = a[i][j];
            }
        }
    }
    printf("\n");

    printf("M1 изм 2:\n");
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
            printf("%3d", a1[i][j]);
        printf("\n");
    };
    free(a);
    getchar();   getchar();
    return 0;
}

