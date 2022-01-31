#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#include <time.h>
#include "laundry.h"

struct data 
{
	int diskon,harga,jenis,bayar,bon;
	float berat;
	char nama[30];
	struct data *next;
}*head=NULL,*tail,*baru,*cek,*temp;

int tambah();
int lihat();


//Program untuk menampilkan file 
void cekfile(){
	head=NULL;
	fflush(stdin);
	FILE *in=fopen("Data.txt","rb");
	if(!in)
	{	//cek apakah filenya ada atau tidak 
		printf("\t\t\t\tData masih kosong\n");
		tambah();
		getch();
	}
	else
	{
		lihat();
	}
	fclose(in);
}


//program untuk menambahkan data pesanan
int tambah ()
{
	char jwb;
	int i;
	float c;
	baru=(struct data*)malloc(sizeof(struct data));
	back:
	printf("|------------------------------------------------------------------------------|\n");
	printf("|                              JENIS PAKET :                                   |\n");
	printf("|                1.Biasa (5000/kg) = selesai dalam 3 hari                      |\n");
	printf("|                2.Express (8000/kg) = selesai dalam 2 hari                    |\n");
	printf("|------------------------------------------------------------------------------|\n");
	printf("|                              PILIH PAKET :                                   |\n");
	scanf("%d",&baru->jenis);
		if(baru->jenis == 1|baru->jenis == 2){
		while(baru->jenis<1 || baru->jenis>2)
		
	{
		printf("Input salah\n");
		printf("Silahkan Ulangi\n");
		getch();
		system("cls");
		printf("Jenis Laundry\t:1.Biasa (5000/kg)\n");
		printf("\t\t 2.Express(8000/kg)");
		printf("\nPilih\t\t: ");
		scanf("%d", &baru->jenis);
	}
	printf("|------------------------------------------------------------------------------|\n");
	printf("|                             Nama Pelanggan :                                 |\n");
	fflush(stdin);
	gets(baru->nama);
	printf("|                             Berat Laundry(kg) :                              |\n");
	scanf("%f",&baru->berat);
	printf("|------------------------------------------------------------------------------|\n");
	if(baru->jenis==1)
	{
		baru->harga=5000*baru->berat;
	}
	else if(baru->jenis==2)
	{
		baru->harga=8000*baru->berat;
	}
	else if(baru->jenis==3)
	{
		baru->harga=10000*baru->berat;
	}
	
	baru->diskon=0;
	c=0;
	
	for(i=2;i<=baru->berat;i=i+2)
	{
		if(i<=50)
		{
			c=(0.03+(0.01*i));
			baru->diskon=baru->harga*c;
		}
		
	}
	printf("|------------------------------------------------------------------------------|\n");
	printf("Harga\t\t= %d\n",baru->harga);
	printf("Diskon (%.0f%c)\t= %d\n",c*100,37,baru->diskon);
	baru->harga=baru->harga-baru->diskon;
	printf("Total\t\t= %d\n",baru->harga);
	bayar:
	printf("|------------------------------------------------------------------------------|\n");
	printf("|                              Jenis Bayar:                                    |\n");
	printf("|                              1.Lunas                                         |\n");
	printf("|                              2.Bon (min dp 30%c)                              |\n",37);
	printf("|                              Pilih :                                         |\n");
	scanf("%d",&baru->bayar);
	printf("|------------------------------------------------------------------------------|\n");
	if(baru->bayar==1)
	{
		baru->bayar = 0;
		baru->bon = 0;
//		
		bayar2 :
		printf("|                      Bayar=                                                  |\n");
		scanf("%d",&baru->bayar);
		
		if(baru->bayar > baru->harga){
			printf("kembalian : %d \n" ,baru->bayar - baru->harga);
		}
		else{
		printf("|------------------------------------------------------------------------------|\n");
		printf("|             		   Uang Kurang, Bayar Harus Lunas!	   		               |\n");
		printf("|------------------------------------------------------------------------------|\n");
			goto bayar2;
		}
		printf("|------------------------------------------------------------------------------|\n");
		printf("|                Anda telah membayar dengan lunas, terima kasih!               |\n");
		printf("|------------------------------------------------------------------------------|\n");
	}
	else if(baru->bayar==2)
	{
		bon:
			printf("|------------------------------------------------------------------------------|\n");
			printf("|                      Wajib dp min 30%c=> %0.f                                |\n",37,baru->harga*0.3);
			printf("|                      Bayar=                                                  |\n");
			scanf("%d",&baru->bayar);
			if(baru->bayar<(baru->harga*0.3))
			{
				printf("|                  Uang Kurang, Bayar Ulang!                               |\n");
				getch();
				goto bon;
			}
			else
			{
				if(baru->bayar>=baru->harga)
				{
					printf("Kembalian\t= %d\n", (baru->bayar-baru->harga));
					printf("Bayar Lunas!");
					baru->bayar=baru->harga=baru->bon=0;
				}
				else
				{
					baru->bon=baru->harga-baru->bayar;
					printf("Transaksi Berhasil\nSisa Bon\t= %d \n",baru->bon);
				}
			}	
		
	}
	else
	{
		printf("Input Salah\nSilahkan Ulangi");
		getch();
		goto bayar;
	}
	getch();
	
	
	if(head==NULL)
	{
		head=tail=baru;
	}
	else
	{
		tail->next=baru;
		tail=baru;
	}
	FILE *out=fopen("Data.txt","ab+");
	fprintf(out,"%s#%f#%d#%d#%d#\n", baru->nama,baru->berat,baru->jenis,baru->bayar,baru->bon);
	fclose(out);
	
	printf("|------------------------------------------------------------------------------|\n");
	printf("|           apakah anda ingin melihat data yang sudah terupdate?               |\n");
	scanf("%s",&jwb);
		if(jwb == 'y'|jwb == 'Y'){
			system("cls");
			lihat();
		}
		else{
			menu();
		}
			
		}else{
			printf("invalid input");
			goto back;
		}
	printf("|------------------------------------------------------------------------------|\n");
}

