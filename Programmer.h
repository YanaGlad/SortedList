//
// Created by y.gladkikh on 27.12.2021.
//

#ifndef MIREALAB1_PROGRAMMER_H
#define MIREALAB1_PROGRAMMER_H

//Программист задание 1.2
class Programmer {

public:
    std::string NOT_STATED = "not stated";
    std::string name,
            surname,
            email = NOT_STATED,
            skype = NOT_STATED,
            telegram = NOT_STATED,
            currentWorkPlace = NOT_STATED,
            mainDevLang;
    int level;

    Programmer(std::string name, std::string surname, std::string mainDevLang, int level) {
        this->name = name;
        this->surname = surname;
        this->mainDevLang = mainDevLang;
        this->level = level;
    }
    Programmer(){

    }

    Programmer(std::string name, std::string surname, std::string mainDevLang,
               std::string email, std::string skype, std::string telegram,
               std::string currentWorkPlace, int level) {
        this->name = name;
        this->surname = surname;
        this->mainDevLang = mainDevLang;
        this->email = email;
        this->skype = skype;
        this->telegram = telegram;
        this->currentWorkPlace = currentWorkPlace;
        this->level = level;
    }

};

#endif //MIREALAB1_PROGRAMMER_H
