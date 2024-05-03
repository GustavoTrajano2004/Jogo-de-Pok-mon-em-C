#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

int num;

typedef struct{ 		//Estrutura dos Pok�mons
	char nome [100];
	int vida;
	int vidamaxima;
	int forca;
	int nivel;
	char tipo[100];
	}pokemon;
	
typedef struct{ 		//Estrutura dos itens
	char tipo[100];
	int quant;
	}item;

typedef struct{ 		//Estrutura do jogador
	char nome [100];
	pokemon time[50];
	item mochila[2];
	int xp;
	}player;

typedef struct{		//Estrutura do jogador para o Ranking
	char nome [100];
	int xp;
}ran;

void menu(player *treinador, pokemon pokemons [15]);
void escolherpoke(player *treinador, pokemon pokemons [15]);
void mapa(player *treinador, pokemon pokemons[15]);
void regras(player *treinador, pokemon pokemons[15]);
void batalha(player *treinador, pokemon pokemons[15]);
void trocarpokemon (int *escolhido, player *treinador, pokemon pokemons[15], int posicao);
void ataque(int *escolhido, int pokerandom, player *treinador, pokemon pokemons[15], pokemon batalha [10]);
void cura (player *treinador, int *escolhido, int pokerandom, pokemon batalha [10]);
void pokebola (player *treinador, int *escolhido, int *a, int pokerandom, pokemon batalha [10], int posicao);
void ginasio(player *treinador, pokemon pokemons[15]);
void fimdejogo(player *treinador, pokemon pokemons[15]);
void fimdejogovitoria(player *treinador, pokemon pokemons[15]);
void ranking (player *treinador, pokemon pokemons[15]);


int main()

{	
	setlocale(LC_ALL,"Portuguese");
	int i=14, j=18;
	player treinador;		  //1							//2									//3										//4										//5										//6										//7									//8									//9									//10									//11									//12							//13								//14								//15
	pokemon pokemons [15]={{"Piplup", 92, 92, 16, 2,"�gua"},{"Mew", 93, 93, 10, 1, "Ps�quico"},{"Caterpie", 74, 74, 12, 3, "Inseto"},{"Pichu", 120, 120, 17, 4, "El�trico"},{"Persian", 150, 150, 15, 3, "Normal"},{"Charmander", 80, 80, 23, 2, "Fogo"},{"Squirtle", 93, 93, 17, 1, "�gua"},{"Weedle", 87, 87, 13, 3, "Inseto"},{"Sandshrew", 72, 72, 32, 5, "Terra"},{"Bulbassauro", 81, 81, 15, 2, "Planta"},{"Chikorita", 78, 78, 18, 4, "Grama"},{"Sniv", 86, 86, 12, 1, "Grama"},{"Totodile", 75, 75, 23, 2, "�gua"},{"Torchic", 108, 108, 21, 5, "Fogo"},{"Fennekin", 96, 96, 14, 4, "Fogo"}};
	
	menu(&treinador, pokemons);
	mapa(&treinador, pokemons);
	return 0;
}

void menu(player *treinador, pokemon pokemons [15]){ //Definindo o menu
	
	setlocale(LC_ALL,"Portuguese");
	
	//Tela de carregamento
	
	/*printf("Carregando");
	sleep(3);
		system("cls");
	printf("Carregando.");
	sleep(1);
		system("cls");	
	printf("Carregando..");
	sleep(1);
		system("cls");
	printf("Carregando...");
	sleep(1);
		system("cls");	
		printf("Seja bem vindo ao Pok�mon: Arena T�tica");
		sleep(5);
			system("cls");
	printf("Se prepare");	
	sleep(2);
		system("cls");
	printf("Se prepare pois aqui voc�");	
	sleep(2);
		system("cls");
	printf("Se prepare pois aqui voc� enfrentar� os seus maiores");	
	sleep(2);
		system("cls");
	printf("Se prepare pois aqui voc� enfrentar� os seus maiores INIMIGOS!");	
	sleep(3);
		system("cls");
	printf("Prepare-se para se tornar");	
	sleep(2);
		system("cls");
	printf("Prepare-se para se tornar um MESTRE POK�MON!");	
	sleep(3);*/
		system("cls");
		
	//Menu principal
	printf("	\tPok�mon: Arena T�tica\n\n\n\n");
	printf("	\tMenu Principal\n\n");
	printf("\t1- Iniciar Jogo\n");
	printf("\t2- Regras de Jogo\n");
	printf("\t3- Ranking\n");
	printf("\t4- Sair\n");
	printf("\n\tEscolha a op��o desejada: \n");
	scanf("%d", &num);
	fflush(stdin);
	switch(num)
	{
		case 1: //Iniciando a gameplay
			system("cls");
			printf("Iniciando o Jogo...\n");
			sleep(2);
			system("cls");
				
				printf("Treinador(a), qual � o seu nome?\n\n");
				scanf("%s", (*treinador).nome);
				fflush(stdin);
				printf("\nSeja bem-vindo(a), treinador(a) %s\n", (*treinador).nome);
				sleep(2);
				system("cls");
				escolherpoke(treinador, pokemons);
				break;
				
		
		case 2: //Abrindo o Manual de regras
			system("cls");
			printf("Acessando o manual de regras...\n");
			sleep(2);
			system("cls");
			regras(treinador, pokemons);
			break;
			
		case 3: // Acessando o Ranking
			system("cls");
			printf("Acessando o Ranking...\n");
			ranking (treinador, pokemons);
			break;
			
		case 4: // Saindo do Jogo
			printf("Saindo do Jogo...\n");	
			sleep(2);
			exit(0);
	}
	system("pause");
	
}

