#ifndef ALLPATIENTS_H_
#define ALLPATIENTS_H_
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

class AllPatients {
    private:
        std::vector<std::string> firstNames;
        std::vector<std::string> lastNames;
    
    public:
        AllPatients() {} //No-arg constructor

        void addPeopleToVector()
        {
            //Opening the text files of 273ville
            std::ifstream firstNames("residents_of_273ville.txt");
            std::ifstream lastNames("surnames_of_273ville.txt");

            //If firstname files fail to open, show error message.
            if (firstNames.fail())
            {
                std::cout << "Sorry, cannot open the file." << std::endl;
                return;
            }

            //If latname files fail to open, show error message.
            if (lastNames.fail())
            {
                std::cout << "Sorry, cannot open the file" << std::endl;
                return;
            }

            //Push info from the text files into the vectors
            std::string row;
            std::string row2;
            while (std::getline(firstNames,row))
            {
                firstNames.push_back(row);
            }

            while (std::getline(lastNames, row))
            {
                lastNames.push_back(row2);
            }
        }

        //Getters (vectors)
        std::vector<std::string> getFirstVector()
        {
            return firstNames; //returns first names of patients
        }

        std::vector<std::string> getLastVector()
        {
            return lastNames; //returns last names of patients
        }

        //Setters (vectors)
        void setFirstVector(std::vector<std::string> firstNames)
        {
            this->firstNames = firstNames;
        }

        void setLastVector(std::vector<std::string> lastNames)
        {
            this->lastNames = lastNames;
        }

        friend class EmergencyRoom;
};

#endif