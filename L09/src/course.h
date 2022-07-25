#include "student.h"
#include <stdbool.h>

/**
* This file creates a new data structure named _coure and it has 4 parameters.
* Two parameters are char, one is a new data type which is created from another file student.h, and one int data.
* The _course data type will make it more easy to store the information of each class.
*/
 
typedef struct _course 
{
  char name[100]; /**< This represents the name of student, which has a length limit 100. */
  char code[10]; /**< This will record the course code which has a length limit 10. */
  Student *students; /**< This is a new data stucture defined in student.h, for more specific details need to check the corresponding file. */
  int total_students; /**< This number means the number of students. */
} Course;

void enroll_student(Course *course, Student *student);
/**
* @brief Function to add the student to the course data. 
* @param course The data type defined above, which contains information of one course object.
* @param student The data type defined in student.h, which contains information of one student object.
* @return It returns nothing. Void.
* @note We use this to enroll students.
*/

void print_course(Course *course);
/**
* @brief Function to show the information of a course, like code, name and number of students. And it will also show all students.
* @param course The data type defined above, which contains information of one course object.
* @return It returns nothing. Void.
* @note We use this to check the details of a course data.
*/

Student *top_student(Course* course);
/**
* @brief Function to show the student who has the highest grade.
* @param course The data type defined above, which contains information of one course object.
* @return It returns student data type.
* @note We use this to quikly check the top student.
*/

Student *passing(Course* course, int *total_passing);
/**
* @brief Function to show the students who passed.
* @param course The data type defined above, which contains information of one course object.
* @param total_passing The integer number which means how many students passed.
* @return It returns passing which is the student data type.
* @note We use this to check all students who passed.
*/
