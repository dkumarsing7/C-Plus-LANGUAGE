#include<iostream>
using namespace std;

// **Task:**
// 1.  Create a class named `Student`.
// 2.  The class should have the following members:
//     *   A `name` (string).
//     *   A dynamically allocated integer pointer `grades`.
//     *   An integer `numGrades` to store the number of grades.
// 3.  Implement a **parameterized constructor** that takes a name and an array of grades. It should perform a **deep copy** of the grades into its dynamically allocated `grades` array.
// 4.  Implement a **deep copy constructor**. When a `Student` object is copied, the new object should have its own separate memory for grades, not just a copy of the pointer.
// 5.  Implement a **destructor** (`~Student()`) that frees the dynamically allocated memory for `grades` to prevent memory leaks.
// 6.  Implement a `display()` method to print the student's name and all their grades.
// 7.  In `main()`:
//     *   Create an initial array of grades.
//     *   Create a `Student` object, `student1`, using the parameterized constructor.
//     *   Create a second `Student` object, `student2`, by copying `student1`.
//     *   Modify one of the grades for `student2`.
//     *   Display the details for both `student1` and `student2` to prove that changing `student2` did **not** affect `student1` (demonstrating a successful deep copy).

// **Example Output:**
// Student 1 Details:
// Name: Alice
// Grades: 85 92 78
// Student 2 Details:
// Name: Alice
// Grades: 85 92 78
// --- After modifying student2's first grade ---
// Student 1 Details:
// Name: Alice
// Grades: 85 92 78
// Student 2 Details:
// Name: Alice
// Grades: 99 92 78