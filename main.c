/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa {
    char name[50];
    int value;
};

typedef struct Mahasiswa Mahasiswa;

int num_mahasiswa = 0;
Mahasiswa* array_mahasiswa = NULL;

Mahasiswa* create_mahasiswa(char name[], int value) {
}

void add_mahasiswa(char name[], int value) {
}

void sort_mahasiswa() {
}

void print_mahasiswa() {
    printf("Mahasiswa (nama: nilai):\n");
}

int main() {
    char name[50];
    printf("Pilihan menu:\n");
    printf("1. Tambah mahasiswa\n");
    printf("2. Cari mahasiswa\n");
    printf("3. Tampilkan semua mahasiswa secara terurut dari nilai\n");
    printf("4. Keluar\n");
    printf("Masukkan pilihan: ");
    // printf("%s sudah ada di dalam list\n",name);
    printf("Masukkan nilai: ");
    printf("Masukkan nama: ");
    // printf("Mahasiswa dengan nama %s tidak ada\n", name);
    // printf("DADAHHHH");
    // printf("Pilihan tidak valid\n");
}
