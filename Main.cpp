#pragma hdrstop

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

#include <stdio.h>
#include "TCPServer.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	char buffer[10];
	char messagerecu;
	char finDeChaine;

	do
	{

		TCPServer myServeur;
		if (myServeur.liaison() == false)

		{
			cout << "erreur lors de la liaison" << endl;
		}
		else
		{
			cout << "la liaison c'est bien etablie" << endl;
		}




		if (myServeur.listenClient() == false)
		{
			cout << "erreur lors du listen" << endl;
		}
		else
		{
			cout << "le listen c'est bien etablie" << endl;
		}


		if (myServeur.recup(buffer, 2) == true)
		{

			messagerecu = buffer[0];
			finDeChaine = buffer[1];

			if (finDeChaine != ';')
			{
				cout << "caractere de fin de chaine incorrect" << endl;
			}


			if (messagerecu == 'r')
			{

				cout << "rouge : " << messagerecu << endl;
				//appel à la fonction de la lib qui dit à la lampe d'allumer le rouge

			}

			else if (messagerecu == 'b')
			{
				cout << "bleu :" << messagerecu << endl;


			}

			else if (messagerecu == 'v')
			{
				cout << "vert : " << messagerecu << endl;

			}

			else if (messagerecu == 'a')
			{
				cout << "on : " << messagerecu << endl;

			}

			else if (messagerecu == 'e')
			{
				cout << "off : " << messagerecu << endl;

			}

		}
		else
		{
			cout << "impossible de lire le message " << endl;
		}
		myServeur.close();


	} while (messagerecu != '!');




	return 0;

}
