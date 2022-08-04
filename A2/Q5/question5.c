#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

float avgCSV (char* inputName){
	float a = 0;
	char s_a[100];
	int num_numbers = 0;
	float sum = 0;
	char temp_line[200];
	int i = 0;
	int position = 0;
	int num_rows = 0;

	FILE *fp = fopen(inputName, "r");
	while(fscanf(fp, "%[^\n] ", temp_line) != EOF){
		//printf("\ngot: %s\n", temp_line);
		num_rows = 0;
		i = 0;
		while(temp_line[i] != '\0' && num_rows < 8){
			if(isdigit(temp_line[i]) || temp_line[i] == '.'){
				while(isdigit(temp_line[i]) || temp_line[i] == '.'){
					s_a[position] = temp_line[i];
					position+=1;
					i+=1;
				}
				s_a[position] = '\0';
				a = atof(s_a);
				sum+=a;
				num_numbers+=1;
				num_rows+=1;
				position = 0;
			}
			i+=1;
		}
	}
	fclose(fp);
	//printf("num: %d sum: %f\n", num_numbers, sum);
	if(num_numbers != 0){
		return sum/num_numbers;
	}else{
		return 0;
	}
}

int main () {
	printf("%f\n", avgCSV("multiline1.csv"));
	// Expected Value = 523.899109
	printf("%f\n", avgCSV("multiline2.csv"));
	// Expected Value = 506.371246
}
