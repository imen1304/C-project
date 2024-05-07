#include <iostream>
#include <string>
#include "../include/functions.h"
#include <cstdlib> 
#include <sstream> 
#include <fstream>
#include <iostream>
#include <iomanip>

#include "../include/Etudiant.h"
#include "../include/Enseignant.h"
#include "../include/Matiere.h"
#include "../include/GroupeModule.h"
#include "../include/Groupe.h"
#include "../include/Note.h"
#include "../include/table.h"

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int countLines(const std::string& filename) {
    std::ifstream file(filename);  // Open the file with the given filename
    if (!file.is_open()) {  // Check if the file was successfully opened
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return -1; 
    }
       // If the file was opened successfully, initialize a counter for lines to 0
    int lineCount = 0;
    std::string line;
    while (std::getline(file, line)) {  // Read each line of the file one by one until the end of the file is reached
        lineCount++;
    }
    // Close the file once all lines have been read
    file.close();
    return lineCount;
}
void displayMainMenu() {
    clearScreen();
    std::cout << "1. Gestion Etudiant" << std::endl;
    std::cout << "2. Gestion Enseignant" << std::endl;
    std::cout << "3. Gestion Matière" << std::endl;
    std::cout << "4. Gestion Groupe de Module" << std::endl;
    std::cout << "5. Gestion Groupe" << std::endl;
    std::cout << "6. Gestion Note" << std::endl;
    std::cout << "7. PV" << std::endl;
    std::cout << "8. Quitter" << std::endl;

}

void displayEtudiantMenu() {
    clearScreen();
    std::cout << "===== Gestion Etudiant =====" << std::endl;
    std::cout << "1. Ajouter Etudiant" << std::endl;
    std::cout << "2. Afficher Etudiant" << std::endl;
    std::cout << "3. Modifier Etudiant" << std::endl;
    std::cout << "4. Supprimer Etudiant" << std::endl;
    std::cout << "5. Retour au menu principal" << std::endl;
}

void addStudent() {
    std::cout << "Function to add a student" << std::endl;

    std::string fichier="etudiant.txt" ; 
    int id = countLines(fichier) + 1;
    std::string nom;
    std::string prenom;
    std::string mail;
    int num_insc;
    std::cout << "Nom: ";
    std::cin >> nom;
    std::cout << "Prenom: ";
    std::cin >> prenom;

    std::cout << "Mail: ";
    std::cin >> mail;

    std::cout << "Num_insc: ";
    std::cin >> num_insc;

    Etudiant etudiant(id, nom, prenom, mail, num_insc);
    etudiant.saveToFile(fichier);
    std::cout << "Etudiant ajouté avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 

}

void displayStudents() {
    std::cout << "Function to display students" << std::endl;

    std::string fichier="etudiant.txt" ;

    std::ifstream file(fichier); //creating an input file stream object 
    if (file.is_open()) { //file opening check
        std::string line;
        while (std::getline(file, line)) { //reading file line by line
            std::istringstream iss(line); //parsing to extract fields id,nom...
            std::string idStr;
            std::getline(iss, idStr, ',');
            std::string nom, prenom, mail, numInscStr;
            std::getline(iss, nom, ',');
            std::getline(iss, prenom, ',');
            std::getline(iss, mail, ',');
            std::getline(iss, numInscStr, ',');

            Etudiant e =  Etudiant(atoi(idStr.c_str()) , nom , prenom , mail , atoi(numInscStr.c_str()));
            e.displayFormatted();
        }
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << fichier << " for reading." << std::endl; //cerr: standard error output 
    }
}

void updateStudent() {
    std::cout << "Function to update a student" << std::endl;

    std::string fichier="etudiant.txt" ;
    int id;
    std::cout << "ID de l'étudiant à modifier: ";
    std::cin >> id;
    Etudiant etudiant = Etudiant().readFromFile(fichier, id);
    if (etudiant.getId() == 0) {
        std::cout << "Aucun étudiant trouvé avec l'ID " << id << std::endl;
        return;
    }
    std::string nom;
    std::string prenom;
    std::string mail;
    int numInsc;

    std::cout << "Nom: ";
    std::cin >> nom;
    std::cout << "Prenom: ";
    std::cin >> prenom;
    std::cout << "Mail: ";
    std::cin >> mail;

    std::cout << "NumInsc: ";
    std::cin >> numInsc;

    etudiant.setNom(nom);
    etudiant.setPrenom(prenom);
    etudiant.setMail(mail);
    etudiant.setNumInsc(numInsc);   
    etudiant.updateInFile(fichier);
    std::cout << "Etudiant modifié avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 

}

