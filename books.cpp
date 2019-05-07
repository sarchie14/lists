//Written by Spencer Archibald
//Purpose: I wanted to keep a record of all the media I've read, watched, and listened to


//Add series to doc

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

void removePUNCT(string &input) {
    //Figure out & removal, maybe add #
    string PUNCT = ".-()\'\"\?! ";

    for(int i = 0; i < input.size(); i++) {
        for(int j = 0; j < PUNCT.size(); j++) {
            if(input[i] == PUNCT[j]) {
            input = input.erase(i,1);
            }
        }
    }

    transform(input.begin(), input.end(), input.begin(), ::tolower);
}

/*searchData is used to determine if input for a song, movie,
or book has already been entered into the database.*/
bool searchData(string book2Search, string auth2Search, ifstream &file)
{
    cout << "\nSearching document for " << book2Search << " BY " << auth2Search << endl;

    string removePUNCTFromDocInput = ".-()\'\"\?! ";

    if(file.fail())
    {
        cout << "Error";
        exit(1);
    }

    vector<string> bookTitles;
    vector<string> authorNam;

    string storeLineFromDoc;
   
    string tempBook;
    string tempAuth;


    while (getline(file, storeLineFromDoc))
    {

        tempBook = storeLineFromDoc;
        tempAuth = storeLineFromDoc;

        tempBook.erase(0,5);
        removePUNCT(tempBook);
        bookTitles.push_back(tempBook);

        tempAuth.erase(0,3);
        removePUNCT(tempAuth);
        authorNam.push_back(tempAuth);

    }

    removePUNCT(book2Search);
    removePUNCT(auth2Search);
    
    bool finalSearch = false;

    for(int i = 2, j = 3; i < bookTitles.size(), j < authorNam.size(); i = i + 3, j = j + 3) {
        if((bookTitles[i] == book2Search) && (authorNam[j] == auth2Search)) {
            finalSearch = true;
        }
    }

    if(finalSearch) {
         cout << "\nBook has already been put into database." << endl;
    }
    return finalSearch;

 
} 

/*doubleCheckInput prints user's input out onto screen. 
Then asks the user if they are pleased with that input*/
bool doubleCheckInput(string book, string author) {
    char input;
    bool doublechecker = true;

    cout << "\nYou entered --> Book: " << book << " \n\t\tAuthor: " << author;
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

//Prints menu and choices to screen
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

//prints out file to screen for user to view contents of file
void printToScreen(ifstream &file) {
     if (file.is_open())
        cout << "\n---------------------------";
        cout << "\n" << file.rdbuf();
        cout << "---------------------------" << endl;
}

/*books will open file and print the user's desired book,
and author into a file*/
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

            ifstream bookData("BooksRead.odt");

            do {

                do {
                    cin.ignore(1000, '\n');

                    cout << "Book: ";
                    getline(cin, bookName);

                    cout << "By: ";
                    getline(cin, authorName);
                }while (!(doubleCheckInput(bookName,authorName)));
            }while(searchData(bookName, authorName, bookData));

            bookData.close();

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

//movies will open file and print the user's desired movie into a file
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

/*books will open file and print the user's desired song, artist,
and album into a file*/
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
    char charInput;
    int userInput;

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