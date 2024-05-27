const int cols = 4; 
const int rows = 4; 
char key[rows][cols] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
int rowPins[rows] = {9, 8, 7, 6};
int colPins[cols] = {5, 4, 3, 2};

void setup() {
    Serial.begin(9600);  
    for (int row = 0; row < rows; row++) {
        pinMode(rowPins[row], INPUT_PULLUP);
    }
    for (int col = 0; col < cols; col++) {
        pinMode(colPins[col], INPUT);
    }
} 

void loop() {
    for (int col = 0; col < cols; col++) {
        pinMode(colPins[col], OUTPUT);
        digitalWrite(colPins[col], LOW);

        for (int row = 0; row < rows; row++) {
            if (digitalRead(rowPins[row]) == LOW) {
                delay(50);  
                if (digitalRead(rowPins[row]) == LOW) {
                    char pressedKey = key[row][col];
                    Serial.println(pressedKey);  
                    while (digitalRead(rowPins[row]) == LOW);  
                }
            }
        }

        digitalWrite(colPins[col], HIGH);
        pinMode(colPins[col], INPUT);
    }
}
