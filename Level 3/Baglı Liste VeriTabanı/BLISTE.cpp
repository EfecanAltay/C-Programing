#include<stdio.h>			///Pazar		Baslangic 22:33 || Kapanisýþ 2:55   	Efecan Altay 
#include<conio.h>			///-Bagliý liste oluþturuldu-Ekleme ve çýkarma islemleri yapildý-dusuk not arama yapildiý silmede hata oluþtu
#include<stdlib.h>			///Pazartesi	Baslangicý18:21 || Kapanis 20:45ýþ      
#include<windows.h>			///-Silme sorunlarý giderildi.
							///-Persembe Dosya islemleri halledildi,Hatalar giderildi.Odev tamamlandi.
							
							 ///Odevin icinde olmayan sorunlar__
							 ///Sorun 1 Dosya.txt bosþ iken programin kayit olusturmasi,
							 ///Sorun 2 Update sonucu 1 satir kaydirmasi.
							
int secim = 0;

/// Bagli Listemiz...Benim Listem Tek yonludur.

typedef struct BLISTE
{
	int id = NULL ;     /// Odeve ek olarak id ekledim.
	int numara = NULL;  /// numara da primary key olaraka islev yapmaktadir.(Tekrar etmemesi saglandi) 
	char isim[15];
	char soyisim[15];
	float puan;
	BLISTE *last = NULL ; 
};


BLISTE  listeBasi;    /// ListeBasi degiskeni adresini asla unutmayacagimiz listenin basidir. 


///fonk bildirimleri

BLISTE  * VeriEkle(BLISTE *, int ,char *, char *, float);//
void VeriSil();											
BLISTE * ara(BLISTE *);
int kullaniciGiris();
void bilgileriGir();
void kullaniciVeriEkle();
void kullaniciVeriListele(BLISTE *);                       
int numaraKontrol(int);
int DosyadanOku();
BLISTE  stringBol(char[]);
void DosyayaEkle(BLISTE *);
void DosyaUpdate();
void DosyayaYaz();





main(){									// Ana fonk.
	DosyadanOku();
	while (1){
		secim = kullaniciGiris();
		switch (secim)
		{
		case 1:
			kullaniciVeriListele(&listeBasi);
			break;
		case 2:
			kullaniciVeriEkle();
			break;
		case 3:
			VeriSil();
			_getch();
			break;
		default:
			break;
		}
	}
	_getch();
	return 0 ;
}
///veri ekleme islemlerinin saglandigi fonk.
BLISTE  * VeriEkle(BLISTE  *listebasi ,int numara, char  isim[15] ,char soyisim[15] ,float puan){
	BLISTE * gecici;
	gecici = listebasi;
	BLISTE * liste  = (BLISTE *) malloc(sizeof(BLISTE));
	strcpy(liste->isim, isim);
	strcpy(liste->soyisim, soyisim);
	liste->puan = puan;
	liste->numara = numara;
	liste->last = NULL;

	while (1)
	{
		if (gecici->last != NULL){
			gecici = gecici->last;
			gecici->id = gecici->id;
		}
		else{
			if (gecici->isim[0] == NULL){
				listeBasi =  * liste;
				listeBasi.id = 0;
			}
			else{
				liste->id = gecici->id + 1;
				gecici->last = liste;
			}
			return liste ;
			break;
		}
	}
}

///Veri silme islemlerinin saglandigi Fonk.
void VeriSil(){
	BLISTE * kisi;
	BLISTE * gecici;
	gecici = &listeBasi;
	kisi = ara(&listeBasi);
	if (kisi == NULL){
		printf("Ogrenci bulunamadi !!!");
		return;
	}
	else
	{
		while (1){
			if (gecici->last != NULL){
				if (gecici == kisi)
				{
					listeBasi = *(gecici->last);
					printf("\nSilme basarili :) ");
					printf("%s ogrencisi Silindi\n",kisi->isim);
					DosyaUpdate();
					return;
				}
				if (gecici->last == kisi){
					gecici->last = kisi->last;
					printf("\nSilme basarili :) ");
					printf("%s ogrencisi Silindi\n",kisi->isim);
					DosyaUpdate();
					return;

				}
				else
				{
					gecici = gecici->last;
				}
			}
			else{
				gecici->isim[0] = NULL;
				gecici->soyisim[0] = NULL;
				gecici->puan = NULL;
				printf("%s ogrencisi Silindi\n",kisi->isim);
				printf("\nSilme basarili :) ");
				DosyaUpdate();
				return;
			}

		}
	}

}

