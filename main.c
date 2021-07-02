#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef union{
    int cartao;
    int dinheiro;
}pagamento;

typedef struct{
    char placa[10];
    char modelo[30];
    int ocupada;
    pagamento metodo;
}vagas;

vagas abrir_estacionamento(vagas carro){//Funcao para iniciar todas as vagas como vazia
    carro.ocupada=0;
    return carro;
}

void vagas_disponiveis(vagas *carro){//Funcao para printar todas as vagas que estao vazias
    int cont;
    printf("\nVagas disponiveis para estacionar\n");
    for(int i=1; i<=30; i++){
        if(carro[i].ocupada ==1){
            printf("| ");
            cont++;
        }
        else if(carro[i].ocupada==0)
        printf("|%d", i);

    }
    if(cont ==30)
        printf("\nDesculpe estamos lotados.");
}

vagas cadastrar_carro(vagas carro){//Funcao para cadastrar os carros nas vagas
    int aux;
    system("cls");
    printf("\n----------Vaga selecionada!--------------");
    printf("\nInformacoes sobre o veiculo.\nPlaca-> ");
    scanf("%s",carro.placa);
    printf("Modelo-> ");
    scanf("%s", carro.modelo);
    printf("Qual o metodo de pagamento na saida?Cartao(1) ou dinheiro(2)\nR->");
    scanf("%d", &aux);
    system("cls");
    if(aux == 1)
        carro.metodo.cartao=1;
    else
        carro.metodo.dinheiro=1;

    carro.ocupada =1;
    return carro;
}

int main()
{
    vagas carro[30];
    int opc, resul, sair, vaga, aux;
    char placa[10];
    for(int i =1;i<=30;i++){
    carro[i]=abrir_estacionamento(carro[i]);
    }

    printf("--------------Bem vindo ao estacionamento!-------------------------");
     while(opc != 5){


        printf("\nQual das opcoes abaixo deseja executar?\n1-Estacionar um veiculo.\n2-Buscar veiculo.\n3-Alterar vaga.\n4-Retirar veiculo.\n5-Sair.\nR->");
        scanf("%d", &opc);
        printf("------------------------------------------");
        switch(opc){
            case 1: system("cls");//Essa e a parte de estacionar ela ira chamar a funcao para mostrar as vagas disponiveis e verificar se a escolhida pelo cliente esta vazia.
                vagas_disponiveis(carro);
                printf("\nQual vagas das mostradas deseja escolher?\nR->");
                scanf("%d", &vaga);
                while(carro[vaga].ocupada ==0){
                    if(carro[vaga].ocupada == 0){
                        carro[vaga] = cadastrar_carro(carro[vaga]);
                    }
                    else
                        printf("\nEssa vaga ja esta ocupada");
                }
            break;

            case 2: system("cls");//Essa e o case de busca, ela pode ser feita a partir da placa do veiculo que ira mostrar aonde ele esta ou pela vaga que ira mostrar qual veiculo esta nela.
                printf("\nDeseja uma busca pela placa(1) ou pela vaga(2)?\nR->");
                scanf("%d", &aux);
                if(aux == 1){//Sera feita a busca caso seja selecionado placa
                    printf("\nQual a placa do veiculo?\nR->");
                    scanf("%s", placa);
                    for(int i=1; i<=30; i++){//faz a comparacao das placas ja cadastradas com a placa que esta buscando
                        if(strcmp(carro[i].placa, placa) == 0){
                            system("cls");
                            printf("\nO %s esta na vaga %d", carro[i].modelo, i);
                            resul=1;
                        }
                    }
                    if(resul != 1){
                        system("cls");
                        printf("\n--------Carro nao escontrado.---------------");
                    }
                }
                else if(aux ==2){//sera feita a busca pela vaga escolhida
                    printf("\nQual a vaga deseja buscar?\nR->");
                    scanf("%d", &vaga);
                    if(carro[vaga].ocupada == 1){//Verifica se a vaga esta vazia ou ocupada
                        system("cls");
                        printf("\nNa vaga %d esta o %s de placa %s",vaga, carro[vaga].modelo, carro[vaga].placa);
                    }
                    else
                        printf("\n----------Nenhum carro nessa vaga.------------");
                }

                else{//caso digite um numero que nao seja aceito
                    system("cls");
                    printf("\nOpcao invalida");
                }
            break;

            case 3: system("cls");
            printf("\nDe qual vaga deseja se mudar?\nR->");//E o case caso o cliente deseje mudar o veiculo de lugar, ele verifica se possui um veiculo na vaga de destino caso nao tenha faz a troca
            scanf("%d", &vaga);
            if(carro[vaga].ocupada==0){//verifica se tem algum veiculo na vaga antes de fazer a troca
                system("cls");
                printf("\nEssa vaga nao possui carro para troca.\n");
            }
            else{
                if(carro[vaga].ocupada == 1){//if para saber se na vaga de destino ja possui um veiculo
                    vagas_disponiveis(carro);
                    scanf("%d", &aux);
                    if(carro[aux].ocupada == 1){
                        system("cls");
                        printf("\nA vaga selecionada ja esta ocupada.");
                    }
                    else{//estando vazia a vaga aqui sera feita a troca
                        system("cls");
                        carro[aux]=carro[vaga];
                        carro[vaga].ocupada = 0;
                        printf("\n----O %s de placa %s trocou para a vaga %d----", carro[aux].modelo, carro[aux].placa, aux);
                    }
                }
            }

            break;

            case 4: system("cls");
                printf("\nDe qual vaga deseja sair?\n");//Case para quando o cliente sair do estacionamento
                scanf("%d", &sair);
                if(carro[sair].ocupada == 0){//verifica se a vaga de saida possui algum veiculo
                    system("cls");
                    printf("\n----------Essa vaga esta vazia!-------------");
                }
                else{//estando com veiculo ela define a vaga como vazia
                    system("cls");
                    carro[sair].ocupada =0;
                    printf("\nO %s saiu!", carro[sair].modelo);
                }
            break;

            case 5: system("cls");//E a opcao para sair do menu de escolhas
                printf("\n----------Volte sempre!------");
             break;

            default: printf("\nOpcao invalida!\n");//caso seja digitado uma opcao invalida

        }
     }

    return 0;
}
