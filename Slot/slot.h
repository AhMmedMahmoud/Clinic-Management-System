#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED

#include <stdio.h>
#include "../Utilities/types.h"

typedef enum EN_slotState_t
{
	NOT_RESERVED, RESERVED
} EN_slotState_t;

typedef enum EN_slotError_t
{
	SLOT_OK, SLOT_INVALID_TIME, SLOT_INVALID_NUMBER
} EN_slotError_t;

typedef struct ST_slot_t
{
	float slotStartTime;
	float slotEndTime;
	EN_slotState_t slotState;
	uint16_t slotNumber;
	struct ST_slot_t* nextSlot;
} ST_slot_t;


// functions prototypes
EN_slotError_t getSlotStartTime(ST_slot_t* slot);
EN_slotError_t getSlotEndTime(ST_slot_t* slot);
EN_slotError_t setSlot(ST_slot_t* slot, float start, float end);
EN_slotError_t setSlotNumber(ST_slot_t* slot, uint16_t number);
void printSlot(ST_slot_t* slot);
void printSlotRanges(ST_slot_t* slot);

#endif // SLOT_H_INCLUDED