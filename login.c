#include <stdio.h>
#include <string.h>
struct usuarios{
    char nome[60];
    char senha[60];
};
void cadastro(){
    FILE *arquivo;
    char nome[100], senha[50];
    arquivo=fopen("dadoslogin.txt", "a");
    if(arquivo== NULL){
        printf("Não foi possível abrir este arquivo.");
    }
    printf("______CADASTRO______");
    printf("Nome:");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] =0;
    printf("Senha:");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] =0;
    //separa por ;
    fprintf(arquivo, "%s;%s\n", nome, senha);
    fclose(arquivo);
    printf("Usuário cadastrado com sucesso.");
}
void entrar(){
    FILE *arquivo;
    char nome[100], senha[50];
    arquivo=fopen("dadoslogin.txt", "r");
    printf("______LOGIN______");
    printf("Nome:");
    fgets(nome, sizeof(nome), stdin);
    printf("Senha:");
    fgets(senha, sizeof(senha), stdin);

}
int login(){
    int opcao;
    do{
        printf("______MENU DE LOGIN______");
        printf("1-Cadastrar");
        printf("2-Entrar");
        printf("3-Sair");
        scanf("%d", &opcao);
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