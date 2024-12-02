#include "audio.h"
#include "utils.h"
#include <emscripten.h>
#include <emscripten/html5.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_USES 5

typedef struct {
    int uses;
} AudioPlayer;

AudioPlayer players[MAX_PLAYERS] = { { 0 } };
int currentPlayerIndex = 0;

void CreateAudioEngine()
{
    // No need to initialize anything for Web Audio API
}

void CreateAudioPlayer(AudioPlayer* player, const char* assetPath)
{
    player->uses = 0; // reset counter
    Log("Successfully created audio player for asset: %s", assetPath);
}

void PlayAudio(const char* assetPath)
{
    // find an available player
    int availableIndex = -1;
    for (int i = 0; i < MAX_PLAYERS; ++i)
    {
        if (players[i].uses < MAX_USES)
        {
            availableIndex = i;
            break;
        }
    }

    // if no available player, create a new one
    if (availableIndex == -1)
    {
        int oldestIndex = currentPlayerIndex;
        currentPlayerIndex = (currentPlayerIndex + 1) % MAX_PLAYERS; // move to the next player in the cycle

        Log("Destroying player %d to create a new one for asset: %s", oldestIndex, assetPath);
        players[oldestIndex].uses = 0;
        availableIndex = oldestIndex;
    }

    // start playing
    if (availableIndex != -1)
    {
        EM_ASM({
            var audio = new Audio('assets/' + UTF8ToString($0));
            audio.play();
        }, assetPath);

        Log("Started playing asset: %s", assetPath);
        players[availableIndex].uses++;
    }
    else
    {
        Log("No available player to play asset: %s", assetPath);
    }
}

void PauseAudio()
{
    EM_ASM({
        var audios = document.getElementsByTagName('audio');
        for (var i = 0; i < audios.length; i++) {
            audios[i].pause();
        }
    });
}

void ResumeAudio()
{
    EM_ASM({
        var audios = document.getElementsByTagName('audio');
        for (var i = 0; i < audios.length; i++) {
            audios[i].play();
        }
    });
}

void StopAudio()
{
    EM_ASM({
        var audios = document.getElementsByTagName('audio');
        for (var i = 0; i < audios.length; i++) {
            audios[i].pause();
            audios[i].currentTime = 0;
        }
    });
}

void DestroyAudioPlayer()
{
    // No need to destroy anything for Web Audio API
}

void DestroyAudioEngine()
{
    // No need to destroy anything for Web Audio API
}