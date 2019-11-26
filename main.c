//
//  main.c
//  二级第七套   一
//
//  Created by 陈泉松 on 2018/10/15.
//  Copyright © 2018 陈泉松. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef int KeyType;

typedef struct {
    KeyType key; //关键字
}RecType; //Record type

typedef struct {
    RecType r[MAXSIZE+1];
    int length;
}SqList;

void BinaryInsert(SqList *L){
    int i,j;
    int low,high,mid;
    
    for (i=2;i<=L->length;i++){

        L->r[0]=L->r[i];
        low=1;
        high=i-1;
        
        while (low<=high) {
        mid=(low+high)/2;
        if(L->r[0].key<L->r[mid].key) high=mid-1;
        else low=mid+1;
        }//循环结束，high+1为插入位置
        for(j=i-1;j>=high+1;j--) L->r[j+1]=L->r[j];
        L->r[high+1]=L->r[0];
    }
}

int main(){
    SqList L;
    for(int i=1;i<=20;i++)
        L.r[i].key=20-i;
    L.length=21;
    for (int i=1; i<=20; i++) {
        printf("%d  ",L.r[i].key);
        
    }
    printf("\n");
    BinaryInsert(&L);
    for (int i=1; i<=20; i++) {
         printf("%d  ",L.r[i].key);
     }
    return 0;
}
