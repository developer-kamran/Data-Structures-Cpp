#include <iostream>
using namespace std;

struct StudentNode {
    int studentID;
    StudentNode* nextStudent;
};

struct CourseNode {
    int courseID;
    CourseNode* nextCourse;
    StudentNode* enrolledStudents;
};

void insertCourse(CourseNode** courseHead, int courseID) {
    CourseNode* newNode = new CourseNode;
    newNode->courseID = courseID;
    newNode->nextCourse = NULL;
    newNode->enrolledStudents = NULL;
    if (*courseHead == NULL) {
        *courseHead = newNode;
    } else {
        CourseNode* temp = *courseHead;
        while (temp->nextCourse != NULL) {
            temp = temp->nextCourse;
        }
        temp->nextCourse = newNode;
    }
}

void printCourses(CourseNode* courseHead) {
    if (courseHead == NULL) {
        cout << "Course list is empty.\n";
        return;
    }

    cout << "Courses:\n";
    CourseNode* temp = courseHead;
    while (temp != NULL) {
        cout << "Course ID: " << temp->courseID << endl;
        temp = temp->nextCourse;
    }
}

CourseNode* searchCourse(CourseNode* courseHead, int courseID) {
    CourseNode* current = courseHead;
    while (current != NULL && current->courseID != courseID) {
        current = current->nextCourse;
    }
    return current;
}

bool deleteCourse(CourseNode** courseHead, int courseID) {
    if (*courseHead == NULL) {
        cout << "Course list is empty. Cannot delete.\n";
        return false;
    }

    CourseNode* current = *courseHead;
    CourseNode* previous = NULL;

    while (current != NULL && current->courseID != courseID) {
        previous = current;
        current = current->nextCourse;
    }

    if (current != NULL && current->courseID == courseID) {
        StudentNode* enrolledStudent = current->enrolledStudents;
        while (enrolledStudent != NULL) {
            StudentNode* temp = enrolledStudent;
            enrolledStudent = enrolledStudent->nextStudent;
            delete temp;
        }
        current->enrolledStudents = NULL;

        if (previous == NULL) {
            *courseHead = current->nextCourse;
        } else {
            previous->nextCourse = current->nextCourse;
        }
        delete current;
        cout << "Course with ID " << courseID << " has been deleted.\n";
        return true;
    } else {
        cout << "Course with ID " << courseID << " not found.\n";
        return false;
    }
}

void insertStudent(CourseNode* courseHead, int courseID, int studentID) {
    CourseNode* current = courseHead;
    while (current != NULL && current->courseID != courseID) {
        current = current->nextCourse;
    }

    if (current != NULL && current->courseID == courseID) {
        StudentNode* newStudent = new StudentNode;
        newStudent->studentID = studentID;
        newStudent->nextStudent = current->enrolledStudents;
        current->enrolledStudents = newStudent;
        cout << "Student with ID " << studentID << " enrolled in course " << courseID << endl;
    } else {
        cout << "Course with ID " << courseID << " not found. Cannot enroll student.\n";
    }
}

void printEnrolledStudents(CourseNode* courseHead, int courseID) {
    CourseNode* current = courseHead;
    while (current != NULL && current->courseID != courseID) {
        current = current->nextCourse;
    }

    if (current != NULL && current->courseID == courseID) {
        cout << "Enrolled students in course " << courseID << ":\n";
        StudentNode* enrolledStudent = current->enrolledStudents;
        while (enrolledStudent != NULL) {
            cout << "Student ID: " << enrolledStudent->studentID << endl;
            enrolledStudent = enrolledStudent->nextStudent;
        }
    } else {
        cout << "Course with ID " << courseID << " not found.\n";
    }
}

StudentNode* searchStudent(CourseNode* courseHead, int courseID, int studentID) {
    CourseNode* course = searchCourse(courseHead, courseID);
    if (course != NULL) {
        StudentNode* enrolledStudent = course->enrolledStudents;
        while (enrolledStudent != NULL && enrolledStudent->studentID != studentID) {
            enrolledStudent = enrolledStudent->nextStudent;
        }
        return enrolledStudent;
    }
    return NULL;
}

bool deleteStudent(CourseNode* courseHead, int courseID, int studentID) {
    CourseNode* course = searchCourse(courseHead, courseID);
    if (course != NULL) {
        StudentNode* current = course->enrolledStudents;
        StudentNode* previous = NULL;

        while (current != NULL && current->studentID != studentID) {
            previous = current;
            current = current->nextStudent;
        }

        if (current != NULL && current->studentID == studentID) {
            if (previous == NULL) {
                course->enrolledStudents = current->nextStudent;
            } else {
                previous->nextStudent = current->nextStudent;
            }
            delete current;
            cout << "Student with ID " << studentID << " deleted from course " << courseID << endl;
            return true;
        } else {
            cout << "Student with ID " << studentID << " not found in course " << courseID << endl;
            return false;
        }
    } else {
        cout << "Course with ID " << courseID << " not found.\n";
        return false;
    }
}

int main() {
    CourseNode* courseHead = NULL;

    int choice, courseID, studentID;

    while (true) {
        cout << "\n1. Insert course\n";
        cout << "2. Display courses\n";
        cout << "3. Search course\n";
        cout << "4. Delete course\n";
        cout << "5. Insert student into course\n";
        cout << "6. Display enrolled students in course\n";
        cout << "7. Search student\n";
        cout << "8. Delete student from course\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter course ID: ";
                cin >> courseID;
                insertCourse(&courseHead, courseID);
                break;
            case 2:
                printCourses(courseHead);
                break;
            case 3:
                cout << "Enter course ID to search: ";
                cin >> courseID;
                if (searchCourse(courseHead, courseID) != NULL) {
                    cout << "Course found.\n";
                } else {
                    cout << "Course not found.\n";
                }
                break;
            case 4:
                cout << "Enter course ID to delete: ";
                cin >> courseID;
                deleteCourse(&courseHead, courseID);
                break;
            case 5:
                cout << "Enter course ID: ";
                cin >> courseID;
                cout << "Enter student ID: ";
                cin >> studentID;
                insertStudent(courseHead, courseID, studentID);
                break;
            case 6:
                cout << "Enter course ID: ";
                cin >> courseID;
                printEnrolledStudents(courseHead, courseID);
                break;
            case 7:
			    cout << "Enter course ID: ";
                cin >> courseID;
                cout << "Enter student ID to search: ";
                cin >> studentID;
                if (searchStudent(courseHead, courseID, studentID) != NULL) {
                    cout << "Student found.\n";
                } else {
                    cout << "Student not found.\n";
                }
                break;
            case 8:
                cout << "Enter course ID: ";
                cin >> courseID;
                cout << "Enter student ID to delete: ";
                cin >> studentID;
                deleteStudent(courseHead, courseID, studentID);
                break;
            case 9:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

