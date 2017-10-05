#include <stdio.h>
#include <string.h>
#include "BibliotecaDinamica.h"

void Espera() {
	printf("Pressione qualquer tecla para continuar.\n\n");
	fflush(stdin);
	getchar();
}

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
	ListaAluno alunos;
	ListaLivro livros;
	
	Aluno a;
	int nUsp;
	char nome[100], email[100], telefone[100];
	
	Livro l;
	int isbn, quantidade;
	char titulo[100], autor[100], editora[100];
	
	int opcao, confirmacao;
	
	cria_a(&alunos);
	cria_l(&livros);
	
	while(1) {
		MenuPrincipal();
		scanf("%d", &opcao);
		printf("\n");
		
		if(opcao == 1) {
			nUsp = 1;
			while(1 && nUsp != -1) {
				printf("Digite as informacoes do aluno ou -1 para sair: \n");
				printf("nUsp: ");
				scanf("%d", &nUsp);
				printf("\n");
				if(nUsp != -1 && !BuscarAluno(&alunos, &a, &nUsp)) {
					printf("Usando o sistema em nome do aluno:\n");
					printf("Nome: %s\tnUsp: %d\n\n", a.nome, a.nUsp);
					
					while(1) {
						MenuAluno();
						scanf("%d", &opcao);
						printf("\n");
						if(opcao == 1) {
							isbn = 0;
							while(1 && isbn != -1) {
								printf("Digite as informacoes do livro ou -1 para sair: \n");
								printf("ISBN: ");
								scanf("%d", &isbn);
								if(isbn != -1 && !BuscarLivro(&livros, &l, &isbn)) {
									printf("Titulo: %s\n", l.titulo);
									printf("Autor: %s\n", l.autor);
									printf("Editora: %s\n", l.editora);
									printf("Quantidade: %d\n\n", l.quantidade);
									
									confirmacao = -1;
									while(confirmacao != 0 && confirmacao != 1) {
										printf("Deseja retirar esse livro?\n");
										printf("Digite 1 para confirmar ou 0 para cancelar\n\n");
										printf("Opcao: ");
										scanf("%d", &confirmacao);
										printf("\n");
									}
									
									if(confirmacao == 1) {
										if(RetirarLivro(&alunos, &a.nUsp, &livros, &isbn)) {
											printf("Livro retirado com sucesso.\n\n");
										}
										else {
											printf("Voce foi colocado na fila de espera. Assim que o livro estiver disponivel recebera uma mensagem.\n");
										}
									}
									else {
										printf("Livro nao foi retirado.\n\n");
									}
									
									break;
								}
								else {
									if(isbn != -1)
										printf("Livro nao encontrado, escolha outro ISBN\n\n");
								}
							}
//							Espera();
						}
						else if(opcao == 2) {
							isbn = 0;
							while(1 && isbn != -1) {
								printf("Digite as informacoes do livro ou -1 para sair: \n");
								printf("ISBN: ");
								scanf("%d", &isbn);
								if(isbn != -1 && !BuscarLivro(&livros, &l, &isbn)) {
									printf("Titulo: %s\n", l.titulo);
									printf("Autor: %s\n", l.autor);
									printf("Editora: %s\n", l.editora);
									printf("Quantidade: %d\n\n", l.quantidade);
									
									confirmacao = -1;
									while(confirmacao != 0 && confirmacao != 1) {
										printf("Deseja devolver esse livro?\n");
										printf("Digite 1 para confirmar ou 0 para cancelar\n\n");
										printf("Opcao: ");
										scanf("%d", &confirmacao);
										printf("\n");
									}
									
									if(confirmacao == 1) {
										DevolverLivro(&livros, &isbn);
										printf("Livro devolvido com sucesso.\n\n");
									}
									else {
										printf("Livro nao foi devolvido.\n\n");
									}
									
									break;
								}
								else {
									if(isbn != -1)
										printf("Livro nao encontrado, escolha outro ISBN\n\n");
								}
							}
						}
						else if(opcao == 3) {
							if(!VerMensagens(&alunos, &nUsp)) {
								printf("Nao ha mensagens.\n\n");
							}
							Espera();
						}
						else if(opcao == 0)
							break;
						else {
							printf("Digite uma opcao valida.\n\n");
						}
					}
					
					break;
				}
				else {
					if(nUsp != -1)
						printf("Aluno nao encontrado, escolha outro nUsp\n\n");
				}
			}
			Espera();
		}
		else if(opcao == 2) {
			while(1) {
				MenuAdministracao();
				scanf("%d", &opcao);
				printf("\n");
				if(opcao == 1) {
					isbn = 0;
					while(1 && isbn != -1) {
						printf("Digite as informacoes do livro ou -1 para sair: \n");
						printf("ISBN: ");
						scanf("%d", &isbn);
						if(isbn != -1 && BuscarLivro(&livros, &l, &isbn)) {
							printf("Titulo: ");
							fflush(stdin);
							gets(titulo);
							printf("Autor: ");
							fflush(stdin);
							gets(autor);
							printf("Editora: ");
							fflush(stdin);
							gets(editora);
							printf("Quantidade: ");
							fflush(stdin);
							scanf("%d", &quantidade);
							
							CadastrarLivro(&livros, &isbn, titulo, autor, editora, &quantidade);
							break;
						}
						else {
							if(isbn != -1)
								printf("Livro ja cadastrado, escolha outro ISBN\n\n");
						}
					}
					Espera();
				}
				else if(opcao == 2) {
					isbn = 0;
					while(1 && isbn != -1) {
						printf("Digite as informacoes do livro ou -1 para sair: \n");
						printf("ISBN: ");
						scanf("%d", &isbn);
						if(isbn != -1 && !BuscarLivro(&livros, &l, &isbn)) {
							printf("Titulo: %s\n", l.titulo);
							printf("Autor: %s\n", l.autor);
							printf("Editora: %s\n\n", l.editora);
							
							confirmacao = -1;
							while(confirmacao != 0 && confirmacao != 1) {
								printf("Deseja excluir esse livro?\n");
								printf("Digite 1 para confirmar ou 0 para cancelar\n\n");
								printf("Opcao: ");
								scanf("%d", &confirmacao);
							}
							
							if(confirmacao == 1) {
								RemoverLivro(&livros, &isbn);
								printf("Livro removido com sucesso.\n\n");
							}
							else {
								printf("Remocao cancelada.\n\n");
							}
							
							break;
						}
						else {
							if(isbn != -1)
								printf("Livro nao encontrado, escolha outro ISBN\n\n");
						}
					}
					Espera();
				}
				else if(opcao == 3) {
					nUsp = 1;
					while(1 && nUsp != -1) {
						printf("Digite as informacoes do aluno ou -1 para sair: \n");
						printf("nUsp: ");
						scanf("%d", &nUsp);
						if(nUsp != -1 && BuscarAluno(&alunos, &a, &nUsp)) {
							printf("Nome: ");
							fflush(stdin);
							gets(nome);
							printf("Email: ");
							fflush(stdin);
							gets(email);
							printf("Telefone: ");
							fflush(stdin);
							gets(telefone);
							
							CadastrarAluno(&alunos, &nUsp, nome, email, telefone);
							break;
						}
						else {
							if(nUsp != -1)
								printf("Aluno ja cadastrado, escolha outro nUsp\n\n");
						}
					}
					Espera();
				}
				else if(opcao == 4) {
					nUsp = 0;
					while(1 && nUsp != -1) {
						printf("Digite as informacoes do aluno ou -1 para sair: \n");
						printf("nUsp: ");
						scanf("%d", &nUsp);
						if(nUsp != -1 && !BuscarAluno(&alunos, &a, &nUsp)) {
							printf("Nome: %s\n", a.nome);
							printf("Email: %s\n", a.email);
							printf("Telefone: %s\n\n", a.telefone);
							
							confirmacao = -1;
							while(confirmacao != 0 && confirmacao != 1) {
								printf("Deseja excluir esse aluno?\n");
								printf("Digite 1 para confirmar ou 0 para cancelar\n\n");
								printf("Opcao: ");
								scanf("%d", &confirmacao);
							}
							
							if(confirmacao == 1) {
								RemoverDaFila(&livros, &nUsp);
								RemoverAluno(&alunos, &nUsp);
								printf("Aluno removido com sucesso.\n\n");
							}
							else {
								printf("Remocao cancelada.\n\n");
							}
							
							break;
						}
						else {
							if(nUsp != -1)
								printf("Aluno nao encontrado, escolha outro nUsp\n\n");
						}
					}
					Espera();
				}
				else if(opcao == 0)
					break;
				else {
					printf("Digite uma opcao valida.\n\n");
				}
			}
		}
		else if(opcao == 0)
			break;
		else {
			printf("Digite uma opcao valida.\n\n");
		}
	}
	
	return 0;
}
//	nUsp = 1;
//	strcpy(nome, "lucas");
//	strcpy(email, "lucas@usp");
//	strcpy(telefone, "5514");
//	CadastrarAluno(&alunos, &nUsp, nome, email, telefone);
//	
//	nUsp = 2;
//	strcpy(nome, "felipe");
//	strcpy(email, "felipe@usp");
//	strcpy(telefone, "5516");
//	CadastrarAluno(&alunos, &nUsp, nome, email, telefone);
//	
//	isbn = 11;
//	strcpy(titulo, "a");
//	strcpy(autor, "b");
//	strcpy(editora, "c");
//	quantidade = 0;
//	CadastrarLivro(&livros, &isbn, titulo, autor, editora, &quantidade);
//	
//	isbn = 11;
//	BuscarLivro(&livros, &l, &isbn);	
//	printf("ISBN: %d\n", l.isbn);
//	printf("Titulo: %s\n", l.titulo);
//	printf("Autor: %s\n", l.autor);
//	printf("Editora: %s\n", l.editora);
//	printf("Quantidade: %d\n", l.quantidade);
//	
//	nUsp = 1;
//	RetirarLivro(&alunos, &nUsp, &livros, &isbn);
//	
//	isbn = 11;
//	BuscarLivro(&livros, &l, &isbn);	
//	printf("\n\nISBN: %d\n", l.isbn);
//	printf("Titulo: %s\n", l.titulo);
//	printf("Autor: %s\n", l.autor);
//	printf("Editora: %s\n", l.editora);
//	printf("Quantidade: %d\n", l.quantidade);
//	
//	nUsp = 2;
//	RetirarLivro(&alunos, &nUsp, &livros, &isbn);
//	
//	nUsp = 1;
//	RemoverDaLista(&livros, &nUsp);
//	RemoverAluno(&alunos, &nUsp);
//	
//	DevolverLivro(&livros, &isbn);
//	
//	isbn = 11;
//	BuscarLivro(&livros, &l, &isbn);	
//	printf("\n\nISBN: %d\n", l.isbn);
//	printf("Titulo: %s\n", l.titulo);
//	printf("Autor: %s\n", l.autor);
//	printf("Editora: %s\n", l.editora);
//	printf("Quantidade: %d\n", l.quantidade);
//	
//	printf("\n");
//	nUsp = 2;
//	printf("Mensagem aluno 2: "); VerMensagens(&alunos, &nUsp);
