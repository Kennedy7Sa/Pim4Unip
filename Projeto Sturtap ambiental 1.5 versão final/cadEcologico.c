#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_EMPRESAS 100
#define MESES_NO_ANO 12

typedef struct {
    char nome[50];
    char cnpj[15];
    char razaoSocial[100];
    char dataAbertura[20];
    char telefone[15];
    char endereco[100];
    char numero[10];
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[10];
    char email[50];
    char nomeResponsavel[50];
    char cpfResponsavel[15];

    float residuosMensais[MESES_NO_ANO];
    float custoEstimadoMensal[MESES_NO_ANO];
    float somaResiduosAnual;
    float somaCustoAnual;
} Empresa;

typedef struct {
    char username[20];
    char password[20];
} Usuario;

const char *nomeMes(int numeroMes) {
    switch (numeroMes) {
        case 1: return "Janeiro";
        case 2: return "Fevereiro";
        case 3: return "Março";
        case 4: return "Abril";
        case 5: return "Maio";
        case 6: return "Junho";
        case 7: return "Julho";
        case 8: return "Agosto";
        case 9: return "Setembro";
        case 10: return "Outubro";
        case 11: return "Novembro";
        case 12: return "Dezembro";
        default: return "Mês Inválido";
    }
}

int realizarLogin(Usuario usuarios[], int *numUsuarios) {
    char username[20];
    char password[20];

    printf("\n----- Login -----\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0) {
        printf("Login do administrador bem-sucedido!\n");
        return 2;
    }

    for (int i = 0; i < *numUsuarios; i++) {
        if (strcmp(username, usuarios[i].username) == 0 &&
            strcmp(password, usuarios[i].password) == 0) {
            printf("Login bem-sucedido!\n");
            return 1;
        }
    }

    printf("Login falhou. Verifique suas credenciais.\n");
    return 0;
}

void cadastrarUsuario(Usuario usuarios[], int *numUsuarios) {
    printf("\n----- Cadastro de Usuario -----\n");
    printf("Digite o novo username: ");
    scanf("%s", usuarios[*numUsuarios].username);
    printf("Digite a nova senha: ");
    scanf("%s", usuarios[*numUsuarios].password);

    (*numUsuarios)++;
    printf("Usuario cadastrado com sucesso!\n");
}

void cadastrarEmpresa(Empresa empresas[], int *numEmpresas) {
    printf("\n-------------Cadastrando nova empresa----------------\n");
    printf("\nDigite o nome da empresa: ");
    scanf(" %49[^\n]", empresas[*numEmpresas].nome);

    printf("Digite o CNPJ da empresa: ");
    scanf(" %14s", empresas[*numEmpresas].cnpj);

    printf("Digite a razao social da empresa: ");
    scanf(" %99[^\n]", empresas[*numEmpresas].razaoSocial);

    printf("Digite a data de abertura da empresa: ");
    scanf(" %19s", empresas[*numEmpresas].dataAbertura);

    printf("Digite o telefone da empresa: ");
    scanf(" %14s", empresas[*numEmpresas].telefone);

    printf("\n* Endereço da empresa *\n");
    printf("Digite o numero da empresa: ");
    scanf(" %9s", empresas[*numEmpresas].numero);

    printf("Digite a rua da empresa: ");
    scanf(" %49[^\n]", empresas[*numEmpresas].rua);

    printf("Digite o bairro da empresa: ");
    scanf(" %49[^\n]", empresas[*numEmpresas].bairro);

    printf("Digite a cidade da empresa: ");
    scanf(" %49[^\n]", empresas[*numEmpresas].cidade);

    printf("Digite o estado da empresa: ");
    scanf(" %2s", empresas[*numEmpresas].estado);

    printf("Digite o CEP da empresa: ");
    scanf(" %9s", empresas[*numEmpresas].cep);

    printf("Digite o e-mail da empresa: ");
    scanf(" %49[^\n]", empresas[*numEmpresas].email);

    printf("\n* Responsavel pela empresa *\n");
    printf("Digite o nome do responsavel da empresa: ");
    scanf(" %49[^\n]", empresas[*numEmpresas].nomeResponsavel);

    printf("Digite o CPF do responsavel da empresa: ");
    scanf(" %14s", empresas[*numEmpresas].cpfResponsavel);

    // Loop para preencher os resíduos mensais
    for (int i = 0; i < MESES_NO_ANO; i++) {
        printf("Digite os resíduos sólidos em Kg da empresa em %s: ", nomeMes(i + 1));
        scanf("%f", &empresas[*numEmpresas].residuosMensais[i]);
    }

    // Loop para preencher os custos
    for (int i = 0; i < MESES_NO_ANO; i++) {
        printf("Digite o custo estimado em R$ da empresa em %s: ", nomeMes(i + 1));
        scanf("%f", &empresas[*numEmpresas].custoEstimadoMensal[i]);
    }

    // Calculando a soma dos resíduos e custos anuais
    empresas[*numEmpresas].somaResiduosAnual = 0;
    empresas[*numEmpresas].somaCustoAnual = 0;

    for (int i = 0; i < MESES_NO_ANO; i++) {
        empresas[*numEmpresas].somaResiduosAnual += empresas[*numEmpresas].residuosMensais[i];
        empresas[*numEmpresas].somaCustoAnual += empresas[*numEmpresas].custoEstimadoMensal[i];
    }

    printf("\n Soma da quantidade anual de Resíduos %.2f", empresas[*numEmpresas].somaResiduosAnual);
    printf("\n Soma do custo anual da empresa %.2f", empresas[*numEmpresas].somaCustoAnual);

    (*numEmpresas)++;
    printf("\n-------Empresa cadastrada com sucesso!--------\n");
}

