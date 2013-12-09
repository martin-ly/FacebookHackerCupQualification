#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node{
	string name;
	int shot;
	int height;
	int draft;
	int time;
};
bool myFunc(struct node Node1,struct node Node2){
	if(Node1.shot==Node2.shot){
		if(Node1.height>Node2.height){
			return true;
		}
		return false;
	}
	else if(Node1.shot>Node2.shot){
		return true;
	}
	return false;
}
bool myFunc1(struct node Node1,struct node Node2){
	if(Node1.time==Node2.time){
		if(Node1.draft<Node2.draft){
			return true;
		}
		return false;
	}
	else{
		if(Node1.time<Node2.time){
			return true;
		}
		return false;
	}
}
bool myFunc3(struct node Node1,struct node Node2){
	if((Node1.name.compare(Node2.name))<0){
		return true;
	}
	return false;
}
void display(vector<struct node> Data){
	int i=0;
	while(i<Data.size()){
		cout<<Data[i].name<<" "<<Data[i].time<<" ";
		i++;
	}
	cout<<endl;
}
void setTeam(int P,int M,vector<struct node>& Team){
	int j=1;
	int k;
	while(j<=M){
		k=0;
		while(k<P){
			Team[k].time++;
			k++;
		}
		sort(Team.begin(),Team.begin()+P,myFunc1);
		sort(Team.begin()+P,Team.end(),myFunc1);
		iter_swap(Team.begin()+P,Team.begin()+P-1);
		j++;
	}
}
int main(){
	int T;
	int i,j;
	int k;
	int N,M,P;
	scanf("%d",&T);
	string str;
	int shot,height;
	i=1;
	while(i<=T){
		scanf("%d %d %d",&N,&M,&P);
		vector<struct node> OrigData(N);
		vector<struct node> Result;
		vector<struct node> Team1;
		vector<struct node> Team2;
		j=0;
		while(j<N){
			cin>>str>>shot>>height;
			struct node Node;
			Node.name=str;Node.shot=shot;Node.height=height;Node.draft=0;Node.time=0;
			OrigData[j]=Node;	
			j++;
		}
		sort(OrigData.begin(),OrigData.end(),myFunc);
		j=0;
		while(j<N){
			OrigData[j].draft=j+1;
			if(j%2==0){
				Team1.push_back(OrigData[j]);
			}
			else{
				Team2.push_back(OrigData[j]);
			}
			j++;
		}
		cout<<"Case #"<<i<<": ";
		if((2*P==N)){
			sort(OrigData.begin(),OrigData.end(),myFunc3);
			j=0;
			while(j<N){
				cout<<OrigData[j].name<<" ";
				j++;
			}
			cout<<endl;
		}
		else{
			setTeam(P,M,Team1);
			Result.insert(Result.begin(),Team1.begin(),Team1.begin()+P);
			if((2*P+1)==N){
				Result.insert(Result.end(),Team2.begin(),Team2.end());
			}
			else{
				setTeam(P,M,Team2);	
				Result.insert(Result.begin(),Team2.begin(),Team2.begin()+P);
			}
			sort(Result.begin(),Result.end(),myFunc3);
			j=0;
			while(j<Result.size()){
				cout<<Result[j].name<<" ";
				j++;
			}
			cout<<endl;
		}
		i++;
	}
	return 0;
}
