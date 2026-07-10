#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Function to convert letter grade to grade point
double getGradePoint(string grade) {
    if (grade == "O" || grade == "A+") return 10.0;
    else if (grade == "A") return 9.0;
    else if (grade == "B+") return 8.0;
    else if (grade == "B") return 7.0;
    else if (grade == "C") return 6.0;
    else if (grade == "P") return 5.0;
    else return 0.0; // RA / F / Invalid
}

int main() {
    int n;
    cout << "========== CGPA CALCULATOR ==========\n";
    cout << "Enter the number of courses: ";
    cin >> n;

    vector<string> grades(n);
    vector<int> credits(n);

    double totalCredits = 0;
    double totalGradePoints = 0;

    cout << "\nEnter course details:\n";

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Grade (O, A+, A, B+, B, C, P, F): ";
        cin >> grades[i];

        cout << "Credit Hours: ";
        cin >> credits[i];

        double gp = getGradePoint(grades[i]);

        totalCredits += credits[i];
        totalGradePoints += gp * credits[i];
    }

    double sgpa = totalGradePoints / totalCredits;

    cout << "\n=====================================\n";
    cout << "Course Details\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i] << endl;
    }

    cout << "\nTotal Credits      : " << totalCredits;
    cout << "\nTotal Grade Points : " << totalGradePoints;
    cout << "\nSemester GPA (SGPA): " << fixed << setprecision(2) << sgpa;

    // Overall CGPA
    char choice;
    cout << "\n\nDo you have previous semesters? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        double previousCredits, previousGradePoints;

        cout << "Enter Total Previous Credits: ";
        cin >> previousCredits;

        cout << "Enter Total Previous Grade Points: ";
        cin >> previousGradePoints;

        double overallCGPA = (previousGradePoints + totalGradePoints) /
                             (previousCredits + totalCredits);

        cout << "\nOverall CGPA: " << fixed << setprecision(2)
             << overallCGPA << endl;
    } else {
        cout << "\nOverall CGPA: " << fixed << setprecision(2)
             << sgpa << endl;
    }

    cout << "=====================================\n";

    return 0;
}