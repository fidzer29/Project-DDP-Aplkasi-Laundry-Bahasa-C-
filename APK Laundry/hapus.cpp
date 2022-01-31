#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "laundry.h"

void hapus()
{
	char a,jawab;
	FILE *in=fopen("Data.txt","rb");
	
	//rb=
	//a=masukkan data

	if(!in)
	{ //cek apakah filenya ada atau tidak
		printf("DATA MASIH KOSONG\n");
		getch();
	}
	else 
	{
		printf("|------------------------------------------------------------------------------|\n");
		printf("|             APAKAH ANDA YAKIN INGIN MENGHAPUS SEMUA DATA? (Y/T) :            |\n");
		printf("|------------------------------------------------------------------------------|\n");
		fflush(stdin);
		a=getchar();
		if(a=='y' || a=='Y')
		{
			fclose(in);
			remove("Data.txt");
			printf("|------------------------------------------------------------------------------|\n");
			printf("|                        DATA BERHASIL DIHAPUS!                                |\n");
			printf("|------------------------------------------------------------------------------|\n");
		}
		else if(a=='t' || a=='T')
		{
			printf("|------------------------------------------------------------------------------|\n");
			printf("|                       DATA TIDAK JADI DIHAPUS!                               |\n");
			printf("|------------------------------------------------------------------------------|\n");
		}
		else 
		{
			return hapus();
			printf("|------------------------------------------------------------------------------|\n");
			printf("|                             INPUT ANDA SALAH!                                |\n");
			printf("|------------------------------------------------------------------------------|\n");
		}
	}
	getch();
	
		printf("|------------------------------------------------------------------------------|\n");
		printf("|                   APAKAH INGIN KEMBALI KE MENU UTAMA                         |\n");
		printf("|------------------------------------------------------------------------------|\n");
		scanf(" %s", &jawab);
		fclose(in);
		system("cls");
			if(jawab == 'y'|jawab == 'Y'){
				menu();
			}else{
				hapus();
				//pake fclose?
			}
		
	
}

