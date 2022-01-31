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

void petunjuk(){
	FILE *data;
	char petunjuk[600];
	
	data = fopen("help.txt", "r");
	
	system("cls");
	while(!feof(data)){
		fgets(petunjuk, sizeof(petunjuk), data);
		printf("%s", petunjuk);
	}
	
	printf("\n\t");
	fclose(data);
	system("pause");
	menu();
}
