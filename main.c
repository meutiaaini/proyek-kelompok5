#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
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
    } // akhir proses registrasii
    
    if(manyArgument == 2){
        regis reg;
        FILE *fpr = fopen("database/login.bin", "rb");

        char add[3] = "#";
        strcat(reg.username, add);
        strcat(reg.username, reg.password);

        fread(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpr);

        fclose(fpr);
        
        char acc[0];
        printf("\nFail to login !\n");
        printf("Anda belum memasukkan password !\n");
        printf("See your account? (y/n) "); gets(acc);
        if (acc[0] == 'y')
        {
            fgets(reg.username, sizeof(reg.username), fpr);
            printf("Your account : %s\n", reg.username);
        }
        printf("Note cara login : ./FileProgramUtama Username Password (harap perhatikan huruf besar dan kecil ya <3!)\n\n");
    }
    
}

if(manyArgument == 3){
        regis reg;

        char usernameInput[10], passwordInput[10];
        strcpy(usernameInput, argument[1]);
        strcpy(passwordInput, argument[2]);
        
        FILE *fpr = fopen("database/login.bin", "rb");

        fread(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpr);

        fclose(fpr);

        char *string[3];
        char username[20], password[20];
        int ctrl = 0;

        string[0] = strtok(reg.username, "#");
        while (string[ctrl++] != NULL){
            string[ctrl] = strtok(NULL, "#");
        }

        strcpy(username, string[0]);
        strcpy(password, string[1]);

        if( (strcmp(usernameInput, username) != 0 ) && (strcmp(passwordInput, password) != 0)) {
            printf("Anda Gagal login !\n");
            exit(1);
        } 
        else{
            printf("Login berhasil!");
            printf("\n\n\t\t\t\tWelcome to \"QUIZ PINTAR\"");
            printf("\n\n\t\t\t\tyuk jawab quiz pintar agar kamu semakin pintar!!!");
            printf("\n\t\t\t\tTekan \"ENTER\" untuk memulai permainan!\n\n");
            getchar();
            soal();
        }

    }
    return 0;
}
void soal(){
    int hadiah=0; 
    char jawaban;

    //soal 1    
    printf("\n\nHadiah untuk pertanyaan pertama = Rp200.000\n");
    printf("\n\t\t\t\tTekan \"ENTER\" untuk menuju ke soal pertama!");
    getchar();
    system("cls");
    printf("\t\t\tUang yang anda telah kumpulkan = Rp%d", hadiah);
    printf("\n\n\t\t\tDiketahui segitiga XYZ dengan <X = <Y = 45. Jenis segitiga XYZ adalah...\n\n");
    printf("\t\t\t\tA. Segitiga siku-siku \n");
    printf("\t\t\t\tB. segitiga sama kaki\n");
    printf("\t\t\t\tC. Jawaban a dan b benar\n\n");
    printf("\t\t\tJawaban anda (Jawablah menggunakan huruf kapital sesuai pilihan yang tersedia (A/B/C)) = ");
    scanf("%c", &jawaban);
    getchar();

    if(jawaban=='C'){
        printf("\n\nSelamat jawaban anda benar!");
        hadiah+=200000;
    }
    else{
        printf("\n\nMohon maaf jawaban anda salah\nAnda berhak membawa pulang uang sebesar Rp%d!\n\nTerima kasih telah memainkan game ini!!!", hadiah);
        exit(1);
    }
    
    //soal 2    
    printf("\n\nHadiah untuk pertanyaan kedua = Rp400.000\n");
    printf("\n\t\t\t\tTekan \"ENTER\" untuk menuju soal berikutnya!");
    getchar();
    system("cls");
    printf("\t\t\tUang yang anda telah kumpulkan = Rp%d", hadiah);
    printf("\n\n\t\t\tBenua yang dijuluki dengan nama benua biru adalah...n\n");
    printf("\t\t\t\tA. Benua Amerika\n");
    printf("\t\t\t\tB. Benua Eropa\n");
    printf("\t\t\t\tC. Benua Asia\n\n");
    printf("\t\t\tJawaban anda (Jawablah menggunakan huruf kapital sesuai pilihan yang tersedia (A/B/C)) = ");
    scanf("%c", &jawaban);
    getchar();

    if(jawaban=='B'){
        printf("\n\nSelamat jawaban anda benar!");
        hadiah+=400000;
    }
    else{
        printf("\n\nMohon maaf jawaban anda salah\nAnda berhak membawa pulang uang sebesar Rp%d!\n\nTerima kasih telah memainkan game ini!!!", hadiah);
        exit(1);
    }
    
    //soal 3    
    printf("\n\nHadiah untuk pertanyaan ketiga = Rp800.000\n");
    printf("\n\t\t\t\tTekan \"ENTER\" untuk menuju soal berikutnya!");
    getchar();
    system("cls");
    printf("\t\t\tUang yang anda telah kumpulkan = Rp%d", hadiah);
    printf("\n\n\t\t\tNama lain dari negara Inggris adalah...?n\n");
    printf("\t\t\t\tA. Britania Raya\n");
    printf("\t\t\t\tB. Netherland\n");
    printf("\t\t\t\tC. Amsterdam\n\n");
    printf("\t\t\tJawaban anda (Jawablah menggunakan huruf kapital sesuai pilihan yang tersedia (A/B/C)) = ");
    scanf("%c", &jawaban);
    getchar();

    if(jawaban=='A'){
        printf("\n\nSelamat jawaban anda benar!");
        hadiah+=800000;
    }
    else{
        printf("\n\nMohon maaf jawaban anda salah\nAnda berhak membawa pulang uang sebesar Rp%d!\n\nTerima kasih telah memainkan game ini!!!", hadiah);
        exit(1);
    }
    //soal 4    
    printf("\n\nHadiah untuk pertanyaan keempat = Rp1.600.000\n");
    printf("\n\t\t\t\tTekan \"ENTER\" untuk menuju soal berikutnya!");
    getchar();
    system("cls");
    printf("\t\t\tUang yang anda telah kumpulkan = Rp%d", hadiah);
    printf("\n\n\t\t\tDi bawah ini merupakan fungsi untuk melakukan looping, kecuali?\n\n");
    printf("\t\t\t\tA. While\n");
    printf("\t\t\t\tB. Switch\n");
    printf("\t\t\t\tC. For\n\n");
    printf("\t\t\tJawaban anda (Jawablah menggunakan huruf kapital sesuai pilihan yang tersedia (A/B/C)) = ");
    scanf("%c", &jawaban);
    getchar();

    if(jawaban=='B'){
        printf("\n\nSelamat jawaban anda benar!");
        hadiah+=1600000;
    }
    else{
        printf("\n\nMohon maaf jawaban anda salah\nAnda berhak membawa pulang uang sebesar Rp%d!\n\nTerima kasih telah memainkan game ini!!!", hadiah);
        exit(1);
    }
    
    //soal 5    
    printf("\n\nHadiah untuk pertanyaan kelima = Rp3.000.000\n");
    printf("\n\t\t\t\tTekan \"ENTER\" untuk menuju soal berikutnya!");
    getchar();
    system("cls");
    printf("\t\t\tUang yang anda telah kumpulkan = Rp%d", hadiah);
    printf("\n\n\t\t\t\"i++\" merupakan contoh dari perintah?\n\n");
    printf("\t\t\t\tA. Increment\n");
    printf("\t\t\t\tB. Decrement\n");
    printf("\t\t\t\tC. Nested loop\n\n");
    printf("\t\t\tJawaban anda (Jawablah menggunakan huruf kapital sesuai pilihan yang tersedia (A/B/C)) = ");
    scanf("%c", &jawaban);
    getchar();

    if(jawaban=='A'){
        hadiah+=3000000;
        printf("\n\nSelamat jawaban anda benar dan anda telah memenangkan game ini!\nAnda berhak membawa pulang uang tunai sebesar Rp%d!\n\nTerima kasih telah memainkan game ini!!!", hadiah);
    }
    else{
        printf("\n\nMohon maaf jawaban anda salah\nAnda berhak membawa pulang uang sebesar Rp%d!\n\nTerima kasih telah memainkan game ini!!!", hadiah);
        exit(1);
    }
}