void regras(player *treinador, pokemon pokemons[15]){

	int r;
	int i;
	
	printf("\n\t*****MANUAL DE REGRAS*****\n\n");
	sleep(1);
	printf("\n\n\tSeja bem vindo ao Pok�mon: Arena T�tica!\n\n");
	sleep(2);
	printf("\tAqui, voc� explorar� um lugar repleto de Pok�mons, criaturas monstruosas e m�gicas que lutam entre s� em nome de um(a) treinador(a).\n\n");
	sleep(3);
	printf("\tInicialmente, ap�s o(a) jogador(a) informar seu nome, deve-se escolher 3 entre 15 Pok�mons na tela para poder ser redirecionado para o mapa.\n\n");
	sleep(3);
	printf("\tNo mapa, percebe-se que o(a) jogador(a) ter� a oportunidade de identificar os Pok�mons selecionados em sua interface pessoal.\n\n");
	sleep(2);
	printf("\tN�o s� isso, tamb�m � observ�vel que o(a) jogador(a) iniciar� possuindo 1 Pok�bola e 2 Po��es em seu invent�rio!\n\n");
	sleep(3);
	printf("\tTendo ci�ncia disso, o(a) jogador(a) dever� entrar em matos (representados pelo caractere 'X') para ter a oportunidade de coletar mais itens.\n\n");
	sleep(3);
	printf("\tTendo a oportunidade de coletar novos itens, o(a) jogador(a), atrav�s dos matos, tamb�m poder� ser redirecionado para uma batalha com um Pok�mon selvagem.\n\n");
	sleep(2);
	printf("\tSer� necess�rio que se ven�a ou capture o Pok�mon selvagem para que o(a) jogador(a) possa ter mais chances de vencer na batalha final.\n\n");
	sleep(3);
	printf("\tAp�s conseguir novos Pok�mons e/ou a evolu��o dos selecionados pelo(a) jogador(a), ser� necess�rio entrar no gin�sio para que se enfrente o grande chef�o final!\n\n");
	sleep(3);
	printf("\tSe o(a) jogador(a) vencer, ele(a) finalmente se tornar� o(a) MESTRE POK�MON! Por�m, se perder, ele(a) ter� a oportunidade de retornar para o menu principal e tentar novamente.\n\n");
	sleep(4);
	printf("\n\n\n\n\tVoc� deseja:\n\n");
	printf("\t1 - Ir para o menu principal.\n\n");
	printf("\t2 - Sair do jogo.\n\n");
	
	scanf("%d",&r);
	
	switch(r){
	
		case 1:
			printf("\tRedirecionando para o menu principal...");
			sleep(2);
			system ("cls");
			menu(treinador, pokemons);
			break;
			
		case 2:
			printf("\tSaindo do jogo...");
			sleep(2);
			exit(0);
			break;
	
		default: i--; 
			printf("Tecla inv�lida!\n") ;
			break;
	}
}

void ranking(player *treinador, pokemon pokemons[15]){
	
	int x;
	FILE *f;
	ran treinadores [100];
	ran aux [100];
	
	int cont = 0, xp;
	
	f = fopen ("ranking.txt", "r");
	
	
	while (fscanf(f,"%s %d", (*treinador).nome, &(*treinador).xp)!= -1){
		strcpy(treinadores[cont].nome, (*treinador).nome);
		treinadores[cont].xp = (*treinador).xp;
		cont++;
	}
	
	int i, j;

	
	for ( i = 0; i < cont; i++) {
    	for ( j = 0; j < i; j++) {
	        if (treinadores[i].xp > treinadores[j].xp) {
				aux [i] = treinadores[i];
	 			treinadores[i] = treinadores[j];
	  			treinadores[j] = aux [i];
	        }
	    }
	}
	
	system("cls");

	printf ("\t \t   RANKING \n");

	printf ("______________________________________________\n \n");
	
	
	for ( i = 0; i < cont; i++) { 
	printf ("\n%d� - Nome: %s - Pontua��o: %d\n", i+1, treinadores[i].nome, treinadores[i].xp);
	}
	fclose (f);
	
	printf("\n\n\n\n\n\n\n\n\tDigite 1 para retornar ao menu principal!");
	
	scanf("%d", &x);
	
	switch(x){
		
		case 1:
			system("cls");
			sleep(1);
			printf("Carregando...");
			system("cls");
			menu(treinador, pokemons);
			break;
		
	}
	
}

