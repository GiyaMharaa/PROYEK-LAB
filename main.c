#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void tampilkanPertanyaan(const char *pertanyaan, const char *opsiA, const char *opsiB, const char *opsiC, const char *opsiD)
{
    printf("==========================================\n");
    printf("%s\n", pertanyaan);
    printf("A. %s\n", opsiA);
    printf("B. %s\n", opsiB);
    printf("C. %s\n", opsiC);
    printf("D. %s\n", opsiD);
    printf("==========================================\n");
}

// menu quiz
void kuiz() // fungsi menu untuk quiz
{
    char jawaban[10];
    int skor = 0;

    // 1
    pertanyaan("Siapa penulis novel \"Laskar Pelangi\"?", "Andrea Hirata", "Andrea Hirata", "Dee Lestari", "Raditya Dika");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "A") == 0 || strcmp(jawaban, "a") == 0)
    {
        skor += 100;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");
    
    // 2
    pertanyaan("Berapa jumlah provinsi di Indonesia saat ini?", "30", "32", "34", "36");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "C") == 0 || strcmp(jawaban, "c") == 0)
    {
        skor += 120;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");
    
    // 3
    pertanyaan("Apa ibu kota Indonesia?", "Jakarta", "Bandung", "Surabaya", "Yogyakarta");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "A") == 0 || strcmp(jawaban, "a") == 0)
    {
        skor += 150;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");
    
    // 4
    pertanyaan("Apa nama mata uang resmi Indonesia?", "Rupiah", "Dinar", "Euro", "Yen");
    printf("Jawaban Anda (A/B/C/D): ");
    scanf("%s", jawaban);
    if (strcmp(jawaban, "A") == 0 || strcmp(jawaban, "a") == 0)
    {
        skor += 100;
        printf("Jawaban Anda benar!\n");
    }
    else
    {
        printf("Jawaban Anda salah!\n");
    }
    printf("==========================================\n");


}


int main(int BanyakArgumen, char *argumen[]) // ./main username passwword
{
      if (BanyakArgumen != 3)
    {

        printf("\n Cara penggunaan : ./(namafile) username password\n");

        return EXIT_FAILURE;
    }

    char usernameinput[10], passwordinput[10];
    strcpy(usernameinput, argumen[1]);
    strcpy(passwordinput, argumen[2]);

    // buka dan baca file binary : login.bin
    FILE *fpr = fopen("database/login.bin", "rb");
    char akun[20];

    if (fpr == NULL)
    {
        printf("Gagal membuka file.\n");
        return 1;
    }

    // Cek apakah file kosong
    fseek(fpr, 0, SEEK_END);
    if (ftell(fpr) == 0)
    {
        printf("================================================================\n");
        printf("\tGagal login, Silahkan registrasi terlebih dahulu!\n");
        printf("================================================================\n");

        // membuka file binary untuk memasukan data registrasi
        FILE *fpw = fopen("database/login.bin", "wb");
        char id[20];
        char pw[20];
        printf("Registrasi\n");
        printf("Masukan id: ");
        scanf("%s", id);

        printf("Masukan pw: ");
        scanf("%s", pw);
        fprintf(fpw, "%s", id);

        fprintf(fpw, " ");
        fprintf(fpw, "%s", pw);

        fprintf(fpw, "\0"); // Menambahkan karakter nul di akhir data

        fclose(fpw);

        return EXIT_FAILURE;
    }

    if ((fpr = fopen("database/login.bin", "rb")) == NULL)
    {
        printf("Gagal membuka file!");

        return EXIT_FAILURE;
    }

    // membaca file binary dan ditampunf di variable akun
    fread(akun, sizeof(char), sizeof(akun) / sizeof(char), fpr);

    fclose(fpr);

    char *string[3];
    char username[20], password[20];
    int ctrl = 0;

    string[0] = strtok(akun, " ");

    // memisahkan kata perkata menggunakan fungsi strtok
    while (string[ctrl++] != NULL)
    {
        string[ctrl] = strtok(NULL, " ");
    }

    strcpy(username, string[0]);
    strcpy(password, string[1]);

    // memulai quiz ketika login berhasil
    if (strcmp(usernameinput, username) == 0 && strcmp(usernameinput, username) == 0)
    {
        printf("Login Berhasil!\n");
        
        // tarok fungsi menu quiz
    }
    else // gagal login
    {
        printf("PW SALAH!\n");

        printf("Riwayat Akun!\n");
        printf("Username %s\n", username);
        printf("Password %s\n", password);
        printf("%s ", argumen[1]);
        printf("%s", argumen[2]);
    }

    return 0;
}
