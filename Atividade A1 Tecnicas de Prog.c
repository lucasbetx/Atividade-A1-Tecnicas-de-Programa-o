#include <stdio.h>
#define T 50

//Dados heterogeneos

typedef struct{
        char marca[15];
        char modelo[15];
        int ano;
        char placa[15];
}CARRO;



int menu();

CARRO inserir();
void exibir(CARRO c[], int t);
void exibirAno(CARRO c[], int t, int ano);
void exibirModelo(CARRO c[], int t, char marca[]);
void exibirAnoSupDesc(CARRO c[], int t, int ano);

int main(){
	
    int n, cont = 0, ano;
    float preco;
    char marca[15];
    char modelo[15];
    char placa[15];
    printf("\nInforme a quantidade de veiculos que deseja cadastrar: ");
    scanf("%d",&n);
    while(n > 10){
    	printf("\nDesculpe, voce digitou uma quantidade maior que o limite, digite novamente: ");
    	scanf("%d",&n);
	}
    
    
    CARRO car[n];
    int opc, opChefe, opRelatorio,  processo;
    do{
       opc = menu();
       switch(opc){
           case 1:
             if(cont < n){              
              car[cont] = inserir();                 
                 cont++;  
             }
             else                
                 printf("\nVoce passou do limite de cadastro de veiculos!!");
                 printf("\nPressione alguma tecla para retornar !! ");
				 getch();                
          getchar();
           break;
           case 2:
            if(cont > 0){              
             exibir(car, cont);
             getch();
            }
            else           
             printf("\nNao a nenhum veiculo registrado");
			 getch();            
         getchar();            
           break;
           case 3:
            if(cont > 0){
             printf("\nInforme o ano do veiculo a ser exibido: ");
             scanf("%d",&ano);
             exibirAno(car, cont, ano);
             getch();
            }
            else          
              printf("\nNao a nenhum veiculo registrado");
			  getch();            
          getchar(); 
           break;
           case 4:
            if(cont > 0){
             getchar();
             printf("\nInforme o modelo do veiculo a ser exibido: ");
             gets(modelo);
             exibirModelo(car, cont, modelo);
			 getch();           
            }
            else          
             printf("\nNao a nenhum veiculo registrado");
			 getch();             
         getchar(); 
        break;
           case 5:
            if(cont > 0){
             printf("\nInforme o ano especifico: ");
             scanf("%d",&ano);
             exibirAnoSupEsp(car, cont, ano);
             getch();
            }
            else          
              printf("\nNao a nenhum veiculo registrado");
			  getch();            
          getchar(); 
           break;
           case 0: break;
           default:
        printf("Opcao %d invalida, tente outro numero ! ",opc);
           getch();
           break;

       }
    }while(opc != 0);
}

int menu(){
    int opc;
    system("cls");
    printf("--------------------- Veiculos ---------------------\n"
		   "1-Cadastrar veiculo\n"
           "2-Listar todos veiculos cadastrados\n"
           "3-Listar por Ano\n"
           "4-Listar por Modelo\n"
           "5-Listar veiculos por ano superior ao especificado\n"
           "0-Sair\n");
           
    printf("\nDigite o numero referente ao que deseja: ");
    scanf("%d", &opc);
    return opc;
}

CARRO inserir(CARRO car){
 CARRO c;
 getchar();
 printf("\n");
 printf("Informe a marca do veiculo: ");
    gets(c.marca);
    printf("Informe o modelo do veiculo: ");
    gets(c.modelo);
    printf("Informe a placa do veiculo: ");
    gets(c.placa);
    printf("Informe o ano do veiculo: ");
    scanf("%d",&c.ano);
      return c;
}

void exibir(CARRO c[], int t){
 int x;
 for(x = 0; x< t; x++){
  printf("\n");
  printf("Marca: %s\n", c[x].marca);
  printf("Modelo: %s\n", c[x].modelo);
  printf("Ano: %d\n", c[x].ano);
  printf("Placa: %s\n", c[x].placa);
  printf("\n");
  
 }
 printf("\nPressione alguma tecla para retornar !! ");
}

void exibirAno(CARRO c[], int t, int ano){
 int x;
  for(x = 0; x< t; x++){
    if(ano == c[x].ano){
     printf("\n");
     printf("Marca: %s\n", c[x].marca);
     printf("Modelo: %s\n", c[x].modelo);
     printf("Ano: %d\n", c[x].ano);
     printf("Placa: %s\n", c[x].placa);
     printf("\n");
    }else{
    	printf("\nNenhum carro encontrado com este ano, tente novamente!!!\n");
	} 
  }
  printf("\nPressione alguma tecla para retornar !! ");
}
  
void exibirModelo(CARRO c[], int t, char modelo[]){
 int x;
  for(x = 0; x< t; x++){
    if(strcmp(c[x].modelo, modelo) == 0){
     printf("\n");
     printf("Modelo: %s\n", c[x].modelo);
     printf("Marca: %s\n", c[x].marca);
     printf("Ano: %d\n", c[x].ano);
     printf("Placa: %s\n", c[x].placa);
     printf("\n");
    }else{
    	printf("\nNenhum veiculo encontrado com este modelo, tente novamente!!!\n");
	} 
   
  }
  printf("\nPressione alguma tecla para retornar !! ");
}

void exibirAnoSupEsp(CARRO c[], int t, int ano){
 int x;
  for(x = 0; x< t; x++){
    if(ano < c[x].ano){
     printf("\n");
     printf("Marca: %s\n", c[x].marca);
     printf("Modelo: %s\n", c[x].modelo);
     printf("Ano: %d\n", c[x].ano);
     printf("Placa: %s\n", c[x].placa);
     printf("\n");
    }
  }
  printf("\nPressione alguma tecla para retornar !! ");
}