void escolherpoke(player *treinador, pokemon pokemons[15]){ 
 	//O Jogador escolher� os Pok�mons para formar a sua equipe
	int i;
	int x;
	int u;
	printf("\nEscolha 3 Pok�mons!\n\n");
	for (i = 0; i<15; i++){
		printf ("\n [%i] - %s", i+1, pokemons[i]);
		}
	printf("\n\n");			//Zerando a vida dos Pok�mons para evitar lixo de mem�ria (bugs)
	
	for(i = 0; i<3; i++){
		printf("Digite o n�mero correspondente ao %d� Pok�mon desejado: ", i+1);
	scanf("%d", &x);
	switch(x){		//Definindo os n�meros para escolher os Pok�mons
		
		case 1:			//Piplup
		(*treinador).time[i] = pokemons[0];			
			break;
			
		case 2:			//Mew
			(*treinador).time[i] = pokemons[1];
			break;
			
		case 3:			//Caterpie
			(*treinador).time[i] = pokemons[2];
			break;
			
		case 4:			//Pichu
			(*treinador).time[i] = pokemons[3];
			break;
			
		case 5:			//Persian
			(*treinador).time[i] = pokemons[4];
			break;
		
		case 6:			//Charmander
			(*treinador).time[i] = pokemons[5];
			break;
			
		case 7:			//Squirtle
			(*treinador).time[i] = pokemons[6];
			break;	
			
		case 8:			//Weedle
			(*treinador).time[i] = pokemons[7];
			break;
			
		case 9:			//Sandshrew
			(*treinador).time[i] = pokemons[8];
			break;
			
		case 10:		//Bulbassauro
			(*treinador).time[i] = pokemons[9];
			break;
			
		case 11:		//Chikorita
			(*treinador).time[i] = pokemons[10];
			break;
			
		case 12:		//Sniv
			(*treinador).time[i] = pokemons[11];
			break;
		
		case 13:		//Totodile
			(*treinador).time[i] = pokemons[12];
			break;
			
		case 14:		//Torchic
			(*treinador).time[i] = pokemons[13];
			break;
			
		case 15:		//Fennekin
			(*treinador).time[i] = pokemons[14];
			sleep (1);
			break;
			
		default: i--; 
			printf("Tecla inv�lida!\n") ;
			break;
		}
	}
	
	mapa(treinador, pokemons);
	
	
	}
	


