#include "slot.h"


/*
this functions asks for start time of slot
it checks entered time
if entered time is negative or less than 0, return SLOT_INVALID_TIME
if entered time is minutes greater than or equal 60, return SLOT_INVALID_TIME
if entered time is greater than or equal 23.60,return SLOT_INVALID_TIME
else store entered time and return SLOT_OK
*/
EN_slotError_t getSlotStartTime(ST_slot_t* slot)
{
	printf("Enter slot start time: ");
	float temp;
	scanf_s("%f", &temp);

	if (temp <= 0 || (((temp - (int)temp) * 100) > 60) || temp > 23.60)
		return SLOT_INVALID_TIME;
	else
		slot->slotStartTime = temp;

	return SLOT_OK;
}




/*
this functions asks for end time of slot
it checks entered time
if entered time is negative or less than 0, return SLOT_INVALID_TIME
if entered time is minutes greater than or equal 60, return SLOT_INVALID_TIME
if entered time is greater than or equal 23.60, return SLOT_INVALID_TIME
if entered time less than start time, return SLOT_INVALID_TIME
else store entered time and return SLOT_OK
*/
EN_slotError_t getSlotEndTime(ST_slot_t* slot)
{
	printf("Enter slot End time: ");
	float temp;
	scanf_s("%f", &temp);

	if (temp <= 0 || (((temp - (int)temp) * 100) > 60) || temp < slot->slotStartTime || temp > 23.60)
		return SLOT_INVALID_TIME;
	else
	{
		slot->slotEndTime = temp;
		return SLOT_OK;
	}
}



/*
this functions set  start and end time of slot
it checks entered start time and entered end time
if entered start time is negative or less than 0, return SLOT_INVALID_TIME
if entered start time is minutes greater than or equal 60, return SLOT_INVALID_TIME
if entered start time is greater than or equal 23.60,return SLOT_INVALID_TIME
if entered end time is negative or less than 0, return SLOT_INVALID_TIME
if entered end time is minutes greater than or equal 60, return SLOT_INVALID_TIME
if entered end time is greater than or equal 23.60, return SLOT_INVALID_TIME
if entered end time less than entered start time, return SLOT_INVALID_TIME
else store entered start time, entered end time and return SLOT_OK
*/
EN_slotError_t setSlot(ST_slot_t* slot, float start, float end)
{
	if (start <= 0 || start > 23.60 || (((start - (int)start) * 100) > 60)
		|| end <= 0 || end > 23.60 || (((end - (int)end) * 100) > 60)
		|| start >= end)
		return SLOT_INVALID_TIME;
	else
	{
		slot->slotStartTime = start;
		slot->slotEndTime = end;
		return SLOT_OK;
	}
}



/*
this functions set number for slot 
it checks passed number
if it less than 0, it return SLOT_INVALID_NUMBER
else it stores entered number and return SLOT_OK
*/
EN_slotError_t setSlotNumber(ST_slot_t* slot, uint16_t number)
{
	if (number < 0)
		return SLOT_INVALID_NUMBER;

	slot->slotNumber = number;
	return SLOT_OK;
}


/*
this functions print slot information
*/
void printSlot(ST_slot_t* slot)
{
	if (slot->slotState == RESERVED)
		printf("%.2f to %.2f	Reserved\n", slot->slotStartTime, slot->slotEndTime);
	else
		printf("%.2f to %.2f	notReserved\n", slot->slotStartTime, slot->slotEndTime);
}


void printSlotRanges(ST_slot_t* slot)
{
	printf("%.2f to %.2f\n", slot->slotStartTime, slot->slotEndTime);
}