void deleteStudent() {
    std::cout << "Function to delete a student" << std::endl;

    std::string fichier="etudiant.txt" ;
    int id;
    std::cout << "ID de l'étudiant à supprimer: ";
    std::cin >> id;
    Etudiant etudiant = Etudiant().readFromFile(fichier, id);
    if (etudiant.getId() == 0) {
        std::cout << "Aucun étudiant trouvé avec l'ID " << id << std::endl;
        return;
    }
    etudiant.deleteFromFile(fichier, id);
    std::cout << "Etudiant supprimé avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 

}

void displayEnseignantMenu() {
    clearScreen();
    std::cout << "===== Gestion Enseignant =====" << std::endl;
    std::cout << "1. Ajouter Enseignant" << std::endl;
    std::cout << "2. Afficher Enseignant" << std::endl;
    std::cout << "3. Modifier Enseignant" << std::endl;
    std::cout << "4. Supprimer Enseignant" << std::endl;
    std::cout << "5. Retour au menu principal" << std::endl;
}

void addTeacher() {
    std::cout << "Function to add a teacher" << std::endl;

    std::string fichier="enseignant.txt" ;
    int id = countLines(fichier) + 1;
    std::string nom;
    std::string prenom;
    std::string mail;
    int cnss;
    std::cout << "Nom: ";
    std::cin >> nom;
    std::cout << "Prenom: ";
    std::cin >> prenom;

    std::cout << "Mail: ";
    std::cin >> mail;

    std::cout << "CNSS: ";
    std::cin >> cnss;

    Enseignant enseignant(id, nom, prenom, mail, cnss);
    enseignant.saveToFile(fichier);
    std::cout << "Enseignant ajouté avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 

}

void displayTeachers() {
    std::cout << "Function to display teachers" << std::endl;

    std::string fichier="enseignant.txt" ;

    std::ifstream file(fichier);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, ',');
            std::string nom, prenom, mail, cnssStr;
            std::getline(iss, nom, ',');
            std::getline(iss, prenom, ',');
            std::getline(iss, mail, ',');
            std::getline(iss, cnssStr, ',');

            Enseignant e =  Enseignant(atoi(idStr.c_str()) , nom 
            , prenom , mail , atoi(cnssStr.c_str()));
            e.displayFormatted();
        }
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << fichier << " for reading." << std::endl;
    }

}

void updateTeacher() {
    std::cout << "Function to update a teacher" << std::endl;

    std::string fichier="enseignant.txt" ;
    int id;
    std::cout << "ID de l'enseignant à modifier: ";
    std::cin >> id;
    Enseignant enseignant = Enseignant().readFromFile(fichier, id);
    if (enseignant.getId() == 0) {
        std::cout << "Aucun enseignant trouvé avec l'ID " << id << std::endl;
        return;
    }
    std::string nom;
    std::string prenom;
    std::string mail;
    int cnss;
    std::cout << "Nom: ";
    std::cin >> nom;
    std::cout << "Prenom: ";
    std::cin >> prenom;
    std::cout << "Mail: ";
    std::cin >> mail;
    std::cout << "CNSS: ";
    std::cin >> cnss;

    enseignant.setNom(nom);
    enseignant.setPrenom(prenom);
    enseignant.setMail(mail);
    enseignant.setCNSS(cnss);   
    enseignant.updateInFile(fichier);
    std::cout << "Enseignant modifié avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 
    }

void deleteTeacher() {
    std::cout << "Function to delete a teacher" << std::endl;

    std::string fichier="enseignant.txt" ;
    int id;
    std::cout << "ID de l'enseignant à supprimer: ";
    std::cin >> id;
    Enseignant enseignant = Enseignant().readFromFile(fichier, id);
    if (enseignant.getId() == 0) {
        std::cout << "Aucun enseignant trouvé avec l'ID " << id << std::endl;
        return;
    }
    // std::cout << "e";
    enseignant.deleteFromFile(fichier, id);
    std::cout << "Enseignant supprimé avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore();  //skip characters
    std::cin.get(); //read characters from input

}

void displayMatiereMenu() 
{
    clearScreen();
    std::cout << "===== Gestion Matière =====" << std::endl;
    std::cout << "1. Ajouter Matière" << std::endl;
    std::cout << "2. Afficher Matière" << std::endl;
    std::cout << "3. Modifier Matière" << std::endl;
    std::cout << "4. Supprimer Matière" << std::endl;
    std::cout << "5. Retour au menu principal" << std::endl;
}

