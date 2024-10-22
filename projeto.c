#include <stdio.h>
#include <string.h>
#include <conio.h>

int nsenhas = 0;
//=======DEFINE=FUNC=======================================================================================================================================================================================================  
void addusuario(char usuario[][50], char senha[][20], char senhaconfirma[20]);
void criptografa(char senha[100][20], char cripto[100][100]);
//=========================================================================================================================================================================================================================  
int main() {
//=======VAR===============================================================================================================================================================================================================  
    char escolha[10];
    char usuario[100][50], senha[100][20], senhaconfirma[20], cripto[100][100];
//=======INICIO============================================================================================================================================================================================================  
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
                // 
                break;
            case '3':
                // 
                break;
            case '4':
                system("cls");
                for (int i = 0; i < nsenhas; i++) {
                    printf("Usuario: %s\n", usuario[i]);
                    printf("Senha: %s\n", senha[i]);
                    printf("Criptografada: %s\n", cripto[i]);
                    printf("\n");
                }
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
//=======INICIO=FUNC=========================================================================================================================================================================================================
void addusuario(char usuario[][50], char senha[][20], char senhaconfirma[20]) {
    int erro=0, simounao;
    int i = nsenhas;
    do {
        printf("\nusuario: ");
        fgets(usuario[i], sizeof(usuario[i]), stdin);
        usuario[i][strcspn(usuario[i], "\n")] = '\0'; // p garantir que n vai ler uma nova linha
        system("cls");

        do {
            erro = 0;
            
            printf("\nsenha: ");
            fgets(senha[i], sizeof(senha[i]), stdin);
            senha[i][strcspn(senha[i], "\n")] = '\0';  
            
            printf("confirme a senha: ");
            fgets(senhaconfirma, 50, stdin);
            senhaconfirma[strcspn(senhaconfirma, "\n")] = '\0'; 
            
            if (strcmp(senha[i], senhaconfirma) != 0) {
                erro = 1;
                printf("\nAs senhas nao conferem! Tente novamente.");
                printf("\nPressione Enter para continuar...");
                getchar();
                system("cls");
            }

            system("cls");
        } while (erro !=0);

        printf("\nUsuario incluido com sucesso!");
        nsenhas++; // senha aumenta 1
        printf("\nDeseja incluir mais usuarios?\n\n1 - Sim\n2 - Nao\n");
        scanf(" %d", &simounao);
        getchar(); 
        system("cls");
        i++;
    } while (simounao == 1);
}


void criptografa(char senha[][20], char cripto[100][100]) {
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
//=========================================================================================================================================================================================================================  