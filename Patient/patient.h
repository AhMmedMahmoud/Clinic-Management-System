#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include <stdio.h>
#include <ctype.h>
#include "../Utilities/types.h"

typedef enum EN_patientError_t
{
	PATIENT_OK,PATIENT_WRONG_NAME,PATIENT_WRONG_GENDER,PATIENT_WRONG_AGE,PATIENT_WRONG_ID, PATIENT_FAILED
}EN_patientError_t;

typedef enum EN_gender_t
{
	MALE, FEMALE
}EN_gender_t;


typedef struct ST_patient_t
{
	uint8_t patientName[25];
	EN_gender_t patientGender;
	uint16_t patientAge;
	uint8_t patientId[15];
	struct ST_patient_t *nextPatient;
}ST_patient_t;



// functions prototypes
EN_patientError_t getPatientName(ST_patient_t* patient);
EN_patientError_t getPatientGender(ST_patient_t* patient);
EN_patientError_t getPatientAge(ST_patient_t* patient);
EN_patientError_t getPatientId(ST_patient_t* patient);
void printPatient(ST_patient_t *patient);


#endif // PATIENT_H_INCLUDED