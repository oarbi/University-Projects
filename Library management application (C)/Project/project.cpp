#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "bib.h" 
#define TMAX 1000 
void main()
{ // inscrire - consulter - modifier - Recherche - suprimer un membre
	// Declaration des variables 
	int x, y, z;
	bool ok = false;
	char numcin[20], numisbn[20], chaine[TMAX], nbrmaxle[20], nbrmaxjl[20], test[20], recherche[TMAX] = "", password[TMAX], cin[TMAX], isbn[TMAX], livre[TMAX], nom[TMAX], prenom[TMAX];
	MEMBRE m;
	LIVRE l;
	PRET p;
	FILE* f1 = NULL;
	FILE* f2 = NULL;
	FILE* f3 = NULL;
	FILE* pret = NULL;
	FILE* temp = NULL;
	FILE* pass = NULL;
	//debut de prog
rpass:
	system("cls");
	gotoxy(10, 10);
	printf("Entrer le mot de pass \n");
	gotoxy(10, 11);
	scanf("%s", password);
	pass = fopen("pass.cle", "r");
	if (pass != NULL)
	{
		if (strcmp(fgets(chaine, TMAX, pass), password) == 0)
		{
			fclose(pass);
			goto debut;	
		}
		else
		{
			gotoxy(10, 12);
			printf("Le mot de pass est incorrect !!");
			delay(2);
		}
		goto rpass;
	}
debut:
	system("cls");
	printf("\t ** GESTION DE LA BIBLIOTHEQUE ** \n");
	notif();
A:
	printf("\nMenu :\n\t 1/ Gestion des membres \n\t 2/ Gestion des livres \n\t 3/ Gestion d\'emprunt \n\t 4/ Parametre du programme \n\t 5/ Sortir du Programme \n");
	printf("\nQue voulez vous faire ? (Donner le numero de la tache) : ");
	scanf("%d", &x);
	switch (x)
	{
	case 1: // Gestion des membres
	M :
		printf("\nLa gestion des membres comporte \n\t 1/ l\'inscription d'un nouveau membre \n\t 2/ Consultation de la liste des membres \n\t 3/ Recherche, modification et supression d'un membre \n\t 4/ Retour au menu principale \n\t 5/ Sortir du programme \n");
	  printf("\n Que voulez vous faire ? (Donner le numero de la tache) : ");
	  scanf("%d", &y);
	  switch (y)
	  {
	  case 1: // inscrire un membre
		  printf("voulez vous donner les information du membre a inscrire : \n");
		  while ((strlen(m.cin) != 8) || (atoi(m.cin) == 0) || (strlen(test) != 8))
		  {
		  L:
			  printf("Donner le Numero cin : "); scanf("%s", m.cin); sprintf(test, "%d", atoi(m.cin));
		  }
		  f1 = fopen("membre.bib", "r");
		  if (f1 != NULL)
		  {
			  while (fgets(chaine, TMAX, f1) != NULL)
			  {
				  if (strstr(chaine, m.cin) != NULL)
				  {
					  printf("Ce membre est deja inscris \n"); goto L;
				  }
			  }
			  fclose(f1);
		  }
		  printf("Donner le nom : "); scanf("%s", m.nom);
		  printf("Donner le prenom : "); scanf("%s", m.prenom);
		  printf("Donner le class : "); scanf("%s", m.clas);
		  printf("Donner l'E-mail : "); scanf("%s", m.email);
		  printf("Donner le Numero de tel : "); scanf("%s", m.tel);
		  f1 = fopen("membre.bib", "a");
		  fprintf(f1, "%s %s %s %s %s %s \n", m.cin, m.nom, m.prenom, m.clas, m.email, m.tel);
		  fclose(f1);
		  m.cin[0] = ' ';
		  printf("------------------------------------------"); goto M; break;
	  case 2: // consulter la liste des membre
		  f1 = fopen("membre.bib", "r");
		  while (fgets(chaine, TMAX, f1) != NULL)
		  {
			  printf("%s", chaine);
		  }

		  fclose(f1);
		  printf("------------------------------------------"); goto M; break;
	  case 3: // modifier - Recherche - suprimer un membre
	  R :
		  printf("Donner le numero du cin de l'etudiant : ");
		scanf("%s", numcin);
		f1 = fopen("membre.bib", "r");
		if (f1 != NULL)
		{
			while (fgets(chaine, TMAX, f1) != NULL)
			{
				if (strstr(chaine, numcin) != NULL)
				{
					printf("\nLe membre recherche est :\n\t%s\n", chaine); break;
				}
				else
				{
					printf("\tLe membre recherche n'existe pas !!\n");
					printf("------------------------------------------"); goto M; break;
				}
			}
			fclose(f1);
		}
		printf("Que voulez vous faire ? \n\t 1/ Modifir ce membre \n\t 2/ Supprimer ce membre \n\t 3/ Rechercher un autre membre  \n\t 4/ Retourner au menu principale \n");
		printf(" Donner le numero de la tache : ");
		scanf("%d", &z);
		if ((z == 1) || (z == 2))
		{
			f1 = fopen("membre.bib", "r");
			f2 = fopen("temp.bib", "a");
			if (f1 != NULL)
			{
				while (fgets(chaine, TMAX, f1) != NULL)
				{
					if (strstr(chaine, numcin) == NULL) fputs(chaine, f2);
					if ((strstr(chaine, numcin) != NULL) && (z == 1))
					{
						printf("Donner les nouveaus info :\n");
						printf("Donner le Numero de  cin : "); scanf("%s", m.cin);
						printf("Donner le nom : "); scanf("%s", m.nom);
						printf("Donner le prenom : "); scanf("%s", m.prenom);
						printf("Donner le class : "); scanf("%s", m.clas);
						printf("Donner l'E-mail : "); scanf("%s", m.email);
						printf("Donner le N de tel : "); scanf("%s", m.tel);
						fprintf(f2, "%s %s %s %s %s %s \n", m.cin, m.nom, m.prenom, m.clas, m.email, m.tel);
					}
				}
			}
			fclose(f1);
			fclose(f2);
			remove("membre.bib");
			f1 = fopen("membre.bib", "a");
			f2 = fopen("temp.bib", "r");
			if (f2 != NULL)
			{
				while (fgets(chaine, TMAX, f2) != NULL)
				{
					fputs(chaine, f1);
				}
			}
			fclose(f1);
			fclose(f2);
			remove("temp.bib");
		}
		if (z == 3) goto R;
		if (z == 4)
		{
			printf("------------------------------------------");
			goto M;
		}
		break;
	  case 4:
		  goto A; break;
	  case 5:
		  exit(1); break;
	  } break;
	case 2:// Gestion des livre
	M1 :
		printf("\nLa gestion des Livres comporte \n\t 1/ Ajouter un nouveau livre \n\t 2/ Consulter la liste des livres \n\t 3/ Chercher, modifier et supprimer un livre \n");
	   printf("\n Que voulez vous faire ? (Donner le numero de la tache) : ");
	   scanf("%d", &y);
	   switch (y)
	   {
	   case 1: // ajouter un livre

		   while (((strlen(l.isbn) != 10) && (strlen(l.isbn) != 13)) || (atoi(l.isbn) == 0) || ((strlen(test) != 10) && (strlen(test) != 13)))
		   {
		   L1:
			   printf("Donner le ISBN : "); scanf("%s", l.isbn); sprintf(test, "%d", atoi(l.isbn));
		   }
		   f1 = fopen("livre.bib", "r");
		   if (f1 != NULL)
		   {
			   while (fgets(chaine, TMAX, f1) != NULL)
			   {
				   if (strstr(chaine, l.isbn) != NULL)
				   {
					   printf("Ce livre existe \n"); goto L1;
				   }
			   }
			   fclose(f1);
		   }
		   printf("Donner le titre du livre : "); scanf("%s", l.titre);
		   printf("Donner le nom de l'auteur : "); scanf("%s", l.auteur);
		   printf("Donner le nombre des livres disponibles : "); scanf("%s", l.nbr);
		   f1 = fopen("livre.bib", "a");
		   fprintf(f1, "%s %s %s :%s\n", l.isbn, l.titre, l.auteur, l.nbr);
		   fclose(f1);
		   l.isbn[0] = ' ';
		   printf("------------------------------------------"); goto M1; break;
	   case 2: // consulter la liste des livres
		   f1 = fopen("livre.bib", "r");
		   while (fgets(chaine, TMAX, f1) != NULL)
		   {
			   printf("%s", chaine);
		   }

		   fclose(f1);
		   printf("------------------------------------------"); goto M1; break;
	   case 3: // modifier - Recherche - suprimer un livre
	   R1 :
		   printf("Donner l'ISBN du livre : ");
		  scanf("%s", numisbn);
		  f1 = fopen("livre.bib", "r");
		  if (f1 != NULL)
		  {
			  while (fgets(chaine, TMAX, f1) != NULL)
			  {
				  if (strstr(chaine, numisbn) != NULL)
				  {
					  printf("\nLe livre recherche est :\n\t%s\n", chaine); break;
				  }
				  else
				  {
					  printf("\tLe livre recherche n'existe pas !!\n");
					  printf("------------------------------------------"); goto M1; break;
				  }
			  }
			  fclose(f1);
		  }
		  printf("Que voulez vous faire ? \n\t 1/ Modifir ce livre \n\t 2/ Supprimer ce livre \n\t 3/ Rechercher un autre livre  \n\t 4/ Retourner au menu principale \n");
		  printf(" Donner le numero de la tache : ");
		  scanf("%d", &z);
		  if ((z == 1) || (z == 2))
		  {
			  f1 = fopen("livre.bib", "r");
			  f2 = fopen("temp.bib", "a");
			  if (f1 != NULL)
			  {
				  while (fgets(chaine, TMAX, f1) != NULL)
				  {
					  if (strstr(chaine, numisbn) == NULL) fputs(chaine, f2);
					  if ((strstr(chaine, numisbn) != NULL) && (z == 1))
					  {
						  printf("Donner les nouveaux informations :\n");
						  printf("Donner l'ISBN : "); scanf("%s", l.isbn);
						  printf("Donner le titre du livre : "); scanf("%s", l.titre);
						  printf("Donner le nom de l'auteur : "); scanf("%s", l.auteur);
						  printf("Donner le nombre des livres disponibles : "); scanf("%s", l.nbr);
						  fprintf(f2, "%s %s %s %s \n", l.isbn, l.titre, l.auteur, l.nbr);
					  }
				  }
			  }
			  fclose(f1);
			  fclose(f2);
			  remove("livre.bib");
			  f1 = fopen("livre.bib", "a");
			  f2 = fopen("temp.bib", "r");
			  if (f2 != NULL)
			  {
				  while (fgets(chaine, TMAX, f2) != NULL)
				  {
					  fputs(chaine, f1);
				  }
			  }
			  fclose(f1);
			  fclose(f2);
			  remove("temp.bib");
		  }
		  if (z == 3) goto R1;
		  if (z == 4)
		  {
			  printf("------------------------------------------");
			  goto M1;
		  }
		  break;
	   case 4:
		   goto A; break;
	   case 5:
		   exit(1); break;
	   } break;
	case 3: // gestion d'emprunt
	M2 :
		printf("\nLa gestion d'emprunt comporte \n\t 1/ l'ajout d'un emprunt \n\t 2/ Consultation de la liste des emprunts \n\t 3/ Supression d'un emprunt \n\t 4/ Retour au menu principale \n");
	   printf("\nQue voulez vous faire ? (Donner le numero de la tache) : ");
	   scanf("%d", &y);
	   switch (y)
	   {
	   case 1://ajout
		   while ((strlen(p.cin) != 8) || (atoi(p.cin) == 0) || (strlen(test) != 8))
		   {
		   L2:
			   printf("Donner le Numero de cin : "); scanf("%s", p.cin); sprintf(test, "%d", atoi(p.cin));
		   }

		   if (nbr("membre.bib", p.cin) == 0)
		   {
			   printf("Ce membre n'existe pas \n"); goto L2;
		   }
		   else
		   {
			   pret = fopen("pret.bib", "a");
			   if (nbr("pret.bib", p.cin) >= atoi(extract("parametre.bib", "1/")))
			   {
				   printf("Ce membre ne peut plus avoir de pret de livres \n"); goto L2;
			   }
			   else
			   {
				   while (((strlen(p.isbn) != 10) && (strlen(p.isbn) != 13)) || (atoi(p.isbn) == 0) || ((strlen(test) != 10) && (strlen(test) != 13)))
				   {
				   L2b:
					   printf("Donner l'ISBN : "); scanf("%s", p.isbn); sprintf(test, "%d", atoi(p.isbn));
				   }
				   if (nbr("pret.bib", p.isbn) >= atoi(extract("livre.bib", p.isbn)))
				   {
					   printf("le livre n'est pas disponible \n"); goto L2b;
				   }
				   else
				   {
					   if (nbr("livre.bib", p.isbn) == 0)
					   {
						   printf("Ce livre n\'existe pas\n"); goto L2b;
					   }
					   else
					   {
						   strcat(recherche, p.cin);
						   strcat(recherche, " ");
						   strcat(recherche, p.isbn);
						   if (nbr("pret.bib", recherche) != 0)
						   {
							   printf("Ce pret existe deja \n"); goto M2;
						   }
						   fprintf(pret, "%s %s %d/%d/%d\n", p.cin, p.isbn, jour(), mois(), annee());
					   }
					   fclose(pret);
				   }
			   }
		   } goto M2; break;
	   case 2://cons
		   pret = fopen("pret.bib", "r");
		   while (fgets(chaine, TMAX, pret) != NULL)
		   {
			   //printf("%s", chaine);
			   strcpy(cin, extfichier("pret.bib", chaine, 1));
			   strcpy(isbn, extfichier("pret.bib", chaine, 2));
			   strcpy(nom, extfichier("membre.bib", cin, 2));
			   strcpy(prenom, extfichier("membre.bib", cin, 3));
			   strcpy(livre, extfichier("livre.bib", isbn, 2));
			   printf("%s %s => %s (%s) \n", nom, prenom, livre, isbn);
			   if (int(diffjour(extfichier("pret.bib", chaine, 3))) >= atoi(extract("parametre.bib", "2/")))
				   printf("\t => Ce membre a depasse la duree limite de %d jours.\n", atoi(extract("parametre.bib", "2/")));
			   printf("___________________________________________________________\n");
		   }
		   fclose(pret); goto M2; break;
	   case 3: // supp
	   R2 :
		   printf("Donner les informations du pret a supprimer \n");
		  printf("Donner le Numero de cin du membre :"); scanf("%s", p.cin);
		  printf("Donner l'ISBN :"); scanf("%s", p.isbn);
		  strcat(recherche, p.cin);
		  strcat(recherche, " ");
		  strcat(recherche, p.isbn);
		  if (nbr("pret.bib", recherche) == 0)
		  {
			  printf("Ce pret n\'existe pas \n"); goto R2;
		  }
		  else
		  {
			  if (int(diffjour(extfichier("pret.bib", recherche, 3))) >= atoi(extract("parametre.bib", "2/")))
				  printf("\t => Ce membre a depasse la duree limite de %d jours.\n", atoi(extract("parametre.bib", "2/")));
			  pret = fopen("pret.bib", "r");
			  temp = fopen("temp.bib", "a");
			  if (pret != NULL)
			  {
				  while (fgets(chaine, TMAX, pret) != NULL)
				  {
					  if (strstr(chaine, recherche) == NULL) fputs(chaine, temp);

				  }
			  }
			  fclose(pret);
			  fclose(temp);
			  remove("pret.bib");
			  pret = fopen("pret.bib", "a");
			  temp = fopen("temp.bib", "r");
			  if (temp != NULL)
			  {
				  while (fgets(chaine, TMAX, temp) != NULL)
				  {
					  fputs(chaine, pret);
				  }
			  }
			  fclose(pret);
			  fclose(temp);
			  remove("temp.bib");
		  }
		  printf("apuiez sur entrer pour continuer...");
		  _getch();
		  goto M2; break;
	   case 4:
		   goto A; break;
	   }
	   break;
	case 4: // paremtrage
		f3 = fopen("parametre.bib", "r");
		printf("Vos parametres sont :\n");
		if (f3 != NULL)
		{
			while (fgets(chaine, TMAX, f3) != NULL)
			{
				printf("\t%s", chaine);
			}
			fclose(f3);
		}
	P:
		printf("Que voulez vous faire ? \n\t 1/ Modifier le 1er parametre \n\t 2/ Modifier le 2eme parametre \n\t 3/ Changer le mot de pass \n\t 4/ Retourner au menu principale \n");
		scanf("%d", &y);
		switch (y)
		{
		case 1:
			parametrage("Le nombre maximum des livres par etudiant", "1/"); goto P;  break;
		case 2:
			parametrage("Le nombre maximum des jours d'emprunt d'un livre", "2/"); goto P; break;
		case 3:
			pass = fopen("pass.cle", "w+");
			printf("Entrer le nouveau mot de pass : "); scanf("%s", password);
			fprintf(pass, "%s", password);
			fclose(pass);
			goto P; break;
		case 4:
			goto A; break;
		}
	case 5:

		exit(-1);
	}
	_getch();
}