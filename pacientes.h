#ifndef PACIENTES_H_INCLUDED
#define PACIENTES_H_INCLUDED

typedef struct paciente PACIENTE;
struct paciente
{
    char nome[50];
    char telefone[120];
    char idade[15];
    char cep[15];
    char email[100];
    char comorbidades[100];

};

void CadastrarPaciente(){
    PACIENTE paciente;
    int opcao;
    FILE* arquivo;


    arquivo = fopen("pacientes.bin","ab");  // escrita e binario
    if(arquivo == NULL)
    {
        printf("Problema ao tentar abrir o arquivo. \n");

    }else
        do{
            system("cls");
            fflush(stdin);
            desenha(24,5,100,20);
            gotoxy(26,5);
            printf(" CADASTRAR PACIENTE ");
            gotoxy(26,7);
            printf("Nome: ");
            gotoxy(26,8);
            printf("Idade: ");
            gotoxy(26,9);
            printf("3 - Sem ideias");
            gotoxy(26,10);
            printf("CEP: ");
            gotoxy(26,11);
            printf("Telefone: ");
            gotoxy(26,12);
            printf("Email: ");

            gotoxy(32,7);
            fflush(stdin);
            pegaLetras(paciente.nome);
            if (strcmp(paciente.nome,"")==0)break; 

            gotoxy(33,8);
            fflush(stdin);
            pegaDigito(paciente.idade);
            if (strcmp(paciente.idade,"")==0) break; 

            gotoxy(31,10);
            fflush(stdin);
            pegaDigito(paciente.cep);
            if (strcmp(paciente.cep,"")==0) break; 

            gotoxy(37,11);
            fflush(stdin);
            pegaDigito(paciente.telefone);
            if (strcmp(paciente.telefone,"")==0) break; 

            gotoxy(33,12);
            fflush(stdin);
            pegaEmail(paciente.email);
            if (strcmp(paciente.email,"")==0) break; 
        {
            fwrite(&paciente, sizeof(PACIENTE),1,arquivo);
            gotoxy(30,20);
            printf(" ---- CADASTRADO COM SUCESSO! DESEJA CONTINUAR CADASTRANDO ? ----- ");
            gotoxy(30,21);
            printf("      0 = NAO      ");
            gotoxy(30,22);
            printf("      1 = SIM      ");
            gotoxy(30,23);        
        }
        fflush(stdin);
        scanf("%d",&opcao);
        system("cls");
    }
    while(opcao != 0);
    fclose(arquivo); 
}
#endif