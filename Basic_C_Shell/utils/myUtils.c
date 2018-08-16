#include "myUtils.h"

void strip(char *array){
	if(array == NULL)
	{
		perror("array is null");
		exit(-99);
	}// end if

	int len = strlen(array), x = 0;
   
	while(array[x] != '\0' && x < len)
	{
	  if(array[x] == '\r')
		 array[x] = '\0';

	  else if(array[x] == '\n')
		 array[x] = '\0';

	  x++;

}// end while
   
}// end strip

int menu(){
   char temp[MAX];
   int choice;
   printf("1) Print the list\n");
   printf("2) Add First\n");
   printf("3) Add Last\n");
   printf("4) Sort\n");
   printf("5) Remove Item\n"); 
   printf("6) Quit\n"); 
   printf("Choice --> ");
   fgets(temp, MAX, stdin);
   choice = atoi(temp);

   
   while(choice < 1 || choice > 6)
   {
      printf("1) Print the list\n");
      printf("2) Add First\n");
      printf("3) Add Last\n");
      printf("4) Sort\n");
      printf("5) Remove Item\n"); 
      printf("6) Quit\n"); 
      printf("Choice --> ");
      fgets(temp, MAX, stdin);
      choice = atoi(temp);
   
   }// end while

   return choice;
   
}// end menu

int isCD(char* buff){
    //char temp[strlen(buff)+1];
    //strncpy(temp,buff,3);
    //printf("%s\n",temp);
    return (strstr(buff,"cd") != NULL)?0:1;
}

void performCD(char* buff){
    char temp[strlen(buff)+1];
    strncpy(temp,buff+3,strlen(buff));
    printf("%s\n",temp);
    chdir(temp);
}

int getHistoryNumber(char* buff){
    char temp[strlen(buff)+1];
    
    strncpy(temp,buff+1,strlen(buff));
    //printf("%s\n",temp);
    
    int x;
    sscanf(temp,"%d",&x);
    //printf("%d\n",x);
    return x;
}

int fileExists(const char* file){
    FILE* fp = fopen(file,"r");
    
    if(fp != NULL){
        fclose(fp);
        return 0;
    }
    return -1;
}

int numItems(const char* file){
    int i,count = 0;
    FILE* fin = fopen(file,"r");
    
    if(fin != NULL){
        for(i = getc(fin);i != EOF;i = getc(fin)){
            if(i == '\n'){
                count++;
            }
        }
        fclose(fin);
    }
    return (count);
}