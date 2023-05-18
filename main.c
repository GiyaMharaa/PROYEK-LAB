#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int BanyakArgumen, char *argumen[]) // ./main username passwword
{
    if (BanyakArgumen != 3)
    {
        printf("Gagal login!");
        printf("\n Cara penggunaan : ./(namafile) username password");
        return EXIT_FAILURE;
    }
    char usernameinput[20], passwordinput[20];
    strncpy(usernameinput, argumen[1], sizeof(usernameinput) - 1);
    strncpy(passwordinput, argumen[2], sizeof(passwordinput) - 1);

    usernameinput[sizeof(usernameinput) - 1] = '\0';
    passwordinput[sizeof(passwordinput) - 1] = '\0';

    FILE *fpr = fopen("database/login.bin", "rb");

    if (fpr == NULL)
    {
        printf("Gagal membuka file.\n");
        return EXIT_FAILURE;
    }

    // Cek apakah file kosong
    fseek(fpr, 0, SEEK_END);
    if (ftell(fpr) == 0)
    {
        printf("================================================================\n");
        printf("\tGagal login, Silahkan registrasi terlebih dahulu!\n");
        printf("================================================================\n");

        FILE *fpw = fopen("database/login.bin", "wb");
        char id[20];
        
        char pw[20];
        printf("Registrasi\n");
        printf("Masukan id: ");
        scanf("%s", id);

        printf("Masukan pw: ");
        scanf("%s", pw);

        fprintf(fpw, "%s ", id);
        fprintf(fpw, "%s", pw);
        fclose(fpw);

        return EXIT_FAILURE;
    }

    rewind(fpr);

    char akun[40];
    if (fread(akun, sizeof(akun), 1, fpr) != 1)
    {
        printf("Gagal membaca data dari file!\n");
        fclose(fpr);
        return EXIT_FAILURE;
    }

    fclose(fpr);

    char *username, *password;
    username = strtok(akun, " ");
    password = strtok(NULL, " ");

    if (username != NULL && password != NULL && strcmp(usernameinput, username) == 0 && strcmp(passwordinput, password) == 0)
    {
        printf("Login Berhasil!\n");
        menu();
    }
    else
    {
        printf("Password Salah!\n");
        printf("Gagal login!\n");
        printf("Username: %s\n", username);
        printf("Password: %s\n", password);
    }

    return 0;
}
