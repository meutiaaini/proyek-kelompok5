#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){

    char username[20], password[20], repassword[20];
    char usernamelog[20], passwordlog[20];
    char input1;

    if (argc == 3) {
        goto login;
    }
    
    FILE *reg;

    printf("Selamat datang\n");
    printf("Buat akun(y/n): ");
    scanf("%s", &input1);
    getchar();

    
    if(input1 == 'y'){
        reg = fopen("login.bin", "wb");  
        if(reg == NULL){
            printf("Erorr.. !!\n");
            exit(1);
        }
        printf("\n======== Register Session =========\n");
        printf("->Masukkan username anda: ");
        gets(username);
        printf("->Masukkan password anda: ");
        gets(password);
        pass: 
        printf("->Konfirmasi password ulang: ");
        gets(repassword);
        printf("===================================\n");

        while(password != repassword){
            if(strcmp(password, repassword) == 0){
                printf("\nAkun anda sudah dibuat\n");
                break;
            }
            else{
                printf("\nIPasssword salahn");
                goto pass;
            }
        }
        
        fwrite(&username,sizeof(char),sizeof(username)/sizeof(char),reg);
        fwrite(&password,sizeof(char),sizeof(password)/sizeof(char),reg);
        
        fclose(reg);
        printf("Please login by : ./FileMainProgram.exe username password\n");

        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }

    login:
    strcpy(usernamelog, argv[1]);
    strcpy(passwordlog, argv[2]);

    reg = fopen("login.bin", "rb");

    if(reg == NULL){
        printf("File didn't exist\n");
        exit(1);
    }

    fread(username, sizeof(char), sizeof(username)/sizeof(char), reg);
    fread(password, sizeof(char), sizeof(password)/sizeof(char), reg);

    if(strcmp(username,usernamelog) == 0 && strcmp(password,passwordlog) == 0) {
        printf("\tLogin berhasil\n\tSelamat datang teman-teman\n");
    } else{
        printf("Usernama/salah Password\nmohon login kembali dengan username dan password yang benar\n");
        exit(2);
    }    

    fclose(reg);
    
}

