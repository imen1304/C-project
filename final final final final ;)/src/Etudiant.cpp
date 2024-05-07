#include "../include/Etudiant.h"
#include <fstream>
#include <iostream>
#include <sstream> 
#include <iomanip>
Etudiant::Etudiant() : Num_insc(0) {}

Etudiant::Etudiant(int id, const std::string& nom, const std::string& prenom, const std::string& mail, int num_insc) 
    : Personne(id, nom, prenom, mail), Num_insc(num_insc) {}

int Etudiant::getNumInsc() const {
    return Num_insc;
}

void Etudiant::setNumInsc(int num_insc) {
    Num_insc = num_insc;
}
void Etudiant::saveToFile(const std::string& filename) const {
        std::ofstream file(filename, std::ios_base::app); 

    if (file.is_open()) {
        file << getId() << "," << getNom() << "," << getPrenom() << "," << getMail() << "," << getNumInsc() << "\n";
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

Etudiant Etudiant::readFromFile(const std::string& filename, int id) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, ',');
            if (std::stoi(idStr) == id) {
                std::string nom, prenom, mail, numInscStr;
                std::getline(iss, nom, ',');
                std::getline(iss, prenom, ',');
                std::getline(iss, mail, ',');
                std::getline(iss, numInscStr, ',');
                return Etudiant(id, nom, prenom, mail, std::stoi(numInscStr));
            }
        }
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
    return Etudiant();
}

void Etudiant::updateInFile(const std::string& filename) const
{
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, ',');
            if (std::stoi(idStr) == getId()) {
                temp << getId() << "," << getNom() << "," << getPrenom() << "," << getMail() << "," << getNumInsc() << "\n";
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
}

void Etudiant::deleteFromFile(const std::string& filename, int idToDelete) {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr, nom, prenom, mail, numInscStr;
            std::getline(iss, idStr, ',');
            int id = std::stoi(idStr);
            if (id != idToDelete) {
                if (id > idToDelete) {
                    id--; 
                }
                temp << id << ",";
                std::getline(iss, nom, ',');
                temp << nom << ",";
                std::getline(iss, prenom, ',');
                temp << prenom << ",";
                std::getline(iss, mail, ',');
                temp << mail << ",";
                std::getline(iss, numInscStr, ',');
                temp << numInscStr << "\n";
            }
        }
        file.close();
        temp.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
}

void Etudiant::displayFormatted() const {
    std::cout << "|" << std::setw(2) << getId() << "|"
              << std::setw(10) << getNom() << "|"
              << std::setw(10) << getPrenom() << "|"
              << std::setw(20) << getMail() << "|"
              << std::setw(6) << getNumInsc() << "|" << std::endl;
}