void addMatiere() {
    std::cout << "Function to add a matiere" << std::endl;
    std::string fichier = "matiere.txt";
    int idMat = countLines(fichier) + 1;
    std::string nomMat;
    float coef;
    int ensId;

    std::cout << "ID Matiere: ";
    std::cout << idMat << "\n";

    std::cout << "Nom Matiere: ";
    std::cin >> nomMat;
    std::cout << "Coefficient: ";
    std::cin >> coef;
    std::cout << "ID de l'enseignant associé: ";
    std::cin >> ensId;

    Enseignant enseignant = Enseignant().readFromFile("enseignant.txt", ensId);
    Matiere matiere = Matiere(std::to_string(idMat), nomMat, coef, enseignant);

    matiere.saveToFile(fichier);

    std::cout << "Matiere ajoutée avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 
}

void displayMatieres() {
    std::cout << "Function to display matieres" << std::endl;
    std::string fichier = "matiere.txt";
    std::ifstream file(fichier);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idMat, nomMat, ensId;
            float coef;
            std::getline(iss, idMat, ',');
            std::getline(iss, nomMat, ',');
            std::string coefStr;
            std::getline(iss, coefStr, ',');
            coef = std::stof(coefStr); //converts from string to float
            std::getline(iss, ensId, ',');
            Enseignant enseignant = Enseignant().readFromFile("enseignant.txt", std::stoi(ensId));
            Matiere matiere(idMat, nomMat, coef, enseignant);
            matiere.displayFormatted();
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << fichier << " for reading." << std::endl;
    }
}

void updateMatiere() {
    std::cout << "Function to update a matiere" << std::endl;
    std::string fichier = "matiere.txt";
    std::string idMat;
    std::cout << "ID de la matiere à modifier: ";
    std::cin >> idMat;
    Matiere matiere = Matiere().readFromFile(fichier, idMat);
    if (matiere.getIdMat().empty()) {
        std::cout << "Aucune matiere trouvée avec l'ID " << idMat << std::endl;
        return;
    }
    std::string nomMat;
    float coef;
    int ensId;

    std::cout << "Nouveau Nom Matiere: ";
    std::cin >> nomMat;
    std::cout << "Nouveau Coefficient: ";
    std::cin >> coef;
    std::cout << "Nouvel ID de l'enseignant associé: ";
    std::cin >> ensId;

    Enseignant enseignant = Enseignant().readFromFile("enseignant.txt", ensId);
    if (enseignant.getId() == 0) {
        std::cerr << "Erreur: Enseignant avec ID " << ensId << " non trouvé." << std::endl;
        return;
    }

    matiere.setNomMat(nomMat);
    matiere.setCoef(coef);
    matiere.setEnseignant(enseignant);
    matiere.updateInFile(fichier);

    std::cout << "Matiere modifiée avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 
}
void deleteMatiere() {
    std::string filename = "matiere.txt";
    std::string idMat;
    std::cout << "ID de la matiere à supprimer: ";
    std::cin >> idMat;

    Matiere matiere = Matiere().readFromFile(filename, idMat);

    if (matiere.getIdMat().empty()) {
        std::cout << "Aucune matiere trouvée avec l'ID " << idMat << std::endl;
        return;
    }

    Matiere().deleteFromFile(filename, idMat);

    std::cout << "Matiere supprimée avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get();    
}

void addGroupeModule() {
    std::cout << "Function to add a groupe module" << std::endl;

    std::string fichier = "groupe_module.txt";
    int idGM = countLines(fichier) + 1; //unique id for a new entry in the file

    std::string nomGM;
    double coefGM;

    std::cout << "ID du groupe module: " << idGM << std::endl;
    std::cout << "Nom du groupe module: ";
    std::cin >> nomGM;
    std::cout << "Coefficient du groupe module: ";
    std::cin >> coefGM;

    std::vector<Matiere> ListeMat;
    std::cout <<"Liste des matieres :";
    while(true)
    {
        std::string idMat;
        std::cout << "ID de la matiere: ";
        std::cin >> idMat;
        Matiere matiere = Matiere().readFromFile("matiere.txt", idMat);
        if (matiere.getIdMat().empty()) {
            std::cerr << "Erreur: Matiere avec ID " << idMat << " non trouvée." << std::endl;
            continue;
        }
        ListeMat.push_back(matiere);
        std::cout << "Voulez-vous ajouter une autre matiere ? (O/N) ";
        char reponse;
        std::cin >> reponse;
        if (reponse == 'N' || reponse == 'n') {
            break;
        }
    }

    GroupeModule groupeModule = GroupeModule(std::to_string(idGM), nomGM, coefGM, ListeMat);

    groupeModule.saveToFile(fichier);

    std::cout << "Groupe module ajouté avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 
}

