#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../Utilities/types.h"

typedef enum EN_adminError_t
{
	ADMIN_OK, ADMIN_WRONG_PASSWORD, ADMIN_INVALID_PASSWORD
} EN_adminError_t;

typedef struct ST_admin_t
{
	uint8_t adminPassword[5];
} ST_admin_t;


// functions prototypes
EN_adminError_t setAdminPassword(ST_admin_t* admin, uint8_t password[]);
EN_adminError_t getAdminPassword(ST_admin_t* admin);
EN_adminError_t checkEnteredPassword(ST_admin_t admin, uint8_t password[]);
EN_adminError_t askPasswordThenCheck(ST_admin_t admin);
EN_adminError_t askPasswordThenCheckForThreeTrial(ST_admin_t admin);

#endif // ADMIN_H_INCLUDED