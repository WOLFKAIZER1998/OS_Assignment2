// Ryan Delos Reyes
// OS Programming Assignment 2
// DUE: 3/7/2024


#include <iostream>
#include <vector>
#include <random>

class Process {
public: 
    int id;
    int tickets;

    // Constructor of process class
    Process(int id, int tickets) : id(id), tickets(tickets) {}
};

class Scheduler {
public:
    // Vector of processes managed by scheduler
    std::vector<Process> processes;

    // Add a process to the vector
    void addProcess(Process process) {
        processes.push_back(process);
    }

    // Allocate tickets to a process
    void allocateTickets(Process& process, int tickets) {
        process.tickets = tickets;
    }

    // Select next process to run based on lottery scheduling algorithm
    // Loops through the processes and add tickets to the total
    Process selectNextProcess() {
        int totalTickets = 0;
        for (auto& process : processes) {
            totalTickets += process.tickets;
        }
        // Generate random numbers using rand()
        srand(time(0));
        int winningTicket = rand() % totalTickets + 1;
        int currentTicket = 0;

        // Loop through process again, add the process's tickets to current,
        // and if the current ticket number is >= winning ticket, then return process as winner
        for (auto& process : processes) {
            currentTicket += process.tickets;
            if (currentTicket >= winningTicket) {
                return process;
            }
        }
        // Return a dummy process in case of error
        return Process(-1, -1);
    }
};

int main() {
    // Creating Scheduler object
    Scheduler scheduler;

    // Create process objects with their respective id and the number of tickets
    Process process1(1, 10);
    Process process2(2, 20);
    Process process3(3, 30);

    // Add the processes to the scheduler
    scheduler.addProcess(process1);
    scheduler.addProcess(process2);
    scheduler.addProcess(process3);

    // Select next process to run using the lottery scheduling algorithm
    // Then print out the result
    Process nextProcess = scheduler.selectNextProcess();
    std::cout << "Process " << nextProcess.id << " wins the lottery!" << std::endl;

    return 0;
}

