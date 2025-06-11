#include <stdio.h>
struct usuarios{
    char nome[60];
    char senha[60];
};
void cadastro(){
    FILE *arquivo;
    struct usuarios u1;
    arquivo=fopen("dadoslogin.txt", "a");
    printf("Nome:");
    scanf("%[^\n]s", u1.nome);
    printf("Senha:");
    scanf("%[^\n]s", u1.senha);
}
void entrar(){

}
int login(){
    int opcao;
    
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
        return 1;
    }
    return 0;
}