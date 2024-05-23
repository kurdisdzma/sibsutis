head.h
#include<stdio.h>
#include <stdlib.h>
#define RED "\033[1;31m"
#define RESET "\033[0m" // == in hex "\x1B[0m"
#define BLACK "\e[0;30m"
#define WHITE "\e[0;37m"
#include <time.h>
void print_array(int arr[], int n);
void fill_keyboard(int arr[], int n);
void fill_random(int arr[], int n);
void insertion_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void cocktail_sort(int arr[], int n);
int binary_search(int arr[], int item, int low, int high) ;
void binary_insertion_sort(int arr[], int n);
void shell_sort(int arr[], int n);


bin1.c
#include"head.h"
// Функция для выполнения бинарного поиска
int binary_search(int arr[], int item, int low, int high) {
if (high <= low)
return (item > arr[low]) ? (low + 1) : low;
int mid = (low + high) / 2;
if (item == arr[mid])
return mid + 1;
if (item > arr[mid])
return binary_search(arr, item, mid + 1, high);
return binary_search(arr, item, low, mid - 1);
}


bin2.c
#include"head.h"
// Функция сортировки методом бинарного включения
void binary_insertion_sort(int arr[], int n) {
int i, loc, j, selected, swap = 0, count = 0;
for (i = 1; i < n; ++i) {
count++;
j = i - 1;
selected = arr[i];
// находим позицию для вставки
loc = binary_search(arr, selected, 0, j);
count += 3;
// передвигаем большие элементы вправо
while (j >= loc) {
arr[j + 1] = arr[j];
swap++;
j--;
}
arr[j + 1] = selected;
swap++;
}
printf("M+C = %d ", swap+count);
}


Fill.c
#include"head.h"
// Функция для заполнения массива с клавиатуры
/*fill_keyboard(int arr[], int n) {
printf("Введите %d элементов массива:\n", n);
for (int i = 0; i < n; i++) {
for (int j=n;j>0;--j){
arr[i]=j;
}
}
return arr;
}*/


Fill_r.c
#include"head.h"
// Функция для заполнения массива случайными числами
void fill_random(int arr[], int n) {
srand(time(NULL)); // инициализация генератора случайных чисел
for (int i = 0; i < n; i++) {
arr[i] = rand() % 1000; // случайное число от 0 до 999
}
}


Hell.c
#include"head.h"
// Функция сортировки методом Шелла
void shell_sort(int arr[], int n) {
int gap, i, j, temp, count = 0, swap = 0;
for (gap = n / 2; gap > 0; gap /= 2) {
for (i = gap; i < n; i++) {
count ++;
temp = arr[i];
swap ++;
for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
count ++;
arr[j] = arr[j - gap];
swap ++;
}
arr[j] = temp;
swap ++;
}
}
printf("M+C = %d", swap+count);
}


la13.c
#include "head.h"
// Главная
функцияint
main() {
 int n_values[] = {100, 200, 300, 400, 500};
 int num_values = sizeof(n_values) / sizeof(n_values[0]);
 printf("n\tShell Sort\tBinary Insertion Sort\tCocktail Sort\tBubble Sort\tInsertion
Sort\n");
 for (int i = 0; i < num_values; i++) {
int n = n_values[i];
int arr[n];
double time_taken;
int choice, sorting_method;
printf("Выберите способ заполнения массива (1 - случайные числа, 2 - ввод с
клавиатуры): ");
scanf("%d", &choice);
printf("%d\n",choice);
// Заполнение массива в зависимости от выбора пользователя
switch(choice) {
case 1:
fill_random(arr, n);
break;
case 2:
fill_keyboard(arr, n);
break;
default:
printf( RED "Некорректный выбор. \n" );
return 1;
}
printf("Выберите метод сортировки (1 - Шелл, 2 - Бинарное включение,
3 - Шейкерная, 4 -Пузырьковая, 5 - Простое включение): ");
scanf("%d", &sorting_method);
printf("%d\n", sorting_method);
// Засекаем время перед сортировкой
clock_t t_start, t_end;
// Выполняем сортировку в зависимости от выбранного метода
switch(sorting_method) {
time_taken = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
// Выводим результаты
printf("%d\t%f\n", n, time_taken);
 }
 return 0;
}


Puzir.c
#include"head.h"
// Функция сортировки методом пузырьковой сортировки
void bubble_sort(int arr[], int n) {
int i, j, temp, swap = 0, count = 0;
for (i = 0; i < n-1; i++) {
// Last i elements are already in place
for (j = 0; j < n-i-1; j++) {
if (arr[j] > arr[j+1]) {
count++;
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
swap += 3;
}
}
}
printf("M+C = %d", swap+count);
}


Shake.c
#include"head.h"
// Функция сортировки методом шейкерной сортировки (шейкерной сортировки)
void cocktail_sort(int arr[], int n) {
int left = 0, right = n - 1, swapped = 0, count = 0, swap = 0;
while (left < right && !swapped) {
count++;
swapped = 1;
for (int i = left; i < right; i++) {
if (arr[i] > arr[i + 1]) {
count++;
int temp = arr[i];
arr[i] = arr[i + 1];
arr[i + 1] = temp;
swap += 3;
swapped = 0;
}
}
right--;
if (!swapped) {
swapped = 1;
for (int i = right; i > left; i--) {
if (arr[i] < arr[i - 1]) {
count++;
int temp = arr[i];
arr[i] = arr[i - 1];
arr[i - 1] = temp;
swap += 3;
swapped = 0;
}
}
left++;
}
}
printf("M+C = %d", swap+count);
}


Simple.c
#include"head.h"
// Функция сортировки методом простого включения (Insertion Sort)
void insertion_sort(int arr[], int n) {
int i, key, j, swap = 0, count = 0;
for (i = 1; i < n; i++) {
key = arr[i];
j = i - 1;
swap++;
/* Move elements of arr[0..i-1], that are
greater than key, to one position ahead
of their current position */
while (j >= 0 && arr[j] > key) {
count++;
arr[j + 1] = arr[j];
j = j - 1;
swap += 2;
}
arr[j + 1] = key;
swap ++;
}
printf("M+C = %d", swap+count);
}


Viviod.c
#include"head.h"
// Функция для вывода массива на экран
void print_array(int arr[], int n) {
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
printf(