/**
* This file creates a new data structure named _student and it has 5 parameters.
* Three parameters are char, one is double pointer and last one is an integer.
* The _student data type will make it more easy to store the information of each student.
*/

typedef struct _student 
{ 
  char first_name[50]; /**< First name of a student with a length limit of 50. */
  char last_name[50]; /**< Last name of a student with a length limit of 50. */
  char id[11]; /**< The student number and it is at most 11 digits. */
  double *grades;  /**< The mark taht the student got. And it's a pointer. */
  int num_grades; /**<  Which grade that the student in. */
} Student;

void add_grade(Student *student, double grade);
/**
* @brief Function to give the grade to a student.
* @param student The data type defined above, which contains information of one student object.
* @param grade The mark that the student got.
* @return It returns nothing, void.
*/

double average(Student *student);
/**
* @brief Function to calculate the average of one student.
* @param student The data type defined above, which contains information of one student object.
* @return It returns the average grade which is double type.
*/

void print_student(Student *student);
/**
* @brief Function to show the all information of one student. The name, ID, grade and average grade.
* @param student The data type defined above, which contains information of one student object.
* @return It returns nothing, void.
*/

Student* generate_random_student(int grades); 
/**
* @brief Function to create a student with random name, ID and other informations.
* @param grades The mark that the student got.
* @return It returns a new student type data.
*/