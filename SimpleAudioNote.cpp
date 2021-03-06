#include "SimpleAudioNote.h"

namespace {

enum {
    NOTE_C4     = 262,
    NOTE_CS4    = 277,
    NOTE_D4     = 294,
    NOTE_DS4    = 311,
    NOTE_E4     = 330,
    NOTE_F4     = 349,
    NOTE_FS4    = 370,
    NOTE_G4     = 392,
    NOTE_GS4    = 415,
    NOTE_A4     = 440,
    NOTE_AS4    = 466,
    NOTE_B4     = 494,
    NOTE_C5     = 523,
    NOTE_CS5    = 554,
    NOTE_D5     = 587,
    NOTE_DS5    = 622,
    NOTE_E5     = 659,
    NOTE_F5     = 698,
    NOTE_FS5    = 740,
    NOTE_G5     = 784,
    NOTE_GS5    = 831,
    NOTE_A5     = 880,
    NOTE_AS5    = 932,
    NOTE_B5     = 988,
    NOTE_C6     = 1047,
    NOTE_CS6    = 1109,
    NOTE_D6     = 1175,
    NOTE_DS6    = 1245,
    NOTE_E6     = 1319,
    NOTE_F6     = 1397,
    NOTE_FS6    = 1480,
    NOTE_G6     = 1568,
    NOTE_GS6    = 1661,
    NOTE_A6     = 1760,
    NOTE_AS6    = 1865,
    NOTE_B6     = 1976,
    NOTE_C7     = 2093,
    NOTE_CS7    = 2217,
    NOTE_D7     = 2349,
    NOTE_DS7    = 2489,
    NOTE_E7     = 2637,
    NOTE_F7     = 2794,
    NOTE_FS7    = 2960,
    NOTE_G7     = 3136,
    NOTE_GS7    = 3322,
    NOTE_A7     = 3520,
    NOTE_AS7    = 3729,
    NOTE_B7     = 3951,
    NOTE_C8     = 4186,
    NOTE_CS8    = 4435,
    NOTE_D8     = 4699,
    NOTE_DS8    = 4978,
    NOTE_E8     = 5274,
    NOTE_F8     = 5588,
    NOTE_FS8    = 5920,
    NOTE_G8     = 6272,
    NOTE_GS8    = 6645,
    NOTE_A8     = 7040,
    NOTE_AS8    = 7459,
    NOTE_B8     = 7902,
} NoteFrequency;

unsigned int notes[] = {
    NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
    NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
    NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
    NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7,
    NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8, NOTE_E8, NOTE_F8, NOTE_FS8, NOTE_G8, NOTE_GS8, NOTE_A8, NOTE_AS8, NOTE_B8,
};

}

SimpleAudio::Note::Note()
    : frequency(),
      duration(),
      valid(false)
{
    this->duration = calculateDuration(Duration::WHOLE, 0);
}

SimpleAudio::Note::Note(int toneIndex, int noteDuration, int noteOctave, int dotsCount)
    : frequency(),
      duration(),
      valid(true)
{
    if (toneIndex < 0) {
        this->frequency = 0;
    } else {
        this->frequency = notes[toneIndex + (noteOctave - Octave::OCTAVE_4) * 12];
    }

    this->duration = calculateDuration(noteDuration, dotsCount);
}

unsigned long
SimpleAudio::Note::calculateDuration(int duration, int dotsCount) const
{
    unsigned long result = 60 * 1000L * 4 / duration;

    unsigned long pow = 1 << dotsCount;
    if (pow != 1) {
        result = result * (2 * pow - 1) / pow;
    }

    return result;
}

unsigned long
SimpleAudio::Note::getDuration() const
{
    return this->duration;
}

unsigned int
SimpleAudio::Note::getFrequency() const
{
    return this->frequency;
}

bool
SimpleAudio::Note::isValid() const
{
    return this->valid;
}
