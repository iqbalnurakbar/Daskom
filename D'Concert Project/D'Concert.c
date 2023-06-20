#include<stdio.h>
#include<string.h>

struct{
	char uname[100], nama[100], pass[100];
}signup, signin;

struct{
	char jumlah[100], jenis[100], namaconcert[100], tanggal[100], status[100],ket[100],hp[100];
	int harga, harga_VVIP,harga_VIP,harga_reguler,bayar,saldo, VVIP, VIP, reguler, total_seat, sementara;
}ccr, temp[100], temp2;

int i,j,n,chance=3;
char dicari[100];
char nama[100],jenis[100];
FILE *concert;
FILE *concert2;
FILE *user;
FILE *admin;
FILE *saldo;

void signinadmin();
void menuadmin();
void awaluser();
void menuuser();
void inputconcert();
void tambahconcert();
void cancel();
void userupdate();
void hapusconcert();
void logout();
void signupuser();
void signinuser();
void bookingconcert();
void listconcert1();
void rincianconcert();
void pembayaran();
void topup();
void lihattiket();

main (){
	int pilmenu,menuadmin,menuuser;
	system("cls");
	printf("\t==============");
	printf("\n\t=== D'CONCERT ===");
	printf("\n\t==============");
	printf("\n\n1. Admin");
	printf("\n2. User");
	printf("\n\nMasuk sebagai : "); scanf("%d",&pilmenu); getchar();
	system("cls");
	
	switch(pilmenu){
		case 1: signinadmin(); break;
		case 2: awaluser(); break;
		default: printf("Maaf menu tidak terserdia"); break;
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
	int menuadmin;
	printf("\t==================");
	printf("\n\tMENU SEBAGAI ADMIN");
	printf("\n\t==================\n");
	printf("1. Input concert\n");
	printf("2. Tambah concert\n");
	printf("3. Hapus concert\n");
	printf("4. List concert\n");
	printf("5. Log out\n");
	printf("\n\nPilih menu : "); scanf("%d",&menuadmin);
	switch (menuadmin){
		case 1: inputconcert(); break;
		case 2: tambahconcert(); break;
		case 3: hapusconcert(); break;
		case 4: listconcert1(); break;
		case 5: main(); break;
		default: printf("Maaf menu tidak terserdia");
	}
}

void awaluser(){
	system("cls");
	int awaluser;
	printf("\t==================");
	printf("\n\tSEBAGAI USER");
	printf("\n\t==================\n");
	printf("\n1. Sign Up");
	printf("\n2. Sign In"); 
	printf("\nPilih : "); scanf("%d", &awaluser); getchar();
	switch(awaluser){
		case 1: signupuser(); break;
		case 2: signinuser(); break;
	}
}

void menuuser(){
	system("cls");
	int menuuser;
	int i, j, s;
	printf("\t==================");
	printf("\n\tMENU SEBAGAI USER");
	printf("\n\t==================\n");
	printf("\n\tLIST concert\n\n");
	concert=fopen("listconcert.dat","rb");
	while(fread(&ccr, sizeof(ccr), 1, concert)==1){
		s=i;
		temp[s]=ccr;
		i++;
	}
	for (s=i-1;s>=1;s--)
		for (j=1;j<=s;j++)
		{
			if (temp[j-1].harga_reguler>temp[j].harga_reguler){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	for(s=0;s<i;s++){
		printf("%d. Nama event\t:%s\n",s+1,temp[s].namaconcert);
		printf("   Harga\t:%d - %d\n",temp[s].harga_reguler, temp[s].harga_VVIP);
		printf("\n");
	}
	fclose(concert);
	printf("\n1. Rincian event");
	printf("\n2. Beli tiket");
	printf("\n3. Top up saldo");
	printf("\n4. Lihat tiket");
	printf("\n5. Batalkan pesanan");
	printf("\n6. Logout");
	printf("\n\nPilih menu : "); scanf("%d",&menuuser);
	switch (menuuser){
		case 1: rincianconcert(); break;
		case 2: bookingconcert(); break;
		case 3: topup(); break;
		case 4: lihattiket(); break;
		case 5: cancel (); break;
		case 6: main (); break;
		default: printf("Maaf menu tidak terserdia");
	}
}

void inputconcert(){
	system("cls");
	concert=fopen("listconcert.dat","wb");
	printf("Masukkan jumlah concert : "); scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		printf("\nNama event: "); gets(ccr.namaconcert);
		printf("Tanggal: "); gets(ccr.tanggal);
		printf("Jumlah VVIP: ");scanf("%d", &ccr.VVIP);
		printf("Harga : "); scanf("%d",&ccr.harga_VVIP);
		printf("Jumlah VIP: "); scanf("%d", &ccr.VIP);
		printf("Harga : "); scanf("%d",&ccr.harga_VIP);
		printf("Jumlah Reguler: "); scanf("%d", &ccr.reguler);
		printf("Harga : "); scanf("%d",&ccr.harga_reguler); getchar();
		fwrite(&ccr, sizeof(ccr),1,concert);
		printf("Input berhasil!\n");
		system("pause");
	}
	fclose(concert);
	menuadmin(); 
}

void tambahconcert(){
	system ("cls");
	concert = fopen("listconcert.dat", "ab");
	printf("Silahkan masukkan banyaknya concert tambahan: ");
	scanf("%d", &n); getchar();
	
	for(i=1;i<=n;i++){
		printf("\nNama event: "); gets(ccr.namaconcert);
		printf("Tanggal: "); gets(ccr.tanggal);
		printf("Jumlah VVIP: ");scanf("%d", &ccr.VVIP);
		printf("Harga : "); scanf("%d",&ccr.harga_VVIP);
		printf("Jumlah VIP: "); scanf("%d", &ccr.VIP);
		printf("Harga : "); scanf("%d",&ccr.harga_VIP);
		printf("Jumlah Reguler: "); scanf("%d", &ccr.reguler);
		printf("Harga : "); scanf("%d",&ccr.harga_reguler); getchar();	
		fwrite(&ccr, sizeof(ccr),1,concert);
		printf("Input berhasil !");
		system("pause");
	}
	fclose(concert);
	menuadmin();
}

void hapusconcert(){
	int i, j, s;
	system("cls");
	
	concert=fopen("listconcert.dat","rb");
	while(fread(&ccr, sizeof(ccr), 1, concert)==1){
		s=i;
		temp[s]=ccr;
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
		printf("%d. Nama event\t:%s\n",s, temp[s].namaconcert);
		printf("Tanggal\t\t:%s\n",temp[s].tanggal);
		printf("VVIP\t\t:%d kursi\n",temp[s].VVIP);
		printf("VIP\t\t:%d kursi\n",temp[s].VIP);
		printf("Reguler\t\t:%d kursi\n",temp[s].reguler);
		printf("\n");
	}
	fclose(concert);
	concert = fopen("listconcert.dat", "rb");
	concert2 = fopen("listconcert2.dat", "wb");
	printf("Silahkan masukkan nama concert yang akan dihapus: "); fflush (stdin); gets(dicari);
	
	while (fread(&ccr,sizeof (ccr),1, concert)==1){
		if (strcmp(ccr.namaconcert, dicari)!=0){
			fwrite(&ccr, sizeof(ccr), 1, concert2);
		}
	}
	fclose(concert);
	fclose(concert2);
	remove("listconcert.dat");
	rename("listconcert2.dat","listconcert.dat");
	printf("Berhaisl dihapus!\n");
	system("pause");
	menuadmin();
}

void listconcert1(){
	system("cls");
	int i, j, s;
	concert=fopen("listconcert.dat","rb");
	while(fread(&ccr, sizeof(ccr), 1, concert)==1){
		s=i;
		temp[s]=ccr;
		i++;
	}
	for (s=i-1;s>=1;s--)
		for (j=1;j<=s;j++)
		{
			if (temp[j-1].harga_reguler>temp[j].harga_reguler){
				temp2=temp[j-1];
				temp[j-1]=temp[j];
				temp[j]=temp2;
			}
		}
	for(s=0;s<i;s++){
		printf("%d. Nama event\t:%s\n",s, temp[s].namaconcert);
		printf("Tanggal\t\t:%s\n",temp[s].tanggal);
		printf("VVIP\t\t:%d kursi\n",temp[s].VVIP);
		printf("VIP\t\t:%d kursi\n",temp[s].VIP);
		printf("Reguler\t\t:%d kursi\n",temp[s].reguler);
		printf("\n");
	}
	fclose(concert);
	system("pause");
	menuadmin();
}

void signupuser(){
	system("cls");
	user=fopen("datauser.dat","ab");
	printf("Nama : "); gets(signup.nama);
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
			fclose(concert); 
			system("pause");
			menuuser(); 
		}
 	}
 	
	if(x!=1){
		chance--;
		printf("\nUsername atau Password salah\n");
		printf("Sisa kesempatan %d kali\n",chance);
		system("pause"); 
	
		if (chance<=0){
			printf("Kesempatan sudah habis\n");
			system("pause");
			awaluser();
		}
		signinuser();
 	}
 }


