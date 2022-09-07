#include "clinic.h"

ST_slotList_t slotsList;
ST_patientsList_t patientsList;
ST_reservationList_t reservationsList;
static uint16_t seqNumber = 1;


/*
this functions initialize slots, patients, reservations lists
*/
void lists_init()
{
	patientsList.noOfPatients = 0;
	patientsList.head = NULL;
	patientsList.tail = NULL;

	slotsList.noOfSlots = 0;
	slotsList.head = NULL;
	slotsList.tail = NULL;

	reservationsList.noOfReservations = 0;
	reservationsList.head = NULL;
	reservationsList.tail = NULL;
}



////////////////////////////////////patient list/////////////////////////////////////////////////////


EN_patientListError_t RegistNewPatient()
{
	ST_patient_t* temp = (ST_patient_t*)calloc(1, sizeof(ST_patient_t));

	while (getPatientId(temp) != PATIENT_OK);

	if (searchAtPatient(temp->patientId) == PATIENT_LIST_EXIST)
	{
		free(temp);
		return PATIENT_LIST_ALREADY_EXIST;
	}

	while (getPatientName(temp) != PATIENT_OK);
	while (getPatientGender(temp) != PATIENT_OK);
	while (getPatientAge(temp) != PATIENT_OK);

	temp->nextPatient = NULL;

	if (patientsList.noOfPatients == 0)
	{
		patientsList.head = temp;
		patientsList.tail = temp;
		patientsList.noOfPatients++;
	}
	else
	{
		patientsList.tail->nextPatient = temp;
		patientsList.tail = temp;
		patientsList.noOfPatients++;
	}
	return PATIENT_LIST_OK;
}


EN_patientListError_t addNewPatient(ST_patient_t **storingAddress)
{	
	ST_patient_t *temp = (ST_patient_t*)calloc(1, sizeof(ST_patient_t));

	while (getPatientId(temp) != PATIENT_OK);

	if (searchAtPatientThenStore(temp->patientId, storingAddress) == PATIENT_LIST_EXIST)
	{
		free(temp);
		return PATIENT_LIST_ALREADY_EXIST;
	}

	while (getPatientName(temp) != PATIENT_OK);
	while (getPatientGender(temp) != PATIENT_OK);
	while (getPatientAge(temp) != PATIENT_OK);
	
	temp->nextPatient = NULL;

	if (patientsList.noOfPatients == 0)
	{
		patientsList.head = temp;
		patientsList.tail = temp;
		patientsList.noOfPatients++;
	}
	else
	{
		patientsList.tail->nextPatient = temp;
		patientsList.tail = temp;
		patientsList.noOfPatients++;
	}
	*storingAddress = temp;
	return PATIENT_LIST_OK;
}


void printPatientList()
{
	ST_patient_t* current = patientsList.head;
	while(current != NULL)
	{
		printPatient(current);
		current = current->nextPatient;
		printf("-------------------------------------\n");
	}
}


EN_patientListError_t searchAtPatient(uint8_t id[])
{
	ST_patient_t* current = patientsList.head;
	while (current != NULL)
	{
		if (strcmp(current->patientId, id) == 0)
		{
			return PATIENT_LIST_EXIST;
		}
		current = current->nextPatient;
	}
	return PATIENT_LIST_PATIENT_NOT_EXIST;
}


EN_patientListError_t searchAtPatientThenStore(uint8_t id[], ST_patient_t** storingAddress)
{
	ST_patient_t* current = patientsList.head;
	while (current != NULL)
	{
		if (strcmp(current->patientId, id) == 0)
		{
			*storingAddress = current;
			return PATIENT_LIST_EXIST;
		}
		current = current->nextPatient;
	}
	return PATIENT_LIST_PATIENT_NOT_EXIST;
}


