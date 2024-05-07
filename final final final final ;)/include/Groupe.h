#ifndef GROUPE_H
#define GROUPE_H

#include <string>
#include <vector>
#include "Etudiant.h"
#include "GroupeModule.h"

class Groupe {
private:
    std::string IdGRP;
    std::string Niveau;
    std::string Diplome;
    std::string Specialite;
    int Num_G;
    std::vector<GroupeModule> ListeModules;
    std::vector<Etudiant> ListeEtudiants;

public:
    Groupe();
    Groupe(const std::string& idGRP, const std::string& niveau, const std::string& diplome, const std::string& specialite, int num_G, const std::vector<GroupeModule>& listeModules, const std::vector<Etudiant>& listeEtudiants);

    std::string getIdGRP() const;
    void setIdGRP(const std::string& idGRP);

    std::string getNiveau() const;
    void setNiveau(const std::string& niveau);

    std::string getDiplome() const;
    void setDiplome(const std::string& diplome);

    std::string getSpecialite() const;
    void setSpecialite(const std::string& specialite);

    int getNumG() const;
    void setNumG(int num_G);

    std::vector<GroupeModule> getListeModules() const;
    void setListeModules(const std::vector<GroupeModule>& listeModules);

    std::vector<Etudiant> getListeEtudiants() const;
    void setListeEtudiants(const std::vector<Etudiant>& listeEtudiants);
    void saveToFile(const std::string& filename) const ;    
    Groupe readFromFile(const std::string& filename, const std::string& id);
    void updateInFile(const std::string& filename) const;
    void deleteFromFile(const std::string& filename, const std::string& id);
    void displayFormatted() const;

};

#endif 