//program untuk melihat data 
int lihat(){
		head=NULL;
	fflush(stdin);
	FILE *in=fopen("Data.txt","rb");
	if(!in)
	{	//cek apakah filenya ada atau tidak 
		printf("Data masih kosong\n");
		fclose(in);
		getch();
	}
	else
	{
		while(!feof(in))
		{
			fflush(stdin);
			baru=(struct data*)malloc(sizeof(struct data));
			fscanf(in,"%[^#]#%f#%d#%d#%d#\n",&baru->nama,&baru->berat,&baru->jenis,&baru->bayar,&baru->bon);
			if(head==NULL)
			{
				head=tail=baru;
			}
			else
			{
				tail->next=baru;
				tail=baru;
				tail->next=NULL;
			}
		}
		fclose(in);
		cek=head;
		int i=1,a,b;
		printf("|------------------------------------------------------------------------------|\n");
		printf("|                               Data :                                         |\n");
		printf("|No\tNama\tBerat\t\tJenis\t\tStatus|\n");
		while(cek!=tail->next)
		{
			printf("%d.\t%s\t%.1f kg\t\t",i,cek->nama,cek->berat);
			if(cek->jenis==1)
			{
				printf("Biasa\t\t");
			}
			else
			{
				printf("Express\t\t");
			}
			if(cek->bon==0)
			{
				printf("Lunas");
			}
			else
			{
				printf("Bon\t%d",baru->bon);
			}
			printf("\n");
			i++;
			cek=cek->next;
		}
		printf("|------------------------------------------------------------------------------|\n");
		printf("|                                 Menu:                                        |\n");
		printf("|                                 1.Bayar                                      |\n");
		printf("|                                 2.Kembali ke Menu                            |\n");
		printf("|                                 3.Tambah Data                                |\n");
		printf("|                                 Pilihan :                                    |\n");
		printf("|------------------------------------------------------------------------------|\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Bayar No : ");
				scanf("%d",&a);
				cek=head;
				for(b=1;b<a;b++)
				{
					cek=cek->next;
				}
				kurang :
				printf("Data:\n");
				printf("Nama \t\t= %s\n",cek->nama);
				printf("Jenis\t\t= ");
				if(cek->jenis==1)
				{
					printf("Biasa\n");
				}
				else if(cek->jenis==2)
				{
					printf("Express\n");
				}
				printf("Berat\t\t= %.0f kg\n",cek->berat);
				if(cek->bayar<=0)
				{
					Sleep(30);
					printf("%s sudah lunas",cek->nama);
					Sleep(3000);
					system("cls");
					lihat();
				}
				else if(cek->bayar>0)
				{
					printf("Bon\t\t= %d\n",cek->bon);
					printf("Bayar (harus lunas) \t= ");
					scanf("%d",&b);
					if(b<cek->bon)
					{
						printf("Uang Kurang\nMasukan Ulang!");
						goto kurang;
					}
					else
					{
						printf("Kembalian\t\t= %d\n",b-cek->bon);
						printf("Transaksi Berhasil!");
						cek->bayar=cek->bon=0;
						FILE *in=fopen("Data.txt","w");
						cek=head;
						while(cek!=tail->next)
						{
							fflush(stdin);
							fprintf(in,"%s#%f#%d#%d#%d#\n",cek->nama,cek->berat,cek->jenis,cek->bayar,cek->bon);
							cek=cek->next;
						}
						fclose(in);
						Sleep(3000);
					 	system("cls");
					}
					lihat();
				}
				break;
			case 2:
			 menu();
				break;
			case 3:
				system("cls");
			 tambah();
				break;
			default:
				printf("Input Salah\nSilahkan Ulangi!");
				getch();
				system("cls");
				return lihat();
				break;
		}
		getch();
		
	}
	fclose(in);
}
