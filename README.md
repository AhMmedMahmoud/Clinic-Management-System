# Clinic-Management-System
this project was written in c using Microsoft Visual Studio
## Aim
implement clinic management system helps clinic receptionist to manage the clinic
## Procedure Details
At the beginning of the system, it asks the user to choose between admin mode and user mode.
### Admin Mode
The system asks for password, the default password is 1234. The system allows 3 trails for the password entry, if the entered password was incorrect for 3 consecutive times, the system shall close. After login in the admin mode, the system shall provide the following features:

### 1. Add new patient record
To add a new patient, the admin shall shall enter these basic information: name, age, gender and ID.

### 2. Edit patient record
By entering patient ID, the system allows the admin to edit the patient information.

### 3. Reserve a slot with the doctor
- By default there are 5 available slots, 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm and 4:30pm to 5pm.
- Upon opening of this window, The admin shall enter the patient ID
- if patient is already registered, the system shall display the available slots to choose  desired slot.
- if patient isnot registered, the system asks for entire information then display the available slots to choose desired slot
### 4. Cancel reservation
By entering patient ID, the system allows the admin to cancel the reservation.

### 5. Change Slot Reservation
By entering patient ID, the system allows the admin to cjange slot reservation.

### 6. Log out
exit from admin mode

### User Mode
There is no password. The system allows the following features:
#### 1. View patient record
By entering the patient ID, the system shall show the basic information for the patient.

### 2. View today’s reservation
the system shall print all reservations with the patient Information and reserved slot attached to each reservation.

### 3. Exit From User Mode
exit from admin mode

