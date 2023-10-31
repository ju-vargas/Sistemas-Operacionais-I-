#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
int main(void){
    pid_t retorno_do_fork;         
    //criar 5 processos, com dois forks do processo principal e um fork para cada filho

        
    printf("Tem UM processo.\n");
    printf ("\n\n----------\nSou o processo PAI pid %d e meu pai eh... %d\n----------\n\n", getpid(), getppid());

    //printf("PAI: %d\n", getpid());
    retorno_do_fork = fork() ;
    printf("Tem DOIS processos\n");
     
    //se for o pai (retorno do fork diferente de 0) eu vou criar mais um processo 
    //aqui o filho tambem vai estar executando

    if(retorno_do_fork != 0){
       // printf("sou o PAI, vou ter mais um filho\n"); 
       // printf("FILHO 1: %d \n", retorno_do_fork);
        retorno_do_fork = fork();
       
        //vai continuar sendo o pai, pq so ele deu ambos os dois forks
        //o filho 2 vai partir daqui, mas ele nunca chegou a dar fork, entao ta com zero 
        
        //if(retorno_do_fork != 0)
            //printf("FILHO 2: %d \n", retorno_do_fork);
    }

    printf("Agora, devem ter TRES processos executando isso\n");

    //agora, cada filho deve der um filho (somente os filhos)
    //eles nao fizeram fork ainda, entao o retorno_do_fork pra ambos eh zero

    if(retorno_do_fork == 0) {
        //printf("Sou um filho e terei um filho! \n");
        retorno_do_fork = fork();
        
        //ja que agora os filhos tem valor pra retorno de fork
        //vou printar esse valor pra ver o pid do neto
        
        //if(retorno_do_fork != 0)
            //printf("NETO: %d\n", retorno_do_fork);
    }

    printf ("Agora, devem ter CINCO processos executando isso\n");
    printf ("\n\n----------\nSou o processo %d e meu pai eh o processo %d\n----------\n\n", getpid(), getppid());     
    return(0);
}

