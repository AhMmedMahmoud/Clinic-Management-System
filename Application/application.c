#include "application.h"


EN_mode_t mode;
EN_operation_t operation;

ST_admin_t admin;

void setup()
{
	lists_init();

	createNewSlot(2.00, 2.30);
	createNewSlot(2.30, 3.00);
	createNewSlot(3.00, 3.30);
	createNewSlot(3.30, 4.00);
	createNewSlot(4.00, 4.30);
	
	setAdminPassword(&admin, "1234");
}

void appStart()
{
	system("cls");
	printf("press  ---> 0 for Admin Mode\n");
	printf("       ---> 1 for User Mode\n");
	
	scanf_s("%d", &mode);	while ((getchar()) != '\n'); //consume the '\n' char

	switch (mode)
	{
		case ADMIN:
			if (askPasswordThenCheckForThreeTrial(admin) == ADMIN_OK)
			{
				RemainInAdminMode: system("cls");
				printf("press   --> 0 for Register New Patient\n");
				printf("	--> 1 for Edit Patient\n");
				printf("	--> 2 for Reserve\n");
				printf("	--> 3 for Cancel Reservation\n");
				printf("	--> 4 for Change Slot\n");
				printf("	--> 5 for Log Out\n");

				scanf_s("%d", &operation);	while ((getchar()) != '\n'); //consume the '\n' char

				switch (operation)
				{
					case ADMIN_OPERATION_REGISTER_NEW_PATIENT:
						system("cls");
						switch (RegistNewPatient())
						{
							case PATIENT_LIST_ALREADY_EXIST:
								printf("already registed\n");
							break;

							case PATIENT_LIST_OK:
								printf("registration is done\n");
							break;
						}
						printf("Press Any Key To Continue");
						getchar();
						goto RemainInAdminMode;
					break;

					case ADMIN_OPERATION_EDIT_PATIENT:
						system("cls");
						switch (editPatient())
						{		
							case PATIENT_LIST_EMPTY:
								printf("there arenot any registed patients yet\n");
							break;

							case PATIENT_LIST_INVALID_ID:
								printf("Invalid ID\n");
							break;

							case PATIENT_LIST_PATIENT_NOT_EXIST:
								printf("not registed\n");
							break;

							case PATIENT_LIST_EDIT_CANCELLED:
								printf("editing patient is cancelled\n");
							break;

							case PATIENT_LIST_OK:
								printf("editing patient is done\n");
							break;
						}
						printf("Press Any Key To Continue");
						getchar();
						goto RemainInAdminMode;

					break;

					case ADMIN_OPERATION_RESERVE:
						system("cls");
						switch (Reserve())
						{
							case RESERVATION_LIST_CANCEL:
								printf("reservation is cancelled\n");
							break;

							case RESERVATION_LIST_COMPLETED:
								printf("all slots are occupied\n");
							break;

							case RESERVATION_LIST_ALREADY_RESERVED:
								printf("reserved already\n");
							break;

							case RESERVATION_LIST_DONE:
								printf("reservation is done\n");
							break;
						}
						printf("Press Any Key To Continue");
						getchar();
						goto RemainInAdminMode;
					break;

					case ADMIN_OPERATION_CANCEL_RESERVATION:
						system("cls");
						switch (cancelReservation())
						{
							case RESERVATION_LIST_EMPTY:
							printf("there arenot any reservation yet\n");
							break;

							case RESERVATION_LIST_CANCEL:
								printf("reservation is not cancelled\n");
							break;

							case RESERVATION_LIST_NOT_EXIST:
								printf("reservation is not exist\n");
							break;

							case RESERVATION_LIST_DONE:
								printf("cancell reservation is done\n");
							break;
						}
						printf("Press Any Key To Continue");
						getchar();
						goto RemainInAdminMode;
					break;

					case ADMIN_OPERATION_EDIT_RESERVATION:
						system("cls");
						switch (changeSlotReservation())
						{		
							case RESERVATION_LIST_EMPTY:
								printf("there arenot any reservation yet\n");
							break;

							case RESERVATION_LIST_WRONG_ID:
								printf("Invalid ID\n");
							break;

							case RESERVATION_LIST_CANCEL:
								printf("changing slot is cancelled\n");
							break;

							case RESERVATION_LIST_NOT_EXIST:
								printf("reservation is not exist\n");
							break;

							case RESERVATION_LIST_COMPLETED:
								printf("all slots are occupied\n");
							break;

							case RESERVATION_LIST_DONE:
								printf("changing slot is done\n");
							break;
						}
						printf("Press Any Key To Continue");
						getchar();
						goto RemainInAdminMode;
					break;

					case LOGOUT:
						break;

					default:
						goto RemainInAdminMode;
				}
			}
		break;

		case USER:
			RemainInUserMode: system("cls");
			printf("press   --> 0 for View Patient Record\n");
			printf("	--> 1 for View Today Reservation\n");
			printf("	--> 2 for Exit From User Mode\n");

			scanf_s("%d", &operation);	while ((getchar()) != '\n'); //consume the '\n' char
			switch (operation)
			{
				case USER_OPERATION_VIEW_PATIENT_RECORD:
					switch (viewPatientRecord())
					{
						case PATIENT_LIST_OK:
							printf("view patient record is done\n");
						break;

						case PATIENT_LIST_INVALID_ID:
							printf("invalid id\n");
						break;

						case PATIENT_LIST_PATIENT_NOT_EXIST:
							printf("not registed\n");
						break;
					}
					printf("Press Any Key To Continue");
					getchar();
					goto RemainInUserMode;
				break;

				case USER_OPERATION_TODAY_RESERVATION:
					viewTodayReservations();
					printf("Press Any Key To Continue");
					getchar();
					goto RemainInUserMode;
				break;

				case EXIT_FROM_USER_MODE:
					break;

				default:
					goto RemainInUserMode;
			}
		break;
	}
}



