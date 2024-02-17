#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <string.h>

int toplamalan=0;
void kaynakrezerv_hesapla(int toplamalan)
{
	float yuzeyalani;
	
   	yuzeyalani=toplamalan*10;

	printf("\nCizdilerin seklin kaynak rezerv degeri :%.1f\n",yuzeyalani);
	
}
void alan_bul(int alan_dizi[50],int sayac)
{
	int degisim_X[20];
	int degisim_Y[20];
	
	if(sayac==3)// dortgen icin
	{
		
		int boyut = sayac*2+4;
		for(int i=0;i<boyut;i++)
		{
			alan_dizi[i]=alan_dizi[i]/15;
		}
		

		for(int i=0, j=0; i<boyut/2-1 ,j<boyut/2-1;i+=2,j++)
		{
			degisim_X[j]=alan_dizi[i]-alan_dizi[i+2];
			degisim_Y[j]=alan_dizi[i+1]+alan_dizi[i+3];
		}
		int alan[boyut];
		int alan_toplam=0;
		for(int i=0;i<boyut/2-1;i++)
		{
			alan[i]=degisim_X[i]*degisim_Y[i];
			alan_toplam+=alan[i];
		}
		printf("Seklin alani:%d",alan_toplam/2);
		
		toplamalan+=alan_toplam;

		
    }
    
	
    if(sayac==2) // ucgen icin
    { 
    	int boyut = sayac*2+4;
		for(int i=0;i<boyut;i++)
		{
			alan_dizi[i]=alan_dizi[i]/15;
		}
	
		for(int i=0, j=0; i<boyut/2-1 ,j<boyut/2-1;i+=2,j++)
		{
			degisim_X[j]=alan_dizi[i]-alan_dizi[i+2];
			degisim_Y[j]=alan_dizi[i+1]+alan_dizi[i+3];
		}
		int alan[boyut];
		int alan_toplam=0;
		for(int i=0;i<boyut/2-1;i++)
		{
			alan[i]=degisim_X[i]*degisim_Y[i];
			alan_toplam+=alan[i];
		}
		printf("Seklin alani:%d",alan_toplam/2);
	
		toplamalan+=alan_toplam;
		
		printf("\ntoplam alan : %d\n",toplamalan/2);
	}
	
	if(sayac>3) // daha buyuk sekiller icin
    { 
    	int boyut = sayac*2+4;
		for(int i=0;i<boyut;i++)
		{
			alan_dizi[i]=alan_dizi[i]/15;
		}
	
		for(int i=0, j=0; i<boyut/2-1 ,j<boyut/2-1;i+=2,j++)
		{
			degisim_X[j]=alan_dizi[i]-alan_dizi[i+2];
			degisim_Y[j]=alan_dizi[i+1]+alan_dizi[i+3];
		}
		int alan[boyut];
		int alan_toplam=0;
		for(int i=0;i<boyut/2-1;i++)
		{
			alan[i]=degisim_X[i]*degisim_Y[i];
			alan_toplam+=alan[i];
		}
		printf("Seklin alani:%d",alan_toplam/2);
	
		toplamalan+=alan_toplam;
		
		printf("\ntoplam alan : %d\n",toplamalan/2);
	}

	kaynakrezerv_hesapla(toplamalan/2);
	
	    
	
	
}
void sekil_ciz(int x1[50],int y1[50],int n)
{
	int dizi2[50];
	dizi2[0]=x1[0];
	dizi2[1]=y1[0];
	int sayac2=0;
	int f=1;
	int b=1;
	for(int i=1;i<n;i++)
	{
		if(x1[0]==x1[i] && y1[0]==y1[i])
		{
			
			dizi2[sayac2*2+2]=x1[i]; //son elemanlari atadik.
			dizi2[sayac2*2+3]=y1[i];
			break;
		}
	
		else
		{
			dizi2[b+1]=x1[f]; // ayni olan degerler arasindaki elemanlari aldik.
			dizi2[b+2]=y1[f];
			f++;
			b+=2;
			sayac2++;
		
		}
			
		
	}
	fillpoly(sayac2+2,dizi2);
	alan_bul(dizi2,sayac2);



	if(sayac2+2<n )
	{
		int sayac3=0;
	    int dizi3[50];
	    b=1;
		dizi3[0]=x1[sayac2+2];//yeni seklin ilk koordinatlari geldi
		dizi3[1]=y1[sayac2+2];
		
		for(int i=sayac2+3;i<n;i++)
		{
			if(x1[sayac2+2]==x1[i] && y1[sayac2+2]==y1[i])
			{
				dizi3[sayac2*2]=x1[i];
				dizi3[sayac2*2+1]=y1[i];
				break;
			}
			else
			{
				dizi3[b+1]=x1[sayac2+3]; // ayni olan degerler arasindaki elemanlari aldik.
			    dizi3[b+2]=y1[sayac2+3];
			    sayac2++;
			    b+=2;
			
				sayac3++;//cizimdeki kose degerini sayar.
			
			}
		}
		

			
		fillpoly(sayac3+1,dizi3);
	    alan_bul(dizi3,sayac3-1);


	}

}
int main(int argc, char** argv) {
	

	initwindow(300,300);
	int x=0;
	int y=0;
	for(int i=0;i<400;i++)
	{
	    setcolor(8);
	    setlinestyle(0,5,1);
		line(0,x,1000,x);
		x+=15;
			
	}
		for(int i=0;i<400;i++)
	{   
	    setcolor(8);
	    setlinestyle(0,5,1);
		line(y,0,y,1000);
		y+=15;
			
	}
	
 system("curl https://bilgisayar.kocaeli.edu.tr/prolab1/prolab1.txt > lab.txt");
	
	FILE *dosya = fopen("lab.txt","r");
	
	if (dosya == NULL) {
        printf("Dosya açma hatasý!\n");
        return -1; 
    }
    
    char karakter[100];
    int sayacsatir=0;
    int hedefsatir;
	float bsondajmaliyet;
    float bplatformaliyet;
    int n=0;
    int k=0;
    int l=1;
    int dizi[100];
    
    printf("\nKacinci satirin cizdirilecegini giriniz:");
    scanf("%d",&hedefsatir);
    printf("\nBirim sondaj maliyetini giriniz: ");
    scanf("%f",&bsondajmaliyet);
    printf("\nBirim platform maliyetini giriniz:");
    scanf("%f",&bplatformaliyet);
    
    while(fgets(karakter,sizeof(karakter),dosya)!=NULL)
    {
         sayacsatir++;
       if(sayacsatir==hedefsatir)
       {
       	for(int i=0;i<sizeof(karakter);i++)
       	{
		   
       	  if(karakter[i] == '(')
       	  {
       	    
       	  	int x=0,y=0,sayac=0;
       	  	
       	  	i++;
       	
       	  	while(karakter[i]!=',')
       	  	{
       	  		if(sayac !=0)
       	  		{
					 x=x*10;
			    }
       	  	x = x +karakter[i]-'0';
       	  	sayac++;
       	  	i++;
       	  	
			}
			
			sayac=0;
			i++;
			
			while(karakter[i]!=')')
			{
				if(sayac != 0)
				{
					y=y*10;
					
				}
				y = y +karakter[i]-'0';
				sayac++;
				i++;
			}
			 
			dizi[k]=x;
			dizi[l]=y;
			n++;
			k=k+2;
			l=l+2;
			
			
			}
			 }
			 }
	   }
	
			
				for(int i=0;i<n*2;i++)
			{
				dizi[i]=dizi[i]*15;
			}
	    
	    
	    int x1[50];
		int y1[50];
		int h=1,m=0;
		for(int i=0;i<n*2;i++)
		{
			x1[i]=dizi[m];
			m=m+2;
			y1[i]=dizi[h];
			h=h+2;
		}
	        	
			setcolor(4);
			setlinestyle(0,0,2);
			sekil_ciz(x1,y1,n);     	 
			
			getch();
			closegraph();
			fclose(dosya);

            return 0;
}
