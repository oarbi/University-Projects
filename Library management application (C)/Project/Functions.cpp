#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#define TMAX 1000
int jour()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant = *localtime(&secondes);
	//printf("%d/%d/%d ; %d:%d:%d \n", instant.tm_mday, instant.tm_mon + 1, instant.tm_year + 1900, instant.tm_hour, instant.tm_min, instant.tm_sec);
	return instant.tm_mday;
}
int mois()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant = *localtime(&secondes);
	//printf("%d/%d/%d ; %d:%d:%d \n", instant.tm_mday, instant.tm_mon + 1, instant.tm_year + 1900, instant.tm_hour, instant.tm_min, instant.tm_sec);
	return instant.tm_mon + 1;
}
int annee()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant = *localtime(&secondes);
	//printf("%d/%d/%d ; %d:%d:%d \n", instant.tm_mday, instant.tm_mon + 1, instant.tm_year + 1900, instant.tm_hour, instant.tm_min, instant.tm_sec);
	return instant.tm_year + 1900;
}
char* date()
{
	char dateinst[10];
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant = *localtime(&secondes);
	sprintf(dateinst, "%d/%d/%d", instant.tm_mday, instant.tm_mon + 1, instant.tm_year + 1900);
	return dateinst;
}
double diffjour(char *date)
{
	int jj, mm, aaaa;
	struct tm when = { 0 };
	double diff_t;
	time_t converted, now;
	sscanf(date, "%2d/%2d/%4d", &jj, &mm, &aaaa);
	when.tm_mday = jj;
	when.tm_mon = mm - 1;
	when.tm_year = aaaa - 1900;
	time(&now);
	converted = mktime(&when);
	diff_t = difftime(now, converted);
	return diff_t / 86400;
}
void delay(int i)    /*Pause l'application pour i seconds*/
{
	clock_t start, end;
	start = clock();
	while (((end = clock()) - start) <= i*CLOCKS_PER_SEC); // while(((end=clock())-start)<=((i*CLOCKS_PER_SEC)/1000)); => ms
}
void success(char *fichier, char *ch)
{
	bool exist = false;
	char chaine[TMAX];
	FILE* f1 = NULL;
	f1 = fopen(fichier, "r");
	if (f1 != NULL)
	{
		while (fgets(chaine, TMAX, f1) != NULL)
		{
			if (strstr(chaine, ch) != NULL)
			{
				exist = true; break;
			}
		}
		fclose(f1);
	}
	if (exist == true)
	{
		printf("\n\t Operation termine avec succees");
		delay(3);
		system("cls"); // effacer le contenue de la console
	}
	else
	{
		printf("\n\t Operation a echoue");
	}
}
char* extract(char *fichier, char *ch) // pour obtenir le resulta en chiffre "atoi(extract(char *fichier,char *ch))"
{
	char *res = NULL;
	int i;
	char chaine[TMAX];
	FILE* f1 = NULL;
	f1 = fopen(fichier, "r");
	if (f1 != NULL)
	{
		while (fgets(chaine, TMAX, f1) != NULL)
		{
			if (strstr(chaine, ch) != NULL) break;
		}
		fclose(f1);
	}
	for (i = 0; i < strlen(chaine); i++)
	{
		if (*(chaine + i) == ':')
		{
			res = chaine + i + 1;
		}
	}
	return res;
}
char* extchaine(char *chaine, int x)
{
	char part1[TMAX], part2[TMAX], part3[TMAX], part4[TMAX], part5[TMAX], part6[TMAX];
	sscanf(chaine, "%s %s %s %s %s %s", part1, part2, part3, part4, part5, part6);
	switch (x)
	{
	case 1:
		return part1; break;
	case 2:
		return part2; break;
	case 3:
		return part3; break;
	case 4:
		return part4; break;
	case 5:
		return part5; break;
	case 6:
		return part6; break;
	}
}
char* extfichier(char *fichier, char *ch, int x) // pour obtenir le resulta en chiffre "atoi(extract(char *fichier,char *ch))"
{
	char part1[TMAX], part2[TMAX], part3[TMAX], part4[TMAX], part5[TMAX], part6[TMAX];
	char chaine[TMAX];
	FILE* f1 = NULL;
	f1 = fopen(fichier, "r");
	if (f1 != NULL)
	{
		while (fgets(chaine, TMAX, f1) != NULL)
		{
			if (strstr(chaine, ch) != NULL) break;
		}
		fclose(f1);
	}
	sscanf(chaine, "%s %s %s %s %s %s", part1, part2, part3, part4, part5, part6);
	switch (x)
	{
	case 1:
		return part1; break;
	case 2:
		return part2; break;
	case 3:
		return part3; break;
	case 4:
		return part4; break;
	case 5:
		return part5; break;
	case 6:
		return part6; break;
	}
}
int nbr(char *fichier, char *ch)
{
	int i = 0;
	char chaine[TMAX];
	FILE* f1 = NULL;
	f1 = fopen(fichier, "r");
	if (f1 != NULL)
	{
		while (fgets(chaine, TMAX, f1) != NULL)
		{
			if (strstr(chaine, ch) != NULL)
				i++;
		}
		fclose(f1);
	}
	return i;
}
void parametrage(char *ch, char *nbr)
{
	char chaine[TMAX], nbrmaxle[20], nbrmaxjl[20];
	//FILE* f1 = NULL;
	FILE* f2 = NULL;
	FILE* f3 = NULL;
	f3 = fopen("parametre.bib", "r");
	f2 = fopen("temp.bib", "a");
	if (f3 != NULL)
	{
		while (fgets(chaine, TMAX, f3) != NULL)
		{
			if (strstr(chaine, nbr) == NULL) fputs(chaine, f2);
			if (strstr(chaine, nbr) != NULL)
			{
				printf("%s : ", ch); scanf("%s", nbrmaxle);
				fprintf(f2, "%s %s :%s\n", nbr, ch, nbrmaxle);
			}
		}
	}
	fclose(f3);
	fclose(f2);
	remove("parametre.bib");
	f3 = fopen("parametre.bib", "a");
	f2 = fopen("temp.bib", "r");
	if (f2 != NULL)
	{
		while (fgets(chaine, TMAX, f2) != NULL)
		{
			fputs(chaine, f3);
		}
	}
	fclose(f3);
	fclose(f2);
	remove("temp.bib");
}
void notif()
{
	int x, y, z;
	bool exist = false;
	char chaine[TMAX], cin[TMAX], isbn[TMAX], livre[TMAX], nom[TMAX], prenom[TMAX];
	FILE* pret = NULL;
	pret = fopen("pret.bib", "r");
	printf("\nCentre de notifications :\n\n");
	while (fgets(chaine, TMAX, pret) != NULL)
	{
		if (int(diffjour(extfichier("pret.bib", chaine, 3))) >= atoi(extract("parametre.bib", "2/")))
		{
			strcpy(cin, extfichier("pret.bib", chaine, 1));
			strcpy(isbn, extfichier("pret.bib", chaine, 2));
			strcpy(nom, extfichier("membre.bib", cin, 2));
			strcpy(prenom, extfichier("membre.bib", cin, 3));
			strcpy(livre, extfichier("livre.bib", isbn, 2));
			printf("%s %s => %s (%s) \n", nom, prenom, livre, isbn);
			exist = true;
		}
	}
	if (exist == true)
		printf("\t => Ces membres ont depasse la duree limite de %d jours.\n", atoi(extract("parametre.bib", "2/")));
	else
		printf("Il n'y a aucune notification ! \n");
	printf("___________________________________________________________\n");
	fclose(pret);
}
void gotoxy(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}