void listarEmpresas(Empresa empresas[], int numEmpresas) {
    printf("\nListagem de Empresas:\n");
    for (int i = 0; i < numEmpresas; i++) {
        printf("\nNome: %s\n", empresas[i].nome);
        printf("CNPJ: %s\n", empresas[i].cnpj);
        printf("Razao Social: %s\n", empresas[i].razaoSocial);
        printf("Data de Abertura: %s\n", empresas[i].dataAbertura);
        printf("Telefone: %s\n", empresas[i].telefone);
        printf("\n* Endereço da empresa *\n");
        printf("Numero: %s\n", empresas[i].numero);
        printf("Rua: %s\n", empresas[i].rua);
        printf("Bairro: %s\n", empresas[i].bairro);
        printf("Cidade: %s\n", empresas[i].cidade);
        printf("Estado: %s\n", empresas[i].estado);
        printf("CEP: %s\n", empresas[i].cep);
        printf("Email: %s\n", empresas[i].email);
        printf("\n* Responsavel pela empresa *\n");
        printf("Nome do Responsavel: %s\n", empresas[i].nomeResponsavel);
        printf("CPF do Responsavel: %s\n", empresas[i].cpfResponsavel);
        printf("Soma da quantidade anual de Resíduos: %.2f\n", empresas[i].somaResiduosAnual);
        printf("Soma do custo anual da empresa: %.2f\n", empresas[i].somaCustoAnual);
        printf("\n--------------------------------------\n");
    }
}

void atualizarCadastro(Empresa empresas[], int numEmpresas) {
    char cnpj[15];
    int encontrada = 0;

    printf("\nDigite o CNPJ da empresa que deseja atualizar: ");
    scanf("%s", cnpj);

    for (int i = 0; i < numEmpresas; i++) {
        if (strcmp(cnpj, empresas[i].cnpj) == 0) {
            printf("\nDigite o novo nome da empresa: ");
            scanf("%s", empresas[i].nome);

            // Loop para atualizar os resíduos mensais
            for (int j = 0; j < MESES_NO_ANO; j++) {
                printf("Digite os resíduos sólidos em Kg da empresa em %s: ", nomeMes(j + 1));
                scanf("%f", &empresas[i].residuosMensais[j]);
            }

            printf("Cadastro atualizado com sucesso!\n");
            encontrada = 1;
            break;
        }
    }

    if (!encontrada) {
        printf("Empresa não encontrada.\n");
    }
}

void excluirEmpresa(Empresa empresas[], int *numEmpresas) {
    char cnpj[15];
    int encontrada = 0;

    printf("\nDigite o CNPJ da empresa que deseja excluir: ");
    scanf(" %s", cnpj);

    for (int i = 0; i < *numEmpresas; i++) {
        if (strcmp(cnpj, empresas[i].cnpj) == 0) {
            // Move a última empresa para a posição da empresa a ser excluída
            empresas[i] = empresas[(*numEmpresas) - 1];
            (*numEmpresas)--;
            printf("Empresa excluida com sucesso!\n");
            encontrada = 1;
            break;
        }
    }

    if (!encontrada) {
        printf("Empresa não encontrada.\n");
    }
}

