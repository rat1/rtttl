#pragma once

#include "AbstractRtttlSongReader.h"
#include "RtttlParser.h"

namespace SimpleAudio {

class RtttlPlayer {
public:
    RtttlPlayer(int outputPin, AbstractRtttlSongReader& reader);

    bool eof() const;

    void play();
    void reset();

    void stepNext();
    void stepPrev();

    const char *getSongName() const;
private:
    AbstractRtttlSongReader& reader;
    RtttlParser parser;
    int currentNote;
    int outputPin;
};

}
