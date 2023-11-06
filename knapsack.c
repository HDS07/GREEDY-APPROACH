/*Author- Harshdeep shakya
 Date: 06/11/2023 */

#include<stdio.h>
float knapsack(float profit[],float weight[],float pbw[],float M,int n){
    float p=0;
    for(int i=0;i<n;i++){
        if(M>0 && weight[i]<=M){
            M=M-weight[i];
            p=p+profit[i];
        }
        else if(M>0){
            p=p+((M/weight[i])*(profit[i]));
            break;
        }
    }    
    return p;
}
void swap(int *a,int *b,float *c,float *d,float *e,float *f,float *g,float *h){
    int temp=*a;
    *a=*b;
    *b=temp;

    float temp2=*c;
    *c=*d;
    *d=temp2;

    temp2=*e;
    *e=*f;
    *f=temp2;
    
    temp2=*g;
    *g=*h;
    *h=temp2;

}
int partition(int obj[],float profit[],float pbw[],float weight[],int p,int q){
    float pivot=pbw[p];
    int i=p;
    for(int j=p+1;j<=q;j++)
    {
        if(pbw[j]>=pivot){
            i++;
            swap(&obj[i],&obj[j],&profit[i],&profit[j],&pbw[i],&pbw[j],&weight[i],&weight[j]);
        }
    }
    swap(&obj[i],&obj[p],&profit[i],&profit[p],&pbw[i],&pbw[p],&weight[i],&weight[p]);
    return i;
}

void sort(int obj[],float profit[],float pbw[],float weight[],int p,int q){
    if(p<q){
        int m=partition(obj,profit,pbw,weight,p,q);
        sort(obj,profit,pbw,weight,p,m-1);
        sort(obj,profit,pbw,weight,m+1,q);
    }
}

int main(){
    int n;
    int obj[100];
    float pbw[100],profit[100],weight[100],M;
    printf("Enter the capacity of a beg:");
    scanf("%f",&M);
    printf("Enter the no. of object: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        obj[i]=i+1;
        printf("Enter the profit and weight of obj %d :",obj[i]);
        scanf("%f %f",&profit[i],&weight[i]);
    }
    for(int i=0;i<n;i++){
        pbw[i]=profit[i]/weight[i];
        printf("profit by weight of obj %d is: %f\n",obj[i],pbw[i]);
    }  
    sort(obj,profit,pbw,weight,0,n);
    printf("\nAfter sorting:\n");
    for(int i=0;i<n;i++){
        printf("%d %f %f %f\n",obj[i],pbw[i],profit[i],weight[i]);
    }  
    float c=knapsack(profit,weight,pbw,M,n);
    printf("\nThe maximum profit is:%f",c);
   
    return 0;
}