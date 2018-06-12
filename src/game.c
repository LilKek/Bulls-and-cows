#include "game.h"
#include "func.h"

void game(int players)
{
	system("clear");
	char num[100];
	int *A, *B;
	int check, attempt = 1;
	int len, prev_num[10];
	if (players == 1)
		B = gen_number();
	else if (players == 2) {
		while(1) {
			if ((lan % 2) == 0)
				printf("Guess the number or enter (q) to back to main menu: ");
			else
				printf("Загадайте число или введите (q) для выхода в главное меню: ");
			fgets(num, 100, stdin);
			len = strlen(num);
			B = str_to_int(num, len - 1);
			check = check_input(num, B, len);
			if (check == 0)
				return;
			else if (check == -1)
				continue;
			else {
				system("clear");
				break;
			}
		}
	}
	
	while (attempt != 10) {
		
		if ((lan % 2) == 0)
			printf("Attempt № %d\nEnter number or (q) to back to main menu: ", attempt);
		else
			printf("Попытка № %d\nВведите число или (q) для выхода в главное меню: ", attempt);
		fgets(num, 100, stdin);
		len = strlen(num);
		A = str_to_int(num, len - 1);
		check = check_input(num, A, len);
		if (check == 0)
			return;
		else if (check == -1)
			continue;
		
		system("clear");
		prev_num[attempt - 1] = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
		if ((lan % 2) == 0)
			printf("Your prev numbers:\n");
		else
			printf("Ваши предыдущие числа\n");
		for(int i = 0; i < attempt; i++)
			printf("%d\n", prev_num[i]);
		for(int i = 10; i > attempt; i--)
			printf("\n");
		
		attempt++;
		
		int bulls = 0, cows = 0;
		bulls = count_bulls(A, B);
		if (bulls == 4) {
			while(1) {
				system("clear");
				if ((lan % 2) == 0) {
					printf("Congratulations! You guessed the number at the attempt № %d\n", attempt);
					printf("Enter (r) to restart or (q) to back to main menu: ");
				}else {
					printf("Поздравляем! Вы отгадали число с попытки № %d\n", attempt);
					printf("Введите (r) для рестарта или (q) для выхода в главное меню: ");
				}
				fgets(num, 100, stdin);
				if ((strlen(num) == 2) && (num[0] == 'q'))
					return;
				else if ((strlen(num) == 2) && (num[0] == 'r')) {
					game(players);
					return;
				}else {
					system("clear");
					if ((lan % 2) == 0)
						printf("Wrong option\n");
					else
						printf("Не правильная опция\n");
				}
			}
		}else if (bulls == 0) {
			if ((lan % 2) == 0)
				printf("No bulls\n");
			else
				printf("Нет быков\n");
		}
		cows = count_cows(A, B);
		if (cows == 0) {
			if ((lan % 2) == 0)
				printf("No cows\n");
			else
				printf("Нет коров\n");
		}
		
	}
	while(1) {
		if ((lan % 2) == 0)
			printf("You lose\nEnter (r) to restart or (q) to back to main menu: ");
		else
			printf("Вы проиграли\nВведите (r) для рестарта или (q) для выхода в главное меню: ");
		fgets(num, 100, stdin);
		if ((strlen(num) == 2) && (num[0] == 'q'))
			return;
		else if ((strlen(num) == 2) && (num[0] == 'r')) {
			game(players);
			return;
		}else {
			system("clear");
			if ((lan % 2) == 0)
				printf("Wrong option\n");
			else
				printf("Не правильная опция\n");
		}
	}
}
