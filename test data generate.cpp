#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
void crypt(char PASS[])
{
	char pass[9]={119,-92,-3,-31,99,12,-49,40,68};
	for(char i=0;i<9;i++)
		PASS[i]^=pass[i];
	return;
}
void strand(char PASS[])
{
	for(char j,i=0;i<8;i++)
		if(PASS[i]=='\0')
		{
			for(j=i+1;j<9;j++)
				PASS[j]=rand();
			break;
		}
	return;
}
int main()
{
	srand(unsigned(time(NULL)));
	FILE *fin(fopen("list.txt","r")),*fout(fopen("HW1.dat","wb"));
	if(fin==NULL)
	{
		fclose(fin);
		fclose(fout);
		return 0;
	}
	char PASS[9],department[100];
	unsigned int Tn,Sn,Ln,id,T,S;
	unsigned short grade,time,credit,gpa;
	for(char i=0;i<9;i++)
		fscanf(fin,"%c",PASS+i);
	PASS[8]='\0';
	strand(PASS);
	crypt(PASS);
	fwrite(PASS,9,1,fout);
	fscanf(fin,"%u%u%u",&Tn,&Sn,&Ln);
	fwrite(&Tn,4,1,fout);
	fwrite(&Sn,4,1,fout);
	fwrite(&Ln,4,1,fout);
	for(unsigned int i=0;i<Tn;i++)
	{
		do
		{
			fscanf(fin,"%c",PASS);
		}
		while(PASS[0]!='\n');
		for(char i=0;i<9;i++)
		{
			fscanf(fin,"%c",PASS+i);
			if(PASS[i]==' ')
			{
				PASS[i]='\0';
				break;
			}
		}
		PASS[8]='\0';
		strand(PASS);
		fscanf(fin,"%s",department);
		fscanf(fin,"%u",&id);
		fwrite(PASS,9,1,fout);
		fwrite(department,strlen(department)+1,1,fout);
		fwrite(&id,4,1,fout);
	}
	for(unsigned int i=0;i<Sn;i++)
	{
		do
		{
			fscanf(fin,"%c",PASS);
		}
		while(PASS[0]!='\n');
		for(char i=0;i<9;i++)
		{
			fscanf(fin,"%c",PASS+i);
			if(PASS[i]==' ')
			{
				PASS[i]='\0';
				break;
			}
		}
		PASS[8]='\0';
		strand(PASS);
		fscanf(fin,"%s",department);
		fscanf(fin,"%hu",&grade);
		fscanf(fin,"%u",&id);
		fwrite(PASS,9,1,fout);
		fwrite(department,strlen(department)+1,1,fout);
		fwrite(&grade,2,1,fout);
		fwrite(&id,4,1,fout);
	}
	for(unsigned int i=0;i<Ln;i++)
	{
		fscanf(fin,"%u",&T);
		fscanf(fin,"%u",&S);
		fscanf(fin,"%hu",&time);
		fscanf(fin,"%s",department);
		fscanf(fin,"%hu",&credit);
		fscanf(fin,"%hu",&gpa);
		fscanf(fin,"%hu",&grade);
		fwrite(&T,4,1,fout);
		fwrite(&S,4,1,fout);
		fwrite(&time,2,1,fout);
		fwrite(department,strlen(department)+1,1,fout);
		fwrite(&credit,2,1,fout);
		fwrite(&gpa,2,1,fout);
		fwrite(&grade,2,1,fout);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
