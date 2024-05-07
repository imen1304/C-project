#include "../include/Note.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

Note::Note() : mat(Matiere()), etu(Etudiant()), note(0.0), Type("") {}

Note::Note(const Matiere& matiere, const Etudiant& etudiant, double note, const std::string& type) 
    : mat(matiere), etu(etudiant), note(note), Type(type) {}

Matiere Note::getMatiere() const {
    return mat;
}

void Note::setMatiere(const Matiere& matiere) {
    mat = matiere;
}

Etudiant Note::getEtudiant() const {
    return etu;
}

void Note::setEtudiant(const Etudiant& etudiant) {
    etu = etudiant;
}

double Note::getNote() const {
    return note;
}

void Note::setNote(double note) {
    note = note;
}

std::string Note::getType() const {
    return Type;
}

void Note::setType(const std::string& type) {
    Type = type;
}

void Note::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios_base::app); 
    if (file.is_open()) {
        file << getMatiere().getIdMat() << "," << getEtudiant().getId() << "," << getNote() << "," << getType() << "\n";
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

Note Note::readFromFile(const std::string& filename, const std::string& idMat, int id , 
    const std::string& type) {
    std::ifstream file(filename
    );
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idMatStr, idEtuStr, noteStr, typeStr;
            std::getline(iss, idMatStr, ',');
            std::getline(iss, idEtuStr, ',');
            std::getline(iss, noteStr, ',');
            std::getline(iss, typeStr, ',');

            if (idMatStr == idMat && std::stoi(idEtuStr) == id && typeStr == type) {
                return Note(Matiere().readFromFile("matiere.txt", idMat), Etudiant().readFromFile("etudiant.txt", id), std::stod(noteStr), typeStr);
            }
            else{

            }
        }
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
    return Note(); 
}

void Note::updateInFile(const std::string& filename) const
{
    std::ifstream
    file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idMatStr, idEtuStr, noteStr, typeStr;
            std::getline(iss, idMatStr, ',');
            std::getline(iss, idEtuStr, ',');
            std::getline(iss, noteStr, ',');
            std::getline(iss, typeStr, ',');
            if (idMatStr == getMatiere().getIdMat() &&  std::stoi(idEtuStr) == getEtudiant().getId() &&  typeStr == getType() ) {
                temp << getMatiere().getIdMat() << "," << getEtudiant().getId() << "," << getNote() << "," << getType() << "\n";
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        std::remove(filename.c_str());
        std::rename("temp.txt", filename.c_str());
    }
}
void Note::deleteFromFile(const std::string& filename, const std::string& idMat, int id, const std::string& type) {
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idMatStr, idEtuStr, noteStr, typeStr;
            std::getline(iss, idMatStr, ',');
            std::getline(iss, idEtuStr, ',');
            std::getline(iss, noteStr, ',');
            std::getline(iss, typeStr, ',');

            if (idMatStr != idMat || std::stoi(idEtuStr) != id || typeStr != type) {
                temp << line << "\n"; 
            }
        }
        file.close();
        temp.close();
        std::remove(filename.c_str()); 
        std::rename("temp.txt", filename.c_str()); 
    } else {
        std::cerr << "Error: Unable to open file for reading or writing." << std::endl;
    }
}
void Note::displayFormatted () const {
    std::cout << "|" << std::setw(10) << getMatiere().getNomMat() << "|"
              << std::setw(10) << getNote() << "|"
              << std::setw(10) <<getEtudiant().getNom()  << " " << getEtudiant().getPrenom() << "|"
                << std::setw(10) << getType() << "|" << std::endl;
}