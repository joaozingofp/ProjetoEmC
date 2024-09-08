#include <stdio.h>
#include <locale>
#include <unistd.h> // <windows.h>

int opc;
bool estarLogado = false;
void cadastrar(void);
void sacar(void);
void depositar(void);
void entrar_na_conta(void);

struct dados {
	int dinheiroNaConta, senha;
	char nome[];
} pessoa;

int main()
{
	setlocale(LC_ALL, "Portuguese");
	//printf("Bem vindo ao sistema de atendimento do banco F.\nSelecione uma op��o: \n(1) Cadastro. \n(2) Entrar na conta.\n(3)Sacar.\n(4)Dep�sito.\n(5)Sair.\n");
	if (!estarLogado){
		printf("\nEntre em sua conta para continuar com as operações\n");
		cadastrar();
	}
	//printf("%i", pessoa.dinheiroNaConta);
	scanf("%i", &opc);
	while(1){
		
		switch(opc){
			case 1:
				cadastrar();
				break;
			case 2:
			
				break;
			case 3:
				sacar();
				printf("\nSelecione uma op��o: \n(1) Cadastro. \n(2) Entrar na conta\n(3)Sacar\n(4)Dep�sito\n(5)Sair.\n");
				scanf("%i", &opc);		
				break;
			case 4:
				depositar();
				printf("\nSelecione uma op��o: \n(1) Cadastro. \n(2) Entrar na conta\n(3)Sacar\n(4)Dep�sito\n(5)Sair.\n");
				scanf("%i", &opc);		
				break;
				
			case 5:
				return 0;
			default:
				printf("\nErro: Opção n�o foi aceita.\nSelecione uma op��o: \n(1) Cadastro. \n(2) Entrar na conta\n(3)Sacar\n(4)Dep�sito\n(5)Sair.\n");
				scanf("%i", &opc);
		}
	}
}
void cadastrar(void)
{
	printf("Digite o seu nome de usuário:\n> ");
	fgets(pessoa.nome, 50, stdin);
	printf("Digite a senha:\n> ");
	scanf("%i", &pessoa.senha);
	printf("\n%s", pessoa.nome);
}
void entrar_na_conta(void)
{
	/*printf("Digite o seu nome de usuário:\n> ");
	fgets(pessoa.nome, 12, stdin);
	printf("Digite a senha:\n> ");
	scanf("%i", &pessoa.senha);*/
}
void depositar(void)
{
	int quantia = 0;
	printf("Selecionado: Dep�sito.\nSaldo Atual: %i R$\nDigite a quantia � ser depositada: ", pessoa.dinheiroNaConta);
	scanf("%i", &quantia);
	for (int i = 0; i <= 2; i++) {
		sleep(0.5);
		printf(".");
	}
	pessoa.dinheiroNaConta += quantia;
	printf("\nValor dep�sito: %i R$\nSaldo atual: %i R$", quantia, pessoa.dinheiroNaConta);
}
void sacar(void)
{
	int quantia = 0;
	printf("Selecionado: Saque.\nSaldo Atual: %i R$\nDigite a quantia � ser retirada: ", pessoa.dinheiroNaConta);
	scanf("%i", &quantia);
	for (int i = 0; i <= 2; i++) {
		sleep(0.5);
		printf(".");
	}
	pessoa.dinheiroNaConta -= quantia;
	printf("\nValor sacado: %i R$\nSaldo atual: %i R$", quantia, pessoa.dinheiroNaConta);
	
}
