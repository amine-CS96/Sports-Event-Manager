
# Sports Event Manager — Competitive Event Tracking System in C

## Description

This C program is a command-line application that manages sports events and participants. It allows users to register participants, create events, assign participants to events based on their sport type, update results, and save or load data from files.

The project makes use of dynamic memory allocation and doubly-linked lists to handle flexible data structures efficiently. It also practices modular programming with header files.

---

## Features

* Register new participants with name, age, and sport.
* Create new sports events with a name, date, and sport type.
* Automatically link participants to events based on their sport.
* Update event results for specific participants.
* Display all events and their participants with details.
* Save events and participant data to a file.
* Load and display event data from a file.

---

## Project Structure

* `main.c` — contains the main menu loop and user interaction logic.
* `events.h` — defines data structures and declares/implements all functions (e.g., event and participant handling).

---

## Compilation & Execution

```bash
gcc src/main.c -o sports-event-manager
./sports-event-manager
```

---

## Usage

1. Run the program.

2. Select an option from the menu:

   * **1**: Register a new participant.
   * **2**: Add a new event (participants with the matching sport are auto-assigned).
   * **3**: Record or update the result for a participant in a specific event.
   * **4**: Display all events and participant information.
   * **5**: Save events and participants to a file.
   * **6**: Load and display event data from a file.
   * **7**: Exit the application.

3. Follow the on-screen prompts for input.

---

## Data Structures

```c
typedef struct data {
    char nom[50];
    char prenom[50];
    int Age;
    char sport[66];
    int result;
} data;

typedef struct listp {
    data particpant;
    struct listp *next;
    struct listp *prev;
} listp;

typedef struct Date {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct data_event {
    char nom_ev[50];
    Date date;
    char Type_spr[66];
    listp *list_paricipant;
} data_event;

typedef struct list_ev {
    data_event evenement;
    struct list_ev *next;
    struct list_ev *prev;
} list_ev;
```

---

## Example Saved Event Output Format

```
------------------------Les informations de l'evenement 1 :-----------------------
 Nom de l'evenement  : Football Cup
 Date de l'evenement  (JJ/MM/AA): 15/07/2025
 Type de sport  : Football

 *************** les informations des participants de l'evenement 1 : *************
 -->les informations de participant  1 :
 Nom : Smith
 Prenom : John
 Age : 23
 Sport : Football
 Resultat : 2
--------------------------------------------------------------------------------
```

---

## Highlights & Learning Outcomes

* Modular design using header files
* Use of doubly-linked lists for flexible data storage
* File handling: reading/writing structured data
* String and structure manipulation
* Menu-driven user interface
* Dynamic participant-event association

---

## Limitations & Future Improvements

* Add input validation (e.g., age must be positive, unique names).
* Search, filter, or sort participants/events.
* Export/import in CSV or JSON format.
* Improve error messages and interaction UX.
* Create a GUI or web-based front end.

---

## Author

*Amine El Harrab*

---

