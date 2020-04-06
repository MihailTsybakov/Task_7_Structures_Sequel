#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef
struct SStudent_{
    int group;
    char name[256];
    float rating;
}SStudent;

int main(void){
    FILE* input_file;
    SStudent* student_array = NULL;
    char* temp_string;
    float rating;
    char scan_temp[256], student_name[256];
    int number_of_students = 0, student_group;
    input_file = fopen("C:\\Users\\mihai\\Desktop\\progy\\data.txt","r");
    while (fgets(scan_temp, sizeof(scan_temp), input_file) != NULL){
        number_of_students++;
    }
    fseek(input_file, 0, 0);
    student_array = (SStudent*)malloc(number_of_students*sizeof(SStudent));
    for (int i = 0; i < number_of_students; i++){

    }
}
