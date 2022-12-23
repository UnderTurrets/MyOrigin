#include<stdio.h>
#include<string.h>
#include<iostream>



typedef struct
{
    int exposure;
    int aperture;
    int gamma;
    double whitebalance;
    char coding[10];

} mystruct;



int main()
{   printf("输入的结构体的个数是：");
    int i,j;scanf("%d",&i);
	mystruct inf[i];

//写入：
    for (j=0;j<i;j++){
      printf("输入第%d个exposure数值\n",j+1);
  	  scanf("%d",&inf[j].exposure);
	  printf("输入第%d个aperture数值\n",j+1);
	  scanf("%d",&inf[j].aperture);
	  printf("输入第%d个gamma数值\n",j+1);
	  scanf("%d",&inf[j].gamma);
      printf("输入第%d个whitebalance数值\n",j+1);
	  scanf("%lf",&inf[j].whitebalance);
	  printf("输入第%d个coding数值\n",j+1);
	  scanf("%s",&inf[j].coding);
    }
	  FILE *p1=fopen("fileReadWrite.txt","w");
      if(p1){
    	fwrite(inf,sizeof(mystruct),i,p1);
    	fclose(p1);
	  }

//读取：
     int start=0,dis,n;
     printf("你要从第几个结构体读取:\n");
     scanf("%d",&start);
     printf("你要读取几个数据:\n");
     scanf("%d",&dis);


     for(j=0;j<dis;j++){

       FILE *p2 =fopen("fileReadWrite.txt","r");
       if(p2){
       	  mystruct temp;
     	  fseek(p2,sizeof(mystruct)*(start-1+j),SEEK_SET);
     	  fread(&temp,sizeof(mystruct),1,p2);
     	  fclose(p2);

	   printf("exposure:%d\naperture:%d\ngamma:%d\nwhitebalance:%f\ncoding:%s\n",temp.exposure,temp.aperture,temp.gamma,temp.whitebalance,temp.coding);
	   printf("\n");
       }
    }














    return 0;

}

