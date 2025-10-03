#include "BimonthlyExam.h"
#include <algorithm>

// Default constructor
BimonthlyExam::BimonthlyExam() : num_questions(0), grade(0.0f), subject("") {
}

// Parameterized constructor
BimonthlyExam::BimonthlyExam(int num_q, std::vector<std::string> questions, 
                             float grade, std::string subject) 
    : num_questions(num_q), questions(questions), grade(grade), subject(subject) {
    
    // Clamp grade between 0 and 100
    if (this->grade < 0.0f) this->grade = 0.0f;
    if (this->grade > 100.0f) this->grade = 100.0f;
}

// Copy constructor
BimonthlyExam::BimonthlyExam(const BimonthlyExam &other) 
    : num_questions(other.num_questions), questions(other.questions), 
      grade(other.grade), subject(other.subject) {
}

// Destructor
BimonthlyExam::~BimonthlyExam() {
}

// Assignment operator
BimonthlyExam& BimonthlyExam::operator=(const BimonthlyExam& other) {
    if (this != &other) {
        num_questions = other.num_questions;
        questions = other.questions;
        grade = other.grade;
        subject = other.subject;
    }
    return *this;
}

// Getters
int BimonthlyExam::getNumQuestions() const {
    return num_questions;
}

std::string BimonthlyExam::getQuestion(int index) const {
    if (index >= 0 && index < static_cast<int>(questions.size())) {
        return questions[index];
    }
    return "";
}

float BimonthlyExam::getGrade() const {
    return grade;
}

std::string BimonthlyExam::getSubject() const {
    return subject;
}

// Setters
void BimonthlyExam::setGrade(float new_grade) {
    grade = new_grade;
    // Clamp grade between 0 and 100
    if (grade < 0.0f) grade = 0.0f;
    if (grade > 100.0f) grade = 100.0f;
}

void BimonthlyExam::setSubject(const std::string& new_subject) {
    subject = new_subject;
}

void BimonthlyExam::addQuestion(const std::string& question) {
    questions.push_back(question);
    num_questions = questions.size();
}

// Comparison operators (for sorting by grade)
bool BimonthlyExam::operator<(const BimonthlyExam &other) const {
    return grade < other.grade;
}

bool BimonthlyExam::operator>(const BimonthlyExam &other) const {
    return grade > other.grade;
}

bool BimonthlyExam::operator==(const BimonthlyExam &other) const {
    return (grade == other.grade && subject == other.subject);
}

// Utility methods
bool BimonthlyExam::hasPassingGrade() const {
    return grade >= 60.0f;
}

void BimonthlyExam::displayInfo() const {
    std::cout << "Subject: " << subject << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    std::cout << "Number of questions: " << num_questions << std::endl;
    std::cout << "Status: " << (hasPassingGrade() ? "PASSED" : "FAILED") << std::endl;
}

// Stream operators
std::ostream& operator<<(std::ostream &out, const BimonthlyExam &exam) {
    out << "Exam - Subject: " << exam.subject 
        << ", Grade: " << exam.grade 
        << ", Questions: " << exam.num_questions;
    return out;
}

std::istream& operator>>(std::istream &in, BimonthlyExam &exam) {
    std::cout << "Enter subject: ";
    std::getline(in, exam.subject);
    
    std::cout << "Enter grade (0-100): ";
    in >> exam.grade;
    
    std::cout << "Enter number of questions: ";
    in >> exam.num_questions;
    
    in.ignore(); // Clear the newline
    
    exam.questions.clear();
    for (int i = 0; i < exam.num_questions; ++i) {
        std::string question;
        std::cout << "Enter question " << (i + 1) << ": ";
        std::getline(in, question);
        exam.questions.push_back(question);
    }
    
    return in;
}