#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "BAGAGE.h"
#include "P_date.h"
#include "Destination.h"
#include "Passager.h"
#include "Personne.h"
#include "Temp.h"
#include "Trajet.h"
#include "Vol.h"
#include "Reservation.h"
#include "Function.h"

using namespace std;

void main()
{
	ofstream f1("Reservation.txt",ios::app);
	ofstream f2("Vol.txt", ios::app);
	ofstream f3("Destination.txt", ios::app);
	ofstream f4("Trajet.txt", ios::app);
	f1.close();
	f2.close();
	f3.close();
	f4.close();
menu:
	system("cls");
        gotoxy(20,5);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENU PRINCIPALE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        gotoxy(20,7);
        cout<<"\xDB\xDB\xDB\xDB\xB2 1. Gestion de destinations ";
        gotoxy(20,9);
        cout<<"\xDB\xDB\xDB\xDB\xB2 2. Gestion de trajets";
        gotoxy(20,11);
        cout<<"\xDB\xDB\xDB\xDB\xB2 3. Gestion de vols";
        gotoxy(20,13);
        cout<<"\xDB\xDB\xDB\xDB\xB2 4. Gestion de reservations ";
        gotoxy(20,15);
        cout<<"\xDB\xDB\xDB\xDB\xB2 5. Quitter Application";
        gotoxy(20,17);
        cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        gotoxy(20,19);
        cout<<"Veuillez entrer votre choix : ";
	int x;
	cin >> x;
	switch (x)
	{
	case 3:
	{
		vol: system("cls");
		  gotoxy(20,5);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GESTION DE VOLS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,7);
	cout<<"\xDB\xDB\xDB\xDB\xB2 1. Ajouter un vol";
	gotoxy(20,9);
	cout<<"\xDB\xDB\xDB\xDB\xB2 2. Afficher un vol";
	gotoxy(20,11);
	cout<<"\xDB\xDB\xDB\xDB\xB2 3. Chercher un vol";
	gotoxy(20,13);
	cout<<"\xDB\xDB\xDB\xDB\xB2 4. Modifier un vol";
	gotoxy(20,15);
	cout<<"\xDB\xDB\xDB\xDB\xB2 5. Supprimer un vol";
	gotoxy(20,17);
	cout<<"\xDB\xDB\xDB\xDB\xB2 6. retourner au menu principale";
	gotoxy(20,19);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,22);
	cout<<"Veuillez entrer votre choix : ";
		
	
	    cin >> x;
     	switch (x)
		{
			char var1;
		case 1:
			do
			{
			ajoutvol(); 
			cout << "Voulez-vous ajouter un autre vol ? [o/n] ";
			cin >> var1;
			} while (var1 == 'o');
			goto vol;
			break;

		case 2:
			affichevol();
			cout << endl;
			system("pause");
			goto vol;
			break;
		case 3:
			do
			{
			recherchevol();
			cout << "Voulez-vous chercher un autre vol ? [o/n] ";
			cin >> var1;
			} while (var1 == 'o');
			goto vol;
			
			break;
		case 4:
			do
			{
			modifvol(); 
			cout << "Voulez-vous modifier un autre vol ? [o/n] ";
			cin >> var1;
			} while (var1 == 'o');
			goto vol;
			break;


		case 5:
			do
			{
				cout << "Veuillez entrer le numero de vol a supprimer : ";
				long z;
			cin >> z;
			supprimvol(z);
			cout << "Voulez-vous supprimer un autre vol ? [o/n] ";
			cin >> var1;
			} while (var1 == 'o');
			goto vol;
			
			break;
		case 6:
			goto menu;break;
		default: 
			gotoxy(10,23);
		cout<<"\a Erreur!!! Verifiez votre choix [de 1 a 6 ] !";
		delay(2);
		goto vol;
		}break;
	}

	case 1:
	{
		destination: system("cls");
		  gotoxy(20,5);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 GESTION DE DESTINATIONS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,7);
	cout<<"\xDB\xDB\xDB\xDB\xB2 1. Ajouter une destination";
	gotoxy(20,9);
	cout<<"\xDB\xDB\xDB\xDB\xB2 2. Afficher la liste de destinations";
	gotoxy(20,11);
	cout<<"\xDB\xDB\xDB\xDB\xB2 3. Chercher une destination";
	gotoxy(20,13);
	cout<<"\xDB\xDB\xDB\xDB\xB2 4. Supprimer une destination";
	gotoxy(20,15);
	cout<<"\xDB\xDB\xDB\xDB\xB2 5. Retourner au menu principale";
	gotoxy(20,17);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,20);
	cout<<"Veuillez entrer votre choix : ";
		int x1;
		
		cin >> x1;
		switch (x1)
		{
			char var2;
		    case 1:
				do
				{
				ajoutdes();
				cout << "Voulez-vous ajouter une autre destination ? [o/n] ";
				cin >> var2;
			   } while (var2 == 'o');
				goto destination;
				break;
			case 2:
				afficherdes();
				cout << endl;
				system("pause");
				goto destination;
				break;
			case 3:
				do
				{
				recherchdes();
				cout << "Voulez-vous chercher une autre destination ? [o/n] ";
				cin >> var2;
			   } while (var2 == 'o');
				goto destination;
				break;
			case 4:
				do
				{
					cout << "Veuillez entrer la reference de destination a supprimer : ";
					long h;
					cin >> h;
				supprimdes(h);
				cout << "Voulez-vous supprimer une autre destination ? [o/n] ";
				cin >> var2;
			   } while (var2 == 'o');
				goto destination;
				break;
			case 5 :
				goto menu;
				break;
			
			default: 
			gotoxy(10,23);
		cout<<"\a Erreur!!! Verifiez votre choix [de 1 a 5 ] !";
		delay(2);
		goto destination;

		}
	}break;
	case 2:
	{
    trajet: system("cls");
    gotoxy(20,5);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2GESTION DE TRAJETS\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,7);
	cout<<"\xDB\xDB\xDB\xDB\xB2 1. Ajouter un trajet";
	gotoxy(20,9);
	cout<<"\xDB\xDB\xDB\xDB\xB2 2. Afficher la liste des trajets";
	gotoxy(20,11);
	cout<<"\xDB\xDB\xDB\xDB\xB2 3. Chercher un trajet";
	gotoxy(20,13);
	cout<<"\xDB\xDB\xDB\xDB\xB2 4. Modifier un trajet";
	gotoxy(20,15);
	cout<<"\xDB\xDB\xDB\xDB\xB2 5. Supprimer un trajet";
	gotoxy(20,17);
	cout<<"\xDB\xDB\xDB\xDB\xB2 6. Ouvrir ou fermer un trajet";
	gotoxy(20,19);
	cout<<"\xDB\xDB\xDB\xDB\xB2 7. retourner au menu principale";
	gotoxy(20,21);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,24);
	cout<<"Veuillez entrer votre choix : ";
		int x;
		cin >> x;
		switch (x)
		{
			char var3;
		case 1:
			do
			{
				ajouttrajet();
				cout << "Voulez-vous ajouter un autre trajet ? [o/n] ";
				cin >> var3;
			} while (var3 == 'o');
			goto trajet;
			break;
		case 2: 
			affichetrajet();
			cout << endl;
			system("pause");
			goto trajet;
			break;
		case 3:
			do
			{
				recherchtrajet();
				cout << "Voulez-vous rechercher un autre trajet ? [o/n] ";
				cin >> var3;
			} while (var3 == 'o');
			goto trajet;
			break;
		case 4:
			do
			{
				modiftrajet('m');
				cout << "Voulez-vous modifier un autre trajet ? [o/n] ";
				cin >> var3;
			} while (var3 == 'o');
			goto trajet;
			break;
		
		case 5:
			do
			{
				long tr;
				cout << "Veuillez entrer la refenrece de trajet a supprimer : ";
				cin >> tr;
				supprimtrajet(tr);
				cout << "Voulez-vous supprimer un autre trajet ? [o/n] ";
				cin >> var3;
			} while (var3 == 'o');
			goto trajet;
			break;
		case 6:
			do
			{
			cout << "Voulez_vous ouvrir ou fermer un trajet ? [o/f] ";
			cin >> var3;
			modiftrajet(var3);
			cout << "Voulez-vous ouvrir ou fermer un autre trajet ? [o/n] ";
				cin >> var3;
			} while (var3 == 'o');
			goto trajet;
			break;
		case 7:
			goto menu ; break;

		default: 
		gotoxy(10,23);
		cout<<"\a Erreur!!! Verifiez votre choix [de 1 a 7 ] !";
		delay(2);
		goto trajet;
		}

	}
	case 4:
	{
		reservation:system("cls");
		  gotoxy(20,5);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2GESTION DE RESERVATIONS\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,7);
	cout<<"\xDB\xDB\xDB\xDB\xB2 1. Ajouter une reservation";
	gotoxy(20,9);
	cout<<"\xDB\xDB\xDB\xDB\xB2 2. Afficher la liste de reservationS";
	gotoxy(20,11);
	cout<<"\xDB\xDB\xDB\xDB\xB2 3. Chercher une reservation";
	gotoxy(20,13);
	cout<<"\xDB\xDB\xDB\xDB\xB2 4. Modifier une reservation";
	gotoxy(20,15);
	cout<<"\xDB\xDB\xDB\xDB\xB2 5. Supprimer une reservation";
	gotoxy(20,17);
	cout<<"\xDB\xDB\xDB\xDB\xB2 6. retourner au menu principale";
	gotoxy(20,19);
	cout<<"\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
	gotoxy(20,22);
	cout<<"Veuillez entrer votre choix : ";
		int x;
		cin >> x;
		switch (x)
		{
			char var4;

		case 1:
			do
			{
			ajoutres();
				cout << "Voulez-vous ajouter une autre reservation ? [o/n] ";
				cin >> var4;
			} while (var4 == 'o');
			goto reservation;

			break;
		case 2:
			afficheres();
			cout << endl;
			system("pause");
			goto reservation;
			break;
		case 3:
			do
			{
			recherchres();
			cout << "Voulez-vous chercher une autre reservation ? [o/n] ";
				cin >> var4;
			} while (var4 == 'o');
			goto reservation;
			break;
		case 4:
			do
			{
			modifres();
			cout << "Voulez-vous modifier une autre reservation ? [o/n] ";
				cin >> var4;
			} while (var4 == 'o');
			goto reservation;

			break;
		case 5:
			do
			{
			cout << "Veuillez entrer le numero de reservation a supprimer : ";
			long x;
			cin >> x;
			supprimres(x);
			cout << "Voulez-vous supprimer une autre reservation ? [o/n] ";
				cin >> var4;
			} while (var4 == 'o');
			goto reservation;

			break;
		case 6:
			goto menu; break;
		default: 
		gotoxy(10,23);
		cout<<"\a Erreur!!! Verifiez votre choix [de 1 a 6 ] !";
		delay(2);
		goto reservation;

		}
	}break;
	case 5:
	{
		system("cls");
		gotoxy(20, 5);
		cout << " Ecole Nationale des Ingenieurs de Carthage ";
		gotoxy(20, 9);
		cout << "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PROJET GESTION DE VOL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ";
		gotoxy(20, 14);
		cout << " Etudiants : Arbi Oussama & Helali Souha ";
		gotoxy(20, 16);
		cout << " Annee universitaire : 2014/2015 ";
		gotoxy(40, 25);
		cout << " Fermeture  dans 3 secondes  ...........";
		delay(5);
		exit(1);
	}
	default :
		gotoxy(10,23);
		cout<<"\a Erreur!!! Verifiez votre choix [de 1 a 6 ] !";
		delay(2);
		goto menu;

	}

	system("pause");
}