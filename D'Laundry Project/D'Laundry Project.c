#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct x{
	char name[99],pass[99];
}regis, login;
struct y{
	char nama[99],alamat[99],nohp[99],berat[99],tanggal[99],paket[99],harga[99];
}pesanan,tahu,sementara[100];
char hapus[99],string[99];
int i,j;

FILE *fp;
FILE *data;
FILE *data2;
FILE *text;

void hapuspesanan();
void buatpesanan();
void signinadmin();
void listpesanan();
void cekpesanan();
void beriharga();
void menuadmin();
void menuuser();
void listuser();
void signup();
void signin();
void awal();

main(){ 
	int n;
	system("cls");
	text=fopen("daslaundry.txt","r");
	while (fgets(string, sizeof(string), text) != NULL){
		printf("%s",string);
	}
	fclose(text);
 	printf("\n\n\n\n\n");
 	printf("\t\t\t\t\t\t");
 	printf("1. Admin\n");
 	printf("\t\t\t\t\t\t");
 	printf("2. User\n");
 	printf("\t\t\t\t\t\t");
 	printf("Pilih: ");
 	scanf("%d",&n); getchar();
 	switch (n){
  		case 1: signinadmin(); break;
  		case 2: awal();break;
  		default: main();
 	}
}

void signup(){ 
 	system ("cls");
 	printf("\n\n\n\n\n\n\n\n\n\n\n");
 	fp=fopen ("datauser.dat", "ab");
 	printf("\t\t\t\t\t\t");
 	printf("Username: "); gets(regis.name);
 	printf("\t\t\t\t\t\t");
 	printf("Password: "); gets(regis.pass);
 	fwrite(&regis, sizeof(regis),1,fp);
 	printf("\t\t\t\t\t    ");
 	printf("Registrasi berhasil!\n");
 	fclose(fp); 
 	system("\t\t\t\tpause"); 
 	awal();
}

void signin(){
	int x=0;
 	system ("cls");
 	printf("\n\n\n\n\n\n\n\n\n\n\n");
 	fp=fopen ("datauser.dat", "rb");
 	printf("\t\t\t\t\t\t");
 	printf("Username: "); gets(login.name);
 	printf("\t\t\t\t\t\t");
 	printf("Password: "); gets(login.pass);
 	while (fread(&regis,sizeof(regis),1,fp)==1){
		if (strcmp(login.name,regis.name)==0 && strcmp(login.pass, regis.pass)==0){
	 		printf("\t\t\t\t\t      ");
   			printf("Login berhasil!\n"); 
   			x = 1;
   			fclose(fp); 
   			system("pause");
   			menuuser(); 
  	 	}
 	}
 	if(x!=1){
 		printf("\t\t\t\t\t");
  		printf("Username atau Password salah\n");
  		system("pause"); 
   		awal();
 	}
}

void signinadmin(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t");
 	printf("Username: "); gets(login.name);
 	printf("\t\t\t\t\t\t");
 	printf("Password: "); gets(login.pass);
	if (strcmp(login.name,"daskom")==0 && strcmp(login.pass, "daskom")==0){
		printf("\t\t\t\t\t\t");
		printf("Login berhasil!"); getchar();
		menuadmin(); 
	} else{
		printf("\t\t\t\t\t");
		printf("Username atau Password salah\n");
  		system("pause"); 
		system("cls");
   		main();
	}
}

void menuuser(){
	int n;
	system ("cls");
	text=fopen("daslaundry.txt","r");
	while (fgets(string, sizeof(string), text) != NULL){
		printf("%s",string);
	}
	fclose(text);
 	printf("\n\n\n\n\n");
 	printf("\t\t\t\t\t\t");
 	printf("1. Buat Pesanan\n");
 	printf("\t\t\t\t\t\t");
 	printf("2. Cek Pesanan\n");
 	printf("\t\t\t\t\t\t");
 	printf("3. Log Out\n");
 	printf("\t\t\t\t\t\t");
 	printf("Pilih: ");
 	scanf("%d", &n);getchar();
 	switch (n){
		case 1: buatpesanan(); break;
		case 2: cekpesanan(); break;
		case 3: awal(); break;
		default:
		printf("\t\t\t\t\t\t"); 
		printf("Menu tidak ada, coba lagi\n");
		system("pause");
		menuuser();
  	}	
}

