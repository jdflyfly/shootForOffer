#include<stdio.h>

int m,n,t;
int mat[1005][1005];


int search(int num){
    int i=0;
    int j=n-1;
    while(i<m&&j>=0){
        if(num>mat[i][j])
            i++;
        else if(num<mat[i][j])
            j--;
        else
            return 1;
    }
    
    return 0;

}



int main(){
    while(scanf("%d%d%d",&m,&n,&t)!=EOF){
        int i,j;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%d",&mat[i][j]);
    
    if(search(t))
        printf("Yes\n");
    else
        printf("No\n");
        
    
    
    }


    return 0;
}
