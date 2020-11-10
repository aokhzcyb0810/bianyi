#include<iostream>
#include<stdlib.h>
#include<string.h>
char stack[10000],stackq[10000];
int f(char a,char b);
int main(int argc,char* argv[]) {
	FILE *fp;
	fp=fopen(argv[1],"r");
	char a,c;
	int p=-1,q=-1;
	stack[++p]='a';
	while(fscanf(fp,"%c",&a)!=EOF){
		if(a=='\n' || a=='\r')
		break;
		else{
				if(f(stack[p],a)==0){
					stack[++p]=a;
					printf("I%c\n",a);
					if(a=='(')
					stackq[++q]=a;
				}
				else if(f(stack[p],a)==1){
					while(f(stack[p],a)==1){
						if(stack[p]=='i'){
							stackq[++q]='i';
							p--;
							printf("R\n");
						}
						else{
							if(q>0){
								p--;
								q--;
								if(stackq[q]=='('){
									printf("RE\n");
									return 0;
								}
								printf("R\n");
							}
							else{
								printf("RE\n");
								return 0;
							}
						}
					}
					stack[++p]=a;
				//	stackq[++q]=a;
					printf("I%c\n",a);
					if(f(stack[p-1],stack[p])==2){
						printf("R\n");
						p-=2;
						stackq[--q]='i';
					}
				}
				else if(f(stack[p],a)==2){
					printf("I%c\n",a);
						printf("R\n");
						p--;
						stackq[--q]='i';
					}
				else if(f(stack[p],a)==-1){
					printf("E\n");
					return 0;
				}
		}
		}
		a='a';
		while(stack[p]!='a'){
		if(f(stack[p],a)==0){
					stack[++p]=a;
					if(a=='(')
					stackq[++q]=a;
				}
				else if(f(stack[p],a)==1){
					while(f(stack[p],a)==1){
						if(stack[p]=='i'){
							stackq[++q]='i';
							p--;
							printf("R\n");
						}
						else{
							if(q>0){
								int nump=0,numq=0;
								for(int i=0;i<=q;i++){
									if(stackq[i]=='i')
									numq++;
								}
								for(int i=0;i<=p;i++){
									if(stack[i]=='+' || stack[i]=='*')
									nump++;
								}
								if(numq-nump<1 && p!=0){
									printf("RE\n");
									return 0;
								}
								p--;
								q--;
								if(stackq[q]=='('){
									printf("RE\n");
									return 0;
								}
								printf("R\n");
							}
							else{
								printf("RE\n");
								return 0;
							}
						}
						if(f(stack[p],a)==-1 && p!=0)
							{
								printf("E\n");
								return 0;
							}
					}
					stack[++p]=a;
				//	stackq[++q]=a;
				//	printf("I%c\n",a);
				if(f(stack[p-1],stack[p])==2){
						printf("R\n");
						p-=2;
						stackq[--q]='i';
					}
				}
				else if(f(stack[p],a)==2){
					printf("I%c\n",a);
						printf("R\n");
						p--;
						stackq[--q]='i';
					}
				else if(f(stack[p],a)==-1){
					printf("E\n");
					return 0;
				}
			}
	return 0;
}
int f(char a,char b){
	if(a=='a'){
		if(b=='+')
		return 0;
		if(b=='*')
		return 0;
		if(b=='i')
		return 0;
		if(b=='(')
		return 0;
		if(b==')')
		return -1;
		if(b=='a')
		return -1;
		return -1;
	}
	if(a=='+'){
		if(b=='+')
		return 1;
		if(b=='*')
		return 0;
		if(b=='i')
		return 0;
		if(b=='(')
		return 0;
		if(b==')')
		return 1;
		if(b=='a')
		return 1;
		return -1;
	}
	if(a=='*'){
		if(b=='+')
		return 1;
		if(b=='*')
		return 1;
		if(b=='i')
		return 0;
		if(b=='(')
		return 0;
		if(b==')')
		return 1;
		if(b=='a')
		return 1;
		return -1;
	}
	if(a=='i'){
		if(b=='+')
		return 1;
		if(b=='*')
		return 1;
		if(b=='i')
		return -1;
		if(b=='(')
		return -1;
		if(b==')')
		return 1;
		if(b=='a')
		return 1;
		return -1;
	}
	if(a=='('){
		if(b=='+')
		return 0;
		if(b=='*')
		return 0;
		if(b=='i')
		return 0;
		if(b=='(')
		return 0;
		if(b==')')
		return 2;
		if(b=='a')
		return -1;
		return -1;
	}
	if(a==')'){
		if(b=='+')
		return 1;
		if(b=='*')
		return 1;
		if(b=='i')
		return -1;
		if(b=='(')
		return -1;
		if(b==')')
		return 1;
		if(b=='a')
		return 1;
		return -1;
	}
	
}
