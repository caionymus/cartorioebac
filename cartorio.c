#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro () //fun��o para registro de nomes
{
	//inicio das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variaveis
	
	printf ("Digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf ("%s",cpf); //% chama a variavel, s de string
	
	strcpy(arquivo,cpf); //copia valor da string
	
	FILE *file; //FILE � a fun��o, file � o nome do arquivo. cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo na pasta, w de write
	
	file = fopen(arquivo,"a"); //a de atualizar
	fprintf (file,"CPF: "); //adiciona texto ao documento
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf  (file,cpf); //f antes pq � dentro do file. salva o valor da variavel
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo,"a");
	fprintf (file,"\n");
	fclose (file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf ("%s",nome);
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,"Nome: ");
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,nome);
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,"\n");
	fclose (file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf ("%s",sobrenome);
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,"Sobrenome: ");
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,sobrenome);
	fclose (file);	
	
	file = fopen (arquivo,"a");
	fprintf (file,"\n");
	fclose (file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf ("%s",cargo);
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,"Cargo: ");
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,cargo);
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file,"\n");
	fclose (file);
	
}

int consulta() //fun��o para consultar nomes
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf ("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r de read
	
	if (file == NULL)
	{
		printf ("N�o foi possivel localizar o arquivo. \n"); //condicional caso n�o ache o arquivo
	}
	
	while (fgets(conteudo, 200, file) != NULL) //fgets de buscar no arquivo, verifica os caracteres no arquivo e enquanto n�o verificar 200 continua imprimindo
	{
		printf ("%s", conteudo);
	}
	
	system ("pause");
}

int deletar () //fun��o para deletar nomes
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	printf ("Digite CPF do usu�rio a ser deletado: ");
	scanf ("%s",cpf);
	
	remove (cpf); //deleta o arquvio
	
	FILE *file;
	file = fopen(cpf, "r"); //le o arquivo
	
	if(file == NULL) //caso n�o consiga ler, NULL, manda a mensagem
	{
		printf ("O usu�rio n�o se encontra no sistema. \n");
		system ("pause");
	}
}

int main()
{
	int  opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;) //come�o da repeti��o
	{
		
		system ("cls"); //limpeza de tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
		printf ("\t Cart�rio da EBAC\n\n"); //inicio do menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n"); 
		printf ("Op��o: "); //fim do menu
		
		scanf ("%d",&opcao); //armazenando escolha do usuario
	
		system ("cls"); //limpeza de tela
				
		switch(opcao) //come�o do switch, menu
		{
			case 1:
				registro(); //chama fun��o
			break;
			
			case 2:
				consulta ();
			break;
			
			case 3:
				deletar ();
			break;
			
			default:
				printf("Essa op��o n�o est� disponivel\n");
				system ("pause");
			break;
				
		} //fim do switch
	
	} //fim da repeti��o
}
