#include<stdio.h>
int main(){
	int T,N;
	int result;
	scanf("%d",&T);
	int k=1;
	int ilow,ihigh,jlow,jhigh;
	int i,j;
	while(k<=T){
		scanf("%d",&N);
		result=1;
		char Data[N][N];
		ilow=jlow=-1;
		i=0;
		while(i<N){
			scanf("%s",Data[i]);
			j=0;
			while(j<N){
				if(Data[i][j]=='#'){
					if(ilow==-1){
						ilow=i;
						ihigh=i;
					}
					else if(i>ihigh){
						ihigh=i;
					}
					if(jlow==-1){
						jlow=j;
						jhigh=j;
					}
					else if(j>jhigh){
						jhigh=j;
					}
				}
				j++;
			}
			i++;
		}
		if((ihigh-ilow)==(jhigh-jlow)){
			i=ilow;
			while(i<=ihigh){
				j=jlow;
				while(j<=jhigh){
					if(Data[i][j]!='#'){
						result=0;
						break;
					}
					j++;
				}
				if(result==0){
					break;
				}
				i++;
			}	
		}
		else{
			result=0;
		}
		if(result){
				printf("Case #%d: YES\n",k);
		}
		else{
			printf("Case #%d: NO\n",k);
		}
		k++;
	}
	return 0;
}
