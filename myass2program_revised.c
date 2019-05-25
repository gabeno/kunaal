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
#define MONTHS_IN_YEAR 12

typedef struct
{
    // char site[11];
    int station;
    int year;
    int month;
    float rainfall;
    char validated;
} data_point;

typedef struct
{
    int month;
    int num;
    float avg;
} monthly_average;

char *months[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void read_file(char *file_name, data_point *entries)
{
    printf("%s\n", file_name);
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
            sscanf(line, "IDCJAC0001,%d,%d,%d,%5f,%c",
                &entries[i].station, &entries[i].year, &entries[i].month, &entries[i].rainfall, &entries[i].validated);
        }
        i++;
    }
    fclose(stream);
    return;
}

void check_data(data_point *entries)
{
    int i;
    for(i=1; i<NUM_RECORDS; i++)
    {
        // printf("%i\n", i);
        printf("IDCJAC0001 %d %d %d %.1f %c\n", entries[i].station, entries[i].year,
            entries[i].month, entries[i].rainfall, entries[i].validated);
        // printf("%c, %i\n", entries[i].validated, entries[i].validated == 'Y');
    }
    return;
}

void show_rainfall_summary(data_point *entries)
{
    int i, j, currentYear, prevYear = 1111, m = 1;

    printf("S1, site number 086039, 115 datalines in input\n");
    // loop through our data
    for(j=1; j<NUM_RECORDS; j++)
    {
        currentYear = entries[j].year;
        while (prevYear != currentYear) {
            printf("S1, ");
            printf("%d: ", entries[j].year);
            for(i=1; i<=MONTHS_IN_YEAR; i++)
            {
                if (i == entries[m].month)
                {
                    if (entries[m].validated == 'N')
                    {
                        printf("%4s%s", months[i], "*");
                    }
                    else
                    {
                        printf("%4s ", months[i]);
                    }
                }
                else
                {
                    printf("%*s ", 4, "...");
                    continue;
                }
                m++;
            }
            printf("\n");
            prevYear = currentYear;
        }
    }
    return;
}

void get_monthly_averages(data_point *entries, monthly_average *monthly_averages)
{
    int i, j;
    float avg;
    for(i=1; i<=MONTHS_IN_YEAR; i++)
    {
        float sum = 0.0;
        int count = 0;
        // printf("%s\n", months[i]);
        // printf("%i\n", i);
        for(j=1; j<NUM_RECORDS; j++)
        {
            if (i == entries[j].month){
                // printf("%.1f\n", entries[j].rainfall);
                sum += entries[j].rainfall;
                count++;
            }
        }
        // printf("%.1f\n", sum);
        // printf("%i\n", count);
        avg = sum / count;
        // printf("%.1f\n", avg);
        monthly_averages[i].month = i;
        monthly_averages[i].avg = avg;
        monthly_averages[i].num = count;
    }
    return;
}

void show_rainfall_averages(monthly_average *monthly_averages) {
    int i;
    for(i=1; i<=MONTHS_IN_YEAR; i++) {
        printf("S2, ");
        printf("%s , ", months[monthly_averages[i].month]);
        printf("%2i ", monthly_averages[i].num);
        printf("values ");
        printf("mean of %.1fmm", monthly_averages[i].avg);
        printf("\n");
    }
}


int main(int argc, char *argv[]) {
    printf("starting program ... \n");
    // printf("argc %d\n", argc);
    data_point entries[NUM_RECORDS];
    monthly_average monthly_averages[MONTHS_IN_YEAR];
    printf("reding data from input file: %s\n", argv[1]);
    read_file(argv[1], entries);
    // check_data(entries);
    show_rainfall_summary(entries);
    get_monthly_averages(entries, monthly_averages);
    show_rainfall_averages(monthly_averages);
    return 0;
}
