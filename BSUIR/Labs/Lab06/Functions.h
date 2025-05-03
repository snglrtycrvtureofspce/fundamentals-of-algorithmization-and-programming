#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

struct Game {
    std::string name;
    std::string genre;
    double rating;
    std::vector<std::string> platforms;
};

std::vector<Game> games;

int inputInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value)
            return value;
        else {
            std::cout << "Incorrect input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

double inputDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value)
            return value;
        else {
            std::cout << "Incorrect input. Try again.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

void addGame() {
    Game g;
    std::cout << "Enter the name of the game: ";
    std::cin.ignore();
    std::getline(std::cin, g.name);
    std::cout << "Enter genre: ";
    std::getline(std::cin, g.genre);
    g.rating = inputDouble("Enter a rating: ");

    int numPlatforms = inputInt("How many platforms? ");
    std::cin.ignore();
    g.platforms.resize(numPlatforms);
    for (int i = 0; i < numPlatforms; ++i) {
        std::cout << "Platform " << i + 1 << ": ";
        std::getline(std::cin, g.platforms[i]);
    }
    games.push_back(g);
}

void clearGames() {
    games.clear();
    std::cout << "The array of games has been cleared.\n";
}

void showGames() {
    if (games.empty()) {
        std::cout << "The game list is empty.\n";
        return;
    }
    for (const auto& g : games) {
        std::cout << "Name: " << g.name << " | Genre: " << g.genre << " | Rating: " << g.rating << " | Platforms: ";
        for (const auto& p : g.platforms) std::cout << p << ", ";
        std::cout << std::endl;
    }
}

void task1() {
    if (games.empty()) {
        std::cout << "The array is empty.\n";
        return;
    }
    std::string genre;
    std::cout << "Enter the genre of interest: ";
    std::cin.ignore();
    std::getline(std::cin, genre);

    std::vector<Game> filtered;
    for (const auto& g : games)
        if (g.genre == genre)
            filtered.push_back(g);

    sort(filtered.begin(), filtered.end(), [](const Game& a, const Game& b) {
        return a.rating > b.rating;
        });

    if (filtered.empty())
        std::cout << "There are no games with this genre.\n";
    else
        for (const auto& g : filtered)
            std::cout << g.name << " | " << g.rating << std::endl;
}

void task2() {
    if (games.empty()) {
        std::cout << "The array is empty.\n";
        return;
    }
    std::map<std::string, int> genreCount;
    for (const auto& g : games)
        genreCount[g.genre]++;

    for (const auto& pair : genreCount) {
        double percent = 100.0 * pair.second / games.size();
        std::cout << pair.first << ": " << percent << "%\n";
    }
}

void saveToFile() {
    std::ofstream fout("games.txt");
    for (const auto& g : games) {
        fout << g.name << '\n' << g.genre << '\n' << g.rating << '\n';
        fout << g.platforms.size() << '\n';
        for (const auto& p : g.platforms) fout << p << '\n';
    }
    fout.close();
    std::cout << "Saved in games.txt\n";
}

void loadFromFile() {
    std::ifstream fin("games.txt");
    if (!fin.is_open()) {
        std::cout << "File not found.\n";
        return;
    }
    games.clear();
    while (!fin.eof()) {
        Game g;
        getline(fin, g.name);
        getline(fin, g.genre);
        fin >> g.rating;
        int count;
        fin >> count;
        fin.ignore();
        for (int i = 0; i < count; ++i) {
            std::string p;
            std::getline(fin, p);
            g.platforms.push_back(p);
        }
        if (!g.name.empty()) games.push_back(g);
    }
    fin.close();
    std::cout << "Downloaded from file.\n";
}

void menu() {
    int choice;
    do {
        std::cout << "Menu:\n1. Add a game\n2. Clear the list\n3. Save to file\n4. Load from file\n5. Show games\n6. Task 1\n7. Task 2\n0. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: addGame(); break;
        case 2: clearGames(); break;
        case 3: saveToFile(); break;
        case 4: loadFromFile(); break;
        case 5: showGames(); break;
        case 6: task1(); break;
        case 7: task2(); break;
        case 0: std::cout << "Exit...\n"; break;
        default: std::cout << "Wrong choice.\n";
        }
    } while (choice != 0);
}