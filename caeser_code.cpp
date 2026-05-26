// ===== Header Files =====
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// ===== Function Prototypes =====
void encrypt();
void decrypt();
void caesarBruteForce();
void randomKeyEncrypt();
void randomKeyDecrypt();
void fileEncrypt();
void fileDecrypt();
void generateKeyFile();
void generateWordlist();

// ===== Main Function =====
int main()
{
    srand(time(0));   // Initialize random generator

    int choice = 0;

    // Display menu until Exit
    while(choice != 10)
    {
        cout << "\n====== Caesar Cipher Tool ======\n";
        cout << "1.  Encrypt\n";
        cout << "2.  Decrypt\n";
        cout << "3.  Caesar Brute Force\n";
        cout << "4.  Random Key Encrypt\n";
        cout << "5.  Random Key Decrypt\n";
        cout << "6.  File Encrypt\n";
        cout << "7.  File Decrypt\n";
        cout << "8.  Generate Key File\n";
        cout << "9.  Generate Custom Wordlist\n";
        cout << "10. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        // Handle invalid input like @ or letters
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Numbers only.\n";
            continue;
        }

        // ===== Menu Options =====
        switch(choice)
        {
            case 1:
                encrypt();
                break;

            case 2:
                decrypt();
                break;

            case 3:
                caesarBruteForce();
                break;

            case 4:
                randomKeyEncrypt();
                break;

            case 5:
                randomKeyDecrypt();
                break;

            case 6:
                fileEncrypt();
                break;

            case 7:
                fileDecrypt();
                break;

            case 8:
                generateKeyFile();
                break;

            case 9:
                generateWordlist();
                break;
            case 10:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
// ===== Encrypt Function =====
void encrypt()
{
    string text;
    string encrypted = "";
    int shiftKey;

    cin.ignore(1000, '\n');

    // Take input text
    cout << "\nEnter text to encrypt: ";
    getline(cin, text);

    // Take shift key
    cout << "Enter shift key (1-25): ";
    cin >> shiftKey;

    // Validate key
    if(cin.fail() || shiftKey < 1 || shiftKey > 25)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid shift key!\n";
        return;
    }

    // Encrypt text character by character
    for(int i = 0; i < text.length(); i++)
    {
        // Uppercase letters
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            encrypted += (text[i] - 'A' + shiftKey) % 26 + 'A';
        }

        // Lowercase letters
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            encrypted += (text[i] - 'a' + shiftKey) % 26 + 'a';
        }

        // Symbols and spaces remain same
        else
        {
            encrypted += text[i];
        }
    }

    cout << "\nOriginal Text : " << text << endl;
    cout << "Shift Key     : " << shiftKey << endl;
    cout << "Encrypted Text: " << encrypted << endl;
}


// ===== Decrypt Function =====
void decrypt()
{
    string text;
    string decrypted = "";
    int shiftKey;

    cin.ignore(1000, '\n');

    // Take encrypted text
    cout << "\nEnter encrypted text: ";
    getline(cin, text);

    // Take shift key
    cout << "Enter shift key (1-25): ";
    cin >> shiftKey;

    // Validate key
    if(cin.fail() || shiftKey < 1 || shiftKey > 25)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid shift key!\n";
        return;
    }

    // Decrypt text character by character
    for(int i = 0; i < text.length(); i++)
    {
        // Uppercase letters
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            decrypted += (text[i] - 'A' - shiftKey + 26) % 26 + 'A';
        }

        // Lowercase letters
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            decrypted += (text[i] - 'a' - shiftKey + 26) % 26 + 'a';
        }

        // Symbols remain same
        else
        {
            decrypted += text[i];
        }
    }

    cout << "\nDecrypted Text: " << decrypted << endl;
}


// ===== Caesar Brute Force =====
void caesarBruteForce()
{
    string text;
    string decrypted = "";

    cin.ignore(1000, '\n');

    cout << "\nEnter encrypted text: ";
    getline(cin, text);

    cout << "\n===== All Possible Decryptions =====\n";

    // Try all 25 keys
    for(int key = 1; key <= 25; key++)
    {
        decrypted = "";

        for(int i = 0; i < text.length(); i++)
        {
            if(text[i] >= 'A' && text[i] <= 'Z')
            {
                decrypted += (text[i] - 'A' - key + 26) % 26 + 'A';
            }
            else if(text[i] >= 'a' && text[i] <= 'z')
            {
                decrypted += (text[i] - 'a' - key + 26) % 26 + 'a';
            }
            else
            {
                decrypted += text[i];
            }
        }

        cout << "Key " << key << " : " << decrypted << endl;
    }
}
// ===== Random Key Encrypt =====
void randomKeyEncrypt()
{
    string text;
    string encrypted = "";
    int key;

    cin.ignore(1000, '\n');

    cout << "\nEnter text to encrypt: ";
    getline(cin, text);

    // Generate random key 1-25
    key = rand() % 25 + 1;

    // Encrypt text
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            encrypted += (text[i] - 'A' + key) % 26 + 'A';
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            encrypted += (text[i] - 'a' + key) % 26 + 'a';
        }
        else
        {
            encrypted += text[i];
        }
    }

    cout << "\nRandom Key   : " << key << endl;
    cout << "Encrypted Text: " << encrypted << endl;
    cout << "Save this key for decryption.\n";
}