void displayGroupeModuleMenu(){
    clearScreen();
    std::cout << "===== Gestion Groupe de Module =====" << std::endl;
    std::cout << "1. Ajouter Groupe de Module" << std::endl;
    std::cout << "2. Afficher Groupe de Module" << std::endl;
    std::cout << "3. Modifier Groupe de Module" << std::endl;
    std::cout << "4. Supprimer Groupe de Module" << std::endl;
    std::cout << "5. Retour au menu principal" << std::endl;
}
void displayGroupeModules() {

    std::cout << "Function to display groupe modules" << std::endl;

    std::string fichier = "groupe_module.txt";

    std::ifstream file(fichier);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);

            std::string idGM, nomGM;
            double coefGM;

            std::vector<std::string> listeMatIds;
            std::vector<Matiere> ListeMat;
            std::getline(iss, idGM, ',');
            std::getline(iss, nomGM, ',');
            std::string coefStr;
            std::getline(iss, coefStr, ',');  //converts from string to double
            coefGM = std::stod(coefStr);
            std::string matieresStr;
            std::getline(iss, matieresStr, ',');
            std::istringstream matieresIss(matieresStr);
            std::string matiereId;
            while (std::getline(matieresIss, matiereId, ';')) {
                Matiere m=  Matiere().readFromFile("matiere.txt", matiereId); 
                std::cout << m.getNomMat() << std::endl;
            ListeMat.push_back(
                   m
                );            
            }            

            GroupeModule groupeM = GroupeModule(idGM , nomGM , coefGM , ListeMat);
            groupeM.displayFormatted();

        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << fichier << " for reading." << std::endl;
    }

    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get();    
}

void updateGroupeModule() {
    std::cout << "Function to update a groupe module" << std::endl;
    std::string fichier = "groupe_module.txt";
    std::string idGM;
    std::cout << "ID du groupe module à modifier: ";
    std::cin >> idGM;
    GroupeModule groupeModule = GroupeModule().readFromFile(fichier, idGM);
    if (groupeModule.getIdGM().empty()) {
        std::cout << "Aucun groupe module trouvé avec l'ID " << idGM << std::endl;
        return;
    }
    std::string nomGM;
    double coefGM;

    std::cout << "Nouveau Nom du groupe module: ";
    std::cin >> nomGM;
    std::cout << "Nouveau Coefficient du groupe module: ";
    std::cin >> coefGM;

    std::vector<Matiere> ListeMat;
    std::cout <<"Liste des matieres :";
    while(true)
    {
        std::string idMat;
        std::cout << "ID de la matiere: ";
        std::cin >> idMat;
        Matiere matiere = Matiere().readFromFile("matiere.txt", idMat);
        if (matiere.getIdMat().empty()) {
            std::cerr << "Erreur: Matiere avec ID " << idMat << " non trouvée." << std::endl;
            continue;
        }
        ListeMat.push_back(matiere);
        std::cout << "Voulez-vous ajouter une autre matiere ? (O/N) ";
        char reponse;
        std::cin >> reponse;
        if (reponse == 'N' || reponse == 'n') {
            break;
        }
    }
       groupeModule.setNomGM(nomGM);
    groupeModule.setCoefGM(coefGM);
    groupeModule.setListeMat(ListeMat);

    groupeModule.updateInFile(fichier);

    std::cout << "Groupe module modifié avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get();    
}

void deleteGroupeModule() {
    std::cout << "Function to delete a groupe module" << std::endl;
    std::string filename = "groupe_module.txt";
    std::string idGM;
    std::cout << "ID du groupe module à supprimer: ";
    std::cin >> idGM;

    GroupeModule groupeModule = GroupeModule().readFromFile(filename, idGM);

    if (groupeModule.getIdGM().empty()) {
        std::cout << "Aucun groupe module trouvé avec l'ID " << idGM << std::endl;
        return;
    }

    GroupeModule().deleteFromFile(filename, idGM);

    std::cout << "Groupe module supprimé avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get();    
}

