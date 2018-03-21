#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
    int i = 1234;
    FILE *fp; 
    
    if((fp=fopen("data.txt","w+"))==NULL)//如果文件不存在，新建文件，写数据 
    { 
        printf("Can not open file.\n"); 
        exit(0); 
    } 
    fwrite(itoa(i),fp);//试验数据，文件存在时尝试，文件不存在时尝试 
    fclose(fp); 
    return 0; 
}
