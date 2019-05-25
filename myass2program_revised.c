/* Solution to comp20005 Assignment 2, 2019 semester 1.

   Authorship Declaration:

   (1) I certify that the program contained in this submission is completely
   my own individual work, except where explicitly noted by comments that
   provide details otherwise.  I understand that work that has been developed
   by another student, or by me in collaboration with other students,
   or by non-students as a result of request, solicitation, or payment,
   may not be submitted for assessment in this subject.  I understand that
   submitting for assessment work developed by or in collaboration with
   other students or non-students constitutes Academic Misconduct, and
   may be penalized by mark deductions, or by other penalties determined
   via the University of Melbourne Academic Honesty Policy, as described
   at https://academicintegrity.unimelb.edu.au.

   (2) I also certify that I have not provided a copy of this work in either
   softcopy or hardcopy or any other form to any other student, and nor will
   I do so until after the marks are released. I understand that providing
   my work to other students, regardless of my intention or any undertakings
   made to me by that other student, is also Academic Misconduct.

   (3) I further understand that providing a copy of the assignment
   specification to any form of code authoring or assignment tutoring
   service, or drawing the attention of others to such services and code
   that may have been made available via such a service, may be regarded
   as Student General Misconduct (interfering with the teaching activities
   of the University and/or inciting others to commit Academic Misconduct).
   I understand that an allegation of Student General Misconduct may arise
   regardless of whether or not I personally make use of such solutions
   or sought benefit from such actions.

   Signed by: [Kunaal Dipash Patel 944661]
   Dated:     [13/05/2019]

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_RECORDS 116

typedef struct
{
    char site[11];
    char station[7];
    char year[5];
    char month[3];
    char rainfall[6];
    char validated[2];
} data_point;

void read_file(char *file_name, data_point *entries)
{
    printf("%s\n", file_name);
    int parsedData;
    int i = 0;
    FILE *stream = fopen(file_name, "r");
    char line[128];

    if(stream == NULL) {
        perror("Failed to open file.");
        exit(1);
    }

    while (fgets(line, sizeof(line), stream) != NULL && i < NUM_RECORDS)
    {
        if (i > 0)
        {
            parsedData = sscanf(line, "%10[^,],%6[^,],%5[^,],%2[^,],%5[^,],%s\n", entries[i].site,
                entries[i].station, entries[i].year, entries[i].month, entries[i].rainfall, entries[i].validated);
            printf("%i\n", i);
            printf("%i\n", parsedData);
            printf("%s %s %s %s %s %s\n", entries[i].site, entries[i].station, entries[i].year,
                entries[i].month, entries[i].rainfall, entries[i].validated);
        }
        i++;
    }
    fclose(stream);
    return;
}

// void check_data(data_point *entries)
// {
//     int i;
//     for(i=0; i<NUM_RECORDS; i++)
//     {
//         printf("%i\n", i);
//         printf("%s,%s,%i,%s,%1f,%s\n", entries[i].site, entries[i].station,
//             entries[i].year, entries[i].month, entries[i].rainfall, entries[i].validated);
//     }
//     return;
// }

int main(int argc, char *argv[]) {
    printf("starting program ... \n");
    // printf("argc %d\n", argc);
    data_point entries[NUM_RECORDS];
    printf("reding data from input file: %s\n", argv[1]);
    read_file(argv[1], entries);
    // check_data(entries);
    return 0;
}
