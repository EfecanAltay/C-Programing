#include<stdio.h>

class yigin{
private :
int arka,veri,*dizi,boyut; 
public : 
yigin(int);
void ekle(int);
int say();
void listele();
void getir();
};

yigin::yigin(int boy)
{
	this-> arka =0;
	this-> boyut = boy ;
	dizi = new int [boy];
}

void yigin::ekle(int boy){
	if(arka == boyut)
			printf("yiginda yeterli alana yoktur...");
	else{
		dizi[arka] = boy ;
		arka = arka+ 1 ;
	}
}

int yigin::say()
{
	return arka ;
}
void yigin::getir(){
	if(arka == 0 )
	printf("yiginda eleman yoktur");
	else
	{
		printf("ilk eleman : %d",dizi[arka-1]);
	}
}
void yigin::listele()
{
	if(arka == 0)
	printf("yigin bos..");
	else{
		int i ;
		for(i=0;i<arka;i++){
			printf("%d. eleman %d\n",i+1,dizi[i]);
		}
	}
}
main(){
	char y ;
	int boy,a ;
	printf("kuyrugun boyutunu giriniz :");
	scanf("%d",&boy);
	yigin b(boy);
	
	while(1){
		printf("\nEkle -->E\nSay -->S\nGetir -->G\nListele -->L\nCikis -->C\n");
		scanf("%s",&y);
		if(y == 'C')break ;
		switch(y){
			case 'E':
			printf("Eklemek istediginiz sayiyi giriniz :");
			scanf("%d",&a);
			b.ekle(a); 
			 break ;
			case 'S':
				printf("Kuyrugun boyu --> %d",b.say()); 
			 break ;
			case 'G':
				b.getir();
				//...
			 break ;
			case 'L':
				b.listele();
				//... 
			 break ;
			default : 
			 break ;
			 
		}
		
	}
}