void mapa(player *treinador, pokemon pokemons[15]){			//Definindo o mapa
	
	int i, j, linha = 14, coluna = 18;
	int m;
	int pn;
	int quantidadedepokemons = 3;
	int aleatorio = 1;
	char mov = 'm';
	char mapa[15][37] = {"____________________________________",
                    "|                       X          |",
                    "|   X     X    ________       X    |",
                    "|              |  G   |            |",
                    "|     X        |_    _|            |",
                    "|               |    |             |",
                    "|     X    X    |_  _|  X      X   |",
                    "|                                  |",
                    "|               X       X          |",
                    "|        X                 X       |",
                    "|   X              X               |",
                    "|                      X           |",
                    "|     X      X                X    |",
                    "|                         X        |",
                    "________________     _______________"};
        
        for (i=3; i<50; i++){
        (*treinador).time[i].vida=-20;	//Time de Pok�mons escolhidos pelo jogador na tela de sele��o
}
		(*treinador).mochila[0].quant=1; 	//Pokebola
		(*treinador).mochila[1].quant=2; 	//Po��o
		
		do{
			
			system("cls");
			for (i = 0; i<15; i++){
        	printf ("\n\n\n\t");
        	for (j = 0; j<37; j++){
        		if(i == linha && j == coluna) printf("O  ");	//O Jogador � representado pelo caractere "O" na matriz
        		else printf("%c  ", mapa[i][j]);
			}
		}     	//Interface do jogador (Nomo do jogador, pokemons escolhidos e mochila)
        	printf("\n\tNome do(a) treinador(a): %s", (*treinador).nome); //Interface mostrando o nome do jogador
        	printf("\n\tPok�mons do(a) Treinador(a): "); //Interface dos Pok�mons do jogador
        	for (i=0; i<50; i++){
        		if((*treinador).time[i].vida>0){
        			printf("\n\t- %s", (*treinador).time[i]);
				}
			}
			printf("\n\tPok�bolas: %d\n\tPo��es: %d", (*treinador).mochila[0].quant, (*treinador).mochila[1].quant); //Interface da mochila
			
			printf("\n\n\tMovimento: "); //Definindo o Movimento
        	mov = getch ();
        	fflush(stdin);
        	
        	//Movimenta��o do jogador no mapa
        	switch(mov){ 
        		
        		case 'w': //Tecla W para subir na matriz
        			if(mapa[linha-1][coluna]=='_'|| mapa[linha-1][coluna] == '|'){
					}else{							
					linha--;
					}
					
					if(mapa[linha][coluna]=='X'){	//Se o jogador passar na matrtriz...
					srand( time(NULL) ); 
						
						m = 1+rand()%4;
						if (m == 1){ 	//25% Nada acontecer�
						}
						if (m == 2){ 	//25% Ele conseguir� uma Pok�bola
							(*treinador).mochila[0].quant++; 
						}
						if (m == 3){ 	//25% Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
						if (m == 4){ 	//25% Ele encontrar� um Pok�mon selvagem
							
							batalha(treinador, pokemons);
					}	
				}
				
				 if(mapa[linha][coluna]=='G'){
				 	
					ginasio(treinador, pokemons);
				
				 }
        			break;
        			
        		case 's':	//Tecla S para descer na matriz
        			if(mapa[linha+1][coluna]=='_' || mapa[linha+1][coluna] == '|'){
					}else{		
					linha++;
					}
					
					if(mapa[linha][coluna]=='X'){ 	//Se o jogador passar na matrtriz...
						m = 1+rand()%5;
						if (m == 1){ 	// Nada acontecer�
						}
						if (m == 2){ 	// Ele conseguir� uma Pok�bola
							(*treinador).mochila[0].quant++; 
						}
						if (m == 3){ 	// Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
						if (m == 4){ 	// Ele encontrar� um Pok�mon selvagem
							
							batalha(treinador, pokemons);
							
						}
						
						if (m == 5){ 	//25% Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
						
						if (m == 6){ 	//25% Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
					}
					
					if(mapa[linha][coluna]=='G'){
				 	
					ginasio(treinador, pokemons);
				
				 }
					
        			break;
        			
        		case 'a':	//Tecla A para andar para a esquerda na matriz
        			if(mapa[linha][coluna-1]=='_' || mapa[linha][coluna-1] == '|'){
					}else{		
					coluna--;
					}
					
					if(mapa[linha][coluna]=='X'){ 	//Se o jogador passar na matrtriz...
						m = 1+rand()%5;
						if (m == 1){ 	// Nada acontecer�
						}
						if (m == 2){ 	// Ele conseguir� uma Pok�bola
							(*treinador).mochila[0].quant++; 
						}
						if (m == 3){ 	// Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
						if (m == 4){ 	// Ele encontrar� um Pok�mon selvagem
							
							batalha(treinador, pokemons);
							
						}
						
						if (m == 5){ 	//25% Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
						
						if (m == 6){ 	//25% Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
					}
					
					if(mapa[linha][coluna]=='G'){
				 	
					ginasio(treinador, pokemons);
				
				 }
					
        			break;
        			
        		case 'd':	//Tecla D para andar para a direita na matriz
        			if(mapa[linha][coluna+1]=='_' || mapa[linha][coluna+1] == '|')	{
					}else{	
					coluna++;
					}
					
					if(mapa[linha][coluna]=='X'){ 	//Se o jogador passar na matrtriz...
						m = 1+rand()%5;
						if (m == 1){ 	// Nada acontecer�
						}
						if (m == 2){ 	// Ele conseguir� uma Pok�bola
							(*treinador).mochila[0].quant++; 
						}
						if (m == 3){ 	// Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
						if (m == 4){ 	// Ele encontrar� um Pok�mon selvagem
							
							batalha(treinador, pokemons);
							
						}
						
						if (m == 5){ 	//25% Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
						
						if (m == 6){ 	//25% Ele conseguir� uma po��o
							(*treinador).mochila[1].quant++;
						}
					}
					
					if(mapa[linha][coluna]=='G'){
				 	
					ginasio(treinador, pokemons);
				
				 }
					
        			break;
        			
        			
        		default:
        			printf("\n\tTecla inv�lida!");		//Caso o jogador aperte uma tecla que n�o seja W, A, S, D, aparecer� uma mensagem indicando que a tecla escolhida � inv�lida!
        			sleep(1);
        		
			}
			
		} while(num == 1);                             	
}

void batalha (player *treinador, pokemon pokemons[15]){		//Batalha de Pok�mons
	
	int i;
	int cont = 0;
	int posicao = 0;
	int pokerandom, escolhido;
	int z;
	int a = 1;
	srand( time(NULL) );
	pokerandom = rand()%10;
	
	for (i = 0; i < 50; i++){
        
    if ((*treinador).time[i].vida > 0){
    posicao++;
        }
    }
							
								//1										//2										//3									//4											//5									//6										//7									//8										//9									//10 
	pokemon batalha [10]={{"Ivyssauro", 110, 110, 25, 6,"Planta"},{"Charmeleon", 107, 107, 19, 7, "Fogo"},{"Wartotle", 127, 127, 23, 9, "�gua"},{"Pikachu", 150, 150, 21, 7, "El�trico"},{"Sandslash", 134, 134, 27, 8, "Terra"},{"Metapod", 90, 90, 32, 6, "Inseto"},{"Kakuna", 118, 118, 22, 7, "Inseto"},{"Meowth", 124, 124, 27, 7, "Normal"},{"Graveler", 98, 98, 42, 6, "Terra"},{"Pidgeotto", 131, 131, 27, 8, "Normal"}};
		
		trocarpokemon (&escolhido, treinador, pokemons, posicao);
	
	while(a == 1){
	if((*treinador).time[escolhido].vida>0 && batalha[pokerandom].vida>0)
		{
			
			
	system("cls");
	
	printf("\n\t\t\t 	 *****Zona de Guerra*****\n\n");
	printf("\tPok�mon: %s			  VS			Pok�mon: %s\n", (*treinador).time[escolhido].nome, batalha[pokerandom].nome);
	printf("\tVida: %d							Vida: %d\n", (*treinador).time[escolhido].vida, batalha[pokerandom].vida);
	printf("\tFor�a: %d							For�a: %d\n", (*treinador).time[escolhido].forca, batalha[pokerandom].forca);
	printf("\tN�vel: %d							N�vel: %d\n", (*treinador).time[escolhido].nivel, batalha[pokerandom].nivel);
	printf("\tTipo: %s							Tipo: %s\n\n", (*treinador).time[escolhido].tipo, batalha[pokerandom].tipo);
	printf("\t_______________________________________________________________________________\n\n");
	printf("\t1 - Atacar\n");
	printf("\t2 - Capturar\n");
	printf("\t3 - Trocar Pok�mon\n");
	printf("\t4 - Curar\n");
	printf("\t5 - Fugir\n");
	printf("\n\n\n\tPok�bola: %d", (*treinador).mochila[0].quant);
	printf("\n\tPo��o: %d\n\n", (*treinador).mochila[1].quant);
	printf("\t");
	
	scanf("%d", &z);
	
		switch(z){
		
			case 1:
				ataque(&escolhido, pokerandom, treinador, pokemons, batalha);
				break;
		
			case 2:
				pokebola (treinador, &escolhido, &a, pokerandom, batalha, posicao);
				break;
			
			case 3:
				trocarpokemon(&escolhido, treinador, pokemons, posicao);
				break;
			
			case 4:
				cura (treinador, &escolhido, pokerandom, batalha);
				break;
			
			case 5:
				
				printf("\n\n\t********** Voc� fugiu da batalha! **********");
				sleep (2);
				a = 2;
				break;
			
			default:
				printf("\n\tTecla inv�lida!");
				sleep(1);
				}
		}else{
			if((*treinador).time[escolhido].vida>0 && batalha[pokerandom].vida<=0){ 		//Os Pok�mons sobem de n�vel
				printf("\n\n\tVoc� derrotou o seu oponente!\n\n");
				sleep(2);
				(*treinador).time[escolhido].vidamaxima+=45;
				(*treinador).time[escolhido].nivel++;
				(*treinador).time[escolhido].forca+=7;
				(*treinador).xp+=3;
				a = 2;
			}else{
				if((*treinador).time[escolhido].vida<=0 && batalha[pokerandom].vida>0){ 
				printf("\n\tO seu Pok�mon foi derrotado!\n\n");
				sleep(2);
				trocarpokemon(&escolhido, treinador, pokemons, posicao);
				
			}
		}
	} 
	
	}

}

void pokebola (player *treinador, int *escolhido, int *a, int pokerandom, pokemon batalha [10], int posicao){
    
    int x = 0, y = 0;
    srand(time(NULL));
       y = rand()%100;
    x = (batalha[pokerandom].vida/(*treinador).time[*escolhido].nivel);
    
    if ((*treinador).mochila[0].quant > 0){
    if (x < 50 && y > 85){
            printf ("\n\tParab�ns! Voc� capturou o %s!", batalha[pokerandom].nome);
            sleep (2);
            (*treinador).time[posicao] = batalha[pokerandom];
            (*treinador).mochila[0].quant--;
            *a = 2;
    }else{
        if (x < 10 && y > 10){
            printf ("\n\tParab�ns! Voc� capturou o %s!", batalha[pokerandom].nome);
            sleep (2);
            (*treinador).time[posicao] = batalha[pokerandom];
            (*treinador).mochila[0].quant--;
            *a = 2;
        }else{
            (*treinador).mochila[0].quant--;
            printf ("\n\tQue pena, voc� n�o conseguiu capturar o %s.", batalha[pokerandom].nome);
            sleep (2);
        }
    }
    }else{
        printf ("\n\tPok�bolas insuficientes para capturar o %s.", batalha[pokerandom].nome);
        sleep (2);
    }  
}


void trocarpokemon (int *escolhido, player *treinador, pokemon pokemons[15], int posicao){		//Troca de Pok�mon
	
	int contador = 0;
	int i;
	int u;
	
	system ("cls");
	
	for (i=0; i<posicao; i++){
		if((*treinador).time[i].vida>0){
			contador++;
		}
	}
	if(contador == 0)
	{
	
	fimdejogo(treinador,pokemons);
	
	}
	for (i=0; i<50; i++){
		if((*treinador).time[i].vida>0){
		
		
		
		
		printf("\t%d - %s - Vida: %d - For�a: %d - N�vel: %d - Tipo: %s\n\n", i+1, (*treinador).time[i].nome, (*treinador).time[i].vida, (*treinador).time[i].forca, (*treinador).time[i].nivel, (*treinador).time[i].tipo);
	}}
	
	scanf("%d", &u);
	*escolhido = u-1;
	(*treinador).time[*escolhido];
		
} 

void ataque(int *escolhido, int pokerandom, player *treinador, pokemon pokemons[15], pokemon batalha [10]){
	
	
	int m;
	srand( time(NULL) );
	int tapa1, bonus1;
	int tapa2, bonus2;
	tapa1 = 10+rand()%(*treinador).time[*escolhido].forca;
	tapa2 = 10+rand()%batalha[pokerandom].forca;
	m = 1+rand()%7;
	
	
	// Vantagens dos Tipos de cada Pok�mon
	
	bonus1 = tapa1+(tapa1*0.2);
	bonus2 = tapa2-(tapa2*0.2);
		/*||											Planta vs Terra														   ||					Planta vs Normal					*/
	if (strcmp((*treinador).time[*escolhido].tipo, batalha[0].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[4].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[7].tipo)==0)){
	
		(*treinador).time[*escolhido].vida-=bonus2;
		batalha[pokerandom].vida-=bonus1;
		
		if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}		
		
	}
		
	}else{
		
	
			/*||											Fogo vs Planta													   ||					Fogo vs Normal						||						Fogo vs Inseto					*/
	if (strcmp((*treinador).time[*escolhido].tipo, batalha[1].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[0].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[7].tipo)==0 ||strcmp(batalha[pokerandom].tipo, batalha[5].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;
	
	if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}	
		
	}
	
	}else{
	
	
				/*||											�gua vs Planta												  ||					�gua vs Fogo						||						�gua vs El�trico					*/
	if (strcmp((*treinador).time[*escolhido].tipo, batalha[2].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[0].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[1].tipo)==0 ||strcmp(batalha[pokerandom].tipo, batalha[3].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;
	
	if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}		
		
	}
	
	}else{
		
	
				/*||											El�trico vs Planta										      ||					El�trico vs Inseto						||						El�trico vs Normal					*/
	if (strcmp((*treinador).time[*escolhido].tipo, batalha[3].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[0].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[5].tipo)==0 ||strcmp(batalha[pokerandom].tipo, batalha[7].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;
	
	if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
						}
							
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}	
		
	}
	
	}else{
	
	
	/*||											Normal vs �gua										  					  ||					Normal vs Inseto					*/
	if (strcmp((*treinador).time[*escolhido].tipo, batalha[7].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[2].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[5].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;
	
	if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}	
		
	}
	
	}else{
	
		
		/*||											Inseto vs Planta										  		   	  ||					Inseto vs Terra						 */
	if (strcmp((*treinador).time[*escolhido].tipo, batalha[5].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[0].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[4].tipo)==0)){

		
	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;
		
		if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}		
		
	}
		
	}else{
	
	
			/*||											Terra vs El�trico										  		  ||					Terra vs Fogo					*/
	if (strcmp((*treinador).time[*escolhido].tipo, batalha[4].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[3].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[1].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;
	
	if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
							
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}		
		
	}
	
	}else{
	
	
				/*||											Ps�quico vs Fogo										  				||					Ps�quico vs Inseto					*/
	if (strcmp((*treinador).time[*escolhido].tipo, pokemons[1].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[1].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[5].tipo)==0)){

	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;

	if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}		
		
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}

	}else{
	
	
					/*||											Grama vs Planta										  				||					Grama vs Terra					*/
	if (strcmp((*treinador).time[*escolhido].tipo, pokemons[10].tipo)==0 &&(strcmp(batalha[pokerandom].tipo, batalha[0].tipo)==0 || strcmp(batalha[pokerandom].tipo, batalha[4].tipo)==0)){

	(*treinador).time[*escolhido].vida-=bonus2;
	batalha[pokerandom].vida-=bonus1;

	if(bonus2>=bonus1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}		
		
	}

	}else{
	



	// Vantagem do Pok�mon Selvagem
	
	
	
	
		/*||											Planta vs Terra												 ||					Planta vs Normal					*/
	if (strcmp(batalha[pokerandom].tipo, batalha[0].tipo)==0 &&(strcmp((*treinador).time[*escolhido].tipo, batalha[4].tipo)==0 || strcmp((*treinador).time[*escolhido].tipo, batalha[7].tipo)==0)){
	
		(*treinador).time[*escolhido].vida-=bonus1;
		batalha[pokerandom].vida-=bonus2;
		
		if(bonus1>=bonus2){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}		
		
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}
		
	}
		
	}else{

	
			/*||											Fogo vs Planta											 ||					Fogo vs Normal						   ||						Fogo vs Inseto					*/
	if (strcmp(batalha[pokerandom].tipo, batalha[1].tipo)==0 &&(strcmp((*treinador).time[*escolhido].tipo, batalha[0].tipo)==0 || strcmp((*treinador).time[*escolhido].tipo, batalha[7].tipo)==0 ||strcmp((*treinador).time[*escolhido].tipo, batalha[5].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus1;
	batalha[pokerandom].vida-=bonus2;
	
	if(bonus1>=bonus2){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}		
		
	}
	
	}else{
	
	
				/*||											�gua vs Planta										 ||					�gua vs Fogo						   ||						�gua vs El�trico					*/
	if (strcmp(batalha[pokerandom].tipo, batalha[2].tipo)==0 &&(strcmp((*treinador).time[*escolhido].tipo, batalha[0].tipo)==0 || strcmp((*treinador).time[*escolhido].tipo, batalha[1].tipo)==0 ||strcmp((*treinador).time[*escolhido].tipo, batalha[3].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus1;
	batalha[pokerandom].vida-=bonus2;
	
	if(bonus1>=bonus2){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}		
		
	}
	
	}else{
	
	
				/*||											El�trico vs Planta									 ||					El�trico vs Inseto					   ||						El�trico vs Normal					*/
	if (strcmp(batalha[pokerandom].tipo, batalha[3].tipo)==0 &&(strcmp((*treinador).time[*escolhido].tipo, batalha[0].tipo)==0 || strcmp((*treinador).time[*escolhido].tipo, batalha[5].tipo)==0 ||strcmp((*treinador).time[*escolhido].tipo, batalha[7].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus1;
	batalha[pokerandom].vida-=bonus2;
	
	if(bonus1>=bonus2){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
			
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}		
		
	}
	
	}else{
	
	
	/*||											Normal vs �gua										  			 ||					Normal vs Inseto					*/
	if (strcmp(batalha[pokerandom].tipo, batalha[7].tipo)==0 &&(strcmp((*treinador).time[*escolhido].tipo, batalha[2].tipo)==0 || strcmp((*treinador).time[*escolhido].tipo, batalha[5].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus1;
	batalha[pokerandom].vida-=bonus2;
	
	if(bonus1>=bonus2){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}	
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}	
		
	}
	
	}else{
	
		
		/*||											Inseto vs Planta										  	 ||					Inseto vs Terra						 */
	if (strcmp(batalha[pokerandom].tipo, batalha[5].tipo)==0 &&(strcmp((*treinador).time[*escolhido].tipo, batalha[0].tipo)==0 || strcmp((*treinador).time[*escolhido].tipo, batalha[4].tipo)==0)){
		
	(*treinador).time[*escolhido].vida-=bonus1;
	batalha[pokerandom].vida-=bonus2;
	
	if(bonus1>=bonus2){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}	
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}	
		
	}
		
	}else{
	
	
			/*||											Terra vs El�trico										 ||					Terra vs Fogo					*/
	if (strcmp(batalha[pokerandom].tipo, batalha[4].tipo)==0 &&(strcmp((*treinador).time[*escolhido].tipo, batalha[3].tipo)==0 || strcmp((*treinador).time[*escolhido].tipo, batalha[1].tipo)==0)){
	
	(*treinador).time[*escolhido].vida-=bonus1;
	batalha[pokerandom].vida-=bonus2;
	
	if(bonus1>=bonus2){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}		
		
	}
	
	}else{		//Se n�o tiver essas condi��es, o ataque n�o ter� vantagem
	(*treinador).time[*escolhido].vida-=tapa2;
	batalha[pokerandom].vida-=tapa1;
	}
	
	if(tapa2>=tapa1){
		
			if (m == 1){
		
				printf("\n\t %s tomou uma sova!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
						
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", (*treinador).time[*escolhido].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", (*treinador).time[*escolhido].nome);
				sleep(2);
						}
		
	}else{
		
		if (m == 1){
		
				printf("\n\t %s tomou uma sova!", batalha[pokerandom].nome);
				sleep (2);
						}
										
			if ( m == 2){
			
				printf("\n\t %s levou um sopapo!", batalha[pokerandom].nome);
				sleep (2);
						}
		
			if ( m == 3){
			
				printf("\n\t %s apanhou feio!", batalha[pokerandom].nome);
				sleep(2);
						}
		
			if (m == 4){
			
				printf("\n\t %s foi maltratado!", batalha[pokerandom].nome);
				sleep(2);
	
						}
						
			if (m == 5){
			
				printf("\n\t %s foi obliterado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 6){
			
				printf("\n\t %s tomou uma surra!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 7){
			
				printf("\n\t %s foi judiado!", batalha[pokerandom].nome);
				sleep(2);
						}
						
			if (m == 8){
			
				printf("\n\t %s tomou um sacode!", batalha[pokerandom].nome);
				sleep(2);
						}					
		
	}


	}}}}}}}}}}}}}}}
}

