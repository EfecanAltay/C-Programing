#include<stdio.h>
#include<conio.h>
int main(){
int degisik[10];

for(int i=0;i<10;i++){
	printf("%d. elemaný gir : ",i);
	scanf("%d",&degisik[i]);
}
for(int i=0;i<10;i++){
printf("%d\n",degisik[i]);
}
getch();
return 0;
}


