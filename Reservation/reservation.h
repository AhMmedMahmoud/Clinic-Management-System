#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

#include <stdio.h>
#include "../Utilities/types.h"
#include "../Patient/patient.h"
#include "../Slot/slot.h"


typedef struct ST_reservation_t
{
	ST_patient_t *patient;
	ST_slot_t *slot;
	uint16_t sequentialNumber;
	struct ST_reservation_t *nextReservation;
} ST_reservation_t;


void printReservation(ST_reservation_t reservation);




#endif // RESERVATION_H_INCLUDED