void displayGroupeMenu()
{
    clearScreen();
    std::cout << "===== Gestion Groupe =====" << std::endl;
    std::cout << "1. Ajouter Groupe" << std::endl;
    std::cout << "2. Afficher Groupe" << std::endl;
    std::cout << "3. Modifier Groupe" << std::endl;
    std::cout << "4. Supprimer Groupe" << std::endl;
    std::cout << "5. Retour au menu principal" << std::endl;

}
void addGroupe() {
    std::cout << "Function to add a groupe" << std::endl;
    std::string fichier = "groupes.txt";
    int idGRP = countLines(fichier) + 1;
    std::string niveau;
    std::string diplome;
    std::string specialite;
    int num_G;

    std::cout << "Niveau: ";
    std::cin >> niveau;
    std::cout << "Diplome: ";
    std::cin >> diplome;
    std::cout << "Specialite: ";
    std::cin >> specialite;
    std::cout << "Num_G: ";
    std::cin >> num_G;

     std::vector<GroupeModule> ListeModules;
    std::vector<Etudiant> ListeEtudiants;
    std::cout <<"Liste des modules :";
    while(true)
    {
        int idGM;
        std::cout << "ID du groupe module: ";
        std::cin >> idGM;

        GroupeModule groupeModule = GroupeModule().readFromFile("groupe_module.txt", std::to_string(idGM));
        if (groupeModule.getIdGM().empty()) {
            std::cerr << "Erreur: Groupe module avec ID " << idGM << " non trouvé." << std::endl;
            continue;
        }
        ListeModules.push_back(groupeModule);
        std::cout << "Voulez-vous ajouter un autre groupe module ? (O/N) ";
        char reponse;
        std::cin >> reponse;
        if (reponse == 'N' || reponse == 'n') {
            break;
        }
    }

    std::cout <<"Liste des etudiants :";
    while(true)
    {
        int idEt;
        std::cout << "ID de l'etudiant: ";
        std::cin >> idEt;
        Etudiant etudiant = Etudiant().readFromFile("etudiant.txt", idEt);
        if (etudiant.getId() == 0) {
            std::cerr << "Erreur: Etudiant avec ID " << idEt << " non trouvé." << std::endl;
            continue;
        }
        ListeEtudiants.push_back(etudiant);
        std::cout << "Voulez-vous ajouter un autre etudiant ? (O/N) ";
        char reponse;
        std::cin >> reponse;
        if (reponse == 'N' || reponse == 'n') {
            break;
        }
    }

    Groupe groupe = Groupe(std::to_string(idGRP), niveau, diplome, specialite, num_G, ListeModules, ListeEtudiants);
    groupe.saveToFile(fichier);

    std::cout << "Groupe ajouté avec succès." << std::endl;

    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 
}

void displayGroupes() {
    std::string fichier = "groupes.txt";
    std::ifstream file(fichier);
    if (file.is_open()) {
        std::string line;
          std::cout << "|" << std::setw(10) << "id" << "|" //setw used to set the width of each column to ensure proper alignment
              << std::setw(10) << "Niveau" << "|"
              << std::setw(14) << "Diplome" << "|"
                << std::setw(10) << "specialite" << "|" << std::endl;


            std::cout << "-------------------------------------------------" << std::endl;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idGRP;
            std::string niveau, diplome, specialite;
            int num_G;
            std::string modulesStr;
            std::string etudiantsStr;
            std::getline(iss, idGRP, ',');
            std::getline(iss, niveau, ',');
            std::getline(iss, diplome, ',');
            std::getline(iss, specialite, ',');
            std::string numGStr;
            std::getline(iss, numGStr, ',');
            num_G = std::stoi(numGStr); //convert strings containing numeric values into integers
            std::getline(iss, modulesStr, ',');
            std::istringstream modulesIss(modulesStr);
            std::string moduleId;
            std::vector<GroupeModule> ListeModules;
            while (std::getline(modulesIss, moduleId, ';')) {
                GroupeModule groupeModule = GroupeModule().readFromFile("groupe_module.txt", moduleId);
                if (groupeModule.getIdGM().empty()) {
                    std::cerr << "Erreur: Groupe module avec ID " << moduleId << " non trouvé." << std::endl;
                    continue;
                }
                ListeModules.push_back(groupeModule);
            }
            std::getline(iss, etudiantsStr, ',');
            std::istringstream etudiantsIss(etudiantsStr);
            std::string etudiantId;
            std::vector<Etudiant> ListeEtudiants;
            while (std::getline(etudiantsIss, etudiantId, ';')) {
                Etudiant etudiant = Etudiant().readFromFile("etudiant.txt", std::stoi(etudiantId));
                if (etudiant.getId() == 0) {
                    std::cerr << "Erreur: Etudiant avec ID " << etudiantId << " non trouvé." << std::endl;
                    continue;
                }
                ListeEtudiants.push_back(etudiant);
            }
            Groupe groupe = Groupe(idGRP, niveau, diplome, specialite, num_G, ListeModules, ListeEtudiants);
            groupe.displayFormatted();
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << fichier << " for reading." << std::endl;
    }

}

