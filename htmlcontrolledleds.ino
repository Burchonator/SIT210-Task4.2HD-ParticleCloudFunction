int led_red = D4;
int led_green = D5;
int led_blue = D6;

bool redLedOn = false;
bool greenLedOn = false;
bool blueLedOn = false;

//String command = Particle.function("ledToggle", ledToggler);

void setup() {
    pinMode(led_red, OUTPUT);
    pinMode(led_green, OUTPUT);
    pinMode(led_blue, OUTPUT);
    //Particle.function("ledToggle", ledToggle);
    //Particle.subscribe("ledToggle", ledToggle);
    //particle.callFunction({ deviceId: myDevice, name: "ledToggle", argument: "switch", auth: myToken });
    
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_blue, LOW);
}

void loop() {
    Particle.function("ledToggle", ledToggler);
}

// thers is a limit of 15 functions that can be used
int ledToggler(String command){
    // Red LED
    if(command == "red" && redLedOn == false) {
        digitalWrite(led_red, HIGH);
        redLedOn = true;
    } 
    else if (command == "red" && redLedOn == true){
        digitalWrite(led_red, LOW);
        redLedOn = false;
    }
    // return 0 means false statement 1 is a true statement -1 means command or function was not found
    // Green LED
    if(command == "green" && greenLedOn == false) {
        digitalWrite(led_green, HIGH);
        greenLedOn = true;
    } 
    else if (command == "green" && greenLedOn == true){
        digitalWrite(led_green, LOW);
        greenLedOn = false;
    }
    
    // Blue LED
    if(command == "blue" && blueLedOn == false) {
        digitalWrite(led_blue, HIGH);
        blueLedOn = true;
    } 
    else if (command == "blue" && blueLedOn == true){
        digitalWrite(led_blue, LOW);
        blueLedOn = false;
    }
    
    return 1;
}

/*int ledToggle(String command){
    if (command == "red" && redLedOn == false) {
    digitalWrite(led_red, HIGH);
    redLedOn = true;
    } 
    else if (command == "red" && redLedOn == true){
        digitalWrite(led_red, LOW);
        redLedOn = false;
    }
    
    /*if (command == "green" && greenLedOn==false) {
        digitalWrite(led_green, HIGH);
        greenLedOn = true;
    } 
    else if (command == "green" && greenLedOn==true){
        digitalWrite(led_green, LOW);
        greenLedOn = false;
    }
    
    if (command == "blue" && blueLedOn==false) {
        digitalWrite(led_blue, HIGH);
        blueLedOn = true;
    } 
    else if (command == "blue" && blueLedOn==true){
        digitalWrite(led_blue, LOW);
        blueLedOn = false;
    }*/
