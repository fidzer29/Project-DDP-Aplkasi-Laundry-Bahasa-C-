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

void masukkan(){
	
    char text[255];
    FILE *fptr;

    fptr = fopen("masukkan.txt","a");

	system("cls");
	
    for(int i = 0; i <= 1; i++)
	
	{
    printf("|------------------------------------------------------------------------------|\n");
	printf("|                     silahkan ketik masukkan anda :                           |\n", i);
    fgets(text, sizeof(text), stdin);
	fputs(text, fptr);
	}
    printf("|              masukkan anda telah tersimpan, terima kasih                     |\n");
    printf("|------------------------------------------------------------------------------|\n");
		

    fclose(fptr);
    Sleep(3000);
    menu();

}