void updateGroupe() {
    std::cout << "Function to update a groupe" << std::endl;
    std::string fichier = "groupes.txt";
    std::string idGRP;
    std::cout << "ID du groupe à modifier: ";
    std::cin >> idGRP;
    Groupe groupe = Groupe().readFromFile(fichier, idGRP);
    if (groupe.getIdGRP().empty()) {
        std::cout << "Aucun groupe trouvé avec l'ID " << idGRP << std::endl;
        return;
    }
    std::string niveau;
    std::string diplome;
    std::string specialite;
    int num_G;

    std::cout << "Nouveau Niveau du groupe: ";
    std::cin >> niveau;
    std::cout << "Nouveau Diplome du groupe: ";
    std::cin >> diplome;
    std::cout << "Nouvelle Spécialité du groupe: ";

    std::cin >> specialite;
    std::cout << "Nouveau Numéro de Groupe: ";
    std::cin >> num_G;
 std::vector<GroupeModule> ListeModules;
    std::vector<Etudiant> ListeEtudiants;
    std::cout <<"Liste des modules :";
    while(true)
    {
        int idGM;
        std::cout << "ID du groupe module: ";
        std::cin >> idGM;

        GroupeModule groupeModule = GroupeModule().readFromFile("groupe_module.txt", std::to_string(idGM));
        if (groupeModule.getIdGM().empty()) {
            std::cerr << "Erreur: Groupe module avec ID " << idGM << " non trouvé." << std::endl;
            continue;
        }
        ListeModules.push_back(groupeModule);
        std::cout << "Voulez-vous ajouter un autre groupe module ? (O/N) ";
        char reponse;
        std::cin >> reponse;
        if (reponse == 'N' || reponse == 'n') {
            break;
        }
    }

    std::cout <<"Liste des etudiants :";
    while(true)
    {
        int idEt;
        std::cout << "ID de l'etudiant: ";
        std::cin >> idEt;
        Etudiant etudiant = Etudiant().readFromFile("etudiant.txt", idEt);
        if (etudiant.getId() == 0) {
            std::cerr << "Erreur: Etudiant avec ID " << idEt << " non trouvé." << std::endl;
            continue;
        }
        ListeEtudiants.push_back(etudiant);
        std::cout << "Voulez-vous ajouter un autre etudiant ? (O/N) ";
        char reponse;
        std::cin >> reponse;
        if (reponse == 'N' || reponse == 'n') {
            break;
        }
    }

    groupe.setNiveau(niveau);
    groupe.setDiplome(diplome);
    groupe.setSpecialite(specialite);
    groupe.setNumG(num_G);
    groupe.setListeModules(ListeModules);
    groupe.setListeEtudiants(ListeEtudiants);
    groupe.updateInFile(fichier);

    std::cout << "Groupe modifié avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 

}

void deleteGroupe() {
    std::cout << "Function to delete a groupe" << std::endl;
    std::string filename = "groupes.txt";
    std::string idGRP;
    std::cout << "ID du groupe à supprimer: ";
    std::cin >> idGRP;

    Groupe groupe = Groupe().readFromFile(filename, idGRP);

    if (groupe.getIdGRP().empty()) {
        std::cout << "Aucun groupe trouvé avec l'ID " << idGRP << std::endl;
        return;
    }

    Groupe().deleteFromFile(filename, idGRP);

    std::cout << "Groupe supprimé avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get();    

}

