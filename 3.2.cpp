#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int** a; // ��������� �� ������
    int** b;
    int i, j, n, m;
    system("chcp 1251");
    system("cls");
    printf("������� ���������� �����: ");
    scanf("%d", &n);

    // ��������� ������
    a = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(n * sizeof(int));
    }

    // ���� ��������� �������

    srand(time(NULL));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i != j) {
                a[i][j] = rand() % 2;
                a[j][i] = a[i][j];
            }
            else a[i][j] = 0; // ������, �������� ������� ��� ��������� �����
        }
    printf("M1:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)

            printf("%3d", a[i][j]);
        printf("\n");
    };

    printf("\n");

    printf("������� ���������� �����: ");
    scanf("%d", &m);
    b = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++)
    {
        b[i] = (int*)malloc(m * sizeof(int));
    }

    // ���� ��������� �������

    srand(time(NULL));

    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            if (i != j) {
                b[i][j] = rand() % 2;
                b[j][i] = b[i][j];
            }
            else b[i][j] = 0; // ������, �������� ������� ��� ��������� �����
        }
    printf("M2:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
            printf("%3d", b[i][j]);
        printf("\n");
    };

    printf("\n");
    if (n != m)
    {
        printf("������ ����������� ������!");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                a[i][j] = a[i][j] or b[i][j];
            }
        }
        printf("���������� �������:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                printf("%3d", a[i][j]);
            printf("\n");
        };
    }
    free(a);
    free(b);
    getchar();   getchar();
    return 0;
}
