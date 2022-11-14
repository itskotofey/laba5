#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int** a; // указатель на массив
    int i, j, n, v1, v2;
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


    printf("\n");
    printf("¬ведите первую вершину: ");
    scanf("%d", &v1);
    printf("¬ведите вторую вершину: ");
    scanf("%d", &v2);
    for (i = 0; i < n; i++)
    {
        a[i][v1] = a[i][v1] or a[i][v2];
    }
    printf("M1 изм:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)

            printf("%3d", a[i][j]);
        printf("\n");
    };
    /*код удалени€ строки */
    for (i = v2; i < n - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = a[i + 1][j];
        }
    }
    /*код удалени€ столбца */
    for (i = 0; i < n; i++)
    {
        for (j = v2; j < n - 1; j++)
        {
            a[i][j] = a[i][j + 1];
        }
    }
    printf("M1 изм 2:\n");
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)

            printf("%3d", a[i][j]);
        printf("\n");
    };
    free(a);
    getchar();   getchar();
    return 0;
}
