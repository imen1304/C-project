#include "../include/Groupe.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

Groupe::Groupe() : IdGRP(""), Niveau(""), Diplome(""), Specialite(""), Num_G(0), ListeModules({}), ListeEtudiants({}) {}

Groupe::Groupe(const std::string& idGRP, const std::string& niveau, const std::string& diplome, const std::string& specialite, int num_G, const std::vector<GroupeModule>& listeModules, const std::vector<Etudiant>& listeEtudiants) 
    : IdGRP(idGRP), Niveau(niveau), Diplome(diplome), Specialite(specialite), Num_G(num_G), ListeModules(listeModules), ListeEtudiants(listeEtudiants) {}

std::string Groupe::getIdGRP() const {
    return IdGRP;
}

void Groupe::setIdGRP(const std::string& idGRP) {
    IdGRP = idGRP;
}

std::string Groupe::getNiveau() const {
    return Niveau;
}

void Groupe::setNiveau(const std::string& niveau) {
    Niveau = niveau;
}

std::string Groupe::getDiplome() const {
    return Diplome;
}

void Groupe::setDiplome(const std::string& diplome) {
    Diplome = diplome;
}

std::string Groupe::getSpecialite() const {
    return Specialite;
}

void Groupe::setSpecialite(const std::string& specialite) {
    Specialite = specialite;
}

int Groupe::getNumG() const {
    return Num_G;
}

void Groupe::setNumG(int num_G) {
    Num_G = num_G;
}

std::vector<GroupeModule> Groupe::getListeModules() const {
    return ListeModules;
}

void Groupe::setListeModules(const std::vector<GroupeModule>& listeModules) {
    ListeModules = listeModules;
}

std::vector<Etudiant> Groupe::getListeEtudiants() const {
    return ListeEtudiants;
}

void Groupe::setListeEtudiants(const std::vector<Etudiant>& listeEtudiants) {
    ListeEtudiants = listeEtudiants;
}

void Groupe::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios_base::app); 
    if (file.is_open()) {
        file << getIdGRP() << "," << getNiveau() << "," << getDiplome() << "," << getSpecialite() << "," << getNumG() << ",";

        int i=0;
        for (const GroupeModule& module : getListeModules()) {
            if(i==0){
                file << module.getIdGM() ;
                i++;
            }
            else{
                file << ";" << module.getIdGM() ;
            }
        }

        file << ","; 
        i=0;
        for (const Etudiant& etudiant : getListeEtudiants()) {
            if(i==0){
                file << etudiant.getId() ;
                i++;
            }
            else{
                file << ";" << etudiant.getId() ;
            }
        }
        file << "\n";
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
    }
}

Groupe Groupe::readFromFile(const std::string& filename, const std::string& id) {
    std::ifstream
    file(filename); 
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idGRP;
            std::getline(iss, idGRP, ',');
            if (idGRP == id) {
                std::string niveau, diplome, specialite, numGStr;
                std::getline(iss, niveau, ',');
                std::getline(iss, diplome, ',');
                std::getline(iss, specialite, ',');
                std::getline(iss, numGStr, ',');
                int numG = std::stoi(numGStr);
                std::vector<GroupeModule> listeModules;
                std::vector<Etudiant> listeEtudiants;
                std::string modulesStr, etudiantsStr;
                std::getline(iss, modulesStr, ',');
                std::getline(iss, etudiantsStr, ',');
                std::istringstream modulesIss(modulesStr);
                std::string moduleID;
                while (std::getline(modulesIss, moduleID, ';')) {
                    GroupeModule module = GroupeModule().readFromFile("groupe_module.txt", moduleID);
                    listeModules.push_back(module);
                }
                std::istringstream etudiantsIss(etudiantsStr);
                std::string etudiantID;
                while (std::getline(etudiantsIss, etudiantID, ';')) {
                    Etudiant etudiant = Etudiant().readFromFile("etudiant.txt", std::stoi(etudiantID));
                    listeEtudiants.push_back(etudiant);
                }
                return Groupe(idGRP, niveau, diplome, specialite, numG, listeModules, listeEtudiants);
            }
        }
        file.close();
    } else {

        std::cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
    }
    return Groupe();
}

void Groupe::updateInFile(const std::string& filename) const
{
    std::ifstream file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        int id=1;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idGRP;
            std::getline(iss, idGRP, ',');
            if (idGRP == getIdGRP()) {
                temp << id << "," << getNiveau() << "," << getDiplome() << "," << getSpecialite() << "," << getNumG() << ",";

                int i=0;
        for (const GroupeModule& module : getListeModules()) {
            if(i==0){
                temp << module.getIdGM() ;
                i++;
            }
            else{
                temp << ";" << module.getIdGM() ;
            }
        }

        temp << ","; 
        i=0;
        for (const Etudiant& etudiant : getListeEtudiants()) {
            if(i==0){
                temp << etudiant.getId() ;
                i++;
            }
            else{
                temp << ";" << etudiant.getId() ;
            }
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

void Groupe::deleteFromFile(const std::string& filename, const std::string& id) {
    std::ifstream
    file(filename);
    std::ofstream temp("temp.txt");
    if (file.is_open() && temp.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string idGRP;
            std::getline(iss, idGRP, ',');
            if (idGRP != id) {
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

void Groupe::displayFormatted() const {
    std::cout << "|" << std::setw(10) << getIdGRP() << "|"
              << std::setw(10) << getNiveau() << "|"
              << std::setw(10) << getDiplome() << "|"
              << std::setw(10) << getSpecialite() << "|"
              << std::setw(6) << getNumG() << "|("; 

    int i= 0 ; 
    for (const GroupeModule& module : getListeModules()) {
        if (i == 0) {
            std::cout << module.getNomGM()  ;
            i++;
        }
        else {
            std::cout << "," << module.getNomGM()  ;
        }

    }
    std::cout << ")|(";
     i=0;
    for (const Etudiant& etudiant : getListeEtudiants()) {
        if (i == 0) {
            std::cout << etudiant.getNom() << " " << etudiant.getPrenom()  ;
            i++;
        }
        else {
            std::cout << "," << etudiant.getNom() << " " << etudiant.getPrenom() ;
        }
    }
    std::cout << ")|";

}