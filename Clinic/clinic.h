#ifndef CLINIC_H_INCLUDED
#define CLINIC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "../Admin/admin.h"
#include "../Reservation/reservation.h"



typedef struct ST_slotList_t
{
	int noOfSlots;
	ST_slot_t* head;
	ST_slot_t* tail;
} ST_slotList_t;


typedef struct ST_patientsList_t
{
	int noOfPatients;
	ST_patient_t* head;
	ST_patient_t* tail;
} ST_patientsList_t;


typedef struct ST_reservationList_t
{
	int noOfReservations;
	ST_reservation_t* head;
	ST_reservation_t* tail;
} ST_reservationList_t;



typedef enum EN_slotListError_t
{
	SLOT_LIST_OK, SLOT_LIST_CANCEL, SLOT_LIST_COMPLETELY_CHOSEN
} EN_slotListError_t;



typedef enum EN_patientListError_t
{
	PATIENT_LIST_OK, PATIENT_LIST_EXIST, PATIENT_LIST_PATIENT_NOT_EXIST, PATIENT_LIST_ALREADY_EXIST,
	PATIENT_LIST_INVALID_ID, PATIENT_LIST_EDIT_CANCELLED, PATIENT_LIST_EMPTY
} EN_patientListError_t;



typedef enum EN_reservationListError_t
{
	RESERVATION_LIST_DONE, RESERVATION_LIST_CANCEL, RESERVATION_LIST_COMPLETED, RESERVATION_LIST_WRONG_ID, RESERVATION_LIST_EXIST,
	RESERVATION_LIST_NOT_EXIST , RESERVATION_LIST_ALREADY_RESERVED, RESERVATION_LIST_EMPTY
} EN_reservationListError_t;





void lists_init();



EN_patientListError_t RegistNewPatient();
EN_patientListError_t addNewPatient(ST_patient_t** storingAddress);
void printPatientList();
EN_patientListError_t searchAtPatient(uint8_t id[]);
EN_patientListError_t searchAtPatientThenStore(uint8_t id[], ST_patient_t** storingAddress);
EN_patientListError_t editPatient();
EN_patientListError_t viewPatientRecord();




void printSlotList();
EN_slotListError_t createNewSlot(float start, float end);
EN_slotListError_t addNewSlot();
EN_slotListError_t chooseSlot(ST_slot_t** storingAddress);



EN_patientListError_t isInReservationList(ST_patient_t* temp);
EN_reservationListError_t deleteReservation(ST_reservation_t* temp);
EN_reservationListError_t Reserve();
EN_reservationListError_t cancelReservation();
void viewTodayReservations();





#endif // CLINIC_H_INCLUDED