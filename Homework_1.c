#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                             7 xuat hien 2 lan
//                                             8 xuat hien 3 lan

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN);
void randomArray(typeArray *value, uint8_t length);
void sortArray(typeArray *arr);
void countArray(typeArray *arr);

int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 20);

    for (int i = 0; i < arr.size; i++)
    {
         printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }
    
    sortArray(&arr);
    countArray(&arr);
    return 0;
}
//---------- Creating random Elements ----------
int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

//---------- Creating random Array function ----------
void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    int r;
    for(int i = 0; i < value->size; ++i){
        value->firstAdd[i] = randomA(0,10);
    }    
}

//---------- Sorting Array function ----------
void sortArray(typeArray *arr) {
    for(int i = 0; i < arr->size - 1; i++) {
        for(int j = i + 1; j < arr->size; j++) {
            if(arr->firstAdd[i] > arr->firstAdd[j]) {
                arr->firstAdd[i] = arr->firstAdd[i] ^ arr->firstAdd[j];
                arr->firstAdd[j] = arr->firstAdd[i] ^ arr->firstAdd[j];
                arr->firstAdd[i] = arr->firstAdd[i] ^ arr->firstAdd[j];
            }
        }
    }
    printf("\t\t=== After sorted===\n");
    for (int i = 0; i < arr->size; i++)
    {
        printf("Element no.%d = %d\n",i, arr->firstAdd[i]);
    }
}
//---------- Appearance of Elements ----------
void countArray(typeArray *arr) {
    uint8_t count = 1;
    for(int i=0; i < arr->size; i++)
    {  
        if (arr->firstAdd[i] == arr->firstAdd[i+1]) {
            count++;
        }
        if(arr->firstAdd[i] != arr->firstAdd[i+1]) {
            printf("\nElement %d appears %d time(s)\n", arr->firstAdd[i], count);
            count = 1;
          } 
    }      
}
