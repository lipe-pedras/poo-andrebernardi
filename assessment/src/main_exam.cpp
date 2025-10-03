#include <iostream>
#include <vector>
#include <algorithm>
#include "BimonthlyExam.h"

using namespace std;

int main() {
    cout << "=== BimonthlyExam Demonstration ===" << endl;
    
    // Create some sample exams
    vector<string> math_questions = {
        "What is the derivative of x^2?",
        "Solve: 2x + 3 = 7",
        "What is the integral of 2x?"
    };
    
    vector<string> physics_questions = {
        "What is Newton's second law?",
        "Calculate: F = ma when m=5kg and a=2m/s^2"
    };
    
    BimonthlyExam math_exam(3, math_questions, 85.5f, "Mathematics");
    BimonthlyExam physics_exam(2, physics_questions, 72.0f, "Physics");
    BimonthlyExam chemistry_exam(1, {"What is H2O?"}, 95.0f, "Chemistry");
    
    // Display exam information
    cout << "Created exams:" << endl;
    cout << "1. " << math_exam << endl;
    cout << "2. " << physics_exam << endl;
    cout << "3. " << chemistry_exam << endl;
    
    // Test individual exam methods
    cout << "\nMath exam details:" << endl;
    math_exam.displayInfo();
    
    cout << "\nQuestions in math exam:" << endl;
    for (int i = 0; i < math_exam.getNumQuestions(); ++i) {
        cout << (i + 1) << ". " << math_exam.getQuestion(i) << endl;
    }
    
    // Test comparison operators
    cout << "\nComparison tests:" << endl;
    cout << "Math exam grade > Physics exam grade: " 
         << (math_exam > physics_exam ? "Yes" : "No") << endl;
    cout << "Chemistry exam grade > Math exam grade: " 
         << (chemistry_exam > math_exam ? "Yes" : "No") << endl;
    
    // Test passing grade
    cout << "\nPassing grade tests (60% threshold):" << endl;
    cout << "Math exam passed: " << (math_exam.hasPassingGrade() ? "Yes" : "No") << endl;
    cout << "Physics exam passed: " << (physics_exam.hasPassingGrade() ? "Yes" : "No") << endl;
    cout << "Chemistry exam passed: " << (chemistry_exam.hasPassingGrade() ? "Yes" : "No") << endl;
    
    // Test sorting
    vector<BimonthlyExam> all_exams = {math_exam, physics_exam, chemistry_exam};
    
    cout << "\nBefore sorting by grade:" << endl;
    for (size_t i = 0; i < all_exams.size(); ++i) {
        cout << (i + 1) << ". " << all_exams[i] << endl;
    }
    
    sort(all_exams.begin(), all_exams.end()); // Sort by grade (ascending)
    
    cout << "\nAfter sorting by grade (ascending):" << endl;
    for (size_t i = 0; i < all_exams.size(); ++i) {
        cout << (i + 1) << ". " << all_exams[i] << endl;
    }
    
    // Create exam from user input
    cout << "\nCreate your own exam:" << endl;
    BimonthlyExam user_exam;
    cin >> user_exam;
    
    cout << "\nYour exam:" << endl;
    user_exam.displayInfo();
    
    return 0;
}