echo "# CS-2073-001-202420-G2" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/EDITHmk42/CS-2073-001-202420-G2.git
git push -u origin main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 8
#define MAX_ROUTES 10
#define MAX_DESTINATIONS 10
#define MAX_STAFF 8

typedef struct {
    int id;
    char name[50];
    char username[20];
    char password[20];
} Staff;

typedef struct {
    int id;
    char name[50];
} Destination;

typedef struct {
    int id;
    char name[50];
    int capacity;
} Bus;

typedef struct {
    int id;
    char name[50];
    int bus_id;
    int destination_id;
} Route;

Destination destinations[MAX_DESTINATIONS];
Bus buses[MAX_BUSES];
Route routes[MAX_ROUTES];
Staff staff[MAX_STAFF];
int num_destinations = 0;
int num_buses = 0;
int num_routes = 0;
int num_staff = 0;

// Function prototypes...
int authenticate_user(char username[], char password[]);
int authenticate_staff(char username[], char password[]);

// Function to add a new staff member
void add_staff(char name[], char username[], char password[]) {
    if (num_staff >= MAX_STAFF) {
        printf("Cannot add more staff. Limit reached.\n");
        return;
    }
    staff[num_staff].id = num_staff + 1;
    strcpy(staff[num_staff].name, name);
    strcpy(staff[num_staff].username, username);
    strcpy(staff[num_staff].password, password);
    num_staff++;
}

// Function to display all staff members
void display_staff() {
    printf("Staff Members:\n");
    for (int i = 0; i < num_staff; i++) {
        printf("%d. %s\n", staff[i].id, staff[i].name);
    }
}

// Function to check if the username and password match for staff
int authenticate_staff(char username[], char password[]) {
    // Example staff credentials
    char valid_username[] = "staff123";
    char valid_password[] = "staffpassword123";

    if (strcmp(username, valid_username) == 0 && strcmp(password, valid_password) == 0) {
        return 1; // Authentication successful
    } else {
        return 0; // Authentication failed
    }
}

// Function to add a new destination
void add_destination(char name[]) {
    destinations[num_destinations].id = num_destinations + 1;
    strcpy(destinations[num_destinations].name, name);
    num_destinations++;
}

// Function to display all destinations
void display_destinations() {
    printf("Destinations:\n");
    for (int i = 0; i < num_destinations; i++) {
        printf("%d. %s\n", destinations[i].id, destinations[i].name);
    }
}

// Function to add a new bus
void add_bus(char name[], int capacity) {
    if (num_buses >= MAX_BUSES) {
        printf("Cannot add more buses. Limit reached.\n");
        return;
    }
    buses[num_buses].id = num_buses + 1;
    strcpy(buses[num_buses].name, name);
    buses[num_buses].capacity = capacity;
    num_buses++;
}

// Function to display all buses
void display_buses() {
    printf("Buses:\n");
    for (int i = 0; i < num_buses; i++) {
        printf("%d. %s (Capacity: %d)\n", buses[i].id, buses[i].name, buses[i].capacity);
    }
}

// Function to connect a bus to a destination
void connect_bus_to_destination(int bus_id, int destination_id) {
    if (bus_id < 1 || bus_id > num_buses || destination_id < 1 || destination_id > num_destinations) {
        printf("Invalid bus or destination ID.\n");
        return;
    }
    routes[num_routes].id = num_routes + 1;
    strcpy(routes[num_routes].name, "Route");
    routes[num_routes].bus_id = bus_id;
    routes[num_routes].destination_id = destination_id;
    num_routes++;
}

// Function to display routes
void display_routes() {
    printf("Routes:\n");
    for (int i = 0; i < num_routes; i++) {
        printf("%d. %s (Bus: %s, Destination: %s)\n", routes[i].id, routes[i].name, buses[routes[i].bus_id - 1].name, destinations[routes[i].destination_id - 1].name);
    }
}

