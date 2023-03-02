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
    Mahasiswa* new_mahasiswa = (Mahasiswa*) calloc(1, sizeof(Mahasiswa));
    strcpy(new_mahasiswa->name, name);
    new_mahasiswa->value = value;
    return new_mahasiswa;
}

void add_mahasiswa(char name[], int value) {

    if (array_mahasiswa == NULL) {
        array_mahasiswa = (Mahasiswa*) calloc(1, sizeof(Mahasiswa));
    } else {
        array_mahasiswa = (Mahasiswa*) realloc(array_mahasiswa, (num_mahasiswa+1) * sizeof(Mahasiswa));
    }
    array_mahasiswa[num_mahasiswa++] = *create_mahasiswa(name, value);
}

void sort_mahasiswa() {
    for (int i = 0; i < num_mahasiswa-1; i++) {
        for (int j = i+1; j < num_mahasiswa; j++) {
            if (array_mahasiswa[j].value > array_mahasiswa[i].value) {
                Mahasiswa temp = array_mahasiswa[i];
                array_mahasiswa[i] = array_mahasiswa[j];
                array_mahasiswa[j] = temp;
            }
        }
    }
}

void print_mahasiswa() {
    printf("Mahasiswa (nama: nilai):\n");
    for (int i = 0; i < num_mahasiswa; i++) {
        printf("%s: %d\n", array_mahasiswa[i].name, array_mahasiswa[i].value);
    }
}

int main() {
    int choice = 0;
    char name[50];
    int value = 0;

    while (choice != 4) {
        printf("Pilihan menu:\n");
        printf("1. Tambah mahasiswa\n");
        printf("2. Cari mahasiswa\n");
        printf("3. Tampilkan semua mahasiswa secara terurut dari nilai\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            {
                printf("Masukkan nama: ");
                scanf("%s", name);
                int ketemu = 0;
                for (int i = 0; i < num_mahasiswa; i++) {
                    if (strcmp(name, array_mahasiswa[i].name) == 0) {
                        ketemu = 1;
                        break;
                    }
                }
                if (ketemu == 1){
                    printf("%s sudah ada di dalam list\n",name);
                    break;
                }else{
                    printf("Masukkan nilai: ");
                    scanf("%d", &value);
                    add_mahasiswa(name, value);
                    break;
                }
            }
        case 2:
            {
                printf("Masukkan nama: ");
                scanf("%s", name);
                int found = 0;
                for (int i = 0; i < num_mahasiswa; i++) {
                    if (strcmp(name, array_mahasiswa[i].name) == 0) {
                        printf("%s: %d\n", array_mahasiswa[i].name, array_mahasiswa[i].value);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Mahasiswa dengan nama %s tidak ada\n", name);
                }
            }
            break;
        case 3:
            {
                sort_mahasiswa();
                print_mahasiswa();
            }
            break;
        case 4:
            printf("DADAHHHH");
            return 0;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }
    }
    return 0;
}
