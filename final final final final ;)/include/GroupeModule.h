#ifndef GROUPEMODULE_H
#define GROUPEMODULE_H

#include <string>
#include <vector>
#include "Matiere.h"

class GroupeModule {
private:
    std::string IdGM;
    std::string NomGM;
    double CoefGM;
    std::vector<Matiere> ListeMat;

public:
    GroupeModule();
    GroupeModule(const std::string& idGM, const std::string& nomGM, double coefGM, const std::vector<Matiere>& listeMat);

    std::string getIdGM() const;
    void setIdGM(const std::string& idGM);

    std::string getNomGM() const;
    void setNomGM(const std::string& nomGM);

    double getCoefGM() const;
    void setCoefGM(double coefGM);

    std::vector<Matiere> getListeMat() const;
    void setListeMat(const std::vector<Matiere>& listeMat);
    void saveToFile(const std::string& filename) const ;
    GroupeModule readFromFile(const std::string& filename, const std::string& idGM);
    void updateInFile(const std::string& filename) const;
    void deleteFromFile(const std::string& filename, const std::string& idGM);
    void displayFormatted() const;

};

#endif 