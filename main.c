#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Declaring all the functions
void checkBalance(char*);
void transferMoney(void);
void display(char*);
void person(char*);
void login(void);
void loginSuccess(void);
void account(void);
void accountCreated(void);
void afterLogin(void);
void logout(void);

// setting cursor position
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// data of the user
struct pass {
	char username[50];
	int date, month, year;
	char phnumber[15];
	char adharno[20];
	char firstname[20];
	char lastname[20];
	char fathername[20];
	char mothername[20];
	char address[50];
	char accounttype[20];
};

// Structure to keep track of amount transfer
struct money {
	char usernameto[50];
	char userpersonfrom[50];
	long int money1;
};

struct userpass {
	char password[50];
};

// Driver Code
int main()
{
	int i, a, b, choice;
	int passwordlength;

	gotoxy(20, 3);

	// Main menu
	printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
	gotoxy(18, 5);

	printf("**********************************");
	gotoxy(25, 7);

	gotoxy(20, 10);
	printf("1.... CREATE A BANK ACCOUNT");

	gotoxy(20, 12);
	printf("2.... ALREADY A USER? SIGN IN");
	gotoxy(20, 14);
	printf("3.... EXIT\n\n");

	printf("\n\nENTER YOUR CHOICE..");

	scanf("%d", &choice);

	switch (choice) {
	case 1:
		system("cls");
		printf("\n\n USERNAME 50 CHARACTERS MAX!!");
		printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
		account();
		break;

	case 2:
		login();
		break;

	case 3:
		exit(0);
		break;

		getch();
	}
}

void account(void)
{
	char password[20];
	int passwordlength, i, seek = 0;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass p1;

	struct userpass u2;

	fp = fopen("username.txt", "ab");

	// Inputs
	system("cls");
	printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

	printf("\n\nFIRST NAME..");
	scanf("%s", &u1.firstname);

	printf("\n\n\nLAST NAME..");
	scanf("%s", &u1.lastname);

	printf("\n\nFATHER's NAME..");
	scanf("%s", &u1.fathername);

	printf("\n\nMOTHER's NAME..");
	scanf("%s", &u1.mothername);

	printf("\n\nADDRESS..");
	scanf("%s", &u1.address);

	printf("\n\nACCOUNT TYPE..");
	scanf("%s", &u1.accounttype);

	printf("\n\nDATE OF BIRTH..");
	printf("\nDATE-");
	scanf("%d", &u1.date);
	printf("\nMONTH-");
	scanf("%d", &u1.month);
	printf("\nYEAR-");
	scanf("%d", &u1.year);

	printf("\n\nADHAR NUMBER..");
	scanf("%s", u1.adharno);

	printf("\n\nPHONE NUMBER..");
	scanf("%s", u1.phnumber);

	printf("\n\nUSERNAME.. ");
	scanf("%s", &u1.username);

	printf("\n\nPASSWORD..");

	// Taking password in the form of stars
	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}
		else
			break;
	}

	// Writing to the file
	fwrite(&u1, sizeof(u1),
		1, fp);

	fclose(fp);
	accountCreated();
}

