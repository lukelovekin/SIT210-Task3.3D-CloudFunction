int wavePin = D4;
int patPin = D2;

void eventHandler(const char *event, const char *data);
void waveResponse();
void patResposne();

void setup() {
    pinMode(wavePin, OUTPUT);
    pinMode(patPin, OUTPUT);
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", eventHandler);
}

void loop() {

}

void eventHandler(const char *event, const char *data){
    if(strcmp(data, "wave") == 0){
        waveResponse();
    }
    else if (strcmp(data, "pat") == 0){
        patResponse();
    }
    String eventResponse = String::format("Handled %s", data);
    Particle.publish("Handler", eventResponse);
}

void waveResponse(){
    for(int i = 0; i < 3; i++){
        digitalWrite(wavePin, HIGH);
        delay(500);
        digitalWrite(wavePin, LOW);
        delay(500);
    }
}

void patResponse(){
    digitalWrite(wavePin, HIGH);
    delay(3000);
    digitalWrite(wavePin, LOW);
}