#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <stdlib.h>
#include <string.h>
#include "audio.h"
#include "utils.h"

#define MAX_PLAYERS 5

typedef struct {
    uint32_t buffer;
    uint32_t source;
    int uses;
} AudioPlayer;

AudioPlayer players[MAX_PLAYERS] = { { 0, 0, 0 } };
int currentPlayerIndex = 0;

void CreateAudioEngine()
{
    // No need to initialize anything for Web Audio API
}

void CreateAudioPlayer(AudioPlayer* player, const char* assetPath)
{
    player->buffer = EM_ASM_INT({
        var audioContext = new (window.AudioContext || window.webkitAudioContext)();
        var request = new XMLHttpRequest();
        request.open('GET', UTF8ToString($0), true);
        request.responseType = 'arraybuffer';

        request.onload = function() {
            audioContext.decodeAudioData(request.response, function(buffer) {
                HEAPU32[$1 >> 2] = buffer;
            });
        };

        request.send();
        }, assetPath, & player->buffer);

    player->uses = 0;
}

void PlayAudio(const char* assetPath)
{
    AudioPlayer* player = &players[currentPlayerIndex];

    if (player->buffer == 0)
    {
        CreateAudioPlayer(player, assetPath);
    }

    player->source = EM_ASM_INT({
        var audioContext = new (window.AudioContext || window.webkitAudioContext)();
        var source = audioContext.createBufferSource();
        source.buffer = HEAPU32[$0 >> 2];
        source.connect(audioContext.destination);
        source.start();
        return source;
        }, player->buffer);

    player->uses++;

    currentPlayerIndex = (currentPlayerIndex + 1) % MAX_PLAYERS;
}

void PauseAudio()
{
    // Web Audio API does not support pausing individual sounds
}

void ResumeAudio()
{
    // Web Audio API does not support resuming individual sounds
}

void StopAudio()
{
    // Web Audio API does not support stopping individual sounds
}

void DestroyAudioPlayer()
{
    // No need to destroy anything for Web Audio API
}

void DestroyAudioEngine()
{
    // No need to destroy anything for Web Audio API
}