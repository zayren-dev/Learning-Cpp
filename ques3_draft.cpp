#include <iostream>
using namespace std;

int main() {
    // ===== Murdoch ke 8 visited flags (0 = unvisited, 1 = visited) =====
    int murVisitedBoilerRoom = 0;
    int murVisitedCargoHold = 0;
    int murVisitedThirdClass = 0;
    int murVisitedDiningSaloon = 0;
    int murVisitedPromenadeDeck = 0;
    int murVisitedBridge = 0;
    int murVisitedLifeboatDeck = 0;
    int murVisitedCrowsNest = 0;

    // ===== Mary ke 8 visited flags =====
    int maryVisitedBoilerRoom = 0;
    int maryVisitedCargoHold = 0;
    int maryVisitedThirdClass = 0;
    int maryVisitedDiningSaloon = 0;
    int maryVisitedPromenadeDeck = 0;
    int maryVisitedBridge = 0;
    int maryVisitedLifeboatDeck = 0;
    int maryVisitedCrowsNest = 0;

    // current deck (dono Boiler Room = 0 se shuru)
    int murCurrent = 0, maryCurrent = 0;

    // helper variables: next = agla deck, flood = rule 1 chala (1 = haan), frozen = rescued ya trapped (1 = haan)
    // C1,C2,C3 = rule 2 ke corridors (-1 = koi nahi), Lead = visited deck se naya rasta milta hai (1 = haan)
    int murNext = 0, murFlood = 0, murFrozen = 0, murStuck = 0;
    int murC1 = -1, murC2 = -1, murC3 = -1;
    int murLead1 = 0, murLead2 = 0, murLead3 = 0;
    int maryNext = 0, maryFlood = 0, maryFrozen = 0;
    int maryC1 = -1, maryC2 = -1, maryC3 = -1;

    // path ke liye: P1..P6 = har move ke baad ka deck (-1 = move nahi hui)
    int murP1 = -1, murP2 = -1, murP3 = -1, murP4 = -1, murP5 = -1, murP6 = -1;
    int maryP1 = -1, maryP2 = -1, maryP3 = -1, maryP4 = -1, maryP5 = -1, maryP6 = -1;

    // Boiler Room se dono shuru karte hain, to wo jagah pehle se visited maani gayi hai
    murVisitedBoilerRoom = 1;
    maryVisitedBoilerRoom = 1;

    cout << "===== Women and Children First =====" << endl;

    // ================= MURDOCH : MOVE 1 =================
    switch (murFrozen) {
    case 0:
        murNext = murCurrent;     // by default wahin rahe
        murFlood = 0;
        murStuck = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (murCurrent) {
        case 2:
            switch (murVisitedBridge) {
            case 0: cout << "Murdoch (Move 1): WaterRising" << endl; murNext = 5; murFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (murFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (murCurrent) {
            case 0: murC1 = 1; murC2 = 2; murC3 = -1; break;     // Boiler Room
            }
            // Rule 3: agla deck chuno
            switch (murCurrent) {
            case 0:     // Boiler Room
                switch (murVisitedCargoHold) {
                case 0: murNext = murC1; break;     // Cargo Hold unvisited hai, isi par jao
                case 1:
                    switch (murVisitedThirdClass) {
                    case 0: murNext = murC2; break;     // Third Class unvisited hai, isi par jao
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break;
        case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break;
        case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break;
        case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break;
        case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) {
        case 0: murP1 = murCurrent; break;     // path mein add
        }

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (murCurrent) {
        case 6: cout << "Murdoch (Move 1): Rescued" << endl; murFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (murCurrent) {
        case 7:
            switch (murVisitedDiningSaloon) {
            case 1: cout << "Murdoch (Move 1): DoorSealed" << endl; murVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MURDOCH : MOVE 2 =================
    switch (murFrozen) {
    case 0:
        murNext = murCurrent;     // by default wahin rahe
        murFlood = 0;
        murStuck = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (murCurrent) {
        case 2:
            switch (murVisitedBridge) {
            case 0: cout << "Murdoch (Move 2): WaterRising" << endl; murNext = 5; murFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (murFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (murCurrent) {
            case 1: murC1 = 0; murC2 = 3; murC3 = 4; break;     // Cargo Hold
            }
            // Rule 3: agla deck chuno
            switch (murCurrent) {
            case 1:     // Cargo Hold
                switch (murVisitedBoilerRoom) {
                case 0: murNext = murC1; break;     // Boiler Room unvisited hai, isi par jao
                case 1:
                    switch (murVisitedDiningSaloon) {
                    case 0: murNext = murC2; break;     // Dining Saloon unvisited hai, isi par jao
                    case 1:
                        switch (murVisitedPromenadeDeck) {
                        case 0: murNext = murC3; break;     // Promenade Deck unvisited hai, isi par jao
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break;
        case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break;
        case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break;
        case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break;
        case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) {
        case 0: murP2 = murCurrent; break;     // path mein add
        }

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (murCurrent) {
        case 6: cout << "Murdoch (Move 2): Rescued" << endl; murFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (murCurrent) {
        case 7:
            switch (murVisitedDiningSaloon) {
            case 1: cout << "Murdoch (Move 2): DoorSealed" << endl; murVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MURDOCH : MOVE 3 =================
    switch (murFrozen) {
    case 0:
        murNext = murCurrent;     // by default wahin rahe
        murFlood = 0;
        murStuck = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (murCurrent) {
        case 2:
            switch (murVisitedBridge) {
            case 0: cout << "Murdoch (Move 3): WaterRising" << endl; murNext = 5; murFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (murFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (murCurrent) {
            case 3: murC1 = 1; murC2 = 7; murC3 = -1; break;     // Dining Saloon
            }
            // Rule 3: agla deck chuno
            switch (murCurrent) {
            case 3:     // Dining Saloon
                switch (murVisitedCargoHold) {
                case 0: murNext = murC1; break;     // Cargo Hold unvisited hai, isi par jao
                case 1:
                    switch (murVisitedCrowsNest) {
                    case 0: murNext = murC2; break;     // Crow's Nest unvisited hai, isi par jao
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break;
        case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break;
        case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break;
        case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break;
        case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) {
        case 0: murP3 = murCurrent; break;     // path mein add
        }

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (murCurrent) {
        case 6: cout << "Murdoch (Move 3): Rescued" << endl; murFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (murCurrent) {
        case 7:
            switch (murVisitedDiningSaloon) {
            case 1: cout << "Murdoch (Move 3): DoorSealed" << endl; murVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MURDOCH : MOVE 4 =================
    switch (murFrozen) {
    case 0:
        murNext = murCurrent;     // by default wahin rahe
        murFlood = 0;
        murStuck = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (murCurrent) {
        case 2:
            switch (murVisitedBridge) {
            case 0: cout << "Murdoch (Move 4): WaterRising" << endl; murNext = 5; murFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (murFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (murCurrent) {
            case 7: murC1 = 3; murC2 = 4; murC3 = -1; break;     // Crow's Nest
            }
            // Rule 3: agla deck chuno
            switch (murCurrent) {
            case 7:     // Crow's Nest
                switch (murVisitedDiningSaloon) {
                case 0: murNext = murC1; break;     // Dining Saloon unvisited hai, isi par jao
                case 1:
                    switch (murVisitedPromenadeDeck) {
                    case 0: murNext = murC2; break;     // Promenade Deck unvisited hai, isi par jao
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break;
        case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break;
        case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break;
        case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break;
        case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) {
        case 0: murP4 = murCurrent; break;     // path mein add
        }

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (murCurrent) {
        case 6: cout << "Murdoch (Move 4): Rescued" << endl; murFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (murCurrent) {
        case 7:
            switch (murVisitedDiningSaloon) {
            case 1: cout << "Murdoch (Move 4): DoorSealed" << endl; murVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MURDOCH : MOVE 5 =================
    switch (murFrozen) {
    case 0:
        murNext = murCurrent;     // by default wahin rahe
        murFlood = 0;
        murStuck = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (murCurrent) {
        case 2:
            switch (murVisitedBridge) {
            case 0: cout << "Murdoch (Move 5): WaterRising" << endl; murNext = 5; murFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (murFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (murCurrent) {
            case 3: murC1 = 1; murC2 = 7; murC3 = -1; break;     // Dining Saloon
            }
            // Rule 3: agla deck chuno
            switch (murCurrent) {
            case 3:     // Dining Saloon
                switch (murVisitedCargoHold) {
                case 0: murNext = murC1; break;     // Cargo Hold unvisited hai, isi par jao
                case 1:
                    switch (murVisitedCrowsNest) {
                    case 0: murNext = murC2; break;     // Crow's Nest unvisited hai, isi par jao
                    case 1:
                        cout << "Murdoch (Move 5): TurnBack" << endl;
                        // ab dekhte hain kaun sa visited padosi deck abhi bhi naya rasta de sakta hai (1 = haan, 0 = nahi)
                        // padosi 1: Cargo Hold (1)
                        murLead1 = 0;
                        switch (murVisitedBoilerRoom) {
                        case 0: murLead1 = 1; break;
                        case 1:
                            switch (murVisitedDiningSaloon) {
                            case 0: murLead1 = 1; break;
                            case 1:
                                switch (murVisitedPromenadeDeck) {
                                case 0: murLead1 = 1; break;
                                }
                                break;
                            }
                            break;
                        }
                        // padosi 2: Crow's Nest (7)
                        murLead2 = 0;
                        switch (murVisitedDiningSaloon) {
                        case 0: murLead2 = 1; break;
                        case 1:
                            switch (murVisitedPromenadeDeck) {
                            case 0: murLead2 = 1; break;
                            }
                            break;
                        }
                        murStuck = 1;      // pehle maan lo koi nahi mila
                        switch (murLead1) {
                        case 1: murNext = murC1; murStuck = 0; break;
                        case 0:
                            switch (murLead2) {
                            case 1: murNext = murC2; murStuck = 0; break;
                            case 0: break;
                            }
                            break;
                        }
                        switch (murStuck) {
                        case 1:
                            cout << "Murdoch (Move 5): Trapped" << endl;
                            murFrozen = 1;     // ab baqi saari moves mein wahin ruka rahega
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break;
        case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break;
        case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break;
        case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break;
        case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) {
        case 0: murP5 = murCurrent; break;     // path mein add
        }

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (murCurrent) {
        case 6: cout << "Murdoch (Move 5): Rescued" << endl; murFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (murCurrent) {
        case 7:
            switch (murVisitedDiningSaloon) {
            case 1: cout << "Murdoch (Move 5): DoorSealed" << endl; murVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MURDOCH : MOVE 6 =================
    switch (murFrozen) {
    case 0:
        murNext = murCurrent;     // by default wahin rahe
        murFlood = 0;
        murStuck = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (murCurrent) {
        case 2:
            switch (murVisitedBridge) {
            case 0: cout << "Murdoch (Move 6): WaterRising" << endl; murNext = 5; murFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (murFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (murCurrent) {
            case 1: murC1 = 0; murC2 = 3; murC3 = 4; break;     // Cargo Hold
            }
            // Rule 3: agla deck chuno
            switch (murCurrent) {
            case 1:     // Cargo Hold
                switch (murVisitedBoilerRoom) {
                case 0: murNext = murC1; break;     // Boiler Room unvisited hai, isi par jao
                case 1:
                    switch (murVisitedDiningSaloon) {
                    case 0: murNext = murC2; break;     // Dining Saloon unvisited hai, isi par jao
                    case 1:
                        switch (murVisitedPromenadeDeck) {
                        case 0: murNext = murC3; break;     // Promenade Deck unvisited hai, isi par jao
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (murNext) {
        case 0: murVisitedBoilerRoom = 1; break;
        case 1: murVisitedCargoHold = 1; break;
        case 2: murVisitedThirdClass = 1; break;
        case 3: murVisitedDiningSaloon = 1; break;
        case 4: murVisitedPromenadeDeck = 1; break;
        case 5: murVisitedBridge = 1; break;
        case 6: murVisitedLifeboatDeck = 1; break;
        case 7: murVisitedCrowsNest = 1; break;
        }
        murCurrent = murNext;
        switch (murStuck) {
        case 0: murP6 = murCurrent; break;     // path mein add
        }

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (murCurrent) {
        case 6: cout << "Murdoch (Move 6): Rescued" << endl; murFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (murCurrent) {
        case 7:
            switch (murVisitedDiningSaloon) {
            case 1: cout << "Murdoch (Move 6): DoorSealed" << endl; murVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MARY : MOVE 1 =================
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent;     // by default wahin rahe
        maryFlood = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (maryCurrent) {
        case 2:
            switch (maryVisitedBridge) {
            case 0: cout << "Mary (Move 1): WaterRising" << endl; maryNext = 5; maryFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (maryFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (maryCurrent) {
            case 0: maryC1 = 1; maryC2 = 2; maryC3 = -1; break;     // Boiler Room
            }
            // Rule 3: agla deck chuno
            switch (maryCurrent) {
            case 0:     // Boiler Room
                switch (maryVisitedCargoHold) {
                case 0: maryNext = maryC1; break;     // Cargo Hold pehle
                case 1:
                    switch (maryVisitedThirdClass) {
                    case 0: maryNext = maryC2; break;     // phir Third Class
                    case 1: maryNext = maryC1; break;     // dono dekh li, ab aage barho
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break;
        case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break;
        case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break;
        case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break;
        case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext;
        maryP1 = maryCurrent;     // path mein add

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (maryCurrent) {
        case 6: cout << "Mary (Move 1): Rescued" << endl; maryFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (maryCurrent) {
        case 7:
            switch (maryVisitedDiningSaloon) {
            case 1: cout << "Mary (Move 1): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MARY : MOVE 2 =================
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent;     // by default wahin rahe
        maryFlood = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (maryCurrent) {
        case 2:
            switch (maryVisitedBridge) {
            case 0: cout << "Mary (Move 2): WaterRising" << endl; maryNext = 5; maryFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (maryFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (maryCurrent) {
            case 1: maryC1 = 0; maryC2 = 3; maryC3 = 4; break;     // Cargo Hold
            }
            // Rule 3: agla deck chuno
            switch (maryCurrent) {
            case 1:     // Cargo Hold
                switch (maryVisitedThirdClass) {
                case 0: maryNext = maryC1; break;     // Third Class (1 corridor door) abhi baaki hai, aage mat jao, wapas Boiler Room
                case 1:
                    switch (maryVisitedDiningSaloon) {
                    case 0: maryNext = maryC2; break;     // Dining Saloon
                    case 1:
                        switch (maryVisitedPromenadeDeck) {
                        case 0: maryNext = maryC3; break;     // Promenade Deck
                        case 1: maryNext = maryC1; break;     // yahan sab ho gaya, wapas
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break;
        case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break;
        case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break;
        case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break;
        case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext;
        maryP2 = maryCurrent;     // path mein add

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (maryCurrent) {
        case 6: cout << "Mary (Move 2): Rescued" << endl; maryFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (maryCurrent) {
        case 7:
            switch (maryVisitedDiningSaloon) {
            case 1: cout << "Mary (Move 2): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MARY : MOVE 3 =================
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent;     // by default wahin rahe
        maryFlood = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (maryCurrent) {
        case 2:
            switch (maryVisitedBridge) {
            case 0: cout << "Mary (Move 3): WaterRising" << endl; maryNext = 5; maryFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (maryFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (maryCurrent) {
            case 0: maryC1 = 1; maryC2 = 2; maryC3 = -1; break;     // Boiler Room
            }
            // Rule 3: agla deck chuno
            switch (maryCurrent) {
            case 0:     // Boiler Room
                switch (maryVisitedCargoHold) {
                case 0: maryNext = maryC1; break;     // Cargo Hold pehle
                case 1:
                    switch (maryVisitedThirdClass) {
                    case 0: maryNext = maryC2; break;     // phir Third Class
                    case 1: maryNext = maryC1; break;     // dono dekh li, ab aage barho
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break;
        case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break;
        case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break;
        case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break;
        case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext;
        maryP3 = maryCurrent;     // path mein add

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (maryCurrent) {
        case 6: cout << "Mary (Move 3): Rescued" << endl; maryFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (maryCurrent) {
        case 7:
            switch (maryVisitedDiningSaloon) {
            case 1: cout << "Mary (Move 3): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MARY : MOVE 4 =================
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent;     // by default wahin rahe
        maryFlood = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (maryCurrent) {
        case 2:
            switch (maryVisitedBridge) {
            case 0: cout << "Mary (Move 4): WaterRising" << endl; maryNext = 5; maryFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (maryFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (maryCurrent) {
            case 2: maryC1 = 0; maryC2 = 5; maryC3 = 6; break;     // Third Class
            }
            // Rule 3: agla deck chuno
            switch (maryCurrent) {
            case 2:     // Third Class
                switch (maryVisitedBridge) {
                case 0: maryNext = maryC2; break;     // Bridge
                case 1:
                    switch (maryVisitedLifeboatDeck) {
                    case 0: maryNext = maryC3; break;     // Lifeboat Deck
                    case 1: maryNext = maryC1; break;     // wapas Boiler Room
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break;
        case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break;
        case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break;
        case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break;
        case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext;
        maryP4 = maryCurrent;     // path mein add

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (maryCurrent) {
        case 6: cout << "Mary (Move 4): Rescued" << endl; maryFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (maryCurrent) {
        case 7:
            switch (maryVisitedDiningSaloon) {
            case 1: cout << "Mary (Move 4): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MARY : MOVE 5 =================
    switch (maryFrozen) {
    case 0:
        maryNext = maryCurrent;     // by default wahin rahe
        maryFlood = 0;

        // Rule 1: Flooding (Third Class par ho aur Bridge visit nahi hui to seedha Bridge)
        switch (maryCurrent) {
        case 2:
            switch (maryVisitedBridge) {
            case 0: cout << "Mary (Move 5): WaterRising" << endl; maryNext = 5; maryFlood = 1; break;     // seedha Bridge, rule 2 aur 3 skip
            }
            break;
        }

        switch (maryFlood) {
        case 0:
            // Rule 2: corridors ki list (legal connections)
            switch (maryCurrent) {
            case 5: maryC1 = 2; maryC2 = 6; maryC3 = 7; break;     // Bridge
            }
            // Rule 3: agla deck chuno
            switch (maryCurrent) {
            case 5:     // Bridge
                switch (maryVisitedLifeboatDeck) {
                case 0: maryNext = maryC2; break;     // Lifeboat Deck (2 corridor door, qareeb wala pehle)
                case 1:
                    switch (maryVisitedDiningSaloon) {
                    case 0: maryNext = maryC1; break;     // Dining Saloon baaki hai, wapas Third Class se jao
                    case 1:
                        switch (maryVisitedPromenadeDeck) {
                        case 0: maryNext = maryC1; break;     // Promenade Deck baaki hai, wapas
                        case 1:
                            switch (maryVisitedCrowsNest) {
                            case 0: maryNext = maryC3; break;     // Crow's Nest (sab qareeb wale ho gaye)
                            case 1: maryNext = maryC1; break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }

        // naye deck ka visited flag update + current update
        switch (maryNext) {
        case 0: maryVisitedBoilerRoom = 1; break;
        case 1: maryVisitedCargoHold = 1; break;
        case 2: maryVisitedThirdClass = 1; break;
        case 3: maryVisitedDiningSaloon = 1; break;
        case 4: maryVisitedPromenadeDeck = 1; break;
        case 5: maryVisitedBridge = 1; break;
        case 6: maryVisitedLifeboatDeck = 1; break;
        case 7: maryVisitedCrowsNest = 1; break;
        }
        maryCurrent = maryNext;
        maryP5 = maryCurrent;     // path mein add

        // Rule 4: Lifeboat Deck par pohanch gaye (Rescued check)
        switch (maryCurrent) {
        case 6: cout << "Mary (Move 5): Rescued" << endl; maryFrozen = 1; break;
        }

        // Rule 5: Door seal glitch (Crow's Nest par Dining Saloon dobara unvisited)
        switch (maryCurrent) {
        case 7:
            switch (maryVisitedDiningSaloon) {
            case 1: cout << "Mary (Move 5): DoorSealed" << endl; maryVisitedDiningSaloon = 0; break;
            }
            break;
        }
        break;
    }

    // ================= MARY : MOVE 6 =================
    switch (maryFrozen) {
    case 1:
        // Mary pehle hi freeze ho chuka hai, is move mein kuch nahi hoga
        break;
    }

    cout << endl;
    cout << "Murdoch path: Boiler Room";     // P0 hamesha start deck
    switch (murP1) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP2) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP3) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP4) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP5) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (murP6) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    cout << endl;
    cout << "Mary path: Boiler Room";     // P0 hamesha start deck
    switch (maryP1) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP2) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP3) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP4) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP5) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    switch (maryP6) {
    case -1: break;     // is move mein koi movement nahi hui
    case 0: cout << " -> Boiler Room"; break;
    case 1: cout << " -> Cargo Hold"; break;
    case 2: cout << " -> Third Class"; break;
    case 3: cout << " -> Dining Saloon"; break;
    case 4: cout << " -> Promenade Deck"; break;
    case 5: cout << " -> Bridge"; break;
    case 6: cout << " -> Lifeboat Deck"; break;
    case 7: cout << " -> Crow's Nest"; break;
    }
    cout << endl;

    return 0;
}