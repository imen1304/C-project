#include "../include/GroupeModule.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

GroupeModule::GroupeModule() : IdGM(""), NomGM(""), CoefGM(0.0), ListeMat({}) {}

GroupeModule::GroupeModule(const std::string& idGM, const std::string& nomGM, double coefGM, const std::vector<Matiere>& listeMat) 
    : IdGM(idGM), NomGM(nomGM), CoefGM(coefGM), ListeMat(listeMat) {}

std::string GroupeModule::getIdGM() const {
    return IdGM;
}

void GroupeModule::setIdGM(const std::string& idGM) {
    IdGM = idGM;
}

std::string GroupeModule::getNomGM() const {
    return NomGM;
}

void GroupeModule::setNomGM(const std::string& nomGM) {
    NomGM = nomGM;
}

double GroupeModule::getCoefGM() const {
    return CoefGM;
}

void GroupeModule::setCoefGM(double coefGM) {
    CoefGM = coefGM;
}

std::vector<Matiere> GroupeModule::getListeMat() const {
    return ListeMat;
}

void GroupeModule::setListeMat(const std::vector<Matiere>& listeMat) {
    ListeMat = listeMat;
}

void GroupeModule::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios_base::app); 
    if (file.is_open()) {
        file << getIdGM() << "," << getNomGM() << "," << getCoefGM() << ",";
        for (const Matiere& matiere : getListeMat()) {
            file << matiere.getIdMat() << ";"; 
        }
        file << "\n";
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

GroupeModule GroupeModule::readFromFile(const std::string& filename, const std::string& idGM) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr, nom, coefStr, matieresStr;
            std::getline(iss, idStr, ',');
            if (idStr == idGM) {
                std::getline(iss, nom, ',');
                std::getline(iss, coefStr, ',');
                double coef = std::stod(coefStr);

                std::vector<Matiere> matieres;
                std::string matiereId;
                while (std::getline(iss, matiereId, ';')) {

                    Matiere matiere = Matiere().readFromFile("matiere.txt", matiereId);
                    if (!matiere.getIdMat().empty()) {
                        matieres.push_back(matiere);
                    }
                }
                return GroupeModule(idStr, nom, coef, matieres);
            }
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
    return GroupeModule(); 
}

void GroupeModule::updateInFile(const std::string& filename) const {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        int id = 1; 

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, ',');

            if (idStr == getIdGM()) {
                temp << id++ << "," << getNomGM() << "," << getCoefGM() << ",";
                for (const Matiere& matiere : getListeMat()) {
                    temp << matiere.getIdMat() << ";";
                }
                temp << "\n";
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

void GroupeModule::deleteFromFile(const std::string& filename, const std::string& idGM) {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    int id=1 ; 
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idStr;
            std::getline(iss, idStr, ',');
            if (idStr != idGM) {
                temp << id++ << "," << line << "\n"; 
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

void GroupeModule::displayFormatted() const {
    std::cout << "|" << std::setw(10) << getIdGM() << "|"
              << std::setw(10) << getNomGM() << "|"
              << std::setw(10) << getCoefGM() << "|(";

    int i = 0 ;
    for (const Matiere& matiere : getListeMat()) {
        if (i == 0) {
            std::cout << matiere.getNomMat()  ;
            i++;
        }
        else
        {
            std::cout <<"," << matiere.getNomMat() ;
        }
    }
    std::cout << ")|" << std::endl;
}