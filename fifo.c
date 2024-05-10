#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd;
    sleep(5);
   char*myfifo="myfifo";

   //create fifo
   mkfifo=(myfifo,0666);


   char arr1[80];
   fd=open(myfifo,O_WRONLY);
   fgets=(arr1,80,stdin);
   write(fd,arr1,strlen(arr1)+1);

int i=0,word=0,line=0,characters=0;

while(i<strlen(arr1)+1)
{
    if(arr1[i]="" | arr1[i]="/n")
{
    word++;
}
else if(arr1[i]=="/n"){
    line++
}
else {
    characters;

}
i++;

}
      printf("\n Number of words: %d",words);
      printf("\n Number of Lines: %d",lines);
      printf("\nNumber of Characters: %d",characters);
       close(fd);
       return 0;
}



fifo.c