// ===== Random Key Decrypt =====
void randomKeyDecrypt()
{
    string text;
    string decrypted = "";
    int key;

    cin.ignore(1000, '\n');

    cout << "\nEnter encrypted text: ";
    getline(cin, text);

    cout << "Enter saved random key: ";
    cin >> key;

    // Validate key
    if(cin.fail() || key < 1 || key > 25)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid key!\n";
        return;
    }

    // Decrypt text
    for(int i = 0; i < text.length(); i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            decrypted += (text[i] - 'A' - key + 26) % 26 + 'A';
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            decrypted += (text[i] - 'a' - key + 26) % 26 + 'a';
        }
        else
        {
            decrypted += text[i];
        }
    }

    cout << "\nDecrypted Text: " << decrypted << endl;
}


// ===== Generate Key File =====
void generateKeyFile()
{
    string filename;
    int key;

    cin.ignore(1000, '\n');

    cout << "\nEnter filename to save key: ";
    getline(cin, filename);

    // Random key generation
    key = rand() % 25 + 1;

    ofstream fout(filename.c_str());

    // File check
    if(!fout.is_open())
    {
        cout << "Error creating file!\n";
        return;
    }

    // Save key in file
    fout << "===== Caesar Cipher Key File =====\n";
    fout << "Secret Key : " << key << endl;
    fout << "Keep this key safe.\n";

    fout.close();

    cout << "\nKey file created successfully.\n";
    cout << "Generated Key: " << key << endl;
}
// ===== File Encrypt =====
void fileEncrypt()
{
    string inputFile;
    string outputFile;
    string line;
    string encrypted = "";
    int shiftKey;

    cin.ignore(1000, '\n');

    // Take filenames
    cout << "\nEnter input filename: ";
    getline(cin, inputFile);

    cout << "Enter output filename: ";
    getline(cin, outputFile);

    cout << "Enter shift key (1-25): ";
    cin >> shiftKey;

    // Validate key
    if(cin.fail() || shiftKey < 1 || shiftKey > 25)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid shift key!\n";
        return;
    }

    // Open input file
    ifstream fin(inputFile.c_str());

    if(!fin.is_open())
    {
        cout << "Cannot open input file!\n";
        return;
    }

    // Create output file
    ofstream fout(outputFile.c_str());

    if(!fout.is_open())
    {
        cout << "Cannot create output file!\n";
        fin.close();
        return;
    }

    // Read file line by line
    while(getline(fin, line))
    {
        encrypted = "";

        // Encrypt each character
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] >= 'A' && line[i] <= 'Z')
            {
                encrypted += (line[i] - 'A' + shiftKey) % 26 + 'A';
            }
            else if(line[i] >= 'a' && line[i] <= 'z')
            {
                encrypted += (line[i] - 'a' + shiftKey) % 26 + 'a';
            }
            else
            {
                encrypted += line[i];
            }
        }

        fout << encrypted << endl;
    }

    // Close files
    fin.close();
    fout.close();

    cout << "\nFile encrypted successfully.\n";
    cout << "Output saved in: " << outputFile << endl;
}


// ===== File Decrypt =====
void fileDecrypt()
{
    string inputFile;
    string outputFile;
    string line;
    string decrypted = "";
    int shiftKey;

    cin.ignore(1000, '\n');

    // Take filenames
    cout << "\nEnter encrypted filename: ";
    getline(cin, inputFile);

    cout << "Enter output filename: ";
    getline(cin, outputFile);

    cout << "Enter shift key (1-25): ";
    cin >> shiftKey;

    // Validate key
    if(cin.fail() || shiftKey < 1 || shiftKey > 25)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid shift key!\n";
        return;
    }

    // Open encrypted file
    ifstream fin(inputFile.c_str());

    if(!fin.is_open())
    {
        cout << "Cannot open input file!\n";
        return;
    }

    // Create output file
    ofstream fout(outputFile.c_str());

    if(!fout.is_open())
    {
        cout << "Cannot create output file!\n";
        fin.close();
        return;
    }

    // Read file line by line
    while(getline(fin, line))
    {
        decrypted = "";

        // Decrypt each character
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] >= 'A' && line[i] <= 'Z')
            {
                decrypted += (line[i] - 'A' - shiftKey + 26) % 26 + 'A';
            }
            else if(line[i] >= 'a' && line[i] <= 'z')
            {
                decrypted += (line[i] - 'a' - shiftKey + 26) % 26 + 'a';
            }
            else
            {
                decrypted += line[i];
            }
        }

        fout << decrypted << endl;
    }

    // Close files
    fin.close();
    fout.close();

    cout << "\nFile decrypted successfully.\n";
    cout << "Output saved in: " << outputFile << endl;
}
// ===== Generate Custom Wordlist =====
void generateWordlist()
{
    string name, dob, pet, age, filename;

    cin.ignore(1000, '\n');

    cout << "\nEnter Name: ";
    getline(cin, name);

    cout << "Enter Date of Birth: ";
    getline(cin, dob);

    cout << "Enter Pet Name: ";
    getline(cin, pet);

    cout << "Enter Age: ";
    getline(cin, age);

    cout << "Enter output filename: ";
    getline(cin, filename);

    ofstream fout(filename.c_str());

    if(!fout.is_open())
    {
        cout << "Cannot create file!\n";
        return;
    }

    // Generate wordlist combinations
    fout << name << endl;
    fout << name << "123" << endl;
    fout << name << "786" << endl;
    fout << name << dob << endl;
    fout << name << pet << endl;
    fout << name << age << endl;
    fout << pet << "123" << endl;
    fout << pet << age << endl;
    fout << name << dob << pet << endl;
    fout << name << age << pet << endl;

    fout.close();

    cout << "\nWordlist generated successfully.\n";
    cout << "Saved in: " << filename << endl;
}