void displayNoteMenu()
{
    clearScreen();
    std::cout << "===== Gestion Note =====" << std::endl;
    std::cout << "1. Ajouter Note" << std::endl;
    std::cout << "2. Afficher Note" << std::endl;
    std::cout << "3. Modifier Note" << std::endl;
    std::cout << "4. Supprimer Note" << std::endl;
    std::cout << "5. Retour au menu principal" << std::endl;
}
void addNote()
{
    std::cout << "Function to add a note" << std::endl;
    std::string fichier = "notes.txt";
    int idEt;
    std::string idMat;
    float note;
    std::string type ; 
    std::cout << "ID de l'étudiant: ";
    std::cin >> idEt;
    std::cout << "ID de la matière: ";
    std::cin >> idMat;
    std::cout << "Note: ";
    std::cin >> note;
    std::cout << "Type de la note: ";
    std::cin >> type;
    Etudiant etudiant = Etudiant().readFromFile("etudiant.txt", idEt);
    if (etudiant.getId() == 0) {
        std::cerr << "Erreur: Etudiant avec ID " << idEt << " non trouvé." << std::endl;
        return;
    }
    Matiere matiere = Matiere().readFromFile("matiere.txt", idMat);
    if (matiere.getIdMat().empty()) {
        std::cerr << "Erreur: Matiere avec ID " << idMat << " non trouvée." << std::endl;
        return;
    }
    Note noteObj = Note( matiere, etudiant, note , type );
    noteObj.saveToFile(fichier);
    std::cout << "Note ajoutée avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 
}

void updateNote()
{
    std::cout << "Function to update a note" << std::endl;
    std::string fichier = "notes.txt";
    std::string idMatiere ; 
    int idEtudiant ; 
    std::string type ; 
    std::cout << "ID de la matiere  ";
    std::cin >> idMatiere;
    std::cout << "ID de l'etudiant: ";
    std::cin >> idEtudiant;
    std::cout << "Type de la note: ";
    std::cin >> type;
    Note note = Note().readFromFile(fichier, idMatiere , idEtudiant , type );
    if (note.getMatiere().getIdMat().empty()) {
        std::cout << "Aucune note trouvée avec l'ID " << idMatiere << std::endl;
        return;
    }
    float noteValue;
    std::cout << "Nouvelle note: ";
    std::cin >> noteValue;
    std::cout << noteValue;
    note.setNote(noteValue);
    note.setNote(1);

    note.updateInFile(fichier);
    std::cout << "Note modifiée avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 

}
void displayNote()
{
    std::cout << "Function to display notes" << std::endl;
    std::string fichier = "notes.txt";
    std::ifstream file(fichier);
    if (file.is_open()) {
        std::string line;
            std::cout << "|" << std::setw(10) << "Matiere" << "|"
              << std::setw(10) << "Note" << "|"
              << std::setw(14) << "Etudiant " << "|"
                << std::setw(10) << "Type note" << "|" << std::endl;
            std::cout << "-------------------------------------------------" << std::endl;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type, idEt, idMat, noteStr;
            std::getline(iss, idMat, ',');
            std::getline(iss, idEt, ',');
            std::getline(iss, noteStr, ',');
            std::getline(iss, type, ',');
            Etudiant etudiant = Etudiant().readFromFile("etudiant.txt", std::stoi(idEt));
            Matiere matiere = Matiere().readFromFile("matiere.txt", idMat);
            Note note = Note(
                matiere , 
                etudiant ,
                std::stof(noteStr)  ,
                type
            );

            note.displayFormatted();
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << fichier << " for reading." << std::endl;
    }
}

void deleteNote()
{
    std::cout << "Function to delete a note" << std::endl;
    std::string filename = "notes.txt";
    std::string idMatiere ;
    int idEtudiant ;
    std::string type ;
    std::cout << "ID de la matiere: ";
    std::cin >> idMatiere;
    std::cout << "ID de l'etudiant: ";
    std::cin >> idEtudiant;
    std::cout << "Type de la note: ";
    std::cin >> type;
    Note note = Note().readFromFile(filename, idMatiere , idEtudiant , type);
    if (note.getMatiere().getIdMat().empty()) {
        std::cout << "Aucune note trouvée avec l'ID " << idMatiere << std::endl;
        return;
    }
    note.deleteFromFile(filename, idMatiere , idEtudiant , type);
    std::cout << "Note supprimée avec succès." << std::endl;
    std::cout << "Appuyez sur entrée pour continuer...";
    std::cin.ignore(); 
    std::cin.get(); 

}

