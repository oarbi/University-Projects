#include <stdio.h>
#include <string.h>    
#include <stdlib.h>    
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h>    
#include <pthread.h>

pthread_mutex_t mut;
struct sockaddr_in server , client;
int sock , acc,tsock, C0 = 20;


void *ConnectionClient(void *args)
{
    FILE *his;
    int rec,som=0,i,j;
    int tab[2];
    char ch[20]={""},rep[20]={""};
    
    pthread_mutex_lock(&mut);
    socklen_t clt = sizeof(client);
    if(tsock == SOCK_STREAM )
    { 
        rec = recv(acc , tab , sizeof(tab) , 0);
        if(rec == -1)
        {
            printf("\nProbleme de reception des données !!\n");
            exit(-1);
        }
    }
    else
    {
        rec = recvfrom(sock , tab , sizeof(tab) , 0,(struct sockaddr *)&client,&clt);
        if(rec == -1)
        {
            printf("\nProbleme de reception des données !!\n");
            exit(-1);
        }
    }
    his = fopen("historique.txt","a+");
    fseek(his,0,0);
    while((!feof(his)) && (fscanf(his,"%d %d %s",&i,&j,ch)!=-1))
    {
        if(strcmp(ch,"succes") == 0)
        {
            som+=j;
        }
    }
    if ((som+tab[1]) > C0)
    {
        strcpy(rep,"echec");
        
        if(fprintf(his ,"%d %d %s\n",tab[0],tab[1],rep) == -1)
        {
            printf("\nProbleme d'écriture dans le fichier !!\n");
            exit(-1);
        }
        if(tsock == SOCK_STREAM )
        {
            if(send(acc , rep , strlen(rep) , 0)<0)
            {
                printf("\nProbleme d'envoie des données !!\n");
                exit(-1);
            }
        }
        else
        {
            if( sendto(sock , rep , strlen(rep) , 0,(struct sockaddr *)&client,sizeof(client))<0)
            {
                printf("\nProbleme d'envoie des données !!\n");
                exit(-1);
            }
        }
        printf("\nLe client numero %d n'arrive pas a inscrire %d sportifs.\nLa capacité restante est %d \n",tab[0],tab[1],C0 -som);
    }
    else
    {
        strcpy(rep,"succes");
        if(fprintf(his,"%d %d %s\n",tab[0],tab[1],rep) == -1)
        {
            printf("\nProbleme d'écriture dans le fichier !!\n");
            exit(-1);
        }
        if(tsock == SOCK_STREAM )
        {
            if(send(acc , rep , strlen(rep) , 0)<0)
            {
                printf("\nProbleme d'envoie des données !!\n");
                exit(-1);
            }
        }
        else
        {
            if(sendto(sock , rep , strlen(rep) , 0,(struct sockaddr *)&client,sizeof(client))<0)
            {
                printf("\nProbleme d'envoie des données !!\n");
                exit(-1);
            }
        }
        printf("\nLe client numero %d a inscrire %d sportifs.\nLa capacité restante est %d \n",tab[0],tab[1],C0 -(som+tab[1]));
    }
    pthread_mutex_unlock(&mut);
    fclose(his);
    pthread_exit(0);
    return 0;
} 

 
int main(int argc , char *argv[])
{
    int c ,pn;
    pthread_t thrd;
    pthread_mutex_init(&mut,NULL);
    char type[20]={""};
    
    if(argc == 3)
    {
        pn=atoi(argv[1]);
        if(strcmp(argv[2],"tcp") == 0)
            tsock = SOCK_STREAM;
        else if(strcmp(argv[2],"udp") == 0)
            tsock = SOCK_DGRAM;
        else goto TS;
    }
    else
    {
        printf("\n ***** Configuration ***** \n");
        printf("\nspecifier le port : ");
        scanf("%d",&pn);
    TS: printf("specifier le protocole a utuliser (tcp/udp) : ");
        scanf("%s",type);
        if(strcmp(type,"tcp") == 0)
            tsock = SOCK_STREAM;
        else if(strcmp(type,"udp") == 0)
            tsock = SOCK_DGRAM;
        else goto TS;
    }
    printf("\n ***** Parametrage ***** \n");
    printf("\nLa capacité initiale est : %d\nVoulez vous la modifier ( 0 Pour la valeur initiale) ? : ",C0);
    scanf("%d",&C0);
    if(C0 == 0)
    {
        C0 = 20;
    }
    
    printf("\n ***** Demarrage de serveur ***** \n");
    sock = socket(AF_INET , tsock , 0);
    if (sock == -1)
    {
        printf("\nProbleme de Création de Socket !!\n");
        exit(-1);
    }
    printf("\nSocket crée avec succes. \n");
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(pn);
    
    if( bind(sock,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        printf("\nProbleme de Bind !!\n");
        exit(-1);
    }
    printf("Bind fait avec succes. \n");
    
    if(tsock == SOCK_STREAM )
    {
        if(listen(sock , 5) == -1)
        {
            printf("\nProbleme de listen !!\n");
            exit(-1);
        }
        printf("En attente de connection. \n");
    }
    c = sizeof(struct sockaddr_in);
    printf("\n ***** Reception des données et Inscription ***** \n");
    while(1)
    {
        if(tsock == SOCK_STREAM )
        {
            pthread_mutex_lock(&mut);
            acc = accept(sock, (struct sockaddr *)&client, (socklen_t*)&c);
            pthread_mutex_unlock(&mut);
            if (acc == -1)
            {
                printf("\nConnection non acceptée !!\n");
                exit(-1);
            }
        }
            if( pthread_create( &thrd , NULL ,  ConnectionClient , NULL) < 0)
            {
                printf("\nProbleme de Création de thread !!\n");
                exit(-1);
            }
        pthread_join( thrd , NULL);
    }
    close(sock);
    pthread_mutex_destroy(&mut);
    return 0;
}

 
