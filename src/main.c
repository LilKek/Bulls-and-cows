#include "menu.h"
#include "game.h"

int main(int argc, char *argv[])
{
	int procces = 1;
	if (argc < 2)
		lan = 0;
	else if (argc == 2) {
		if (strcmp(argv[1], "eng") == 0)
			lan = 0;
		else if (strcmp(argv[1], "rus") == 0)
			lan = 1;
		else {
			printf("Wrong arguments(не правильные аргументы)\n");
			printf("Example(пример):\n\t./game (language option)\n");
			return 0;
		}
	}else {
		printf("Too much arguments(слишком много аргументов)\n");
		return 0;
	}
	while (procces != 0) {
		
		menu(lan);
		
		switch (op[0]) {
			case '1':
				game(1);
				break;
			case '2':
				game(2);
				break;
			case '3':
				rules(lan);
				break;
			case '4':
				lan++;
				break;
			case '5':
				procces = 0;
				break;
		}
	}
	system("clear");
	return 0;
}
				
