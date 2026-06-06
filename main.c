#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int id;
char ad[50];
float fiyat;
int stok;
}urun;

void urunekle(int *n,urun u[]);
void listele(int n,urun u[n]);
void varmi(int n,urun u[n]);
void urunsil(int *n,urun[]);
void guncelle(int n,urun u[n]);
void dosyayakaydet(int n,urun u[n]);
void dosyadanoku();

int main()
{
int n=0;
urun u[100];
int secim=-1;

while(secim!=0){
printf("\n----URUN MENUSU----\n");
printf("0-cikis\n");
printf("1-urun ekleme\n");
printf("2-listeleme\n");
printf("3-urun kontrolu\n");
printf("4-urun silme\n");
printf("5-stok guncelleme\n");
printf("6-dosyaya kaydetme\n");
printf("7-dosyadan okuma\n");
printf("lutfen 0-7 arasindan sayi seciniz: ");
scanf("%d",&secim);

switch(secim){
case 0: printf("\nprogramdan cikis yapiliyor...\n");
break;

case 1: urunekle(&n,u);
break;

case 2: listele(n,u);
break;

case 3: varmi(n,u);
break;

case 4: urunsil(&n,u);
break;

case 5: guncelle(n,u);
break;

case 6: dosyayakaydet(n,u);
break;

case 7: dosyadanoku();
break;

default : printf("\nhatali sayi girdiniz!!!\n");
break;
}
}

    return 0;
}

void urunekle(int *n,urun u[]){
int i;
if(*n>100){
printf("urun limiti dolu!!!\n");
}
else{

printf("\nurunun ID bilgisini giriniz: ");
scanf("%d",&u[*n].id);
getchar();

printf("urunun ismini giriniz: ");
fgets(u[*n].ad,sizeof(u[*n].ad),stdin);
u[*n].ad[strcspn(u[*n].ad,"\n")]=0;

printf("urunun fiyatini giriniz: ");
scanf("%f",&u[*n].fiyat);

printf("urunun stok miktarini giriniz: ");
scanf("%d",&u[*n].stok);

(*n)++;
}
}

void listele(int n,urun u[n]){
int i;
printf("\n----MARKET STOK TAKIBI----\n");
for(i=0;i<n;i++){
printf("urun ID:%d\n",u[i].id);
printf("urun ad:%s\n",u[i].ad);
printf("urun  fiyati:%.1f\n",u[i].fiyat);
printf("urun stok adeti:%d\n",u[i].stok);
}
}

void varmi(int n,urun u[n]){
int i;
int aranacak,bulundu=0;
printf("aramak istediginiz urunun id bilgisini giriniz: ");
scanf("%d",&aranacak);

for(i=0;i<n;i++){
if(u[i].id==aranacak){
printf("\n--URUN BILGILERI--\n");
printf("urun adi:%s\n",u[i].ad);
printf("urun id'si:%d\n",u[i].id);
printf("urun fiyati:%.1f\n",u[i].fiyat);
printf("urunun stok miktari:%d\n",u[i].stok);
bulundu=1;
}
}
if(bulundu==0){
printf("\naranan urun bulunamadi\n");
}
}

void urunsil(int *n,urun u[]){
int silinecek,i,j;

printf("\nsilmek istediginiz urunun id bilgisini giriniz: ");
scanf("%d",&silinecek);

for(i=0;i<(*n);i++){
if(u[i].id==silinecek){
printf("\nSILINECEK URUNUN BILGILERI\n");
printf("urun adi:%s\n",u[i].ad);
printf("urun id'si:%d\n",u[i].id);
printf("urun fiyati:%.1f\n",u[i].fiyat);
printf("urunun stok miktari:%d\n",u[i].stok);

for(j=i;j<(*n)-1;j++){
u[j]=u[j+1];
}
(*n)--;
return;
}
}
}


void guncelle(int n,urun u[n]){
int i;
int guncellenecek,yenistok,bulundu=0;
printf("\nguncellemek istedgin urunun ID'sini gir: ");
scanf("%d",&guncellenecek);

for(i=0;i<n;i++){
if(u[i].id==guncellenecek){
printf("yeni stok adeti giriniz: ");
scanf("%d",&yenistok);
u[i].stok=yenistok;

printf("\nurunun guncel stok adeti:%d\n",yenistok);
bulundu=1;
break;
}
}
if(bulundu==0){
printf("\nurun bulunamadi\n");
}
}

void dosyayakaydet(int n, urun u[n]){
int i;
FILE *dosya;
dosya=fopen("proje.txt","w");
if(dosya==NULL){
printf("dosya acilamadi");
return;
}

fprintf(dosya,"\n---URUN BILGILERI---\n");
for(i=0;i<n;i++){
fprintf(dosya,"\nurun adi:%s\n",u[i].ad);
fprintf(dosya,"urun id'si:%d\n",u[i].id);
fprintf(dosya,"urun fiyati:%.1f\n",u[i].fiyat);
fprintf(dosya,"urunun stok miktari:%d\n",u[i].stok);
}
fclose(dosya);
}

void dosyadanoku(){
FILE *dosya;
dosya=fopen("proje.txt","r");
if(dosya==NULL){
printf("dosya acilamadi");
return;
}
char metin[200];
while(fgets(metin,sizeof(metin),dosya)!=NULL){
printf("%s",metin);
}
fclose(dosya);
}


