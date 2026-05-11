# Student Management System


#  Group Members

| Name | ID |
| :--- | :--- |
| Mona Walid | 2300446 |
| Nour Mohammed | 2300780 |
| Hamsa Tarek | 2300634 |
| Farah Zayed | 2300418 |
| Sohila Samir | 2300117 |

---

# Project Description
This Student Management System is a C++ application built with the Qt Framework designed to streamline academic record-keeping. 

It allows administrators to manage student registrations, track course performance across four academic levels, and calculate real-time GPAs. 

The system features a graphical user interface (GUI) to handle complex operations like grade updates, student deletions, and subject performance analytics.

---

# Data Structures Used

To ensure efficiency and logical organization, the following data structures were implemented:

### 1. `map<string, Student>` (Main Storage)
* **Why:** Used for the primary student database. It provides $O(\log n)$ search, insertion, and deletion time based on the unique Student ID, ensuring quick lookups during updates.

### 2. `map<string, courseDetails>` (Student Records)
* **Why:** Maps course names to their specific grade components. This allows for flexible grade updates without iterating through a list.

### 3. `list<string>` (System/Student History)
* **Why:** Used for logging system actions and student grade history. A list is ideal for frequent "push-back" operations where we only need to keep a chronological sequence of events.

### 4. `vector<CourseInfo>`
* **Why:** Used within the static levels map to store a fixed list of courses per level. Vectors provide fast contiguous memory access for iterating through curriculum requirements.

---

#  Implemented Features

* Student Registration:  Add new students with a name, unique ID, and starting academic level.
*  Grade Management: Update specific components (**Midterm, Final, Activities**) for courses assigned to the student's current level.
*  Automatic Promotion:  Students are automatically promoted to the next level upon completing **12 credit hours** in their current level.
*  Academic Reporting:  Generate formatted **HTML reports** showing a student's GPA and a detailed breakdown of all courses.
*  System Statistics:  Calculate the average grade (letter grade) for any specific subject across the entire student body.
*  Data Persistence (Session):  Uses a centralized storage manager to handle student data during the application runtime.
*  Search & Delete: Efficiently find student records by **ID** and remove them from the system.

---
# AI Usage Declaration

During the development of this project, AI (Gemini/ChatGPT) was utilized for:
* **Logic Refinement:** Fine-tuning the algorithms for **GPA rounding** and **level promotion** criteria.

* **Data Structure Selection:** Assisting in the architectural choice of using `std::map` for efficient student lookups and `std::list` for maintaining a sequential system log.
* **Error Handling & Validation:** Implementing robust checks to verify student existence before performing deletion or grade update operations to prevent runtime errors.
* **UI/UX Formatting:** Enhancing the visual presentation of data within `QTableWidget` and managing layouts to ensure the interface remains responsive and organized.

---
##  How to Compile and Run

###  Prerequisites
* **Qt Creator** (Recommended) or **Qt Framework** (6.x or higher).
* **C++17 Compiler** (GCC, Clang, or MSVC).

### Steps to Run
1. **Open the Project:**
   * Launch **Qt Creator**.
   * Open the `StudentManagementSystem.pro` file (or `CMakeLists.txt` if using CMake).

2. **Configure Project:**
   * Select your installed Kit (e.g., Desktop Qt 6.x.x MinGW/MSVC).

3. **Build:**
   * Click the **Hammer icon** (Build)

4. **Run:**
   * Click the **Green Play button** (Run)
  
