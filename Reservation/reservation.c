#include "reservation.h"


/*
this functions print all information of reservation
it prints patient data, slot data, reservation SeqNumber
*/
void printReservation(ST_reservation_t reservation)
{
	printPatient(reservation.patient);
	printf("Slot	  :%.2f to %.2f\n", reservation.slot->slotStartTime , reservation.slot->slotEndTime);
	printf("SeqNumber :%d \n", reservation.sequentialNumber);
	printf("----------------------------------\n");
}

