#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//var globais
int nsenhas = 0;
int erro = 0;

//=======DEFINE=FUNC-PRINCIPAIS===============================================================================================================================================================
void addusuario(char usuario[100][50], char senha[100][50], char senhaconfirma[50]);
void criptografa(char senha[100][50], char cripto[100][200]);
void erroo(char senha[20], char confirmacao[20]);
void lista(char usuario[100][50],char senha[100][50],char cripto[100][200]);
void alterusuario(char usuario[100][50], char senha[100][50], char senhaconfirma[50],int escolhausuario);  
//=======DEFINE=FUNC-SECUNDARIAS==============================================================================================================================================================
int compespc(char ch);
int compnum(char ch);
int completra(char ch);
//============================================================================================================================================================================================

int main() {
    char escolha[10];
    char usuario[100][50], senha[100][50], senhaconfirma[50], cripto[100][200];
    int escolhausuario,soun=0;

    system("cls");
    while (escolha[0] != 's') {
        printf("------Bem vindo!------\n\nO que deseja fazer?\n\n1 - Inclusao de Usuarios\n2 - Alterar Usuarios\n3 - Exclusao de Usuarios\n4 - Listagem de Usuarios\ns - Sair\n");
        fgets(escolha, sizeof(escolha), stdin);
        system("cls");
        switch (escolha[0]) {
            case '1':
                addusuario(usuario, senha, senhaconfirma);
                criptografa(senha, cripto);
                break;
            case '2':
               do {
                    system("cls");
                    printf("--------------------------------\n| Qual usuario deseja alterar? |\n--------------------------------\n");
                    lista(usuario, senha, cripto);
                    scanf("%d", &escolhausuario);
                    if (escolhausuario < 1 || escolhausuario > nsenhas) {
                        printf("Usuario invalido. Tente novamente.\n");
                        getchar(); // Limpa o buffer
                        continue;
                    }

                    system("cls");
                    printf("--------------------------------\n| Qual usuario deseja alterar? |\n--------------------------------\n");
                    printf("Usuario escolhido: %d - (%s)\nConfirmar escolha?\n1 - Sim\n2 - Nao\n", escolhausuario, usuario[escolhausuario - 1]);
                    scanf("%d", &soun);
                    system("cls"); 
                } while (soun != 1);

                alterusuario(usuario, senha, senhaconfirma, escolhausuario);
                criptografa(senha, cripto);

                escolhausuario = 0;  // Reseta a variável
                    
                break;
            case '3':
                //
                break;
            case '4':
                system("cls");
                lista(usuario,senha,cripto);
                printf("\n\nPressione Enter para continuar...");
                getchar();
                system("cls");
                break;
            default:
                break;
        }
    }
    return 0;
}

//============================================================================================================================================================================================

//==========funcoes comp (que comparam a string, identificando se há caracteres)==============================================================================================================
int compnum(char ch)  { // verificar se a senha tem um numero
    return isdigit(ch); } 
int compespc(char ch) { // verificar se tem carac especial
    char especiais[] = "!@#$%¨&*()_+{}[]|;:<>,./?~^`-=";
    for (int j = 0; j < strlen(especiais); j++) {
        if (ch == especiais[j]) return 1;
    }
    return 0;
}
int completra(char ch){// verificar se tem letra (funcao isalpha ve se tem caracter de A a Z na string)
    return isalpha(ch); } 
//============================================================================================================================================================================================
void erroo(char senha[20], char confirmacao[20]) {// funcao paraa verificar TODOS os possiveis erros
    erro = 0; //reseta erro

    int temEspecial = 0, temNumero = 0, temLetra = 0;
    for (int x = 0; senha[x] != '\0'; x++) {
        if (senha[x] == ' ') { // ve se tem espaços
            erro = 1;
            printf("A senha nao pode conter espaços...\n");
            return;
        }
        if (compespc(senha[x])) temEspecial = 1;
        if (compnum(senha[x])) temNumero = 1;
        if (completra(senha[x])) temLetra = 1;
    }

    
    if (!temEspecial) {//se nn tiver especial
        erro = 1;
        printf("\nA senha deve conter pelo menos um caractere especial.\n");
        printf("Pressione Enter para continuar...");
        getchar();
    } else if (!temNumero) {//se nn tiver numero
        erro = 1;
        printf("\nA senha deve conter pelo menos um numero.\n");
        printf("Pressione Enter para continuar...");
        getchar();
    } else if (!temLetra) {//se nn tiver letra
        erro = 1;
        printf("\nA senha deve conter pelo menos uma letra.\n");
        printf("Pressione Enter para continuar...");
        getchar();
    } else if (strcmp(senha, confirmacao) != 0) {//se senha!=confirmacao
        erro = 1;
        printf("\nAs senhas nao conferem! Tente novamente.\n");
        printf("Pressione Enter para continuar...");
        getchar();
    }else if(strlen(senha)<8 || strlen(senha)>20){
        erro = 1;
        printf("\nA senha deve ter no minimo 8 caracteres e no maximo 20 caracteres.\n");
        printf("Pressione Enter para continuar...");
        getchar();
    }
    
}

