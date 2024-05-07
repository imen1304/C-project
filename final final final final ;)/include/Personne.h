#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>

class Personne {
private:
    int Id;
    std::string Nom;
    std::string Prenom;
    std::string Mail;

public:
    Personne();
    Personne(int id, const std::string& nom, const std::string& prenom, const std::string& mail);

    int getId() const;
    void setId(int id);

    std::string getNom() const;
    void setNom(const std::string& nom);

    std::string getPrenom() const;
    void setPrenom(const std::string& prenom);

    std::string getMail() const;
    void setMail(const std::string& mail);

};

#endif 