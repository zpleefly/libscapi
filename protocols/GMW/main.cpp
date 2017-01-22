#include <iostream>
#include "Circuit.h"
#include "MPCCommunication.h"
#include "GMWParty.h"

int main(int argc, char* argv[]) {
    boost::asio::io_service io_service;
    shared_ptr<Circuit> circuit = make_shared<Circuit>();
    circuit->readCircuit(argv[2]);

    int id = atoi(argv[1]);
    auto parties = MPCCommunication::setCommunication(io_service, id, circuit->getNrOfParties(), argv[3]);
    cout << "----------end communication--------------" << endl;
    string tmp = "init times";
    byte tmpBytes[20];
    cout << "parties size : " <<parties.size() << endl;
    for (int i=0; i<parties.size(); i++){
        if (parties[i]->getID() < id){
            parties[i]->getChannel()->write(tmp);
            parties[i]->getChannel()->read(tmpBytes, tmp.size());
        } else {
            parties[i]->getChannel()->read(tmpBytes, tmp.size());
            parties[i]->getChannel()->write(tmp);
        }
    }
    int numThreads = atoi(argv[5]);
    cout << "num of threads : " << numThreads << endl;
    GMWParty party(id, circuit, parties, numThreads, argv[4]);
    cout << "----------start protocl--------------" << endl;
    party.run();

    cout << "----------finish protocl--------------" << endl;
    return 0;
}