void addusuario(char usuario[100][50], char senha[100][50], char senhaconfirma[50]) {
    int simounao;
    int i = nsenhas;

    do {
        printf("\nUsuario: ");
        fgets(usuario[i], sizeof(usuario[i]), stdin);
        usuario[i][strcspn(usuario[i], "\n")] = '\0';
        system("cls");
        do {
            printf("\nUsuario: %s",usuario[i]);
            erro = 0; // Reseta erro

            printf("\nSenha: ");
            fgets(senha[i], sizeof(senha[i]), stdin);
            senha[i][strcspn(senha[i], "\n")] = '\0';

            printf("Confirme a senha: ");
            fgets(senhaconfirma, 50, stdin);
            senhaconfirma[strcspn(senhaconfirma, "\n")] = '\0';

            erroo(senha[i], senhaconfirma); // Função verificar erros
            
            system("cls");
        } while (erro != 0);

        printf("\nUsuario incluido com sucesso!");
        system("cls");
        nsenhas++;
        printf("\nDeseja incluir mais usuarios?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &simounao);
        getchar();
        system("cls");
        i++;

    } while (simounao == 1);
}

void lista(char usuario[100][50],char senha[100][50],char cripto[100][200]){ //funcao para listar usuarios
    for (int i = 0; i < nsenhas; i++) {
        printf("\n-------------------------------------------------------\n");
        printf("%d - Usuario: %s\n", i+1,usuario[i]);
        printf("     Senha: %s\n", senha[i]);
        printf("     Criptografada: %s\n", cripto[i]);
        printf("-------------------------------------------------------\n");
        }
}

void alterusuario(char usuario[100][50], char senha[100][50], char senhaconfirma[50],int escolhausuario) {
    
    escolhausuario=escolhausuario-1;

    fflush(stdin);
    printf("\nNovo nome de usuario: ");
    fgets(usuario[escolhausuario], sizeof(usuario[escolhausuario]), stdin);
    usuario[escolhausuario][strcspn(usuario[escolhausuario], "\n")] = '\0';//adicionando /0 no ultimo caractere
    system("cls");

    do {
        printf("\nNovo nome de usuario: %s",usuario[escolhausuario]);
        erro = 0; // Reseta erro

        printf("\nNova senha: ");
        fgets(senha[escolhausuario], sizeof(senha[escolhausuario]), stdin);
        senha[escolhausuario][strcspn(senha[escolhausuario], "\n")] = '\0';

        printf("Confirme a nova senha: ");
        fgets(senhaconfirma, 50, stdin);
        senhaconfirma[strcspn(senhaconfirma, "\n")] = '\0';

        erroo(senha[escolhausuario], senhaconfirma); // Função verificar erros
            
        system("cls");
    } while (erro != 0);

    printf("\nUsuario alterado com sucesso!");
    printf("\n\nPressione Enter para continuar...");
    getchar();
    system("cls");

    
}

void criptografa(char senha[100][50], char cripto[100][200]) {
    for (int i = 0; i < nsenhas; i++) {
        cripto[i][0] = '\0';
        int x = 0;
        while (senha[i][x] != '\0') {
            switch (senha[i][x]) {
                case 'a':
                    strcat(cripto[i], "trs!");
                    break;
                case 'b':
                    strcat(cripto[i], "34$");
                    break;
                case 'c':
                    strcat(cripto[i], "@d^");
                    break;
                case 'd':
                    strcat(cripto[i], "67#");
                    break;
                case 'e':
                    strcat(cripto[i], "!q*");
                    break;
                case 'f':
                    strcat(cripto[i], "12%");
                    break;
                case 'g':
                    strcat(cripto[i], "#y&");
                    break;
                case 'h':
                    strcat(cripto[i], "89(");
                    break;
                case 'i':
                    strcat(cripto[i], "++h)");
                    break;
                case 'j':
                    strcat(cripto[i], "*3-");
                    break;
                case 'k':
                    strcat(cripto[i], "(8=");
                    break;
                case 'l':
                    strcat(cripto[i], "&5+");
                    break;
                case 'm':
                    strcat(cripto[i], "0p<");
                    break;
                case 'n':
                    strcat(cripto[i], "^1>");
                    break;
                case 'o':
                    strcat(cripto[i], "4u?");
                    break;
                case 'p':
                    strcat(cripto[i], "$a/");
                    break;
                case 'q':
                    strcat(cripto[i], "7r|");
                    break;
                case 'r':
                    strcat(cripto[i], "6t:");
                    break;
                case 's':
                    strcat(cripto[i], "+w;");
                    break;
                case 't':
                    strcat(cripto[i], "x9.");
                    break;
                case 'u':
                    strcat(cripto[i], "-b,");
                    break;
                case 'v':
                    strcat(cripto[i], "=j{");
                    break;
                case 'w':
                    strcat(cripto[i], ";v}");
                    break;
                case 'x':
                    strcat(cripto[i], ">c~");
                    break;
                case 'y':
                    strcat(cripto[i], "?f[");
                    break;
                case 'z':
                    strcat(cripto[i], ":z]");
                    break;
                case '0':
                    strcat(cripto[i], "_z!");
                    break;
                case '1':
                    strcat(cripto[i], "(p$");
                    break;
                case '2':
                    strcat(cripto[i], "+s@");
                    break;
                case '3':
                    strcat(cripto[i], "/h#");
                    break;
                case '4':
                    strcat(cripto[i], "|k%");
                    break;
                case '5':
                    strcat(cripto[i], "<q^");
                    break;
                case '6':
                    strcat(cripto[i], "}a&");
                    break;
                case '7':
                    strcat(cripto[i], "^g*");
                    break;
                case '8':
                    strcat(cripto[i], ".b(");
                    break;
                case '9':
                    strcat(cripto[i], ",j)");
                    break;
                case ' ':
                    strcat(cripto[i], "J");
                    break;
                case '!':
                    strcat(cripto[i], "*#");
                    break;
                case '@':
                    strcat(cripto[i], "+$");
                    break;
                case '#':
                    strcat(cripto[i], "^&");
                    break;
                case '$':
                    strcat(cripto[i], "!pi");
                    break;
                case '%':
                    strcat(cripto[i], "~^");
                    break;
                case '&':
                    strcat(cripto[i], "(|");
                    break;
                case '*':
                    strcat(cripto[i], "9@");
                    break;
                case '(':
                    strcat(cripto[i], "){");
                    break;
                case ')':
                    strcat(cripto[i], "}[" );
                    break;
                case '-':
                    strcat(cripto[i], "=/");
                    break;
                case '+':
                    strcat(cripto[i], "|;");
                    break;
                case '=':
                    strcat(cripto[i], "?<");
                    break;
                case '{':
                    strcat(cripto[i], "}>");
                    break;
                case '}':
                    strcat(cripto[i], "[<");
                    break;
                case '[':
                    strcat(cripto[i], "]>");
                    break;
                case ']':
                    strcat(cripto[i], "^");
                    break;
                case ';':
                    strcat(cripto[i], ",~");
                    break;
                case ':':
                    strcat(cripto[i], ".?");
                    break;
                case '"':
                    strcat(cripto[i], "'s");
                    break;
                case '\'':
                    strcat(cripto[i], "a'");
                    break;
                case '<':
                    strcat(cripto[i], ">b");
                    break;
                case '>':
                    strcat(cripto[i], "/c");
                    break;
                case ',':
                    strcat(cripto[i], "-=pd");
                    break;
                case '.':
                    strcat(cripto[i], "~f");
                    break;
                case '?':
                    strcat(cripto[i], "!g");
                    break;
                case '/':
                    strcat(cripto[i], "$h");
                    break;
                case '\\':
                    strcat(cripto[i], "^j");
                    break;
                default:
                    strncat(cripto[i], &senha[i][x], 1);
                    break;
            }
            x++; 
        }
    }
}
//============================================================================================================================================================================================