#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef
struct SStudent_{
    char name[256];
    int group;
    float rating;
}SStudent;

int Input(FILE* input_file, SStudent** student_array, int number_of_students);
int Input(FILE* input_file, SStudent** student_array, int number_of_students){
    SStudent* input_student_array;
    SStudent input_student;
    int student_group;
    char student_name[256];
    float student_rating;
    input_student_array = (SStudent*)malloc(number_of_students*sizeof(SStudent));
    for (int h= 0 ; h < number_of_students; h++){
        student_group = 0;
        student_name[0] = 'a';
        student_name[1] = '_';
        student_rating = -0.1;
        fscanf(input_file, "%d", &student_group);
        fscanf(input_file, "%s", &student_name);
        fscanf(input_file, "%g", &student_rating);
        if (student_group == 0 || (student_rating + 0.1 < 0.0001) || student_name[1] == '_'){
            printf("Error! Incorrect data in the input file\n");
            exit(-2);
        }
        input_student.group = student_group;
        input_student.rating  =student_rating;
        strcpy(input_student.name, student_name);
        input_student_array[h] = input_student;
    }
    for (int h = 0; h < number_of_students; h++){
        student_array[h] = &(input_student_array[h]);
    }
}

int Output(SStudent** student_array, int number_of_students);
int Output(SStudent** student_array, int number_of_students){
    for (int j = 0; j < number_of_students; j++){
        printf("Student's group is %d, student's name is %s, student's rating is %g\n", (*student_array[j]).group, (*student_array[j]).name, (*student_array[j]).rating);
    }
}

int Sort(SStudent** student_array, int number_of_students);
int Sort(SStudent** student_array, int number_of_students){
    SStudent temp_student;
    for (int k = 0; k < number_of_students; k++){
        for (int j = 0; j < number_of_students-1; j++){
            if ((*student_array[j]).rating < (*student_array[j+1]).rating){
                temp_student = (*student_array[j]);
                (*student_array[j]) = (*student_array[j+1]);
                (*student_array[j+1]) = temp_student;
            }
        }
    }
}
int Change_Groups(SStudent** student_array, int number_of_students);
int Change_Groups(SStudent** student_array, int number_of_students){
    int top_group, change_flag, index;
    top_group = (*student_array[0]).group;
    for (int i = 1; i < number_of_students; i++){
        change_flag = 0;
        if ((*student_array[i]).group != top_group){
            for (int k = i+1;k < number_of_students; k++){
                if (change_flag == 0){
                    if ((*student_array[k]).group == top_group){
                        change_flag++;
                        (*student_array[k]).group = (*student_array[i]).group;
                        (*student_array[i]).group = top_group;
                    }
                }
            }
        }
    }
}

int Autotest(void);
int Autotest(void){
    FILE* testfile;
    SStudent** test_student_array = NULL;
    SStudent temp_student;
    testfile = fopen("C:\\Users\\mihai\\Desktop\\progy\\test.txt", "r");
    test_student_array = (SStudent**)malloc(4*sizeof(SStudent*));
    Input(testfile, test_student_array, 4);
    Sort(test_student_array, 4);
    Change_Groups(test_student_array, 4);
    if ((*test_student_array[1]).name[0] == 'B'){
        printf("Autotest passed successfully\n");
    }
    else{
        printf("Autotest not passed\n");
        exit(-4);
    }
    fclose(testfile);
    free(test_student_array);
}

int main(void){
    SStudent student;
    SStudent** student_array = NULL;
    char scan_temp[256];
    int number_of_students = 0;
    FILE* file;
    file = fopen("C:\\Users\\mihai\\Desktop\\progy\\data.txt", "r");
    if (!file){
        printf("Error: cannot open file");
        exit(-4);
    }
    while (fgets(scan_temp, sizeof(scan_temp), file) != NULL){
        number_of_students++;
    }
    if (number_of_students == 1){
        printf("There is only 1 student in the input file\n");
        exit(-3);
    }
    if (number_of_students == 0){
        printf("Error: there are no students in the input file\n");
    }
    fseek(file, 0, 0);
    student_array = (SStudent**)malloc(number_of_students*sizeof(SStudent*));
    Input(file, student_array, number_of_students);
    Autotest();
    printf("Input is:\n");
    Output(student_array, number_of_students);
    Sort(student_array, number_of_students);
    Change_Groups(student_array, number_of_students);
    printf("----------Changed Groups------------\n");
    Output(student_array, number_of_students);
    fclose(file);
    free(student_array);
    return 0;
}