void displayPVGroupe(){
    std::cout << "Function to display PV for a groupe" << std::endl;
    std::string fichier = "notes.txt";
    std::string idGRP;
    std::cout << "ID du groupe: ";
    std::cin >> idGRP;
    Groupe groupe = Groupe().readFromFile("groupes.txt", idGRP);
    if (groupe.getIdGRP().empty()) {
        std::cerr << "Erreur: Groupe avec ID " << idGRP << " non trouvé." << std::endl;
        return;
    }
    std::vector<GroupeModule> listGM = groupe.getListeModules();
    TextTable t( '-', '|', '+' ); //displaying data in rows and  columns

    t.add("               ") ; 

    std::cout << std::setw(30);
     for (const GroupeModule& GPM : listGM) { //iterates the list of group modules and adds each module's name 
        t.add(GPM.getNomGM()) ;
     }
    t.add("               ") ; 
    t.add("               ") ; 
    t.add("               ") ; 

    t.endOfRow();
    t.add("               ") ; 

     for (const GroupeModule& GPM : listGM) { //iterates the list of group modules and adds each module's cofficient
        t.add(std::to_string(GPM.getCoefGM())) ;
     }
      t.add("               ") ; 
    t.add("               ") ; 
    t.add("               ") ; 

    t.endOfRow();

   
    t.add("               ") ;
    for (const GroupeModule& GPM : listGM) { //adds the modules name then material's name to the table
        std::string innerTableString = "" ;
        std::vector<Matiere> listeMat = GPM.getListeMat();
        for (const Matiere& mat : listeMat) {
            innerTableString+= "|" + mat.getNomMat() + "|" ;
        }

          t.add(innerTableString);

    }
    t.add("               ") ;
    t.add("               ") ;
    t.add("               ") ;
    t.endOfRow();
        t.add("Liste Etudiants") ;


    for (const GroupeModule& GPM : listGM) {
        std::vector<Matiere> listeMat = GPM.getListeMat();
        std::string innerTableString = "" ;

        for (const Matiere& mat : listeMat) {
            innerTableString+= "|" + std::to_string(mat.getCoef()) + "|" ;
        }
        innerTableString+="MoyGM";
        t.add(innerTableString);

     }
    t.add(" Moyenne Generale ") ;
    t.add("Resultat") ;
    t.add("Mention") ;
    t.endOfRow();


    std::cout << std::endl ;
    std::vector<Etudiant> listeEtudiants = groupe.getListeEtudiants();
    for (const Etudiant& etudiant : listeEtudiants) {
            float MG=0 ; 

        t.add(
            std::to_string(etudiant.getNumInsc()) + "|" +
            etudiant.getNom() + "|" + etudiant.getPrenom() //adding student data to the table
    
        ); 
        int sumCoeff=0 ; //total coefficient of all group modules 
        for (const GroupeModule& GPM : listGM) { //iterates over each group module in the list
            float MGM=0 ; 
            sumCoeff+=GPM.getCoefGM();

            std::vector<Matiere> listeMat = GPM.getListeMat();
            std::string innerString="" ; 
            for (const Matiere& mat : listeMat) {
                Note note = Note().readFromFile("notes.txt", mat.getIdMat(), etudiant.getId(), "ds");
                Note note2 = Note().readFromFile("notes.txt", mat.getIdMat(), etudiant.getId(), "examen");
                Note note3 = Note().readFromFile("notes.txt", mat.getIdMat(), etudiant.getId(), "cc");
                float moyenne = (note.getNote() + note2.getNote() + note3.getNote() )/ 3;
                innerString += 
                "|" + std::to_string(moyenne) + "|" ;
                MGM += (moyenne * mat.getCoef())/GPM.getCoefGM();
            }
            

           
            MG += (MGM * GPM.getCoefGM())/sumCoeff;
           
            innerString += "="+ std::to_string(MGM);



// Add the colorized MGMString to the TextTable
t.add(innerString);

        }
        t.add(std::to_string(MG));
         
         if(MG >= 10)
         {
             t.add("ADMIS");
         }
         else
         {
             t.add("Ajourné");
         }
         if(MG>=10 && MG < 12)
            {
                t.add("Passable") ;
            }
            else if(MG>=12 && MG < 14)
            {
                t.add("Assez Bien") ;
            }
            else if(MG>=14 && MG < 16)
            {
                
                t.add("Bien") ;
            }
            else if(MG>=16 && MG < 18)
            {
                t.add("Très Bien") ;
            }
            else if(MG>=18 && MG <= 20)
            {
                t.add("Excellent") ;
            }
            else
            {
                t.add("-") ;
            }
        t.endOfRow();
       
    }    
    std::cout << t << std::endl; 

}