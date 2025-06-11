#include <iostream>
#include <string>
#include <vector>
using namespace std;

void FriendAsksForPC() {
    string TheAnswer;

    while (true) {
        cout << "You: So, I was wondering if I could build a PC for you.\n";
        cout << "Friend: .....\n";
        cout << "Friend: Ok fine, but here's a deal: you have to carry my books for a week.\n";
        cout << "<Agree y/n>\n";
        cin >> TheAnswer;

        if (TheAnswer == "Y" || TheAnswer == "y") {
            cout << "You: Fine... deal.\n";
            break;
        } else {
            cout << "Wanna try again? <Y/N>\n";
            cin >> TheAnswer;

            if (TheAnswer == "Y" || TheAnswer == "y") {
                continue;
            } else {
                cout << "Friend: Ok fine, no deal then. See ya!\n";
                exit(0);
            }
        }
    }
}

class PCBuilder {
private:
    string cpu, gpu, ram, motherboard, storage;

public:
    bool componentChoice() {
        int choice;
        vector<int> userChoices;
        const int expectedOrder[] = {1, 4, 2, 3, 5};

        cout << "Choose the order in which you should install the components:\n";
        cout << "1. CPU\n";
        cout << "2. GPU\n";
        cout << "3. RAM\n";
        cout << "4. Motherboard\n";
        cout << "5. Storage\n";
        cout << "6. Finish Choices\n";

        while (true) {
            cout << "Enter your choice (1-6): ";
            cin >> choice;

            if (choice >= 1 && choice <= 6) {
                if (choice == 6) {
                    break;
                }
                userChoices.push_back(choice);
            } else {
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            }
        }

        bool correctOrder = true;
        for (int i = 0; i < userChoices.size() && i < 5; i++) {
            if (userChoices[i] != expectedOrder[i]) {
                correctOrder = false;
                break;
            }
        }

        if (correctOrder) {
            cout << "Finishing choices...\n";
            cpu = "Default CPU";
            motherboard = "Default Motherboard";
            gpu = "Default GPU";
            ram = "Default RAM";
            storage = "Default Storage";
            return true;
        } else {
            cout << "You installed the components in the wrong order and fried the motherboard. Your friend is not happy...\n";
            return false;
        }
    }

    void greet() {
        cout << "You chose to install:\n";
        cout << "First, you install the " << cpu << " on the " << motherboard << endl;
        cout << "Then, you install the " << ram << endl;
        cout << "Next, you install the " << gpu << endl;
        cout << "Finally, you install the " << storage << endl;
    }
};

int main() {
    string answer;

    cout << "You're a tech enthusiast.\n";

    while (true) {
        cout << "You want to build a PC but don't have the money to build one for yourself... <continue? Y/N>\n";
        cin >> answer;

        if (answer == "Y" || answer == "y") {
            cout << "However, you see your friend sitting next to you...\n";
            cout << "Do you ask your friend if you can build a PC for them? <Y/N>\n";
            cin >> answer;

            if (answer == "Y" || answer == "y") {
                cout << "You go up to your friend and start asking.\n";
                break;
            }
        } else {
            cout << "Game ends.\n";
            cout << "Wanna go again? <Y/N>\n";
            cin >> answer;

            if (answer != "Y" && answer != "y") {
                cout << "Oop.. I guess you don't then. Baibai!\n";
                return 0;
            }
        }

        cout << "Wanna go again? <Y/N>\n";
        cin >> answer;

        if (answer != "Y" && answer != "y") {
            cout << "Oop.. I guess you don't then. Baibai!\n";
            return 0;
        }
    }

    FriendAsksForPC();

    PCBuilder pcBuilder;
    char tryAgain;

    do {
        bool success = pcBuilder.componentChoice();

        if (success) {
            pcBuilder.greet();
            break;
        }

        cout << "Do you want to try again? (Y/N): ";
        cin >> tryAgain;

        if (tryAgain != 'Y' && tryAgain != 'y') {
            cout << "You gave up and your friend is stuck with a broken PC.\n";
        }

    } while (tryAgain == 'Y' || tryAgain == 'y');

    return 0;
}
