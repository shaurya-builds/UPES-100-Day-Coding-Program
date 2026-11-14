#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "hotels.dat"

typedef struct {
    int id;
    char name[100];
    char city[50];
    char state[50];

    float rating;
    float price;

    int wifi;
    int parking;
    int restaurant;

    char bookingSite[100];
} Hotel;


// ---------------------------------------------------------
// Clear extra characters from keyboard input
// ---------------------------------------------------------

void clearInputBuffer() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}


// ---------------------------------------------------------
// Create starting hotel dataset
// ---------------------------------------------------------

void createInitialDataset() {

    FILE *file = fopen(DATA_FILE, "rb");

    // If dataset already exists, don't overwrite it
    if (file != NULL) {
        fclose(file);
        return;
    }

    Hotel hotels[] = {

        {
            1,
            "Himalayan Retreat",
            "Chopta",
            "Uttarakhand",
            4.7,
            2800,
            1,
            1,
            1,
            "Booking Site A"
        },

        {
            2,
            "Mountain View Homestay",
            "Chopta",
            "Uttarakhand",
            4.5,
            1800,
            1,
            1,
            0,
            "Booking Site B"
        },

        {
            3,
            "Valley Resort",
            "Dehradun",
            "Uttarakhand",
            4.6,
            3500,
            1,
            1,
            1,
            "Booking Site A"
        },

        {
            4,
            "Budget Inn",
            "Dehradun",
            "Uttarakhand",
            4.1,
            1400,
            1,
            0,
            0,
            "Booking Site C"
        },

        {
            5,
            "Snow Peak Hotel",
            "Manali",
            "Himachal Pradesh",
            4.8,
            4200,
            1,
            1,
            1,
            "Booking Site A"
        },

        {
            6,
            "Backpacker Stay",
            "Manali",
            "Himachal Pradesh",
            4.3,
            1200,
            1,
            0,
            0,
            "Booking Site B"
        },

        {
            7,
            "Royal Jaipur Palace",
            "Jaipur",
            "Rajasthan",
            4.9,
            6500,
            1,
            1,
            1,
            "Booking Site A"
        },

        {
            8,
            "Pink City Stay",
            "Jaipur",
            "Rajasthan",
            4.4,
            2200,
            1,
            1,
            1,
            "Booking Site C"
        },

        {
            9,
            "Beach Paradise",
            "Goa",
            "Goa",
            4.8,
            5200,
            1,
            1,
            1,
            "Booking Site A"
        },

        {
            10,
            "Goa Budget Rooms",
            "Goa",
            "Goa",
            4.2,
            1600,
            1,
            0,
            1,
            "Booking Site B"
        }
    };

    int count = sizeof(hotels) / sizeof(hotels[0]);

    file = fopen(DATA_FILE, "wb");

    if (file == NULL) {
        printf("ERROR: Could not create dataset.\n");
        return;
    }

    fwrite(hotels, sizeof(Hotel), count, file);

    fclose(file);

    printf("\nInitial hotel dataset created successfully!\n");
}


// ---------------------------------------------------------
// Add new hotel
// ---------------------------------------------------------

void addHotel() {

    Hotel hotel;

    FILE *file = fopen(DATA_FILE, "ab");

    if (file == NULL) {
        printf("Could not open dataset.\n");
        return;
    }

    printf("\n========== ADD NEW HOTEL ==========\n");

    printf("Hotel ID: ");
    scanf("%d", &hotel.id);
    clearInputBuffer();


    printf("Hotel Name: ");
    fgets(hotel.name, sizeof(hotel.name), stdin);
    hotel.name[strcspn(hotel.name, "\n")] = 0;


    printf("City: ");
    fgets(hotel.city, sizeof(hotel.city), stdin);
    hotel.city[strcspn(hotel.city, "\n")] = 0;


    printf("State: ");
    fgets(hotel.state, sizeof(hotel.state), stdin);
    hotel.state[strcspn(hotel.state, "\n")] = 0;


    printf("Rating: ");
    scanf("%f", &hotel.rating);


    printf("Price per night: Rs ");
    scanf("%f", &hotel.price);


    printf("WiFi available? (1 = Yes, 0 = No): ");
    scanf("%d", &hotel.wifi);


    printf("Parking available? (1 = Yes, 0 = No): ");
    scanf("%d", &hotel.parking);


    printf("Restaurant available? (1 = Yes, 0 = No): ");
    scanf("%d", &hotel.restaurant);

    clearInputBuffer();


    printf("Booking Site: ");
    fgets(hotel.bookingSite, sizeof(hotel.bookingSite), stdin);
    hotel.bookingSite[strcspn(hotel.bookingSite, "\n")] = 0;


    fwrite(&hotel, sizeof(Hotel), 1, file);

    fclose(file);

    printf("\nHotel added successfully!\n");
}


// ---------------------------------------------------------
// Display hotel
// ---------------------------------------------------------

