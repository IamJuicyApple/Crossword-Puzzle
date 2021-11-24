#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

void write_file(string word,vector<string> data, string file_name)
{
    ofstream file(file_name.c_str(), std::ios::app);
    file << " " << word;
    file.close();
}

void display_puzzle(vector<vector<string>> puzzle, int row, int column)
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << puzzle[i][j] << " ";
        }
        cout << endl;
    }
}

void puzzle_results(vector<vector<string>> puzzle, vector<string> data)
{
    vector<string> words = data;
    vector <vector<string>> results;
    bool found;
    int count = 0;
    int row = puzzle.size();
    int column = puzzle[0].size();

    // Horizontal (left to right)

    for (int i = 0; i < words.size();i++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < column; c++)
            {            
                if (toupper(puzzle[r][c][0]) == toupper(words[i][count]))
                {
                    if (count > words[i].size())
                        count = 0;                  
                    else
                        count++;
                }
                else
                {
                    count = 0;
                }

                if (count == words[i].size())
                {
                    results.push_back({ words[i] ,std::to_string(r+1), std::to_string(c - count + 1 + 1) });
                    //cout << words[i] << endl;
                    count = 0;
                    r = row;
                    c = column;
                }
            }
        }  
    }
    cout << endl;
    // Horizontal (right to left)

    for (int i = 0; i < words.size(); i++)
    {

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < column; c++)
            {

                if (toupper(puzzle[row - r - 1][column - c - 1][0]) == toupper(words[i][count]))
                {
                    if (count > words[i].size())
                        count = 0;
                    else
                        count++;
                }
                else
                {
                    count = 0;
                }
                if (count == words[i].size())
                {
                    results.push_back({ words[i] ,std::to_string(row - r), std::to_string(column - c + count -1) });
                    //cout << words[i] << endl;
                    count = 0;
                    r = row;
                    c = column;
                }
            }
        }
    }
    cout << endl;
    // Vertical ( up to down)

    for (int i = 0; i < words.size(); i++)
    {
        for (int c = 0; c < column; c++)
        {
            for (int r = 0; r < row; r++)
            {

                if (toupper(puzzle[r][c][0]) == toupper(words[i][count]))
                {
                    if (count > words[i].size())
                        count = 0;
                    else
                        count++;
                }
                else
                {
                    count = 0;
                }

                if (count == words[i].size())
                {
                    results.push_back({ words[i] ,std::to_string(r - count +1 +1), std::to_string(c + 1) });
                    //cout << words[i] << endl;
                    count = 0;
                    r = row;
                    c = column;
                }
            }
        }
    }
    cout << endl;
    // Vertical (down to up)

    for (int i = 0; i < words.size(); i++)
    {
        for (int c = 0; c < column; c++)
        {
            for (int r = 0; r < row; r++)
            {

                if (toupper(puzzle[row - r - 1][column - c - 1][0]) == toupper(words[i][count]))
                {
                    if (count > words[i].size())
                        count = 0;
                    else
                        count++;
                }
                else
                {
                    count = 0;
                }

                if (count == words[i].size())
                {
                    results.push_back({ words[i] ,std::to_string(row - r + count - 1), std::to_string(column - c) });
                    //cout << words[i] << endl;
                    count = 0;
                    r = row;
                    c = column;
                }
            }
        }
    }

    cout << endl;
    // Narrow ( start from top left, go south east)    
    for (int i = 0; i < words.size(); i++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < column; c++)
            {
                count = 0;
                if (toupper(puzzle[r][c][0]) == toupper(words[i][count]))
                {
                    count++;
                    bool loop = true;
                    while (loop)
                    {
                        if (r + count < row && c + count < column) {
                            if (toupper(puzzle[r + count][c + count][0]) == toupper(words[i][count]))
                            {
                                if (count > words[i].size())
                                    count = 0;
                                else
                                {
                                    count++;
                                    if (count == words[i].size())
                                    {
                                        results.push_back({ words[i] ,std::to_string(r + 1), std::to_string(c + 1) });
                                        //cout << words[i] << endl;
                                        loop = false;
                                        count = 0;
                                    }
                                }
                                   
                            }
                            else
                            {
                                loop = false;
                                count = 0;
                            }
                        }
                        else
                        {
                            loop = false;
                        }
                    }
                }
            }
        }
    }

    cout << endl;
    // Narrow ( start from bottom left  and go north east)  
    for (int i = 0; i < words.size(); i++)
    {
        for (int r = row - 1; r >= 0; r--)
        {
            for (int c = 0; c < column; c++)
            {
                count = 0;
                if (toupper(puzzle[r][c][0]) == toupper(words[i][count]))
                {
                    count++;
                    bool loop = true;
                    while (loop)
                    {
                        if (r - count >= 0 && c + count < column) {
                            if (toupper(puzzle[r - count][c + count][0]) == toupper(words[i][count]))
                            {
                                if (count > words[i].size())
                                    count = 0;
                                else
                                {
                                    count++;
                                    if (count == words[i].size())
                                    {
                                        results.push_back({ words[i] ,std::to_string(r + 1), std::to_string(c + 1) });
                                        //cout << words[i] << endl;
                                        loop = false;
                                        count = 0;
                                    }
                                }

                            }
                            else
                            {
                                loop = false;
                                count = 0;
                            }
                        }
                        else
                        {
                            loop = false;
                        }
                    }
                }
            }
        }
    }

    cout << endl;
    // Narrow ( start from bottom right , and go to north west)  
    for (int i = 0; i < words.size(); i++)
    {
        for (int r = row - 1; r >= 0; r--)
        {
            for (int c = column - 1; c >= 0; c--)
            {
                count = 0;
                if (toupper(puzzle[r][c][0]) == toupper(words[i][count]))
                {
                    count++;
                    bool loop = true;
                    while (loop)
                    {
                        if (r - count >= 0 && c - count >= 0) {
                            if (toupper(puzzle[r - count][c - count][0]) == toupper(words[i][count]))
                            {
                                if (count > words[i].size())
                                    count = 0;
                                else
                                {
                                    count++;
                                    if (count == words[i].size())
                                    {
                                        results.push_back({ words[i] ,std::to_string(r + 1), std::to_string(c + 1) });
                                        //cout << words[i] << endl;
                                        loop = false;
                                        count = 0;
                                    }
                                }

                            }
                            else
                            {
                                loop = false;
                                count = 0;
                            }
                        }
                        else
                        {
                            loop = false;
                        }
                    }
                }
            }
        }
    }

    cout << endl;
    // Narrow ( start from top right , and go to south west)  
    for (int i = 0; i < words.size(); i++)
    {
        for (int r = 0; r < row; r++)
        {
            for (int c = column - 1; c >= 0; c--)
            {
                count = 0;
                if (toupper(puzzle[r][c][0]) == toupper(words[i][count]))
                {
                    count++;
                    bool loop = true;
                    while (loop)
                    {
                        if (r + count < row && c - count >= 0) {
                            if (toupper(puzzle[r + count][c - count][0]) == toupper(words[i][count]))
                            {
                                if (count > words[i].size())
                                    count = 0;
                                else
                                {
                                    count++;
                                    if (count == words[i].size())
                                    {
                                        results.push_back({ words[i] ,std::to_string(r + 1), std::to_string(c + 1) });
                                        //cout << words[i] << endl;
                                        loop = false;
                                        count = 0;
                                    }
                                }
                            }
                            else
                            {
                                loop = false;
                                count = 0;
                            }
                        }
                        else
                        {
                            loop = false;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < results.size(); i++)
    {
        cout << i + 1 << ". " << results[i][0] << " ( " << results[i][1] << "," << results[i][2] << " )" << endl;
    }

}

int main()
{
    string blank_item = "", temp;
    int  count,option;
    int column, row;
    vector<string> words;
    vector<vector<string>> puzzle;

    // Retrieve all the words from Database
    ifstream inFile;
    inFile.open("Database.txt");

    count = 0;
    while (!inFile.eof())
    {
        words.push_back(blank_item);
        inFile >> words[count];
        count++;
    }
    inFile.close();

    /*for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << "|";
    }*/
    do {
        cout << "\n\t\tCrossWord Puzzle !!!" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "\n\t1. Add Words\n";
        cout << "\n\t2. New Puzzle\n";
        cout << "\n\t3. Results\n";
        cout << "\n\n-- Enter Your Choice : ";
        cin >> option;

        if (option == 1)
        {
            cout << "\n\t\tAdd Words (0 to quit) \n";
            cout << "--------------------------------------------------------------------------" << endl;
            do {
                cout << "\n\tWords : ";

                cin >> temp;
                if (temp != "0")
                {
                    words.push_back(temp);
                    write_file(temp, words, "Database.txt");
                }
            } while (temp != "0");

        }
        else if (option == 2)
        {
            puzzle.clear();
            cout << "\n\t\t New Puzzle \n";
            cout << "--------------------------------------------------------------------------" << endl;
            cout << "\n\n\tEnter the Row: ";
            cin >> row;
            cout << "\tEnter the Column: ";
            cin >> column;
            cout << "Enter the puzzle: ";
            for (int i = 0; i < row; i++)
            {
                //cout << "Row " << i + 1 << endl;
                puzzle.push_back({});
                for (int j = 0; j < column; j++)
                {
                    cin >> temp;

                    while (temp.size() != 1)
                    {
                        cout << "Only one Character !!! " << endl;
                        cout << "Enter a character: ";
                        cin >> temp;
                    }
                    puzzle[i].push_back(temp);
                    
                }
            }
            display_puzzle(puzzle, row, column);
            
        }
        else if (option == 3)
        {
            cout << "Current Puzzle: ";
            display_puzzle(puzzle, row, column);
            cout << endl;
            puzzle_results(puzzle, words);
        }


    } while (option != 0);

}
