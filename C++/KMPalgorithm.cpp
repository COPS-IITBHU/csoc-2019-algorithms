#include<bits/stdc++.h>

using namespace std;

void makerefarray(char* sub,int b,int* ref){
	int i=1,j=0;
	ref[0]=0;
	while(i<b){
		if(sub[i]==sub[j]){
			j++;
			ref[i]=j;
			i++;
		}
		else{
			if(j!=0){
				j=ref[j-1];
			}
			else{
				ref[i]=0;
				i++;
			}
		}
	}
}

void KMPsearch(char* main,char* sub){
	int a=strlen(main);
	int b=strlen(sub);
	int ref[b];
	
	makerefarray(sub,b,ref);
	
	int i = 0; 
    int j = 0; 
    while (i<a) { 
        if (sub[j]==main[i]){ 
            j++; 
            i++; 
        } 
        if(j==b){ 
            cout<<"Found substring at index :"<<i-j;
            j=ref[j-1]; 
        } 
  
        else if (i<a&&sub[j]!=main[i]) { 
            if (j!=0) 
                j=ref[j-1]; 
            else
                i=i+1; 
        } 
    } 
}

int main(){
	cout<<"Write Your String :";
	char main[50];
	cin>>main;
	cout<<"Write Your Substring :";
	char sub[50];
	cin>>sub;
	KMPsearch(main,sub);
}
