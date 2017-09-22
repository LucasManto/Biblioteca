#include <stdio.h>
#include "BibliotecaDinamica.h"
// #include "BibliotecaEstatica.h"

void MenuAluno() {
    printf("1- Retirar Livro\n");
    printf("2- Ver Mensagens\n");
    printf("0- Sair\n\n");
    printf("Opcao: ");
}

void MenuAdministracao() {
    printf("1- Cadastrar Livro\n");
    printf("2- Remover Livro\n");
    printf("3- Cadastrar Aluno\n");
    printf("4- Remover Aluno\n");
    printf("0- Voltar\n\n");
    printf("Opcao: ");
}

void MenuPrincipal() {
    printf("1- Aluno\n");
    printf("2- Administracao\n");
    printf("0- Encerrar\n\n");
    printf("Opcao: ");
}

int main() {
    ListaAluno alunos;
    // Lista livros;
    int opcao, opcaoExclusao;
    
    NoAluno *a = NULL;

    // Variaveis p/ Aluno
    char *nome, *email;
    int nUsp, *telefone;

    cria_a(&alunos);
    // cria(&livros);

    MenuPrincipal();
    scanf(" %d", &opcao);
    printf("\n");
    while (opcao != 0) {
        switch (opcao) {
            case 1:
        		if(tamanho_a(&alunos) == 0) {
            		printf("Nao ha alunos cadastrados! Cadastre um aluno na secao Administracao para utilizar essa area.\n\n");
            		break;
				}
                while (opcao != 0) {
                	while(a == NULL && nUsp != -1) {
	                	printf("Digite o nUsp do aluno ou -1 para voltar: ");
	                	scanf("%d", &nUsp);
	                	
	                	if(nUsp != -1) {
		                	a = BuscaAluno(&alunos, &nUsp);               	
		                	if(a != NULL) {
		                		printf("\nUtilizando o sistema em nome do aluno:\n%s nUsp: %d\n\n", a->info.nome, a->info.nUsp);
		                		MenuAluno();
			                    scanf(" %d", &opcao);
			                    printf("\n");
			                    switch (opcao) {
			                        case 1:
			                            // Retirar Livro();
			                            break;
			                        case 2:
			                            // VerMensagens();
			                            break;
			                        case 0:
			                        	a = NULL;
			                            break;
			                        default:
			                            printf("Digite uma opcao valida\n\n");
			                            break;
			                    }
		                	}
		                	else
		                		printf("\nAluno nao encontrado! Tente novamente.\n\n");
		                }
		                else {
		                	opcao = 0;
		                	printf("\n");
						}
					}
					nUsp = 0;
				}
                break;
            case 2:
                while (opcao != 0) {
                    MenuAdministracao();
                    scanf(" %d", &opcao);
                    printf("\n");
                    switch (opcao) {
                        case 1:
                            // CadastrarLivro();
                            break;
                        case 2:
                            // RemoverLivro();
                            break;
                        case 3:
                        	printf("Por favor, digite as informacoes do aluno\n");
                            printf("Nome: ");
                            nome = LeString();
                            printf("nUsp: ");
                            scanf(" %d", &nUsp);
                            printf("Telefone (somente numeros e sem espaco): ");
                            telefone = LeTelefone();
                            printf("Email: ");
                            email = LeString();
                            
                            if(CadastrarAluno(&alunos, nome, nUsp, telefone, email));
							else printf("\nCadastro realizado com sucesso! Pressione qualquer tecla para continuar\n\n");
							
							getchar();
                            break;
                        case 4:
                        	if(tamanho_a(&alunos) == 0) {
			            		printf("Nao ha alunos cadastrados! Cadastre um aluno na secao Administracao para utilizar essa area.\n\n");
			            		break;
							}
							while(a == NULL && nUsp != -1) {
			                	printf("Digite o nUsp do aluno ou -1 para voltar: ");
			                	scanf("%d", &nUsp);
			                	
			                	if(nUsp != -1) {
			                		printf("Tamanho: %d\n", tamanho_a(&alunos));
				                	a = BuscaAluno(&alunos, &nUsp);                	
				                	if(a != NULL) {
				                		printf("Voce realmente deseja excluir esse aluno?\n");
				                		printf("Nome: %s\n", a->info.nome);
				                		printf("nUsp: %d\n", a->info.nUsp);
//				                		printf("Telefone: %s\n", e->a.telefone);
//										ImprimeTelefone();
				                		printf("Email: %s\n\n", a->info.email);
				                		
				                		printf("Digite 1 para excluir ou 0 para cancelar: ");
				                		scanf("%d", &opcaoExclusao);
				                		
				                		if(opcaoExclusao == 1)
                            				if(RemoverAluno(&alunos, a)) {
                            					printf("Remocao ocorreu com sucesso\nTamanho: %d\n\n", tamanho_a(&alunos));
											}
				                	}
				                	else
				                		printf("\nAluno nao encontrado! Tente novamente.\n\n");
				                }
							}
							a = NULL;
							nUsp = 0;
                            break;
                        case 0:
                            break;
                        default:
                            printf("Digite uma opcao valida\n\n");
                            break;
                    }
                }
                break;
        }
        MenuPrincipal();
        scanf(" %d", &opcao);
        printf("\n");
    }

    getchar();
    return 0;
}
