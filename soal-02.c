/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : Overview of C Language
*Percobaan        : -
*Hari dan Tanggal : Kamis, 17 Februari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int matrix[3][3],tres,histemp[5];//inisialisasi variabel matrix, treshold LBP, dan matriks histogram
    char hist[10][5];
    //inisialisasi histemp = 0 untuk semua elemennya
    for (int i = 0; i < 5; i++)
    {
        histemp[i] = 0;
    }
    //baca matriks dari input user
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("masukkan data ke - [%d][%d] ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    //hitung banyaknya nilai pixel di tiap rentang
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] <= 10)
            {
                histemp[0] = histemp[0] + 1;
            }
            else if(matrix[i][j]>10 && matrix[i][j] <=20)
            {
                histemp[1] = histemp[1] + 1;
            }
            else if (matrix[i][j] > 20 && matrix[i][j] <= 30)
            {
                histemp[2] = histemp[2] + 1;
            }
            else if (matrix[i][j] > 30 && matrix[i][j] <= 40)
            {
                histemp[3] = histemp[3] + 1;
            }
            else
            {
                histemp[4] = histemp[4] + 1;
            }
        }
    }
    //isi matriks histogram
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j < histemp[i])
            {
                hist[j][i] = '1';
            }
            else
            {
                hist[j][i] = ' ';
            }
            
        }
    }
    //hitung kode LBP
    tres = matrix[1][1];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] >= tres)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
    //output histogram
    printf("histogram matriks adalah :\n");
    for (int i = 9; i >=0; i--)
    {
        for (int j = 0; j <5; j++)
        {
            printf("%c",hist[i][j]);
        }
        printf("\n");
    }
    //output LBP
    printf("lbp matriks adalah :\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != 1 || j != 1)
            {
                printf("%d", matrix[i][j]);
            }
        }
    }
    
}
