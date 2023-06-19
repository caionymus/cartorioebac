#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro () //função para registro de nomes
{
	//inicio das variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variaveis
	
	printf ("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
	scanf ("%s",cpf); //% chama a variavel, s de string
	
	strcpy(arquivo,cpf); //copia valor da string
	
	FILE *file; //FILE é a função, file é o nome do arquivo. cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo na pasta, w de write
	
	file = fopen(arquivo,"a"); //a de atualizar
	fprintf (file,"CPF: "); //adiciona texto ao documento
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf  (file,cpf); //f antes pq é dentro do file. salva o valor da variavel
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

int consulta() //função para consultar nomes
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
		printf ("Não foi possivel localizar o arquivo. \n"); //condicional caso não ache o arquivo
	}
	
	while (fgets(conteudo, 200, file) != NULL) //fgets de buscar no arquivo, verifica os caracteres no arquivo e enquanto não verificar 200 continua imprimindo
	{
		printf ("%s", conteudo);
	}
	
	system ("pause");
}

int deletar () //função para deletar nomes
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf [40];
	printf ("Digite CPF do usuário a ser deletado: ");
	scanf ("%s",cpf);
	
	remove (cpf); //deleta o arquvio
	
	FILE *file;
	file = fopen(cpf, "r"); //le o arquivo
	
	if(file == NULL) //caso não consiga ler, NULL, manda a mensagem
	{
		printf ("O usuário não se encontra no sistema. \n");
		system ("pause");
	}
}

int main()
{
	int  opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;) //começo da repetição
	{
		
		system ("cls"); //limpeza de tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo o idioma
	
		printf ("\t Cartório da EBAC\n\n"); //inicio do menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n"); 
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Opção: "); //fim do menu
		
		scanf ("%d",&opcao); //armazenando escolha do usuario
	
		system ("cls"); //limpeza de tela
				
		switch(opcao) //começo do switch, menu
		{
			case 1:
				registro(); //chama função
			break;
			
			case 2:
				consulta ();
			break;
			
			case 3:
				deletar ();
			break;
			
			case 4:
				printf ("Obrigado por utilizar o sistema \n");
				return 0;
			break;
			
			default:
				printf("Essa opção não está disponivel\n");
				system ("pause");
			break;
				
		} //fim do switch
	
	} //fim da repetição
}
