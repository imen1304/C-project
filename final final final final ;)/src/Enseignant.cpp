#include "../include/Enseignant.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

Enseignant::Enseignant() : CNSS(0) {}

Enseignant::Enseignant(int id, const std::string& nom, const std::string& prenom, const std::string& mail, int cnss) 
    : Personne(id, nom, prenom, mail), CNSS(cnss) {}

int Enseignant::getCNSS() const {
    return CNSS;
}

void Enseignant::setCNSS(int cnss) {
    CNSS = cnss;
}
void Enseignant::saveToFile(const std::string& filename) const {
    std::ofstream file(filename , 
    std::ios_base::app

    );
    if (file.is_open()) {
        file << getId() << "," << getNom() << "," << getPrenom() << "," << getMail() << "," << getCNSS() << "\n";
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

Enseignant Enseignant::readFromFile(const std::string& filename, int id) {
    std::ifstream file(filename
    );
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, ',');
            if (std::stoi(idStr) == id) {

                std::string nom, prenom, mail, cnssStr;
                std::getline(iss, nom, ',');
                std::getline(iss, prenom, ',');
                std::getline(iss, mail, ',');
                std::getline(iss, cnssStr, ',');
                return Enseignant(id, nom, prenom, mail, std::stoi(cnssStr));
            }
        }
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
    return Enseignant();
}

void Enseignant::updateInFile(const std::string& filename) const
{
    std::ifstream
    file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, ',');
            if (std::stoi(idStr) == getId()) {
                temp << getId() << "," << getNom() << "," << getPrenom() << "," << getMail() << "," << getCNSS() << "\n";
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

void Enseignant::deleteFromFile(const std::string& filename, int idToDelete) {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr, nom, prenom, mail, CNSSStr;
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
                std::getline(iss, CNSSStr, ',');
                temp << CNSSStr << "\n";
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

void Enseignant::displayFormatted() const  {
    std::cout << "|" << std::setw(2)
                << getId() << "|" << std::setw(20)
                << getNom() << "|" << std::setw(20)
                << getPrenom() << "|" << std::setw(20)
                << getMail() << "|" << std::setw(20)
                << getCNSS() << "|" << std::endl;
}