int main() {
    char choice;
    printf("Are you a staff member (S) or a regular user (U)? ");
    scanf(" %c", &choice);
    getchar(); // Consume newline character left in the input buffer

    if (choice == 'S' || choice == 's') {
        // Staff login
        char username[20];
        char password[20];
        printf("Please enter your staff login: ");
        scanf("%s", username);
        printf("Please enter your password: ");
        scanf("%s", password);
        if (authenticate_staff(username, password)) {
            printf("Login successful. Welcome, %s!\n", username);
            // Proceed with staff operations
            // For now, let's just display staff members
            display_staff();
        } else {
            printf("Invalid username or password. Login failed.\n");
            return 0;
        }
    } else if (choice == 'U' || choice == 'u') {
        // User login
        char username[20];
        char password[20];
        printf("Please enter your username: ");
        scanf("%s", username);
        printf("Please enter your password: ");
        scanf("%s", password);
        if (authenticate_user(username, password)) {
            printf("Login successful. Welcome, %s!\n", username);
            // Proceed with regular user operations
            // For now, let's just display destinations
            display_destinations();
        } else {
            printf("Invalid username or password. Login failed.\n");
            return 0;
        }
    } else {
        printf("Invalid choice. Please choose 'S' for staff or 'U' for regular user.\n");
        return 0;
    }
    
    int route_add()
{
    printf("adding route...\n");
    char a[100];
    int x;
    printf("Please write Bus number\t");
    scanf("%s",a);
    FILE *out;
    out = fopen( "BusList.txt", "w" );
    fprintf(out, "Bus %s",a);
    fclose(out);
    
    char* extension = ".txt";
    char fileSpec[strlen(a)+strlen(extension)+1];

    snprintf( fileSpec, sizeof( fileSpec ), "%s%s", a, extension );
    
    out = fopen( fileSpec, "w" );
    fprintf(out, "%s\n",a);
    printf("How Many Stops are there?\t");
    scanf("%d",&x);
    
    for (int i = 0; i < x; i++)
    {
        printf("name of stop %d:\t",i + 1);
        scanf("%s",a);
        fprintf(out, "%s\n",a);
    }
    
    fclose(out);
    
}

int Bus_List()
{
    FILE *out;
    out = fopen( "BusList.txt", "r" );
    char myString[100];
    while(fgets(myString, 100, out)) 
    {
        printf("%s", myString);
    }
    fclose(out);
}


 // Add some example destinations
    add_destination("The Reserves"); //1
    add_destination("Broadstone"); //2
    add_destination("Sterling"); //3
    add_destination("High View"); //4
    add_destination("Hill Country"); //5
    add_destination("The Luxx");//6
    add_destination("Maverick Creek");//7
    add_destination("Campus Edge");//8
    add_destination("Tetro Village");//9
    add_destination("Villas at Babock");//10
    add_destination("Avalon Place");//11
    display_destinations();

    // Add some example buses
    add_bus("Bus 12", 40); //1
    add_bus("Bus 14", 40); //2
    add_bus("Bus 20", 40); //3
    add_bus("Bus 22", 40); //4
    add_bus("Bus 45", 40); //5
    add_bus("Bus 47", 40); //6
    add_bus("Bus 13", 40); //7 
    add_bus("Bus 43", 40); //8
    display_buses();

    // User chooses a destination
    int destination_choice;
    printf("Enter the destination number: ");
    scanf("%d", &destination_choice);

    // Display the selected destination
    printf("Destination: %s\n", destinations[destination_choice - 1].name);

    // Connect the selected destination with a predetermined bus
    int bus_id = 0

; // Default value
    switch (destination_choice) {
        case 5:  // Hill Country
            bus_id = 1; // Bus 12
            break;
        case 1:  // The Reserves
            bus_id = 2; // Bus 14
            break;
        case 3:  // Sterling
            bus_id = 6 ; // Bus 47
            break;
        case 4:  // Highveiw
            bus_id = 6 ; // Bus 47
            break;
         case 2:  // Broadstone
            bus_id = 2; // Bus 14
            break;
         case 6:  // The Luxx
            bus_id = 2; // Bus 14
            break;
         case 7:  // Maverick creek
            bus_id = 5; // Bus 45
            break;
         case 8:  // Campus Edge
            bus_id = 3; // Bus 20
            break;
         case 9:  // Tetro Village
            bus_id = 6 ; // Bus 47
            break;
        case 10:  // Villas at Babock
            bus_id =  4; // Bus 22
            break;
        case 11:  // Avalon Palace
            bus_id = 3; // Bus 20
            break;
        // Assign other destinations to buses as needed
        default:
            printf("Destination not assigned to a bus.\n");
            break;
    }

    // Display the assigned bus
    printf("Assigned Bus: %s\n", buses[bus_id - 1].name);

    // Connect the selected bus to the chosen destination
    connect_bus_to_destination(bus_id, destination_choice);

    // Display the route
    printf("Route details:\n");
    printf("Bus: %s, Destination: %s\n", buses[bus_id - 1].name, destinations[destination_choice - 1].name);
    
    return 0;
}

int authenticate_user(char username[], char password[]) {
    // Placeholder for user authentication
    return 1; // Assume successful authentication for now
}
