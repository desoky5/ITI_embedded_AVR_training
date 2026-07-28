# Clinic Management System (C)

A console-based Clinic Management System written in C as part of the **ITI AVR Embedded Systems Diploma**. The project models a small real-world workflow — patient records and doctor appointment slots — entirely from scratch using manual memory management and singly linked lists, with no external libraries beyond the standard C library.

---

## 1. Project Overview

The system supports two operating modes, selected at runtime:

| Mode  | Access              | Capabilities                                                                 |
|-------|---------------------|-------------------------------------------------------------------------------|
| Admin | Password-protected (3 attempts, default `1234`) | Add patient record, edit patient record, view reservations, reserve a slot, cancel a reservation |
| User  | Open access          | Search a patient by ID, view today's reservations                            |

Both modes operate on the **same in-memory data structures** for the duration of a single program run, so a patient added in Admin mode is immediately visible to a User-mode search — no separate storage or synchronization step is needed.

---

## 2. Core C Programming Concepts Demonstrated

This project intentionally exercises the foundational building blocks of C beyond "hello world" level:

- **Structs & self-referential structs** — `records` and `Reservations` each contain a pointer to their own type (`struct node_records *next`), which is what makes a linked list possible in C.
- **Pointers & pointer arithmetic** — traversal (`current = current->next`), pass-by-reference for functions that mutate the list (`records *Head`), and the classic "trailing pointer" (`previous`/`last`) pattern used for insertion and deletion.
- **Dynamic memory management** — `malloc()` for creating new nodes on the heap at runtime (since the number of patients/reservations isn't known in advance), paired with `free()` for deallocation, and `NULL` checks to guard against allocation failure.
- **Arrays & fixed-size buffers** — `char Name[50]`, `char gender[20]`, and `char password[20]` model fixed-capacity string storage, typical of embedded/resource-constrained environments.
- **String handling** — `strcpy()` for copying into struct fields and `strcmp()` for password validation, both from `<string.h>`.
- **Control flow** — nested `switch` statements for menu routing, and `while` loops (both bounded, like the 3-trial password check, and unbounded with an internal exit flag, like the feature menus).
- **Modular design** — logic is decomposed into single-responsibility functions (`Add_patient_record`, `search_patient_record_by_id`, `Edit_patient_record`, etc.) declared via forward prototypes and implemented separately from `main()`.
- **Custom typedefs** — project-specific fixed-width types (`u8`) from a shared `STD_TYPES.h` header, a convention carried over from embedded/AVR firmware work for portability and clarity about data width.

---

## 3. Data Structures Used

### 3.1 Singly Linked List (with dummy head node)

Both patient records and appointment reservations are stored as **singly linked lists**, each anchored by a **dummy head node** — an allocated node that is never itself a real record but always exists, so that insertion/deletion logic never has to special-case "the list is empty."

```
Head (dummy) -> [Patient A] -> [Patient B] -> [Patient C] -> NULL
```

**Why a linked list here (and not an array)?**
- The number of patients/reservations is unknown ahead of time and grows dynamically — a linked list avoids pre-allocating a fixed-size array or dealing with resizing.
- Insertion at the tail and deletion of an arbitrary node are both `O(1)` *once the correct position is found*, without shifting other elements (unlike an array).
- It mirrors how dynamic collections are handled in memory-constrained embedded contexts, where the standard library's dynamic containers (e.g. C++ `std::vector`) aren't available.

### 3.2 Node structures

```c
typedef struct node_records {
    u8 ID;
    u8 Age;
    u8 gender[20];
    u8 Name[50];
    struct node_records *next;
} records;

typedef struct node_reservations {
    u8 Name[50];
    u8 slot;
    u8 ID;
    struct node_reservations *next;
} Reservations;
```

---

## 4. Algorithms Implemented

| Operation                     | Function                        | Technique                                                    | Time Complexity |
|--------------------------------|----------------------------------|----------------------------------------------------------------|------------------|
| Insert (tail, with uniqueness check) | `Add_patient_record`         | Linear scan to check for duplicate ID, then append at tail using a trailing pointer | O(n) |
| Insert (tail, with slot-conflict check) | `Add_new_reservation`     | Linear scan to check if a slot is already booked, then append  | O(n) |
| Search by key                  | `search_patient_record_by_id`   | Linear search, early return on match                          | O(n) |
| Update (search + mutate)       | `Edit_patient_record`           | Linear search followed by in-place field update                | O(n) |
| Delete by key (general node)   | `remove_by_slot_no`             | Linear search with a `previous`/`current` pointer pair to unlink the target node safely, then `free()` | O(n) |
| Full traversal / display       | `show_record`, `show_reservations` | Iterate from `Head->next` to `NULL`, printing each node       | O(n) |
| Bounded-retry authentication    | Password check in `main()`      | Loop with a trial counter compared against `MAX_TRIALS`, using `strcmp` for validation | O(1) per attempt |

**Design note on deletion:** node removal always follows the same safe three-step pattern to avoid dangling pointers and use-after-free bugs:
1. Locate the target node while keeping a pointer to its **predecessor**.
2. Re-link the predecessor's `next` to skip over the target (`previous->next = current->next`).
3. Only then call `free(current)` — never dereference a node after it has been freed.

---

## 5. Program Flow

```
main()
 └─ while(1)                         // outer session loop
     ├─ prompt: Admin (0) / User (1) / Exit (2)
     ├─ [Admin] password gate (max 3 trials) → feature menu loop
     │        1. Add patient record
     │        2. Edit patient record
     │        3. Show today's reservations
     │        4. Reserve a slot
     │        5. Cancel a reservation
     │        0. Back to main menu
     └─ [User] feature menu loop
              1. View today's reservations
              2. Search patient record by ID
              0. Back to main menu
```

Because the outer loop persists for the whole program lifetime and both modes share the same `Head` / `Head_res` pointers, switching between Admin and User mode multiple times in one run preserves all data — nothing is reset between mode switches.

---

## 6. Project Structure

```
├── src/
│   └── main.c              # Application logic, menus, linked-list operations
├── inc/
│   └── STD_TYPES.h         # Fixed-width type definitions (u8, etc.)
└── README.md
```

---

## Author

**Omar Desoky** Mechatronics & Robotics Engineering — Egypt-Japan University of Science and Technology (E-JUST)

[![GitHub](https://img.shields.io/badge/GitHub-desoky5-181717?style=flat&logo=github&logoColor=white)](https://github.com/desoky5)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0A66C2?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/desoky5)

---

## License

This project is open source. See [LICENSE](LICENSE) for details.