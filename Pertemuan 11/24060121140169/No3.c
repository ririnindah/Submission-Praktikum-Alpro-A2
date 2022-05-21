/*Nama File 	: No3.c*/
/*Deskripsi 	: Membantu dalam memecahkan lokasi widya yg hilang/
/*Pembuat   	: 24060121140169 - Majid Ilham Adhim*/
/*Tgl Pembuatan	: 21 Mei 2022 - 22.06*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//permutasi dan palindrom
void palindrom(char *a, int l, int r)
{
    int i;
    int count=0;
    if (l == r) {
        int p = 0;
        int h = strlen(a) - 1;

        while (h > p){
            if (a[p++] != a[h--]){
                printf("%s bukan palindrom\n", a);
                return;
            }
        }
        printf("%s adalah palindrom\n", a);


    } else {
        for (i = l; i <= r; i++){
            swap((a+l), (a+i));
            palindrom(a, l+1, r);
            swap((a+l), (a+i));
        }

    }

}


int main()
{
    char *a[255];
    char S[255];
    int N;
    int j,k,i; //counter

    printf("masukkan kata: ");
    scanf("%s", &S);

    N =strlen(S);

    i = 0;
    char temp[255];
    for(j = 0; j<N;j++) {
        for(k=N; k>=0;k--) {
            if((j!=k) && (S[j]==S[k])) {
                temp[j] = S[j];
                temp[j-1] = temp[j];
            }
        }
    }

    for(i=0; i<=N;i++) {
        palindrom(S,i,N-1);
    }

    return 0;
}
