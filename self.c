/*
 * Студент: Мареева Ангелина Ильинична
 * Группа: ПИ 11
 * Сортировка массива
 */

#include <stdio.h>
void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            int t = a[i];
            a[i] = a[max_index];
            a[max_index] = t;
        }
    }
}
int is_descending(const int a[], int n) {
    if (n <= 1) {
        return 1;
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < a[i + 1]) {
            return 0;
        }
    }

    return 1;
}
void print_array(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}
int main(void) {
    int a[] = {4, -2, 7, 4, 0};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, n);
    print_array(a, n);
    printf("; проверка %d\n", is_descending(a, n));
    int b[] = {5};
    sort(b, 1);
    print_array(b, 1);
    printf("; проверка %d\n", is_descending(b, 1));
    int c[] = {3, 1, 2};
    printf("Проверка без сортировки: %d\n", is_descending(c, 3));
    int d[] = {2, 2, 1};
    printf("Граница, равные элементы: %d\n", is_descending(d, 3));
    int e[1] = {0};
    printf("Пустой массив: %d\n", is_descending(e, 0));

    return 0;
}