#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//Khai bao ham
	int choose,i,j,location,count,check;
	char tempName[100];
	float tempPrice;
	int n=5;
	char checkName[100];
	struct Dish{
		int id;
		char name[100];
		float price;		
	};
	struct Dish menu[100]={
		{1,"Tom chien gion",100},
		{2,"Ca chep om dua",150},
		{3,"Thit cho",200},
		{4,"Ga luoc",100},
		{5,"Rau xao",70},
	};
	
	//Hien thi menu
	while(choose!=7) {		
	printf("\nMENU\n");
	printf("1.In ra gia tri cac phan tu co trong menu\n");
	printf("2.Them 1 phan tu vao vi tri chi dinh\n");
	printf("3.Sua 1 phan tu o vi tri chi dinh \n");
	printf("4.Xoa 1 phan tu o vi tri chi dinh\n");
	printf("5.Sap xep cac phan tu tang dan\n");
	printf("6.Tim kiem phan tu\n");
	printf("7.Thoat\n");
	printf("Moi ban nhap lua chon cua minh:");
	scanf("%d",&choose);
	
	switch(choose) {
		case 1://In ra gia tri cac phan tu co trong menu
			printf("Menu chon mon\n");
			count=1;
			for(i=0;i<n;i++) {
				menu[i].id=count;
				printf("%d.%s:%.3f\n",menu[i].id,menu[i].name,menu[i].price);
				count++;
			}
			break;
		case 2://Them 1 phan tu vao vi tri chi dinh
		    printf("Moi ban nhap vi tri ban muon them:");
		    scanf("%d",&location);
		    for(i=n;i>location-1;i--) {
		    	menu[i].id=menu[i-1].id;
		    	strcpy(menu[i].name,menu[i-1].name);
		    	menu[i].price=menu[i-1].price;
			}
			n++;
			fflush(stdin);
		    printf("Moi ban nhap mon muon them:");
		    fgets(menu[location-1].name,100,stdin);
		    menu[location-1].name[strcspn(menu[location].name,"\n")]='\0';
			printf("Moi ban nhap gia cho mon vua roi:");
		    scanf("%f",&menu[location-1].price);
		    getchar();
		    count=1;
		    for(i=0;i<n;i++) {
				menu[i].id=count;
				printf("%d.%s:%.3f\n",menu[i].id,menu[i].name,menu[i].price);
				count++;
			}
			break;
		case 3://Sua 1 phan tu o vi tri chi dinh
		    printf("Moi ban nhap vi tri ban muon sua:");
		    scanf("%d",&location);
		    fflush(stdin);
		    printf("Moi ban nhap mon muon thay vao:");
		    fgets(menu[location].name,100,stdin);
		    menu[location].name[strcspn(menu[location].name,"\n")]='\0';
			printf("Moi ban nhap gia moi cho mon vua thay vao:");
		    scanf("%f",&menu[location].price);
		    getchar();
		    count=1;
		    for(i=0;i<n;i++) {
				menu[i].id=count;
				printf("%d.%s:%.3f\n",menu[i].id,menu[i].name,menu[i].price);
				count++;
			}
			break;
		case 4://Xoa 1 phan tu o vi tri chi dinh
  		    printf("Moi ban nhap vi tri ma ban muon xoa:");
  		    scanf("%d",&location);
  		    n--;
  		    for(i=location-1;i<n;i++) {
  		    	strcpy(menu[i].name,menu[i+1].name);
  		    	menu[i].price=menu[i+1].price;
			}
			count=1;
			for(i=0;i<n;i++) {
				menu[i].id=count;
				printf("%d.%s:%.3f\n",menu[i].id,menu[i].name,menu[i].price);
				count++;
			}
			break;
		case 5://Sap xep cac phan tu
			printf("Menu sau khi duoc sap xep la:\n");
			for(i=1;i<n-1;i++) {
				for(j=1;j<n-i-1;j++) {
					if(menu[j].price > menu[j-1].price) {
						strcpy(tempName,menu[j].name);
						strcpy(menu[j].name,menu[j-1].name);
						strcpy(menu[j-1].name,tempName);
						tempPrice=menu[j].price;
						menu[j].price=menu[j-1].price;
						menu[j-1].price=tempPrice;
					}
				}
			}
			count=1;
			for(i=0;i<n;i++) {
				menu[i].id=count;
				printf("%d.%s:%.3f\n",menu[i].id,menu[i].name,menu[i].price);
				count++;
			}
			break;
		case 6://Tim kiem phan tu
			check=0;
			fflush(stdin);
			printf("Moi ban nhap mon muon kiem:");
			fgets(checkName,100,stdin);
			checkName[strcspn(checkName,"\n")]='\0';
			for(i=0;i<n;i++) {
				if(strcmp(checkName,menu[i].name)==0) {
					check++;
					printf("Mon %s co trong menu voi gia %.3f\n",checkName,menu[i].price);
				}
			}
			if(check==0) {
				printf("Mon %s khong co trong menu",checkName);
			}
			break;
		case 7://Thoat
			printf("Thoat chuong trinh\n");
			break;
	}
	}
		printf("HEN GAP LAi!!!");
	return 0;
 }

