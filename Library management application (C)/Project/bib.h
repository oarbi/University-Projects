struct membre
{
	char cin[20], nom[20], prenom[20], clas[20], email[20], tel[20];
};
struct livre
{
	char isbn[50], titre[50], auteur[50] ,nbr[20];
};
struct pret
{
	char cin[20], isbn[20], datePret[20];
};
typedef struct membre MEMBRE;
typedef struct livre LIVRE;
typedef struct pret PRET;
int jour();
int mois();
int annee();
char* date();
double diffjour(char *datestr);
void delay(int i);
void success(char *fichier, char *ch);
char* extract(char *fichier, char *ch);
char* extfichier(char *fichier, char *ch, int x);
char* extchaine(char *chaine, int x);
void parametrage(char *ouss, char *nbr);
int nbr(char *fichier, char *ch);
void notif();
void gotoxy(int x, int y);