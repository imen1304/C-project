#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "Personne.h"

class Enseignant : public Personne {
private:
    int CNSS;

public:
    Enseignant();
    Enseignant(int id, const std::string& nom, const std::string& prenom, const std::string& mail, int cnss);

    int getCNSS() const;
    void setCNSS(int cnss);
    void saveToFile(const std::string& filename) const;
     Enseignant readFromFile(const std::string& filename, int id);
    void updateInFile(const std::string& filename) const;
    void deleteFromFile(const std::string& filename, int id);
    void displayFormatted() const;

};

#endif 