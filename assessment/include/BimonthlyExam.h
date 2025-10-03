#ifndef BIMONTHLYEXAM_H
#define BIMONTHLYEXAM_H

#include <iostream>
#include <vector>
#include <string>

class BimonthlyExam
{
private:
    int num_questions;                    // Number of questions
    std::vector<std::string> questions;   // List of questions
    float grade;                          // Student's grade
    std::string subject;                  // Subject name

public:
    BimonthlyExam();                                                        // Default constructor
    BimonthlyExam(int num_q, std::vector<std::string> questions, 
                  float grade, std::string subject);                        // Parameterized constructor
    BimonthlyExam(const BimonthlyExam &other);                             // Copy constructor
    ~BimonthlyExam();                                                      // Destructor

    // Assignment operator
    BimonthlyExam& operator=(const BimonthlyExam& other);

    // Getters
    int getNumQuestions() const;
    std::string getQuestion(int index) const;
    float getGrade() const;
    std::string getSubject() const;

    // Setters
    void setGrade(float new_grade);
    void setSubject(const std::string& new_subject);
    void addQuestion(const std::string& question);

    // Comparison operators (for sorting by grade)
    bool operator<(const BimonthlyExam &other) const;
    bool operator>(const BimonthlyExam &other) const;
    bool operator==(const BimonthlyExam &other) const;

    // Utility methods
    bool hasPassingGrade() const;
    void displayInfo() const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream &out, const BimonthlyExam &exam);
    friend std::istream& operator>>(std::istream &in, BimonthlyExam &exam);
};

#endif