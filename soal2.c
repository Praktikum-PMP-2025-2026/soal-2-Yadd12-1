/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
*   Modul               : 1 - Overview of C Language
*   Hari dan Tanggal    : Rabu, 15 April 2026
*   Nama (NIM)          : Fayyadh Ramadhan (13224077)
*   Nama File           : soal2.c
*   Deskripsi           : 
* 
*/

#include <stdio.h>

void inputTransformasi(int T, int counter, int *n)
{
    if(counter>=T)
    {
        return;
    }
    
    scanf(" %d", &n[counter]);

    inputTransformasi(T, counter+1, n);
}

void transformasiLangkah(int T, int counter, int *n, int langkah)
{
    if((n[counter] % 2) == 0)
    {
        n[counter] = (n[counter]) * 2;
    }
    else
    {
        n[counter] = 3*(n[counter]) + 1;
    }

    if(n[counter] == 1)
    {
        printf("LANGKAH %d\n", langkah);
        return;
    }
    // else
    // {
    //     printf("hadi");
    //     return;
    // }

    transformasiLangkah(T, counter, &n[50], langkah+1);
}

void hitungLangkah(int T, int start, int *n)
{
    if (start >= T)
    {
        return;
    }

    transformasiLangkah(T, start, n, 0);

    hitungLangkah(T, start+1, n);
}

int main()
{
    int T, n[50], langkah=0;
    scanf("%d", &T);
    
    inputTransformasi(T, 0, n);
    hitungLangkah(T, 0, n);

    // printf("%d %d", n[0], n[1]);
    return 0;
}