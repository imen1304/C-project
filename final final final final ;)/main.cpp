#include <iostream>
#include <windows.h>
#include "./include/Personne.h"
#include "./include/Etudiant.h"
#include "./include/Enseignant.h"
#include "./include/Matiere.h"
#include "./include/GroupeModule.h"
#include "./include/Groupe.h"
#include "./include/Note.h"
#include "./include/Functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <dos.h>
#include <windows.h>

int main() {
    int choix;
    bool quitter = false;

    while (!quitter) {
        displayMainMenu();
        std::cout << "Choisir une option : ";
        std::cin >> choix;

        switch (choix) {
            case 1:
                while (true) {
                    displayEtudiantMenu();
                    std::cout << "Choisir une option : ";
                    std::cin >> choix;
                    switch (choix) {
                        case 1:
                            addStudent();
                            break;
                        case 2:
                            displayStudents();
                            break;
                        case 3:
                            updateStudent();
                            break;
                        case 4:
                            deleteStudent();
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                    }
                    if (choix == 5) {
                        break;
                    }
                    std::cout << "Appuyez sur entrée pour continuer...";
                    std::cin.ignore(); 
                    std::cin.get(); 
                }
                break;
            case 2:
                std::cout << "Gestion Enseignant" << std::endl;
                while (true) {
                    displayEnseignantMenu();
                    std::cout << "Choisir une option : ";
                    std::cin >> choix;
                    switch (choix) {
                        case 1:
                            addTeacher();
                            break;
                        case 2:
                            displayTeachers();
                            break;
                        case 3:
                            updateTeacher();
                            break;
                        case 4:
                            deleteTeacher();
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                    }
                    if (choix == 5) {
                        break;
                    }
                    std::cout << "Appuyez sur entrée pour continuer...";
                    std::cin.ignore(); 
                    std::cin.get(); 
                }
                break;
            case 3:
                std::cout << "Gestion Matière" << std::endl;
                while (true) {
                    displayMatiereMenu();
                    std::cout << "Choisir une option : ";
                    std::cin >> choix;
                    switch (choix) {
                        case 1:
                            addMatiere();
                            break;
                        case 2:
                            displayMatieres();
                            break;
                        case 3:
                            updateMatiere();
                            break;
                        case 4:
                            deleteMatiere();
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                    }
                    if (choix == 5) {
                        break;
                    }
                    std::cout << "Appuyez sur entrée pour continuer...";
                    std::cin.ignore(); 
                    std::cin.get(); 
                }

                break;
            case 4:
                std::cout << "Gestion Groupe de     Module" << std::endl;
                while (true) {
                    displayGroupeModuleMenu();
                    std::cout << "Choisir une option : ";
                    std::cin >> choix;
                    switch (choix) {
                        case 1:
                            addGroupeModule();
                            break;
                        case 2:
                            displayGroupeModules();
                            break;
                        case 3:
                            updateGroupeModule();
                            break;
                        case 4:
                            deleteGroupeModule();
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                    }

                    if (choix == 5) {
                        break;
                    }
                    std::cout << "Appuyez sur entrée pour continuer...";
                    std::cin.ignore(); 
                    std::cin.get(); 
                }
                break;
            case 5:
                std::cout << "Gestion Groupe" << std::endl;
                while (true) {
                    displayGroupeMenu();
                    std::cout << "Choisir une option : ";
                    std::cin >> choix;
                    switch (choix) {
                        case 1:
                            addGroupe();
                            break;
                        case 2:
                            displayGroupes();
                            break;
                        case 3:
                            updateGroupe();
                            break;
                        case 4:
                            deleteGroupe();
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                    }
                    if (choix == 5) {
                        break;
                    }
                    std::cout << "Appuyez sur entrée pour continuer...";
                    std::cin.ignore(); 
                    std::cin.get(); 
                }
                break;
            case 6:
                std::cout << "Gestion Note" << std::endl;
                while (true) {
                    displayNoteMenu();
                    std::cout << "Choisir une option : ";
                    std::cin >> choix;
                    switch (choix) {
                        case 1:
                            addNote();
                            break;
                        case 2:
                            displayNote();
                            break;
                        case 3:
                            updateNote();
                            break;
                        case 4:
                            deleteNote();
                            break;
                        case 5:
                            break;
                        default:
                            std::cout << "Option invalide. Veuillez réessayer." << std::endl;
                    }
                    if (choix == 5) {
                        break;
                    }
                    std::cout << "Appuyez sur entrée pour continuer...";
                    std::cin.ignore(); 
                    std::cin.get(); 
                }
                break;
            case 7:
                std::cout << "Gestion PV Groupe" << std::endl;
                displayPVGroupe();

                break;
            case 8:
                std::cout << "Quitter le programme..." << std::endl;
                quitter = true;
                break;
            default:
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
        }
        if (!quitter) {
            std::cout << "Appuyez sur entrée pour continuer...";
            std::cin.ignore(); 
            std::cin.get(); 
        }
    }

    return 0;
}