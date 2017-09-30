#include <stdio.h>
#include "BibliotecaDinamica.h"
//#include "BibliotecaEstatica.h"

void MenuAluno() {
    printf("1- Retirar Livro\n");
    printf("2- Devolver Livro\n");
    printf("3- Ver Mensagens\n");
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
	
	int erro;
	
	
    ListaAluno alunos;
    ListaLivro livros;
    int opcaoMenu, opcao;
    
    // Variavel Pilha Mensagem
	char m[50];
    
    // Variaveis p/ Aluno
    NoAluno *a = NULL;
	char nome[50], email[50], telefone[15];
    int nUsp;
    
    // Variaveis p/ Livro
    NoLivro *l = NULL;
    int isbn, quantidade;
    char titulo[50], autor[50], editora[50];

    cria_a(&alunos);
    cria_l(&livros);

    MenuPrincipal();
    scanf(" %d", &opcaoMenu);
    printf("\n");
    while (opcaoMenu != 0) {
        switch (opcaoMenu) {
            case 1:
        		if(tamanho_a(&alunos) == 0) {
            		printf("Nao ha alunos cadastrados! Cadastre um aluno na secao Administracao para utilizar essa area.\n");
            		printf("Pressione qualquer tecla para continuar.\n\n");
            		fflush(stdin);
            		getchar();
            		break;
				}
                while (opcaoMenu != 0) {
                	while(a == NULL && nUsp != -1) {
	                	printf("Digite o nUsp do aluno ou -1 para voltar: ");
	                	scanf("%d", &nUsp);
	                	
	                	if(nUsp != -1) {
		                	a = BuscaAluno(&alunos, &nUsp);
		                	if(a != NULL) {
		                		while(opcaoMenu != 0) {
			                		printf("\nUtilizando o sistema em nome do aluno:\n\nNome: %s\tnUsp: %d\n\n", a->info.nome, a->info.nUsp);
			                		MenuAluno();
				                    scanf(" %d", &opcaoMenu);
				                    printf("\n");
				                    switch (opcaoMenu) {
				                        case 1:
				                        	if(tamanho_l(&livros)  == 0) {
				                        		printf("Nao ha livros cadastrados! Cadastre um livro na secao Administracao para utilizar essa area.\n");
				                        		printf("Pressione qualquer tecla para continuar.\n\n");
				                        		fflush(stdin);
				                        		getchar();
				                        		break;
											}
				                        	while(l == NULL && isbn != -1) {
							                	printf("Digite o ISBN do livro ou -1 para voltar: ");
							                	scanf("%d", &isbn);
							                	
							                	if(isbn != -1) {
								                	l = BuscaLivro(&livros, &isbn);                	
								                	if(l != NULL) {
								                		if(l->info.quantidade > 0) {
									                		printf("\n\nVoce realmente deseja retirar esse livro?\n\n");
									                		printf("Titulo: %s\n", l->info.titulo);
									                		printf("ISBN: %d\n", l->info.isbn);
									                		printf("Autor: %s\n", l->info.autor);
									                		printf("Editora: %s\n\n", l->info.editora);
									                		
									                		printf("Digite 1 para excluir ou 0 para cancelar: ");
									                		scanf("%d", &opcao);
									                		printf("\n");
									                		
									                		if(opcao == 1) {
									                			l->info.quantidade--;
									                			printf("\nLivro retirado com sucesso!\n\n");
															}
														}
														else {
															if(ColocaNaFila(l, a)) {
																printf("\n\nTodos os livros com esse ISBN estao alugados. Voce recebera uma mensagem quando ele estiver disponivel\n");
															}
															else {
																printf("Nao foi possivel inserir na fila de espera. Fila cheia\n");															
															}
														}
														
														printf("Pressione qualquer tecla para continuar.\n\n");
						                        		fflush(stdin);
						                        		getchar();
								                	}
								                	else
								                		printf("\nLivro nao encontrado! Tente novamente.\n\n");
								                }
											}
											l = NULL;
											isbn = 0;
				                            break;
				                        case 2:
				                            while(l == NULL && isbn != -1) {
							                	printf("Digite o ISBN do livro ou -1 para voltar: ");
							                	scanf("%d", &isbn);
							                	
							                	if(isbn != -1) {
								                	l = BuscaLivro(&livros, &isbn);                	
								                	if(l != NULL) {
								                		printf("\n\nVoce realmente deseja devolver esse livro?\n\n");
								                		printf("Titulo: %s\n", l->info.titulo);
								                		printf("ISBN: %d\n", l->info.isbn);
								                		printf("Autor: %s\n", l->info.autor);
								                		printf("Editora: %s\n\n", l->info.editora);
								                		
								                		printf("Digite 1 para excluir ou 0 para cancelar: ");
								                		scanf("%d", &opcao);
								                		printf("\n");
								                		
								                		if(opcao == 1) {
								                			l->info.quantidade++;
								                			printf("\nLivro devolvido com sucesso!\n\n");
								                			RemoveDaFila(l, a);
								                			sprintf(m, "Livro disponivel.\n ISBN: %d\tTitulo: %s\n", l->info.isbn, l->info.titulo);
															Push(&a->info.mensagens, m, &erro);
								                			printf("Pressione qualquer tecla para continuar.\n\n");
							                        		fflush(stdin);
							                        		getchar();
														}
								                	}
								                	else
								                		printf("\nLivro nao encontrado! Tente novamente.\n\n");
								                }
											}
											l = NULL;
											isbn = 0;
				                            break;
				                        case 3:
				                        	if(!IsEmpty(&a->info.mensagens)) {
					                        	while(!IsEmpty(&a->info.mensagens)) {
					                        		Pop(&a->info.mensagens, m, &erro);
					                        		printf("%s\n", m);
												}
											}
											else
												printf("Nao ha mensagens.\n");
											printf("Pressione qualquer tecla para continuar.\n\n");
			                        		fflush(stdin);
			                        		getchar();
				                        	break;
				                        case 0:
				                        	a = NULL;
				                            break;
				                        default:
				                            printf("Digite uma opcao valida\n\n");
				                            break;
				                    }
								}
		                	}
		                	else
		                		printf("\nAluno nao encontrado! Tente novamente.\n\n");
		                }
		                else {
		                	opcaoMenu = 0;
		                	printf("\n");
						}
					}
					nUsp = 0;
				}
                break;
            case 2:
                while (opcaoMenu != 0) {
                    MenuAdministracao();
                    scanf(" %d", &opcaoMenu);
                    printf("\n");
                    switch (opcaoMenu) {
                        case 1:
                            printf("Por favor, digite as informacoes do livro\n");
                        	printf("ISBN: ");
                            scanf(" %d", &isbn);
                            l = BuscaLivro(&livros, &isbn);
                            while(l != NULL) {
                            	printf("\n\nISBN em uso! Escolha outro:\n\n");
                            	printf("ISBN: ");
	                            scanf(" %d", &isbn);
	                            l = BuscaLivro(&livros, &isbn);
							}
                            printf("Titulo: ");
							fflush(stdin);
							gets(titulo);
                            printf("Autor: ");
                            gets(autor);
                            printf("Editora: ");
							fflush(stdin);
                            gets(editora);
                            printf("Quantidade: ");
                            scanf(" %d", &quantidade);
                            
                            if(CadastrarLivro(&livros, titulo, isbn, autor, editora, quantidade));
							else printf("\nCadastro realizado com sucesso!\n");
							printf("Pressione qualquer tecla para continuar.\n\n");
                    		fflush(stdin);
                    		getchar();
                            break;
                        case 2:
                            if(tamanho_l(&livros) == 0) {
			            		printf("Nao ha livros cadastrados! Cadastre um livro na secao Administracao para utilizar essa area.\n");
			            		printf("Pressione qualquer tecla para continuar.\n\n");
                        		fflush(stdin);
                        		getchar();
			            		break;
							}
							while(l == NULL && isbn != -1) {
			                	printf("Digite o ISBN do livro ou -1 para voltar: ");
			                	scanf("%d", &isbn);
			                	
			                	if(isbn != -1) {
				                	l = BuscaLivro(&livros, &isbn);                	
				                	if(l != NULL) {
				                		printf("\n\nVoce realmente deseja excluir esse livro?\n");
				                		printf("Titulo: %s\n", l->info.titulo);
				                		printf("ISBN: %d\n", l->info.isbn);
				                		printf("Autor: %s\n", l->info.autor);
				                		printf("Editora: %s\n", l->info.editora);
				                		printf("Quantidade: %d\n\n", l->info.quantidade);
				                		
				                		printf("Digite 1 para excluir ou 0 para cancelar: ");
				                		scanf("%d", &opcao);
				                		printf("\n");
				                		
				                		if(opcao == 1)
                            				if(RemoverLivro(&livros, l))
                            					printf("\nLivro removido com sucesso\n\n");
                            			else
                            				printf("Remocao cancelada.\n");
                            				
                            			printf("Pressione qualquer tecla para continuar.\n\n");
		                        		fflush(stdin);
		                        		getchar();
				                	}
				                	else
				                		printf("\nLivro nao encontrado! Tente novamente.\n\n");
				                }
							}
							l = NULL;
							isbn = 0;
                            break;
                        case 3:
                        	printf("Por favor, digite as informacoes do aluno\n");
                        	printf("nUsp: ");
                            scanf(" %d", &nUsp);
                            a = BuscaAluno(&alunos, &nUsp);
                            while(a != NULL) {
                            	printf("\n\nnUsp em uso! Escolha outro:\n\n");
                            	printf("nUsp: ");
	                            scanf(" %d", &nUsp);
	                            a = BuscaAluno(&alunos, &nUsp);
							}
                            printf("Nome: ");
							fflush(stdin);
							gets(nome);
                            printf("Telefone (somente numeros e sem espaco): ");
                            gets(telefone);
                            printf("Email: ");
							fflush(stdin);
                            gets(email);
                            
                            if(CadastrarAluno(&alunos, nome, nUsp, telefone, email));
							else printf("\nCadastro realizado com sucesso!\n");
							printf("Pressione qualquer tecla para continuar.\n\n");
                    		fflush(stdin);
                    		getchar();
                            break;
                        case 4:
                        	if(tamanho_a(&alunos) == 0) {
			            		printf("Nao ha alunos cadastrados! Cadastre um aluno na secao Administracao para utilizar essa area.\n");
			            		printf("Pressione qualquer tecla para continuar.\n\n");
                        		fflush(stdin);
                        		getchar();
			            		break;
							}
							while(a == NULL && nUsp != -1) {
			                	printf("Digite o nUsp do aluno ou -1 para voltar: ");
			                	scanf("%d", &nUsp);
			                	
			                	if(nUsp != -1) {
				                	a = BuscaAluno(&alunos, &nUsp);                	
				                	if(a != NULL) {
				                		printf("\n\nVoce realmente deseja excluir esse aluno?\n");
				                		printf("Nome: %s\n", a->info.nome);
				                		printf("nUsp: %d\n", a->info.nUsp);
				                		printf("Telefone: %s\n", a->info.telefone);
				                		printf("Email: %s\n\n", a->info.email);
				                		
				                		printf("Digite 1 para excluir ou 0 para cancelar: ");
				                		scanf("%d", &opcao);
				                		printf("\n");
				                		
				                		if(opcao == 1) {
                            				if(RemoverAluno(&alunos, a))
                            					printf("\nAluno removido com sucesso\n\n");
										}
                            			else
                            				printf("Remocao cancelada.\n");
                            				printf("Pressione qualquer tecla para continuar.\n\n");
			                        		fflush(stdin);
			                        		getchar();
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
                            printf("Digite uma opcao valida.\n\n");
                            break;
                    }
                }
                break;
            default:
            	printf("Digite uma opcao valida.\n\n");
        }
        MenuPrincipal();
        scanf(" %d", &opcaoMenu);
        printf("\n");
    }

    getchar();
    return 0;
}
