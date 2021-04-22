#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	srand(time(NULL));
	FILE *p;
	char prompt = 'y';
	int ch;
	char website[25];
	int passChar;
	char characters[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM123456789!@#$%^&*.,";
while (prompt == 'y') {
	printf("Website: ");
	scanf("%[^\n]", &website);
	while ((ch = getchar()) != '\n' && ch != EOF);

	printf("Enter Desired Password Length: ");
	scanf("%d", &passChar);
	while ((ch = getchar()) != '\n' && ch != EOF);

	char password[sizeof(passChar)];
	printf("%[^\n]: ", website);
	p = fopen("c:\\Users\\jacob\\Desktop\\Password Gen\\passwords.txt", "a");
	fprintf(p, "%s: ", website);
	for (int i = 0; i < passChar; i++) {
		password[i] = characters[rand() % strlen(characters)];
		printf("%c", password[i]);
		fprintf(p, "%c", password[i]);
		}
		fprintf(p, "\n");
		printf("\nAdd another password? (y/n)\n");
		scanf("%c", &prompt);
	}
	puts("Saved");
	fclose(p);
	return 0;
}