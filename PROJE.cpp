#include<stdio.h>
#include<string.h>		//strcmp fonksiyonu için
#include<conio.h>
#include<stdlib.h>
	struct kayit
	{	char ad[15]; 
	 	char soyad[15]; 
		char evTel[15]; 
		char cepTel[15]; 
		char isTel[15]; 
	 	char dogumTarihi[15];  
 		char ePosta[50];
		char il[20];
		char ilce[20];
		char mahalle[20];
		int sokak[20];
	}kisi;
	int N;
	FILE *dd;
	FILE *guncel;
	FILE *yeni_dd;
	void oku();
	void kisiEkle();
	void kisiGoruntule();
	void guncelle();
	void sil();
	void arama();
	void menu();
	
main()
{
	system("color FC");
	int i;
	menu();
}
void kisiEkle()
{
	char secim;
	printf("Ismi giriniz:");
		scanf("%s",&kisi.ad);
	printf("Soyadini giriniz:");
		scanf("%s",&kisi.soyad);
	printf("Ev telefonunu giriniz:");
		scanf("%s",&kisi.evTel);
	printf("Cep telefonunu giriniz:");
		scanf("%s",&kisi.cepTel);
	printf("Is telefonunu giriniz:");
		scanf("%s",&kisi.isTel);
	printf("E-postayi giriniz:");
		scanf("%s",&kisi.ePosta);
	printf("Dogum gununu giriniz:");
		scanf("%s",&kisi.dogumTarihi);
	printf("Ikamet ettigi sehri giriniz:");
		scanf("%s",&kisi.il);
	printf("Ikamet ettigi ilceyi giriniz:");
		scanf("%s",&kisi.ilce);	
	printf("Ikamet ettigi mahalleyi giriniz:");
		scanf("%s",&kisi.mahalle);
	printf("Ikamet ettigi sokagi giriniz:");
		scanf("%s",&kisi.sokak);
	dd = fopen("D:/proje.txt","a");	
	fprintf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
	fclose(dd);
	printf("Kisi basariyla eklendi..Baska bir islem yapmak istiyor musunuz?\n\a");
	printf("Yeni kisi eklemek icin ->(e/E), menuye donmek icin ->(m/M), cikis icin ->ESC\n");
	secim = getch();
		if(secim=='e'||secim=='E')
	kisiEkle();
		else if(secim == char(27))
	exit(0);
		else if(secim=='m'||secim=='M')
	menu();
		else
	printf("**Hatali tuslama yaptiniz!!**\a");
}
void kisiGoruntule()
{
	char tus;
	dd = fopen("D:/proje.txt","r");
	if(dd==NULL)
	{
		printf("**Rehberinizde kayitli kisi yoktur!!**\n\a");
		printf("Kisi eklemek icin->(e/E), menuye donmek icin ->(m/M\n");
		tus = getch();
		if(tus=='e'|| tus=='E')
			kisiEkle();
		if(tus=='m'|| tus=='M')
			menu();
	
	}
	else if(dd != NULL)
	{
	printf("Rehberinizdeki kisiler\n");
	printf("AD\tSOYAD\tEV TELEFONU\tCEP TELEFONU\tIS TELEFONU\tDOGUM TARIHI\tE-POSTA\t\t\t\tIL\tILCE\t\tMAHALLE\t\tSOKAK\n");
	printf("=======================================================================================================================================================\n");
	while(!feof(dd))
	{
		fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.dogumTarihi,kisi.ePosta,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.dogumTarihi,kisi.ePosta,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
	}
	fclose(dd);
	printf("Baska bir islem yapmak istiyor musunuz?\nMenuye donmek icin ->(m/M), cikis icin ->(ESC)\n");
	tus = getch();
		if(tus=='m'||tus=='M')
		{
			menu();
		}
		else if(tus == char(27))
			exit(0);
		else
		{
			printf("**Hatali tuslama yaptiniz! Menuye geri donuluyor..**\n\a");
			menu();
		}
	}
}

