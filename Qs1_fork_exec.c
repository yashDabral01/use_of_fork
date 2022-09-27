#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void sameProgramSameCode(){
system("clear");
fprintf(stdout,"Parent and child will execute same code and print pid\n");
fork();
fprintf(stdout,"pid:%d\n",getpid());
exit(1);
}
void sameProgramDifferentCode(){
    fprintf(stdout,"Different code in parent and child\n");
    pid_t pid = fork();
    if(pid == 0){
        fprintf(stdout,"Inside child with pid :%d\n",getpid());
        exit(1);
    }
    else if (pid>0){
        fprintf(stdout,"Inside parent with pid :%d\n",getpid());
        exit(1);
    }
    else{
        printf(stdout,"Error!!..");
        exit(1);
    }
}
void sameProgramWaitForChildToExit(){
    fprintf(stdout,"Differnt code in parent and child and parent will wait for child\n");
    pid_t pid = fork();
    if(pid == 0){
        sleep(1);
        fprintf(stdout,"Inside child with pid :%d\n",getpid());
        fprintf(stdout,"Exiting parent\n");
        exit(1);
    }
    else if (pid>0){
        fprintf(stdout,"Inside parent with pid :%d\n",getpid());
        fprintf(stdout,"Parent waiting for child\n");
        wait(NULL);
        fprintf(stdout,"Exiting parent\n");
        exit(1);
    }
    else{
        printf(stdout,"Error!!..");
        exit(1);
    }
}
int main(){
int choice;
while(1){
    printf("Press 0. To exit program\n");
    printf("Press 1. Same program and same code\n");
    printf("Press 2. Same program different code\n");
    printf("Press 3. Before terminating ,the parent waits for the child to finish its task\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 0:
        exit(0);
        break;
    case 1:
         sameProgramSameCode();
         break;
    case 2:
         sameProgramDifferentCode();
         break;
    case 3:
        sameProgramWaitForChildToExit();        
         break;
    default:
         printf("Enter a valid choice!!..");
         break;
    }

}
    return 0;
}