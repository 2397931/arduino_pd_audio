// Le code minimal

#include <Arduino.h> 
#include <Bounce2.h>

#define BROCHE_BOUTON1 2
#define BROCHE_BOUTON2 4
#define BROCHE_DEL1 3
#define BROCHE_DEL2 5

bool etat8tn = LOW;
bool etatDel = LOW;

Bounce2::Button bouton1;
Bounce2::Button bouton2;


void setup() {
    Serial.begin(115200);// Initialisation de la vitesse de communication série à 115200 bauds
    // Configuration de la DEL
    pinMode(BROCHE_DEL1, OUTPUT);
    digitalWrite(BROCHE_DEL1, etatDel);

    pinMode(BROCHE_DEL2, OUTPUT);
    digitalWrite(BROCHE_DEL2, etatDel);

    bouton1.attach(BROCHE_BOUTON1, INPUT_PULLUP);
    bouton2.attach(BROCHE_BOUTON2, INPUT_PULLUP);

    bouton1.setPressedState(LOW);
    bouton2.setPressedState(LOW);
}

void loop() {
      bouton1.update();
      bouton2.update();

    // Gestion de l'événement de pression
    if (bouton1.pressed())
    {
        Serial.print("bouton1"); //description du bouton
        Serial.print(" "); // espace
        Serial.print(1); // valeur
        Serial.println(); // saut de ligne

        
    }

    if (bouton2.pressed())
    {
        Serial.print("bouton2");
        Serial.print(" ");
        Serial.print(2);
        Serial.println();

    }
}













//Serial.println("123"); Envoie la chaîne "123" sur le port série