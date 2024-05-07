#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Personne.h"

class Etudiant : public Personne {
private:
    int Num_insc;

public:
    Etudiant();
    Etudiant(int id, const std::string& nom, const std::string& prenom, const std::string& mail, int num_insc);

    int getNumInsc() const;
    void setNumInsc(int num_insc);
    void saveToFile(const std::string& filename) const ;
     Etudiant readFromFile(const std::string& filename, int id);
    void updateInFile(const std::string& filename) const;
     void deleteFromFile(const std::string& filename, int id);
void  displayFormatted() const ;
};

#endif 