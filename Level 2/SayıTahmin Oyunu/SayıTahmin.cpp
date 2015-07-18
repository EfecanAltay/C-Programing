#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


int puan1=0 ;
int puan2=0 ;


int sayiGir(){                // Kullanicidan aldigimiz sayifonk.nu
	int sayi ;
	printf("Tahminin :");
	scanf("%d",&sayi); 
	return sayi ;	
}


int sonuc(int tahmin,int a,int b,int c){    //puan degerlerinin hesaplanan fonksiyonu
	int x=(tahmin%10),y=(tahmin%100-x),z=(tahmin%1000-(y+x));  // tahmin sayisini x,y,z rakamlara parcaladik
	y = y/10;
	z = z/100;
//	printf("%d,%d,%d\n",z,y,x); //parcalanan rakamlari gormek icin bu kod satirini calistir
	if(x == c){
		puan1 ++;
	}
	else if(x == b || x == a){	
		puan2 ++;
	}
	
	if(y == b){
		puan1 ++;
	}
	else if(y == a || y == c){	
		puan2 ++;
	}
	
	if(z == a){
		puan1 ++;
	}
	else if(z == b || z == c){	
		puan2 ++;
	}
	printf("Sonuc:  +%d -%d \n",puan1,puan2);
	if(puan1 == 3)return 1;
	else return 0 ;

}



main(){
srand(time(NULL));
	int a,b,c,giris;
	a = rand()%9+1;     // %9 mod almamizin ve 1 arttirmamizin nedeni 0 olmamasi 1 ile 9 arasinda alinir

	while(1){
	b = rand()%10;      // b ondalik rakam olduðundan 0 da olabilir
	if(b != a )break ;
	}	

	while(1){
	c = rand()%10;        // c de birler basamagidir
	if( c !=a || c != b)break; 	
	}

printf("3 basamakli rakamlari farkli bir sayi giriniz  :\n");
while (1){
//printf("%d\n",(a*100)+(b*10)+c);           //Random olarak tutulan sayiyi yazdrdk eger dogru yaptgni gormek icin bu satiri calistir 	
puan1 = 0 ;
puan2 = 0 ;
if(sonuc(sayiGir(),a,b,c)){
break ;    //Tahmin dogru ise sonuc fonknun 1 olmasi durumu while dan cikilir ;
}
printf("\n");
}


printf("%cDogru sonucu buldunuz tebrikler%c",1,1);
	getch();
	return 0;
}


