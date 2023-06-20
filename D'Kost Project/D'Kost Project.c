#include<stdio.h>
#include<string.h>

struct{
	char alamat[100], luas[100], namakamar[100], fasilitas[100], status[100], nohp[100], email[100], uname[100], pass[100], stop[100];
 	long int harga, bayar;
}kmr, temp[100], temp2, signin, signup;

int i, j, n, chance=3, invoice=3141;
char dicari[100];
char nama[100];
FILE *kamar;
FILE *kamar2;
FILE *user;
FILE *admin;

void signinadmin();
void menuadmin();
void awaluser();
void menuuser();
void inputkamar();
void tambahkamar();
void updatesewauser();
void hapuskamar();
void logout();
void signupuser();
void signinuser();
void sewakamar();
void listkamar1();
void rinciankamar();

main (){
	int pilmenu,menuadmin,menuuser;
	system("cls");
	printf("\t==============");
	printf("\n\t=== D'KOST ===");
	printf("\n\t==============");
	printf("\n\n1. Admin");
	printf("\n2. User");
	printf("\n\nMasuk sebagai : "); scanf("%d",&pilmenu); getchar();
	system("cls");
	
	switch(pilmenu){
		case 1: signinadmin(); break;
		case 2: awaluser(); break;
		default: printf("Maaf menu tidak tersedia"); main(); break;
	}
}

void signinadmin(){
	system("cls");
	printf("Username : ");gets(signin.uname);
	printf("Password : ");gets(signin.pass);
		
	if (strcmp(signin.uname,"1")==0 && strcmp(signin.pass, "1")==0){
		printf("Login berhasil!"); getchar();
		menuadmin(); 
	} 
		
	else{
		chance--;
		printf("\nUsername atau Password salah\n");
		printf("Sisa kesempatan %d kali\n", chance);
		system("pause");
			
		if (chance==0){
			printf("Kesempatan sudah habis ya ges\n");
			system("pause");
			main();
		}
		signinadmin(); 
	}
}

void menuadmin(){
	system("cls");
	int n;
	printf("\t==================");
	printf("\n\tMENU SEBAGAI ADMIN");
	printf("\n\t==================\n");
	printf("1. Input kamar\n");
	printf("2. Tambah kamar\n");
	printf("3. Hapus kamar\n");
	printf("4. List kamar\n");
	printf("5. Log out\n");
	printf("\n\nPilih menu : "); scanf("%d",&n);
	switch (n){
		case 1: inputkamar(); break;
		case 2: tambahkamar(); break;
		case 3: hapuskamar(); break;
		case 4: listkamar1(); break;
		case 5: main(); break;
		default: printf("Maaf menu tidak terserdia"); menuadmin(); break;
	}
}

void awaluser(){
	system("cls");
	int n;
	printf("\t==================");
	printf("\n\tSEBAGAI USER");
	printf("\n\t==================\n");
	printf("\n1. Sign Up");
	printf("\n2. Sign In"); 
	printf("\nPilih : "); scanf("%d", &n); getchar();
	switch(n){
		case 1: signupuser(); break;
		case 2: signinuser(); break;
		default: awaluser(); break;
	}
}

