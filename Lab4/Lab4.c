#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int num;
	char title[30];
	char author[25];
	float price; 

}bookT;

void initBook(bookT* library, int size);
void addBook(bookT* lib, int size);
void editBook(bookT* lib, int size);
void displayBook(bookT* lib, int size);
void searchLibrary(bookT* lib, int size);
int loginChoice();
void loading(bookT* lib, int size);
void saving(bookT* lib, int size);

void main() {
	FILE* fpAdmin = fopen("database.txt", "w");
	FILE* fpGuest = fopen("database.txt", "r");

	int NoOfbooks = 4;
	int menu;
	bookT* library;

	int access = loginChoice();

	library = (bookT*)malloc(NoOfbooks * sizeof(bookT));

	initBook(library, NoOfbooks);

	loading(library, NoOfbooks);

	if (access == 0) {

		printf("welcome to the library Admin,Please enter 1 for book entry, 2 to display books  and 3 to search books ,or 4 to edit the price of current book or 5 to save or -1 to exit\n");
		scanf("%d", &menu);

		printf("Please enter the number of books you wish to add\n");
		scanf("%d", &NoOfbooks);

		printf("%d",NoOfbooks);

		library = (bookT*)malloc(NoOfbooks * sizeof(bookT));

		initBook(library, NoOfbooks);

		do{

			if (menu == 1) {
				addBook(library, NoOfbooks);
			}
			else if (menu == 2) {
				displayBook(library, NoOfbooks);
			}
			else if (menu == 3) {
				searchLibrary(library, NoOfbooks);
			}
			else if (menu == 4) {
				editBook(library, NoOfbooks);
			}
			else if (menu == 5) {
				saving(library, NoOfbooks);
			}
			else {
				printf("Sorry number out of bounds\n");
			}
			
		} while (menu != -1);
	}

	else 
	{
		printf("welcome to the library Guest,Please enter 1 for book entry, 2 to display books  or 3 to search books or -1 to exit\n");
		scanf("%d", &menu);

		printf("Please enter the number of books you wish to add\n");
		scanf("%d", &NoOfbooks);

		printf("%d", NoOfbooks);
		library = (bookT*)malloc(NoOfbooks * sizeof(bookT));

		initBook(library, NoOfbooks);

		do{

			if (menu == 1) {
				addBook(library, NoOfbooks);
			}
			else if (menu == 2) {
				displayBook(library, NoOfbooks);
			}
			else if (menu == 3) {
				searchLibrary(library, NoOfbooks);
			}
			else {
				printf("Sorry number out of bounds\n");
			}
		} while (menu != -1);
	}
	
	





}
void editBook(bookT* lib, int size) {

	int id;
	printf("Enter the number of the book you wich to edit the price off");
	scanf("%d", &id);

	printf("Please enter the new price for the book\n");
	scanf("%f", (lib + id)->price);
}

void initBook(bookT* library,int size) {

	int i;
	for ( i = 0; i < size; i++)
	{
		(library + i)->num = 0;
	}

}

void addBook(bookT* lib, int size) {
	int i;
	for (i = 0; i < size; i++)
	{
		printf("Please enter the isbn for the book %d\n",i +1);
		scanf("%s", &(lib + i)->num);

		printf("Please enter the title for the book %d \n",i+1);
		scanf("%s", (lib + i)->title);

		printf("Please enter the author for the book %d\n",i+1);
		scanf("%s", (lib + i)->author);

		printf("Please enter the price for the book %d\n",i+1);
		scanf("%f", &(lib + i)->price);
	}
}

void displayBook(bookT* lib, int size) {
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d %s %s %f\n",(lib +i)->num, (lib + i)->title, (lib + i)->author,(lib + i)->price);
	}

}

void searchLibrary(bookT* lib, int size) {

	int i;
	int isbn;

	printf("Please enter the number of the book you wish to search\n");
	scanf("%d",&isbn);

	for (i = 0; i < size; i++)
	{
		if (isbn == &(lib + i)->num) 
		{
			printf("%d %s %s %f\n", (lib + i)->num, (lib + i)->title, (lib + i)->author, (lib + i)->price);
		}
	}


}


int loginChoice() {
	FILE* fp = fopen("login.txt", "r");

	char password [20];
	char filePassword[20];
	int access;

	while (!feof(fp)) {
		printf("please enter password\n");
		scanf(" %s", password);
		
		fscanf(fp," %s",filePassword);

		access = strcmp(password,filePassword);

	}
	if (access == 0) {
		printf("You are now logged in as the Admin\n");
	}
	else {
		printf("You are now logged in as a guest\n");
	}

	//printf("%d\n", access);  for debug purposes
	return access;
	
}

void loading(bookT* lib, int size) {
	FILE* fpGuest = fopen("database.txt", "r");
	int i;
	if (fpGuest == NULL) {

		printf(" Sorry!!!!!!!!!,file doesnt exist");
	}
	else
	{
		while (!feof(fpGuest)) {
			for (i = 0; i < size; i++) {

				fscanf("%d %s %s %f\n", &(lib + i)->num, (lib + i)->title, (lib + i)->author, &(lib + i)->price);
			}

		}
		fclose(fpGuest);
	}



}

void saving(bookT* lib, int size) {
	FILE* fpAdmin = fopen("database.txt", "r");
	int i;
	if (fpAdmin == NULL) {

		printf(" Sorry!!!!!!!!!,file doesnt exist");
	}
	else
	{
		while (!feof(fpAdmin)) {
			for (i = 0; i < size; i++) {

				fprintf("%d %s %s %f\n", &(lib + i)->num, (lib + i)->title, (lib + i)->author, &(lib + i)->price);
			}

		}
		fclose(fpAdmin);
	}
	


}