#include "func.h"
#include "game.h"

int *str_to_int(char *s, int n)
{
	int *arr;
	arr = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
		if((s[i] > 47) && (s[i] < 58))
			arr[i] = (int)s[i] - 48;
		else {
			arr[0] = 0;
			return arr;
		}
	return arr;
}

int input_correct(int *A)
{
	int i, j, k = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if ((A[i] == A[j]) && (i != j)) {
				k++;
			}
			if (k != 0) {
				return 20;
			}
		}
	}

	return 0;
}

int *gen_number()
{
	int *arr;
	int i = 1, j, number;
	srand(time(NULL));
	arr = (int*)malloc(4 * sizeof(int));
	arr[0] = rand() %9 + 1;

    while(i < 4) {
		number = rand() % 10;
        for(j = 0; j <= i; j++) {
			if (number == arr[j]) {
				break;
			}
		}
        if (j == i + 1) {
			arr[i] = number;
			i++;
        }
    }
    return arr;
}

int count_bulls (int *A, int *B)
{
	int i, bulls = 0;
	for (i = 0; i < 4; i++) {
		if (A[i] == B[i]) {
			if ((lan % 2) == 0)
				printf("Bull: %d  ", A[i]);
			else
				printf("Бык: %d  ", A[i]);
			bulls++;
		}
	}
	if(bulls != 0)
		printf("\n");
	return bulls;
}

int count_cows (int *A, int *B)
{
	int i, j, n = 3, cows = 0;

	for (i = n; i >= 0; i--) {
		for (j = n; j >= 0; j--) {
			if ((A[i] == B[j]) && (A[i] != B[i])) {
				if ((lan % 2) == 0)
					printf("Cows: %d  ", A[i]);
				else
					printf("Корова: %d  ", A[i]);
				cows++;
			} 
		}
	}
	if(cows != 0)
		printf("\n");
	return cows;
}

int check_input(char *str, int *arr, int len)
{
	if ((len == 2) && (str[0] == 'q'))
		return 0;
	else if (arr[0] == 0) {
		system("clear");
		if ((lan % 2) == 0)
			printf("ERROR: you should enter four-digit nubmer\n");
		else
			printf("ОШИБКА: вы доолжны ввести четырех значное число\n");
		return -1;
	}else if (len != 5) {
		system("clear");
		if ((lan % 2) == 0)
			printf("ERROR: number must be four-digit\n");
		else
			printf("ОШИБКА: чилсо должно быть четырех значное\n");
		return -1;
	}
	int check = input_correct(arr);
	if (check != 0) {
		system("clear");
		if ((lan % 2) == 0)
			printf("The digits must be all different\n");
		else
			printf("Цифры должны быть разными\n");
		return -1;
	}
	return 1;
}