## Project State Diagram
![image](https://user-images.githubusercontent.com/104006521/189241357-4d634398-f1d1-4e07-9d8b-3d60ac84885a.png)

## Constraints
- Admin Password is 4 characters
- Patient ID is 14 numeric characters
- Patient Name is 24 alphabetic characters string max and 20 min.
- Patient Age is less than 300.
- Slot start time and slot end time are float in the format HH.MM, e.g 12.30.
- Slot end time must be greater than slot start time.
- at Register New Patient operation or Reserve Operation, entering any invalid data about patient keeps asking for Re-entering
valid data.
- patients' database is a linked list of ST_patient_t for patients.
- slots' database is a linked list of ST_slot_t for the defined slots by admin.
- reservations' database is a linked list of ST_reservation_t for the upcoming appointments only.


## Video 
[here](https://drive.google.com/file/d/1MzAeNSiVyD5y7izZ9DSC3t569PHGfPec/view?usp=sharing)
## Zip File 
[here](https://drive.google.com/file/d/1UFmx2mPELyvGPVMZOBtz_p7yB3pRz3l9/view?usp=sharing)
## Documentation
the following shots are taken from the application during running
## Choosing Mode
![image](https://user-images.githubusercontent.com/104006521/189236657-11a96f39-a123-4287-90bb-d5bbfc0e20e8.png)
## Entering to Admin Mode
![image](https://user-images.githubusercontent.com/104006521/189236728-19091b3f-11ba-4d5c-8b4d-82f89212a136.png)
## Entering to User Mode
![image](https://user-images.githubusercontent.com/104006521/189258531-70ce726c-a82d-4360-860f-6c4b70ead96e.png)
## Log In
![image](https://user-images.githubusercontent.com/104006521/189236849-dea2633c-d581-441c-bbc7-57c84c3093ea.png)
![image](https://user-images.githubusercontent.com/104006521/189236946-d1131e5c-5769-4bb4-93f6-2ea23d5b0b96.png)
## choosing from admin operations
![image](https://user-images.githubusercontent.com/104006521/189237121-b3fc4f30-bd5e-475f-9963-bb173f5985df.png)
## choosing from user operations
![image](https://user-images.githubusercontent.com/104006521/189258365-59a4369b-f35e-4cca-948e-cec7bd23e2ef.png)
## Enter Patient ID
![image](https://user-images.githubusercontent.com/104006521/189252600-843ab7d8-20d5-4c88-9324-bf87f5fc01f2.png)
![image](https://user-images.githubusercontent.com/104006521/189252759-dd19d3c8-c15a-4028-928a-d23c6079ffdc.png)
## Enter Patient Name
![image](https://user-images.githubusercontent.com/104006521/189252872-138f800e-dc64-4a55-88b5-21e83f7a40f3.png)
![image](https://user-images.githubusercontent.com/104006521/189252981-074feb03-f8aa-4c78-b1d8-49e8b22503ad.png)
## Enter Patient Gender
![image](https://user-images.githubusercontent.com/104006521/189253144-96142d9c-13a9-401b-ba84-61cb0fc20468.png)
![image](https://user-images.githubusercontent.com/104006521/189253324-f93dc289-3cba-4b74-970f-6ea40ccda793.png)
## Enter Patient Age
![image](https://user-images.githubusercontent.com/104006521/189253396-c2542844-4b94-4245-9804-cec2e2251df4.png)
![image](https://user-images.githubusercontent.com/104006521/189253478-dfb156e9-594d-40b4-ae66-b14b57600fa2.png)
# choosing Register for New Patient Operation
- Choosing mode
- Entering to admin mode
- log in
- choosing from admin operation
- ![image](https://user-images.githubusercontent.com/104006521/189237671-35c871f8-54ee-433a-80fb-ef024803f6d8.png)
- entering patient information
- ![image](https://user-images.githubusercontent.com/104006521/189253916-421dd202-e263-45d5-a5c0-c702f425eb63.png)
- ![image](https://user-images.githubusercontent.com/104006521/189253956-236caf46-fcbb-432b-94ab-488aeb10164f.png)
# choosing Edit Patient Operation
- Choosing mode
- Entering to admin mode
- log in
- choosing from admin operation
- ![image](https://user-images.githubusercontent.com/104006521/189254865-a9771d07-19e7-40ea-9bce-57fbaaa3c1b0.png)
- Enter Patient id
- ![image](https://user-images.githubusercontent.com/104006521/189252600-843ab7d8-20d5-4c88-9324-bf87f5fc01f2.png)
- ![image](https://user-images.githubusercontent.com/104006521/189252759-dd19d3c8-c15a-4028-928a-d23c6079ffdc.png)
- choose which patient information to edit
- ![image](https://user-images.githubusercontent.com/104006521/189255200-dbf49e1d-189c-42fe-8d75-c7215f8614fd.png)
- for example: choosing age
- ![image](https://user-images.githubusercontent.com/104006521/189255378-d796b2ea-7162-4f9c-92d8-378f801fb3b0.png)
- ![image](https://user-images.githubusercontent.com/104006521/189255660-7e962d78-2670-4144-ab99-0efe64aca624.png)
- ![image](https://user-images.githubusercontent.com/104006521/189255721-acc22b27-6984-4032-b977-e443eb00e43c.png)
- ![image](https://user-images.githubusercontent.com/104006521/189255761-2121180b-4dc6-495c-a903-7a0445c9b71d.png)
# choosing Reserve Operation
- Choosing mode
- Entering to admin mode
- log in
- choosing from admin operation
- ![image](https://user-images.githubusercontent.com/104006521/189256342-d4d1ffbb-c75f-4d44-b57d-5f8972e2b0a3.png)
- Enter Patient id
- ![image](https://user-images.githubusercontent.com/104006521/189252600-843ab7d8-20d5-4c88-9324-bf87f5fc01f2.png)
- ![image](https://user-images.githubusercontent.com/104006521/189252759-dd19d3c8-c15a-4028-928a-d23c6079ffdc.png)
- Choose a slot
- ![image](https://user-images.githubusercontent.com/104006521/189256486-bb6c6fb9-0ba4-4354-92a3-1b18a6193ee2.png)
- for example: 2.00 to 2.30
- ![image](https://user-images.githubusercontent.com/104006521/189256555-fbcec18f-a8a8-4606-a658-5dfb147ef505.png)
![image](https://user-images.githubusercontent.com/104006521/189256604-4e7fb052-79b9-4dc2-a310-9c42a477d1f3.png)
# Choosing Cancell Reseervation Operation
- Choosing mode
- Entering to admin mode
- log in
- choosing from admin operation
- ![image](https://user-images.githubusercontent.com/104006521/189256879-aa4b8ebd-d339-4f63-b2c8-ffcc267a21ac.png)
- Enter Patient id
- ![image](https://user-images.githubusercontent.com/104006521/189252600-843ab7d8-20d5-4c88-9324-bf87f5fc01f2.png)
- ![image](https://user-images.githubusercontent.com/104006521/189252759-dd19d3c8-c15a-4028-928a-d23c6079ffdc.png)
- confirm cancell
- ![image](https://user-images.githubusercontent.com/104006521/189256988-8d1ff440-bb3b-4aa6-b568-ffe2f53793e5.png)
- ![image](https://user-images.githubusercontent.com/104006521/189257066-e515816b-f8ca-4a9b-b98b-4055a945241e.png)
- ![image](https://user-images.githubusercontent.com/104006521/189257103-f80fdc95-ce8b-4437-8e3d-cce7f3a125bf.png)
# Choosing Change Slot Operation
- Choosing mode
- Entering to admin mode
- log in
- choosing from admin operation
- ![image](https://user-images.githubusercontent.com/104006521/189257382-cc2f7ef3-515d-4c02-967a-652e68714218.png)
- Enter Patient id
- ![image](https://user-images.githubusercontent.com/104006521/189252600-843ab7d8-20d5-4c88-9324-bf87f5fc01f2.png)
- ![image](https://user-images.githubusercontent.com/104006521/189252759-dd19d3c8-c15a-4028-928a-d23c6079ffdc.png)
- choose from available slots
- ![image](https://user-images.githubusercontent.com/104006521/189257680-2e297006-75e8-43bc-9516-ab485e759018.png)
- for example: 4.00 to 4.30
- ![image](https://user-images.githubusercontent.com/104006521/189257745-ecbe0837-74a6-4959-934a-ed89c192b5c7.png)
- ![image](https://user-images.githubusercontent.com/104006521/189257814-dc854c45-25bb-4567-8611-1e4a57602c42.png)
# Choosing View Patient Record Operation
- Choosing mode
- Entering to user mode
- choosing from user operation
- ![image](https://user-images.githubusercontent.com/104006521/189259481-542dea94-5624-4ae2-9b91-d36a6381bfd6.png)
- Enter Patient id
- ![image](https://user-images.githubusercontent.com/104006521/189252600-843ab7d8-20d5-4c88-9324-bf87f5fc01f2.png)
- ![image](https://user-images.githubusercontent.com/104006521/189252759-dd19d3c8-c15a-4028-928a-d23c6079ffdc.png)
- ![image](https://user-images.githubusercontent.com/104006521/189259830-eb34abe9-c7bb-4793-8a08-7f49e5541d6f.png)
# Choosing View Today Reservation Operation
- Choosing mode
- Entering to user mode
- choosing from user operation
- ![image](https://user-images.githubusercontent.com/104006521/189258700-90d0a8eb-9ea6-44b1-af53-42dce04ab595.png)
![image](https://user-images.githubusercontent.com/104006521/189258772-64ad1617-786f-4e43-a27a-da7ed6db69d0.png)
![image](https://user-images.githubusercontent.com/104006521/189258831-cb2a0788-51af-4326-932e-00890ca51d88.png)
