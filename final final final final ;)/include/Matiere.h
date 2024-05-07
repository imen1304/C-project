#ifndef MATIERE_H
#define MATIERE_H

#include <string>
#include "Enseignant.h"

class Matiere {
private:
    std::string IdMat;
    std::string NomMat;
    float Coef;
    Enseignant Ens;

public:
    Matiere();
    Matiere(const std::string& idMat, const std::string& nomMat, double coef, const Enseignant& enseignant);

    std::string getIdMat() const;
    void setIdMat(const std::string& idMat);

    std::string getNomMat() const;
    void setNomMat(const std::string& nomMat);

    double getCoef() const;
    void setCoef(double coef);

    Enseignant getEnseignant() const;
    void setEnseignant(const Enseignant& enseignant);
    void saveToFile(const std::string& filename) const;
     Matiere readFromFile(const std::string& filename, const std::string& idMat);
    void updateInFile(const std::string& filename) const;
     void deleteFromFile(const std::string& filename, const std::string& idMat);

    void displayFormatted() const;
};

#endif 