void cura (player *treinador, int *escolhido, int pokerandom, pokemon batalha [10]){
    
    int x, cura = 0;
    x = (*treinador).time[*escolhido].vidamaxima - (*treinador).time[*escolhido].vida;
    srand(time(NULL));
    
    if ((*treinador).mochila[1].quant > 0 && (*treinador).time[*escolhido].vida != (*treinador).time[*escolhido].vidamaxima){
        cura = 1+rand()%x;
        (*treinador).time[*escolhido].vida += cura;
        (*treinador).mochila[1].quant--;
        printf ("\n\t%s regenerou %d de vida utilizando a po��o.", (*treinador).time[*escolhido].nome, cura);
        sleep (2);
    }else{
        if ((*treinador).mochila[1].quant >= 0 && (*treinador).time[*escolhido].vida == (*treinador).time[*escolhido].vidamaxima){
                    printf ("\n\tO seu Pok�mon est� totalmente saud�vel!");
                    sleep (1);
        }else{
        printf ("\n\tSuas po��es de cura acabaram!");
        sleep (2);
    }
}
}
      
void ginasio(player *treinador, pokemon pokemons[15]){
	
	int i;
	int cont = 0;
	int contador = 0;
	int posicao = 0;
	int pokerandom, escolhido;
	int z;
	int a = 1;
	srand( time(NULL) );
	pokerandom = rand()%4;
	
	for (i = 0; i < 50; i++){
        
    if ((*treinador).time[i].vida > 0){
    posicao++;
        }
    }
							
								//1										//2										//3									//4											//5									//6										//7									//8										//9									//10 
	pokemon batalha [4]={{"Charizard", 400, 400, 45, 10,"Fogo"},{"Raichu", 300, 300, 57, 14, "El�trico"},{"Beedrill", 200, 200, 62, 18, "Inseto"},{"Venussauro", 500, 500, 68, 20, "Planta"}};
		
		trocarpokemon (&escolhido, treinador, pokemons, posicao);
	
	system("cls");
	printf("Carregando...");
	sleep(1);
	system ("cls");
	printf("\n - Jessie: Veja s� quem est� aqui, se n�o � o(a) %s!\n", (*treinador).nome);
	sleep(5);
	printf("\n - James: Mais um(a) perdedor(a)!");
	sleep(5);
	printf("\n\n - %s: Hoje ser� o dia da minha grande vit�ria!", (*treinador).nome);
	sleep(6);
	printf("\n\n - Jessie: Isso nunca! Voc� jamais se tornar� um(a) MESTRE POK�MON!");
	sleep(6);
	printf("\n\n - %s: Talvez seja verdade, ou ainda outro engano, de qualquer modo, te enfrentarei com toda a minha for�a!", (*treinador).nome);
	sleep(6);
	
	system("cls");
	
	sleep(1);
	printf("Carregando...");
	sleep(1);
	
	while(a == 1){
	if((*treinador).time[escolhido].vida>0 && batalha[pokerandom].vida>0)
		{
			
			
	system("cls");
	
	
	
	printf("\n\t\t\t 	    *****Gin�sio*****\n\n");
	printf("\tPok�mon: %s			  VS			Pok�mon: %s\n", (*treinador).time[escolhido].nome, batalha[pokerandom].nome);
	printf("\tVida: %d							Vida: %d\n", (*treinador).time[escolhido].vida, batalha[pokerandom].vida);
	printf("\tFor�a: %d							For�a: %d\n", (*treinador).time[escolhido].forca, batalha[pokerandom].forca);
	printf("\tN�vel: %d							N�vel: %d\n", (*treinador).time[escolhido].nivel, batalha[pokerandom].nivel);
	printf("\tTipo: %s							Tipo: %s\n\n", (*treinador).time[escolhido].tipo, batalha[pokerandom].tipo);
	printf("\t_______________________________________________________________________________\n\n");
	printf("\t1 - Atacar\n");
	printf("\t2 - Trocar Pok�mon\n");
	printf("\t3 - Curar\n");
	printf("\n\tPo��o: %d\n\n", (*treinador).mochila[1].quant);
	printf("\t");
	
	scanf("%d", &z);
	
		switch(z){
		
			case 1:
				ataque(&escolhido, pokerandom, treinador, pokemons, batalha);
				break;
		
			case 2:
				trocarpokemon(&escolhido, treinador, pokemons, posicao);
				break;
			
			case 3:
				cura (treinador, &escolhido, pokerandom, batalha);
				break;
			
			default:
				printf("\n\tTecla inv�lida!");
				sleep(1);
				}
		}else{
			if((*treinador).time[escolhido].vida>0 && batalha[pokerandom].vida<=0){ 	
			
			for (i = 0; i < 4; i++){ if(batalha[i].vida > 0){ pokerandom= i; }}
			
				//Os Pok�mons sobem de n�vel
				printf("\n\n\tVoc� derrotou o seu oponente!\n\n");
				sleep(2);
				(*treinador).time[escolhido].vidamaxima+=45;
				(*treinador).time[escolhido].nivel++;
				(*treinador).time[escolhido].forca+=7;
				contador++;
			}else{
				if((*treinador).time[escolhido].vida<=0 && batalha[pokerandom].vida>0){ 
				printf("\n\tO seu Pok�mon foi derrotado!\n\n");
				sleep(2);
				trocarpokemon(&escolhido, treinador, pokemons, posicao);
				
			}
		}
		if (contador == 4){
			a = 0;
			fimdejogovitoria(treinador, pokemons);
			
		}
	} 
	
	}	
	
	} 


      