void bookingconcert(){
	int i,s;
	concert=fopen("listconcert.dat", "rb+");
	concert2=fopen("listconcert2.dat", "wb");
	saldo=fopen("info saldo.dat","rb");
	printf("Nama event yg ingin dipesan\t:");fflush(stdin); gets(nama);
	printf("Jenis seat (VVIP, VIP, Reguler)\t: "); gets(jenis);
	if (strcmp(jenis, "VVIP")==0){
		if (strcmp(ccr.namaconcert,nama)==0){
			printf("Harga VVIP: %d\n", ccr.harga_VVIP);
			while (fread(&ccr, sizeof(ccr), 1, concert)==1){
			printf("Nama Pemesan: "); gets(ccr.status);
			for(s=0; s<i; s++){
				if(strcmp(ccr.status, temp[s].status)==0){
					printf("Anda telah membooking tiket!\n");
					system("pause");
					menuuser();
				} else{
			printf("Nomor HP : "); gets(ccr.hp);
			printf("Masukkan Nominal : "); scanf("%d",&ccr.bayar);
			if(ccr.bayar==ccr.saldo || ccr.bayar>=ccr.saldo && ccr.bayar>=ccr.VVIP){
				printf("Pesanan berhasil!\n");
				ccr.VVIP=ccr.VVIP-1;
				ccr.saldo=ccr.saldo-ccr.bayar;
				strcpy(ccr.jenis, "VVIP");
				strcpy(ccr.ket, "Lunas");
				fwrite(&ccr, sizeof(ccr),1,concert2);
				fclose(concert);
	fclose(concert2);
	remove("listconcert.dat");
	rename("listconcert2.dat", "listconcert.dat");
	system("pause");
	menuuser();
			}
			else{
				printf("Pembayaran gagal, pesanan gagal");
				menuuser();
			}
					
				}
			}
			}
	}
}
		else if (strcmp(jenis, "VIP")==0){
		if (strcmp(ccr.namaconcert,nama)==0){
			printf("Harga VIP: %d\n", ccr.harga_VIP);
			while (fread(&ccr, sizeof(ccr), 1, concert)==1){
			printf("Nama Pemesan: "); gets(ccr.status);
			for(s=0; s<i; s++){
				if(strcmp(ccr.status, temp[s].status)==0){
					printf("Anda telah membooking tiket!\n");
					system("pause");
					menuuser();
				} else{
			printf("Nomor HP : "); gets(ccr.hp);
			printf("Masukkan Nominal : "); scanf("%d",&ccr.bayar);
			if(ccr.bayar==ccr.saldo || ccr.bayar>=ccr.saldo || ccr.bayar>=ccr.VVIP){
				printf("Pesanan berhasil!\n");
				ccr.VVIP=ccr.VIP-1;
				ccr.saldo=ccr.saldo-ccr.bayar;
				strcpy(ccr.jenis, "VIP");
				strcpy(ccr.ket, "Lunas");
				fwrite(&ccr, sizeof(ccr),1,concert2);
					fclose(concert);
	fclose(concert2);
	remove("listconcert.dat");
	rename("listconcert2.dat", "listconcert.dat");
	system("pause");
	menuuser();
			}
			else{
				printf("Pembayaran gagal, pesanan gagal");
				menuuser();
			}
					
				}
			}
			}
	}
}
 else if (strcmp(jenis, "Reguler")==0){
		if (strcmp(ccr.namaconcert,nama)==0){
			printf("Harga Reguler: %d\n", ccr.harga_reguler);
			while (fread(&ccr, sizeof(ccr), 1, concert)==1){
			printf("Nama Pemesan: "); gets(ccr.status);
			for(s=0; s<i; s++){
				if(strcmp(ccr.status, temp[s].status)==0){
					printf("Anda telah membooking tiket!");
					system("pause");
					menuuser();
				} else{
			printf("Nomor HP : "); gets(ccr.hp);
			printf("Masukkan Nominal : "); scanf("%d",&ccr.bayar);
			if(ccr.bayar==ccr.saldo || ccr.bayar>=ccr.saldo || ccr.bayar>=ccr.VVIP){
				printf("Pesanan berhasil!\n");
				ccr.reguler=ccr.reguler-1;
				ccr.saldo=ccr.saldo-ccr.bayar;
				strcpy(ccr.jenis, "Reguler");
				strcpy(ccr.ket, "Lunas");
				fwrite(&ccr, sizeof(ccr),1,concert2);
					fclose(concert);
	fclose(concert2);
	remove("listconcert.dat");
	rename("listconcert2.dat", "listconcert.dat");
	system("pause");
	menuuser();
			}
			else{
				printf("Pembayaran gagal, pesanan gagal");
				menuuser();
			}
					
				}
			}
			}
	}
}
	

}

