#include <iostream>
using namespace std;

int main() {
    int murVisitedBoilerRoom = 1, murVisitedCargoHold = 0, murVisitedThirdClass = 0,
        murVisitedDiningSaloon = 0, murVisitedPromenadeDeck = 0, murVisitedBridge = 0,
        murVisitedLifeboatDeck = 0, murVisitedCrowsNest = 0;

    int maryVisitedBoilerRoom = 1, maryVisitedCargoHold = 0, maryVisitedThirdClass = 0,
        maryVisitedDiningSaloon = 0, maryVisitedPromenadeDeck = 0, maryVisitedBridge = 0,
        maryVisitedLifeboatDeck = 0, maryVisitedCrowsNest = 0;

    int murCurrent = 0, maryCurrent = 0;
    int murNext, murFlood, murFrozen = 0, murStuck;
    int murC1, murC2, murC3;
    int murLead1, murLead2;
    int maryNext, maryFlood, maryFrozen = 0;
    int maryC1, maryC2, maryC3;

    int murP1 = -1, murP2 = -1, murP3 = -1, murP4 = -1, murP5 = -1, murP6 = -1;
    int maryP1 = -1, maryP2 = -1, maryP3 = -1, maryP4 = -1, maryP5 = -1, maryP6 = -1;

    cout << "===== Women and Children First =====" << endl;
    switch (murFrozen) {
    case 0:
        murNext = murCurrent; murFlood = 0; murStuck = 0;
        switch (murCurrent) {
        case 2: switch (murVisitedBridge) { case 0: cout << "Murdoch (Move 1): WaterRising" << endl; murNext = 5; murFlood = 1; break; } break;
        }
        switch (murFlood) {
        case 0:
            switch (murCurrent) { case 0: murC1 = 1; murC2 = 2; murC3 = -1; break; }
            switch (murCurrent) {
            case 0:
                switch (murVisitedCargoHold) {
                case 0: murNext = murC1; break;
                case 1: switch (murVisitedThirdClass) { case 0: murNext = murC2; break; } break;
                }
                break;
            }
            break;
        }
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break; case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break; case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break; case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break; case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) { case 0: murP1 = murCurrent; break; }
        switch (murCurrent) { case 6: cout << "Murdoch (Move 1): Rescued" << endl; murFrozen = 1; break; }
        switch (murCurrent) {
        case 7: switch (murVisitedDiningSaloon) { case 1: cout << "Murdoch (Move 1): DoorSealed" << endl; murVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (murFrozen) {
    case 0:
        murNext = murCurrent; murFlood = 0; murStuck = 0;
        switch (murCurrent) {
        case 2: switch (murVisitedBridge) { case 0: cout << "Murdoch (Move 2): WaterRising" << endl; murNext = 5; murFlood = 1; break; } break;
        }
        switch (murFlood) {
        case 0:
            switch (murCurrent) { case 1: murC1 = 0; murC2 = 3; murC3 = 4; break; }
            switch (murCurrent) {
            case 1:
                switch (murVisitedBoilerRoom) {
                case 0: murNext = murC1; break;
                case 1:
                    switch (murVisitedDiningSaloon) {
                    case 0: murNext = murC2; break;
                    case 1: switch (murVisitedPromenadeDeck) { case 0: murNext = murC3; break; } break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break; case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break; case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break; case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break; case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) { case 0: murP2 = murCurrent; break; }
        switch (murCurrent) { case 6: cout << "Murdoch (Move 2): Rescued" << endl; murFrozen = 1; break; }
        switch (murCurrent) {
        case 7: switch (murVisitedDiningSaloon) { case 1: cout << "Murdoch (Move 2): DoorSealed" << endl; murVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (murFrozen) {
    case 0:
        murNext = murCurrent; murFlood = 0; murStuck = 0;
        switch (murCurrent) {
        case 2: switch (murVisitedBridge) { case 0: cout << "Murdoch (Move 3): WaterRising" << endl; murNext = 5; murFlood = 1; break; } break;
        }
        switch (murFlood) {
        case 0:
            switch (murCurrent) { case 3: murC1 = 1; murC2 = 7; murC3 = -1; break; }
            switch (murCurrent) {
            case 3:
                switch (murVisitedCargoHold) {
                case 0: murNext = murC1; break;
                case 1: switch (murVisitedCrowsNest) { case 0: murNext = murC2; break; } break;
                }
                break;
            }
            break;
        }
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break; case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break; case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break; case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break; case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) { case 0: murP3 = murCurrent; break; }
        switch (murCurrent) { case 6: cout << "Murdoch (Move 3): Rescued" << endl; murFrozen = 1; break; }
        switch (murCurrent) {
        case 7: switch (murVisitedDiningSaloon) { case 1: cout << "Murdoch (Move 3): DoorSealed" << endl; murVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (murFrozen) {
    case 0:
        murNext = murCurrent; murFlood = 0; murStuck = 0;
        switch (murCurrent) {
        case 2: switch (murVisitedBridge) { case 0: cout << "Murdoch (Move 4): WaterRising" << endl; murNext = 5; murFlood = 1; break; } break;
        }
        switch (murFlood) {
        case 0:
            switch (murCurrent) { case 7: murC1 = 3; murC2 = 4; murC3 = -1; break; }
            switch (murCurrent) {
            case 7:
                switch (murVisitedDiningSaloon) {
                case 0: murNext = murC1; break;
                case 1: switch (murVisitedPromenadeDeck) { case 0: murNext = murC2; break; } break;
                }
                break;
            }
            break;
        }
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break; case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break; case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break; case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break; case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) { case 0: murP4 = murCurrent; break; }
        switch (murCurrent) { case 6: cout << "Murdoch (Move 4): Rescued" << endl; murFrozen = 1; break; }
        switch (murCurrent) {
        case 7: switch (murVisitedDiningSaloon) { case 1: cout << "Murdoch (Move 4): DoorSealed" << endl; murVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (murFrozen) {
    case 0:
        murNext = murCurrent; murFlood = 0; murStuck = 0;
        switch (murCurrent) {
        case 2: switch (murVisitedBridge) { case 0: cout << "Murdoch (Move 5): WaterRising" << endl; murNext = 5; murFlood = 1; break; } break;
        }
        switch (murFlood) {
        case 0:
            switch (murCurrent) { case 3: murC1 = 1; murC2 = 7; murC3 = -1; break; }
            switch (murCurrent) {
            case 3:
                switch (murVisitedCargoHold) {
                case 0: murNext = murC1; break;
                case 1:
                    switch (murVisitedCrowsNest) {
                    case 0: murNext = murC2; break;
                    case 1:
                        cout << "Murdoch (Move 5): TurnBack" << endl;
                        murLead1 = 0;
                        switch (murVisitedBoilerRoom) {
                        case 0: murLead1 = 1; break;
                        case 1:
                            switch (murVisitedDiningSaloon) {
                            case 0: murLead1 = 1; break;
                            case 1: switch (murVisitedPromenadeDeck) { case 0: murLead1 = 1; break; } break;
                            }
                            break;
                        }
                        murLead2 = 0;
                        switch (murVisitedDiningSaloon) {
                        case 0: murLead2 = 1; break;
                        case 1: switch (murVisitedPromenadeDeck) { case 0: murLead2 = 1; break; } break;
                        }
                        murStuck = 1;
                        switch (murLead1) {
                        case 1: murNext = murC1; murStuck = 0; break;
                        case 0: switch (murLead2) { case 1: murNext = murC2; murStuck = 0; break; } break;
                        }
                        switch (murStuck) {
                        case 1: cout << "Murdoch (Move 5): Trapped" << endl; murFrozen = 1; break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break; case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break; case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break; case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break; case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) { case 0: murP5 = murCurrent; break; }
        switch (murCurrent) { case 6: cout << "Murdoch (Move 5): Rescued" << endl; murFrozen = 1; break; }
        switch (murCurrent) {
        case 7: switch (murVisitedDiningSaloon) { case 1: cout << "Murdoch (Move 5): DoorSealed" << endl; murVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (murFrozen) {
    case 0:
        murNext = murCurrent; murFlood = 0; murStuck = 0;
        switch (murCurrent) {
        case 2: switch (murVisitedBridge) { case 0: cout << "Murdoch (Move 6): WaterRising" << endl; murNext = 5; murFlood = 1; break; } break;
        }
        switch (murFlood) {
        case 0:
            switch (murCurrent) { case 1: murC1 = 0; murC2 = 3; murC3 = 4; break; }
            switch (murCurrent) {
            case 1:
                switch (murVisitedBoilerRoom) {
                case 0: murNext = murC1; break;
                case 1:
                    switch (murVisitedDiningSaloon) {
                    case 0: murNext = murC2; break;
                    case 1: switch (murVisitedPromenadeDeck) { case 0: murNext = murC3; break; } break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break; case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break; case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break; case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break; case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) { case 0: murP6 = murCurrent; break; }
        switch (murCurrent) { case 6: cout << "Murdoch (Move 6): Rescued" << endl; murFrozen = 1; break; }
        switch (murCurrent) {
        case 7: switch (murVisitedDiningSaloon) { case 1: cout << "Murdoch (Move 6): DoorSealed" << endl; murVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent; maryFlood = 0;
        switch (maryCurrent) {
        case 2: switch (maryVisitedBridge) { case 0: cout << "Mary (Move 1): WaterRising" << endl; maryNext = 5; maryFlood = 1; break; } break;
        }
        switch (maryFlood) {
        case 0:
            switch (maryCurrent) { case 0: maryC1 = 1; maryC2 = 2; maryC3 = -1; break; }
            switch (maryCurrent) {
            case 0:
                switch (maryVisitedCargoHold) {
                case 0: maryNext = maryC1; break;
                case 1: switch (maryVisitedThirdClass) { case 0: maryNext = maryC2; break; case 1: maryNext = maryC1; break; } break;
                }
                break;
            }
            break;
        }
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break; case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break; case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break; case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break; case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext; maryP1 = maryCurrent;
        switch (maryCurrent) { case 6: cout << "Mary (Move 1): Rescued" << endl; maryFrozen = 1; break; }
        switch (maryCurrent) {
        case 7: switch (maryVisitedDiningSaloon) { case 1: cout << "Mary (Move 1): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent; maryFlood = 0;
        switch (maryCurrent) {
        case 2: switch (maryVisitedBridge) { case 0: cout << "Mary (Move 2): WaterRising" << endl; maryNext = 5; maryFlood = 1; break; } break;
        }
        switch (maryFlood) {
        case 0:
            switch (maryCurrent) { case 1: maryC1 = 0; maryC2 = 3; maryC3 = 4; break; }
            switch (maryCurrent) {
            case 1:
                switch (maryVisitedThirdClass) {
                case 0: maryNext = maryC1; break;  
                case 1:
                    switch (maryVisitedDiningSaloon) {
                    case 0: maryNext = maryC2; break;
                    case 1: switch (maryVisitedPromenadeDeck) { case 0: maryNext = maryC3; break; case 1: maryNext = maryC1; break; } break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break; case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break; case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break; case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break; case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext; maryP2 = maryCurrent;
        switch (maryCurrent) { case 6: cout << "Mary (Move 2): Rescued" << endl; maryFrozen = 1; break; }
        switch (maryCurrent) {
        case 7: switch (maryVisitedDiningSaloon) { case 1: cout << "Mary (Move 2): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent; maryFlood = 0;
        switch (maryCurrent) {
        case 2: switch (maryVisitedBridge) { case 0: cout << "Mary (Move 3): WaterRising" << endl; maryNext = 5; maryFlood = 1; break; } break;
        }
        switch (maryFlood) {
        case 0:
            switch (maryCurrent) { case 0: maryC1 = 1; maryC2 = 2; maryC3 = -1; break; }
            switch (maryCurrent) {
            case 0:
                switch (maryVisitedCargoHold) {
                case 0: maryNext = maryC1; break;
                case 1: switch (maryVisitedThirdClass) { case 0: maryNext = maryC2; break; case 1: maryNext = maryC1; break; } break;
                }
                break;
            }
            break;
        }
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break; case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break; case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break; case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break; case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext; maryP3 = maryCurrent;
        switch (maryCurrent) { case 6: cout << "Mary (Move 3): Rescued" << endl; maryFrozen = 1; break; }
        switch (maryCurrent) {
        case 7: switch (maryVisitedDiningSaloon) { case 1: cout << "Mary (Move 3): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent; maryFlood = 0;
        switch (maryCurrent) {
        case 2: switch (maryVisitedBridge) { case 0: cout << "Mary (Move 4): WaterRising" << endl; maryNext = 5; maryFlood = 1; break; } break;
        }
        switch (maryFlood) {
        case 0:
            switch (maryCurrent) { case 2: maryC1 = 0; maryC2 = 5; maryC3 = 6; break; }
            switch (maryCurrent) {
            case 2:
                switch (maryVisitedBridge) {
                case 0: maryNext = maryC2; break;
                case 1: switch (maryVisitedLifeboatDeck) { case 0: maryNext = maryC3; break; case 1: maryNext = maryC1; break; } break;
                }
                break;
            }
            break;
        }
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break; case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break; case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break; case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break; case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext; maryP4 = maryCurrent;
        switch (maryCurrent) { case 6: cout << "Mary (Move 4): Rescued" << endl; maryFrozen = 1; break; }
        switch (maryCurrent) {
        case 7: switch (maryVisitedDiningSaloon) { case 1: cout << "Mary (Move 4): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent; maryFlood = 0;
        switch (maryCurrent) {
        case 2: switch (maryVisitedBridge) { case 0: cout << "Mary (Move 5): WaterRising" << endl; maryNext = 5; maryFlood = 1; break; } break;
        }
        switch (maryFlood) {
        case 0:
            switch (maryCurrent) { case 5: maryC1 = 2; maryC2 = 6; maryC3 = 7; break; }
            switch (maryCurrent) {
            case 5:
                switch (maryVisitedLifeboatDeck) {
                case 0: maryNext = maryC2; break;
                case 1:
                    switch (maryVisitedDiningSaloon) {
                    case 0: maryNext = maryC1; break;
                    case 1:
                        switch (maryVisitedPromenadeDeck) {
                        case 0: maryNext = maryC1; break;
                        case 1: switch (maryVisitedCrowsNest) { case 0: maryNext = maryC3; break; case 1: maryNext = maryC1; break; } break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break; case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break; case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break; case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break; case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext; maryP5 = maryCurrent;
        switch (maryCurrent) { case 6: cout << "Mary (Move 5): Rescued" << endl; maryFrozen = 1; break; }
        switch (maryCurrent) {
        case 7: switch (maryVisitedDiningSaloon) { case 1: cout << "Mary (Move 5): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break; } break;
        }
        break;
    }
    switch (maryFrozen) {
    case 1: break;
    }
    cout << endl << "Murdoch path: Boiler Room";
    switch (murP1) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP2) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP3) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP4) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP5) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP6) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    cout << endl;

    cout << "Mary path: Boiler Room";
    switch (maryP1) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP2) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP3) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP4) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP5) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP6) {
    case 0: cout << " -> Boiler Room"; break; case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break; case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break; case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break; case 7: cout << " -> Crow's Nest"; break;
    }
    cout << endl;
    return 0;
}