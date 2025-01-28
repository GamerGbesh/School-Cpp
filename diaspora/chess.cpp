#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void createSampleFile(const string& filePath) {
    ofstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error: Unable to create file." << endl;
        return;
    }

    file << "250 5750\n";
    file << "100 28000\n";
    file << "50 35750\n";
    file << "25 18750\n";

    file.close();
    cout << "Sample file created: " << filePath << endl;
}

void calculateTotalSales(const string& filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error: File not found." << endl;
        return;
    }

    int totalTicketsSold = 0;
    double totalSales = 0.0;

    double ticketPrice;
    int ticketsSold;

    while (file >> ticketPrice >> ticketsSold) {
        totalTicketsSold += ticketsSold;
        totalSales += ticketPrice * ticketsSold;
    }

    file.close();

    cout << "Total Tickets Sold: " << totalTicketsSold << endl;
    cout << fixed << setprecision(2);
    cout << "Total Sales Amount: $" << totalSales << endl;
}

// Example usage:
int main() {
    string filePath = "ticket_sales.txt";
    
    // Create sample file
    createSampleFile(filePath);
    
    // Calculate total sales
    calculateTotalSales(filePath);
    return 0;
}