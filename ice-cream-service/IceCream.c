
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define queue_capacity 100
#define EAC_queue_capacity 100
#define length_of_name 11


struct Customer {
	char name[length_of_name];
	char age_group;
};

struct Customer customerQueue[queue_capacity];
struct Customer ElderQueue[EAC_queue_capacity];
struct Customer AdultQueue[EAC_queue_capacity];
struct Customer ChildrenQueue[EAC_queue_capacity];

int generalIndex = 0;
int E_head = 0, E_tail = 0;
int A_head = 0, A_tail = 0;
int C_head = 0, C_tail = 0;

int main() {
	char ServeOrNew[25], name[50];
	char ageCtgry;
	int num;
	FILE* inputf, * outputf;

	inputf = fopen("input.txt", "r");
	if (inputf == NULL) {
		printf("ERROR! The file was not opened!");
		return;
	}
	else {

		while (fscanf(inputf, "%s", ServeOrNew) != -1) {
			int conTab = fscanf(inputf, "%d", &conTab);
			if (strcmp(ServeOrNew, "NewCustomer") == 0)
			{
				int getInfo = fscanf(inputf, "%c%s", &ageCtgry, &name);
				if (ageCtgry == 'E') {
					if ((E_tail < EAC_queue_capacity) && (strlen(name) < length_of_name)) {
						strcpy(ElderQueue[E_tail].name, name);
						ElderQueue[E_tail].age_group = 'E';
						E_tail++;
					} 
				}

				else if (ageCtgry == 'A') {
					if ((A_tail < EAC_queue_capacity) && (strlen(name) < length_of_name)) {
						strcpy(AdultQueue[A_tail].name, name);
						AdultQueue[A_tail].age_group = 'A';
						A_tail++;
					} 
				}

				else if (ageCtgry == 'C') {
					if ((C_tail < EAC_queue_capacity) && (strlen(name) < length_of_name)) {
						strcpy(ChildrenQueue[C_tail].name, name);
						ChildrenQueue[C_tail].age_group = 'C';
						C_tail++;
					} 
				}
			}

			else if (strcmp(ServeOrNew, "ServeCustomers") == 0) {

				int getInfo = fscanf(inputf, "%c%d", &ageCtgry, &num);

				if (ageCtgry == 'E') {
					while (num > 0) {

						if ((E_tail > E_head)) {
							if (generalIndex < queue_capacity) {
								strcpy(customerQueue[generalIndex].name, ElderQueue[E_head].name);
								customerQueue[generalIndex].age_group = 'E';
								generalIndex++;
								E_head++;
							}
						}

						else {
							if (generalIndex < queue_capacity) {
								strcpy(customerQueue[generalIndex].name, "*****");
								customerQueue[generalIndex].age_group = 'E';
								generalIndex++;
							}
						} 
						num--;
					}
				}

				if (ageCtgry == 'A') {
					while (num > 0) {

						if ((A_tail > A_head)) {
							if (generalIndex < queue_capacity) {
								strcpy(customerQueue[generalIndex].name, AdultQueue[A_head].name);
								customerQueue[generalIndex].age_group = 'A';
								generalIndex++;
								A_head++;
							}
						}

						else {
							if (generalIndex < queue_capacity) {
								strcpy(customerQueue[generalIndex].name, "*****");
								customerQueue[generalIndex].age_group = 'A';
								generalIndex++;
							}
						} 
						num--;
					}
				}

				if (ageCtgry == 'C') {
					while (num > 0) {
						if ((C_tail > C_head)) {
							if (generalIndex < queue_capacity) {
								strcpy(customerQueue[generalIndex].name, ChildrenQueue[C_head].name);
								customerQueue[generalIndex].age_group = 'C';
								generalIndex++;
								C_head++;
							}
						}

						else {
							if (generalIndex < queue_capacity) {
								strcpy(customerQueue[generalIndex].name, "*****");
								customerQueue[generalIndex].age_group = 'C';
								generalIndex++;
							}						
						} 
						num--;
					}
				}
			}
		}
	}

	fclose(inputf);

	outputf = fopen("output.txt", "w"); 
	if (outputf == NULL){
		printf("\nERROR! The file was not opened!");
		exit(0);
	}

	while (generalIndex >= 0)
	{
		fprintf(outputf, "%c	%s\n", customerQueue[generalIndex].age_group, customerQueue[generalIndex].name);
		generalIndex--;
	}

	fclose(outputf);
	return 0;
}

