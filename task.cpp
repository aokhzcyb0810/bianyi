#include<iostream>
#include<stdlib.h>
#include<string.h>
char str[100];
char a;
int flag=1;
void Print(char str[]);
int main(int argc,char* argv[]){
	FILE *fp;
	int n=0;
	fp=fopen(argv[1],"r");
	while(fscanf(fp,"%c",&a)!=EOF){
		if(a>32){
		if(n==0){
			str[n++]=a;
		}
		else{
		if(str[n-1]>=48 && str[n-1]<=57){
			if(a>=48 && a<=57){
				str[n++]=a;
			}
			else{
				str[n]='\0';
				Print(str);
				if(flag==0)
				return 0;
				n=0;
				str[n++]=a;
			}
			}
		else if((str[n-1]>=65 && str[n-1]<=90) || (str[n-1]>=97 && str[n-1]<=122)){
			if(a>=48 && a<=57){
				str[n++]=a;
			}
			else if(a>=65 && a<=90){
				str[n++]=a;
			}
			else if(a>=97 && a<=122){
				str[n++]=a;
			}
			else{
				str[n]='\0';
				Print(str);
				if(flag==0)
				return 0;
				n=0;
				str[n++]=a;
			}
		}
		else{
			if(str[n-1]==':' && a=='='){
				str[n++]=a;
			}
			else{
				str[n]='\0';
				Print(str);
				if(flag==0)
				return 0;
				n=0;
				str[n++]=a;
			}
		}
		}
	}
	else{
		if(n!=0){
		str[n]='\0';
		Print(str);
		if(flag==0)
		return 0;
		n=0;
	}
	}
	}
	if(n!=0){
		str[n]='\0';
		Print(str);
		if(flag==0)
		return 0;
		n=0;
	}
	return 0;
}
void Print(char str[]){
	if(strcmp(str,"BEGIN")==0)
	  printf("Begin\n");
	else if(strcmp(str,"END")==0)
	  printf("End\n");
	else if(strcmp(str,"FOR")==0)
	  printf("For\n");
	else if(strcmp(str,"IF")==0)
	  printf("If\n");
	else if(strcmp(str,"THEN")==0)
	  printf("Then\n");
	else if(strcmp(str,"ELSE")==0)
	  printf("Else\n");
	else if(str[0]>=48 && str[0]<=57)
		printf("Int(%s)\n",str);
	else if((str[0]>=65 && str[0]<=90) || (str[0]>=97 && str[0]<=122))
		printf("Ident(%s)\n",str);
	else if(strcmp(str,":")==0)
	  printf("Colon\n");
	else if(strcmp(str,"+")==0)
	  printf("Plus\n");
	else if(strcmp(str,"*")==0)
	  printf("Star\n");
	else if(strcmp(str,",")==0)
	  printf("Comma\n");
	else if(strcmp(str,"(")==0)
	  printf("LParenthesis\n");
	else if(strcmp(str,")")==0)
	  printf("RParenthesis\n");
	else if(strcmp(str,":=")==0)
	  printf("Assign\n");
	else
	{
		printf("Unknown\n");
		flag=0;
	}
}
