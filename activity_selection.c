/*Author - Harshdeep shakya
Date-07/11/2023 */ 
#include<stdio.h> 
void ActivitySelector(int act[],int start[],int finish[],int n){
    int A=act[1];
    int i=1;
    printf("\n%d Activity = %d",i,A);
    for(int m=2;m<=n;m++){
        if(start[m]>=finish[i]){
            A=act[m];
            i=m;
            printf("\n%d Activity = %d",i,A);
        }  
    }
}

void swap(int *a,int *b,int *c,int *d,int *e,int *f){
    int temp=*a;
    *a=*b;
    *b=temp;

    temp=*c;
    *c=*d;
    *d=temp;

    temp=*e;
    *e=*f;
    *f=temp;
}
int partition(int act[],int start[],int finish[],int p,int q){
    int pivot=finish[p];
    int i=p;
    for(int j=p+1;j<=q;j++)
    {
        if(finish[j]<=pivot){
            i++;
            swap(&act[i],&act[j],&start[i],&start[j],&finish[i],&finish[j]);
        }
    }
    swap(&act[i],&act[p],&start[i],&start[p],&finish[i],&finish[p]);
    return i;
}

void sort(int act[],int start[],int finish[],int p,int q){
    if(p<q){
        int m=partition(act,start,finish,p,q);
        sort(act,start,finish,p,m-1);
        sort(act,start,finish,m+1,q);
    }
}
int main(){
    int n;
    printf("Enter the no. of activity: ");
    scanf("%d",&n);
    int start[100],finish[100],act[100];
    act[0]=0;
    start[0]=0;
    finish[0]=0;
    for(int i=1;i<=n;i++){
        act[i]=i;
        printf("Enter the starting and finish time of an activity %d : ",i);
        scanf("%d %d",&start[i],&finish[i]);
        
    }
    sort(act,start,finish,0,n);
    ActivitySelector(act,start,finish,n);

    return 0;
}