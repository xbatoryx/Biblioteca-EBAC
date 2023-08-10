#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() //fun��o responsavel por casdatrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando inform��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletando inform��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo  o "a" significa arquivar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,","); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando inform��o do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,sobrenome); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
		
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,","); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando inform��o do usu�rio
	scanf("%s",cargo);  //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,cargo); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	

	
	system("pause"); // pausa o processor		
}

int consultar() //fun��o responsavel por consultar os usu�rios no sistema
{
  setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
  
  //inicio cria��o de vari�veis/string
  char cpf[40];
  char conteudo[200];
  //final da cria��o de vari�veis/string
  
  printf("Digite o CPF a ser consultado: "); // coletando inform��o do usu�rio
  scanf("%s",cpf); //%s refere-se a string
  
  FILE *file; //cria o arquivo
  file = fopen(cpf,"r"); //cria o arquivo o "r" significa ler
  
  if(file == NULL) //significa que o arquivo pode ser nulo
  {
  	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); // coletando inform��o do usu�rio	
  }
  
  while(fgets(conteudo, 200, file) != NULL) // Fazer com que um programa leia o arquivo
  {
  	printf("\nEssas s�o as informa��es do usu�rio: "); // coletando inform��o do usu�rio
  	printf("%s", conteudo); //%s refere-se a string
  	printf("\n\n"); // pular linha
  }
  
  system("pause"); // pausa o processor
}

int deletar() //fun��o responsavel por deletar os usu�rios no sistema
{
  //inicio cria��o de vari�veis/string
  char cpf[40];
  //final da cria��o de vari�veis/string
    
  printf("Digite o CPF do usu�rio a ser deletado: "); // coletando inform��o do usu�rio
  scanf("%s",cpf);//%s refere-se a string
  
  remove(cpf); // remover um usu�rio
  
  FILE *file; //cria o arquivo
  file = fopen(cpf,"r"); //cria o arquivo o "r" significa ler
  
  if(file == NULL) //significa que o arquivo pode ser nulo
  {
  	printf("O usu�rio n�o se encontra no sistema!.\n"); // coletando inform��o do usu�rio	
  	system("pause"); // pausa o processor
  }	
}

int main()
      {
      int opcao=0; // Defenindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Controle da EBAC ###\n\n");
	printf("Login de admistrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
	      for(laco=1;laco=1;)
	      { 
	        system("cls");  
	
	        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	        printf("### Controle da EBAC ###\n\n"); //Inicio do menu
	        printf("Escolha a op��o desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Op��o: "); //Fim do menu
	
	        scanf("%d", &opcao); // amarzenando a escolha do usu�rio
	
	        system("cls"); // responsavel por limpa a tela
	  
	        switch(opcao) //inicio da sele��o do menu
	            {
	              case 1:
	  	        registro(); // chamada de fun��es
	              break;
	  	
	  	        case 2:
	  	        consultar(); // chamada de fun��es
	  	        break;
	  	
	  	        case 3:
	              deletar(); // chamada de fun��es
	              break;
	              
	              case 4:
	              printf("Obrigado por ultilizar o sistema!\n");
	              return 0;
	              break;
	  	
	  	        default:
	              printf("Essa op��o n�o est� disponivel!\n");
	              system("pause");
	              break;
	            } //Fim da sele��o
            }   
      }
      
      else
        printf("senha errada!");
 }
