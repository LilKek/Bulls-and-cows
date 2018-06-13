#include "menu.h"

char *menu(int lan)
{
	int err = 0;
	while (1) {
		if ((lan % 2) == 0)
			eng_menu(err);
		else
			rus_menu(err);

		fgets(op, 100, stdin);
		
		if ((strlen(op) == 2) && (op[0] > '0') && (op[0] < '6'))
			return op;
		else
			err = 1;
	}
}

void eng_menu(int err)
{
	system("clear");
	printf("Bulls and Cows:\n");
	printf("1.One player\n");
	printf("2.Two players\n");
	printf("3.Rules\n");
	printf("4.Change language\n");
	printf("5.Exit\n");

	if (err == 1)
		printf("Wrong option, select option again (1,2,3,4 or 5): ");
	else
			printf("Select option (1,2,3,4 or 5): ");
	return;
}

void rus_menu(int err)
{
	system("clear");
	printf("Быки и Коровы:\n");
	printf("1.Один игрок\n");
	printf("2.Два игрока\n");
	printf("3.Правила\n");
	printf("4.Сменить язык\n");
	printf("5.Выйти\n");

	if (err == 1)
		printf("Неправильная опция, попробуйте снова (1,2,3,4 or 5): ");
	else
		printf("Выбрать опцию (1,2,3,4 or 5): ");
	return;
}

void rules(int lan)
{
	int err = 0;
	while (1) {
		if ((lan % 2) == 0)
			eng_rules(err);
		else
			rus_rules(err);
		
		fgets(op, 100, stdin);
		
		if ((strlen(op) == 2) && (op[0] > '0') && (op[0] < '2'))
			return;
		else
			err = 1;
	}
}
void eng_rules(int err)
{
	system("clear");
	printf("You have to guess computer's(or other player's) the four-digit number\n");
	printf("You have only 10 attempts\n");
	printf("The digits must be all different\n");
	printf("Cows - the guessed digits are in different positions\n");
	printf("Bulls - the guessed digits are in their right positions\n");
	printf("1.Back to main menu\n");
	
	if (err == 1)
		printf("Wrong option, select option again (1): ");
	else
		printf("Select option (1): ");
	return;
}

void rus_rules(int err)
{
	system("clear");
	printf("Вы должны отгадать загаданное компьютером (или другим игроком) четырех значное число\n");
	printf("У вас есть только 10 попыток\n");
	printf("Цифры не должны повторяться\n");
	printf("Коровы - цифры, этого числа, находящиеся не на своих позициях\n");
	printf("Быки - цифры, угаданные вплоть до позиций\n");
	printf("1.Вернуться в меню\n");
	
	if (err == 1)
		printf("Неправильная опция, попробуйте снова (1): ");
	else
		printf("Выбрать опцию (1): ");
	return;
}
