#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registration
{
    char name[20];
    char job[20];
    char age[20];
    char hobby[50];
    char username[20];
    char password[20];
} regis;

// proses registrasi
int main(int manyArgument, char *argument[]) 
{
    //pengecekan kondisi pertama
    if(manyArgument == 1){
        regis reg; //membuat variable dari struct
        printf("\n");     
        printf("\t\t      ___       __   __         ___ \n");
        printf("\t\t|  | |__  |    /  ` /  \\  |\\/| |__  \n");
        printf("\t\t|/\\| |___ |___ \\__, \\__/  |  | |___ \n");
        printf("\t\t___________________________________\n");
        printf("\t\t       -Welcome to the Game-        \n");
        printf("\n");
        printf("Silahkan registrasi terlebih dahulu sebelum memulai game quiz <3\n");
        printf("Nama\t\t: "); gets(reg.name);
        printf("Pekerjaan\t: "); gets(reg.job);
        printf("Hobby\t\t: "); gets(reg.hobby);
        printf("Umur\t\t: "); gets(reg.age);
        printf("\n");
        printf("\tcreate your account\n");
        printf("Username\t: "); gets(reg.username);
        printf("Password\t: "); gets(reg.password);
        printf("\nCreate account success !\n");
        printf("lets login and enjoy the game buddy!\n");
        printf("Note cara login : ./FileProgramUtama Username Password\n\n");
        
        FILE *fpw = fopen("database/login.bin", "wb");

        char insl[3] = "#";
        strcat(reg.username, insl); //strcat berfungsi untuk menggabungkan 2 buah string
        strcat(reg.username, reg.password);

        fwrite(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpw);

        fclose(fpw);
    } // akhir proses registrasi
    
}

