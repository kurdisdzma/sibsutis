//Вариант 9

#include<stdio.h>

int main(){
    int i,j;
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);
    
    int A[n];
    
     printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);}
        
for (i=0; i<n; i++){
        if (A[i]<0){
                for (j=i; j<n-1;j++) A[j]=A[j+1];
                n--;
                i--;
                }}
                
    printf("Измененный массив:\n");
    for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
    }
    return 0;
}
------------------------------------------------
вариант 5 // есть+,то 1, нету, то 0

#include <stdio.h> 
 
int main() {  
    int i = 0;  
    int n;  
    printf("Введите размер массива: ");  
    scanf("%d", &n); 
 
    int A[n]; 
     
    printf("Введите %d элементов массива:\n", n); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &A[i]); 
    } 
 
    printf("\n"); 
     
    while (i < n && A[i] > 0) { 
        i++; 
    } 
     
    if (i == n) { 
        printf("1"); 
    } else { 
        printf("0"); 
    } 
 
    return 0;  
}
---------------------------------------------------------------
вариант 3 //если есть минус, то 0, если нет, то 1 


#include <stdio.h>

int main() { 
    int n, i;
    printf("введите размер массива: ");
    scanf("%d", &n);
    
     int A[n]; 
printf("введите элементы массива: ", n);
     for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);    
     }
     
    int s = 0;
    for (i = 0; i < n; i++){
      if (A[i] < 0)
      {
          s++;
          
      }
}      
    if (s == 0){
     printf("1");
    } 
    else{
        printf("0");
    }
}
---------------------------------------------------
ВАРИАНТ 40 //наибольший элемент в массиве.

#include <stdio.h>

int main()
{
    int A[9] = {1, 4, 5, 3, 2, 6, 7, 4, 9};
    int s;
    int i;
    
for (i=0, s=0; i<10; i++) {
     if (A[i]>s) {
         s=A[i];
         
        }
    }
      printf("наибольший элемент массива: %d\n", s);
}
--------------------------------------------------
ВАРИАНТ 29 // считает сумму положительных элементов массива.

#include <stdio.h>

int main()
{
    int n = 5;
    int A[] = {1, 4, 5, 3, -3};
    int s;
    int i;
for (s=0,i=0; i<n && A[i]>0; i++){
        s=s+A[i];
    }
      printf(" %d\n", s);
}
-----------------------------------------------------------
#include <stdio.h>

int main() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int c[n]; // создание массива фиксированного размера

    printf("Введите элементы массива: %d\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int i, j, k;
    for (i = 0, j = n - 1; i < j; i++, j--) {
        k = c[i];
        c[i] = c[j];
        c[j] = k;
    }

    // Печать результата
    printf("Результат: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}