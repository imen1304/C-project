#include "../include/Matiere.h"
#include <fstream>
#include <iostream>
#include <sstream> 
#include <iomanip>
Matiere::Matiere() : IdMat(""), NomMat(""), Coef(0), Ens(Enseignant()) {}

Matiere::Matiere(const std::string& idMat, const std::string& nomMat, double coef, const Enseignant& enseignant) 
    : IdMat(idMat), NomMat(nomMat), Coef(coef), Ens(enseignant) {}

std::string Matiere::getIdMat() const {
    return IdMat;
}

void Matiere::setIdMat(const std::string& idMat) {
    IdMat = idMat;
}

std::string Matiere::getNomMat() const {
    return NomMat;
}

void Matiere::setNomMat(const std::string& nomMat) {
    NomMat = nomMat;
}

double Matiere::getCoef() const {
    return Coef;
}

void Matiere::setCoef(double coef) {
    Coef = coef;
}

Enseignant Matiere::getEnseignant() const {
    return Ens;
}

void Matiere::setEnseignant(const Enseignant& enseignant) {
    Ens = enseignant;
}

void Matiere::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios_base::app); 
    if (file.is_open()) {
        file << getIdMat() << "," << getNomMat() << "," << getCoef() << "," << getEnseignant().getId() << "\n";
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}
Matiere Matiere::readFromFile(const std::string& filename, const std::string& idMat) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idMatStr, nomMat, ensIdStr;
            float coef;
            std::getline(iss, idMatStr, ',');
            if (idMatStr == idMat) {
                std::getline(iss, nomMat, ',');
                std::string coefStr;
                std::getline(iss, coefStr, ',');
                coef = std::stof(coefStr);
                std::getline(iss, ensIdStr, ',');
                Enseignant ens = Enseignant().readFromFile("enseignant.txt", std::stoi(ensIdStr));
                return Matiere(idMatStr, nomMat, coef, ens);
            }
        }
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
    return Matiere("", "", 0.0, Enseignant());
}

void Matiere::updateInFile(const std::string& filename) const {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idMatStr;
            std::getline(iss, idMatStr, ',');
            if (idMatStr == getIdMat()) {
                temp << getIdMat() << "," << getNomMat() << "," << getCoef() << "," << getEnseignant().getId() << "\n";
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

void Matiere::deleteFromFile(const std::string& filename, const std::string& idMat) {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        int id = 1; 
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string currentIdMat;
            std::getline(iss, currentIdMat, ',');
            if (currentIdMat == idMat) {
                continue; 
            }

            temp << id++ << "," << line.substr(line.find(',') + 1) << "\n";
        }
        file.close();
        temp.close();
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
}

void Matiere::displayFormatted() const {
    std::cout << "|" << std::setw(10) << getIdMat() << "|"
              << std::setw(20) << getNomMat() << "|"
              << std::setw(6) << getCoef() << "|"
              << std::setw(10) << getEnseignant().getNom() << "|"
              << std::setw(10) << getEnseignant().getPrenom() << "|"
              << std::setw(20) << getEnseignant().getMail() << "|"
              << std::setw(6) << getEnseignant().getCNSS() << "|" << std::endl;
}