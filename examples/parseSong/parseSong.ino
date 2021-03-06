#include <RtttlParser.h>

#define TONE_PIN 13

SimpleAudio::RtttlParser parser;

char *song = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";

void setup() {
    pinMode(TONE_PIN, OUTPUT);

    Serial.begin(9600);

    Serial.print("Parsing song...\t");
    if (parser.parseSong(song)) {
        Serial.println("OK");
    } else {
        Serial.println("ERROR"); 
    }
}

void loop() {
    Serial.print("Play: ");
    Serial.println(parser.getName());
  
    Serial.print("Default duration: ");
    Serial.println(parser.getDefaultDuration());

    Serial.print("Default octave: ");
    Serial.println(parser.getDefaultOctave());
    
    Serial.print("Default tempo: ");
    Serial.println(parser.getDefaultTempo());

    Serial.println("Plaing...");

    while (1) {
      const SimpleAudio::Note& note = parser.parseNextNote();
      if (note.isValid()) {
          unsigned long duration = note.getDuration() / parser.getDefaultTempo();
          Serial.print("Frequency: ");
          Serial.print(note.getFrequency());
          Serial.print(" Duration: ");
          Serial.println(duration);
          tone(TONE_PIN, note.getFrequency());
          delay(duration);
        } else {
            break;
        }

        noTone(TONE_PIN);
    }

    Serial.println("Stop.");
    
    while (1) {
        delay(1000);
    }
}
