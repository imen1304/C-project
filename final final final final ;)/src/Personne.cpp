#include "../include/Personne.h"
#include <ostream>

Personne::Personne() : Id(0), Nom(""), Prenom(""), Mail("") {}

Personne::Personne(int id, const std::string& nom, const std::string& prenom, const std::string& mail) 
    : Id(id), Nom(nom), Prenom(prenom), Mail(mail) {}

int Personne::getId() const {
    return Id;
}

void Personne::setId(int id) {
    Id = id;
}

std::string Personne::getNom() const {
    return Nom;
}

void Personne::setNom(const std::string& nom) {
    Nom = nom;
}

std::string Personne::getPrenom() const {
    return Prenom;
}

void Personne::setPrenom(const std::string& prenom) {
    Prenom = prenom;
}

std::string Personne::getMail() const {
    return Mail;
}

void Personne::setMail(const std::string& mail) {
    Mail = mail;
}



