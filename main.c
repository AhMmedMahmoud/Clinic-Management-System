#include "Clinic/clinic.h"


int main()
{
	setup();

	while (1)
	{
		appStart();
	}
}


	// test setAdminPassword	
	/*
	ST_admin_t admin;
	setAdminPassword(&admin, "1234");
	printf("Password is %s", admin.adminPassword);
	*/

	// test getAdminPassword
	/*
	ST_admin_t admin;
	while (getAdminPassword(&admin) != ADMIN_OK);
	printf("Password is %s", admin.adminPassword);
	*/

	// test checkEnteredPasswordCorrect
	/*
	ST_admin_t admin;
	setAdminPassword(&admin, "1234");
	printf("%s\n", checkEnteredPassword(admin, "1234") == 0 ? "OK" : "wrong passward");
	*/


	// test askPasswordThenCheck
	/*
	ST_admin_t admin;
	setAdminPassword(&admin, "1234");
	while( askPasswordThenCheck(admin) != ADMIN_OK);
	printf("Entered Password is correct");
	*/

	// test getPatientGender
	/*
	ST_patient_t patient;
	while( getPatientGender(&patient) == PATIENT_WRONG_GENDER);
	system("cls");
	if (patient.patientGender == MALE)
		printf("patientGender is male\n");
	else if(patient.patientGender == FEMALE)
		printf("patientGender is female\n");
	return 0;
	*/


	// test getPatientAge
	/*
	ST_patient_t patient;
	while(getPatientAge(&patient) != PATIENT_OK);
	printf("patientAge = %d\n",patient.patientAge);
	*/


	// test getPatientId
	/*
	ST_patient_t patient;
	while (getPatientId(&patient) != PATIENT_OK);
	printf("ID = %s\n", patient.patientId);
	*/

	// test getPatientName
	/*
	ST_patient_t patient;
	while (getPatientName(&patient) != PATIENT_OK);
	printf("name :  %s\n", patient.name);
	*/