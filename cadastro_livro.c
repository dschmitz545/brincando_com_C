// incluindo as bibliotecas do C
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// definindo o tamanho do array
// pode alterar para definir a quantidade
// de livros a ser cadastrada
# define elementos 20

// cria uma strutc para guardar os cadastros
struct biblioteca{
	int codigo;
	char nom_aut[250];
	char nom_livro[250];
	char nom_edit[250];
};

// inicializa a struct para evitar lixo de memoria
void InicializaVetor(struct biblioteca v[])
{
	int m;
	for(m=0; m < elementos; m++)
	{
		v[m].codigo = 0;
		strcpy(v[m].nom_aut, "");
		strcpy(v[m].nom_livro, "");
		strcpy(v[m].nom_edit, "");
	}
}

// inicia o programa principal
int main(int argc, char *argv[]) {

	setlocale(LC_ALL,"Portuguese");

	// para evitar o problema de imprimir texto destruindo os caracteres especiais
	unsigned int cp = 1252;
	unsigned int cpIn = GetConsoleCP();
	unsigned int cpOut = GetConsoleOutputCP();
	SetConsoleOutputCP(cp);
	SetConsoleCP(cp);

	// declara��o de variavies
	struct biblioteca lista_livros[elementos];

	// iniciando as variaveis para evitar lixo de memoria
	int i;
	int count;
	char opcao;
	char exec_nova;

	i = 0;
	count = 0;
	opcao = ' ';
	exec_nova = ' ';

	// o programa vai executar pelo menos uma vez
	do
	{
		// apresenta as op��es ao usu�rio
		printf("Digite 1 - Inserir um novo cadastro \n");
		printf("Digite 2 - Mostrar todos os cadastros \n");
		printf("Digite 0 - Encerrar \n");
		scanf("%s", &opcao);
		fflush(stdin);

		switch(opcao)
		{
			// caso o usu�rio escolheu um novo cadastro
			case (char)'1':

				// faz o la�o, olhando a quantidade a ser preenchida e se a lista ainda n�o est� completa
				for(i=0; i < elementos && count < elementos ; i++)
				{

					system("cls");

					// definindo o c�digo do cadastro
					lista_livros[i].codigo = i;

					// nome do autor
					printf("\nInsira o nome do(s) %d� autor(es) da obra:", i+1);
					gets(lista_livros[i].nom_aut);
					fflush(stdin);

					//nome do livro
					printf("\nInsira o nome do %d� livro:", i+1);
					gets(lista_livros[i].nom_livro);
					fflush(stdin);

					// nome do editor
					printf("\nInsira o nome da %d� editora:", i+1);
					gets(lista_livros[i].nom_edit);
					fflush(stdin);

					count++;
				}

				// informa ao usu�rio que alcan�ou o limite de armazenamento
				system("cls");
				printf("Sistema de cadastro lotado. N�o � poss�vel armazenar mais informa��es!\n");
				system("pause");
				system("cls");

			break;

			// caso tenha escolhido imprimir os cadastros
			case (char)'2':

				// se a lista n�o estiver vazia
				if(count != 0)
				{

					for(i=0; i < elementos; i++)
					{
						system("cls");
						printf("\nCodigo: %d\n",lista_livros[i].codigo);
						printf("Autor(es): %s\n",lista_livros[i].nom_aut);
						printf("Livro: %s\n",lista_livros[i].nom_livro);
						printf("Editora: %s\n\n",lista_livros[i].nom_edit);

						system("pause");
					}

					system("cls");
				}

				// se a lista estiver vazia
				else
				{
					system("cls");
					printf("Lista vazia! \n");
					system ("pause");
					system("cls");
				}

			break;

			// caso o usu�rio escolheu encerrar o programa
			case (char)'0':

				system("cls");
				exit(-1);

			break;

			// caso o usu�rio digite uma op��o inv�lida
			default:
				system("cls");
				printf("Erro: Op��o inv�lida! \n");
				system("pause");

		}

		system("cls");
	}

	// enquanto n�o for informado 0 para encerrar, continua a execu��o do programa
	while(opcao !='0');

	// encerra o programa
	return 0;

}
