#ifndef TREATMENTQUEUE_H_
#define TREATMENTQUEUE_H_
#include <queue>
#include "Patient.h"
#include "DischargeQueue.h"
#include "WaitingRoomQueue.h"
#include "Caregiver.h"
#include "RandomsGenerator.h"
#include <iostream>

class TreatmentQueue {
    private:
        WaitingRoomQueue *waitingRoomQueue;
        DischargeQueue *dischargeQueue;
        TreatmentQueue *treatmentQueue;
        Caregiver *caregiver;
        std::queue<Patient *> queueOfDoctors;
        std::queue<Patient *> queueOfNurses;
        int start_treatment_time;
        int total_treatment_time;

    public:
        TreatmentQueue() {} //No-arg constructor

        //Getters
        int getTotalTreatmentTime()
        {
            return total_treatment_time; //returns the total amount of time it takes to treat a patient
        }

        int getStartTreatmentTime()
        {
            return start_treatment_time; //returns the start of the time of treatment for a patient
        }

        //Setters
        void setWaitingRoomQueue(WaitingRoomQueue *waitingRoomQueue)
        {
            this->waitingRoomQueue = waitingRoomQueue;
        }

        void setDischargeQueue(DischargeQueue *dischargeQueue)
        {
            this->dischargeQueue = dischargeQueue;
        }

        void setTotalTreatmentTime(int total_treatment_time)
        {
            this->total_treatment_time = total_treatment_time;
        }

        //Updating the functions for the nurses and doctors
        void update_doctor(int clock)
        {
            if (!queueOfDoctors.empty())
            {
                Patient *patient = queueOfDoctors.front(); //pointing patient object to the front of the patients queue
                if ( (clock - patient->start_treatment_time) > patient->total_treatment_time )
                {
                    queueOfDoctors.pop();
                    waitingRoomQueue->num_of_doctors++;
                    patient->discharge_time = clock - patient->start_treatment_time;
                    dischargeQueue->queueOfDoctors.push(patient);
                }
            }

            //bring patient into the treatment queue if queue of doctors is empty in the waiting room queue
            if (waitingRoomQueue->num_of_doctors > 0)
            {
                while (!waitingRoomQueue->queueOfDoctors.empty())
                {
                    Patient *patient = waitingRoomQueue->queueOfDoctors.front();
                    waitingRoomQueue->queueOfDoctors.pop();
                    waitingRoomQueue->num_of_doctors--;
                    patient->start_treatment_time = clock;
                    queueOfDoctors.push(patient);
                }
            }
        }

        void update_nurse(int clock)
        {
            if (!queueOfNurses.empty())
            {
                Patient *patient = queueOfNurses.front(); //points patient to the front of the patients queue
                if ( (clock - patient->start_treatment_time) > patient->total_treatment_time )
                {
                    queueOfNurses.pop();
                    waitingRoomQueue->num_of_nurses++;
                    patient->discharge_time = clock - patient->start_treatment_time;
                    dischargeQueue->queueOfNurses.push(patient);
                }
            }

            //Bringing patient in waiting room into the treatment queue
            if (waitingRoomQueue->num_of_doctors > 0)
            {
                while (!waitingRoomQueue->queueOfNurses.empty())
                {
                    Patient *patient = waitingRoomQueue->queueOfNurses.front();
                    waitingRoomQueue->queueOfNurses.pop();
                    waitingRoomQueue->num_of_nurses--;
                    patient->start_treatment_time = clock;
                    queueOfNurses.push(patient);
                }
            }
        }

        //Updating the clock
        void update(int clock)
        {
            update_doctor(clock);
            update_nurse(clock);
        }
};

#endif