void buatpesanan(){
	int n;
	system("cls");
	data=fopen("datapesanan.dat","ab");
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t");
 	printf ("PAKET D'LAUNDRY\n");
 	printf("\t\t\t\t\t");
	printf("1. Cuci-Setrika (Rp.6000/kg)\n");
	printf("\t\t\t\t\t");
	printf("2. Cuci-Kering (Rp.5000/kg)\n");
	printf("\t\t\t\t\t");
	printf("3. Setrika (Rp.4000/kg)\n\n");
	printf("\t\t\t\t\t");
	printf("Masukan Jumlah pesanan : "); scanf("%d", &n);getchar();
	for (i=0;i<n;i++){
		printf("\t\t\t\t\t");
		printf("Tanggal\t\t:");gets(pesanan.tanggal);
		printf("\t\t\t\t\t");
		printf("Nama\t\t:"); gets(pesanan.nama);
		printf("\t\t\t\t\t");
		printf("Alamat\t\t:"); gets(pesanan.alamat);
		printf("\t\t\t\t\t");
		printf("No.HP\t\t:"); gets(pesanan.nohp);
		printf("\t\t\t\t\t");
		printf("Berat cucian(kg):"); gets(pesanan.berat);
		printf("\t\t\t\t\t");
		printf("Paket\t\t:"); gets(pesanan.paket);
		printf("\n");
		fwrite(&pesanan, sizeof(pesanan),1,data);
	}
 	fclose(data);
 	printf("\t\t\t\t\t");
 	printf("Pesanan telah dibuat!\n");
 	system("pause");
 	menuuser();
}

void cekpesanan(){
	system("cls");
	printf ("Daftar pesanan:\n\n");
	data=fopen("datapesanan.dat", "rb");
	while(fread(&pesanan,sizeof(pesanan),1,data)==1){
		if (strcmp(login.name,pesanan.nama)==0){
			printf("Tanggal\t\t:%s\n",pesanan.tanggal);
			printf("Nama\t\t:%s\n",pesanan.nama);
			printf("Alamat\t\t:%s\n",pesanan.alamat);
			printf("No.HP\t\t:%s\n",pesanan.nohp);
			printf("Berat cucian(kg):%s\n",pesanan.berat);
			printf("Paket\t\t:%s\n",pesanan.paket);
			printf("Harga:\t\t:%s\n",pesanan.harga);
			printf("\n");
		}
	}
	fclose(data);
	system("pause");
	menuuser();
}

void menuadmin(){
	int n;
 	system("cls");
	text=fopen("daslaundry.txt","r");
	while (fgets(string, sizeof(string), text) != NULL){
		printf("%s",string);
	}
	fclose(text);
 	printf("\n\n\n\n");
 	printf("\t\t\t\t\t\t");
 	printf("1. List User\n");
 	printf("\t\t\t\t\t\t");
 	printf("2. List pesanan\n");
 	printf("\t\t\t\t\t\t");
 	printf("3. Hapus pesanan\n");
 	printf("\t\t\t\t\t\t");
 	printf("4. Log out\n");
 	printf("\t\t\t\t\t\t");
 	printf("Pilih:");
 	scanf("%d", &n);
 	switch (n){
		case 1: listuser(); break;
		case 2: listpesanan(); break;
		case 3: hapuspesanan(); break;
		case 4: main(); break;
		default:
		printf("\t\t\t\t\t\t"); 
		printf("Menu tidak ada, coba lagi\n"); 
		system("pause");
		menuadmin();
	}
}

void awal(){
 	int pilih;
 	system("cls");
	text=fopen("daslaundry.txt","r");
	while (fgets(string, sizeof(string), text) != NULL){
		printf("%s",string);
	}
	fclose(text);
 	printf("\n\n\n\n");
 	printf("\t\t\t\t\t\t");
	printf("1. Sign Up\n");
	printf("\t\t\t\t\t\t");
 	printf("2. Sign In\n");
 	printf("\t\t\t\t\t\t");
 	printf("3. Kembali\n");
 	printf("\t\t\t\t\t\t");
 	printf("Pilih: ");
 	scanf("%d", &pilih); getchar();
 	switch (pilih){
  		case 1: signup(); break;
  		case 2: signin(); break;
  		case 3: main(); break;
  		default: awal();
 	}
}

void listuser(){
	system("cls");
	printf("\t\t\t\t\t\t");
	printf ("USERNAME YANG TERDAFTAR");
	printf("\n\n");
	fp=fopen("datauser.dat","rb");
	while(fread(&regis,sizeof(regis),1,fp)==1){
		printf("\nUsername: %s",regis.name);
		i++;
	}
	fclose(fp);
	printf("\n");
	system("pause");
	menuadmin();
}

