// incluindo as bibliotecas do C
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

// definindo o tamanho do array
// pode alterar para definir a quantidade
// de livros a ser cadastrada
# define elementos 5

// cria uma struct para guardar os cadastros
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
	//unsigned int cp = 1252;
	//unsigned int cpIn = GetConsoleCP();
	//unsigned int cpOut = GetConsoleOutputCP();
	//SetConsoleOutputCP(cp);
	//SetConsoleCP(cp);

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
		// apresenta as opcoes ao usuario
		printf("Digite 1 - Inserir um novo cadastro \n");
		printf("Digite 2 - Mostrar todos os cadastros \n");
		printf("Digite 0 - Encerrar \n");
		scanf("%s", &opcao);
		fflush(stdin);

		switch(opcao)
		{
			// caso o usuario escolheu um novo cadastro
			case (char)'1':

				// faz o laco, olhando a quantidade a ser preenchida e se a lista ainda n�o est� completa
				for(i=0; i < elementos && count < elementos ; i++)
				{

					system("clear");

					// definindo o codigo do cadastro
					lista_livros[i].codigo = i;

					// nome do autor
					printf("\nInsira o nome do(s) [%d] autor(es) da obra:", i+1);
					fgets(lista_livros[i].nom_aut, sizeof lista_livros, stdin);
					fflush(stdin);

					//nome do livro
					printf("\nInsira o nome do [%d] livro:", i+1);
					fgets(lista_livros[i].nom_livro, sizeof lista_livros, stdin);
					fflush(stdin);

					// nome do editor
					printf("\nInsira o nome da [%d] editora:", i+1);
					fgets(lista_livros[i].nom_edit, sizeof lista_livros, stdin);
					fflush(stdin);

					count++;
				}

				// informa ao usuario que alcanaou o limite de armazenamento
				system("clear");
				printf("Sistema de cadastro lotado. Nao e possivel armazenar mais informacoes!\n");
				getchar();
				system("clear");

			break;

			// caso tenha escolhido imprimir os cadastros
			case (char)'2':

				// se a lista n�o estiver vazia
				if(count != 0)
				{

					for(i=0; i < elementos; i++)
					{
						system("clear");
						printf("\nCodigo: %d\n",lista_livros[i].codigo);
						printf("Autor(es): %s\n",lista_livros[i].nom_aut);
						printf("Livro: %s\n",lista_livros[i].nom_livro);
						printf("Editora: %s\n\n",lista_livros[i].nom_edit);

						getchar();
					}

					system("clear");
				}

				// se a lista estiver vazia
				else
				{
					system("clear");
					printf("Lista vazia! \n");
					getchar();
					system("clear");
				}

			break;

			// caso o usuario escolheu encerrar o programa
			case (char)'0':

				system("clear");
				exit(-1);

			break;

			// caso o usuario digite uma opcao invalida
			default:
				system("clear");
				printf("Erro: Opcao invalida! \n");
				getchar();

		}

		system("clear");
	}

	// enquanto nao for informado 0 para encerrar, continua a execucao do programa
	while(opcao !='0');

	// encerra o programa
	return 0;

}