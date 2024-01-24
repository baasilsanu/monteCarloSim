#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;


int getRandomDoorOrInput(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 2);
    int random_number = distrib(gen);
    return random_number;
}


bool checkInput(int userInput, int answer){
    if(userInput == answer){
        return true;
    }
    else{
        return false;
    }
}

int openGoatDoorOrSwitch(int userInput, int answer){
    //if switch, pass the user input and goat door.
    int numbers[3] = {0, 1, 2};
    int known1 = userInput;
    int known2 = answer;

    for(int i = 0; i < 3; i++){
        if(numbers[i] != known1 && numbers[i] != known2){
            return numbers[i];
        }
    }
    return 0;
}

double calculateProability(int successes){
    return successes/10000.0;
}

int main(){
    cout << "Welcome to the Monty Hall problem simulator.\nHere we will run 10,000 iterations of the Monty Hall problem, with and without switching doors to see the better strategy. \n\n";
    int userSuccess = 0;
    int switchSuccess = 0;
    for(int i = 0; i < 10000; i++){
        int carDoor = getRandomDoorOrInput();
        // cout << carDoor << " Car\n" << endl;
        int userDoor = getRandomDoorOrInput();
        // cout << userDoor << " User\n" << endl;
        int goatDoor = openGoatDoorOrSwitch(userDoor, carDoor);
        int switchedUserDoor = openGoatDoorOrSwitch(userDoor, goatDoor);
        if(userDoor == carDoor){
            userSuccess++;
        }
        if(switchedUserDoor == carDoor){
            switchSuccess++;
        }
        
    }
    double userSuccessProbability = calculateProability(userSuccess);
    double switchSuccessProbability = calculateProability(switchSuccess);

    if(userSuccessProbability > switchSuccessProbability){
        cout << "Switching was not the right choice.\n\n" << "Probability for initial success was " << userSuccessProbability << "." << endl;
        cout << "Probability for win after switching was " << switchSuccessProbability << ".\n" << endl;
    }
    else{
        cout << "Switching was the right choice.\n\n" << "Probability for initial success was " << userSuccessProbability << endl;
        cout << "Probability for win after switching was " << switchSuccessProbability << ".\n" << endl;       
    }

    return 0;

    

}






