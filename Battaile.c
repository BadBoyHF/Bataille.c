#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


void main ()	
{
	int a = 0;
	int b=0;
	int p=26;
	int l=0;
	int k=0;
	int con;
	int nbrct=0;
	int check=1;
	int var,i,j = 0;
	int paquet[52];
	int deck1[51];
	int deck2[51];
	int exists;
	int var_temp = 0;
	int var_position= 0;
	int egalite = 0;
	
	char Cartes[52][3] = {

		{1,2,3},
		{2,3,3},
		{3,4,3},
		{4,5,3},
		{5,6,3},
		{6,7,3},
		{7,8,3},
		{8,9,3},
		{9,10,3},
		{10,11,3},
		{11,12,3},
		{12,13,3},
		{13,14,3},
		{14,2,4},
		{15,3,4},
		{16,4,4},
		{17,5,4},
		{18,6,4},
		{19,7,4},
		{20,8,4},
		{21,9,4},
		{22,10,4},
		{23,11,4},
		{24,12,4},
		{25,13,4},
		{26,14,4},
		{27,2,5},
		{28,3,5},
		{29,4,5},
		{30,5,5},
		{31,6,5},
		{32,7,5},
		{33,8,5},
		{34,9,5},
		{35,10,5},
		{36,11,5},
		{37,12,5},
		{38,13,5},
		{39,14,5},
		{40,2,6},
		{41,3,6},
		{42,4,6},
		{43,5,6},
		{44,6,6},
		{45,7,6},
		{46,8,6},
		{47,9,6},
		{48,10,6},
		{49,11,6},
		{50,12,6},
		{51,13,6},
		{52,14,6}};


		srand (time(NULL));

		
//Generation de nombres alatoires unique		
		for(i=0;i<=51;i++)
		{
			exists=1;
			if (i==0)
			{
				paquet[i]=rand() % 52;
			}
			else
			{
				while (exists == 1)
				{	
					var=rand() % 52;
					exists= 0;
					for(j=0; j<=i && exists== 0 ;j++)
					{
						if(paquet[j]==var)
						{
							exists=1;
						}  
					}
				} 
				paquet[i]=var;
			}
		}
//Repartition des Cartes en 2 paquets
		//paquet 1
		for (a = 0 ; a<=51; a++)
		{
			if (a<26)
			{
				deck1[a] = paquet[a];
				//printf("deck 1 :%d\n", deck1[a]);
			}
			else
			{
				deck1[a]=99;
			}
		}
		//paquet 2
		for (b = 0 ; b<=51; b++)
		{
			if(b<26)
			{
				deck2[b]=paquet[b+26];
				//printf("deck 2 :%d\n", deck2[b]);
			}
			else
			{

				deck2[b]=99;
				//printf("%d",deck2[b]);
			}
		}

		printf("demarrage du jeu de bataille.\n\n");
		printf("\n\nveuillez appuyer sur une touche pour jouer une  carte\n\n");
		getch();
		do
		{
			// affichage des deux Deck
			//printf("\n \n \n");
			//for (i = 0 ; i <= 51 ; i++)
			//	{
			//	  printf("  %d  %d \n",deck1[i],deck2[i]);
			//	 }
			//
			//getch();

			// Reinit compteur lecture tableau
			k=0;

			//cas ou deck1 est plus petit que deck 2
			if (Cartes[deck1[k]][1] < Cartes[deck2[k]][1])
				{
					printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
					printf("|       |    |      |\n");
					printf("|       |    |      |\n");
					printf("|  %2d%1c  |    |  %2d%1c |\n",Cartes[deck1[k]][1],Cartes[deck1[k]][2],Cartes[deck2[k]][1],Cartes[deck2[k]][2]);
					printf("|       |    |      |\n");
					printf("|       |    |      |\n");
					printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
                    printf("la carte du joueur 2 est plus grande ");
					getch();
					system("cls");
					var_temp = deck2[0];

					for (i=0;deck2[i]!=99;i++)
						{
							deck2[i] = deck2[i+1];
							var_position = i;
						}

					deck2[var_position] = deck1[0];
					deck2[var_position+1] = var_temp;

					for (i=0;deck1[i]!=99;i++)
						{
							deck1[i] = deck1[i+1];
							var_position = i;
						}
					deck1[var_position] = 99;
				}
			//cas ou deck1 est plus grand
			else if (Cartes[deck1[k]][1] > Cartes[deck2[k]][1])
				{
                    printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
					printf("|       |    |      |\n");
					printf("|       |    |      |\n");
					printf("|  %2d%1c  |    |  %2d%1c |\n",Cartes[deck1[k]][1],Cartes[deck1[k]][2],Cartes[deck2[k]][1],Cartes[deck2[k]][2]);
					printf("|       |    |      |\n");
					printf("|       |    |      |\n");
					printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
                    printf("la carte du joueur 1 est plus grande ");
					getch();
					system("cls");
					var_temp = deck1[0];

					for (i=0;deck1[i]!=99;i++)
						{
							deck1[i] = deck1[i+1];	
							var_position = i;
						}


					deck1[var_position] = deck2[0];
					deck1[var_position+1] = var_temp;

					for (i=0;deck2[i]!=99;i++)
						{
							deck2[i] = deck2[i+1];
							var_position = i;
						}
					deck2[var_position] = 99;
				}
            //cas d'egalite
			else if (Cartes[deck1[k]][1] == Cartes[deck2[k]][1])
				{
					printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
					printf("|       |    |      |\n");
					printf("|       |    |      |\n");
					printf("|  %2d%1c  |    |  %2d%1c |\n",Cartes[deck1[k]][1],Cartes[deck1[k]][2],Cartes[deck2[k]][1],Cartes[deck2[k]][2]);
					printf("|       |    |      |\n");
					printf("|       |    |      |\n");
					printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
                    printf("egalite des cartes,veuillez appuyer pour poser vos cartes dessus\n\n");
					getch();
					system("cls");
					egalite = 1;
					while (egalite == 1 && Cartes[deck1[k]][1] == Cartes[deck2[k]][1])
						{
							//cas ou aucun jouer n'a de cartes
							if (deck2[k+2] == 99 && deck1[k+2] == 99)
								{
									printf("Aucun des joueurs n'a encore de cartes dans son Deck\n\n");
									egalite = 4;									
								}
							//cas ou le jouer 1 n'a plus de carte
							else if (deck1[k+2] == 99 && deck2[k+2] != 99)
								{
									printf("le joueur 1 n'a plus de cartes dans son deck\n\n");	
									egalite = 2;
								}
							//cas ou le joueur 2 n'a plus de cartes
							else if (deck2[k+2] == 99 && deck1[k+2] != 99)
								{
									printf("le joueur 2 n'a plus de cartes dans son deck\n\n");
									egalite = 3;
								}
							//cas ou deck2 est plus grand
							else if (Cartes[deck1[k+2]][1] < Cartes[deck2[k+2]][1])
								{
									printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
									printf("|       |    |      |\n");
									printf("|       |    |      |\n");
									printf("|  %2d%1c  |    |  %2d%1c |\n",Cartes[deck1[k+2]][1],Cartes[deck1[k+2]][2],Cartes[deck2[k+2]][1],Cartes[deck2[k+2]][2]);
									printf("|       |    |      |\n");
									printf("|       |    |      |\n");
									printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
									printf("la carte du joueur 2 et plus grande que celle du joueur 1");
									getch();
									system("cls");
									egalite = 5;
									k=k+2;

									for(i=0;i<=k;i++)
									{
									  var_temp = deck2[0];
										for (j=0;deck2[j]!=99;j++)
										{
											deck2[j] = deck2[j+1];
											var_position = j;
										}
									deck2[var_position] = deck1[i];
									deck2[var_position+1] = var_temp;
									}
									for(i=0;i<=k;i++)
									{
										for (l=0;deck1[l]!=99;l++)
										{
											deck1[l] = deck1[l+1];
											var_position = l;
										}
									}
									deck1[var_position] = 99;
							
								}
							//cas ou deck1 est plus grand
							else if (Cartes[deck1[k+2]][1] > Cartes[deck2[k+2]][1])
								{
								printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
								printf("|       |    |      |\n");
								printf("|       |    |      |\n");
								printf("|  %2d%1c  |    |  %2d%1c |\n",Cartes[deck1[k+2]][1],Cartes[deck1[k+2]][2],Cartes[deck2[k+2]][1],Cartes[deck2[k+2]][2]);
								printf("|       |    |      |\n");
								printf("|       |    |      |\n");
								printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
								printf("la carte du joueur 1 et plus grande que celle du joueur 2");
								getch();
								system("cls");
									egalite = 6;
									k=k+2;
									for(i=0;i<=k;i++)
									{
									  var_temp = deck1[0];

										for (j=0;deck1[j]!=99;j++)
										{
											deck1[j] = deck1[j+1];
											var_position = j;
										}
									deck1[var_position] = deck2[i];
									deck1[var_position+1] = var_temp;
									}
									for(i=0;i<=k;i++)
									{
										for (l=0;deck2[l]!=99;l++)
										{
											deck2[l] = deck2[l+1];
											var_position = l;
										}
									}
									deck2[var_position] = 99;

								}
							//cas ou ils sont toujours egaux
							else if (Cartes[deck1[k+2]][1] == Cartes[deck2[k+2]][1])
								{
									printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
									printf("|       |    |      |\n");
									printf("|       |    |      |\n");
									printf("|  %2d%1c  |    |  %2d%1c |\n",Cartes[deck1[k+2]][1],Cartes[deck1[k+2]][2],Cartes[deck2[k+2]][1],Cartes[deck2[k+2]][2]);
									printf("|       |    |      |\n");
									printf("|       |    |      |\n");
									printf("  %c %c %c       %c %c %c \n",196,196,196,196,196,196);
									printf("Il y a toujours egalite entre les deux cartes, remise de deux cartes\n\n");
									getch();
									system("cls");
									egalite = 1;
									k = k+2;
								}
						}
					
						printf(" Fin de la gestion du cas d egalite\n\n");
						getch();

				}
				printf("\n\nveuillez appuyer sur une touche pour jouer une  carte\n\n");
			    getch();
		}
		while(deck1[0] != 99 && deck2[0] != 99);

		//fin de la partie

        printf("\n\nFin de la partie\n\n");	
		if (egalite == 4)	
			{ 
				printf("Aucun joueur ne gagne car plus de carte dans leur deck");	
			}
		else if (deck1[0] == 99 || egalite == 2)	
			{ 
				printf("Joueur 2 a gagne\n");	
			}
		else if (deck2[0] == 99 || egalite == 3)	
			{
				printf("Joueur 1 a gagne\n");	
			}

			getch();
			printf("merci d'avoir jouer.Veuillez appuyer pour quitter le programme. ");


		} // end of program