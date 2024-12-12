#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256

void calculate_and_write(const char* input_filename) {
    char output_filename[MAX_FILENAME];
    FILE* input_file = fopen(input_filename, "r");

    snprintf(output_filename, MAX_FILENAME, "%sparity1.txt", input_filename); //записывает отформатированную строку в указанную строку-память

    FILE* output_file = fopen(output_filename, "w");
    
    double prev_number, curr_number;
    int is_first_number = 1;
    int count = 0;

    while (fscanf(input_file, "%lf", &curr_number) == 1) {
        count++;
        if (!is_first_number) {
            double average = (prev_number + curr_number) / 2;
            fprintf(output_file, "%.6f\n", average);
        }
        prev_number = curr_number;
        is_first_number = 0;
    }

    if (count == 0) {
        printf("Input file is empty.\n");
    }
    else if (count == 1) {
        printf("File consist only one number\n");
    }

    fclose(input_file);
    fclose(output_file);

    if (count > 1) {
        printf("Result write in file: %s\n", output_filename);
    }
}

int main() {
    char input_filename[MAX_FILENAME];
    system("color F0");

    printf("Write name of input file: ");
    if (scanf("%255s", input_filename) != 1) {
        fprintf(stderr, "Error file read.\n");
        return 1;
    }

    calculate_and_write(input_filename);

}
