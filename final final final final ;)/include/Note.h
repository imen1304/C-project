#ifndef NOTE_H
#define NOTE_H

#include "Matiere.h"
#include "Etudiant.h"
#include <string>

class Note {
private:
    Matiere mat;
    Etudiant etu;
    double note;
    std::string Type;

public:
    Note();
    Note(const Matiere& matiere, const Etudiant& etudiant, double note, const std::string& type);

    Matiere getMatiere() const;
    void setMatiere(const Matiere& matiere);

    Etudiant getEtudiant() const;
    void setEtudiant(const Etudiant& etudiant);

    double getNote() const;
    void setNote(double note);

    std::string getType() const;
    void setType(const std::string& type);

    void saveToFile(const std::string& filename) const ;
    Note readFromFile(const std::string& filename, const std::string& idMat, int id , 
    const std::string& type);
    void updateInFile(const std::string& filename) const;
    void deleteFromFile(const std::string& filename, const std::string& idMat, int id,
    const std::string& type);
    void displayFormatted() const;

};

#endif 