//Todo conte√∫do aqui.  Usando GCC, no ambiente windows
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//mudei aqui porra
//teste reverso

int profundidadeglobal;


/*typedef struct CLIENTE{
	float conta;
	char nome[50];
	float limite;
	float saldo;
}cliente;*/


//Retorna 0 se pelo menos um dos arquivos n√£o existe, e 1 se todos existem.
int verifica_existencia(){
	fflush(stdin);
	printf("Verificando banco de dados...");
	FILE *arquivo_hash = fopen("hash.txt", "r");
	FILE *arquivo_clientes = fopen("clientes.txt", "r");
	
	if ((arquivo_hash == NULL) && (arquivo_clientes == NULL)){
			printf("\nOs arquivos de banco nao foram encontrados.  Necessita criar um novo banco de dados....\n");
			return 0;
	}
	if (arquivo_hash == NULL){
			printf("\nO arquivo Hash, de indices, nao existe.  Necessita criar um novo banco de dados....\n");
			return 0;
	}
	if (arquivo_clientes == NULL){
			printf("\nO arquivo Clientes, de dados, nao existe.  Necessita criar um novo banco de dados....\n");	
			return 0;
	}
	printf("\nBanco de Dados Consistente.  Continuando execucao...\n");
	fclose(arquivo_clientes);
	fclose(arquivo_hash);
	return 1; //Ambos os arquivos existem.
}

char *devolve_binario(int conta){
	char binario[10], binarioAux[4];
	binario="9999999999"
	itoa(conta,binario,2); //Converte a conta para binario e armazena em char.
	while(binario[i] != 9){
		i++;
	}
	for(int j=0; j<i; j++){ //binarioAux recebe os 4 ˙ltimos digitos bin·rios da conta
		binarioAux[j] = binario[i-j];
	}
	printf("\nO valor %d em binario tem os ultimos 4 digitos: %s", conta, binarioAux)
	return binarioAux;	
}


int criar_banco(){
	printf("\nCriando banco de dados...");
	FILE *arquivo_hash = fopen("hash.txt", "a");
	FILE *arquivo_clientes = fopen("clientes.txt", "a");
	if ((arquivo_hash != NULL) && (arquivo_clientes != NULL)){
		fprintf(arquivo_hash, "2");
		fprintf(arquivo_hash, "\n2,0"); //1 bucket
		fprintf(arquivo_hash,"\n");
		fprintf(arquivo_hash, "\n2,0"); //2 bucket
		fprintf(arquivo_hash,"\n");
		fprintf(arquivo_hash, "\n2,0"); //3 bucket
		fprintf(arquivo_hash,"\n");
		fprintf(arquivo_hash, "\n2,0"); //4 bucket
		fprintf(arquivo_hash,"\n");
		fclose(arquivo_hash);
		//fprintf(arquivo_hash, "2,0");
		//fclose(arquivo_hash);
		printf("\nArquivos hash.txt e clientes.txt criados.  Continuando execucao...");
		return 1;
	}
	else{
		printf("\nNao foi possivel criar os arquivos de banco de dados");
		return 0;		
	}
		
};

int consultar(int conta, FILE* arquivo_clientes,FILE* arquivo_hash){
	int profundidadeglobal, profundidadelocal, binario;
	char binarioAux[4];
	fscanf(arquivo_hash,"%d",&profundidadeglobal);	
	binarioAux = devolve_binario(conta);
	//binario = atoi(binarioAux);//converto o binario para inteiro (nao da certo)
		
	if (profundidadeglobal==2){ //A profundidade local È, obrigatoriamente, igual a 2 tambÈm.
		if (binario == 0){
			//Devo ler a linha 3 do arquivo_hash
			
		}
		else if(binario == 1){
			//Devo ler a linha 5 do arquivo_hash
			
		}
		else if(binario == 10){
			//Devo ler a linha 7 do arquivo_hash
		}
		else if (binario == 11){
			//Devo ler a linha 9 do arquivo_hash
		}
	}
	
	else if(profundidadeglobal==3){
		
	}
	
	
	else if(profundidadeglobal==4){
	}
	
	
	
}



void cadastra_cliente(FILE* arquivo_clientes,FILE* arquivo_hash){
	int numlinha=0;
	int ja_existe;
	float numconta,contalim,contasaldo,conta,saldo,limite;
	char nome[50],nomecliente[50];
	fscanf(arquivo_hash,"%d",&profundidadeglobal);

	printf("Digite o numero da conta\n");
	scanf("%f",&conta);
	//aqui entra uma das funÁıes de hash
	ja_existe = consultar(conta, arquivo_clientes, arquivo_hash);


	printf("Digite o nome do cliente\n");
	scanf("%s",nomecliente);
	printf("Digite o limite do cliete\n");
	scanf("%f",&limite);
	printf("Digite o saldo inicial do cliente\n");
	scanf("%f",&saldo);
	rewind(arquivo_clientes);
	while(!feof(arquivo_clientes)){
	fscanf(arquivo_clientes,"%d|%s|%f|%f|%f",&numlinha,nome,&numconta,&contalim,&contasaldo);
	printf("%d %s", numlinha, nome);
	}
	numlinha++;
	fprintf(arquivo_clientes,"%d|%s|%.0f|%.2f|%.2f\n",numlinha,nomecliente,conta,limite,saldo);
	printf("Registro escrito");
}

int main(){
	int arquivos, bancos, loop;
	arquivos = verifica_existencia();
	if (arquivos == 0){
		bancos = criar_banco();
		if(bancos == 0) return 0; //N√£o conseguiu criar os arquivos, encerra o programa.	
	}
	FILE* arquivo_clientes=fopen("clientes.txt","r+");
	FILE* arquivo_hash=fopen("hash.txt","r+");
	int op=6;
	while(op!=1 && op!=2 && op!=3 && op!=0){
		printf("\nDigite sua opcao de uso.\n1-Cadastrar\n2-Remover\n3-Consultar por CPF\n4-Sair\n");
		scanf("%d",&op);
		if(op!=1 && op!=2 && op!=3 && op!=0)
			printf("\nPor favor digite uma opcao valida.\n");
		if(op==1){
			cadastra_cliente(arquivo_clientes, arquivo_hash);
			op=0;
		}
		if(op==2){
			// chama removecliente
		}	
		if(op==3){
			// chama consultacliente
		}
		if(op==4){
			fclose(arquivo_clientes);
			fclose(arquivo_hash);
			exit(1);
		}
	}
}