void displayHotel(Hotel hotel) {

    printf("\n----------------------------------------\n");

    printf("Hotel: %s\n", hotel.name);

    printf("Location: %s, %s\n",
           hotel.city,
           hotel.state);

    printf("Rating: %.1f / 5\n",
           hotel.rating);

    printf("Price: Rs %.0f per night\n",
           hotel.price);

    printf("WiFi: %s\n",
           hotel.wifi ? "Yes" : "No");

    printf("Parking: %s\n",
           hotel.parking ? "Yes" : "No");

    printf("Restaurant: %s\n",
           hotel.restaurant ? "Yes" : "No");

    printf("Booking: %s\n",
           hotel.bookingSite);

    printf("----------------------------------------\n");
}


// ---------------------------------------------------------
// Calculate hotel recommendation score
// ---------------------------------------------------------

float calculateScore(Hotel hotel, float maxBudget) {

    float score = 0;

    // Rating importance
    score += hotel.rating * 20;

    // Budget bonus
    if (hotel.price <= maxBudget) {
        score += 20;
    }

    // Facility bonuses
    if (hotel.wifi)
        score += 5;

    if (hotel.parking)
        score += 5;

    if (hotel.restaurant)
        score += 5;

    return score;
}


// ---------------------------------------------------------
// Search hotels
// ---------------------------------------------------------

void searchHotels() {

    char city[50];

    float maxBudget;
    float minRating;

    int needWifi;
    int needParking;
    int needRestaurant;


    printf("\n========== HOTEL SEARCH ==========\n");


    printf("Enter City: ");

    clearInputBuffer();

    fgets(city, sizeof(city), stdin);

    city[strcspn(city, "\n")] = 0;


    printf("Maximum Budget per night: Rs ");

    scanf("%f", &maxBudget);


    printf("Minimum Rating: ");

    scanf("%f", &minRating);


    printf("Need WiFi? (1 = Yes, 0 = No): ");

    scanf("%d", &needWifi);


    printf("Need Parking? (1 = Yes, 0 = No): ");

    scanf("%d", &needParking);


    printf("Need Restaurant? (1 = Yes, 0 = No): ");

    scanf("%d", &needRestaurant);


    FILE *file = fopen(DATA_FILE, "rb");


    if (file == NULL) {

        printf("Dataset not found.\n");

        return;
    }


    Hotel hotel;


    Hotel matches[1000];

    int matchCount = 0;


    // Read hotel records from SECONDARY MEMORY
    // one at a time into RAM

    while (fread(&hotel, sizeof(Hotel), 1, file)) {


        if (strcmp(hotel.city, city) != 0)
            continue;


        if (hotel.price > maxBudget)
            continue;


        if (hotel.rating < minRating)
            continue;


        if (needWifi && !hotel.wifi)
            continue;


        if (needParking && !hotel.parking)
            continue;


        if (needRestaurant && !hotel.restaurant)
            continue;


        // Matching hotel copied into RAM

        matches[matchCount] = hotel;

        matchCount++;


        if (matchCount >= 1000)
            break;
    }


    fclose(file);


    if (matchCount == 0) {

        printf("\nNo matching hotels found.\n");

        return;
    }


    // -----------------------------------------------------
    // Sort results according to recommendation score
    // -----------------------------------------------------

    for (int i = 0; i < matchCount - 1; i++) {

        for (int j = i + 1; j < matchCount; j++) {


            float score1 =
                calculateScore(matches[i], maxBudget);


            float score2 =
                calculateScore(matches[j], maxBudget);


            if (score2 > score1) {

                Hotel temp = matches[i];

                matches[i] = matches[j];

                matches[j] = temp;
            }
        }
    }


    printf("\n\n========== BEST HOTEL OPTIONS ==========\n");


    for (int i = 0; i < matchCount; i++) {

        printf("\nRecommendation #%d", i + 1);

        displayHotel(matches[i]);

        printf("Recommendation Score: %.1f\n",
               calculateScore(matches[i], maxBudget));
    }
}


// ---------------------------------------------------------
// Show all hotels
// ---------------------------------------------------------

void showAllHotels() {

    FILE *file = fopen(DATA_FILE, "rb");


    if (file == NULL) {

        printf("Dataset not found.\n");

        return;
    }


    Hotel hotel;

    int count = 0;


    printf("\n========== COMPLETE HOTEL DATASET ==========\n");


    while (fread(&hotel, sizeof(Hotel), 1, file)) {

        displayHotel(hotel);

        count++;
    }


    fclose(file);


    printf("\nTotal Hotels: %d\n", count);
}


// ---------------------------------------------------------
// Main program
// ---------------------------------------------------------

int main() {

    int choice;


    // Create dataset if it doesn't exist

    createInitialDataset();


    while (1) {


        printf("\n\n=====================================\n");

        printf("       AI TOURISM HOTEL ENGINE\n");

        printf("=====================================\n");


        printf("\n1. Search Best Hotels");

        printf("\n2. Add Hotel");

        printf("\n3. Show Complete Dataset");

        printf("\n4. Exit");


        printf("\n\nEnter Choice: ");

        scanf("%d", &choice);


        switch (choice) {


            case 1:

                searchHotels();

                break;


            case 2:

                addHotel();

                break;


            case 3:

                showAllHotels();

                break;


            case 4:

                printf("\nProgram closed.\n");

                return 0;


            default:

                printf("\nInvalid choice.\n");
        }
    }
}