///En kucuk BLISTE elemanini bulup adresini donduren fonk
BLISTE * ara(BLISTE  *listeBasi){
	float puan ;
	BLISTE *gecici;
	gecici = listeBasi;
	puan  = listeBasi->puan;
	BLISTE * donen;
	donen = gecici;

	while (1)
	{
		if (gecici->last != NULL)
		{
			gecici = gecici->last;
			printf("\ngecici not %f  not : %f ", gecici->puan,puan);
			Sleep(1000);
			if (gecici->puan < puan){
				donen  = gecici;
				puan = gecici->puan;
			}
		}
		else{
			if (gecici->puan < puan){
				donen = gecici;
			}
			return donen;
		}
		
	}
	
}

/// kullanici girisi switch yapisiyla saglandi.
int  kullaniciGiris(){
	system("cls");
	int secim = 0;
	while(secim == 0){
		printf("::::Lutfen Bir islem seciniz::::::\n\n");
		printf("   1.kayit.............Listele\n");
		printf("   2.kayit................ekle\n");
		printf("   3.kayit.................sil\n");
		printf("   4...Programi.Sonlandir....4\n");
		printf("Seciminizi Giriniz : ");
		scanf("%d", &secim);
		//system("cls");
		switch (secim){
		case 1:
			printf("\n  Kaydiniz listeleniyor %c\n\tLutfen Bekleyiniz...",2);
			break;
		case 2:
			printf("\n  Isleminiz secildi %c \n\tLutfen Bekleyiniz...",2);
			break;
		case 3:
			printf("\n  Isleminiz secildi %c\n\tLutfen Bekleyiniz...",2);
			break;
		case 4 : 
				system("cls");
				puts("Hoscakalinnnn....");
				Sleep(1000);
					printf("Bye ");
				Sleep(1000);
					printf("%c", 1);
				Sleep(1000);

				exit(1);
			
			break;
		case 5 :
			DosyayaEkle(&listeBasi);
			break ;
		default:
			printf("\n   Yanlis islem \n \tLütfen Bekleyin!!!!");
			secim = 0;
			Sleep(2500);
			system("cls");
			break;
		}
	}
	for (int i = 3; i < 6; i++)
	{
		if (i%2 == 0 )
		printf("%c",2);
		else
		printf("%c", 1);
		Sleep(1000);
	}
	system("cls");
	return secim;
	
}

///kullanicidan Bilgileri cekmek icin kullanilan fonk..
void kullaniciVeriEkle(){
	char Oad[15] , OSad[15] ;
	int Ono = 0;
	float puan;
	while (1){
		printf("Ogrenci Numarasisi giriniz :");
		scanf("%d",&Ono);
		
		if (numaraKontrol(Ono))
			break;
		else
		{
			printf("Numaraya sahip baska ogrenci bulunmaktadýr!!!\nLutfen Farklý Bir numara giriniz...");
			Sleep(3000);
			system("cls");
		}
	}
	printf("Ogrenci Adini giriniz :");
	gets(Oad);
	gets(Oad);   //Çözemediðim bir Sistem çalýþmasýndan dolayý hata sebebiyle tekrar aldým
	while (1){
		if (Oad[0] != NULL)	//programým listebaþý elemanýnýn boþ kayýt olduðunu isim[0] karakterinin null olup olmadýðýna göre anlýyor. 
			break;			//bu yüzden deneteyip while kullandýk.
		else
		{
			printf("Isim Null birakilmaz !!!\n");
			printf("Ogrenci Adini giriniz :");
			gets(Oad);
		}
	}
	printf("Ogrenci Soyadini giriniz :");
	gets
	(OSad);
	printf("Ogrenci Notunu giriniz :");
	scanf("%f", &puan);
	DosyayaEkle(VeriEkle(&listeBasi, Ono,Oad, OSad, puan));
	printf("%c%c%c Kayit Basarili %c%c%c ",177,177,177,177,177,177);
	_getch();
}
/// Veri listeleme islevi fonk...
void kullaniciVeriListele(BLISTE * listebasi){
	printf("%c%c%c Kayitli Ogrenci Listesi %c%c%c\n", 177, 177, 177, 177, 177, 177);
	printf("ID No Ad # Soyad # not  ");
	printf("\n-------------------------------");
	BLISTE * gecici;
	gecici = listebasi;
	if (gecici->last == NULL && gecici->isim[0] == NULL){
	printf("\n\tListe bos");
	printf("\n-------------------------------");
	_getch();
	return;
	}
	while (1){
		if (&gecici != NULL){
			printf("\n%d %d %s %s %f", gecici->id, gecici->numara, gecici->isim, gecici->soyisim, gecici->puan);
			printf("\n-------------------------------");
			if (gecici->last != NULL)
				gecici = gecici->last;
			else
				break;
		}
		else break;
	}
	printf("\n-------------------------------");
	_getch();
}

