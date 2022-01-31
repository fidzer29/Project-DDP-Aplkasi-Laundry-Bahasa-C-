#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#include <time.h>
#include "laundry.h"
using namespace std;


void login(){
    system("cls");

//kamus data
    char user[10],pass[10];
    int i;
    i=0;
    
    do{
    system("cls");
    printf("|------------------------------------------------------------------------------|\n");
    printf("|                               -Laundry Clean-                                |\n");
    printf("|                         Selamat datang di Menu Admin                         |\n");
    printf("|------------------------------------------------------------------------------|\n");
    printf("                      Silahkan masukan username anda :");
    scanf(" %s", &user);
  printf("\n                      Masukkan password anda         :");
    scanf("\t\t\t %s", &pass);
    if (strcmp(user,"salman")==0&&strcmp(pass,"123")==0){

        i = 5;
        Sleep(1000);

   	}else if (strcmp(user,"hafidh")==0&&strcmp(pass,"123")==0){

        i = 6;
        Sleep(1000);

    }else{
    printf("|                       Username dan Password anda salah                       |\n");
    printf("|                            Silahkan input ulang                              |\n");
    printf("|------------------------------------------------------------------------------|\n");
        i = i +1;
        Sleep(1000);
    }
    }while(i<3);
    
	if(i==3){
	printf("|     Mohon maaf jika anda bukan Admin, tidak seharusnya anda mencoba login    |\n");
	printf("|------------------------------------------------------------------------------|\n");
	Sleep(3000);
	exit(0);
	}
	else {
	printf("|                                                                              |\n");
	printf("|                               Akses diterima                                 |\n");
	printf("|                              Selamat Bekerja:)                               |\n");
	printf("|------------------------------------------------------------------------------|\n");
	Sleep(3000);
	}
	
	system("cls");
	printf("|                                  Loading....                                 |\n");
	printf("|                      Sedang mengupdate dan mengecek data                     |\n");
	for(int i=0;i<=75;i++){
	Sleep(30);
    printf("%c",219);
}
        system("cls");
        
    	printf("|                              LOADING SELESAI                                 |\n");
	
	
	printf("|------------------------------------------------------------------------------|\n");
    printf("|                          Ramahlah kepada pengunjung                          |\n");
    printf("|                      Dan jangan lupa bekerja sesuai SOP                      |\n");
    printf("|                                Terima kasih                                  |\n");
    printf("|------------------------------------------------------------------------------|\n");
    Sleep(3000);
    menu();
}