void topup(){

	saldo=fopen("info saldo.dat","ab");
	printf("Saldo Anda sebesar Rp%d",ccr.saldo);
	printf("\nMasukkan nominal : "); scanf("%d",&ccr.sementara);
	ccr.saldo=ccr.saldo + ccr.sementara;
	printf("Top up berhasil, saldo Anda menjadi Rp%d\n",ccr.saldo);
	fwrite (&ccr,sizeof(ccr),1,saldo);
	system("pause");
	fclose(saldo);
	menuuser();
}

void lihattiket(){
	system("cls");

	concert=fopen("listconcert.dat","rb");
	while(fread(&ccr, sizeof(ccr), 1, concert)==1){
		if(strcmp(ccr.status, signin.uname)==0){
			printf("==================================================\n");
			printf("=================TIKET KONSER=====================\n");
			printf("==\tNama event\t:%s\t\t\t==\n",ccr.namaconcert);
			printf("==\tTanggal\t\t:%s\t\t==\n",ccr.tanggal);
			printf("==\tNama pemesan\t:%s\t\t\t==\n",ccr.status);
			printf("==\tJenis seat\t:%s\t\t\t==\n", ccr.jenis);
			printf("==\tKeterangan\t:%s\t\t\t==\n", ccr.ket);
			printf("==================================================\n");
			printf("==================================================\n");
		}
	}
	fclose(concert);
	system("pause");
	menuuser();
	}
	

