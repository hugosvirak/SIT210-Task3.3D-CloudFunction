#include <string>

const pin_t MY_LED = D3;
void handleEvent(const char *event, const char *data);

void setup() {
    pinMode(MY_LED, OUTPUT);
    Particle.subscribe("3.3D_event", static_cast<void(*)(const char *, const char *)>(handleEvent));
}

void handleEvent(std::string event, std::string data)
{
    if (data == "wave") {
        for (int i = 0; i < 3; i++) {
            digitalWrite(MY_LED, HIGH);
            delay(250ms);
            digitalWrite(MY_LED, LOW);
            delay(250ms);  
        }
    }
    
    if (data == "pat") {
        for (int i = 0; i < 5; i++) {
            digitalWrite(MY_LED, HIGH);
            delay(500ms);
            digitalWrite(MY_LED, LOW);
            delay(500ms);  
        }
    }
}

void handleEvent(const char *event, const char *data)
{
    handleEvent(std::string(event), std::string(data));
}

