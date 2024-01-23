/*
Cho dãy số: 9   10     4    3    15   23   2   67   1    29 
Biểu diễn dãy số ở dạng cây nhị phân tìm kiếm. 
1)  Xây dựng hàm tạo cây nhị phân tìm kiếm. 
2) Xây dựng hàm duyệt giữa (tang dan)trên cây nhị phân tìm kiếm. 
3) Xây dựng hàm duyệt trước (g t p)trên cây nhị phân tìm kiếm. 
4) Xây dựng hàm duyệt sau (giam dan) trên cây nhị phân tìm kiếm. 
5) Xây dựng hàm tìm kiếm một phần tử trên cây nhị phân tìm kiếm. 
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct nut{
    int data;
    struct nut* L;
    struct nut* R;
};
typedef struct nut nut;
nut * taocay(nut * cay, nut * pt){
    if (cay==NULL) cay=pt;
    else{
        nut * tg=cay;
        nut * z;
        while (tg!=NULL){
            z=tg;
            if (tg->data>pt->data)
                tg=tg->L;
            else 
                tg=tg->R;
        }
        if (pt->data<z->data)
            z->L=pt;
        else
            z->R=pt;
    }
    return cay; 
}
void duyetgiua(nut *cay){
    if(cay!=NULL){
        duyetgiua(cay->L);
        printf("%d  ", cay->data);
        duyetgiua(cay->R);
    }
}
void duyetsau(nut *cay){
    if(cay!=NULL){
        duyetsau(cay->L);
        duyetsau(cay->R);
        printf("%d  ", cay->data);
    }
}
void duyettruoc(nut *cay){
    if(cay!=NULL){
        printf("%d  ", cay->data);
        duyettruoc(cay->L);
        duyettruoc(cay->R);
    }
}
int timkiem(nut* goc,int x){
    if(goc!=NULL){
         nut *tg=goc;
        while(tg!=NULL){
            if(x==tg->data) return 1;
            else
                if(x<tg->data)
                    tg=tg->L;
                else
                    tg=tg->R;
        }
        return 0;
    }
}
int main(){
    nut * goc=NULL;
    int n;
    printf("nhap bao nhieu so:");
    scanf("%d",&n);
    for (int i = 1; i <=n; i++)
    {   
        nut*  x=(nut *)malloc(sizeof(nut));;
        x->L=NULL;
        x->R=NULL;
        printf("nhap phan tu %d:",i);
        scanf("%d",&x->data);
        goc= taocay(goc,x);
    }

    
    int a;
    printf("nhap so can tim:");
    scanf("%d", &a);
    if (timkiem(goc,a)==1) printf("\nco trong danh sach");
    else printf("\nkhong co trong danh sach");
    printf("\n duyet giua: ");
    duyetgiua(goc);
    printf("\n duyet sau: ");
     duyetsau(goc);
     printf("\n duyet truoc: ");
    duyettruoc(goc);
}
