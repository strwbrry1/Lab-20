#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 10
#define MAX_M 10

#include <Windows.h>
#include <stdio.h>

int arr[MAX_N][MAX_M] = {
    {0, 1, 2, 3},
    {10, 11, 12, 13},
    {20, 21, 22, 23}
};

int n = 3;
int m = 4;

void printArr() {
    printf("===========================\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("===========================\n");
}

void fillIndex() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * 10 + j;
        }
    }
}

void fillZero() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
        }
    }
}

void fillRandom() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 100;
        }
    }
}

void oddTimesTen() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 != 0) {
                arr[i][j] *= 10;
            }
        }
    }
}

void antiDecimal() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 10 == 0) {
                arr[i][j] = arr[i][j] / 10;
            }
        }
    }
}

void inputArr() {
    printf("\nN = ");
    scanf_s("%d", &n);
    printf("M = ");
    scanf_s("%d", &m);
    
    for (int i = 0; i < n; i++) {
        printf("Введите %d значений (%d/%d)\n", m, i+1, n);
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &arr[i][j]);
        }
    }
}

void save() {
    FILE* fsave = fopen("save.txt", "wt");
    if (fsave == NULL) {
        printf("\n>> Файл сохранения не найден <<\n");
        return;
    }

    fprintf(fsave, "%d ", n);
    fprintf(fsave, "%d\n", m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fsave, "%d ", arr[i][j]);
        }
        fprintf(fsave, "\n");
    }

    fclose(fsave);
}

void load() {
    FILE* fsave = fopen("save.txt", "rt");
    if (fsave == NULL) {
        printf("\n>> Файл сохранения не найден <<\n");
        return;
    }

    fscanf(fsave, "%d ", &n);
    fscanf(fsave, "%d\n", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fsave, "%d", &arr[i][j]);
        }
    }

    fclose(fsave);
}

void delRow(int row) {
    for (int i = row; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    n--;
}

void copyColumn(int col) {
    if (col < MAX_M) {
        for (int i = 0; i < n; i++) {
            for (int j = m + 1; j > col; j--) {
                arr[i][j] = arr[i][j - 1];
            }
        }
        m++;
    }
    else {
        printf("\n>> Достигнут максимум столбцов! <<\n");
    }
}

void minReplace() {
    int min = 99999;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                arr[i][j] = min;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int ans;
    do {
        printArr();
        printf("Выберите операцию:\n");
        printf("1: Заполнить значениями i * 10 + j\n");
        printf("2: Заполнить нулями\n");
        printf("3: Заполнить случайными значениями\n");
        printf("4: Увеличить все нечётные в 10 раз\n");
        printf("5: Все кратные 10 уменьшить в 10 раз\n");
        printf("6: Ввести массив с клавиатуры\n");
        printf("7: Сохранить массив в файл\n");
        printf("8: Загрузить массив из файла\n");
        printf("9: Удалить заданную строку\n");
        printf("10: Продублировать заданный столбец\n");
        printf("11: Заменить элементы с четной суммой индексов на минимум массива\n");
        printf("\n");
        printf("0: Выход из программы\n\n");
        printf("Ввод >> ");
        scanf_s("%d", &ans);
        switch (ans) {
        case 1:
            fillIndex();
            printf("\n>> Заполнено! <<\n\n");
            break;
        case 2:
            fillZero();
            printf("\n>> Заполнено нулями! <<\n\n");
            break;
        case 3:
            fillRandom();
            printf("\n>> Заполнено случайными! <<\n\n");
            break;
        case 4:
            oddTimesTen();
            printf("\n>> Нечётные увеличены! <<\n\n");
            break;
        case 5:
            antiDecimal();
            printf("\n>> Кратные 10 уменьшены! <<\n\n");
            break;
        case 6:
            inputArr();
            break;
        case 7:
            save();
            printf("\n>> Массив сохранён! <<\n\n");
            break;
        case 8:
            load();
            printf("\n>> Массив загружен! <<\n\n");
            break;
        case 9:
        {
            int row;
            printf("Номер удаляемой строки -> ");
            scanf_s("%d", &row);

            delRow(row);
            printf("\n>> Удалено! <<\n\n");
            break;
        }  
        case 10:
        {
            int col;
            printf("Номер копируемого столбца -> ");
            scanf_s("%d", &col);

            copyColumn(col);
            printf("\n>> Скопировано! <<\n\n");
            break;
        }
        case 11:
            minReplace();
            printf("\n>> Готово! <<\n\n");
            break;
        }
    } while (ans != 0);
}

