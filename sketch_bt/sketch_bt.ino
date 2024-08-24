//defining pins of motor driver
#define in1 3
#define in2 5
#define in3 6
#define in4 11

int command; // Int to store app command state.
int Speed = 204; // 0 - 255.
int Speedsec;

void setup() {
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    Serial.begin(9600); // Set the baud rate to your Bluetooth module.
}

void loop() {
    if (Serial.available() > 0) {
        command = Serial.read();
    }
}

void handleCommand(int command) {
    switch (command) {
        case 'F':
            forward();
            break;
        case 'B':
            back();
            break;
        case 'L':
            left();
            break;
        case 'R':
            right();
            break;
        case 'S':
            Stop();
            break;
    }
}

void forward() {
    analogWrite(in1, Speed);
    analogWrite(in3, Speed);
}

void back() {
    analogWrite(in2, Speed);
    analogWrite(in4, Speed);
}

void left() {
    analogWrite(in3, Speed);
    analogWrite(in2, Speed);
}

void right() {
    analogWrite(in4, Speed);
    analogWrite(in1, Speed);
}

void Stop() {
    analogWrite(in1, 0);
    analogWrite(in2, 0);
    analogWrite(in3, 0);
    analogWrite(in4, 0);
}