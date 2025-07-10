#include <iostream>
#include <vector>
using namespace std;


class Note{
    public:
    string text;
    int order;
    int type = 0; // 1 is straight up note 2 is checklist note 3 is - note 4 is doom
    bool isItDone = 0;
    Note(string t){
        text = t;

    }
    
    Note(){
        text = "Dunno idk";


    }
    

    Note(int ty, string t){
        text = t;
        type = ty;

    }

    void changeNote(string nT){
        text = nT;

    }
    


};

class Notebook : Note{
    public:
    string notebookName;
    vector<Note*> notes;

    int lastType = 1;

    Notebook(){
        notebookName = "Idk";

    }

    Notebook(string nN){
        notebookName = nN;

    }

    void addNote(Note* n){
        notes.push_back(n);

        cout << "Note added" << "\n";

    }

    /*void addDirectNote(int ty, string t){
        Note* addingNote = new Note(ty, t);
        addingNote->order = notes.size();
        notes.push_back(addingNote);
        

        cout << "Note added" << "\n";

    }*/

    void displayNotes(){
        cout << "--" << notebookName << "--\n";
        for(int i = 0; i < notes.size(); i++){
            switch(notes[i]->type){
                case 1:
                break;

                case 2: 
                    if(notes[i]->isItDone == true) cout << "[✓] ";
                    if(notes[i]->isItDone == false) cout << "[ ] ";
                break;
                
                case 3: cout << "-";
                break;

                case 4: cout << "Memoryleak * ";
                break;

            }
            cout << notes[i]->text << "\n";
                



        }




    }

    void check(int o){
        bool isProcessOver = false;
        if(notes[o]->isItDone == false){
            notes[o]->isItDone = true;
            cout << notes[o]->text <<  " Note checked\n";
            isProcessOver = true;
        }
        if(notes[o]->isItDone == true && isProcessOver == false){
            notes[o]->isItDone = false;
            cout << notes[o]->text <<  " Note unchecked\n";
        }


    }


};

int main(){ 
    Notebook notezook = {"Notezook"};

    Note no1 = {"MErhaba"};

    Note no2 = {2, "aasdadsa"};
    
    Note no3 = {3, "aaaa"};

    notezook.addNote(&no1);
    notezook.addNote(&no2);
    notezook.addNote(&no3);

    notezook.check(1);

    notezook.displayNotes();


}