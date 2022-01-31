
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "laundry.h"



void menu(){
	time_t local;
			time(&local);
			
	//kamus data
	int a;
	
	//codingan
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("================================================================================\n");
	printf("\t\t\t\t|LAUNDRY CLEAN|\n");
	printf("|==============================================================================|\n");
    printf("                         Waktu : %s", ctime(&local));
	printf("|------------------------------------------------------------------------------|\n");
	printf("|=================================MENU UTAMA===================================|\n");
	printf("|1. TRANSAKSI                                                                  |\n");
	printf("|2. HAPUS PESANAN                                                              |\n");
	printf("|3. PETUNJUK PENGGUNAAN                                                        |\n");
	printf("|4. MASUKKAN                                                                   |\n");
	printf("|5. EXIT                                                                       |\n");
	printf("|==============================================================================|\n:");
	scanf(" %d", &a);
	//biar gak kelewat harus dikasih space sebelum % sama sebelum &
	system("cls");
	
	//switch dan case sepaket
	switch (a)
	{
		char a, jawab;
		case 1:
			cekfile();
			break;
		case 2:
			hapus();
			break;
		case 3:
			petunjuk();
			break;
		case 4:
			masukkan();
			break;
		case 5:
			printf("|------------------------------------------------------------------------------|\n");
			printf("|                       APAKAH ANDA YAKIN INGIN LOGOUT?                        |\n");
			printf("|------------------------------------------------------------------------------|\n");
			scanf("%s", &jawab);
			system("cls");
				if(jawab == 'y'|jawab == 'Y') {
			
			printf("|------------------------------------------------------------------------------|\n");
			printf("|                    TERIMA KASIH, ANDA BERHASIL LOGOUT!                       |\n");
			printf("|------------------------------------------------------------------------------|\n");
//			return 0;

			login();
		}
		else{
			menu();
		}
		
		
	}	

}