void listpesanan(){
	char pil,nama[99];
	int s, i=0;
	system("cls");
	printf("\t\t\t\t\t\t");
	printf ("DAFTAR PESANAN\n\n");
	data=fopen("datapesanan.dat", "rb");
	while(fread(&pesanan,sizeof(pesanan),1,data)==1){
		s=i;
		sementara[s]=pesanan;
		i++;
	}
	for (s=i-1;s>=1;s--)
		for (j=1;j<=s;j++){
			if (strcmp(sementara[j-1].tanggal,sementara[j].tanggal)>0){
				tahu=sementara[j-1];
				sementara[j-1]=sementara[j];
				sementara[j]=tahu;
			}
		}
	for(s=0;s<i;s++){
		printf("Tanggal\t\t:%s\n",sementara[s].tanggal);
		printf("Nama\t\t:%s\n",sementara[s].nama);
		printf("Alamat\t\t:%s\n",sementara[s].alamat);
		printf("No.HP\t\t:%s\n",sementara[s].nohp);
		printf("Berat cucian(kg):%s\n",sementara[s].berat);
		printf("Paket\t\t:%s\n",sementara[s].paket);
		printf("Harga:\t\t:%s\n",sementara[s].harga);
		printf("\n");
	}
	fclose(data);
	
	printf("\t\t\t\t");
	printf("Update harga?(y/n):"); scanf("%s",&pil); getchar();
	if (pil=='Y' || pil=='y'){
		data=fopen("datapesanan.dat", "rb+");
		data2=fopen("datapesanan2.dat", "wb");
		printf("\t\t\t\t");
		printf("Nama\t:"); gets(nama);
		while (fread(&pesanan,sizeof(pesanan),1,data)==1){
			if (strcmp(pesanan.nama,nama)==0){
				printf("\t\t\t\t");
				printf("Harga\t:"); gets(pesanan.harga);
				fwrite (&pesanan,sizeof(pesanan),1,data2);
			} else{
				fwrite (&pesanan,sizeof(pesanan),1,data2);
			}
		}
	fclose(data);
	fclose (data2);
	remove("datapesanan.dat");
	rename("datapesanan2.dat", "datapesanan.dat");
	} else{
		menuadmin();
	}
	printf("\t\t\t\t");
	printf("Pesanan berhasil di-update!\n");
	system("pause");
	menuadmin();	
}

void hapuspesanan(){
	char hapus[99];
	int s,i=0;
	system("cls");
	printf("\t\t\t\t\t\t");
	printf ("DAFTAR PESANAN:\n\n");
	data=fopen("datapesanan.dat", "rb");
	while(fread(&pesanan,sizeof(pesanan),1,data)==1){
		s=i;
		sementara[s]=pesanan;
		i++;
	}
	for (s=i-1;s>=1;s--)
		for (j=1;j<=s;j++)
		{
			if (strcmp(sementara[j-1].tanggal,sementara[j].tanggal)>0){
				tahu=sementara[j-1];
				sementara[j-1]=sementara[j];
				sementara[j]=tahu;
			}
		}
	for(s=0;s<i;s++){
		printf("Tanggal\t\t:%s\n",sementara[s].tanggal);
		printf("Nama\t\t:%s\n",sementara[s].nama);
		printf("Alamat\t\t:%s\n",sementara[s].alamat);
		printf("No.HP\t\t:%s\n",sementara[s].nohp);
		printf("Berat cucian(kg):%s\n",sementara[s].berat);
		printf("Paket\t\t:%s\n",sementara[s].paket);
		printf("Harga:\t\t:%s\n",sementara[s].harga);
		printf("\n");
	}
	fclose(data);
	data=fopen ("datapesanan.dat", "rb");
	data2=fopen ("datapesanan2.dat", "wb");
	printf("\t\t\t\t");
	printf("Masukkan pesanan yang ingin dihapus\n");
	printf("\t\t\t\t");
	printf("Nama:");fflush(stdin); gets(hapus);
	while (fread(&pesanan,sizeof(pesanan),1,data)==1){
		if (strcmp(pesanan.nama,hapus)!=0){
			fwrite(&pesanan,sizeof(pesanan),1,data2);
		}
	}
	fclose(data);
	fclose(data2);
	remove("datapesanan.dat");
	rename("datapesanan2.dat", "datapesanan.dat");
	printf("\t\t\t\t");
	printf("Pesanan berhasil dihapus!\n");
	system("pause");
	menuadmin();
}

