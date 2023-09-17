#include <stdio.h>0
#include <stdlib.h>

#define maxStudent 10
#define maxGrade 3

typedef struct S_student {

    int registration;
    char name[50];
    float grade[maxGrade];
    float media;

} student;

void registerStudent(student studentClass[], int *numStudent) {

    student newStudent;

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &newStudent.registration);

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]s", newStudent.name);

    for (int i = 0; i < maxGrade; i++) {
        printf("Digite a nota %d do aluno: ", i + 1);
        scanf("%f", &newStudent.grade[i]);

        while (newStudent.grade[i] < 0 || newStudent.grade[i] > 10) {
            printf("Digite um valor entre 0 e 10.\n");
            printf("Digite a nota %d do aluno: ", i + 1);
            scanf("%f", &newStudent.grade[i]);
        }
    }

    studentClass[*numStudent] = newStudent;
    (*numStudent)++;

    printf("Aluno cadastrado\n");
    
    if (*numStudent > maxStudent) {
        printf("Numero maximo de cadastros foi atingido.\n");

        return;
    }

}

void calculateAverage(student studentClass[], int numStudent) {

    for (int i = 0; i < numStudent; i++) {
        float sum = 0;

        for (int j = 0; j < maxGrade; j++) {

            sum += studentClass[i].grade[j];
        }

        studentClass[i].media = sum / maxGrade;
    }
}

void showResults(student studentClass[], int numStudent) {

    printf("\nResultados dos alunos:\n");

    for (int i = 0; i < numStudent; i++) {

        printf("\nAluno: %s\n", studentClass[i].name);
        printf("Media: %f\n", studentClass[i].media);
    
        if (studentClass[i].media >= 6) {

            printf("Aprovado\n");

        } else {

            printf("Reprovado\n");
        }
    }
}

int main() {

    student studentClass[maxStudent];
    int numStudent = 0;
    int opcao = 5;

    while (opcao != 0) {

        printf("\n Controle da turma e notas\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Calcular media dos alunos\n");
        printf("3 - Exibir resultados da turma\n");
        printf("0 - Sair\n");

        printf("\nDigite o numero desejado: ");
        scanf("%d", &opcao);

        if (opcao == 1) {

            registerStudent(studentClass, &numStudent);

        } else if (opcao == 2) {

            calculateAverage(studentClass, numStudent);

        } else if (opcao == 3) {

            showResults(studentClass, numStudent);

        } else if (opcao == 0) {

            printf("Saindo...");
            break;

        } else {

            printf("\nDigite um numero que esteja no menu\n");
        }
    }

    return 0;
}
