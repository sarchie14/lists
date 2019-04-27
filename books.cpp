#include <iostream>
#include <fstream>
using namespace std;

void menu() {
    cout << "**Enter the number where you'd "
        << "\n\tlike to add the item**\n";
    cout << "--------------" << endl;
    cout << "|    Menu    |" << endl;
    cout << "--------------" << endl;
    cout << "| 1. Books   |" << endl;
    cout << "| 2. Movies  |" << endl;
    cout << "| 3. Music   |" << endl;
    cout << "| 4. Exit    |" << endl;
    cout << "--------------" << endl; 
}

void books() {
    cout <<"***BOOKS***\n\n";

    ofstream outstream;
    outstream.open("BooksRead.odt", ios::in | ios::app);

    if(outstream.fail()) {
        cout << "Error while opening file";
        exit(1);
    }

        char userInput;
        do {

            string bookName;
            string authorName;

            cin.ignore(1000, '\n');
            cout << "Book: ";
            getline(cin, bookName);

            cout << "By: ";
            getline(cin, authorName);

            outstream << "Book:" << bookName << endl;
            outstream << "By: " << authorName << "\n\n";

            cout << "Would you like to add another entry?";

            cin >> userInput;
        }while (((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')));

        outstream.close();
}

void movies() {
    cout <<"***MOVIES***\n\n";

    ofstream outstream;
    outstream.open("moviesWatched.odt", ios::in | ios::app);

    if(outstream.fail()) {
        cout << "Error while opening file";
        exit(1);
    }

        
        
        char userInput;
        do {
            string movieTitle;

            cin.ignore(1000, '\n');
            cout << "Movie Title: ";
            getline(cin, movieTitle);

            outstream << "Movie Title:" << movieTitle << "\n\n";

            cout << "Would you like to add another entry? ";
            
            cin >> userInput;
        }while (((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')));

        outstream.close();
}


void music() {
    cout <<"***MUSIC***\n\n";

    ofstream outstream;
    outstream.open("musicListenedTo.odt", ios::in | ios::app);

    if(outstream.fail()) {
        cout << "Error while opening file";
        exit(1);
    }

        
        
        char userInput;
        do {

            cout << "Song Title: ";

            /*string songTitle;
            getline(cin, bookName);

            outstream << "Song:" << songTitle << endl;
            cout << "By: ";

            string artist;
            getline(cin, artist);

            outstream << "By: " << artist << endl;
            outstream << "\n";
*/
            cout << "Would you like to add another entry?";

            cin >> userInput;
        }while (((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')));

        outstream.close();
}

int main() {

    int userInput;
    char charInput;

   do { 
    menu();

        do{
            cin >> userInput;
            switch(userInput) {
                case 1: books();
                    break;
                case 2: movies();
                    break;
                case 3: music();
                    break;
                case 4: exit(0);
                    break;
                default: cout << "Incorrect Input try again\n";
            }
        }while((userInput < 1) || (userInput > 4));


        cout << "Do you need to add other entries? ";
        
        cin.ignore(1000, '\n');
        cin >> charInput;

   }while (((charInput != 'N') || (charInput != 'n')) && ((charInput == 'y') || (charInput == 'Y')));
    return 0;
}