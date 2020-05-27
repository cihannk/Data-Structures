#include <stdio.h>
#include <stdlib.h>
struct stack{
    int kapasite;
    int ust;
    int *listebasi;
};
struct stack* stackyarat(int kap){
    struct stack *yeni=(struct stack*)malloc(sizeof(struct stack));
    yeni->kapasite=kap;
    yeni->ust=0;
    yeni->listebasi=(int*)malloc(sizeof(int)*kap);
    return yeni;
}
void stackpush(struct stack *stcfonk,int sayi){
    if(stcfonk->kapasite==stcfonk->ust){
        kaparttir(stcfonk);
    }
    stcfonk->listebasi[stcfonk->ust]=sayi;
    stcfonk->ust++;
}
void stackcikart(struct stack *stcfonk){
    printf("%d cikarildi\n",stcfonk->listebasi[stcfonk->ust-1]);
    stcfonk->listebasi[stcfonk->ust-1]=NULL;
    stcfonk->ust--;
}
void stackyaz(struct stack *stcfonk){
    for(int i=(stcfonk->ust)-1;i>-1;i--){
        printf("%d\n",stcfonk->listebasi[i]);
    }
}
void kaparttir(struct stack *stcfonk){
    stcfonk->kapasite=stcfonk->kapasite *2;
    int *yeni,*del;
    yeni=(int*)malloc(sizeof(int)*(stcfonk->kapasite));
    for(int i=0;i<stcfonk->ust;i++){
        yeni[i]=stcfonk->listebasi[i];
    }
    del=stcfonk->listebasi;
    stcfonk->listebasi=yeni;
    printf("kapasite artik %d\n",stcfonk->kapasite);
    free(del);
}
int main()
{
    struct stack *stc1=stackyarat(4);
    stackpush(stc1,5);
    stackpush(stc1,10);
    stackpush(stc1,15);
    stackpush(stc1,20);
    stackpush(stc1,25);
    stackpush(stc1,30);
    stackyaz(stc1);
    stackcikart(stc1);
    stackcikart(stc1);
    stackyaz(stc1);
    return 0;
}