void menuuser(){
	system("cls");
	int n;
	int i, j, s;
	printf("\t==================");
	printf("\n\tSELAMAT DATANG %s", signin.uname);
	printf("\n\t==================\n");
	printf("\n\t==LIST KAMAR==\n\n");
	kamar=fopen("listkamar.dat","rb");
	while(fread(&kmr, sizeof(kmr), 1, kamar)==1){
		s=i;
		temp[s]=kmr;
		i++;
	}
	for (s=i-1;s>=1;s--)
		for (j=1;j<=s;j++)
		{
			if (temp[j-1].harga>temp[j].harga){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	for(s=0;s<i;s++){
		printf("%d. Nama Kos\t\t:%s\n",s+1,temp[s].namakamar);
		printf("   Harga sewa per bulan\t:%d\n",temp[s].harga);
		printf("   Dibooking oleh\t:%s\n", temp[s].status);
		printf("\n");
	}
	fclose(kamar);
	printf("\t==MAIN MENU==\n");
	printf("\n1. Rincian Kost");
	printf("\n2. Sewa Kost");
	printf("\n3. Status Sewa Kost");
	printf("\n4. Logout");
	printf("\n\nNote:");
	printf("\nPembayaran Harus Uang Pas!!!");
	printf("\nUsername dan Nama Pemesan Harus Sama!!!");
	printf("\n\nPilih menu : "); scanf("%d",&n);
	switch (n){
		case 1: rinciankamar(); break;
		case 2: sewakamar(); break;
		case 3: updatesewauser(); break; 
		case 4: main (); break;
		default: printf("Maaf menu tidak tersedia"); menuuser(); break;
	}
}

void inputkamar(){
	system("cls");
	kamar=fopen("listkamar.dat","wb");
	printf("Masukkan jumlah kamar : "); scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		printf("\nNama Kost\t\t: "); gets(kmr.namakamar);
		printf("Harga sewa per bulan\t: "); scanf("%d", &kmr.harga); getchar();
		printf("Luas (m^2)\t\t: "); gets(kmr.luas);
		printf("Alamat\t\t\t: "); gets(kmr.alamat);
		printf("Fasilitas\t\t: "); gets(kmr.fasilitas);
		fwrite(&kmr, sizeof(kmr),1,kamar);
	}
	fclose(kamar);
	menuadmin(); 
}

void tambahkamar(){
	int n;
	system ("cls");
	kamar = fopen("listkamar.dat", "ab");
	printf("Silahkan masukkan banyaknya kamar tambahan: ");
	scanf("%d", &n); getchar();
	
	for (i=1; i<=n; i++){
		printf("Nama Kost\t\t: "); gets(kmr.namakamar);
		printf("Harga sewa per bulan\t: "); scanf("%d", &kmr.harga); getchar();
		printf("Luas(m^2)\t\t: "); gets(kmr.luas);
		printf("Alamat\t\t\t: "); gets(kmr.alamat);
		printf("Fasilitas\t\t: "); gets(kmr.fasilitas);
		fwrite(&kmr, sizeof (kmr), 1, kamar);
		printf("Input berhasil ditambahkan!\n");
		system("pause");
	}
	fclose(kamar);
	menuadmin();
}

void updatesewauser(){
	char y;
	system("cls");
	printf ("Kost-Kostan ku :\n\n");
	kamar=fopen("listkamar.dat", "rb");
	while(fread(&kmr,sizeof(kmr),1,kamar)==1){
		if (strcmp(signin.uname,kmr.status)==0){
			printf("Nama Kos\t\t:%s\n",kmr.namakamar);
			printf("Harga sewa per bulan\t:%d\n",kmr.harga);
			printf("Luas (m^2)\t\t:%s\n",kmr.luas);
			printf("Alamat\t\t\t:%s\n",kmr.alamat);
			printf("Fasilitas\t\t:%s\n",kmr.fasilitas);
			printf("Dibooking oleh\t\t:%s\n", kmr.status);
			printf("No.hp\t\t\t:%s\n", kmr.nohp);
			printf("Email\t\t\t:%s\n", kmr.email);
			printf("Pembayaran\t\t:%d\n", kmr.bayar);
			printf("Invoice\t\t\t:%d%s\n",invoice, kmr.nohp);
			printf("\n");
		}
	}
	fclose(kamar);
	printf("Berhenti ngekost ga nih bestie (y/g)?"); scanf("%s", &y); getchar();
	if (y=='Y' || y=='y'){
	kamar=fopen("listkamar.dat", "rb+");
	kamar2=fopen("listkamar2.dat", "wb");
	while (fread(&kmr,sizeof(kmr),1,kamar)==1){
		printf("nama kostan: "); gets(nama);
		if (strcmp(kmr.namakamar, nama)==0){
			strcpy(kmr.stop, "berhenti");
			fwrite (&kmr,sizeof(kmr),1,kamar2);
		}
			else {
			fwrite (&kmr,sizeof(kmr),1,kamar2);
			}
		}
	fclose(kamar);
	fclose (kamar2);
	remove("listkamar.dat");
	rename("listkamar2.dat", "listkamar.dat");
} else{
	menuuser();
}
	printf("Okeh tengkyuu, admin bakal segera memprosesnya ya\n");
	system("pause");
	menuuser();
}

void hapuskamar(){
	int i, j, s;
	system("cls");
	
	kamar=fopen("listkamar.dat","rb");
	while(fread(&kmr, sizeof(kmr), 1, kamar)==1){
		s=i;
		temp[s]=kmr;
		i++;
	}
	for (s=i-1;s>=1;s--)
		for (j=1;j<=s;j++)
		{
			if (temp[j-1].harga>temp[j].harga){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	for(s=0;s<i;s++){
		printf("%d. Nama Kos\t\t:%s\n",s+1, temp[s].namakamar);
		printf("   Harga sewa per bulan\t:%d\n",temp[s].harga);
		printf("   Luas (m^2)\t\t:%s\n",temp[s].luas);
		printf("   Alamat\t\t:%s\n",temp[s].alamat);
		printf("   Fasilitas\t\t:%s\n",temp[s].fasilitas);
		printf("   Dibooking oleh\t: %s\n", temp[s].status);
		printf("   No.hp\t\t: %s\n", temp[s].nohp);
		printf("   Email\t\t: %s\n", temp[s].email);
		printf("   Pembayaran\t\t: %d\n", temp[s].bayar);
		printf("   Invoice\t\t: %d%s\n",invoice, temp[s].nohp);
		printf("   Status\t\t: %s", temp[s].stop);
		printf("\n\n");
	}
	fclose(kamar);
	kamar = fopen("listkamar.dat", "rb");
	kamar2 = fopen("listkamar2.dat", "wb");
	printf("Silahkan masukkan nama kamar yang akan dihapus: "); fflush (stdin); gets(dicari);
	
	while (fread(&kmr,sizeof (kmr),1, kamar)==1){
		if (strcmp(kmr.namakamar, dicari)!=0){
			fwrite(&kmr, sizeof(kmr), 1, kamar2);
		}
	}
	fclose(kamar);
	fclose(kamar2);
	remove("listkamar.dat");
	rename("listkamar2.dat","listkamar.dat");
	menuadmin();
}

void listkamar1(){
	system("cls");
	int i, j, s;
	kamar=fopen("listkamar.dat","rb");
	while(fread(&kmr, sizeof(kmr), 1, kamar)==1){
		s=i;
		temp[s]=kmr;
		i++;
	}
	for (s=i-1;s>=1;s--)
		for (j=1;j<=s;j++)
		{
			if (temp[j-1].harga>temp[j].harga){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	for(s=0;s<i;s++){
		printf("%d. Nama Kos\t\t:%s\n",s+1, temp[s].namakamar);
		printf("   Harga sewa per bulan\t:%d\n",temp[s].harga);
		printf("   Luas (m^2)\t\t:%s\n",temp[s].luas);
		printf("   Alamat\t\t:%s\n",temp[s].alamat);
		printf("   Fasilitas\t\t:%s\n",temp[s].fasilitas);
		printf("   Dibooking oleh\t: %s\n", temp[s].status);
		printf("   No.hp\t\t: %s\n", temp[s].nohp);
		printf("   Email\t\t: %s\n", temp[s].email);
		printf("   Pembayaran\t\t: %d\n", temp[s].bayar);
		printf("   Invoice\t\t: %d%s\n",invoice, temp[s].nohp);
		printf("   Status\t\t: %s", temp[s].stop);
		printf("\n\n");
	}
	fclose(kamar);
	system("pause");
	menuadmin();
}

void signupuser(){
	system("cls");
	user=fopen("datauser.dat","ab");
	printf("Username: "); gets(signup.uname);
	printf("Password: "); gets(signup.pass);
	fwrite(&signup, sizeof(signup),1,user);
	printf("Registrasi berhasil!\n");
	fclose(user); 
	system("pause");
	awaluser(); 
}

void signinuser(){
	int x=0;
	system ("cls");
	user=fopen ("datauser.dat", "rb");
	printf("Username: "); gets(signin.uname);
	printf("Password: "); gets(signin.pass);
	
	while (fread(&signup,sizeof(signup),1,user)==1){
		if (strcmp(signin.uname,signup.uname)==0 && strcmp(signin.pass, signup.pass)==0){
			printf("Login berhasil!\n"); 
			x = 1;
			fclose(kamar); 
			system("pause");
			menuuser(); 
		}
 	}
 	
	if(x!=1){
		chance--;
		printf("\nUsername atau Password salah\n");
		printf("Sisa kesempatan %d kali\n",chance);
		system("pause"); 
	
		if (chance==0){
			printf("Kesempatan sudah habis\n");
			system("pause");
			awaluser();
		}
		signinuser();
 	}
 }

void sewakamar(){
	kamar=fopen("listkamar.dat", "rb+");
	kamar2=fopen("listkamar2.dat", "wb");
	printf("\t\t\t\t");
	printf("Nama Kos yg ingin dipesan\t:");fflush(stdin); gets(nama);
	while (fread(&kmr,sizeof(kmr),1,kamar)==1){
		if (strcmp(kmr.namakamar,nama)==0){
			printf("\t\t\t\t");
			printf("Nama Pemesan\t\t\t:"); gets(kmr.status);
			printf("\t\t\t\t");
			printf("No. HP\t\t\t\t:"); gets(kmr.nohp);
			printf("\t\t\t\t");
			printf("Email\t\t\t\t:"); gets(kmr.email);
			printf("\t\t\t\t");
			printf("Pembayaran\t\t\t:"); scanf("%d", &kmr.bayar);
			if (kmr.bayar<kmr.harga){
				printf("\t\t\t\t\t");
				printf("Jumlah pembayaran kurang!\n");
				system("pause");
				menuuser();

				} else {
					printf("\t\t\t\t");
				printf("Invoice\t\t\t\t:%d%s\n", invoice, kmr.nohp);
				strcpy(kmr.stop,"dihuni");
				printf("\t\t\t\t\t");
				printf("Pesanan berhasil!\n");
				fwrite (&kmr,sizeof(kmr),1,kamar2);
				}
		} else{
				fwrite (&kmr,sizeof(kmr),1,kamar2);
				}
		}
	fclose(kamar);
	fclose (kamar2);
	remove("listkamar.dat");
	rename("listkamar2.dat", "listkamar.dat");
	system("pause");
	menuuser();
}

void rinciankamar(){
	int no_struct;
    long int offset_byte;    
	kamar = fopen("listkamar.dat", "rb");
    printf("Silahkan masukkan nomor urutan: ");
    scanf("%d", &no_struct);
    	offset_byte = (no_struct-1) * sizeof(kmr);
    	fseek (kamar, offset_byte, SEEK_SET);

    if (fread(&kmr, sizeof(kmr), 1, kamar) == 0)
    {
        printf("Kost tidak ada\n");
        system("pause");
        menuuser();
    }
    else
    {
        printf("Nama Kos\t\t: %s\n", kmr.namakamar);
        printf("Harga sewa per bulan\t: %d\n", kmr.harga);
        printf("Luas (m^2)\t\t: %s\n", kmr.luas);
        printf("Alamat\t\t\t: %s\n", kmr.alamat);
        printf("Fasilitas\t\t: %s\n", kmr.fasilitas);
        printf("Dibooking oleh\t\t: %s\n", kmr.status);
    }

    fclose(kamar);
    system("pause");
    menuuser();
}