void rincianconcert(){
	int s=0;
	int no_struct;
    long int offset_byte;    
	concert = fopen("listconcert.dat", "rb");
    printf("Silahkan masukkan nomor urutan: ");
    scanf("%d", &no_struct);
    	offset_byte = (no_struct-1) * sizeof(ccr);
    	fseek (concert, offset_byte, SEEK_SET);

    if (fread(&ccr, sizeof(ccr), 1, concert) == 0)
    {
        printf("event tidak ada\n");
        system("pause");
        menuuser();
    }
    else
    {
		printf("%d. Nama event\t:%s\n",s+1, ccr.namaconcert);
		printf("Tanggal\t\t:%s\n",ccr.tanggal);
		printf("VVIP\t\t:%d kursi\n",ccr.VVIP);
		printf("Harga\t\t:Rp%d\n", ccr.harga_VVIP);
		printf("VIP\t\t:%d kursi\n",ccr.VIP);
		printf("Harga\t\t:Rp%d\n", ccr.harga_VIP);
		printf("Reguler\t\t:%d kursi\n",ccr.reguler);
		printf("Harga\t\t:Rp%d\n", ccr.harga_reguler);
		printf("\n");
    }

    fclose(concert);
    system("pause");
    menuuser();
}
void cancel(){
	char y, nama[100];
	system("cls");
	concert=fopen("listconcert.dat","rb");
	while(fread(&ccr, sizeof(ccr), 1, concert)==1){
		if(strcmp(ccr.status, signin.uname)==0){
			printf("==================================================\n");
			printf("=================TIKET KONSER=====================\n");
			printf("==\tNama event\t:%s\t\t\t==\n",ccr.namaconcert);
			printf("==\tTanggal\t\t:%s\t\t==\n",ccr.tanggal);
			printf("==\tNama pemesan\t:%s\t\t\t==\n",ccr.status);
			printf("==\tJenis seat\t:%s\t\t\t==\n", ccr.jenis);
			printf("==\tKeterangan\t:%s\t\t\t==\n", ccr.ket);
			printf("==================================================\n");
			printf("==================================================\n");
		}
	}
	fclose(concert);
	printf("Batalkan pesanan (y/g)?"); scanf("%s", &y); getchar();
	if (y=='Y' || y=='y'){
	concert=fopen("listconcert.dat", "rb+");
	concert2=fopen("listconcert2.dat", "wb");
	while (fread(&ccr,sizeof(ccr),1,concert)==1){
		printf("Nama pemesan: "); gets(nama);
		if (strcmp(ccr.status, nama)==0){
			strcpy(ccr.ket, "Batal");
			strcpy(ccr.status, " ");
			if(strcmp(ccr.jenis, "VVIP")==0){
				ccr.VVIP=ccr.VVIP+1;
			}
			else if(strcmp(ccr.jenis, "VIP")==0){
				ccr.VVIP=ccr.VIP+1;
			}else if (strcmp(ccr.jenis, "Reguler")==0){
				ccr.reguler=ccr.reguler+1;
			}
			fwrite(&ccr, sizeof(ccr),1,concert2);
			
		}
			else {
			fwrite(&ccr, sizeof(ccr),1,concert2);
			}
		}
	fclose(concert);
	fclose(concert2);
	remove("listconcert.dat");
	rename("listconcert2.dat", "listconcert.dat");
} else{
	menuuser();
}
	printf("Pesanan berhasil dibatalkan!\n");
	system("pause");
	menuuser();
}


