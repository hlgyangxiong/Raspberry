#include <stdio.h> 
#include <stdlib.h> 
int main(int argc, char *argv[]) 
{ 
    FILE *fp; 
    if((fp = fopen("f:\\ok.txt","a++")) == NULL)
    { 

    } 
    if((fp=fopen("f:\\ok.txt","w+"))==NULL)//如果文件不存在，新建文件，写数据 
    { 
        printf("Can not open file.\n"); 
        exit(0); 
    } 
    fputs("\n123456789000\n",fp);//试验数据，文件存在时尝试，文件不存在时尝试 
    fclose(fp); 
    return 0; 
}
