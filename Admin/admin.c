#include "admin.h"

EN_adminError_t setAdminPassword(ST_admin_t* admin, uint8_t password[])
{
	if (strlen(password) != 4)
		return ADMIN_INVALID_PASSWORD;

	strcpy(admin->adminPassword, password);
	return ADMIN_OK;
}

EN_adminError_t getAdminPassword(ST_admin_t* admin)
{
	printf("Enter Password: ");
	uint8_t bStr[6];

	fgets(bStr, 6, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');
	
	/*
		1							  '1' , 10 , '\0'
		12							  '1' , '2' , 10 , '\0'
		123							  '1' , '2' , '3' , 10 , '\0'
		1234                          '1' , '2' , '3' , '4' , 10 , '\0'   ----> wanted
		12345					      '1' , '2' , '3' , '4' , '5' , '\0'
		123456789					  '1' , '2' , '3' , '4' , '5' , '\0'
	*/

	int i;
	for (i = 0; bStr[i] != 0; i++){}
	
	if (i <= 4 || (i == 5 && bStr[i - 1] != 10))
		return ADMIN_INVALID_PASSWORD;

	memcpy(admin->adminPassword, &bStr[0], i - 1);
	admin->adminPassword[i - 1] = '\0';
	return ADMIN_OK;
}

EN_adminError_t checkEnteredPassword(ST_admin_t admin , uint8_t password[])
{
	if( strlen(password) != 4 )
		return ADMIN_INVALID_PASSWORD;

	if (strcmp(admin.adminPassword, password) != 0)
		return ADMIN_WRONG_PASSWORD;

	return ADMIN_OK;
}

EN_adminError_t askPasswordThenCheck(ST_admin_t admin)
{
	printf("Enter Password: ");
	uint8_t bStr[6];

	fgets(bStr, 6, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');

	int i;
	for (i = 0; bStr[i] != 0; i++) {}

	if (i <= 4 || (i == 5 && bStr[i - 1] != 10))
		return ADMIN_WRONG_PASSWORD;

	memcpy(bStr, &bStr[0], i - 1);
	bStr[i - 1] = '\0';

	if (strcmp(admin.adminPassword, bStr) != 0)
		return ADMIN_WRONG_PASSWORD;

	return ADMIN_OK;
}

EN_adminError_t askPasswordThenCheckForThreeTrial(ST_admin_t admin)
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		if (askPasswordThenCheck(admin) == ADMIN_OK)
			return ADMIN_OK;
	}
	return ADMIN_WRONG_PASSWORD;
}