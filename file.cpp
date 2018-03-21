#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
int main() 
{ 
    int i = 1234;
    int a = 1;
    int b = 2;
    int c = 3;
    FILE *fp; 
    char buf[100] = "";
    if((fp=fopen("data.txt","w+"))==NULL)//如果文件不存在，新建文件，写数据 
    { 
        printf("Can not open file.\n"); 
        exit(0); 
    } 
    sprintf(buf, "%d,%d,%d,%d", i, a, b, c);
    fwrite(buf,strlen(buf),1 ,fp);//试验数据，文件存在时尝试，文件不存在时尝试 
    fclose(fp); 
    return 0; 
}
