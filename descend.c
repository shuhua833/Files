#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp,*fpp;
	float avg;
	float *p;
	int count=0;
	int i,j;
	float temp;
	fp=fopen("e:\\numbers.txt","r");
	fpp=fopen("e:\\descend.txt","w");
	while(fscanf(fp,"%f",&avg)!=EOF)
	count=count+1;
	p=(float*)malloc(count*sizeof(float));
	rewind(fp);
	for(i=0;i<count;i++)
	fscanf(fp,"%f",(p+i));
	for(i=0;i<count-1;i++)
		{
		for(j=i+1;j<count;j++)
			{
			if(*(p+i)<*(p+j))
			{
				temp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
			}}}
	for(i=0;i<count;i++)
	fprintf(fpp,"%f\t",*(p+i));
	fclose(fp);
	fclose(fpp);
}
