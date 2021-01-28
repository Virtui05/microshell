#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void pomoc() {
    printf("\n**Microshell SOP**\n Krzysztof Rychlik\n");
    printf("Indeks: 462082\n");
    printf(" Lista komend:\n help - autor oraz obslugiwane komendy\n cd - poruszanie sie miedzy folderami\n ");
    printf("exit - zakonczenie programu\n\n");

}
void show_path(){
    char path[1000];
    getcwd(path, sizeof(path));
    printf("[%s]\n$ ",path);
}

char get_path(char ptr[100]){
    char path[1000], com;
    getcwd(path, sizeof(path));
    chdir(ptr);
     return 0;
}

void error(){
    FILE*er;
    er=fopen("nie istnieje.txt","rb");
    if(er==NULL){
    printf("\n");
    printf("Blad polecenia (%d): ",errno);
    printf("%s\n",strerror(errno));
    printf("\n");
    } else{
        fclose(er);
    }

}



void fke(char ptr[100]){
    
    char* path = "";
    char program[20];
    char* args[100];  
    strcpy(program,path);
    strcat(program,ptr);
    int pid=fork();
    if(pid==0){
        execlp(program,ptr,(char *)NULL);
        error();
        exit(EXIT_SUCCESS);
    }else{
        
        wait(NULL);
    }
}

void wypisz(char ech[201]){
    char znak[]=" ,.-";
    ech=strtok(NULL,znak);
    while(ech!=NULL){
        printf("%s ",ech);
        ech=strtok(NULL,znak);
}
    printf("\n");
}


int main(){

    char command[201];
    char help[5] = "help", cd[3] = "cd", exit[5] = "exit", echo[5]="echo";
    show_path();
    gets(command);
    char *ptr = strtok(command, " ");
    if(strcmp(ptr,exit)==0){
        return 0;
    }
    else{
        do {
        
            if (strcmp(ptr, help) == 0) {
                pomoc();
         }
            else if (strcmp(ptr, cd) == 0) {
                ptr = strtok(NULL, " ");
             get_path(ptr);

         }else if(strcmp(ptr, echo) == 0){
             wypisz(ptr);
         }
            else {
                
                fke(ptr);
         }
            
            show_path();
            gets(command);
             ptr = strtok(command, " ");
        }   while (strcmp(ptr, exit) != 0);
    }
    return 0;
}