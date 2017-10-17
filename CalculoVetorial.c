#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vetor
{
	int x;
	int y;
	int z;
	int R3; //define se o vetor é R2 ou R3. se R3 == 1, é um R3, se for 0, é um R2.
}Vetor;

Vetor* novo(int);

bool R3(Vetor*);
float modulo(Vetor*);
void orientacao(Vetor*);
void CalculaVetor(Vetor*);

void CalculaAngulo(Vetor*);
void SomaVetores(Vetor*);
void SubtraiVetores(Vetor*);
void MultiplicaEscalar(Vetor*);
void ProdutoInterno(Vetor*);
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
Vetor* novo(int plano)
{
	if (plano == 2)
	{
		Vetor* v = (Vetor*)malloc(sizeof(Vetor));
		printf("\nNovo Vetor.\nDigite X: ");
		scanf("%d",&v->x);
		printf("\nDigite Y: ");
		scanf("%d",&v->y);
		v->R3 = NULL;
		return v;
	}
	else if (plano == 3)
	{
		Vetor* v = (Vetor*)malloc(sizeof(Vetor));
		printf("\nNovo Vetor.\nDigite X: ");
		scanf("%d",&v->x);
		printf("\nDigite Y: ");
		scanf("%d",&v->y);
		printf("\n\nDigite Z: ");
		scanf("%d",&v->z);
		v->R3 = 1;
		return v;
	}
	else
	{
		char choice;
		Vetor* v = (Vetor*)malloc(sizeof(Vetor));
		printf("\nNovo Vetor.\nDigite X: ");
		scanf("%d",&v->x);
		printf("\nDigite Y: ");
		scanf("%d",&v->y);
		do
		{
			fflush(stdin);
			printf("\nDeseja inserir a coordenada Z para um Vetor R3 ? (s/n)\n");
			scanf("%c",&choice);
			if (choice == 'n'||choice == 'N')
			{
				v->z = NULL;
				v->R3 = NULL;
				system("cls");
				printf("\n\nNovo Vetor: { %d; %d }",v->x, v->y);
			}
			else if (choice == 's' || choice == 'S')
			{
				printf("\n\nDigite Z: ");
				scanf("%d",&v->z);
				v->R3 = 1;
				system("cls");
				printf("\n\nNovo Vetor: { %d; %d; %d }",v->x, v->y, v->z);
			}
			else printf("\nResposta Invalida.\n");
		}while ( choice !='n' && choice !='N' && choice !='s' && choice!='S');
		return v;
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
bool R3(Vetor* v)
{
	if (v->R3 == NULL)
		return false;
	else 
		return true;
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
float modulo(Vetor* v)
{
	float modulo;
	if (R3(v))
	{
		modulo = sqrt( (v->x*v->x) + (v->y*v->y) + (v->z*v->z) );
		return modulo;
	}
	else
	{
		modulo = sqrt( (v->x*v->x) + (v->y*v->y));
		return modulo;
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void orientacao(Vetor* v)
{
	if (R3(v))
	{
		printf("\nFuncionalidades de direcao e sentido para R3 ainda nao implementadas\n");
	}
	else
	{
		int validar;
		float a;
		if (v->x == 0 && v->y == 0)
		{
			printf("\nDirecao e sentido indefinidos pois o Vetor esta NULO\n");
		}
		else if ( v->x != 0 )
		{
			a = (float)v->y / (float)v->x;
			validar = 1;
			printf("\nEquacao da reta: y = %.2fx",a);
		}
		else if (v->x == 0 && v->y != 0)
		{
			a = NULL;
			validar = 0;
		}
		
		if (v->y != 0 && v->x == 0 && validar == 0) //um caso especial e possível.
		{
			printf("\nDirecao: VERTICAL");
			if (v->y > 0)
				printf("\nSentido: para cima\n");
			else
				printf("\nSentido: para baixo\n");
		}
		else if (a == 0 && validar == 1)
		{
			printf("\nDirecao: Horizontal");
			if (v->x > 0)
				printf("\nSentido: para a Direita\n");
			else
				printf("\nSentido: para a Esquerda\n");
		}
	
		if ( (v->x > 0 && v->y > 0) || (v->x < 0 && v->y < 0) && validar == 1 )
		{
			printf("\nDirecao: inclinado a DIREITA");
			if (v->y < 0)
				printf("\nSentido: para baixo\n");
			else 
				printf("\nSentido: Para cima\n");
		}
		else if ( (v->x < 0 && v->y > 0) || (v->x > 0 && v->y < 0) && validar ==1 )
		{
			printf("\nDirecao: inclinado a ESQUERDA");
			if (v->y < 0)
				printf("\nSentido: para baixo\n");
			else 
				printf("\nSentido: Para cima\n");
		}
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CalculaVetor(Vetor* v)
{
	system("cls");
	printf("\nModulo:  %.2f",modulo(v));
	orientacao(v);
	printf("\n\n");
	system("pause");
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void CalculaAngulo(Vetor* v)//FUNÇÃO QUE CALCULA O ANGULO DO VETOR R3
{
	if(R3(v))
	{
		Vetor* produto = (Vetor*)malloc(sizeof(Vetor));
		double somaPI = 0, modA, modB, ang;
		system("cls");
		printf("\nentre com o outro Vetor\n");
		Vetor* v2 = novo(3);

		produto->x = v->x * v2->x;
		produto->y = v->y * v2->y;
		produto->z = v->z * v2->z;
		produto->R3 = 1;

		somaPI = produto->x + produto->y + produto->z;//PRODUTO INTERNO DOS VETORES

		modA = sqrt ( (v->x * v->x) + (v->y * v->y) + (v->z * v->z) );//MODULO DE V
	  	modB = sqrt ( (v2->x * v2->x) + (v2->y * v2->y) + (v2->z * v2->z) );//MODULO DE V2
	  	ang= acos(somaPI/(modA*modB));
        ang=(ang*180)/3.14;
	  	printf("\nAngulo: %.1f",ang);
	  	printf("\nCoseno: %.1f\n\n",cos(ang));
	  	system("pause");
	  	free(v2);
	  	free(produto);
	}
	else
	{
		Vetor* produto = (Vetor*)malloc(sizeof(Vetor));//FUNÇÃO QUE CALCULA O ANGULO DO VETOR R3
		double somaPI = 0, modA, modB, ang;
		system("cls");
		printf("\nentre com o outro Vetor\n");
		Vetor* v2 = novo(2);

		produto->x = v->x * v2->x;
		produto->y = v->y * v2->y;
		produto->R3 = 0;

		somaPI = produto->x + produto->y;//PRODUTO INTERNO DOS VETORES

		modA = sqrt ( (v->x * v->x) + (v->y * v->y));
	  	modB = sqrt ( (v2->x * v2->x) + (v2->y * v2->y) );
	  	ang= acos(somaPI/(modA*modB));
        ang=(ang*180)/3.14;
	  	printf("\nAngulo: %.1f",ang);
	  	printf("\nCoseno: %.1f\n\n",cos(ang));
	  	system("pause");
	  	free(v2);
	  	free(produto);
  	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void SomaVetores(Vetor* v)
{
	if (R3(v))
	{
		Vetor* v2 = novo(3);
		    //printar os vetores
		system("cls");
		printf("\nVetor 1:  ( %d, %d, %d )",v->x, v->y, v->z);
		printf("\nVetor 2:  ( %d, %d, %d )",v2->x, v2->y, v2->z);
		//a mágica acontece aqui lol:
		Vetor* r = (Vetor*)malloc(sizeof(Vetor));
		r->x = v->x + v2->x;
		r->y = v->y + v2->y;
		r->z = v->z + v2->z;
		r->R3 = 1;
		
		printf("\n\nVetor Resultante: ( %d, %d, %d )\n\n ",r->x, r->y, r->z);
		system("pause");
	}
	else
	{
		Vetor* v2 = novo(2); // lembrar de ajustar a estrutura de novo()
		    //printar os vetores
		system("cls");
		printf("\nVetor 1:  ( %d, %d )",v->x, v->y);
		printf("\nVetor 2:  ( %d, %d )",v2->x, v2->y);
		//a mágica acontece aqui lol:
		Vetor* r = (Vetor*)malloc(sizeof(Vetor));
		r->x = v->x + v2->x;
		r->y = v->y + v2->y;
		r->R3 = NULL;
		
		printf("\n\nVetor Resultante: ( %d, %d )\n\n ",r->x, r->y);
		system("pause");
		free(r);
		free(v2);
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void SubtraiVetores(Vetor* v)
{
	if (R3(v))
	{
		Vetor* v2 = novo(3);
		    //printar os vetores
		system("cls");
		printf("\nVetor 1:  ( %d, %d, %d )",v->x, v->y, v->z);
		printf("\nVetor 2:  ( %d, %d, %d )",v2->x, v2->y, v2->z);
		//a mágica acontece aqui lol:
		Vetor* r = (Vetor*)malloc(sizeof(Vetor));
		r->x = v->x - v2->x;
		r->y = v->y - v2->y;
		r->z = v->z - v2->z;
		r->R3 = 1;
		
		printf("\n\nVetor Resultante: ( %d, %d, %d )\n\n ",r->x, r->y, r->z);
		system("pause");
		free (r);
		free(v2);
	}
	else
	{
		Vetor* v2 = novo(2); // lembrar de ajustar a estrutura de novo()
		    //printar os vetores
		system("cls");
		printf("\nVetor 1:  ( %d, %d )",v->x, v->y);
		printf("\nVetor 2:  ( %d, %d )",v2->x, v2->y);
		//a mágica acontece aqui lol:
		Vetor* r = (Vetor*)malloc(sizeof(Vetor));
		r->x = v->x - v2->x;
		r->y = v->y - v2->y;
		r->R3 = NULL;
		
		printf("\n\nVetor Resultante: ( %d, %d )\n\n ",r->x, r->y);
		system("pause");
		free(r);
		free(v2);
	}
}
void MultiplicaEscalar(Vetor* v)
{
	int k;
	system("cls");
	printf("\nEntre com o valor: ");
	scanf("%d",&k);
	if (R3(v))
	{
		Vetor* xXx = (Vetor*)malloc(sizeof(Vetor));
		xXx->x = v->x * k;
		xXx->y = v->y * k;
		xXx->z = v->z * k;
		xXx->R3 = 1;
		printf("\nVetor original (na memoria): ( %d, %d, %d )\n",v->x, v->y, v->z);
		printf("\nVetor resultante: ( %d, %d, %d )\n\n",xXx->x, xXx->y, xXx->z);
		system("pause");
		free(xXx);
	}
	else
	{
		Vetor* xXx = (Vetor*)malloc(sizeof(Vetor));
		xXx->x = v->x * k;
		xXx->y = v->y * k;
		xXx->R3 = 0;
		printf("\nVetor original (na memoria): ( %d, %d )\n",v->x, v->y);
		printf("\nVetor resultante: ( %d, %d )\n\n",xXx->x, xXx->y);
		system("pause");
		free(xXx);
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void ProdutoInterno(Vetor* v)
{
	if(R3(v))
	{
		printf("\nDigite o outro vetor\n");
		Vetor* v2 = novo(3);
		system("cls");
		printf("\nVetor 1:  ( %d, %d, %d )",v->x, v->y, v->z);
		printf("\nVetor 2:  ( %d, %d, %d )",v2->x, v2->y, v2->z);
		Vetor* v3 = (Vetor*)malloc(sizeof(Vetor));
		v3->x = v->x * v2->x;
		v3->y = v->y * v2->y;
		v3->z = v->z * v2->z;
		v3->R3 = 1;
		printf("\n\nProduto interno: %d\n\n",v3->x + v3->y + v3->z);
		system("pause");
		free(v2);
		free(v3);
	}
	else
	{
		printf("\nDigite o outro vetor\n");
		Vetor* v2 = novo(2);
		system("cls");
		printf("\nVetor 1:  ( %d, %d )",v->x, v->y);
		printf("\nVetor 2:  ( %d, %d )",v2->x, v2->y);
		Vetor* v3 = (Vetor*)malloc(sizeof(Vetor));
		v3->x = v->x * v2->x;
		v3->y = v->y * v2->y;
		v3->R3 = 0;
		printf("\n\nProduto interno: %d\n\n",v3->x + v3->y);
		system("pause");
		free(v2);
		free(v3);
	}
}
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void menu(Vetor* v)
{
	system("cls");
	printf("\n* * * * * UTILITARIO DE CALCULO VETORIAL - ICA 4 * * * * *\n");
	if (R3(v))
		printf("\nVetor na Memoria: ( %d, %d, %d )\nPlano: R3\n\n",v->x, v->y, v->z);
	else
		printf("\nVetor na Memoria: ( %d, %d )\nPlano: R2\n\n",v->x, v->y);
	printf("\nESCOLHA OPCAO\n");
	printf("\n[1] Calcular modulo, direcao, sentido e a equacao do vetor");
	printf("\n[2] Calcular Angulo do vetor");
	printf("\n[3] Somar Vetores");
	printf("\n[4] subtrair Vetores");
	printf("\n[5] Alterar o Vetor principal na memoria");
	printf("\n[6] Multiplicacao por escalar");
	printf("\n[7] Produto interno entre Vetores");
	printf("\n[8] Notas da Versao");
	printf("\n[9] Sair do Utilitario\n\n");
}
main()
{
	system("color 71");
	int menuchoice;
	system("cls");
	printf("\nUTILITARIO DE CALCULO VETORIAL - ICA 4\n");
	printf("\nComece entrando com um vetor\n");
	Vetor* v = novo(0);
	do
	{
		do
		{
			menu(v);
			scanf("%d",&menuchoice);
			switch(menuchoice)
			{
				case 1:
					CalculaVetor(v);
					break;
				case 2:
					CalculaAngulo(v);
					break;
				case 3:
					SomaVetores(v);
					break;
				case 4:
					SubtraiVetores(v);
					break;
				case 5:
					free(v);
					v = novo(0);
					break;
				case 6:
					MultiplicaEscalar(v);
					break;
				case 7:
					ProdutoInterno(v);
					break;
				case 8:
					system("cls");
					printf("ICA 4 de Algebra Linear, desenvolvido para calculos elementares\nde vetores nos planos R2 e R3");
					printf("\nProfessor: Jerry Adriane\n\n");
					printf("Desenvolvido por Mateus Garcia, Michele Dalarme,\nMaicon Loureiro e Jeferson Silva Dettman\n\n");
					system("pause");
					break;	
				case 9:
					system("cls");
					printf("\nSaindo do utilitario...\n\n");
					system("pause");
					exit(1);
					break;
				default:
					printf("\nOpcaoo Invalida");
					system("pause");
					break;
			}
		}while( menuchoice < 1 && menuchoice > 9 );
	}while(true); //nunca sai do programa sem a ordem. poupei um goto lol
}

