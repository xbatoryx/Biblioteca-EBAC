#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //função responsavel por casdatrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informção do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da string
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,","); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // coletando informção do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo  o "a" significa arquivar
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,","); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando informção do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,sobrenome); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
		
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,","); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // coletando informção do usuário
	scanf("%s",cargo);  //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo o "a" significa arquivar
	fprintf(file,cargo); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	

	
	system("pause"); // pausa o processor		
}

int consultar() //função responsavel por consultar os usuários no sistema
{
  setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
  
  //inicio criação de variáveis/string
  char cpf[40];
  char conteudo[200];
  //final da criação de variáveis/string
  
  printf("Digite o CPF a ser consultado: "); // coletando informção do usuário
  scanf("%s",cpf); //%s refere-se a string
  
  FILE *file; //cria o arquivo
  file = fopen(cpf,"r"); //cria o arquivo o "r" significa ler
  
  if(file == NULL) //significa que o arquivo pode ser nulo
  {
  	printf("Não foi possivel abrir o arquivo, não localizado!.\n"); // coletando informção do usuário	
  }
  
  while(fgets(conteudo, 200, file) != NULL) // Fazer com que um programa leia o arquivo
  {
  	printf("\nEssas são as informações do usuário: "); // coletando informção do usuário
  	printf("%s", conteudo); //%s refere-se a string
  	printf("\n\n"); // pular linha
  }
  
  system("pause"); // pausa o processor
}

int deletar() //função responsavel por deletar os usuários no sistema
{
  //inicio criação de variáveis/string
  char cpf[40];
  //final da criação de variáveis/string
    
  printf("Digite o CPF do usuário a ser deletado: "); // coletando informção do usuário
  scanf("%s",cpf);//%s refere-se a string
  
  remove(cpf); // remover um usuário
  
  FILE *file; //cria o arquivo
  file = fopen(cpf,"r"); //cria o arquivo o "r" significa ler
  
  if(file == NULL) //significa que o arquivo pode ser nulo
  {
  	printf("O usuário não se encontra no sistema!.\n"); // coletando informção do usuário	
  	system("pause"); // pausa o processor
  }	
}

int main()
      {
      int opcao=0; // Defenindo variáveis
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
	        printf("Escolha a opção desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Opção: "); //Fim do menu
	
	        scanf("%d", &opcao); // amarzenando a escolha do usuário
	
	        system("cls"); // responsavel por limpa a tela
	  
	        switch(opcao) //inicio da seleção do menu
	            {
	              case 1:
	  	        registro(); // chamada de funções
	              break;
	  	
	  	        case 2:
	  	        consultar(); // chamada de funções
	  	        break;
	  	
	  	        case 3:
	              deletar(); // chamada de funções
	              break;
	              
	              case 4:
	              printf("Obrigado por ultilizar o sistema!\n");
	              return 0;
	              break;
	  	
	  	        default:
	              printf("Essa opção não está disponivel!\n");
	              system("pause");
	              break;
	            } //Fim da seleção
            }   
      }
      
      else
        printf("senha errada!");
 }