EN_patientListError_t viewPatientRecord()
{
	printf("Enter ID: ");
	uint8_t bStr[16];

	fgets(bStr, 16, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');

	int i;
	for (i = 0; bStr[i] != 0; i++) {}

	if (i <= 14 || (i == 15 && bStr[i - 1] != 10))
		return PATIENT_LIST_INVALID_ID;

	memcpy(bStr, &bStr[0], i - 1);
	bStr[i - 1] = '\0';


	ST_patient_t* current = patientsList.head;
	while (current != NULL)
	{
		if (strcmp(current->patientId, bStr) == 0)
		{
			system("cls");
			printPatient(current);
			return PATIENT_LIST_OK;
		}
		current = current->nextPatient;
	}

	return PATIENT_LIST_PATIENT_NOT_EXIST;
}


EN_patientListError_t editPatient()
{
	if (patientsList.noOfPatients == 0)
		return PATIENT_LIST_EMPTY;

	printf("Enter ID: ");
	uint8_t bStr[16];

	fgets(bStr, 16, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');

	int i;
	for (i = 0; bStr[i] != 0; i++) {}

	if (i <= 14 || (i == 15 && bStr[i - 1] != 10))
		return PATIENT_LIST_INVALID_ID;

	memcpy(bStr, &bStr[0], i - 1);
	bStr[i - 1] = '\0';


	ST_patient_t* current = patientsList.head;
	while (current != NULL)
	{
		if (strcmp(current->patientId, bStr) == 0)
		{
			printf("press  --> 0 for edit name\n       --> 1 for edit id\n       --> 2 for edit gender\n       --> 3 for edit age\n       --> 4 for cancel\n");
			uint16_t read;
			scanf_s("%d", &read);
			switch (read)
			{
				case 0:
					while (getPatientName(current) != PATIENT_OK);
					return PATIENT_LIST_OK;
				case 1:
					while (getPatientId(current) != PATIENT_OK);
					return PATIENT_LIST_OK;
				case 2:
					while (getPatientGender(current) != PATIENT_OK);
					return PATIENT_LIST_OK;
				case 3:
					while (getPatientAge(current) != PATIENT_OK);
					return PATIENT_LIST_OK;
				case 4:
					return PATIENT_LIST_EDIT_CANCELLED;
			}
		}
		current = current->nextPatient;
	}
	return PATIENT_LIST_PATIENT_NOT_EXIST;
}




///////////////////////////////////////////////slot list//////////////////////////////////////////////////

void printSlotList()
{
	ST_slot_t* current = slotsList.head;
	while (current != NULL)
	{
		printSlot(current);
		current = current->nextSlot;
		printf("-------------------------------------\n");
	}
}


EN_slotListError_t addNewSlot()
{
	ST_slot_t* temp = (ST_slot_t*)calloc(1, sizeof(ST_slot_t));

	while( getSlotStartTime(temp) != SLOT_OK ){}
	while (getSlotEndTime(temp) != SLOT_OK) {}

	temp->nextSlot = NULL;

	if (slotsList.noOfSlots == 0)
	{
		slotsList.head = temp;
		slotsList.tail = temp;
		slotsList.noOfSlots++;
	}
	else
	{
		slotsList.tail->nextSlot = temp;
		slotsList.tail = temp;
		slotsList.noOfSlots++;
	}
	return SLOT_LIST_OK;
}


EN_slotListError_t createNewSlot(float start, float end)
{
	ST_slot_t* temp = (ST_slot_t*)calloc(1, sizeof(ST_slot_t));

	setSlot(temp, start, end);

	temp->nextSlot = NULL;

	if (slotsList.noOfSlots == 0)
	{
		slotsList.head = temp;
		slotsList.tail = temp;
		slotsList.noOfSlots++;
	}
	else
	{
		slotsList.tail->nextSlot = temp;
		slotsList.tail = temp;
		slotsList.noOfSlots++;
	}
	return SLOT_LIST_OK;
}


EN_slotListError_t chooseSlot(ST_slot_t **storingAddress)
{
	if (reservationsList.noOfReservations == slotsList.noOfSlots)
		return SLOT_LIST_COMPLETELY_CHOSEN;

	ST_slot_t* current;
	int i;
back:
	current = slotsList.head;
	i = 0;
	while (current != NULL)
	{
		if (current->slotState == NOT_RESERVED)
		{
			if (i == 0)	 printf("press  --> %d for reserve ", i);
			else         printf("       --> %d for reserve ", i);

			current->slotNumber = i++;
			printSlotRanges(current);
		}
		current = current->nextSlot;
	}
	printf("       --> %d for cancel\n", i);

	int read;
	scanf_s("%d", &read);	while ((getchar()) != '\n'); //consume the '\n' char
	
	if (read < i && read >= 0)
	{
		current = slotsList.head;
		while (current != NULL)
		{
			if ((current->slotState == NOT_RESERVED) && (current->slotNumber == read))
			{
				*storingAddress = current;
				current->slotState = RESERVED;
			}
			current = current->nextSlot;
		}
	}
	else if (read == i)	 return SLOT_LIST_CANCEL;
	else				 goto back;
}



////////////////////////////////////reservation list/////////////////////////////////////////////////////

EN_patientListError_t isInReservationList(ST_patient_t *temp)
{
	ST_reservation_t* current = reservationsList.head;
	while (current != NULL)
	{
		if (current->patient == temp)	return RESERVATION_LIST_EXIST;
		current = current->nextReservation;
	}
	return RESERVATION_LIST_NOT_EXIST;
}


EN_reservationListError_t Reserve()
{
	if (reservationsList.noOfReservations == slotsList.noOfSlots)
		return	RESERVATION_LIST_COMPLETED;

	ST_reservation_t *temp = (ST_reservation_t*)calloc(1, sizeof(ST_reservation_t));

	addNewPatient(&(temp->patient));
	
	// check if patient already reserved
	if (isInReservationList(temp->patient) == RESERVATION_LIST_EXIST)
	{
		free(temp);
		return RESERVATION_LIST_ALREADY_RESERVED;
	}

	// choosing from non reserved slots
	switch( chooseSlot(&(temp->slot)) )
	{		
		case SLOT_LIST_CANCEL:
			free(temp);
			return RESERVATION_LIST_CANCEL;

		case SLOT_LIST_COMPLETELY_CHOSEN:
			free(temp);
			return RESERVATION_LIST_COMPLETED;
	}

	temp->nextReservation = NULL;
	temp->sequentialNumber = seqNumber++;
	if (reservationsList.noOfReservations == 0)
	{
		reservationsList.head = temp;
		reservationsList.tail = temp;
		reservationsList.noOfReservations++;
	}
	else
	{
		reservationsList.tail->nextReservation = temp;
		reservationsList.tail = temp;
		reservationsList.noOfReservations++;
	}
	return RESERVATION_LIST_DONE;
}


void viewTodayReservations()
{
	system("cls");
	printf("Reservations\n");
	printf("-------------------------------------\n");
	ST_reservation_t* current = reservationsList.head;
	while (current != NULL)
	{
		printReservation(*current);
		current = current->nextReservation;
	}
}


EN_reservationListError_t deleteReservation(ST_reservation_t* temp)
{
	/*
	
	no head and no tail need  update
	tail only			needs update     last element in more than elements list       ok
	head only			needs update     first element in more than elements list	   ok
	head and tail		need  update     only one element in list                      ok
	
	*/


	//head and tail		need  update
	if ((reservationsList.head == reservationsList.tail) && reservationsList.head == temp)
	{
		reservationsList.head = NULL;
		reservationsList.tail = NULL;
		temp->slot->slotState = NOT_RESERVED;
		free(temp);
		reservationsList.noOfReservations--;
		return RESERVATION_LIST_DONE;
	}

	//head only			needs update
	else if ((temp == reservationsList.head) && (reservationsList.noOfReservations > 1))
	{
		reservationsList.head = reservationsList.head->nextReservation;
		temp->slot->slotState = NOT_RESERVED;
		free(temp);
		reservationsList.noOfReservations--;
		return RESERVATION_LIST_DONE;
	}

	ST_reservation_t* current = reservationsList.head;
	while (current != NULL)
	{
		if (current->nextReservation == temp)
		{
			if (temp == reservationsList.tail)
			{
				current->nextReservation = NULL;
				reservationsList.tail = current;			
			}
			else
			{
				current->nextReservation = temp->nextReservation;
			}
			temp->slot->slotState = NOT_RESERVED;
			free(temp);
			reservationsList.noOfReservations--;
			return RESERVATION_LIST_DONE;
		}
		current = current->nextReservation;
	}
	return RESERVATION_LIST_NOT_EXIST;
}


EN_reservationListError_t cancelReservation()
{
	if (reservationsList.noOfReservations == 0)
		return RESERVATION_LIST_EMPTY;

	printf("Enter ID: ");
	uint8_t bStr[16];

	fgets(bStr, 16, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');

	int i;
	for (i = 0; bStr[i] != 0; i++) {}

	if (i <= 14 || (i == 15 && bStr[i - 1] != 10))
		return RESERVATION_LIST_WRONG_ID;

	memcpy(bStr, &bStr[0], i - 1);
	bStr[i - 1] = '\0';

	ST_reservation_t* current;

ReAsk:	current = reservationsList.head;
	while (current != NULL)
	{
		if (strcmp(current->patient->patientId, bStr) == 0)
		{
			printf("press  --> 0 for cancel reservation\n       --> 1 for NOT cancel reservation\n");

			uint16_t read;
			scanf_s("%d", &read);	while ((getchar()) != '\n'); //consume the '\n' char

			if (read == 0)
			{
				deleteReservation(current);
				return RESERVATION_LIST_DONE;
			}
			else if (read == 1)		return RESERVATION_LIST_CANCEL;
			else					goto ReAsk;
		}
		current = current->nextReservation;
	}
	return RESERVATION_LIST_NOT_EXIST;
}


EN_reservationListError_t changeSlotReservation()
{	
	if (reservationsList.noOfReservations == 0)
		return RESERVATION_LIST_EMPTY;

	printf("Enter ID: ");
	uint8_t bStr[16];

	fgets(bStr, 16, stdin);
	if (!strchr(bStr, '\n'))            //remove extra characters from fgets
		while (fgetc(stdin) != '\n');

	int i;
	for (i = 0; bStr[i] != 0; i++) {}

	if (i <= 14 || (i == 15 && bStr[i - 1] != 10))
		return RESERVATION_LIST_WRONG_ID;

	memcpy(bStr, &bStr[0], i - 1);
	bStr[i - 1] = '\0';

	ST_reservation_t* current;

ReAsk:	current = reservationsList.head;
	while (current != NULL)
	{
		if (strcmp(current->patient->patientId, bStr) == 0)
		{
			ST_slot_t* temp = current->slot;
			switch( chooseSlot(&(current->slot)) )
			{
				case RESERVATION_LIST_DONE:
					temp->slotState = NOT_RESERVED;
					return RESERVATION_LIST_DONE;
				break;

				case RESERVATION_LIST_COMPLETED:
					return RESERVATION_LIST_COMPLETED;
				break;

				case RESERVATION_LIST_CANCEL:
					return RESERVATION_LIST_CANCEL;
				break;
			}
			return RESERVATION_LIST_DONE;
		}
		current = current->nextReservation;
	}
	return RESERVATION_LIST_NOT_EXIST;
}