void guncelle()
{
	char guncelAd[15],tus,kontrol=0;
	dd = fopen("D:/proje.txt","r");
	guncel = fopen("D:/guncel.txt","w");
	if(dd==NULL)
		printf("**Rehberinizde kayitli kisi yoktur!!**\a");
	else
	{
		printf("Guncellemek istediginiz kisinin ismini giriniz:");
		scanf("%s",guncelAd);
		rewind(dd);
		rewind(guncel);
		while(!feof(dd))
			{
			fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
				if( strcmp(kisi.ad,guncelAd)==0 )
				{
					kontrol=1;
					printf("Guncel ad:");
						scanf("%s",&kisi.ad);
					printf("Guncel soyad:");
						scanf("%s",&kisi.soyad);
					printf("Guncel ev telefonu:");
						scanf("%s",&kisi.evTel);
					printf("Guncel cep telefonu:");
						scanf("%s",&kisi.cepTel);
					printf("Guncel is telefonu:");
						scanf("%s",&kisi.isTel);
					printf("Guncel e-posta:");
						scanf("%s",&kisi.ePosta);
					printf("Guncel dogum tarihi:");
						scanf("%s",&kisi.dogumTarihi);
					printf("Guncel il:");
						scanf("%s",&kisi.il);
					printf("Guncel ilce:");
						scanf("%s",&kisi.ilce);
					printf("Guncel mahalle:");
						scanf("%s",&kisi.mahalle);
					printf("Guncel sokak:");
						scanf("%s",&kisi.sokak);
					fprintf(guncel,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					printf("**KISI GUNCELLENDI**\n");
					printf("AD\tSOYAD\tEV TELEFONU\tCEP TELEFONU\tIS TELEFONU\tDOGUM TARIHI\tE-POSTA\t\tIL\t\tILCE\tMAHALLE\tSOKAK\n");
					printf("==================================================================================================================================\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					printf("Baska bir islem yapmak istiyor musunuz?\nMenuye donmek icin ->(m/M), cikis icin ->(ESC)\n");
					tus=getch();
					if(tus=='m'||tus=='M')
					menu();
					if(tus == char(27))
					exit(0);
						fclose(dd);
						fclose(guncel);
						remove("D:/proje.txt");
						rename("D:/guncel.txt","D:/proje.txt");
				}
				if(strcmp(kisi.ad,guncelAd)!=0)
				{
					printf("**Rehberinizde boyle bir kisi bulunmamaktadir..**\n\a");
					fprintf(guncel,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					fclose(dd);
					fclose(guncel);
					remove("D:/proje.txt");
					rename("D:/guncel.txt","D:/proje.txt");
				}
		}
	
		if(kontrol==0)
			printf("Bu kisi rehberde kayitli degildir...\n");
	}
}
void sil()
{
	int sayac = 0;
	char isimSil[20],devam,tus;
	dd = fopen("d://proje.txt","r");
	yeni_dd = fopen("d://yeniDosya.txt","w");
	
	if(dd == NULL)
		printf("**Rehberinizde kayitli kisi yoktur!!**\a");
	else
	{	
		printf("Silmek istediginiz kisinin ismini giriniz:");
		scanf("%s",isimSil);
		printf("Bu kisiyi silmek istediginize emin misiniz?\n\a");
		printf("Silmek icin ->(e/E), menuye donmek icin ->(m/M)\n");
		tus=getch();
	if(tus=='e'||tus=='E')
	{			
		while(!feof(dd))
		{
			fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
			if( ( strcmp(kisi.ad, isimSil ) == 0 ) && (tus == 'e' || tus == 'E'))
			{
				sayac++;
				printf("**KISI SILINDI**\n\a");
				printf("Baska bir islem yapmak istiyor musunuz?\nMenuye donmek icin ->(m/M), cikis icin ->(ESC)\n");
				tus = getch();
			}
			else if(strcmp(kisi.ad,isimSil) != 0 || sayac > 0)
			{
				fprintf(yeni_dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
			}
		}
		if(sayac == 0)
		{
			printf("%s isimli kisi rehberde bulunamadi!!\n", isimSil);
		}
		
		if(tus=='m'||tus=='M')
		{
			fclose(dd);
			fclose(yeni_dd);
			remove("D:/proje.txt");
			rename("D:/yeniDosya.txt","D:/proje.txt");
			menu();
		}
		else if(tus == char(27)) {
			fclose(dd);
			fclose(yeni_dd);
			remove("D:/proje.txt");
			rename("D:/yeniDosya.txt","D:/proje.txt");
			exit(0);
		}
		else
		{
			fclose(dd);
			fclose(yeni_dd);
			remove("D:/proje.txt");
			rename("D:/yeniDosya.txt","D:/proje.txt");
			printf("**Hatali tuslama yaptiniz! Menuye geri donuluyor..**\n\a");
			menu();
		}
	}
}
}
void arama()
{
	int sayac=0,i=0;
	char arananAd[15], arananSoyad[15], arananTarih[15],tus;
	dd = fopen("d://proje.txt","r");
	if(dd==NULL)
		printf("**Rehberinizde kayitli kisi yoktur!!**\a");
	else
	{
		rewind(dd);		
		printf("Isme gore arama yapmak icin ->(i/I)\nSoyadina gore arama yapmak icin ->(s/S)\nDogum tarihine gore arama yapmak icin ->(d/D)\n");
		tus = getch();
		if(tus=='i'||tus=='I')
		{
			printf("Aramak istediginiz kisinin adini giriniz:");	
			scanf("%s",&arananAd);
			while(!feof(dd))
			{
			fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
				if( strcmp(kisi.ad,arananAd)==0 )
				{
					printf("**Aradiginiz kisi bulundu**\n\a");
					printf("AD\tSOYAD\tEV TELEFONU\tCEP TELEFONU\tIS TELEFONU\tDOGUM TARIHI\tE-POSTA\t\tIL\t\tILCE\tMAHALLE\tSOKAK\n");
					printf("==================================================================================================================================\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",arananAd,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					printf("Baka bir islem yapmak istiyor musunuz? Menuye donmek icin ->(m/M), cikis icin ->(ESC)\n");
					tus = getch();
					if(tus=='m'|| tus=='M')
						menu();
					else if(tus == char(27))
						exit(0);
					else
					printf("**Hatali tuslama yaptiniz**\n\a");	
				}
			}
		}
		else if(tus=='s'||tus=='S')
		{
			printf("Aramak istediginiz kisinin soyadini giriniz:");
			scanf("%s",&arananSoyad);
			while(!feof(dd))
			{
				fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					if( strcmp(kisi.soyad,arananSoyad)==0 )
				{
					printf("**Aradiginiz kisi bulundu**\n\a");
					printf("AD\tSOYAD\tEV TELEFONU\tCEP TELEFONU\tIS TELEFONU\tDOGUM TARIHI\tE-POSTA\t\tIL\t\tILCE\tMAHALLE\tSOKAK\n");
					printf("==================================================================================================================================\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,arananSoyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					printf("Baka bir islem yapmak istiyor musunuz? Menuye donmek icin ->(m/M), cikis icin ->(ESC)\n");
					tus = getch();
					if(tus=='m'|| tus=='M')
						menu();
					else if(tus == char(27))
						exit(0);
					else
					printf("**Hatali tuslama yaptiniz**\n\a");	
				}
			}
		}	
		else if(tus=='d'||tus=='D')
		{
			printf("Aramak istediginiz kisinin dogum gununu giriniz:");
			scanf("%s",&arananTarih);
			while(!feof(dd))
			{
				fscanf(dd,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					if( strcmp(kisi.dogumTarihi,arananTarih)==0 )
				{	
					printf("**Aradiginiz kisi bulundu**\n\a");
					printf("AD\tSOYAD\tEV TELEFONU\tCEP TELEFONU\tIS TELEFONU\tDOGUM TARIHI\tE-POSTA\t\tIL\t\tILCE\tMAHALLE\tSOKAK\n");
					printf("==================================================================================================================================\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,arananTarih,kisi.il,kisi.ilce,kisi.mahalle,kisi.sokak);
					printf("Baka bir islem yapmak istiyor musunuz? Menuye donmek icin ->(m/M), cikis icin ->(ESC)\n");
					tus = getch();
					if(tus=='m'|| tus=='M')
						menu();
					else if(tus == char(27))
						exit(0);
					else
					printf("**Hatali tuslama yaptiniz**\n\a");	
				}
            } 
		}
		else
		{
			printf("**Hatali bir tuslama yaptiniz!! Menuye geri donuluyor..\a");
			main();
		}
	}
}
void menu()
{
	system("cls");
	int tus=0;
	printf("MENU\n");
	printf("|=======================|\n");
	printf("|Rehberi goruntule  >(1)|\n");
	printf("|Kisi ekleme	    >(2)|\n");
	printf("|Rehberi guncelleme >(3)|\n");
	printf("|Kisi silme\t    >(4)|\n");
	printf("|Arama yap\t    >(5)|\n");
	printf("|Cikis icin\t    >ESC|\n");
	printf("|=======================|\n");

	printf("Tercihinizi giriniz(1/2/3/4/5):");
	scanf("%d",&tus);
	if(tus==1)
	kisiGoruntule();
	else if(tus==2){
		kisiEkle();
	}
 	
	else if(tus==3)
	guncelle();
	else if(tus==4)
	sil();
	else if(tus==5)
	arama();
	else if(tus==char(27))
	exit(0);
	else
	printf("**Menu secenekleri disinda bir tuslama yaptiniz!!\a**");

}