void gerarRelatorio(Empresa empresas[], int numEmpresas) {
    FILE *arquivo;
    char nomeArquivo[50];

    printf("\nDigite o nome do arquivo para salvar o relatorio (inclua a extensao .txt): ");
    scanf(" %s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Relatorio de Empresas:\n");
    for (int i = 0; i < numEmpresas; i++) {
        fprintf(arquivo, "Nome: %s\n", empresas[i].nome);
        fprintf(arquivo, "CNPJ: %s\n", empresas[i].cnpj);
        fprintf(arquivo, "Razao Social: %s\n", empresas[i].razaoSocial);
        fprintf(arquivo, "Data de Abertura: %s\n", empresas[i].dataAbertura);
        fprintf(arquivo, "Telefone: %s\n", empresas[i].telefone);
        fprintf(arquivo, "\n* Endereço da empresa *\n");
        fprintf(arquivo, "Numero: %s\n", empresas[i].numero);
        fprintf(arquivo, "Rua: %s\n", empresas[i].rua);
        fprintf(arquivo, "Bairro: %s\n", empresas[i].bairro);
        fprintf(arquivo, "Cidade: %s\n", empresas[i].cidade);
        fprintf(arquivo, "Estado: %s\n", empresas[i].estado);
        fprintf(arquivo, "CEP: %s\n", empresas[i].cep);
        fprintf(arquivo, "Email: %s\n", empresas[i].email);
        fprintf(arquivo, "\n* Responsavel pela empresa *\n");
        fprintf(arquivo, "Nome do Responsavel: %s\n", empresas[i].nomeResponsavel);
        fprintf(arquivo, "CPF do Responsavel: %s\n", empresas[i].cpfResponsavel);
        fprintf(arquivo, "Soma da quantidade anual de Resíduos: %.2f\n", empresas[i].somaResiduosAnual);
        fprintf(arquivo, "Soma do custo anual da empresa: %.2f\n", empresas[i].somaCustoAnual);
        fprintf(arquivo, "\n--------------------------------------\n");
    }

    fclose(arquivo);
    printf("Relatorio salvo com sucesso!\n");
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("\n1. Cadastrar Empresa\n");
    printf("2. Listar Empresas\n");
    printf("3. Atualizar Cadastro de custo e residuos Empresa\n");
    printf("4. Excluir Empresa\n");
    printf("5. Gerar Relatorio de Empresas e Salvar\n");
    printf("6. Cadastrar novo Usuario\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Usuario usuarios[2];
    strcpy(usuarios[0].username, "user1");
    strcpy(usuarios[0].password, "pass1");
    strcpy(usuarios[1].username, "user2");
    strcpy(usuarios[1].password, "pass2");
    int numUsuarios = 2;

    int opcao;
    int numEmpresas = 0;
    Empresa empresas[MAX_EMPRESAS];
    int loginSucesso = 0;
    do {
        if (!loginSucesso) {
            printf("\n----- Sistema de Cadastro de Empresas para uma Startup ecologica-----\n");
            printf("1. Realizar Login\n");
            printf("2. Cadastrar Novo Usuario\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    loginSucesso = realizarLogin(usuarios, &numUsuarios);
                    break;
                case 2:
                    cadastrarUsuario(usuarios, &numUsuarios);
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
            }
        } else {
            printf("\n----- Sistema de Cadastro de Empresas -----\n");
            exibirMenu();
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    cadastrarEmpresa(empresas, &numEmpresas);
                    break;
                case 2:
                    listarEmpresas(empresas, numEmpresas);
                    break;
                case 3:
                    atualizarCadastro(empresas, numEmpresas);
                    break;
                case 4:
                    excluirEmpresa(empresas, &numEmpresas);
                    break;
                case 5:
                    gerarRelatorio(empresas, numEmpresas);
                    break;
                case 6:
                    cadastrarUsuario(usuarios, &numUsuarios);
                    break;
                case 7:
                    printf("Saindo do programa. Obrigado!\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                    break;
            }
        }
    } while (opcao != 7);

    return 0;
}
