#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct contato CONTATO;
struct contato{
	char nome[30];
	char email[20];
	char telefone[11];
};
void sobrec(){
	printf("-----------------------------------------------\n");
	printf("                 SOBRE O TRABALHO            \n");
	printf("-----------------------------------------------\n");
}

void cabecalho(){
	printf("-----------------------------------------------\n");
	printf("                 Seja Bem Vindo         \n");
	printf("-----------------------------------------------\n");
}
void agenda(){
	printf("\n-----------------------------------------------\n");
	printf("                 AGENDA            \n");
	printf("\n-----------------------------------------------\n");
}
void sobre(){
	printf("\n\n\tAGENDA EM LINGUAGUEM C\n\n");
    printf("Trabalho para obtencao de nota Parcial\nDisciplina: Tecnicas de Programacao\n");
    printf("Trabalho feito por Heidielton Carmo");
    getch();  //espera que o usuário pressione uma tecla
}

/*void atualizar(){
} */

void cadastrar(){ // função para Adicionar mais contatos na agenda
	FILE* arquivo;
	CONTATO cont;
	
	arquivo = fopen("contato.txt", "a");
	if(arquivo==NULL){     //Se houver algum erro, o ponteiro apontará para NULL
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
	}else{
		do{
			agenda();
			fflush(stdin);
			printf("\nDigite um nome: ");
			gets(cont.nome);
			
			fflush(stdin);
			printf("\nDigite um Email: ");
			gets(cont.email);
			
			fflush(stdin);
			printf("\nDigite um telefone: ");
			gets(cont.telefone);
			
			fwrite(&cont, sizeof(CONTATO), 1,arquivo);
			
			printf("\nContinuar o Cadastro? (s/n): \n\n");
			
		}while(getche() == 's' );
		fclose(arquivo);
	}
	
}
void pesquisar(){ // função para Pesquisar contatos
	FILE* arquivo;
	CONTATO cont;
	char nome[30];
	cpc();
	arquivo = fopen("contato.txt", "rb");
	if(arquivo==NULL){
		printf("Nao foi possivel abrir o arquivo");
	}else{
		fflush(stdin);
		printf("Qual Contato esta procurando?: ");
		gets(nome);
		
		while(fread(&cont, sizeof(CONTATO), 1, arquivo)==1){
			if(strcmp(nome, cont.nome)==0){
			printf("\nNome:  %s\n",cont.nome );
			printf("Email: %s\n",cont.email );
			printf("Telefone: %s\n",cont.telefone );
			printf("\n-----------------------------------------------\n\n");
			}
		}
		
	}
	fclose(arquivo);
	getch();
	printf("\nClique em Qualquer tecla para voltar ao Iniciar:\n");
} 
void listar(){ // função para Mostrar os contatos no arquivo
	FILE* arquivo;
	CONTATO cont;
	
	arquivo = fopen("contato.txt", "rb");
	cpc();
	if(arquivo==NULL){ //Se houver algum erro, o ponteiro apontará para NULL
    	printf("Nao foi possivel abrir o arquivo");
	}else{
		while( fread(&cont,sizeof(CONTATO), 1, arquivo)==1){
			printf("Nome:  %s\n",cont.nome );
			printf("Email: %s\n",cont.email );
			printf("Telefone: %s\n",cont.telefone );
			printf("\n-----------------------------------------------\n");

		}
		printf("\nClique em Qualquer tecla para voltar ao Iniciar:\n");
	}
	fclose(arquivo);
	getch();
}
void cpc(){ // cabecalho para contato
	printf("-----------------------------------------------\n");
	printf("                CONTATOS\n");
	printf("-----------------------------------------------\n");
}

int main(void){
	int op; //opção
	do{
		cabecalho();
		printf("\n 1 - Fazer Cadastro");
        printf("\n 2 - Pesquisar Contato");
        printf("\n 3 - Listar todos Contatos");
        printf("\n 4 - Sobre o Trabalho");
        printf("\n 5 - Sair\n");
        
        printf("\nEscolha uma Opcao: ");
        scanf("%d", &op);
        
        switch(op){
        	case 1:
        		cadastrar();
        		break;
        	case 2:
        		pesquisar();
        		break;
        	case 3:
        		listar();
        		break;
        	case 4:
        		sobrec();
        		sobre();
        		break;
        	case 5:
        		printf("\n\nFinalizando...\n\n");
            	system("pause");
            	exit(0);
            	break;
        
        	default:
        		printf("\n\nOpcao invalida! Tente Novamente!\n\n");
            	system("pause");
            	break;
		}
	}while(op != 5);
}









