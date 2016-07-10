#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
int main (int argc, char* argv[])
{
    int sock, conn,pn,tsock,choix;
    struct sockaddr_in server;
    char rep[20]={""},adr[20]={""},type[20]={""};
    int tab[2];
    
    if(argc == 3)
    {
        strcpy(adr,argv[1]);
        pn=atoi(argv[2]);
        goto TS;
    }
    else if(argc == 4)
    {
        strcpy(adr,argv[1]);
        pn=atoi(argv[2]);
        if(strcmp(argv[3],"tcp") == 0)
            tsock = SOCK_STREAM;
        else if(strcmp(argv[3],"udp") == 0)
            tsock = SOCK_DGRAM;
        else goto TS;
    }
    else
    {
 CONF:  printf("\n ***** Configuration *****\n");
        printf("\nspecifier l'adresse du serveur : ");
        scanf("%s",adr);
        printf("specifier le port : ");
        scanf("%d",&pn);
    TS: printf("specifier le protocole a utuliser (tcp/udp) : ");
        scanf("%s",type);
        if(strcmp(type,"tcp") == 0)
            tsock = SOCK_STREAM;
        else if(strcmp(type,"udp") == 0)
            tsock = SOCK_DGRAM;
        else goto TS;
    }
    
    printf("\n ***** Demarrage de Client *****\n");
    
    sock = socket(AF_INET , tsock , 0);
    if (sock == -1)
    {
        printf("\nProbleme de Création de Socket !!\n");
        exit(-1);
    }
    printf("\nSocket crée avec succes. \n");
    server.sin_addr.s_addr = inet_addr(adr);
    server.sin_family = AF_INET;
    server.sin_port = htons(pn);
    
    if(tsock == SOCK_STREAM )
    {
    CO: conn = connect(sock , (struct sockaddr *)&server , sizeof(server));
        if (conn == -1)
        {
            printf("\nProbleme de Connection !!\n");
     VOU:   printf("\nVoulez Vous : \n1 - Reconnecter\n2 - Entrer une nouvelle Configuration \n3 - Quitter !!\n");
            scanf("%d",&choix);
            switch(choix)
            {
                case 1: goto CO;break;
                case 2: goto CONF;break;
                case 3: exit(-1);break;
                default: printf("\nChoix Incorrect !!\n");
                         goto VOU;
            }
        }
        printf("Connection établie avec succes. \n");
    }
    printf("\n ***** Inscription *****\n");
INS: printf("\nEnter Votre ID : ");
    scanf("%d" , tab);
    printf("Enter le nbr de sportif a inscrire : ");
    scanf("%d" , tab+1);
    if((tab[0]==0)||(tab[1]==0))
    {
        printf("\nVotre ID et le nbr de sportif ne peut pas étre zéro \n");
        goto INS;
    }
    
    if(tsock == SOCK_STREAM )
    {
        if( send(sock , tab , sizeof(tab) , 0) == -1)
        {
            printf("\nProbleme d'envoie des données !!\n");
            exit(-1);
        }
        printf("\nDonnées envoyés avec succes. \n");
        if( recv(sock , rep , sizeof(rep) , 0) == -1)
        {
            printf("\nProbleme de reception des données !!\n");
            exit(-1);
        }
    }
    else
    {
        
        if( sendto(sock , tab , sizeof(tab) , 0,(struct sockaddr *)&server,sizeof(server)) == -1)
        {
            printf("\nProbleme d'envoie des données !!\n");
            exit(-1);
        }
        printf("\nDonnées envoyés avec succes. \n");
        socklen_t ser = sizeof(server); 
        if( recvfrom(sock , rep , sizeof(rep) , 0,(struct sockaddr *)&server,&ser) == -1)
        {
            printf("\nProbleme de reception des données !!\n");
            exit(-1);
        }
    } 
    printf("\n ***** Resultat ***** \n");
    printf("\nEtat : %s\n\n",rep);
    close(sock);
    return 0;
}