/// Numara kontrol girilen ogrenci numarasinin birdaha girilmemesini saglar.
int numaraKontrol(int numara){
	BLISTE * gecici;
	gecici = &listeBasi;
	while (1){
		if (gecici->numara == numara)
			return 0;
		if (gecici->last != NULL)
			gecici = gecici->last;
		else{
			return 1;
		}
	}
}

/// Dosyadan verilerin okunma islev fonk.
int DosyadanOku(){
	printf("Veriler yukleniyor Lutfen Bekleyin...\n");
	Sleep(1500);	
	int id ,no ;
	char  okunan[20];
	FILE *ptr;
	BLISTE gecici ;
	
	ptr = fopen("dosya.txt","r");
	if(ptr == NULL)
		{
			puts("Dosya Okuma hatasi!!\nLutfen Exe konumunda Dosya.txt dosyasinin olup olmadigini kontrol ediniz.");
			getch();
			return 0 ;
		}
	while(!feof(ptr)){
		fscanf(ptr,"%d %d %s",&id,&no,okunan);
		//printf("%d %d %s\n",id,no,okunan);
		
		gecici = stringBol(okunan);
		VeriEkle(&listeBasi,no,gecici.isim,gecici.soyisim,gecici.puan);
	}
	printf("------------------------------------\n");
	printf("Dosyadan Yukleme basarili =)\n");
	printf("------------------------------------\n");
	printf("Devam icin bir tusa basiniz...");
	getch();
	system("cls");
	printf("Menu aciliyor...");
	Sleep(3000);
	fclose(ptr);
}

/// Okunan veriyi # karakterlerine bolerek BLISTE paketinde Dosyadan oku fonk.da kullanilan fonk.
BLISTE  stringBol(char * a){
	char Bisim[15];
	char BSisim[15];
	char Bpuan[3] ;
	BLISTE gecici ;
	int i,j=0;
	for(i= 0 ;i < 20  ; i++)
	{
		if(a[i] == '#')
			break;
		Bisim[j] = a[i];	
		j++ ;
	}
	i++;
	j=0 ;
	for(;i < 20  ; i++)
	{
		if(a[i] == '#')
			break;
		BSisim[j] = a[i];
		j++ ;
	}
	i++;
	j=0 ;
	for(;i <20  ; i++)
	{
		Bpuan[j] = a[i];
		j++ ;
	}
	strcpy(gecici.isim,Bisim);
	strcpy(gecici.soyisim,BSisim);
	
	gecici.puan = strtof(Bpuan,NULL);
	
	printf("Dosyadan %s Ogrencisi Yuklendi...\n",gecici.isim );
	Sleep(1500);
	return gecici ;
}
///Programimiza ekledigimiz BLISTE Elemanlarini Dosyaya Satir Satir eklemek icin kullanilan fonk. 
void DosyayaEkle(BLISTE * liste){
	FILE * ptr ;
	ptr = fopen("dosya.txt","a");
	if(ptr == NULL ){
		printf("Dosya yazma hatasi!!!");
		getch();
	}
	fprintf(ptr,"\n%d %d %s#%s#%3.1f",liste->id,liste->numara,liste->isim,liste->soyisim,liste->puan);
	fclose(ptr);
	
}
///BListe elemanlarinin silinmesi sirasinda dosyanin tamamen silinip tekrar BLISTE elemanlarinin yazilma islemi 
void DosyaUpdate(){
	FILE * ptr ;
	ptr = fopen("dosya.txt","w");
	fprintf(ptr,"",NULL);
	DosyayaYaz();
	printf("Dosya Guncellendi =)\n\n\tDevam icin Bir tusa basiniz...");
	
}

///Bos dosyaya yazmak icin olusturdum.Dosya updatede kullanmak icin
///bagliListemizdeki Tum elemanlari teker teker dosyaya yaziyor... 
void DosyayaYaz(){
	BLISTE * gecici ;
	gecici = &listeBasi ;
	while(1){
		
		if(gecici->last != NULL )
		{
		DosyayaEkle(gecici);
		gecici = gecici->last ;
		
		}
		else{
			DosyayaEkle(gecici);
			return;
		}
	}
	

}









