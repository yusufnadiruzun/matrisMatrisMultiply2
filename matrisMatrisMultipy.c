#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void matrisOlustur (int satir,int sutun,int sutun2, float **d1, float **d2 ){
    //srand(time(0));
    int i , j;
    
    // 1. Matrisi oluşturmak için
    
    for(i = 0; i < satir; i++){
        for(j = 0; j < sutun; j++){
            (d1[i][j]) = rand()%10 ;
            }
        }
        printf("Matris 1 olusturuldu\n");
    
    // 1. Matrisi yazdırmak  için
    
    for(i = 0; i < satir; i++){
        for(j = 0; j < sutun; j++){
            printf("%2.0f ",d1[i][j]); //rand()%10 ;
        }
          printf("\n");
      }
    
    // 2. Matrisi oluşturmak için
    
    for(i = 0; i < sutun; i++){
        for(j = 0; j < sutun2; j++){
            d2[i][j] = rand()%10 ;
           }
    }
    printf("Matris 2 olusturuldu\n");
    
    // 2. Matrisi yazdırmak için
    
    for(i = 0; i < sutun; i++){
      for(j = 0; j < sutun2; j++){
          printf("%2.0f ",d2[i][j]); //rand()%10 ;
      }
        printf("\n");
    }
}


void sonucYazdir (float **d3,int satir,int sutun2){
    
    int i,j;
    
    // 2 matris çarpımından döndürülen yeni dizinin konsola yazdırılma işlemi
    
    for(i = 0; i< satir; i++){
        for(j = 0; j<sutun2; j++)
            {
            printf(" %2.0f ",d3[i][j]);
        }
        printf("\n");
    }
}


float matrislerCarpimi(float **d1, float **d2, float **d3, int satir,int sutun ,int sutun2){
    
    int  i, j, k;
    
    // Parametre olarak girilen 2 matrisin çarpılma işlemi. Bu işlem sonucunda d3 isimli yeni matris dönüyor.
    /* 3 adet for döngüsü bulunuyor.
     1. for 1. matrisin satir sayisi kadar dönüyor.
     2. for 2. matrisin sutunu kadar dönüyor.
     3. for girilen her iki matristen birbine eşit olan 1. matrisin sutun sayısı ve 2. matrisin satır sayısı kadar dönüyor.
        eşit olma sebebi 2 matrisi çarpmak için 1. matrisin sutunu 2. matrisin satır sayısına eşit olma zorunluluğudur.
     */
    
    for(i = 0; i<satir; i++){
            for(j = 0; j<sutun2; j++){
                for(k = 0; k<sutun; k++){
                d3[i][j] +=d1[i][k]*d2[k][j];
                }
            }
    }
    return **d3;
}



int main(void){
 
    time_t basla, son ;
    int satir,sutun,sutun2,i,temp;
    
    // Kullanci tarafından matris boyutunun girilmesi
    
    printf("1.matris icin satir sayisi giriniz");
    scanf("%d", &satir);
    
    printf("1.matris icin sutun sayisi giriniz");
    scanf("%d", &sutun);

    printf("2.matris icin sutun sayisi giriniz");
    scanf("%d", &sutun2);

    // Malloc kullanılarak kullacının girmiş olduğu matrisin satır sayısına göre  1. 2. ve 3. diziler için hafıza da yer ayrımı yapılıyor
    
    float **d1 = (float **)malloc(satir * sizeof(float *));
    float **d2 = (float **)malloc(sutun * sizeof(float *));
    float **d3 = (float **)malloc(satir * sizeof(float *));

    // Yine malloc kullanılarak daha önce ayrılmış olan hafızanın üstüne kullanıcıdan girilen sutun sayısı için yer ayırma işlemi
    
    for(i = 0; i<satir; i++){
        d1[i] = (float *)malloc( sutun * sizeof(float));
    }
    for(i = 0; i<sutun; i++){
        d2[i] = (float *)malloc( sutun2 * sizeof(float));
    }
    for(i = 0; i< satir ; i++){
        d3[i] = (float *)malloc( sutun2 * sizeof(float));
    }
     
       // Fonksiyonları çağırma işlemleri
    
   matrisOlustur(satir,sutun,sutun2,d1,d2);
    
    // matris çarpma işlemi ve o çarpma işleminde geçen sürenin hesaplanması
   basla = time(NULL) ;
   matrislerCarpimi(d1,d2,d3,satir,sutun,sutun2);
   son = time(NULL);
    
    // Çarpımın sonucunun konsola yazdırılması
    printf("\n 2 Matris carpiminin sonucu : \n");
    sonucYazdir(d3,satir,sutun2);
    printf("\a");
    printf("\a");
    // geçen Sürenin yazdırılması
    printf("gecen sure = %.2f\n", difftime(son,basla));
    return 0;
}
