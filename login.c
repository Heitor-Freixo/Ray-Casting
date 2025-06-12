#include <stdio.h>
#include <string.h>

void cadastro(){
    FILE *arquivo;
    char nome[100], senha[50];
    arquivo=fopen("dadoslogin.txt", "a");
    if(arquivo== NULL){
        printf("Não foi possível abrir este arquivo.");
    }
    printf("______CADASTRO______\n");
    printf("Nome:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] =0;
    //getchar();
    printf("Senha:\n");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] =0;
    //getchar();
    //imprime e separa por ;
    fprintf(arquivo, "%s;%s\n", nome, senha);
    fclose(arquivo);
    printf("Usuário cadastrado com sucesso.\n");
}
void entrar(){
    FILE *arquivo;
    char *nomefix, *senhafix, nome[100], senha[50], linha[200];
    int flag=0;

    arquivo=fopen("dadoslogin.txt", "r");
    if(arquivo == NULL){
        printf("Arquivo não encontrado.\n");
        return;
    }

    printf("______LOGIN______\n");
    printf("Nome:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] =0;
    printf("Senha:\n");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] =0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL && flag == 0) {
        // Remove a quebra de linha
        linha[strcspn(linha, "\n")] = 0;

        // Separa os registros usando strtok
        nomefix = strtok(linha, ";");
        senhafix = strtok(NULL, ";"); // continua de onde parou o ponteiro

        if (nomefix != NULL && senhafix != NULL) {
            if(strcmp(nome, nomefix) == 0){
                printf("Nome correto!!\n");
                if(strcmp(senha, senhafix) == 0){
                    printf("Senha correta!!\n");
                    flag = 1;
                } else {
                    printf("Senha incorreta!\n");
                }
            }
        }
    }
    
    fclose(arquivo);
    
    if(flag == 0) {
        printf("Usuário não encontrado ou credenciais incorretas.\n");
    } else {
        printf("Login bem-sucedido!\n");
    }
}

int main(){
    int opcao;
    do{
        printf("______MENU DE LOGIN______\n");
        printf("1-Cadastrar\n");
        printf("2-Entrar\n");
        printf("3-Sair\n");
        scanf("%d", &opcao);
        getchar();
        switch (opcao){
        case 1:
            cadastro();
            break;
        case 2:
            entrar();
            break;
        case 3:
            printf("Saindo...");
            break;
        default:
            printf("Opção inválida, tente novamente");
        }
    }while(opcao!=3);
    return 0;
}