void fimdejogo (player *treinador, pokemon pokemons[15]){		//Fim de jogo
	
	int x;
	
	FILE *f;
	
	f = fopen ("ranking.txt", "a+");
	fprintf (f, "%s %d\n", (*treinador).nome, (*treinador).xp);
	fclose (f);
	
	system("cls");
	printf("\t**********VOC� PERDEU!**********\n");
	sleep(2);
	
	printf("\n\n\t1 - Menu Principal");
	printf("\n\n\t2- Sair do Jogo\n\n");
	scanf("%d", &x);
	switch(x){
		
		case 1:
			
			printf("\n\n\tRetornando para o Menu Principal...");
			sleep(2);
			system ("cls");
			menu(treinador, pokemons);
			break;
			
		case 2:
			printf("\n\n\tSaindo do jogo...");
			sleep(2);
			exit(0);
			break;
			
	
	}


} 

void fimdejogovitoria(player *treinador, pokemon pokemons[15]){
	
	
	int r;
	int i;
	FILE *f;
	
	f = fopen ("ranking.txt", "a+");
	fprintf (f, "%s %d\n", (*treinador).nome, (*treinador).xp);
	fclose (f);
	
	system ("cls");
	printf("\n - Jessie: N�o, imposs�vel! Como o(a) %s p�de nos derrotar?", (*treinador).nome);
	sleep(3);
	printf("\n\n - James: Isso � inacredit�vel!");
	sleep(3);
	printf("\n\n - Jessie: Nos encontraremos novamente, e retornaremos mais fortes do que nunca!");
	sleep(3);
	printf("\n\n - %s: Ainda h� esperan�a.", (*treinador).nome);
	sleep(5);
	system("cls");
	printf("Carregando...");
	system("cls");
	sleep(1);
	printf("\n\t**********Parab�ns, voc� se tornou um(a) MESTRE POK�MON!!!**********\n\n\n");
	sleep(2);
	printf("\t1 - Retornar ao Menu Principal\n\n");
	printf("\t2 - Sair do Jogo\n\n");
	
	scanf("%d",&r);
	
	switch(r){
	
		case 1:
			printf("\tRedirecionando para o menu principal...");
			sleep(2);
			system ("cls");
			menu(treinador, pokemons);
			break;
			
		case 2:
			printf("\tSaindo do jogo...");
			sleep(2);
			exit(0);
			break;
	
	
}
}
      
      
