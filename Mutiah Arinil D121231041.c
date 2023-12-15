#include <stdio.h>

// Prototipe fungsi
void TampilanSevenSegment(int *segment);
int *DesimalSevenSegment(int angka, int *segment);
void DesimalKeBiner(int desimal, int *w, int *x, int *y, int *z);
void Draw_SevenSegment(int *segment); // Deklarasi prototipe

// Fungsi untuk menampilkan seven-segment display
void TampilanSevenSegment(int *segment) {
    const char horizontal[] = "=====\n";
    const char vertikal[] = "|| ";

    for (int i = 0; i < 7; i++) {
        if (i % 3 == 0 || i == 0) {
            segment[i] == 1 ? printf("%s", horizontal) : printf("\n");
        } else {
            segment[i] == 1 ? printf("%s", vertikal) : printf("   ");
            if (i == 2 || i == 5) printf("\n");
        }
    }
}

// Fungsi untuk mengonversi desimal ke seven-segment display
int *DesimalSevenSegment(int angka, int *segment) {
    const int nyala[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
    };

    for (int i = 0; i < 7; i++) {
        segment[i] = nyala[angka][i];
    }

    return segment;
}

// Fungsi untuk mengonversi desimal ke biner
void DesimalKeBiner(int desimal, int *w, int *x, int *y, int *z) {
    *z = desimal % 2;
    desimal /= 2;
    *y = desimal % 2;
    desimal /= 2;
    *x = desimal % 2;
    desimal /= 2;
    *w = desimal % 2;
}

// Fungsi untuk menampilkan tabel seven-segment
void Draw_SevenSegment(int *segment) {
    printf("\nTabel Seven-Segment:\n");
    printf("===============================\n");
    printf("|| a | b | c | d | e | f | g ||\n");
    printf("-------------------------------\n");
    printf("|| %d | %d | %d | %d | %d | %d | %d ||\n",
           segment[0], segment[1], segment[2],
           segment[3], segment[4], segment[5], segment[6]);
    printf("===============================\n\n\n");
    printf("Output:\n\n\n");
}

int main() {
    printf("\nTugas Proyek Sistem Digital Konversi Angka Desimal\n");
    printf("\nNama    : Mutiah Arinil Fayza Nusar \nNIM     : D121231041 \nProdi   : Teknik Informatika (B)\n\n");

    int inputDesimal;

    // Meminta pengguna memasukkan angka desimal
    printf("Masukkan satu angka desimal: ");
    scanf("%d", &inputDesimal);

    // Memastikan input dalam rentang yang valid
    if (inputDesimal < 0 || inputDesimal > 9) {
        printf("Masukkan angka 0-9.\n");
        return 1;  // Keluar dengan kode kesalahan
    }

    // Menampilkan hasil konversi desimal ke biner
    int w, x, y, z;
    DesimalKeBiner(inputDesimal, &w, &x, &y, &z);

    printf("\n\nTabel konversi %d ke biner:\n", inputDesimal);
    printf("_________________________\n");
    printf("|  w  |  x  |  y  |  z  |\n");
    printf("|-----|-----|-----|-----|\n");
    printf("|%3d  |%3d  |%3d  |%3d  |\n", w, x, y, z);
    printf("|_____|_____|_____|_____|\n");

    // Menampilkan seven-segment display
    int Segment[7];
    DesimalSevenSegment(inputDesimal, Segment);
    Draw_SevenSegment(Segment);
    TampilanSevenSegment(Segment);

    return 0;
}