#include <iostream>
#include <fstream>
using namespace std;

bool doubleCheckInput(string book, string author) {
    char input;
    bool doublechecker = true;

    cout << "You entered --> Book: " << book << " \n\t\tAuthor: " << author;
    cout << "\nIs this correct? (Y/N) ";
    cin >> input;
    
    if(((input != 'Y') || (input != 'y')) && ((input == 'N') || (input == 'n'))) {
        doublechecker = false;
    }
    return doublechecker;
}

bool doubleCheckInput(string movie) {
    char input;
    bool doublechecker = true;

    cout << "You entered --> Movie: " << movie;
    cout << "\nIs this correct? (Y/N) ";
    cin >> input;
    
    if(((input != 'Y') || (input != 'y')) && ((input == 'N') || (input == 'n'))) {
        doublechecker = false;
    }
    return doublechecker;
}

bool doubleCheckInput(string song, string artist, string album) {
    char input;
    bool doublechecker = true;

    cout << "You entered --> Song: " << song << "\n\t\tArtist: " << artist << "\n\t\tAlbum: " << album;
    cout << "\nIs this correct? (Y/N) ";
    cin >> input;
    
    if(((input != 'Y') || (input != 'y')) && ((input == 'N') || (input == 'n'))) {
        doublechecker = false;
    }
    return doublechecker;
}

void menu() {
    cout << "\n**Enter the number where"
        << "\nyou'd like to add the item**\n";
    cout << "--------------" << endl;
    cout << "|    Menu    |" << endl;
    cout << "--------------" << endl;
    cout << "| 1. Books   |" << endl;
    cout << "| 2. Movies  |" << endl;
    cout << "| 3. Music   |" << endl;
    cout << "| 4. Exit    |" << endl;
    cout << "--------------" << endl; 
}

void printToScreen(ifstream &file) {
     if (file.is_open())
        cout << "\n---------------------------";
        cout << "\n" << file.rdbuf();
        cout << "---------------------------" << endl;
}

void books() {
    cout <<"\n***BOOKS***\n\n";

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

            do {
                cin.ignore(1000, '\n');

                cout << "Book: ";
                getline(cin, bookName);

                cout << "By: ";
                getline(cin, authorName);
            }while (!(doubleCheckInput(bookName,authorName)));

            outstream << "Book:" << bookName << endl;
            outstream << "By: " << authorName << "\n\n";

            cout << "\nWould you like to add another entry? (Y/N) ";

            cin >> userInput;
        }while (((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')));

        outstream.close();

        cout << "\nDo you want to view books you have read? (Y/N)";
        cin >> userInput;

            if(((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')))
            {
            ifstream BooksRead("BooksRead.odt");
            
            printToScreen(BooksRead);
            
            BooksRead.close();
            }
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

            do {
            cin.ignore(1000, '\n');

            cout << "\nMovie Title: ";
            getline(cin, movieTitle);
            }while(!(doubleCheckInput(movieTitle)));

            outstream << "Movie Title: " << movieTitle << "\n\n";

            cout << "\nWould you like to add another entry? (Y/N) ";
            
            cin >> userInput;
        }while (((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')));

        outstream.close();

        cout << "\nDo you want to view the movies you have watched? (Y/N) ";
        cin >> userInput;

            if(((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')))
            {
            ifstream moviesWatched("moviesWatched.odt");
            
            printToScreen(moviesWatched);
            
            moviesWatched.close();
            }
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
            string songTitle;
            string artist;
            string album;

            do {
                cin.ignore(1000, '\n');

                cout << "Song Title: ";
                getline(cin, songTitle);

                cout << "Artist: ";
                getline(cin, artist);

                cout << "Album: ";
                getline(cin, album);
            }while (!(doubleCheckInput(songTitle, artist, album)));

            outstream << "Song: " << songTitle << endl;
            outstream << "Artist: " << artist << endl;
            outstream << "Album: " << album << "\n\n\n";

            cout << "Would you like to add another entry? (Y/N) ";

            cin >> userInput;
        }while (((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')));

        outstream.close();

        cout << "\nDo you want to the music you listen to? (Y/N) ";
        cin >> userInput;

            if(((userInput != 'N') || (userInput != 'n')) && ((userInput == 'y') || (userInput == 'Y')))
            {
            ifstream musicListenedTo("musicListenedTo.odt");
            
            printToScreen(musicListenedTo);
            
            musicListenedTo.close();
            }
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


        cout << "Do you wish to add anything else? (Y/N) ";
        
        cin.ignore(1000, '\n');
        cin >> charInput;

   }while (((charInput != 'N') || (charInput != 'n')) && ((charInput == 'y') || (charInput == 'Y'))); 
    return 0;
}