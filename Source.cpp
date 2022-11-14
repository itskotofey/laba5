#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int** a;  // указатель на массив
    int i, j, n;
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
    printf("Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    };

    printf("\n");
    free(a);
    getchar();   getchar();
    return 0;
}