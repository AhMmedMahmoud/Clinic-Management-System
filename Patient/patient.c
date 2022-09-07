#include "patient.h"


/*
this function asks for name
it checks entered name
if entered name contains any illegal characters, return PATIENT_WRONG_NAME
if entered name greater than 24 characters, return PATIENT_WRONG_NAME
if entered name less than 20 characters, return PATIENT_WRONG_NAME
else store entered name and return ok
*/
EN_patientError_t getPatientName(ST_patient_t* patient)
{
	printf("Enter name: ");
	char bStr[26];
	fgets(bStr, 26, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');

	/*
		ahmed                         'a' , 'h' , 'm' , 'e' , 'd', 10 ,'\0'
		ahmed mahmoud mohamed         'a' , 'h' , ............................ , 'e' , 'd' , 10 , '\0'
		ahmed mahmoud mohamed abc     'a' , 'h' , ............................ , 'e' , 'd' , 'a' , 'b' , 'c' , '\0'
	*/

	int i;
	for (i = 0; bStr[i] != '\0'; i++)
	{
		if( isalpha(bStr[i]) == 0 && bStr[i] != ' ' && bStr[i] != 10)
			return PATIENT_WRONG_NAME;
	}

	if (i < 21 || (i == 25 && bStr[i - 1] != 10))
		return PATIENT_WRONG_NAME;
	else
	{
		memcpy(patient->patientName, &bStr[0], i - 1);
		patient->patientName[i - 1] = '\0';
		return PATIENT_OK;
	}
}





/*
this functions asks for patientGender
it tells user to press 0 for male and 1 for female
if patientGender is male or female, store entered patientGender and return ok
else return PATIENT_WRONG_GENDER
*/
EN_patientError_t getPatientGender(ST_patient_t* patient)
{
	printf("press  --> 0 for male\n       --> 1 for female\n");
	int tempGender;
	scanf_s("%d", &tempGender);		while ((getchar()) != '\n'); //consume the '\n' char
	if(tempGender == MALE || tempGender == FEMALE)
	{
		patient->patientGender = tempGender;
		return PATIENT_OK;
	}

	return PATIENT_WRONG_GENDER;
}





/*
this functions asks for patientAge
if patientAge less than or equal zero return PATIENT_WRONG_AGE
if patientAge greater than 200 return PATIENT_WRONG_AGE
else store entered patientAge and return PATIENT_OK
*/
EN_patientError_t getPatientAge(ST_patient_t* patient)
{
	printf("Enter age: ");
	uint16_t tempAge;
	scanf_s("%d", &tempAge);	while ((getchar()) != '\n'); //consume the '\n' char
	if (tempAge <= 0 || tempAge > 200)
		return PATIENT_WRONG_AGE;

	patient->patientAge = tempAge;
	return PATIENT_OK;
}







/*
this functions asks for ID
it checks if entered patientId is 14 characters or not
if entered patientId is 14 characters, it stores entered patientId and return PATIENT_OK
else it returns PATIENT_WRONG_ID
*/
EN_patientError_t getPatientId(ST_patient_t* patient)
{
	printf("Enter ID: ");
	uint8_t bStr[16];

	fgets(bStr, 16, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');

	/*
	1					'1', 10  , '\0'
	12					'1', '2' , 10  , '\0'
	123					'1', '2' , '3' ,  10 , '\0'
	1234				'1', '2' , '3' , '4' , 10  , '\0'
	12345				'1', '2' , '3' , '4' , '5' ,  10  , '\0'
	123456				'1', '2' , '3' , '4' , '5' , '6'  , 10  , '\0'
	1234567				'1', '2' , '3' , '4' , '5' , '6'  , '7' ,  10  , '\0'
	12345678			'1', '2' , '3' , '4' , '5' , '6'  , '7' , '8'  ,  10  , '\0'
	123456789			'1', '2' , '3' , '4' , ..... '9'  ,  10 , '\0'
	1234567890			'1', '2' , '3' , '4' , ..... '9'  , '0' ,  10  , '\0'
	12345678901			'1', '2' , '3' , '4' , ..... '9'  , '0' , '1'  , 10  , '\0'
	123456789012		'1', '2' , '3' , '4' , ..... '9'  , '0' , '1'  , '2' ,  10 , '\0'
	1234567890123		'1', '2' , '3' , '4' , ..... '9'  , '0' , '1'  , '2' , '3' , 10  , '\0'  
	12345678901234		'1', '2' , '3' , '4' , ..... '9'  , '0' , '1'  , '2' , '3' , '4' , 10 ,'\0'  --> wanted
	123456789012345		'1', '2' , '3' , '4' , ..... '9'  , '0' , '1'  , '2' , '3' , '4' , '5' , '\0'
	*/

	int i;
	for (i = 0; bStr[i] != 0; i++) {}

	if (i <= 14 || (i == 15 && bStr[i - 1] != 10))
		return PATIENT_WRONG_ID;

	memcpy(patient->patientId, &bStr[0], i - 1);
	patient->patientId[i - 1] = '\0';
	return PATIENT_OK;
}






/*
this function print all information of patient
*/
void printPatient(ST_patient_t *patient)
{
	//printf("%p\n", patient);
	printf("Name: %s\n", patient->patientName);

	printf("Age: %d\n", patient->patientAge);

	if(patient->patientGender == MALE)
		printf("Gender: male\n");
	else if (patient->patientGender == FEMALE)
		printf("Gender: female\n");

	printf("ID: %s\n", patient->patientId);
}

