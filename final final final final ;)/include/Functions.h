
#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <string>
int countLines(const std::string& filename) ; 

void displayMainMenu();


void displayEtudiantMenu();
void addStudent();
void displayStudents();
void updateStudent();
void deleteStudent();

void displayEnseignantMenu();
void addTeacher();
void displayTeachers();
void updateTeacher();
void deleteTeacher();


void displayMatiereMenu();
void addMatiere();
void displayMatieres();
void updateMatiere();
void deleteMatiere();



void displayGroupeMenu();
void addGroupe();
void displayGroupes();
void updateGroupe();
void deleteGroupe();


void displayGroupeModuleMenu();

void addGroupeModule();
void displayGroupeModules();
void updateGroupeModule();
void deleteGroupeModule();




void displayNoteMenu();
void addNote();
void displayNote();
void updateNote();
void deleteNote();



void displayPVGroupe();



#endif 