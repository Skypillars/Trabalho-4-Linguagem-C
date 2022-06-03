#include <stdio.h>
#include <string.h>

//Declarando as funções e procedimentos

int VerificaLetra(char a, char b);
void ImprimirVetor(int x, int vetor1[x], char vetor2[x], int cont);
void PreencherVetor(int j, int vetor1[j], char vetor2[j], char c);
int ComparaTexto(int j, int vetor1[j], char vetor2[j], char c);

int main()
{
    //Declarando variáveis
    
    char texto[1001];   //Vetor para armanezar os paragráfos passados
    int contadorCaracteres = 0; //Contador de caracteres
    char alfabetoMinusculo[26]; //Vetor com alfabeto minusculo para comparação
    char alfabetoMaiusculo[26]; //Vetor com alfabeto maiusculos para comparação
    char digitos[10];   //Vetor com os algorismos para comparação
    int qtdeAlfabetoMinusculo[26]; //Vetor com a quantidade de caracteres do alfabeto minusculo
    int qtdeAlfabetoMaiusculo[26]; //Vetor com a quantidade de caracteres do alfabeto maiusculo
    int qtdeDigitos[10]; //Vetor com a quantidade de caracteres de algorismos
    
    //Preenchendo os vetores
    
    PreencherVetor(26, qtdeAlfabetoMaiusculo, alfabetoMaiusculo, 'A');
    PreencherVetor(26, qtdeAlfabetoMinusculo, alfabetoMinusculo, 'B');
    PreencherVetor(10, qtdeDigitos, digitos, 'C');
    
    //Definindo o looping para a leitura dos paragráfos
    
    while(1){
        
        //Limpando o vetor para a leitura
        
        for(int i = 0; i < 1001; i++){
            texto[i] = '!';
        }
        
        //leitura do paragráfos em si
        
        fgets(texto, 1001, stdin);
        
        //Se o texto for igual a FIM ele termina o looping

        if(strcmp(texto, "FIM\n") == 0){
            break;
        }
        
        //Contando a quantidade de Caracteres
        
        for(int i = 0; i < 1001; i++){
            contadorCaracteres += ComparaTexto(26, qtdeAlfabetoMaiusculo, alfabetoMaiusculo, texto[i]); 
            contadorCaracteres += ComparaTexto(26, qtdeAlfabetoMinusculo, alfabetoMinusculo, texto[i]); 
            contadorCaracteres += ComparaTexto(10, qtdeDigitos, digitos, texto[i]); 
        }
    } 
    
    //Imprimindo os dados conseguidos
    
    printf("Caracteres Maiusculos:\n");
    ImprimirVetor(26, qtdeAlfabetoMaiusculo, alfabetoMaiusculo, contadorCaracteres);
    printf("\n");
    printf("Caracteres Minusculos:\n");
    ImprimirVetor(26, qtdeAlfabetoMinusculo, alfabetoMinusculo, contadorCaracteres);
    printf("\n");
    printf("Digitos:\n");
    ImprimirVetor(10, qtdeDigitos, digitos, contadorCaracteres);
    
    return 0;
}

//Função para comparar os caracteres

int VerificaLetra(char a, char b){
    if(a == b){
        return 1;
    } else {
        return 0;
    }
}

//Função para comparar o paragráfos com os vetores para comparação e preenchendo os vetores de quantidade 

int ComparaTexto(int j, int vetor1[j], char vetor2[j], char c){
    int x = 0;
    for(int i = 0; i < j; i++){
        vetor1[i] += VerificaLetra(c, vetor2[i]);
        x += VerificaLetra(c, vetor2[i]);
    }
    return x;
}

//Função para preencher os vetores de comparação e limpando os vetores de quantidade

void PreencherVetor(int j, int vetor1[j], char vetor2[j], char c){
    for(int i = 0; i < j; i++){
        switch(c){
            case 'A':
                vetor1[i] = 0;
                vetor2[i] = 'A' + i;
            break;
            
            case 'B': 
                vetor1[i] = 0;
                vetor2[i] = 'a' + i;
            break;
            
            case 'C':
                vetor1[i] = 0;
                vetor2[i] = '0' + i;
            break;
        }
    }
}

//Função para imprimir as informações da maneira pedida 

void ImprimirVetor(int x, int vetor1[x], char vetor2[x], int cont){
    for(int i = 0; i < x; i++){
        printf("%c: ", vetor2[i]);
        for(int j = 0; j < vetor1[i]; j++){
            printf("*");
        }
        printf(" (%d - %.2f)\n", vetor1[i], ((float)vetor1[i]/cont));
    }
}