// Successful account creation
void accountCreated(void)
{
	int i;
	char ch;
	system("cls");
	printf(
		"PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
	for (i = 0; i < 200000000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);

	printf("ACCOUNT CREATED SUCCESSFULLY....");
	gotoxy(0, 20);

	printf("Press enter to login....");

	getch();
	login();
}

// Login function
void login(void)
{
	system("cls");

	char username[50];
	char password[50];

	int i, j, k;
	char ch;
	FILE *fp, *fu;
	struct pass u1;
	struct userpass u2;

	// Opening user file
	fp = fopen("username.txt",
			"rb");

	if (fp == NULL) {
		printf("ERROR IN OPENING FILE");
	}
	gotoxy(34, 2);
	printf(" ACCOUNT LOGIN ");
	gotoxy(7, 5);
	printf("***********************************************"
		"********************************");

	gotoxy(35, 10);
	printf("==== LOG IN ====");

	gotoxy(35, 12);
	printf("USERNAME.. ");
	scanf("%s", &username);

	gotoxy(35, 14);
	printf("PASSWORD..");

	for (i = 0; i < 50; i++) {
		ch = getch();
		if (ch != 13) {
			password[i] = ch;
			ch = '*';
			printf("%c", ch);
		}

		else
			break;
	}

	// Checking user existence
	while (fread(&u1, sizeof(u1),
				1, fp)) {
		if (strcmp(username,
				u1.username)
			== 0) {
			loginSuccess();
			display(username);
		}
	}

	fclose(fp);
}

// Redirect after successful login
void loginSuccess(void)
{
	int i;
	FILE* fp;
	struct pass u1;
	system("cls");
	printf("Fetching account details.....\n");
	for (i = 0; i < 20000; i++) {
		i++;
		i--;
	}

	gotoxy(30, 10);
	printf("LOGIN SUCCESSFUL....");
	gotoxy(0, 20);
	printf("Press enter to continue....");

	getch();
}

// Display function
void display(char username1[])
{
	system("cls");
	FILE* fp;
	int choice, i;
	fp = fopen("username.txt", "rb");
	struct pass u1;

	if (fp == NULL) {
		printf("error in opening file");
	}

	while (fread(&u1, sizeof(u1),
				1, fp)) {
		if (strcmp(username1,
				u1.username)
			== 0) {
			gotoxy(30, 1);
			printf("WELCOME, %s %s",
				u1.firstname, u1.lastname);
			gotoxy(28, 2);
			printf("..........................");
			gotoxy(55, 6);
			printf("==== YOUR ACCOUNT INFO ====");
			gotoxy(55, 8);
			printf("***************************");
			gotoxy(55, 10);
			printf("NAME..%s %s", u1.firstname,
				u1.lastname);

			gotoxy(55, 12);
			printf("FATHER's NAME..%s %s",
				u1.fathername,
				u1.lastname);

			gotoxy(55, 14);
			printf("MOTHER's NAME..%s",
				u1.mothername);

			gotoxy(55, 16);
			printf("ADHAR CARD NUMBER..%s",
				u1.adharno);

			gotoxy(55, 18);
			printf("MOBILE NUMBER..%s",
				u1.phnumber);

			gotoxy(55, 20);
			printf("DATE OF BIRTH.. %d-%d-%d",
				u1.date, u1.month, u1.year);

			gotoxy(55, 22);
			printf("ADDRESS..%s", u1.address);

			gotoxy(55, 24);
			printf("ACCOUNT TYPE..%s",
				u1.accounttype);
		}
	}

	fclose(fp);

	gotoxy(0, 6);

	// Menu of different actions
	printf(" HOME ");
	gotoxy(0, 7);
	printf("******");
	gotoxy(0, 9);
	printf(" 1.CHECK BALANCE....");
	gotoxy(0, 11);
	printf(" 2.TRANSFER MONEY....");
	gotoxy(0, 13);
	printf(" 3.LOG OUT....\n\n");
	gotoxy(0, 15);
	printf(" 4.EXIT....\n\n");

	printf(" ENTER YOUR CHOICE..");
	scanf("%d", &choice);

	switch (choice) {
	case 1:
		checkBalance(username1);
		break;

	case 2:
		transferMoney();
		break;

	case 3:
		logout();
		login();
		break;

	case 4:
		exit(0);
		break;
	}
}

// Function to transfer money
void transferMoney(void)
{
	int i, j;
	FILE *fm, *fp;
	struct pass u1;
	struct money m1;
	char usernamet[20];
	char usernamep[20];
	system("cls");

	fp = fopen("username.txt", "rb");

	// Creating another file to write amount along with username to which amount is going to be transferred
	fm = fopen("other.txt", "ab");

	gotoxy(33, 4);
	printf("---- TRANSFER MONEY ----");
	gotoxy(33, 5);
	printf("========================");

	gotoxy(33, 11);
	printf("FROM (your username).. ");
	scanf("%s", &usernamet);

	gotoxy(33, 13);
	printf(" TO (username of person)..");
	scanf("%s", &usernamep);

	// Checking for username existence
	while (fread(&u1, sizeof(u1),
				1, fp))

	{
		if (strcmp(usernamep,
				u1.username)
			== 0) {
			strcpy(m1.usernameto,
				u1.username);
			strcpy(m1.userpersonfrom,
				usernamet);
		}
	}
	gotoxy(33, 16);

	printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
	scanf("%d", &m1.money1);



	fwrite(&m1, sizeof(m1),
		1, fm);

	gotoxy(0, 26);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 28);
	printf(
		"--------------------------------------------------"
		"--------------------------------------------");

	gotoxy(0, 29);

	gotoxy(10, 27);
	for (i = 0; i < 70; i++) {
		for (j = 0; j < 1200000; j++) {
			j++;
			j--;
		}
		printf("*");
	}

	gotoxy(33, 40);
	printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
	getch();

	fclose(fp);
	fclose(fm);

	// Function to return to the home screen
	display(usernamet);
}

void checkBalance(char username2[])
{
	system("cls");
	FILE* fm;
	struct money m1;
	char ch;
	int i = 1, summoney = 0;

	// Opening amount file record
	fm = fopen("other.txt", "rb");

	int k = 5, l = 10;
	int m = 30, n = 10;
	int u = 60, v = 10;

	gotoxy(30, 2);
	printf("==== BALANCE DASHBOARD ====");
	gotoxy(30, 3);
	printf("***************************");
	gotoxy(k, l);
	printf("S no.");
	gotoxy(m, n);
	printf("SENDER");
	gotoxy(u, v);
	printf("AMOUNT");

	// Reading username to fetch the correct record
	while (fread(&m1, sizeof(m1),
				1, fm)) {
		if (strcmp(username2,
				m1.usernameto)
			== 0) {
			gotoxy(k, ++l);
			printf("%d", i);
			i++;
			gotoxy(m, ++n);
			printf("%s", m1.userpersonfrom);

			gotoxy(u, ++v);
			printf("%d", m1.money1);
			// Total money
			summoney = summoney + m1.money1;
		}
	}

	gotoxy(80, 10);
	printf("TOTAL AMOUNT");

	gotoxy(80, 12);
	printf("%d", summoney);

	getch();

	fclose(fm);
	display(username2);
}

void logout(void)
{
	int i, j;
	system("cls");
	printf("please wait, logging out");

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 25000000; j++) {
			i++;
			i--;
		}
		printf(".");
	}

	gotoxy(30, 10);
	printf("Sign out successfully..\n");

	gotoxy(0, 20);
	printf("press any key to continue....");

	getch();
}

